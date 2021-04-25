#include "cwcn_tsinuu_nebajke.h"
#include "cwcn_tsinuu_piaabo.h"

// void tsinuu_inverse_propagate(__tsinuu_t *_tsinuu, __cwcn_type_t *_output);
// void jkimyei_weight_byinversediff(__tsinuu_t *_tsinuu);
// void jkimyei_bias_byinversediff(__tsinuu_t _tsinuu);
// void tsinuu_direct_propagate(__tsinuu_t *_tsinuu, __cwcn_type_t *_input);
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

__cwcn_type_t linear_direct(__cwcn_type_t _input){return _input;}
__cwcn_type_t linear_direct_derivate(__cwcn_type_t _input){return 1.0;}
__cwcn_type_t linear_inverse(__cwcn_type_t _input){return _input;}
__cwcn_type_t linear_inverse_derivate(__cwcn_type_t _input){return 1.0;}
// __cwcn_type_t bin_sigmoid_forward(__cwcn_type_t _input){return (__cwcn_type_t) 0x0F>>((__cwcn_type_t) 0x0F + (__cwcn_type_t) 0x0F<<(__cwcn_type_t) _input);} // #FIXME

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
void tsinuu_direct_propagate_full_parametric(__tsinuu_t *_tsinuu){ // #FIXME make function pointing to line coord instead of node, #FIXME make nable for lines.
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
    reset_all_nodes_grad(_tsinuu);
    reset_all_noninputnodes_values(_tsinuu);
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
                    for(unsigned int idx_n_from=0x00;idx_n_from<layer_size_from_layer_stack_index(_tsinuu, idx_l_to-0x01);idx_n_from++){
                        c_from_node = node(_tsinuu, node_index_to_node_coord(_tsinuu, idx_l_to-0x01, idx_n_from));
                        c_line = line(_tsinuu, line_index_to_line_coord(_tsinuu, ln_ctx));
                        if(!c_line->__lnbp->__pardon_weight){
                            c_sum += c_line->__ln_kemu->__weight*c_from_node->__n_kemu->__value;
                        } else {
                            c_sum += c_from_node->__n_kemu->__value;
                        }
                        // print_line_by_coord(_tsinuu, line_index_to_line_coord(_tsinuu, ln_ctx));
                        // fprintf(stdout,"\n");
                        ln_ctx++; // accessing lines by this way is dangerous, # FIXME
                    }
                }
                if(!c_to_node->__nbp->__pardon_bias){
                    c_sum += c_to_node->__n_kemu->__bias;
                }
                c_to_node->__n_kemu->__value = c_to_node->__direct(c_sum);
                if(!c_to_node->__nbp->__pardon_grad){
                    if(c_to_node->__type==SIGMOID){
                        c_to_node->__n_kemu->__bias_grad=nat_sigmoid_direct_derivate_fast(c_to_node->__n_kemu->__value);
                    } else {
                        c_to_node->__n_kemu->__bias_grad=c_to_node->__direct_derivate(c_sum);
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
    fprintf(stdout, "\n");
    #ifdef TSINUU_DEBUG
        fprintf(stderr, ">>>> request <tsinuu_direct_propagate_full_parametric>\n");
        fprintf(stderr, ">>>> suspect element value first output:\t %f\n",node(_tsinuu, node_index_to_node_coord(_tsinuu, output_layer_index(_tsinuu), 0x00))->__n_kemu->__value);
    #endif
}

// void tsinuu_direct_propagate_fast(__tsinuu_t *_tsinuu){ // #FIXME make function pointing to line coord instead of node
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

void jkimyei_bydirectNABLA(__tsinuu_t *_tsinuu, __cwcn_type_t *_output_wapaajco){ // #FIXME make function pointing to line coord instead of node
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
    // #FIXME check __has_value
    reset_all_nodes_error(_tsinuu);
    __node_tsinuu_t *c_node1;
    /*
        NODE IS OF CLASS OUTPUT, therefore has error.
    */
    fprintf(stdout,">> OYUTPUT\n");
    for(unsigned int idx_n1=0x00;idx_n1<layer_size_from_layer_stack_index(_tsinuu, output_layer_index(_tsinuu));idx_n1++){
        c_node1 = node(_tsinuu, node_index_to_node_coord(_tsinuu, output_layer_index(_tsinuu), idx_n1));
        if(!c_node1->__nbp->__has_grad){
            fprintf(stderr, ">>>> ERROR: output node must have (grad) [%d][%d].\n",0x00,idx_n1);
            assert(0x00);
        }
        if(!c_node1->__nbp->__is_output){
            fprintf(stderr, ">>>> ERROR: node was expected to be (output) [%d][%d].\n",0x00,idx_n1);
            assert(0x00);
        }
        // c_node1->__n_kemu->__error=c_node1->__n_kemu->__value-_correct_output[idx_n1];
        #ifdef TSINUU_DEBUG
            fprintf(stdout, ">>>> WARNING: output node with no error computed.\n"); // #FIXME
        #endif
        c_node1->__n_kemu->__bias_nabla=_output_wapaajco[idx_n1]*c_node1->__n_kemu->__bias_grad;
        fprintf(stdout,"node:[%d][%d]:\t__bias_nabla:%9.3f\t__bias_grad:%9.3f\t_output_wapaajco[%d]:%9.3f\n",output_layer_index(_tsinuu),idx_n1,c_node1->__n_kemu->__bias_nabla,c_node1->__n_kemu->__bias_grad,idx_n1,_output_wapaajco[idx_n1]);
    }
    /*
        NODE IS OF CLASS HIDDEN/INPUT, therefore has weight-lines.
    */
    fprintf(stdout,">> HIDDEN INPUT\n");
    __node_tsinuu_t *c_node2;
    __cwcn_type_t c_sum = 0x00;
    unsigned int ln_ctx = total_lines(_tsinuu)-0x01;
    for(unsigned int idx_l1=total_layers(_tsinuu)-0x02;idx_l1>=0x00;idx_l1--){
        for(unsigned int idx_n1=0x00;idx_n1<layer_size_from_layer_stack_index(_tsinuu, idx_l1);idx_n1++){
            c_node1 = node(_tsinuu, node_index_to_node_coord(_tsinuu, idx_l1, idx_n1));
            if(!c_node1->__nbp->__has_grad){
                fprintf(stderr, ">>>> ERROR: node must have (grad) [%d][%d].\n",idx_l1,idx_n1);
                assert(0x00);
            }
            if(c_node1->__nbp->__is_output){
                fprintf(stderr, ">>>> ERROR: node was expected to be (hidden) or (input) [%d][%d].\n",idx_l1,idx_n1);
                assert(0x00);
            }
            for(unsigned int idx_n2=layer_size_from_layer_stack_index(_tsinuu, idx_l1+0x01)-0x01;idx_n2>=0x00;idx_n2--){
                c_node2 = node(_tsinuu, node_index_to_node_coord(_tsinuu, idx_l1+0x01, idx_n2-0x00));
                c_sum+=_tsinuu->__lines[ln_ctx]->__ln_kemu->__weight*c_node2->__n_kemu->__bias_nabla;
                ln_ctx--;
                if(idx_n2==0){
                    break;
                }
            }
            c_node1->__n_kemu->__bias_nabla=c_sum*c_node1->__n_kemu->__bias_grad;
            fprintf(stdout,"node:[%d][%d]:\t__bias_nabla:%9.3f\t__bias_grad:%9.3f\tc_sum:%9.3f\n",idx_l1,idx_n1,c_node1->__n_kemu->__bias_nabla,c_node1->__n_kemu->__bias_grad,c_sum);
            c_sum = 0x00;
        }
        if(idx_l1==0){
            break;
        }
    }
    __line_tsinuu_t *c_line;
    ln_ctx = 0x00;
    // #FIXME lack input line
    for(unsigned int idx_l1=0x01;idx_l1<total_layers(_tsinuu);idx_l1++){
        for(unsigned int idx_n1=0x00;idx_n1<layer_size_from_layer_stack_index(_tsinuu, idx_l1);idx_n1++){
            c_node1 = node(_tsinuu, node_index_to_node_coord(_tsinuu, idx_l1, idx_n1));
            if(!c_node1->__nbp->__pardon_grad){
                c_node1->__n_kemu->__bias_delta=_tsinuu->__attributes->__eta*c_node1->__n_kemu->__bias_nabla+_tsinuu->__attributes->__alpha*c_node1->__n_kemu->__bias_delta;
                fprintf(stdout,"NODE DELTA:[%d][%d]:\t__eta:%9.3f * __bias_nabla:%9.3f + __alpha:%9.3f * __bias_delta:%9.3f\n",idx_l1,idx_n1,_tsinuu->__attributes->__eta,c_node1->__n_kemu->__bias_nabla,_tsinuu->__attributes->__alpha,c_node1->__n_kemu->__bias_delta);
                c_node1->__n_kemu->__bias+=c_node1->__n_kemu->__bias_delta;
                fprintf(stdout,"NODE DELTA:[%d][%d]:\t__bias_delta:%9.3f\n",idx_l1,idx_n1,c_node1->__n_kemu->__bias_delta);
            }
            for(unsigned int idx_n2=0x00;idx_n2<layer_size_from_layer_stack_index(_tsinuu, idx_l1-0x01);idx_n2++){
                c_line=_tsinuu->__lines[ln_ctx];
                if(!c_line->__lnbp->__pardon_grad){
                    c_node2 = node(_tsinuu, node_index_to_node_coord(_tsinuu, idx_l1-0x01, idx_n2));
                    c_line->__ln_kemu->__weight_delta=_tsinuu->__attributes->__eta*c_node2->__n_kemu->__value*c_node1->__n_kemu->__bias_nabla+_tsinuu->__attributes->__alpha*c_line->__ln_kemu->__weight_delta;
                    fprintf(stdout,"LINE DELTA:[%d]:\t__eta:%9.3f * __value: %9.3f * __weight_nabla:%9.3f + __alpha:%9.3f * __weight_delta:%9.3f\n",ln_ctx,_tsinuu->__attributes->__eta,c_node2->__n_kemu->__value,c_node1->__n_kemu->__bias_nabla,_tsinuu->__attributes->__alpha,c_line->__ln_kemu->__weight_delta);
                    c_line->__ln_kemu->__weight+=c_line->__ln_kemu->__weight_delta;
                    fprintf(stdout,"LINE DELTA:[%d]:\t__weight_delta:%9.3f\n",ln_ctx,c_line->__ln_kemu->__weight_delta);
                }
                ln_ctx++;
            }
        }
    }
    #ifdef TSINUU_DEBUG
        fprintf(stderr, ">>>> request <jkimyei_bydirectNABLA>\n");
        fprintf(stderr, ">>>> suspect element value first output:\t %f\n",node(_tsinuu, node_index_to_node_coord(_tsinuu, output_layer_index(_tsinuu), 0x00))->__n_kemu->__value);
    #endif
}

/*

*/
__cwcn_type_t *wapaajco_bydifference(__tsinuu_t *_tsinuu, __cwcn_type_t *_correct_output){
    __cwcn_type_t *_wapaajco=malloc(layer_size_from_layer_stack_index(_tsinuu,output_layer_index(_tsinuu))*sizeof(__cwcn_type_t));
    __cwcn_type_t *_c_output=malloc(layer_size_from_layer_stack_index(_tsinuu,output_layer_index(_tsinuu))*sizeof(__cwcn_type_t));
    read_output(_tsinuu,_c_output);
    for(unsigned int idx_n=0x00;idx_n<layer_size_from_layer_stack_index(_tsinuu,output_layer_index(_tsinuu));idx_n++){
        _wapaajco[idx_n]=_correct_output[idx_n]-_c_output[idx_n];
    }
    #ifdef TSINUU_DEBUG
        fprintf(stdout,">>>> request <wapaajco_bydifference>\n");
        fprintf(stdout,">>>> WARINING: wapaajco returned variable must be free after usage\n");
    #endif
    free(_c_output);
    return _wapaajco;
}
/*

*/
void set_seed(){
    srand(time(NULL)); // #FIXME
}