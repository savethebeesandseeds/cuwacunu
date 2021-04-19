#include "cwcn_tsinuu_piaabo.h"
// fprintf(stderr, "<<all mallocs must be asserted not NULL.>> ");
// fprintf(stderr, "<<check for size zero allocation and turn them into size one allocation, for saefty>>");
// _msize(*ptr) is a util function
/*
    In cuwacunu: 
    value_tsinuu[0x00 * __cwcn_type_size] is <<input value>> pointer, 
    value_tsinuu[0xlast * __cwcn_type_size] is <<output value>> pointer.
    value_tsinuu[(Ox00 + 0x00) * __cwcn_type_size] is first <<input value>> pointer.
    value_tsinuu[(Oxlast + 0x00) * __cwcn_type_size]] is first  <<output value>> pointer.

    *
        c_num_hidden is the iterative sum of input+hidden+output sizes
    *
    layer_tsinuu[(0x00 * num_layers + 0x00 * c_num_hidden + 0x00) * __cwcn_type_size] is for layer zero first value conection to layer one first value (layer zero is also known as input) it's <<bias>> value pointer, 
    layer_tsinuu[(0x00 * num_layers + 0x00 * c_num_hidden + 0x01) * __cwcn_type_size] is for layer zero first value conection to layer one first value (layer zero is also known as input) it's <<weight>> value pointer, 
    layer_tsinuu[(0xlast...) * __cwcn_type_size] DOES NOT EXIST. (last layer is output, there is no weight or bias for output)
    layer_tsinuu[(0xlast...) * __cwcn_type_size] DOES NOT EXIST.

    node_tsinuu[(0x00 * num_layers *num_hidden -(num_input - num_hidden) - (num_output - num_hidden) + 0x00 activation) * __function_pointer_size] is the pointer
    node_tsinuu[(0x00 * num_layers *num_hidden -(num_input - num_hidden) - (num_output - num_hidden) + 0x01 derivate) * __function_pointer_size] is the pointer
*/

/*
    UTILS
*/
unsigned int total_layers(tsinuu_t * _tsinuu){
    return _tsinuu->__attributes->__NUM_TOTAL_LAYERS;
}
unsigned int total_nodes(tsinuu_t * _tsinuu){
    return _tsinuu->__attributes->__NUM_TOTAL_NODES;
}
unsigned int total_lines(tsinuu_t * _tsinuu){
    return _tsinuu->__attributes->__NUM_TOTAL_LINES;
}

unsigned int layer_size(tsinuu_t * _tsinuu, unsigned int idx_l){
    #ifdef TSINUU_PIAABO_DEBUG
        if(idx_l>=total_layers(_tsinuu)){
            fprintf(stderr, "ERROR: idx__line exceeds maxima, try NUM_LAYERS-0x01, for last layer.");
            assert(0x00);
        }
    #endif
    return _tsinuu->__attributes->__LAYERS_SIZES[idx_l];
}
unsigned int input_size(tsinuu_t * _tsinuu){
    return layer_size(_tsinuu, (0x00));
}
unsigned int output_size(tsinuu_t * _tsinuu){
    return layer_size(_tsinuu, (total_layers(_tsinuu)-0x01));
}

unsigned int idx_idx_sumupto_layer(tsinuu_t * _tsinuu, unsigned int idx_l){
    unsigned int l_ctx = 0x00;
    for(unsigned int idx_l2=0x00;idx_l2<idx_l;idx_l2++){
        l_ctx+=layer_size(_tsinuu,idx_l2);
    }
    #ifdef TSINUU_PIAABO_DEBUG
        if(l_ctx>total_layers(_tsinuu)){
            fprintf(stderr, "ERROR: idx_idx_sumupto_layer exceeds maxima.");
            assert(0x00);
        }
    #endif
    return l_ctx;
}
unsigned int idx_sumupto_node(tsinuu_t * _tsinuu, unsigned int idx_l ,unsigned int idx_n){
    unsigned int ctx_n = idx_idx_sumupto_layer(_tsinuu, idx_l) + idx_n;
    #ifdef TSINUU_PIAABO_DEBUG
        if(ctx_n>total_nodes(_tsinuu)){
            fprintf(stderr, "ERROR: idx_idx_sumupto_line exceeds maxima.");
            assert(0x00);
        }
    #endif
    return ctx_n;
}
unsigned int idx_idx_sumupto_line(tsinuu_t * _tsinuu, unsigned int from_l, unsigned int from_n, unsigned int to_l, unsigned int to_n){
    #ifndef SYMETRIC_TSINUU
    fprintf(stderr, "The used method for idx_idx_sumupto_line assumes SYMETRIC_TSINUU definition.");
    assert(0x00);
    #endif
    unsigned int ln_ctx = 0x00;
    for(unsigned int idx_l_to=0; idx_l_to<to_l; idx_l_to++){
        for(unsigned int idx_n_to=0;idx_n_to<layer_size(_tsinuu, idx_l_to);idx_n_to++){
            for(unsigned int idx_n_from=0;idx_n_from<layer_size(_tsinuu, idx_l_to-0x01);idx_n_from++){
                ln_ctx++;
            }
        }
    }
    #ifdef TSINUU_PIAABO_DEBUG
        if(ln_ctx>total_lines(_tsinuu)){
            fprintf(stderr, "ERROR: <idx_idx_sumupto_line> exceeds maxima.");
            assert(0x00);
        }
    #endif
    return ln_ctx;
}

node_tsinuu_t * node(tsinuu_t * _tsinuu, unsigned int idx_l, unsigned int idx_n){
    #ifdef TSINUU_PIAABO_DEBUG
        if(idx_l > total_layers(_tsinuu) || idx_n > layer_size(_tsinuu, idx_l)){
            fprintf(stderr, "WARNING: tsinuu <node> index exceeds limits.");
        }
    #endif
    return _tsinuu->__nodes[idx_sumupto_node(_tsinuu, idx_l, idx_n)];
}
kemu_tsinuu_t * node_kemu(tsinuu_t * _tsinuu, unsigned int idx_l, unsigned int idx_n){
    return node(_tsinuu, idx_l, idx_n)->__kemu;
}
line_tsinuu_t * line(tsinuu_t * _tsinuu, unsigned int from_l, unsigned int from_n, unsigned int to_l, unsigned int to_n){
    #ifdef TSINUU_PIAABO_DEBUG
        if(from_l > total_layers(_tsinuu) || from_n > layer_size(_tsinuu, from_n) || to_l > total_layers(_tsinuu) || to_n > layer_size(_tsinuu, to_n)){
            fprintf(stderr, "WARNING: tsinuu <line> index exceeds limits.");
        }
        #ifdef SYMETRIC_TSINUU
        if(from_l - to_l + 0.01 == 0x00){
            fprintf(stderr, "ERROR: tsinuu <line> unreachable, SYMETRIC_TSINUU requires (from_layer == to_layer - 0x01)");
            assert(0x00);
        }
        #endif
    #endif
    return _tsinuu->__lines[idx_idx_sumupto_line(_tsinuu, from_l, from_n, to_l, to_n)];
}
__cwcn_type line_weight(tsinuu_t * _tsinuu, unsigned int from_l, unsigned int from_n, unsigned int to_l, unsigned int to_n){
    return line(_tsinuu, from_l, from_n, to_l, to_n)->__weight;
}


void set_node(tsinuu_t * _tsinuu, node_tsinuu_t * _node, unsigned int idx_l, unsigned int idx_n){
    fprintf(stderr, "WARNING: <set_node> might be wrong");
    *node(_tsinuu, idx_l, idx_n) = *_node;
}
void set_node_kemu(tsinuu_t * _tsinuu, kemu_tsinuu_t * _kemu,  unsigned int idx_l, unsigned int idx_n){
    fprintf(stderr, "WARNING: <set_node_kemu> might be wrong");
    *node(_tsinuu, idx_l, idx_n)->__kemu = *_kemu;
}

void set_input(tsinuu_t * _tsinuu, __cwcn_type * _input_vector){
    for(unsigned int idx_n=0;idx_n<layer_size(_tsinuu, 0x00);idx_n++){
        node(_tsinuu, 0x00, idx_n)->__kemu->__value = _input_vector[idx_n]; // #FIXME no assert for input vector size.
    }
}
void set_output(tsinuu_t * _tsinuu, __cwcn_type * _input_vector){
    for(unsigned int idx_n=0;idx_n<layer_size(_tsinuu, total_layers(_tsinuu)-0x01);idx_n++){
        node(_tsinuu, total_layers(_tsinuu)-0x01, idx_n)->__kemu->__value = _input_vector[idx_n]; // #FIXME no assert for input vector size.
    }
}

void reset_set_node_kemu(tsinuu_t * _tsinuu, unsigned int idx_l, unsigned int idx_n, _Bool _pardon_bias, _Bool _pardon_grad, _Bool _pardon_maxmin, _Bool _pardon_dist){
    fprintf(stderr, "validate reset test with reset_set_node_kemu");
    kemu_tsinuu_t * c_kemu = node(_tsinuu, idx_l, idx_n)->__kemu;
    c_kemu->__value=0x00;
    c_kemu->__error=0x00;
    c_kemu->__entropy=0x00;
    if(!_pardon_bias){
        c_kemu->__bias=0x00;
    }
    if(!_pardon_grad){
        c_kemu->__grad=0x00;
    }
    if(!_pardon_maxmin){
        c_kemu->__max=0x00;
        c_kemu->__min=0x00;
    }
    if(!_pardon_dist){
        c_kemu->__std=0x00;
        c_kemu->__mean=0x00;
    }
}

void reset_all_nodes_kemu(tsinuu_t * _tsinuu, _Bool _pardon_bias, _Bool _pardon_grad, _Bool _pardon_maxmin, _Bool _pardon_dist){
    fprintf(stderr, "validate reset test with reset_all_nodes_kemu");
    for(unsigned int idx_n=0;idx_n<total_nodes(_tsinuu);idx_n++){
        kemu_tsinuu_t * c_kemu = _tsinuu->__nodes[idx_n]->__kemu;
        c_kemu->__value=0x00;
        c_kemu->__error=0x00;
        c_kemu->__entropy=0x00;
        if(!_pardon_bias){
            c_kemu->__bias=0x00;
        }
        if(!_pardon_grad){
            c_kemu->__grad=0x00;
        }
        if(!_pardon_maxmin){
            c_kemu->__max=0x00;
            c_kemu->__min=0x00;
        }
        if(!_pardon_dist){
            c_kemu->__std=0x00;
            c_kemu->__mean=0x00;
        }
    }
}

__cwcn_type * read_output_value(tsinuu_t * _tsinuu){
    __cwcn_type * _output_v = malloc((layer_size(_tsinuu, total_layers(_tsinuu)-0x01))*sizeof(__cwcn_type));
    for(unsigned int idx_n=0x00;idx_n<layer_size(_tsinuu, total_layers(_tsinuu)-0x01);idx_n++){
        _output_v[idx_n] = _tsinuu->__nodes[idx_n]->__kemu->__value;
    }
    return _output_v; 
}


/*
    ACTIVATIONS
*/
__cwcn_type nat_sigmoid_direct(__cwcn_type _input){return 1.0/(1.0+exp(-_input));}
__cwcn_type nat_sigmoid_direct_derivate(__cwcn_type _input){return nat_sigmoid_direct(_input)*(1-nat_sigmoid_direct(_input));} // #FIXME, better perfornce if direct value is saved.
__cwcn_type nat_sigmoid_inverse(__cwcn_type _input){return log(_input/(1-_input));}
__cwcn_type nat_sigmoid_inverse_derivate(__cwcn_type _input){return 1/(_input - _input*_input);}

__cwcn_type linear_direct(__cwcn_type _input){return _input;}
__cwcn_type linear_direct_derivate(__cwcn_type _input){return 1.0;}
__cwcn_type linear_inverse(__cwcn_type _input){return _input;}
__cwcn_type linear_inverse_derivate(__cwcn_type _input){return 1.0;}
// __cwcn_type bin_sigmoid_forward(__cwcn_type _input){return (__cwcn_type) 0x0F>>((__cwcn_type) 0x0F + (__cwcn_type) 0x0F<<(__cwcn_type) _input);} // #FIXME
void tsinuu_initialize_weights(tsinuu_t * _tsinuu){ // #FIXME, add other than random
    for(unsigned int l_ctx=0; l_ctx < total_lines(_tsinuu); l_ctx++){
        #ifdef NAT_TYPE
            _tsinuu->__lines[l_ctx]->__weight = (__cwcn_type) (rand() % 300 - 150)/(100.0);
        #else
            fprintf(stderr, "ERROR: only NAT_TYPE is defined");
            assert(0x00);
        #endif
    }
}
void tsinuu_propagate_forward(tsinuu_t * _tsinuu, __cwcn_type * _input){
    #ifndef SYMETRIC_TSINUU
    fprintf(stderr, "The used method for propagation assumes SYMETRIC_TSINUU definition");
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
    node_tsinuu_t * c_to_node = malloc(sizeof(node_tsinuu_t));
    kemu_tsinuu_t * c_to_node_kemu = malloc(sizeof(kemu_tsinuu_t));
    __cwcn_type c_val = 0x00;
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
}
/*
    PARAMETERS OPERATIONS
*/
// __cwcn_type symetric_tsinuu_get_weight(tsinuu_t * _tsinuu, idx_l, idx_h){
//     return _tsinuu->__weights[idx_h+idx_l*(_tsinuu->__SIZE_HIDDEN)];
// }
// void symetric_tsinuu_set_weight(tsinuu_t * _tsinuu, __cwcn_type _value, idx_l, idx_h){
//     return _tsinuu->__weights[idx_h+idx_l*(_tsinuu->__SIZE_HIDDEN)] = _value;
// }
// __cwcn_type symetric_tsinuu_get_bias(tsinuu_t * _tsinuu, idx_l, idx_h){
//     return _tsinuu->__bias[idx_h+idx_l*(_tsinuu->__SIZE_HIDDEN+1)];
// }
// void symetric_tsinuu_set_bias(tsinuu_t * _tsinuu, __cwcn_type _value, idx_l, idx_h){
//     return _tsinuu->__bias[idx_h+idx_l*(_tsinuu->__SIZE_HIDDEN+1)] = _value;
// }
/*
    FABRIC
*/
tsinuu_t * tsinuu_fabric(attribute_tsinuu_t * _attributes){
    tsinuu_t * new_tsinuu = malloc(sizeof(tsinuu_t)); // #FIXME, sure about the malloc?
    if (new_tsinuu == NULL) {
        fprintf(stderr, ">> ERROR: malloc failed allocating new tsinuu\n");
        assert(0x00);
    }
    printf(">> (START) size of new_tsinuu: %ld\n", sizeof(new_tsinuu));
    // attribute_tsinuu_t * new_tsinuu->__attributes = malloc(sizeof(attribute_tsinuu_t));
    new_tsinuu->__attributes->__NUM_TOTAL_LAYERS = _attributes->__NUM_TOTAL_LAYERS;
    // unsigned int * new_tsinuu->__attributes->__LAYERS_SIZES =  malloc(_attributes->__NUM_TOTAL_LAYERS * sizeof(unsigned int)); // #FIXME, sure about the malloc?
    for(unsigned int idx_ls=0x00;idx_ls<total_layers(new_tsinuu);idx_ls++){
        new_tsinuu->__attributes->__LAYERS_SIZES[idx_ls] = _attributes->__LAYERS_SIZES[idx_ls];
    }
    free(_attributes->__LAYERS_SIZES);
    unsigned int total_nodes_ctx = 0x00;
    unsigned int total_lines_ctx = 0x00;
    #ifdef SYMETRIC_TSINUU
        for(unsigned int idx_l=0x00;idx_l<total_layers(new_tsinuu);idx_l++){total_nodes_ctx += layer_size(new_tsinuu, idx_l);}
        for(unsigned int idx_l=0x00;idx_l<total_layers(new_tsinuu)-1;idx_l++){total_lines_ctx += layer_size(new_tsinuu, idx_l) * layer_size(new_tsinuu, idx_l+1);}
    #else
        fprintf(stderr, "ERROR: please define SYMETRIC_TSINUU to use tsinuu_fabric");
        assert(0x00);
    #endif
    new_tsinuu->__attributes->__NUM_TOTAL_NODES = total_nodes_ctx;
    new_tsinuu->__attributes->__NUM_TOTAL_LINES = total_lines_ctx;

    // list_activations_t * new_tsinuu->__attributes->__layers_activation = malloc(total_layers(new_tsinuu)*sizeof(list_activations_t));
    new_tsinuu->__attributes->__layers_activation = _attributes->__layers_activation;
    free(_attributes->__layers_activation);
    free(_attributes);
    // new_tsinuu->__nodes = malloc(total_nodes(new_tsinuu) * sizeof(node_tsinuu_t));
    unsigned int n_ctx=0x00;
    for(unsigned int idx_l=0x00; idx_l < total_layers(new_tsinuu); idx_l++){
        for(unsigned int idx_n=0x00;idx_n<layer_size(new_tsinuu, idx_l);idx_n++){
            node_tsinuu_t * new_node = malloc(sizeof(node_tsinuu_t));
            new_node->__type = new_tsinuu->__attributes->__layers_activation[idx_l];
            switch(new_tsinuu->__attributes->__layers_activation[idx_l]){
                case SIGMOID:
                    #ifdef NAT_TYPE
                        new_node->__direct = & nat_sigmoid_direct;
                        new_node->__inverse = & nat_sigmoid_inverse;
                        new_node->__direct_derivate = & nat_sigmoid_direct_derivate;
                        new_node->__inverse_derivate = & nat_sigmoid_inverse_derivate;
                    #endif
                    break;
                case LINEAR:
                    new_node->__direct = & linear_direct;
                    new_node->__inverse = & linear_inverse;
                    new_node->__direct_derivate = & linear_direct_derivate;
                    new_node->__inverse_derivate = & linear_inverse_derivate;
                    break;
                default:
                    fprintf(stderr, ">> ERROR, encounter unknown <tsinuu->__attributes->__layers_activation:[%d]> in <tsinuu_fabric>...\n",idx_l);
                    assert(0x00);
                    break;
            }
            kemu_tsinuu_t * new_kemu_tsinuu = malloc(sizeof(kemu_tsinuu_t));
            new_kemu_tsinuu->__cpte_bias_f = 0x01;
            new_kemu_tsinuu->__cpte_grad_f = 0x01;
            new_kemu_tsinuu->__cpte_error_f = 0x01;
            new_kemu_tsinuu->__cpte_maxmin_f = 0x01;
            new_kemu_tsinuu->__cpte_std_f = 0x01;
            new_kemu_tsinuu->__cpte_mean_f = 0x01;
            new_kemu_tsinuu->__cpte_entropy_f = 0x01;

            new_kemu_tsinuu->__value = 0x00;
            new_kemu_tsinuu->__bias = 0x00;
            new_kemu_tsinuu->__grad = 0x00;
            
            new_kemu_tsinuu->__error = 0x00;
            new_kemu_tsinuu->__max = 0x00;
            new_kemu_tsinuu->__min = 0x00;
            new_kemu_tsinuu->__std = 0x00;
            new_kemu_tsinuu->__mean = 0x00;
            new_kemu_tsinuu->__entropy = 0x00;


            new_node->__kemu = new_kemu_tsinuu;
            new_tsinuu->__nodes[n_ctx] = new_node;
            free(new_node);
            free(new_kemu_tsinuu);
            n_ctx++;
        }
    }
    #ifdef TSINUU_PIAABO_DEBUG
        printf(">> node count: %d must be eq to %d\n", total_nodes(new_tsinuu), n_ctx);
    #endif
    // new_tsinuu->__lines = malloc((new_tsinuu->__attributes->__NUM_TOTAL_LINES) * sizeof(line_tsinuu_t));
    unsigned int ln_ctx = 0;
    for(unsigned int idx_l_to=0; idx_l_to<total_layers(new_tsinuu); idx_l_to++){
        for(unsigned int idx_n_to=0;idx_n_to<layer_size(new_tsinuu, idx_l_to);idx_n_to++){
            for(unsigned int idx_n_from=0;idx_n_from<layer_size(new_tsinuu, idx_l_to-0x01);idx_n_from++){
                line_tsinuu_t * new_line = malloc(sizeof(line_tsinuu_t));
                new_line->__weight = 0.0;
                new_line->__from_layer = idx_l_to-0x01;
                new_line->__from_node = idx_n_from;
                new_line->__to_layer = idx_l_to;
                new_line->__to_node = idx_n_to;
                new_tsinuu->__lines[ln_ctx]=new_line;
                ln_ctx++;
                free(new_line);
            }
        }
    }
    #ifdef TSINUU_PIAABO_DEBUG
        printf(">> line count: %d must be eq to %d\n", new_tsinuu->__attributes->__NUM_TOTAL_LINES, ln_ctx);
    #endif
    return new_tsinuu;
}
void tsinuu_destroy(tsinuu_t * _tsinuu){
    fprintf(stderr, "<<_tsinuu_destry still in develpment, remmember malloc check utside function.>>");
    for(unsigned int idx_n=0; idx_n<_tsinuu->__attributes->__NUM_TOTAL_NODES;idx_n++){
        free(_tsinuu->__nodes[idx_n]->__kemu);
        free(_tsinuu->__nodes[idx_n]);
    }
    for(unsigned int idx_l=0; idx_l<_tsinuu->__attributes->__NUM_TOTAL_LINES;idx_l++){
        free(_tsinuu->__lines[idx_l]);
    }
    free(_tsinuu->__nodes);
    free(_tsinuu->__lines);
    free(_tsinuu->__attributes);
    free(_tsinuu);
}