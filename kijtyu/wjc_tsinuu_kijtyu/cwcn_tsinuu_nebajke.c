#include "cwcn_tsinuu_nebajke.h"
#include "cwcn_tsinuu_piaabo.h"
// void tsinuu_inverse_uwaabo(__tsinuu_t *_tsinuu, __cwcn_type_t *_output);
// void jkimyei_weight_byinversediff(__tsinuu_t *_tsinuu);
// void jkimyei_bias_byinversediff(__tsinuu_t _tsinuu);
// void tsinuu_direct_uwaabo(__tsinuu_t *_tsinuu, __cwcn_type_t *_input);
// void jkimyei_weight_bydirectdiff(__tsinuu_t *_tsinuu);
// void jkimyei_bias_bydirectdiff(__tsinuu_t *_tsinuu);
// void cpte_kemu_firstordedgrad(__tsinuu_t *_tsinuu, ___cwcn_bool_t cpte_direct, ___cwcn_bool_t cpte_inverse);
// void cpte_kemu_bias(__tsinuu_t *_tsinuu);
// void cpte_kemu_maxmin(__tsinuu_t *_tsinuu);
// void cpte_kemu_l_dist(__tsinuu_t *_tsinuu, __layer_coords_t *_l_coord);
// void cpte_kemu_n_dist(__tsinuu_t *_tsinuu, __node_coords_t *_n_coord);
// void cpte_kemu_ln_dist(__tsinuu_t *_tsinuu, __line_coords_t *_ln_coord);
/*
    ACTIVATIONS
*/
__cwcn_type_t nat_sigmoid_direct(__cwcn_type_t _input){
    // fprintf(stdout, "¡direct! \t\t%f -> %f\n",_input, 1.0/(1.0+exp(-_input)));
    return 1.0/(1.0+exp(-_input));}
__cwcn_type_t nat_sigmoid_direct_derivate(__cwcn_type_t _input){return nat_sigmoid_direct(_input)*(1-nat_sigmoid_direct(_input));} // #FIXME, better perfornce if direct value is saved.
__cwcn_type_t nat_sigmoid_direct_derivate_fast(__cwcn_type_t _output){return _output*(1-_output);} // #FIXME, better perfornce if direct value is saved.
__cwcn_type_t nat_sigmoid_inverse(__cwcn_type_t _input){return log(_input/(1-_input));}
__cwcn_type_t nat_sigmoid_inverse_derivate(__cwcn_type_t _input){return 1/(_input - _input*_input);}

__cwcn_type_t nat_signedsigmoid_direct(__cwcn_type_t _input){
    return 2.0/(1.0+exp(-2.0*_input))-1.0;}
__cwcn_type_t nat_signedsigmoid_direct_derivate(__cwcn_type_t _input){
    return (2.0*exp(-2.0*_input))/(exp(-2.0*_input)+1);} // #FIXME, better perfornce if direct value is saved.
__cwcn_type_t nat_signedsigmoid_inverse(__cwcn_type_t _input){
    return -0.5*log(2.0/(_input+1.0)-1.0);} // #FIXME  might be inestable
__cwcn_type_t nat_signedsigmoid_inverse_derivate(__cwcn_type_t _input){
    return -1.0/(_input*_input-1.0);} // #FIXME might be inestable

__cwcn_type_t linear_direct(__cwcn_type_t _input){return _input;}
__cwcn_type_t linear_direct_derivate(__cwcn_type_t _input){return 1.0;}
__cwcn_type_t linear_inverse(__cwcn_type_t _input){return _input;}
__cwcn_type_t linear_inverse_derivate(__cwcn_type_t _input){return 1.0;}
// __cwcn_type_t bin_sigmoid_forward(__cwcn_type_t _input){return (__cwcn_type_t) 0x0F>>((__cwcn_type_t) 0x0F + (__cwcn_type_t) 0x0F<<(__cwcn_type_t) _input);} // #FIXME

__cwcn_type_t relu_direct(__cwcn_type_t _input){return max(_input,0);}
__cwcn_type_t relu_direct_derivate(__cwcn_type_t _input){if(_input>0){return 0x01;} else {return 0x00;}}
__cwcn_type_t relu_inverse(__cwcn_type_t _input){return max(_input,0);}
__cwcn_type_t relu_inverse_derivate(__cwcn_type_t _input){if(_input>0){return 0x01;} else {return 0x00;}}

__cwcn_type_t softplus_direct(__cwcn_type_t _input){return log(1+exp(_input));}
__cwcn_type_t softplus_direct_derivate(__cwcn_type_t _input){return 1.0/(1.0+exp(-_input));}
__cwcn_type_t softplus_inverse(__cwcn_type_t _input){return log(exp(_input)-1.0);}
__cwcn_type_t softplus_inverse_derivate(__cwcn_type_t _input){return 1.0/(exp(_input)-1.0)+1.0;}

/*
    PARAMETERS OPERATIONS
*/
void dist_node(__tsinuu_t *_tsinuu, __node_tsinuu_t *_node){ // #FIXME might be util to check for __is_reset 
    /* ASSUMES _node->__n_kemu->__value has been computed.  
        ___nodebolean_parametrics {
            __pardon_maxmin
            __pardon_entropy
            __pardon_dist
            __pardon_count
        }
        __dist_coord_t {
            __max
            __min
            __std
            __M2
            __M3
            __M4
            __kurtosis
            __skewness
            __mean
            __entropy
            __count
        }
    */
    if(!_node->__nbp->__pardon_count){
        _node->__n_kemu->__dist->__count ++;
    } if(!_node->__nbp->__pardon_maxmin){
        _node->__n_kemu->__dist->__max=max(_node->__n_kemu->__dist->__max, _node->__n_kemu->__value);
        _node->__n_kemu->__dist->__min=min(_node->__n_kemu->__dist->__min, _node->__n_kemu->__value);
    } if(!_node->__nbp->__pardon_dist && _node->__n_kemu->__dist->__count>1){
        /*
            https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance#cite_note-11
        */
        __cwcn_type_t _n = _node->__n_kemu->__dist->__count;
        __cwcn_type_t _delta = _node->__n_kemu->__value - _node->__n_kemu->__dist->__mean;
        __cwcn_type_t _delta_n = _delta/_n;
        __cwcn_type_t _delta_n2 = _delta_n*_delta_n;
        __cwcn_type_t _term1 = _delta*_delta_n*(_n-1);
        _node->__n_kemu->__dist->__mean += _delta_n;
        _node->__n_kemu->__dist->__M4 += _term1*_delta_n2*(_n*_n-3*_n+3)+6*_delta_n2*_node->__n_kemu->__dist->__M2-4*_delta_n*_node->__n_kemu->__dist->__M3;
        _node->__n_kemu->__dist->__M3 += _term1*_delta_n*(_n-2)-3*_delta_n*_node->__n_kemu->__dist->__M2;
        _node->__n_kemu->__dist->__M2 += _term1;
        _node->__n_kemu->__dist->__std = _node->__n_kemu->__dist->__M2/(_n-1);
        _node->__n_kemu->__dist->__kurtosis = (_n*_node->__n_kemu->__dist->__M4)/(_node->__n_kemu->__dist->__M2*_node->__n_kemu->__dist->__M2)-3;
        _node->__n_kemu->__dist->__skewness = sqrt(_n)*_node->__n_kemu->__dist->__M3/(pow(_node->__n_kemu->__dist->__M2,3)*sqrt(_node->__n_kemu->__dist->__M2));
    } if(!_node->__nbp->__pardon_entropy){
        #ifdef NAT_TYPE
            _node->__n_kemu->__dist->__entropy = (-1)*_node->__n_kemu->__value*log(_node->__n_kemu->__value);
        #endif
    }
}
void tsinuu_direct_uwaabo_full_parametric(__tsinuu_t *_tsinuu){ // #FIXME make function pointing to line coord instead of node, #FIXME make nable for lines.
    /* THIS METHOD ASSUMES PREVIUS DEFINITION OF NODE-and-LINE-BOOLEAN-PARAMETRICS:
        __nodeboolean_parametric_t {
            __pardon_value  (set) -
            __pardon_grad   (set) -
            __pardon_bias   (set) -
            __pardon_maxmin (set) -
            __pardon_entropy(set) -
            __pardon_dist   (set) -
            __pardon_count  (set) -
            __pardon_error  =0x0X -
            __has_value     (set) -
            __has_grad      =0x0X -
            __is_input      =0x0X -
            __is_output     =0x0X -
            __is_reset      =0x0X -
        }
        __lineboolean_parametric_t {
            __pardon_grad   =0x0X -
            __pardon_weight (set) -
            __has_grad      =0x0X -
        }
    */
    // #FIXME assert is direct
    reset_all_nodes_grad(_tsinuu);
    reset_all_noninputnodes_values(_tsinuu);
    reset_layerdentities(_tsinuu);
    __cwcn_type_t c_sum = 0x00;
    __node_tsinuu_t *c_to_node;
    __node_tsinuu_t *c_from_node;
    __line_tsinuu_t *c_line;
    unsigned int ln_ctx = 0x00;
    for(unsigned int idx_l_to=0x00;idx_l_to<total_layers(_tsinuu);idx_l_to++){
        for(unsigned int idx_n_to=0x00;idx_n_to<layer_size_from_layer_stack_index(_tsinuu, idx_l_to);idx_n_to++){
            c_to_node = node(_tsinuu, node_index_to_node_coord(_tsinuu, idx_l_to, idx_n_to));
            if(!c_to_node->__nbp->__pardon_value){
                if(c_to_node->__nbp->__is_input){
                    /*
                        NODE IS OF CLASS INPUT, 
                        input can still transform with (bais) and (activation function) the 
                        <set_input(...)>-function-placed-values. It acomulates distribution measures of it's value.
                    */
                    c_sum = c_to_node->__n_kemu->__value;
                } else {
                    /*
                        NODE IS OF CLASS HIDDEN/OUTPUT,
                        For a forward tsinuu, a hidden is alike the output. So output transform with 
                        (activation function) and with (bias). And acomulates distribution.
                        There is an util function: pardon_inputoutput_bias(...); So the tsinuu has no 
                        bias on the extrema. 
                        #FIXME find what is different for output.
                    */
                    _tsinuu->__attributes->__layerweight_density[idx_l_to-0x01]=0x00;
                    for(unsigned int idx_n_from=0x00;idx_n_from<layer_size_from_layer_stack_index(_tsinuu, idx_l_to-0x01);idx_n_from++){
                        c_from_node = node(_tsinuu, node_index_to_node_coord(_tsinuu, idx_l_to-0x01, idx_n_from));
                        c_line = line(_tsinuu, line_index_to_line_coord(_tsinuu, _tsinuu->__attributes->__forward_ln_index_list[ln_ctx]));
                        if(!c_line->__lnbp->__pardon_weight){
                            c_sum += c_line->__ln_kemu->__weight*c_from_node->__n_kemu->__value;
                        } else {
                            c_sum += c_from_node->__n_kemu->__value;
                        }
                        _tsinuu->__attributes->__layerweight_density[idx_l_to-0x01]+=c_line->__ln_kemu->__weight;
                        // print_line_by_coord(_tsinuu, line_index_to_line_coord(_tsinuu, _tsinuu->__attributes->__forward_ln_index_list[ln_ctx]));
                        // fprintf(stdout,"\n");
                        ln_ctx++; // accessing lines by this way is dangerous, # FIXME
                    }
                }
                if(!c_to_node->__nbp->__pardon_bias){
                    c_sum += c_to_node->__n_kemu->__bias;
                }
                c_to_node->__n_kemu->__value = c_to_node->__direct(c_sum);
                c_sum=max(c_sum,-5);
                c_sum=min(c_sum,5);
                if(!c_to_node->__nbp->__pardon_grad){
                    if(c_to_node->__type==SIGMOID){
                        c_to_node->__n_kemu->__nodeactivation_grad=nat_sigmoid_direct_derivate_fast(c_to_node->__n_kemu->__value);
                    } else {
                        c_to_node->__n_kemu->__nodeactivation_grad=c_to_node->__direct_derivate(c_sum);
                    }
                    c_to_node->__nbp->__has_grad=___CWCN_TRUE;
                }
                c_to_node->__nbp->__is_reset=___CWCN_FALSE;
                c_to_node->__nbp->__has_value=___CWCN_TRUE;
                dist_node(_tsinuu, c_to_node);
                // print_node_by_coord_with_argument(_tsinuu, node_index_to_node_coord(_tsinuu, idx_l_to, idx_n_to), c_sum);
                // fprintf(stdout,"\n");
                c_sum = 0x00;
            }
        }
        // _tsinuu->__attributes->__layerweight_density[idx_l_to]=; ...
        // // fprintf(stdout, "------------------------(+1)LAYER----------------------\n");
        // // fprintf(stdout, "---------LAYER(from)------[%d][.]\n",idx_l_to);
        // // print_layer_by_coord(_tsinuu, layer_index_to_layer_coord(_tsinuu,idx_l_to-0x01));
        // // fprintf(stdout, "\n");
        // // fprintf(stdout, "---------NODE(to)------[%d][%d]\n",idx_l_to,idx_n_to);
        // // fprintf(stdout, "---------NODE(from)------[%d]\n",idx_n_from);
        // // fprintf(stdout, "\n");
        
        // fprintf(stdout, "---------LAYER(to)------[%d][.]\n",idx_l_to);
        // print_layer_by_coord(_tsinuu, layer_index_to_layer_coord(_tsinuu,idx_l_to));
    }
    /*
        IS OF CLASS OUTPUT
    */
    #ifdef TSINUU_DEBUG
        fprintf(stderr, ">>>> request <tsinuu_direct_uwaabo_full_parametric>\n");
        fprintf(stderr, ">>>> suspect element value first output:\t %f\n",node(_tsinuu, node_index_to_node_coord(_tsinuu, output_layer_index(_tsinuu), 0x00))->__n_kemu->__value);
    #endif
}

// void tsinuu_direct_uwaabo_fast(__tsinuu_t *_tsinuu){ // #FIXME make function pointing to line coord instead of node
//     /* THIS METHOD WORK WITH NODE-and-LINE-BOOLEAN-PARAMETRICS AS: (using fast serves not for jkimyei)
//         __nodeboolean_parametric_t {
//             __pardon_value  =0x00
//             __pardon_grad   =0x01
//             __pardon_bias   =0x00
//             __pardon_maxmin =0x01
//             __pardon_entropy=0x01
//             __pardon_dist   =0x01
//             __pardon_count  =0x00
//             __pardon_error  =0x0X
//             __has_value     =0x01
//             __has_grad      =0x0X
//             __is_input      =0x0X
//             __is_output     =0x0X
//             __is_reset      =0x0X
//         }
//         __lineboolean_parametric_t {
//             __pardon_grad   =0x0X
//             __pardon_weight =0x00
//             __has_grad      =0x0X
//         }
//     */
// }
/*

*/

void jkimyei_tsinuu_bydirectNABLA(__tsinuu_t *_tsinuu){ // #FIXME make function pointing to line coord instead of node
    /* THIS METHOD ASSUMES PREVIUS DEFINITION OF NODE-and-LINE-BOOLEAN-PARAMETRICS:
        __nodeboolean_parametric_t {
            __pardon_value  (set)
            __pardon_grad   (set) 
            __pardon_bias   (set)
            __pardon_maxmin =0x0X
            __pardon_entropy=0x0X
            __pardon_dist   =0x0X
            __pardon_count  =0x0X
            __pardon_error  (set)
            __has_value     (set)
            __has_grad      =0x0X
            __is_input      =0x0X
            __is_output     =0x0X
            __is_reset      =0x0X
        }
        __lineboolean_parametric_t {
            __pardon_grad   (set)
            __pardon_weight (set)
            __has_grad      =0x0X
        }
    */
    // #FIXME check if each node __has_value
    __line_tsinuu_t *c_line;
    __node_tsinuu_t *c_node_to;
    __node_tsinuu_t *c_node_from;
    __cwcn_type_t c_sum = 0x00;
    __cwcn_type_t *c_wapaajco_vector=malloc(output_size(_tsinuu)*sizeof(__cwcn_type_t));
    read_wapaajco(_tsinuu, c_wapaajco_vector);
    reset_all_nodes_error(_tsinuu); // #FIXME what!
    /*
        __NABLA (or backward pass during trainin)
        
        NODE IS OF CLASS OUTPUT, therefore has error. Calculate initial values for nabla
        NODE IS OF CLASS HIDDEN/INPUT, therefore has weight-lines.
    */
    // goto last layer (output __nabla is special)
    for(unsigned int idx_n_from=output_size(_tsinuu)-0x01;idx_n_from>=0x00;idx_n_from--){
        c_node_from = node(_tsinuu, node_index_to_node_coord(_tsinuu, output_layer_index(_tsinuu), idx_n_from));
        if(!c_node_from->__nbp->__has_grad){
            fprintf(stderr, ">>>> ERROR: node must have (_has_grad) [%d][%d].\n",output_layer_index(_tsinuu),idx_n_from);
            assert(0x00);
        }
        if(!c_node_from->__nbp->__is_output){
            fprintf(stderr, "ERROR: problem with layers order...");
            assert(0x00);
        }
        c_node_from->__n_kemu->__nabla=c_wapaajco_vector[idx_n_from]*c_node_from->__n_kemu->__nodeactivation_grad;
        #ifdef TSINUU_VERBOSE_2
            fprintf(stdout,"\033[0;35m");
            fprintf(stdout,"NODE:[%d][%d]:  <<Nabla = _wapaajco*biasGrad.>>\t\t\tNabla:%2.5f   biasGrad:%2.3f   \033[0;32m_wapaajco[%d]\033[0m:%2.3f\n",output_layer_index(_tsinuu),idx_n_from,c_node_from->__n_kemu->__nabla,c_node_from->__n_kemu->__nodeactivation_grad,idx_n_from,c_wapaajco_vector[idx_n_from]);
            fprintf(stdout,"\033[0m");
        #endif
        if(idx_n_from==0){break;}
    }
    // goto rest
    ___cwcn_bool_t allin_flag = 0x00;
    unsigned int ln_ctx = total_lines(_tsinuu)-0x01;
    for(unsigned int idx_l_from=total_layers(_tsinuu)-0x02;idx_l_from>=0x00;idx_l_from--){ // omits input
        for(unsigned int idx_n_from=layer_size_from_layer_stack_index(_tsinuu, idx_l_from)-0x01;idx_n_from>=0x00;idx_n_from--){
            c_node_from = node(_tsinuu, node_index_to_node_coord(_tsinuu, idx_l_from, idx_n_from));
            if(!c_node_from->__nbp->__has_grad){
                fprintf(stderr, ">>>> ERROR: node must have (_has_grad) [%d][%d].\n",idx_l_from,idx_n_from);
                assert(0x00);
            }
            for(unsigned int idx_n_to=layer_size_from_layer_stack_index(_tsinuu, idx_l_from+0x01)-0x01;idx_n_to>=0x00;idx_n_to--){
                c_line=_tsinuu->__lines[_tsinuu->__attributes->__backward_ln_index_list[ln_ctx]];
                c_node_to = node(_tsinuu, node_index_to_node_coord(_tsinuu, idx_l_from+0x01, idx_n_to));
                c_sum+=nat_signedsigmoid_direct(c_line->__ln_kemu->__weight*c_node_to->__n_kemu->__nabla); // #FIXME here is a problem, vanishing gradient
                #ifdef TSINUU_VERBOSE_2
                    fprintf(stdout,"\033[0;35m\t");
                    print_line_by_coord(_tsinuu, line_index_to_line_coord(_tsinuu,_tsinuu->__attributes->__backward_ln_index_list[ln_ctx]));
                    fprintf(stdout,"\t c_sum:%f\n",c_sum);
                    fprintf(stdout,"\033[0m");
                #endif
                if(n_coord_to_l_index(c_line->__ln_coord->__to_node)==idx_l_from+0x01 && n_coord_to_n_index(c_line->__ln_coord->__to_node)==idx_n_to){
                    if(n_coord_to_l_index(c_line->__ln_coord->__from_node)==idx_l_from && n_coord_to_n_index(c_line->__ln_coord->__from_node)==idx_n_from){
                        allin_flag=0x01;
                    }
                }
                if(!allin_flag){
                    fprintf(stderr, ">>>> ERROR: -p- huge problem, line index are not listed as expected.");
                    assert(0x00);
                }
                allin_flag=0x00;
                ln_ctx--;
                if(idx_n_to==0){break;}
            }
            c_node_from->__n_kemu->__nabla=c_sum*c_node_from->__n_kemu->__nodeactivation_grad;
            #ifdef TSINUU_VERBOSE_2
                fprintf(stdout,"\033[0;35m");
                fprintf(stdout,"NODE :(from):[%d][%d]: <<Nabla = c_sum*biasGrad.>>\t\t\t\tNabla:%2.5f   biasGrad:%2.3f   c_sum:%2.3f\n",idx_l_from,idx_n_from,c_node_from->__n_kemu->__nabla,c_node_from->__n_kemu->__nodeactivation_grad,c_sum);
                fprintf(stdout,"\033[0m");
            #endif
            c_sum = 0x00;
            if(idx_n_from==0){break;}
        }
        if(idx_l_from==0){break;}
    }
    free(c_wapaajco_vector);
    /*
        __DELTA (or forward pass during training)
    */
    ln_ctx = 0x00;
    for(unsigned int idx_l_to=0x00;idx_l_to<total_layers(_tsinuu);idx_l_to++){
        for(unsigned int idx_n_to=0x00;idx_n_to<layer_size_from_layer_stack_index(_tsinuu, idx_l_to);idx_n_to++){
            c_node_to = node(_tsinuu, node_index_to_node_coord(_tsinuu, idx_l_to, idx_n_to));
            if(c_node_to->__nbp->__pardon_grad){
                fprintf(stderr,"ERROR! node pardon grad is unexpected: NODE[%d][%d]\n",idx_l_to,idx_n_to);
                assert(0x00);
            }
            if(c_node_to->__nbp->__is_input){
                // #FIXME lack input layer
            } else {
                if(!c_node_to->__nbp->__pardon_bias){ // Update bias
                    c_node_to->__n_kemu->__bias_delta=nat_signedsigmoid_direct(_tsinuu->__attributes->__eta*c_node_to->__n_kemu->__nabla)+nat_signedsigmoid_direct(_tsinuu->__attributes->__alpha*c_node_to->__n_kemu->__bias_delta);
                    // c_node_to->__n_kemu->__bias_delta=_tsinuu->__attributes->__omega*nat_signedsigmoid_direct(_tsinuu->__attributes->__omega_stiffess*c_node_to->__n_kemu->__bias_delta);
                    c_node_to->__n_kemu->__bias_delta = _tsinuu->__attributes->__omega*c_node_to->__n_kemu->__bias_delta;
                    c_node_to->__n_kemu->__bias+=c_node_to->__n_kemu->__bias_delta;
                    clamp_bias(_tsinuu, c_node_to->__n_kemu);
                    #ifdef TSINUU_VERBOSE_2
                        fprintf(stdout,"\033[0;34m");
                        // fprintf(stdout,"NODE:[%d][%d]:<<biasDelta[k] = __eta * Nabla + alpha * biasDelta[k-1].>>\n\t\t\t__eta:%2.3f * Nabla:%9.3f + __alpha:%2.3f * biasDelta:%2.3f\n",idx_l_to,idx_n_to,_tsinuu->__attributes->__eta,c_node_to->__n_kemu->__nabla,_tsinuu->__attributes->__alpha,c_node_to->__n_kemu->__bias_delta);
                        fprintf(stdout,"NODE:[%d][%d]:<<biasDelta[k] = omega * phi(omgStiff * (__eta * Nabla + alpha * biasDelta[k-1])).>>\n\t\t\t__omega: %2.3f __eta:%2.3f  Nabla:%9.3f  __alpha:%2.3f biasDelta:%2.3f\n",idx_l_to,idx_n_to,_tsinuu->__attributes->__omega, _tsinuu->__attributes->__eta,c_node_to->__n_kemu->__nabla,_tsinuu->__attributes->__alpha,c_node_to->__n_kemu->__bias_delta);
                    #endif
                    #ifdef TSINUU_VERBOSE_1
                        fprintf(stdout,"\033[0;34m");
                        fprintf(stdout,"\tBIAS:[%d][%d]:\tbias:%2.3f\t biasDelta[k]:%2.3f\n",idx_l_to,idx_n_to,c_node_to->__n_kemu->__bias,c_node_to->__n_kemu->__bias_delta);
                        fprintf(stdout,"\033[0m");
                    #endif
                } else {
                    #ifdef TSINUU_DEBUG
                        fprintf(stdout,"NODE:[%d][%d]: (bias desactivated for node)\n",idx_l_to,idx_n_to);
                    #endif
                }
                /* LINES */
                for(unsigned int idx_n_from=0x00;idx_n_from<layer_size_from_layer_stack_index(_tsinuu, idx_l_to-0x01);idx_n_from++){
                    c_line=_tsinuu->__lines[_tsinuu->__attributes->__forward_ln_index_list[ln_ctx]]; // #FIXME assert!
                    if(n_coord_to_l_index(c_line->__ln_coord->__to_node)==idx_l_to && n_coord_to_n_index(c_line->__ln_coord->__to_node)==idx_n_to){
                        if(n_coord_to_l_index(c_line->__ln_coord->__from_node)==idx_l_to-0x01 && n_coord_to_n_index(c_line->__ln_coord->__from_node)==idx_n_from){
                            allin_flag=0x01;
                        }
                    }
                    // fprintf(stdout," %d==%d \t %d==%d \t %d==%d \t %d==%d\n",n_coord_to_l_index(c_line->__ln_coord->__to_node),idx_l_to, n_coord_to_n_index(c_line->__ln_coord->__to_node),idx_n_to, n_coord_to_l_index(c_line->__ln_coord->__from_node),idx_l_to-0x01, n_coord_to_n_index(c_line->__ln_coord->__from_node),idx_n_from);
                    if(!allin_flag){
                        fprintf(stderr, ">>>> ERROR: -v- huge problem, line index are not listed as expected.");
                        assert(0x00);
                    }
                    allin_flag=0x00;
                    if(!c_line->__lnbp->__pardon_grad){
                        c_node_from = node(_tsinuu, node_index_to_node_coord(_tsinuu, idx_l_to-0x01, idx_n_from));
                        c_line->__ln_kemu->__weight_delta=nat_signedsigmoid_direct(_tsinuu->__attributes->__eta*c_node_from->__n_kemu->__value*c_node_to->__n_kemu->__nabla)+nat_signedsigmoid_direct(_tsinuu->__attributes->__alpha*c_line->__ln_kemu->__weight_delta);
                        #ifdef TSINUU_VERBOSE_2
                            fprintf(stdout,"\033[0;32m");
                            fprintf(stdout,"\tLINE:[%d]:<<weightDelta[k] = __eta * nodeValue[%d][%d] * Nabla[%d][%d] + __alpha * weightDelta[k-1]>>\n\t\t\t__eta:%2.3f * __value: %2.3f * __weight_nabla:%2.3f + __alpha:%2.3f * __weight_delta:%2.3f\n\t",ln_ctx,idx_l_to-0x01, idx_n_from, idx_l_to, idx_n_to,_tsinuu->__attributes->__eta,c_node_from->__n_kemu->__value,c_node_to->__n_kemu->__nabla,_tsinuu->__attributes->__alpha,c_line->__ln_kemu->__weight_delta);
                            print_line_by_coord(_tsinuu, line_index_to_line_coord(_tsinuu, ln_ctx));
                        #endif
                        // c_line->__ln_kemu->__weight_delta = _tsinuu->__attributes->__omega*nat_signedsigmoid_direct(_tsinuu->__attributes->__omega_stiffess*c_line->__ln_kemu->__weight_delta);
                        c_line->__ln_kemu->__weight_delta = _tsinuu->__attributes->__omega*c_line->__ln_kemu->__weight_delta;
                        c_line->__ln_kemu->__weight+=c_line->__ln_kemu->__weight_delta;
                        clamp_weight(_tsinuu, c_line->__ln_kemu);
                        #ifdef TSINUU_VERBOSE_1
                            fprintf(stdout,"\033[0;32m");
                            fprintf(stdout,"\tWEIGHT:[%d]:\tweight:%2.3f\tweightDelta[k]:%2.3f\n",ln_ctx,c_line->__ln_kemu->__weight,c_line->__ln_kemu->__weight_delta);
                            fprintf(stdout,"\033[0m");
                        #endif
                    } else {
                        fprintf(stderr, ">>>> ERROR: unexpected pardon gran appeared, for line [%d]...\n",_tsinuu->__attributes->__forward_ln_index_list[ln_ctx]);
                        assert(0x00);
                    }
                    ln_ctx++;
                }
            }
        }
    }
    clamp_all_weights(_tsinuu);
    clamp_all_bias(_tsinuu);
    #ifdef TSINUU_DEBUG
        fprintf(stderr, ">>>> request <jkimyei_bydirectNABLA>\n");
        fprintf(stderr, ">>>> suspect element value first output:\t %f\n",node(_tsinuu, node_index_to_node_coord(_tsinuu, output_layer_index(_tsinuu), 0x00))->__n_kemu->__value);
    #endif
}

/*

*/
void wapaajco_bydifference(__tsinuu_t *_tsinuu, __cwcn_type_t *_correct_output){
    __cwcn_type_t *_c_output=malloc(layer_size_from_layer_stack_index(_tsinuu,output_layer_index(_tsinuu))*sizeof(__cwcn_type_t));
    read_output(_tsinuu,_c_output);
    for(unsigned int idx_n=0x00;idx_n<layer_size_from_layer_stack_index(_tsinuu,output_layer_index(_tsinuu));idx_n++){
        _tsinuu->__wapaajco->__w_vector[idx_n]=_tsinuu->__attributes->__wapaajco_potency*(_correct_output[idx_n]-_c_output[idx_n]);
        _tsinuu->__wapaajco->__total_wapaajco+=fabs(_tsinuu->__wapaajco->__w_vector[idx_n]);
    }
    #ifdef TSINUU_DEBUG
        fprintf(stdout,">>>> request <wapaajco_bydifference>\n");
    #endif
    free(_c_output);
}
void set_wapaajco(__tsinuu_t *_tsinuu, __cwcn_type_t *_set_wapaajco){
    for(unsigned int idx_n=0x00;idx_n<layer_size_from_layer_stack_index(_tsinuu,output_layer_index(_tsinuu));idx_n++){
        _tsinuu->__wapaajco->__w_vector[idx_n]=_tsinuu->__attributes->__wapaajco_potency*_set_wapaajco[idx_n];
    }
    #ifdef TSINUU_DEBUG
        fprintf(stdout,">>>> request <set_wapaajco>\n");
    #endif
}
void set_wapaajco_eq(__tsinuu_t *_tsinuu, __cwcn_type_t _set_wapaajco){
    for(unsigned int idx_n=0x00;idx_n<layer_size_from_layer_stack_index(_tsinuu,output_layer_index(_tsinuu));idx_n++){
        _tsinuu->__wapaajco->__w_vector[idx_n]=_tsinuu->__attributes->__wapaajco_potency*_set_wapaajco;
    }
    #ifdef TSINUU_DEBUG
        fprintf(stdout,">>>> request <set_wapaajco_eq>\n");
    #endif
}
void set_wapaajco_index_eq(__tsinuu_t *_tsinuu, __cwcn_type_t _set_wapaajco, unsigned int _index){
    _tsinuu->__wapaajco->__w_vector[_index]=_tsinuu->__attributes->__wapaajco_potency*_set_wapaajco;
    #ifdef TSINUU_DEBUG
        fprintf(stdout,">>>> request <set_wapaajco_index_eq>\n");
    #endif
}
/*

*/
void set_seed(){
    srand(time(NULL)); // #FIXME
}