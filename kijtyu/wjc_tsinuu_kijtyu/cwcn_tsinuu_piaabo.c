#include "cwcn_tsinuu_piaabo.h"
#include "cwcn_tsinuu_nebajke.h"
// stdout/stdin/stdout
// fprintf(stdout, "<<all malloc must be asserted not NULL.>> ");
// fprintf(stdout, "<<check for size zero allocation and turn them into size one allocation, for saefty>>");
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
unsigned int total_layers(__tsinuu_t * _tsinuu){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <total_layers> suspect element __NUM_TOTAL_LAYERS %d \n",_tsinuu->__attributes->__NUM_TOTAL_LAYERS);
    #endif
    return _tsinuu->__attributes->__NUM_TOTAL_LAYERS;
}
unsigned int total_nodes(__tsinuu_t * _tsinuu){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <total_nodes> suspect element __NUM_TOTAL_NODES %d \n",_tsinuu->__attributes->__NUM_TOTAL_NODES);
    #endif
    return _tsinuu->__attributes->__NUM_TOTAL_NODES;
}
unsigned int total_lines(__tsinuu_t * _tsinuu){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <total_lines> suspect element __NUM_TOTAL_LINES %d \n",_tsinuu->__attributes->__NUM_TOTAL_LINES);
    #endif
    return _tsinuu->__attributes->__NUM_TOTAL_LINES;
}
/*
    Direct access
*/
unsigned int l_coord_to_l_index(__layer_coords_t * _l_coord){
    return _l_coord->__l_s_coord->__layer_index;
}
unsigned int ln_coord_to_ln_index(__line_coords_t * _ln_coord){
    return _ln_coord->__ln_s_coord->__line_index;
}
unsigned int n_coord_to_n_index(__node_coords_t * _n_coord){
    return _n_coord->__n_s_coord->__node_index;
}
unsigned int n_coord_to_l_index(__node_coords_t * _n_coord){
    return _n_coord->__l_coord->__l_s_coord->__layer_index;
}
__layer_coords_t * n_coord_to_l_coord(__node_coords_t * _n_coord){
    return _n_coord->__l_coord;
}
/*
    Reverse access
*/
__layer_stack_coord_t * layer_index_to_layer_stack_coord(__tsinuu_t * _tsinuu, unsigned int _l_s_index){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <layer_index_to_layer_stack_coord>.\n");
    #endif
    return _tsinuu->__layers[_l_s_index]->__l_coord->__l_s_coord;
}
__layer_coords_t * layer_index_to_layer_coord(__tsinuu_t * _tsinuu, unsigned int _l_s_index){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <layer_index_to_layer_coord>.\n");
    #endif
    return _tsinuu->__layers[_l_s_index]->__l_coord;
}
__line_stack_coord_t * line_index_to_line_stack_coord(__tsinuu_t * _tsinuu, unsigned int _ln_s_index){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <line_index_to_line_stack_coord>.\n");
    #endif
    return _tsinuu->__lines[_ln_s_index]->__ln_coord->__ln_s_coord;
}
__line_coords_t * line_index_to_line_coord(__tsinuu_t * _tsinuu, unsigned int _ln_s_index){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request line_index_to_line_coord.\n");
    #endif
    return _tsinuu->__lines[_ln_s_index]->__ln_coord;
}
__node_stack_coord_t * index_to_node_stack_coord(__tsinuu_t * _tsinuu, unsigned int _l_s_index, unsigned int _n_s_index){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <index_to_node_stack_coord>.\n");
    #endif
    return _tsinuu->__layers[_l_s_index]->__nodes[_n_s_index]->__n_coord->__n_s_coord;
}
__node_coords_t * index_to_node_coord(__tsinuu_t * _tsinuu, unsigned int _l_s_index, unsigned int _n_s_index){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <index_to_node_coord>.\n");
    #endif
    return _tsinuu->__layers[_l_s_index]->__nodes[_n_s_index]->__n_coord;
}
/*

*/
___cwcn_bool_t is_layer_index_input(__tsinuu_t * _tsinuu, unsigned int __l_index){
    return _tsinuu->__layers[__l_index]->__lbp->__is_input;
}
___cwcn_bool_t is_layer_index_output(__tsinuu_t * _tsinuu, unsigned int __l_index){
    return _tsinuu->__layers[__l_index]->__lbp->__is_output;
}
/*

*/
unsigned int layer_size_from_layer_coord(__tsinuu_t * _tsinuu, __layer_coords_t * _l_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <layer_size_from_layer_coord> suspect element _layer_index: %d has __node_count: %d \n", l_coord_to_l_index(_l_coord), _tsinuu->__layers[l_coord_to_l_index(_l_coord)]->__node_count);
        if(l_coord_to_l_index(_l_coord)>=total_layers(_tsinuu)){
            fprintf(stderr, "ERROR: idx__line exceeds maxima, try NUM_LAYERS-0x01, for last layer.");
            assert(0x00);
        }
    #endif
    return _tsinuu->__layers[l_coord_to_l_index(_l_coord)]->__node_count;
}
unsigned int layer_size_from_layer_stack_index(__tsinuu_t * _tsinuu, unsigned int _l_s_index){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <layer_size_from_layer_stack_index>\n");
        fprintf(stdout, ">>>> request <layer_size_from_layer_stack_index> suspect element _layer_index: %d has __node_count: %d \n", _l_s_index, _tsinuu->__layers[_l_s_index]->__node_count);
        if(_l_s_index>=total_layers(_tsinuu)){
            fprintf(stderr, "ERROR: idx__line exceeds maxima, try NUM_LAYERS-0x01, for last layer.");
            assert(0x00);
        }
    #endif
    return _tsinuu->__layers[_l_s_index]->__node_count;
}
unsigned int input_size(__tsinuu_t * _tsinuu){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <input_size> suspect element layer_id: %d\n",0x00);
        if(!is_layer_index_input(_tsinuu, 0x00)){
            fprintf(stdout, ">>>> ERROR layer_index %d expected to be class input.\n",0x00);
        }
    #endif
    return _tsinuu->__layers[0x00]->__node_count;
}
unsigned int output_size(__tsinuu_t * _tsinuu){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <output_size> suspect element layer_id: %d \n", total_layers(_tsinuu)-0x01);
        if(!is_layer_index_output(_tsinuu, total_layers(_tsinuu)-0x01)){
            fprintf(stdout, ">>>> ERROR layer_index %d expected to be class output.\n", total_layers(_tsinuu)-0x01);
        }
    #endif
    return _tsinuu->__layers[total_layers(_tsinuu)-0x01]->__node_count;
}
/*

*/
unsigned int count_total_nodes(__tsinuu_t * _tsinuu){
    unsigned int total_nodes_ctx = 0x00;
    for(unsigned int idx_l=0x00;idx_l<total_layers(_tsinuu);idx_l++){
        fprintf(stdout, "suspect element: %d\n",total_nodes_ctx);
        total_nodes_ctx += _tsinuu->__attributes->__layers_sizes[idx_l];
    }
    #ifdef TSINUU_DEBUG
        fprintf(stdout, "request <count_total_nodes> suspect element: %d\n",total_nodes_ctx);
    #endif
    return total_nodes_ctx;
}
unsigned int count_total_lines(__tsinuu_t * _tsinuu){
    unsigned int total_lines_ctx = 0x00;
    for(unsigned int idx_l=0x00;idx_l<total_layers(_tsinuu)-0x01;idx_l++){
        total_lines_ctx += _tsinuu->__attributes->__layers_sizes[idx_l] * _tsinuu->__attributes->__layers_sizes[idx_l+0x01];
    }
    #ifdef TSINUU_DEBUG
        fprintf(stdout, "request <count_total_lines> suspect element: %d\n",total_lines_ctx);
    #endif
    return total_lines_ctx;
}

/*

*/
__cartecian_tensor_t * get_node_xyz(__tsinuu_t * _tsinuu, __node_coords_t * _n_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <get_node_xyz>\n");
    #endif
    return _tsinuu->__layers[n_coord_to_l_index(_n_coord)]->__nodes[n_coord_to_n_index(_n_coord)]->__n_coord->__xyz_coord;
}
__cwcn_type_t get_node_x(__tsinuu_t * _tsinuu, __node_coords_t * _n_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <get_node_x>\n");
    #endif
    return _tsinuu->__layers[n_coord_to_l_index(_n_coord)]->__nodes[n_coord_to_n_index(_n_coord)]->__n_coord->__xyz_coord->__coord_x;
}
__cwcn_type_t get_node_y(__tsinuu_t * _tsinuu, __node_coords_t * _n_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <get_node_y>\n");
    #endif
    return _tsinuu->__layers[n_coord_to_l_index(_n_coord)]->__nodes[n_coord_to_n_index(_n_coord)]->__n_coord->__xyz_coord->__coord_y;
}
__cwcn_type_t get_node_z(__tsinuu_t * _tsinuu, __node_coords_t * _n_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <get_node_z>\n");
    #endif
    return _tsinuu->__layers[n_coord_to_l_index(_n_coord)]->__nodes[n_coord_to_n_index(_n_coord)]->__n_coord->__xyz_coord->__coord_z;
}




__cartecian_tensor_t * get_line_xyz(__tsinuu_t * _tsinuu, __line_coords_t * _ln_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <get_line_xyz>\n");
    #endif
    return _tsinuu->__lines[ln_coord_to_ln_index(_ln_coord)]->__ln_coord->__xyz_coord;
}
__cwcn_type_t get_line_x(__tsinuu_t * _tsinuu, __line_coords_t * _ln_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <get_line_x>\n");
    #endif
    return _tsinuu->__lines[ln_coord_to_ln_index(_ln_coord)]->__ln_coord->__xyz_coord->__coord_x;
}
__cwcn_type_t get_line_y(__tsinuu_t * _tsinuu, __line_coords_t * _ln_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <get_line_y>\n");
    #endif
    return _tsinuu->__lines[ln_coord_to_ln_index(_ln_coord)]->__ln_coord->__xyz_coord->__coord_y;
}
__cwcn_type_t get_line_z(__tsinuu_t * _tsinuu, __line_coords_t * _ln_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <get_line_z>\n");
    #endif
    return _tsinuu->__lines[ln_coord_to_ln_index(_ln_coord)]->__ln_coord->__xyz_coord->__coord_z;
}
/*

*/
__node_tsinuu_t * node(__tsinuu_t * _tsinuu, __node_coords_t * _n_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <node> \n");
        if(n_coord_to_l_index(_n_coord) >= total_layers(_tsinuu)){
            fprintf(stderr, ">>>> ERROR: tsinuu <node> request layer index exceeds tsinuu limits.");
            assert(0x00);
        }
        if(n_coord_to_n_index(_n_coord) >= layer_size_from_layer_coord(_tsinuu, n_coord_to_l_coord(_n_coord))){
            fprintf(stderr, ">>>> ERROR: tsinuu <node> request node index exceeds layer limits.");
            assert(0x00);
        }
    #endif
    return _tsinuu->__layers[n_coord_to_l_index(_n_coord)]->__nodes[n_coord_to_n_index(_n_coord)];
}
__node_kemu_t * node_kemu(__tsinuu_t * _tsinuu, __node_coords_t * _n_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <node_kemu>\n");
    #endif
    return node(_tsinuu, _n_coord)->__n_kemu;
}
__cwcn_type_t node_bias(__tsinuu_t * _tsinuu, __node_coords_t * _n_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <node bias>\n");
    #endif
    return node_kemu(_tsinuu, _n_coord)->__bias;
}
__node_coords_t * node_coords_from_xyz(__tsinuu_t * _tsinuu, __cartecian_tensor_t * _xyz){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <node_coords_from_xyz>, x:%f, y:%f, z:%f\n", _xyz->__coord_x, _xyz->__coord_y, _xyz->__coord_z);
        fprintf(stdout, ">>>> WARNING <node_coords_from_xyz> is slow\n");
        fprintf(stdout, ">>>> WARNING <node_coords_from_xyz> might be wrong\n");
    #endif
    ___cwcn_bool_t find_f = ___CWCN_FALSE;
    for(unsigned int idx_l=0x00; idx_l<total_layers(_tsinuu); idx_l++){
        for(unsigned int idx_n=0x00; idx_n<layer_size_from_layer_stack_index(_tsinuu, idx_l); idx_n++){
            __node_coords_t * c_node_coord = index_to_node_coord(_tsinuu, idx_l, idx_n);
            if(get_node_x(_tsinuu, c_node_coord)==_xyz->__coord_x){
                if(get_node_y(_tsinuu, c_node_coord)==_xyz->__coord_y){
                    if(get_node_z(_tsinuu, c_node_coord)==_xyz->__coord_z){
                        return node(_tsinuu, c_node_coord)->__n_coord;
                    }
                }
            }
        }
    }
    return ((void *)0x00);
}
__line_tsinuu_t * line(__tsinuu_t * _tsinuu, __line_coords_t * _ln_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <line> \n");
        #ifdef SYMETRIC_TSINUU
            if(n_coord_to_l_index(_ln_coord->__from_node) - n_coord_to_l_index(_ln_coord->__to_node) + 0.01 == 0x00){
                fprintf(stderr, "ERROR: tsinuu <line> unreachable, SYMETRIC_TSINUU requires (from_layer == to_layer - 0x01)");
                assert(0x00);
            } else if(n_coord_to_l_index(_ln_coord->__from_node) >= total_layers(_tsinuu)-0x01){
                fprintf(stdout, "WARNING: tsinuu <line> from_node line index exceeds layer maxima.");
            } else if(n_coord_to_n_index(_ln_coord->__from_node) > layer_size_from_layer_coord(_tsinuu, _ln_coord->__from_node->__l_coord)){
                fprintf(stdout, "WARNING: tsinuu <line> from_node node index exceeds layer node maxima.");
            } else if(n_coord_to_l_index(_ln_coord->__to_node) >= total_layers(_tsinuu)){
                fprintf(stdout, "WARNING: tsinuu <line> to_node line index exceeds layer maxima.");
            } else if(n_coord_to_n_index(_ln_coord->__to_node) >= layer_size_from_layer_coord(_tsinuu, _ln_coord->__to_node->__l_coord)){
                fprintf(stdout, "WARNING: tsinuu <line> to_node node index exceeds layer node maxima.");
            }
        #endif
    #endif
    return _tsinuu->__lines[ln_coord_to_ln_index(_ln_coord)];
}
__line_kemu_t * line_kemu(__tsinuu_t * _tsinuu, __line_coords_t * _ln_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <line_kemu>\n");
    #endif
    return line(_tsinuu, _ln_coord)->__ln_kemu;
}
__cwcn_type_t line_weight(__tsinuu_t * _tsinuu, __line_coords_t * _ln_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <line_weight>\n");
    #endif
    return line_kemu(_tsinuu, _ln_coord)->__weight;
}
/*

*/
void set_node(__tsinuu_t * _tsinuu, __node_tsinuu_t * _node, __node_coords_t * _n_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <set_node> 4 suspects, 1 warning\n");
        fprintf(stdout, ">>>> WARNING: <set_node> might be wrong\n");
        fprintf(stdout, ">>>> suspect element value _ %f  (may) not be equal to _ %f\n", get_node_x(_tsinuu, _n_coord), _node->__n_coord->__xyz_coord->__coord_x);
    #endif
    *node(_tsinuu, _n_coord) = *_node;
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> suspect element value _ %f  (must) be equal to _ %f\n", get_node_x(_tsinuu, _n_coord), _node->__n_coord->__xyz_coord->__coord_x);
    #endif
}
void set_node_kemu(__tsinuu_t * _tsinuu, __node_kemu_t * _n_kemu,  __node_coords_t * _n_coord){
    fprintf(stdout, "WARNING: <set_node_kemu> might be wrong");
    *node_kemu(_tsinuu, _n_coord) = *_n_kemu;
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <set_node_kemu>\n");
        fprintf(stdout, ">>>> WARNING: <set_node_kemu> might be wrong\n");
        fprintf(stdout, ">>>> suspect element value _ %f  must be equal to _ %f\n", node_kemu(_tsinuu, _n_coord)->__value, _n_kemu->__value);
    #endif
}

void reset_node_kemu(__node_tsinuu_t * _node){
    if(!_node->__nbp->__pardon_value){
        _node->__n_kemu->__value=0x00;
    }
    if(!_node->__nbp->__pardon_grad){
        _node->__n_kemu->__grad=0x00;
    }
    if(!_node->__nbp->__pardon_bias){
        _node->__n_kemu->__bias=0x00;
    }
    if(!_node->__nbp->__pardon_maxmin){
        _node->__n_kemu->__dist->__min=-0x01 * __cwcn_infinite;
        _node->__n_kemu->__dist->__max=__cwcn_infinite;
    }
    if(!_node->__nbp->__pardon_entropy){
        _node->__n_kemu->__dist->__entropy=0x00;
    }
    if(!_node->__nbp->__pardon_mean){
        _node->__n_kemu->__dist->__mean=0x00;
    }
    if(!_node->__nbp->__pardon_std){
        _node->__n_kemu->__dist->__std=0x00;
    }
    if(!_node->__nbp->__pardon_error){
        _node->__n_kemu->__error=0x00;
    }
    _node->__nbp->__is_reset = ___CWCN_TRUE;
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <reset_node_kemu>\n");
        fprintf(stdout, ">>>> suspect element value %f  must be zero\n",_node->__n_kemu->__value);
        fprintf(stdout, ">>>> suspect element value %f  must be zero\n",_node->__n_kemu->__value);
    #endif
}

void reset_kemu_forall_nodes(__tsinuu_t * _tsinuu){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <reset_kemu_forall_nodes>\n");
    #endif
    for(unsigned int idx_l=0;idx_l<total_layers(_tsinuu);idx_l++){
        for(unsigned int idx_n=0;idx_n<layer_size_from_layer_stack_index(_tsinuu, idx_l);idx_n++){
            reset_node_kemu(node(_tsinuu, index_to_node_coord(_tsinuu, idx_l, idx_n)));
        }
    }
}

void reset_line_kemu(__line_tsinuu_t * _line){
    if(!_line->__lnbp->__pardon_grad){
        _line->__ln_kemu->__grad=0x00;
    }
    if(!_line->__lnbp->__pardon_weight){
        _line->__ln_kemu->__weight=0x00;
    }
    _line->__lnbp->__is_reset = ___CWCN_TRUE;
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <reset_line_kemu>\n");
        fprintf(stdout, ">>>> suspect element __grad %f  must be zero\n",_line->__ln_kemu->__grad);
        fprintf(stdout, ">>>> suspect element __weight %f  must be zero\n",_line->__ln_kemu->__weight);
    #endif
}

void reset_kemu_forall_lines(__tsinuu_t * _tsinuu){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <reset_kemu_forall_lines>\n");
    #endif
    for(unsigned int idx_ln=0;idx_ln<total_lines(_tsinuu);idx_ln++){
        reset_line_kemu(_tsinuu->__lines[idx_ln]);
    }
}
/*

*/
void read_layer_value_as_vector_from_coord(__tsinuu_t * _tsinuu, __layer_coords_t * _l_coord, __cwcn_type_t * _result_vector){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <read_layer_value_as_vector_from_coord>\n");
    #endif
    const unsigned int n_l = layer_size_from_layer_coord(_tsinuu, _l_coord);
    for(unsigned int idx_n=0x00;idx_n<n_l;idx_n++){
        _result_vector[idx_n]=node_kemu(_tsinuu, index_to_node_coord(_tsinuu, l_coord_to_l_index(_l_coord), idx_n))->__value;
    }
}
void read_layer_value_as_vector_from_stack_coord(__tsinuu_t * _tsinuu, __layer_stack_coord_t * _l_s_coord, __cwcn_type_t * _result_vector){
    const unsigned int n_l = layer_size_from_layer_stack_index(_tsinuu, _l_s_coord->__layer_index);
    for(unsigned int idx_n=0x00;idx_n<n_l;idx_n++){
        _result_vector[idx_n]=node_kemu(_tsinuu, index_to_node_coord(_tsinuu, _l_s_coord->__layer_index, idx_n))->__value;
    }
}
/*

*/

void read_output(__tsinuu_t * _tsinuu, __cwcn_type_t * _result_vector){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <read_ouput_value>\n");
    #endif
    read_layer_value_as_vector_from_stack_coord(_tsinuu, layer_index_to_layer_stack_coord(_tsinuu, total_layers(_tsinuu)-0x01), _result_vector); 
}
void read_input(__tsinuu_t * _tsinuu, __cwcn_type_t * _result_vector){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <read_input_value>\n");
    #endif
    read_layer_value_as_vector_from_stack_coord(_tsinuu, layer_index_to_layer_stack_coord(_tsinuu, 0x00), _result_vector); 
}

void set_input(__tsinuu_t * _tsinuu, __cwcn_type_t * _input_vector){
    for(unsigned int idx_n=0;idx_n<layer_size_from_layer_stack_index(_tsinuu, 0x00);idx_n++){
        node_kemu(_tsinuu, index_to_node_coord(_tsinuu, 0x00, idx_n))->__value = _input_vector[idx_n]; // #FIXME no assert for input vector size.
    }
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <set_input> suspect element layer_id: %d\n",0x00);
        if(!is_layer_index_input(_tsinuu, 0x00)){
            fprintf(stdout, ">>>> ERROR set_input %d expected to be class input.\n",0x00);
        }
        fprintf(stdout, ">>>> suspect element value _ %f  must be equal to _ %f\n",node_kemu(_tsinuu, index_to_node_coord(_tsinuu, 0x00, 0x00))->__value, _input_vector[0x00]);
    #endif
}
void set_output(__tsinuu_t * _tsinuu, __cwcn_type_t * _output_vector){
    for(unsigned int idx_n=0;idx_n<layer_size_from_layer_stack_index(_tsinuu, total_layers(_tsinuu)-0x01);idx_n++){
        node_kemu(_tsinuu, index_to_node_coord(_tsinuu, total_layers(_tsinuu)-0x01, idx_n))->__value = _output_vector[idx_n]; // #FIXME no assert for output vector size.
    }
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <set_output> suspect element layer_id: %d\n",0x00);
        if(!is_layer_index_output(_tsinuu, 0x00)){
            fprintf(stdout, ">>>> ERROR set_output %d expected to be class output.\n",0x00);
        }
        fprintf(stdout, ">>>> suspect element value _ %f  must be equal to _ %f\n",node_kemu(_tsinuu, index_to_node_coord(_tsinuu, total_layers(_tsinuu)-0x01, 0x00))->__value, _output_vector[0x00]);
    #endif
}
/*

*/
void tsinuu_initialize_weights_random(__tsinuu_t * _tsinuu, __cwcn_type_t _v_max, __cwcn_type_t _v_min){
    for(unsigned int l_ctx=0; l_ctx < total_lines(_tsinuu); l_ctx++){
        _tsinuu->__lines[l_ctx]->__ln_kemu->__weight = (__cwcn_type_t) (rand() % ((int)((_v_max-_v_min)*100.0)) + ((int)(_v_min*100.0)))/(100.0);
    }
    #ifdef TSINUU_DEBUG
        fprintf(stderr, ">>>> request <tsinuu_initialize_weights_random>\n");
        fprintf(stderr, ">>>> suspect element values [%f, %f... %f] must be random\n",_tsinuu->__lines[0x00]->__ln_kemu->__weight, _tsinuu->__lines[0x01]->__ln_kemu->__weight, _tsinuu->__lines[total_lines(_tsinuu)-0x01]->__ln_kemu->__weight);
    #endif
}

void tsinuu_initialize_weights_zero(__tsinuu_t * _tsinuu){
    for(unsigned int l_ctx=0; l_ctx < total_lines(_tsinuu); l_ctx++){
        _tsinuu->__lines[l_ctx]->__ln_kemu->__weight = 0x00;
    }
    #ifdef TSINUU_DEBUG
        fprintf(stderr, ">>>> request <tsinuu_initialize_weights_zero>\n");
        fprintf(stderr, ">>>> suspect element values [%f, %f... %f] must be zero\n",_tsinuu->__lines[0x00]->__ln_kemu->__weight, _tsinuu->__lines[0x01]->__ln_kemu->__weight, _tsinuu->__lines[total_lines(_tsinuu)-0x01]->__ln_kemu->__weight);
    #endif
}
/*
    FABRIC
*/
__tsinuu_t * tsinuu_fabric(__attribute_tsinuu_t * _attributes){
    #ifdef TSINUU_DEBUG
        fprintf(stdout,">> request <tsinuu_fabric> for a new_tsinuu\n");
    #endif
    #ifndef NAT_TYPE
        fprintf(stderr, "ERROR: tsinuu_fabric requirest NAT_TYPE definition");
        assert(0x00);
    #endif
    #ifndef SYMETRIC_TSINUU
        fprintf(stderr, "The method used b for tsinuu_fabric assumes SYMETRIC_TSINUU definition.");
        assert(0x00);
    #endif
    if(!_attributes->__is_symetric){
        fprintf(stderr, "The method used d for tsinuu_fabric requires _atributes->__is_symetric definition.");
        assert(0x00);
    }
    __tsinuu_t * new_tsinuu = malloc(sizeof(__tsinuu_t));
    if (new_tsinuu == NULL) {
        fprintf(stderr, ">> ERROR: malloc failed allocating new tsinuu\n");
        assert(0x00);
    }
    new_tsinuu->__attributes = malloc(sizeof(__attribute_tsinuu_t));
    new_tsinuu->__attributes->__is_symetric=_attributes->__is_symetric;
    new_tsinuu->__attributes->__NUM_TOTAL_LAYERS = _attributes->__NUM_TOTAL_LAYERS;
    new_tsinuu->__attributes->__layers_sizes = malloc(total_layers(new_tsinuu)*sizeof(unsigned int));
    new_tsinuu->__attributes->__layers_activation = malloc(total_layers(new_tsinuu)*sizeof(__list_activations_t));
    new_tsinuu->__layers = malloc(total_layers(new_tsinuu)*sizeof(__layer_tsinuu_t));
    if(!new_tsinuu->__layers){
        fprintf(stderr, ">>>> ERROR: malloc falied allocating __layers");
        assert(0x00);
    }
    for(unsigned int idx_l=0x00;idx_l<total_layers(new_tsinuu);idx_l++){
        new_tsinuu->__attributes->__layers_sizes[idx_l] = _attributes->__layers_sizes[idx_l];
        new_tsinuu->__attributes->__layers_activation[idx_l] = _attributes->__layers_activation[idx_l];
        
        new_tsinuu->__layers[idx_l] = malloc(sizeof(__layer_tsinuu_t));
        new_tsinuu->__layers[idx_l]->__nodes = malloc(new_tsinuu->__attributes->__layers_sizes[idx_l]*sizeof(__node_tsinuu_t));
        new_tsinuu->__layers[idx_l]->__l_coord = malloc(sizeof(__layer_coords_t));
        new_tsinuu->__layers[idx_l]->__l_coord->__l_s_coord = malloc(sizeof(__layer_stack_coord_t));
        new_tsinuu->__layers[idx_l]->__l_coord->__l_s_coord->__layer_index=idx_l;
        new_tsinuu->__layers[idx_l]->__node_count = new_tsinuu->__attributes->__layers_sizes[idx_l];
        new_tsinuu->__layers[idx_l]->__layer_activation = new_tsinuu->__attributes->__layers_activation[idx_l];
        new_tsinuu->__layers[idx_l]->__lbp = malloc(sizeof(__layerboolean_parametric_t));
        new_tsinuu->__layers[idx_l]->__lbp->__is_output=(idx_l==total_layers(new_tsinuu)-0x01);
        new_tsinuu->__layers[idx_l]->__lbp->__is_input=(idx_l==0x00);
        // free(new_layer);
    }
    new_tsinuu->__attributes->__NUM_TOTAL_NODES = count_total_nodes(new_tsinuu);
    new_tsinuu->__attributes->__NUM_TOTAL_LINES = count_total_lines(new_tsinuu);
    free(_attributes); // here config stops, and fabric takes automatically
    /*
        LOOP OVER LAYERS
    */
    unsigned int ctx_n=0x00;
    for(unsigned int idx_l=0x00; idx_l < total_layers(new_tsinuu); idx_l++){
        ctx_n = layer_size_from_layer_stack_index(new_tsinuu, idx_l);
        for(unsigned int idx_n=0x00;idx_n<ctx_n;idx_n++){
            new_tsinuu->__layers[idx_l]->__nodes[idx_n] = malloc(sizeof(__node_tsinuu_t));
            if(idx_l==0x00 && new_tsinuu->__attributes->__layers_activation[idx_l] != LINEAR){
                fprintf(stderr, "Input layer must be LINEAR activation\n");
                assert(new_tsinuu->__attributes->__layers_activation[idx_l] == LINEAR);
            }
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__type = new_tsinuu->__attributes->__layers_activation[idx_l];
            switch(new_tsinuu->__attributes->__layers_activation[idx_l]){
                case SIGMOID:
                    new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__direct = & nat_sigmoid_direct;
                    new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__inverse = & nat_sigmoid_inverse;
                    new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__direct_derivate = & nat_sigmoid_direct_derivate;
                    new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__inverse_derivate = & nat_sigmoid_inverse_derivate;
                    break;
                case LINEAR:
                    new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__direct = & linear_direct;
                    new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__inverse = & linear_inverse;
                    new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__direct_derivate = & linear_direct_derivate;
                    new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__inverse_derivate = & linear_inverse_derivate;
                    break;
                default:
                    fprintf(stderr, ">> ERROR, encounter unknown <tsinuu->__attributes->__layers_activation:[%d]> in <tsinuu_fabric>...\n",idx_l);
                    assert(0x00);
                    break;
            }
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__n_coord=malloc(sizeof(__node_coords_t));
            #ifdef TSINUU_DEBUG
                fprintf(stdout, ">>>> WARNING: (relax) must check changes to expression new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__n_coord->__l_coord=new_tsinuu->__layers[idx_l]->__l_coord");
            #endif
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__n_coord->__l_coord=new_tsinuu->__layers[idx_l]->__l_coord;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__n_coord->__n_s_coord = malloc(sizeof(__node_stack_coord_t));
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__n_coord->__n_s_coord->__node_index=idx_n;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__n_coord->__xyz_coord = malloc(sizeof(__cartecian_tensor_t));
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__n_coord->__xyz_coord->__coord_x=idx_l;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__n_coord->__xyz_coord->__coord_y=idx_n;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__n_coord->__xyz_coord->__coord_z=0x00;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__nbp = malloc(sizeof(__nodeboolean_parametric_t));
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__nbp->__pardon_value=___CWCN_FALSE;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__nbp->__pardon_grad=___CWCN_FALSE;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__nbp->__pardon_bias=___CWCN_FALSE;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__nbp->__pardon_maxmin=___CWCN_FALSE;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__nbp->__pardon_entropy=___CWCN_FALSE;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__nbp->__pardon_mean=___CWCN_FALSE;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__nbp->__pardon_std=___CWCN_FALSE;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__nbp->__pardon_error=___CWCN_FALSE;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__nbp->__has_value=___CWCN_FALSE;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__nbp->__has_grad=___CWCN_FALSE;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__nbp->__is_input=new_tsinuu->__layers[idx_l]->__lbp->__is_input;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__nbp->__is_output=new_tsinuu->__layers[idx_l]->__lbp->__is_output;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__nbp->__is_reset=___CWCN_FALSE;
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__n_kemu = malloc(sizeof(__layer_kemu_t));
            new_tsinuu->__layers[idx_l]->__nodes[idx_n]->__n_kemu->__dist = malloc(sizeof(__dist_tensor_t));
            reset_node_kemu(new_tsinuu->__layers[idx_l]->__nodes[idx_n]);
            #ifdef TSINUU_DEBUG
                fprintf(stdout, "WARNING: tsinuu new_tsinuu->__layers[idx_l]->__nodes[idx_n] asigment might be incorrect after free");
            #endif
        }
    }
    #ifdef TSINUU_DEBUG
        fprintf(stdout,">> node count: %d\n", total_nodes(new_tsinuu));
    #endif
    /*
        LOOP OVER LINES
    */
    new_tsinuu->__lines = malloc((new_tsinuu->__attributes->__NUM_TOTAL_LINES) * sizeof(__line_tsinuu_t));
    unsigned int ln_ctx = 0x00;
    for(unsigned int idx_l_to=0x01; idx_l_to<total_layers(new_tsinuu); idx_l_to++){
        for(unsigned int idx_n_to=0x00;idx_n_to<layer_size_from_layer_stack_index(new_tsinuu, idx_l_to);idx_n_to++){
            for(unsigned int idx_n_from=0x00;idx_n_from<layer_size_from_layer_stack_index(new_tsinuu, idx_l_to-0x01);idx_n_from++){
                new_tsinuu->__lines[ln_ctx] = malloc(sizeof(__line_tsinuu_t));
                new_tsinuu->__lines[ln_ctx]->__lnbp = malloc(sizeof(__lineboolean_parametric_t));
                new_tsinuu->__lines[ln_ctx]->__lnbp->__pardon_grad=___CWCN_FALSE;
                new_tsinuu->__lines[ln_ctx]->__lnbp->__pardon_weight=___CWCN_FALSE;
                new_tsinuu->__lines[ln_ctx]->__lnbp->__has_value=___CWCN_FALSE;
                new_tsinuu->__lines[ln_ctx]->__lnbp->__has_grad=___CWCN_FALSE;
                new_tsinuu->__lines[ln_ctx]->__lnbp->__is_reset=___CWCN_FALSE;
                __node_coords_t * to_node_coord = index_to_node_coord(new_tsinuu, idx_l_to, idx_n_to);
                __node_coords_t * from_node_coord = index_to_node_coord(new_tsinuu, idx_l_to-0x01, idx_n_from);
                new_tsinuu->__lines[ln_ctx]->__ln_coord = malloc(sizeof(__line_coords_t));
                new_tsinuu->__lines[ln_ctx]->__ln_coord->__ln_s_coord = malloc(sizeof(__line_stack_coord_t));
                new_tsinuu->__lines[ln_ctx]->__ln_coord->__xyz_coord = malloc(sizeof(__cartecian_tensor_t));
                new_tsinuu->__lines[ln_ctx]->__ln_coord->__ln_s_coord->__line_index=ln_ctx;
                new_tsinuu->__lines[ln_ctx]->__ln_coord->__xyz_coord->__coord_x=(get_node_x(new_tsinuu, from_node_coord)+get_node_x(new_tsinuu, to_node_coord))/2.0;
                new_tsinuu->__lines[ln_ctx]->__ln_coord->__xyz_coord->__coord_y=(get_node_y(new_tsinuu, from_node_coord)+get_node_y(new_tsinuu, to_node_coord))/2.0;
                new_tsinuu->__lines[ln_ctx]->__ln_coord->__xyz_coord->__coord_z=(get_node_z(new_tsinuu, from_node_coord)+get_node_z(new_tsinuu, to_node_coord))/2.0;
                new_tsinuu->__lines[ln_ctx]->__ln_coord->__from_node=from_node_coord;
                new_tsinuu->__lines[ln_ctx]->__ln_coord->__to_node=to_node_coord;
                new_tsinuu->__lines[ln_ctx]->__type = SCALAR; // #FIXME allow for other types
                new_tsinuu->__lines[ln_ctx]->__ln_kemu = malloc(sizeof(__line_kemu_t));
                reset_line_kemu(new_tsinuu->__lines[ln_ctx]);
                ln_ctx++;
            }
        }
    }
    // 
    tsinuu_initialize_weights_zero(new_tsinuu);
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> line count: %d must be eq to %d\n", new_tsinuu->__attributes->__NUM_TOTAL_LINES, ln_ctx);
    #endif
    return new_tsinuu;
}
/*

*/
void tsinuu_destroy(__tsinuu_t * _tsinuu){
    for(unsigned int idx_l=0x00; idx_l<total_layers(_tsinuu);idx_l++){
        for(unsigned int idx_n=0x00;idx_n<layer_size_from_layer_stack_index(_tsinuu, idx_l);idx_n++){
            free(_tsinuu->__layers[idx_l]->__nodes[idx_n]->__n_kemu->__dist); //
            free(_tsinuu->__layers[idx_l]->__nodes[idx_n]->__n_kemu); //
            free(_tsinuu->__layers[idx_l]->__nodes[idx_n]->__n_coord->__n_s_coord); //
            free(_tsinuu->__layers[idx_l]->__nodes[idx_n]->__n_coord->__xyz_coord); //
            free(_tsinuu->__layers[idx_l]->__nodes[idx_n]->__n_coord); //
            free(_tsinuu->__layers[idx_l]->__nodes[idx_n]->__nbp); //
            free(_tsinuu->__layers[idx_l]->__nodes[idx_n]); //
        }
        free(_tsinuu->__layers[idx_l]->__nodes); //
        free(_tsinuu->__layers[idx_l]->__l_coord->__l_s_coord); //
        free(_tsinuu->__layers[idx_l]->__l_coord); //
        free(_tsinuu->__layers[idx_l]->__lbp); //
        free(_tsinuu->__layers[idx_l]); //
    }
    free(_tsinuu->__layers); //
    for(unsigned int idx_ln=0; idx_ln<total_lines(_tsinuu);idx_ln++){
        free(_tsinuu->__lines[idx_ln]->__ln_kemu); //
        free(_tsinuu->__lines[idx_ln]->__ln_coord->__ln_s_coord); //
        free(_tsinuu->__lines[idx_ln]->__ln_coord->__xyz_coord); //
        free(_tsinuu->__lines[idx_ln]->__ln_coord); //
        free(_tsinuu->__lines[idx_ln]->__lnbp); //
        free(_tsinuu->__lines[idx_ln]); //
    }
    free(_tsinuu->__lines); //
    free(_tsinuu->__attributes->__layers_sizes); //
    free(_tsinuu->__attributes->__layers_activation); //
    free(_tsinuu->__attributes); //
    free(_tsinuu); //
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <tsinuu_destroy>\n");
    #endif
}
