

/*
    ACTIVATIONS
*/
__cwcn_type_t nat_sigmoid_direct(__cwcn_type_t _input){return 1.0/(1.0+exp(-_input));}
__cwcn_type_t nat_sigmoid_direct_derivate(__cwcn_type_t _input){return nat_sigmoid_direct(_input)*(1-nat_sigmoid_direct(_input));} // #FIXME, better perfornce if direct value is saved.
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
void tsinuu_initialize_weights(__tsinuu_t * _tsinuu){ // #FIXME, add other than random
    for(unsigned int l_ctx=0; l_ctx < total_lines(_tsinuu); l_ctx++){
        _tsinuu->__lines[l_ctx]->__weight = (__cwcn_type_t) (rand() % 300 - 150)/(100.0);
    }
    #ifdef TSINUU_DEBUG
    // fprintf(stderr, ">>>> suspect element value _ %d  must be equal to _ %d\n",);
    // fprintf(stderr, ">>>> suspect element address _ %p  must be equal to _ %p\n", (void *) &_tsinuu, );
    #endif
}
void tsinuu_direct_propagate(__tsinuu_t * _tsinuu, __cwcn_type_t * _input){
    #ifndef SYMETRIC_TSINUU
    fprintf(stderr, "This method for direct propagation assumes SYMETRIC_TSINUU definition");
    assert(0x00);
    #endif
    /*
        tsinuu_t * _tsinuu
        _Bool _pardon_bias
        _Bool _pardon_grad
        _Bool _pardon_maxmin
        _Bool _pardon_dist
    */
    reset_all_nodes_kemu(_tsinuu, 0x01, 0x00, 0x01, 0x01);
    set_input(_tsinuu, _input);
    __node_tsinuu_t * c_to_node = malloc(sizeof(__node_tsinuu_t));
    __kemu_tsinuu_t * c_to_node_kemu = malloc(sizeof(__kemu_tsinuu_t));
    __cwcn_type_t c_val = 0x00;
    unsigned int ln_ctx = 0x01;
    for(unsigned int idx_n_to=0x00;idx_n_to<layer_size(_tsinuu, 0x00);idx_n_to++){ // first layer is special
        c_to_node = node(_tsinuu, 0x00, idx_n_to);
        c_to_node_kemu = c_to_node->__kemu;
        c_to_node_kemu->__value += c_to_node->__direct(c_to_node_kemu->__value);
        c_to_node_kemu->__value += c_to_node_kemu->__bias;
    }
    for(unsigned int idx_l_to=0x01;idx_l_to<total_layers(_tsinuu);idx_l_to++){
        for(unsigned int idx_n_to=0x00;idx_n_to<layer_size(_tsinuu, idx_l_to);idx_n_to++){
            c_to_node = node(_tsinuu, idx_l_to, idx_n_to);
            c_to_node_kemu = c_to_node->__kemu;
            for(unsigned int idx_n_from=0x00;idx_n_from<layer_size(_tsinuu, idx_l_to-0x01);idx_n_from++){
                c_val += _tsinuu->__lines[ln_ctx]->__weight * node_kemu(_tsinuu, (idx_l_to-0x01), idx_n_from)->__value; // #FIXME, avoid the node method call
                ln_ctx++;
            }
            c_to_node_kemu->__value += c_to_node_kemu->__bias;
            c_to_node_kemu->__value += c_to_node->__direct(c_val);
            c_val = 0x00;
        }
    }
    free(c_to_node);
    free(c_to_node_kemu);
    #ifdef TSINUU_DEBUG
    fprintf(stderr, ">>>> suspect element value _ %d  must be equal to _ %d\n",);
    fprintf(stderr, ">>>> suspect element address _ %p  must be equal to _ %p\n",);
    #endif
}
void cpte_kemu_firstordedgrad(__tsinuu_t _tsinuu, ___cwcn_bool_t cpte_direct, ___cwcn_bool_t cpte_inverse){}
void cpte_kemu_bias(__tsinuu_t _tsinuu){}
void cpte_kemu_maxmin(__tsinuu_t _tsinuu){}
void cpte_kemu_dist(__tsinuu_t _tsinuu){}

void jkimyei_weight_bydirectdiff(__tsinuu_t _tsinuu){}
void jkimyei_bias_bydirectdiff(__tsinuu_t _tsinuu){}

void tsinuu_inverse_propagate(__tsinuu_t * _tsinuu, __cwcn_type_t * _output){}
void jkimyei_weight_byinversediff(__tsinuu_t _tsinuu){}
void jkimyei_bias_byinversediff(__tsinuu_t _tsinuu){}