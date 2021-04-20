#include "cwcn_tsinuu_piaabo.h"
#include "cwcn_tsinuu_nebajke.h"
// stdout/stdin/stdout
// fprintf(stdout, "<<all mallocs must be asserted not NULL.>> ");
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
    return _n_coord_->__l_coord->__l_s_coord->__layer_index;
}
/*

*/
__layer_coords_t * n_coord_to_l_coord(__node_coords_t * _n_coord){
    return _n_coord->__l_coord;
}
__layer_coords_t * index_to_layer_coord(unsigned int _l_s_index){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request index_to_layer_coord.\n");
        fprintf(stdout, ">>>> WARNING: index_to_layer_coord might be wrong.\n");
    #endif
    return (__layer_coords_t) * {.__ln_s_coord={.__layer_index=_l_s_index}};
}
__node_coords_t * index_to_node_coord(unsigned int _l_s_index, unsigned int _n_s_index){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request index_to_node_coord.\n");
        fprintf(stdout, ">>>> WARNING: index_to_node_coord might be wrong.\n");
    #endif
    return (__node_coords_t) * {.__l_coord=index_to_layer_coord(_l_s_index), .__n_s_coord=_n_s_coord}
}
/*

*/
___cwcn_bool_t is_layer_index_input(__tsinuu_t * _tsinuu, __layer_stack_coord_t * _l_s_coord){
    return _tsinuu->__layers[_l_s_coord->__layer_index]->__lbp->__is_input;
}
___cwcn_bool_t is_layer_index_output(__tsinuu_t * _tsinuu, __layer_stack_coord_t * _l_s_coord){
    return _tsinuu->__layers[_l_s_coord->__layer_index]->__lbp->__is_output;
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
unsigned int layer_size_from_layer_stack_index(__tsinuu_t * _tsinuu, unsigned int _l_index){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <layer_size_from_layer_stack_index> suspect element _layer_index: %d has __node_count: %d \n", _l_index, _tsinuu->__layers[_l_index]->__node_count);
        if(_l_index>=total_layers(_tsinuu)){
            fprintf(stderr, "ERROR: idx__line exceeds maxima, try NUM_LAYERS-0x01, for last layer.");
            assert(0x00);
        }
    #endif
    return _tsinuu->__layers[_l_index]->__node_count;
}
unsigned int input_size(__tsinuu_t * _tsinuu){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <input_size> suspect element layer_id: %d\n",0x00);
        if(!is_layer_index_input(_tsinuu, 0x00)){
            fprintf(stdout, ">>>> ERROR layer_index %d expected to be class input.\n",0x00);
        }
    #endif
    return layer_size_from_layer_coord(_tsinuu, __layer_coords_t * {.__layer_index=0x00});
}
unsigned int output_size(__tsinuu_t * _tsinuu){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <output_size> suspect element layer_id: %d \n", total_layers(_tsinuu)-0x01);
        if(!is_layer_index_output(_tsinuu, total_layers(_tsinuu)-0x01)){
            fprintf(stdout, ">>>> ERROR layer_index %d expected to be class output.\n", total_layers(_tsinuu)-0x01);
        }
    #endif
    return layer_size_from_layer_coord(_tsinuu, __layer_coords_t * {.__layer_index=total_layers(_tsinuu)-0x01});
}
/*

*/
unsigned int count_total_nodes(__tsinuu_t * _tsinuu){
    unsigned int total_nodes_ctx = 0x00;
    for(unsigned int idx_l=0x00;idx_l<total_layers(_tsinuu);idx_l++){
        total_nodes_ctx += layer_size_from_layer_stack_index(_tsinuu, idx_l);
    }
}
unsigned int count_total_lines(__tsinuu_t * _tsinuu){
    unsigned int total_lines_ctx = 0x00;
    for(unsigned int idx_l=0x00;idx_l<total_layers(new_tsinuu)-0x01;idx_l++){
        total_lines_ctx += layer_size_from_layer_stack_index(new_tsinuu, idx_l) * layer_size_from_layer_stack_index(new_tsinuu, idx_l+0x01);
    }
}

/*

*/
__cartecian_tensor_t * get_node_xyz(__tsinuu_t * _tsinuu, __node_coords_t _n_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <get_node_xyz>\n");
    #endif
    return _tsinuu->__layers[n_coord_to_l_index(_n_coord)]->__nodes[n_coord_to_n_index(_n_coord)]->__xyz_coord;
}
__cwcn_type_t get_node_x(__tsinuu_t * _tsinuu, __node_coords_t * _n_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <get_node_x>\n");
    #endif
    return _tsinuu->__layers[n_coord_to_l_index(_n_coord)]->__nodes[n_coord_to_n_index(_n_coord)]->__xyz_coord->__coord_x;
}
__cwcn_type_t get_node_y(__tsinuu_t * _tsinuu, __node_coords_t * _n_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <get_node_y>\n");
    #endif
    return _tsinuu->__layers[n_coord_to_l_index(_n_coord)]->__nodes[n_coord_to_n_index(_n_coord)]->__xyz_coord->__coord_y;
}
__cwcn_type_t get_node_z(__tsinuu_t * _tsinuu, __node_coords_t * _n_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <get_node_z>\n");
    #endif
    return _tsinuu->__layers[n_coord_to_l_index(_n_coord)]->__nodes[n_coord_to_n_index(_n_coord)]->__xyz_coord->__coord_z;
}

__cartecian_tensor_t * get_line_xyz(__tsinuu_t * _tsinuu, __line_stack_coord_t * _ln_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <get_line_xyz>\n");
    #endif
    return _tsinuu->__lines[ln_coord_to_ln_index(_ln_coord)]->__xyz_coord;
}
__cwcn_type_t get_line_x(__tsinuu_t * _tsinuu, __line_stack_coord_t * _ln_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <get_line_x>\n");
    #endif
    return _tsinuu->__lines[ln_coord_to_ln_index(_ln_coord)]->__xyz_coord->__coord_x;
}
__cwcn_type_t get_line_y(__tsinuu_t * _tsinuu, __line_stack_coord_t * _ln_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <get_line_y>\n");
    #endif
    return _tsinuu->__lines[ln_coord_to_ln_index(_ln_coord)]->__xyz_coord->__coord_y;
}
__cwcn_type_t get_line_z(__tsinuu_t * _tsinuu, __line_stack_coord_t * _ln_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <get_line_z>\n");
    #endif
    return _tsinuu->__lines[ln_coord_to_ln_index(_ln_coord)]->__xyz_coord->__coord_z;
}
/*

*/
__node_tsinuu_t * node(__tsinuu_t * _tsinuu, __node_coords_t * _n_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <node> \n");
        if(n_coord_to_l_index(_n_coord) > total_layers(_tsinuu)){
            fprintf(stderr, ">>>> ERROR: tsinuu <node> request layer index exceeds tsinuu limits.");
            assert(0x00);
        }
        if(n_coord_to_n_index(_n_coord) > layer_size_from_layer_coord(_tsinuu, n_coord_to_l_coord(_n_coord))){
            fprintf(stderr, ">>>> ERROR: tsinuu <node> request node index exceeds layer limits.");
            assert(0x00);
        }
    #endif
    return _tsinuu->__layer[n_coord_to_l_index(_n_coord)]->__nodes[n_coord_to_n_index(_n_coord)];
}
__node_kemu_t * node_kemu(__tsinuu_t * _tsinuu, __node_coords_t * _n_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <node_kemu>\n");
    #endif
    return node(_tsinuu, _n_coord)->__n_kemu;
}
__cwcn_type_t node_bias(__tsinuu_t * _tsinuu, __node_coords_t * _n_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <node bias>\n",);
    #endif
    return node_kemu(_tsinuu, _n_coord)->__bias;
}
__node_coords_t * node_coords_from_xyz(__tsinuu_t * _tsinuu, __cartecian_tensor_t * _xyz){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <node_coords_from_xyz>, x:%d, y:%d, z:%d\n", _xyz->__coord_x, _xyz->__coord_y, _xyz->__coord_z);
        fprintf(stdout, ">>>> WARNING <node_coords_from_xyz> is slow\n");
        fprintf(stdout, ">>>> WARNING <node_coords_from_xyz> might be wrong\n");
    #endif
    #ifdef TSINUU_DEBUG
    ___cwcn_bool_t find_f = ___CWCN_FALSE;
    for(unsigned int idx_l=0x00; idx_l<total_layers(_tsinuu); idx_l++){
        for(unsigned int idx_n=0x00; idx_n<layer_size_from_layer_stack_index(_tsinuu, idx_l); idx_n++){
            __node_stack_coord_t * c_node_s_coord = {.__node_index=idx_n};
            __node_coords_t * c_node_coord = {.__n_s_coord=c_node_s_coord, .__l_s_coord=c_layer_coord};
            if(get_node_x(_tsinuu, c_node_coord)==_xyz->__coord_x){
                if(get_node_y(_tsinuu, c_node_coord)==_xyz->__coord_y){
                    if(get_node_z(_tsinuu, c_node_coord)==_xyz->__coord_z){
                        return node(_tsinuu, c_node_coord);
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
            if(from_l - to_l + 0.01 == 0x00){
                fprintf(stderr, "ERROR: tsinuu <line> unreachable, SYMETRIC_TSINUU requires (from_layer == to_layer - 0x01)");
                assert(0x00);
            }
        #endif
        if(n_coord_to_l_index(_ln_coord->__from_node) >= total_layers(_tsinuu)-0x01){
            fprintf(stdout, "WARNING: tsinuu <line> from_node line index exceeds layer maxima.");
        } else if(n_coord_to_n_index(_ln_coord->__from_node) > layer_size_from_layer_coord(_tsinuu, n_coord_to_l_coord(_ln_coord->__from_node))){
            fprintf(stdout, "WARNING: tsinuu <line> from_node node index exceeds layer node maxima.");
        } else if(n_coord_to_l_index(_ln_coord->__to_node) >= total_layers(_tsinuu)){
            fprintf(stdout, "WARNING: tsinuu <line> to_node line index exceeds layer maxima.");
        } else if(n_coord_to_n_index(_ln_coord->__to_node) => layer_size_from_layer_coord(_tsinuu, n_coord_to_l_coord(_ln_coord->__to_node))){
            fprintf(stdout, "WARNING: tsinuu <line> to_node node index exceeds layer node maxima.");
        }
    #endif
    return _tsinuu->__lines[ln_coord_to_ln_index(_ln_coord)];
}
__line_tsinuu_t * line_kemu(__tsinuu_t * _tsinuu, __line_coords_t * _ln_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <line_kemu>\n");
    #endif
    return line(_tsinuu, _ln_coord)->__l_kemu;
}
__cwcn_type_t line_weight(__tsinuu_t * _tsinuu, __line_coords_t * _ln_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <line_weight>\n",);
    #endif
    return line_kemu(_tsinuu, _ln_coord)->__weight;
}
/*

*/
void set_node(__tsinuu_t * _tsinuu, __node_tsinuu_t * _node, __node_coords_t * _n_coord){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <set_node> 4 suspects, 1 warning\n");
        fprintf(stdout, ">>>> WARNING: <set_node> might be wrong\n");
        fprintf(stdout, ">>>> suspect element value _ %d  (may) not be equal to _ %d\n", get_node_x(_tsinuu, _n_coord), _node->__xyz_coord->__coord_x);
        fprintf(stdout, ">>>> suspect element address _ %p  (must) (not) be equal to _ %p\n",&get_node_x(_tsinuu, _n_coord), &_node);
    #endif
    *node(_tsinuu, _n_coord) = *_node;
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> suspect element value _ %d  (must) be equal to _ %d\n", get_node_x(_tsinuu, _n_coord), _node->__xyz_coord->__coord_x);
        fprintf(stdout, ">>>> suspect element address _ %p  (must) (not) be equal to _ %p\n",&get_node_x(_tsinuu, _n_coord), &_node);
    #endif
}
void set_node_kemu(__tsinuu_t * _tsinuu, __kemu_tsinuu_t * _n_kemu,  __node_coords_t * _n_coord){
    fprintf(stdout, "WARNING: <set_node_kemu> might be wrong");
    *node_kemu(_tsinuu, _n_coord) = *_n_kemu;
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <set_node_kemu>\n");
        fprintf(stdout, ">>>> WARNING: <set_node_kemu> might be wrong\n");
        fprintf(stdout, ">>>> suspect element value _ %d  must be equal to _ %d\n", node_kemu(_tsinuu, _n_coord)->__value, _n_kemu->__value);
        fprintf(stdout, ">>>> suspect element address _ %p  must (not) be equal to _ %p\n",&node_kemu(_tsinuu, _n_coord), &_n_kemu);
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
        fprintf(stdout, ">>>> suspect element value %d  must be zero\n",_node->__n_kemu->__value);
        fprintf(stdout, ">>>> suspect element value %d  must be zero\n",_node->__n_kemu->__value);
    #endif
}

void reset_kemu_forall_nodes(__tsinuu_t * _tsinuu){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <reset_kemu_forall_nodes>\n");
    #endif
    for(unsigned int idx_l=0;idx_l<total_layers(_tsinuu);idx_l++){
        for(unsigned int idx_n=0;idx_n<total_nodes();idx_n++){
            reset_node_kemu(_tsinuu, index_to_node_coord(idx_l, idx_n));
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
        fprintf(stdout, ">>>> suspect element value %d  must be zero\n",_line->__ln_kemu->__value);
        fprintf(stdout, ">>>> suspect element value %d  must be zero\n",_line->__ln_kemu->__value);
    #endif
}

void reset_kemu_forall_lines(__tsinuu_t * _tsinuu){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <reset_kemu_forall_lines>\n");
    #endif
    for(unsigned int idx_l=0;idx_l<total_layers(_tsinuu);idx_l++){
        for(unsigned int idx_n=0;idx_n<total_lines();idx_n++){
            reset_line_kemu(_tsinuu, index_to_line_coord(idx_l, idx_n));
        }
    }
}
/*

*/
__cwcn_type_t * read_layer_value_as_vector_from_coord(__tsinuu_t * _tsinuu, __layer_coords_t * _l_coord){
    const unsigned int n_l = layer_size_from_layer_coord(_l_coord);
    __cwcn_type_t _c_vector[n_l];
    for(unsigned int idx_n=0x00;idx_n<n_l;idx_n++){
        _c_vector[idx_n]=node_kemu(_tsinuu, index_to_node_coord(l_coord_to_l_index(_l_coord), idx_n))->__value;
    }
    return _c_vector;
}
__cwcn_type_t * read_layer_value_as_vector_from_idx(__tsinuu_t * _tsinuu, __layer_stack_coord_t * _l_s_coord){
    const unsigned int n_l = layer_size_from_layer_stack_index(_l_coord);
    __cwcn_type_t _c_vector[n_l];
    for(unsigned int idx_n=0x00;idx_n<n_l;idx_n++){
        _c_vector[idx_n]=node_kemu(_tsinuu, index_to_node_coord(_l_s_coord, idx_n))->__value;
    }
    return _c_vector;
}
/*

*/

__cwcn_type_t * read_output(__tsinuu_t * _tsinuu){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request read_ouput_value suspect element _ %d\n",);
    #endif
    return read_layer_value_as_vector_from_idx(_tsinuu, {.__layer_index=total_layers(_tsinuu)-0x01}); 
}
__cwcn_type_t * read_input(__tsinuu_t * _tsinuu){
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request read_input_value suspect element _ %d\n",);
    #endif
    return read_layer_value_as_vector_from_idx(_tsinuu, {.__layer_index=0x00}); 
}

void set_input(__tsinuu_t * _tsinuu, __cwcn_type_t * _input_vector){
    for(unsigned int idx_n=0;idx_n<layer_size_from_layer_stack_index(_tsinuu, 0x00);idx_n++){
        node_kemu(_tsinuu, index_to_node_coord(0x00, idx_n))->__value = _input_vector[idx_n]; // #FIXME no assert for input vector size.
    }
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <set_input> suspect element layer_id: %d\n",0x00);
        if(!is_layer_index_input(_tsinuu, {.__layer_index=0x00})){
            fprintf(stdout, ">>>> ERROR set_input %d expected to be class input.\n",0x00);
        }
        fprintf(stdout, ">>>> suspect element value _ %d  must be equal to _ %d\n",node_kemu(_tsinuu, index_to_node_coord(0x00, 0x00))->__value, _input_vector[0x00]);
        fprintf(stdout, ">>>> suspect element address _ %p  must (not) be equal to _ %p\n",&node_kemu(_tsinuu, index_to_node_coord(0x00, 0x00))->__value, &_input_vector[0x00]);
    #endif
}
void set_output(__tsinuu_t * _tsinuu, __cwcn_type_t * _output_vector){
    for(unsigned int idx_n=0;idx_n<layer_size_from_layer_stack_index(_tsinuu, total_layers(_tsinuu)-0x01);idx_n++){
        node_kemu(_tsinuu, index_to_node_coord(total_layers(_tsinuu)-0x01, idx_n))->__value = _output_vector[idx_n]; // #FIXME no assert for output vector size.
    }
    #ifdef TSINUU_DEBUG
        fprintf(stdout, ">>>> request <set_output> suspect element layer_id: %d\n",0x00);
        fprintf(stdout, ">>>> suspect element value _ %d  must be equal to _ %d\n",node_kemu(_tsinuu, index_to_node_coord(total_layers(_tsinuu)-0x01, 0x00))->__value, _outpu_vector[0x00]);
        fprintf(stdout, ">>>> suspect element address _ %p  must (not) be equal to _ %p\n",&node_kemu(_tsinuu, index_to_node_coord(total_layers(_tsinuu)-0x01, 0x00))->__value, &_outpu_vector[0x00]);
    #endif
}
/*
    FABRIC
*/
__tsinuu_t * tsinuu_fabric(__attribute_tsinuu_t * _attributes){
    #ifdef TSINUU_DEBUG
        fprintf(stdout,">> request <tsinuu_fabric> for a new_tsinuu: %ld\n");
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
    new_tsinuu->__attributes->__NUM_TOTAL_LAYERS = _attributes->__NUM_TOTAL_LAYERS;
    new_tsinuu->__attributes->__NUM_TOTAL_NODES = count_total_nodes(_tsinuu);
    new_tsinuu->__attributes->__NUM_TOTAL_LINES = count_total_lines(_tsinuu);
    new_tsinuu->__attributes->__layers_sizes = malloc(total_layers(new_tsinuu)*sizeof(unsigned int));
    new_tsinuu->__attributes->__layers_activation = malloc(total_layers(new_tsinuu)*sizeof(__list_activations_t));
    for(unsigned int idx_ls=0x00;idx_ls<total_layers(new_tsinuu);idx_ls++){
        new_tsinuu->__attributes->__layers_sizes[idx_ls] = _attributes->__layers_sizes[idx_ls];
        new_tsinuu->__attributes->__layers_activation[idx_ls] = _attributes->__layers_activation[idx_ls];
    }
    free(_attributes); // here config stops, and fabric takes automatically
    /*
        LOOP OVER LAYERS
    */
    unsigned int ctx_n=0x00;
    for(unsigned int idx_l=0x00; idx_l < total_layers(new_tsinuu); idx_l++){
        ctx_n = layer_size_from_layer_stack_index(new_tsinuu, idx_l);
        new_tsinuu->__layers[idx_l]->__lbp->__is_output=(idx_l==total_layers(_tsinuu)-0x01);
        new_tsinuu->__layers[idx_l]->__lbp->__is_input=(idx_l==0x00);
        new_tsinuu->__layers[idx_l]->__nodes=malloc(ctx_n*sizeof(__node_tsinuu_t));
        for(unsigned int idx_n=0x00;idx_n<ctx_n;idx_n++){
            __node_tsinuu_t * new_node = malloc(sizeof(__node_tsinuu_t));
            if(idx_l==0x00){
                assert(new_tsinuu->__attributes->__layers_activation[idx_l] == LINEAR);
            }
            new_node->__type = new_tsinuu->__attributes->__layers_activation[idx_l];
            switch(new_tsinuu->__attributes->__layers_activation[idx_l]){
                case SIGMOID:
                    new_node->__direct = & nat_sigmoid_direct;
                    new_node->__inverse = & nat_sigmoid_inverse;
                    new_node->__direct_derivate = & nat_sigmoid_direct_derivate;
                    new_node->__inverse_derivate = & nat_sigmoid_inverse_derivate;
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
            new_node->__n_coord->__l_coord->__l_s_coord->__layer_index=idx_l;
            new_node->__n_coord->__n_s_coord->__node_index=idx_n;
            new_node->__n_coord->__xyz_coord->__coord_x=idx_l;
            new_node->__n_coord->__xyz_coord->__coord_y=idx_n;
            new_node->__n_coord->__xyz_coord->__coord_z=0x00;

            new_node->__nbp->__pardon_value=___CWCN_FALSE;
            new_node->__nbp->__pardon_grad=___CWCN_FALSE;
            new_node->__nbp->__pardon_bias=___CWCN_FALSE;
            new_node->__nbp->__pardon_maxmin=___CWCN_FALSE;
            new_node->__nbp->__pardon_entropy=___CWCN_FALSE;
            new_node->__nbp->__pardon_mean=___CWCN_FALSE;
            new_node->__nbp->__pardon_std=___CWCN_FALSE;
            new_node->__nbp->__pardon_error=___CWCN_FALSE;
            new_node->__nbp->__has_value=___CWCN_FALSE;
            new_node->__nbp->__has_grad=___CWCN_FALSE;
            new_node->__nbp->__is_input=new_tsinuu->__layers[idx_l]->__lbp->__is_input;
            new_node->__nbp->__is_output=new_tsinuu->__layers[idx_l]->__lbp->__is_output;
            new_node->__nbp->__is_reset=___CWCN_FALSE;
            reset_node_kemu(new_node);
            #ifdef TSINUU_DEBUG
                fprintf(stdout, "WARNING: tsinuu new_node asigment might be incorrect after free");
            #endif
            new_tsinuu->__layers[idx_l]->__nodes[idx_n] = new_node;
            free(new_node);
            free(new_kemu_tsinuu);
        }
    }
    #ifdef TSINUU_DEBUG
    fprintf(stdout, ">>>> suspect element value _ %d  must be equal to _ %d\n",);
    fprintf(stdout, ">>>> suspect element address _ %p  must be equal to _ %p\n",);
    #endif
    /*
        LOOP OVER LINES
    */
    // new_tsinuu->__lines = malloc((new_tsinuu->__attributes->__NUM_TOTAL_LINES) * sizeof(__line_tsinuu_t));
    unsigned int ln_ctx = 0x00;
    for(unsigned int idx_l_to=0x01; idx_l_to<total_layers(new_tsinuu); idx_l_to++){
        for(unsigned int idx_n_to=0x00;idx_n_to<layer_size_from_layer_stack_index(new_tsinuu, idx_l_to);idx_n_to++){
            for(unsigned int idx_n_from=0x00;idx_n_from<layer_size_from_layer_stack_index(new_tsinuu, idx_l_to-0x01);idx_n_from++){
                __line_tsinuu_t * new_line = malloc(sizeof(__line_tsinuu_t));
                new_line->__lnbp->__pardon_grad=___CWCN_FALSE;
                new_line->__lnbp->__pardon_weight=___CWCN_FALSE;
                new_line->__lnbp->__has_value=___CWCN_FALSE;
                new_line->__lnbp->__has_grad=___CWCN_FALSE;
                new_line->__lnbp->__is_reset=___CWCN_FALSE;
                __node_coords_t * to_node_coord = index_to_node_coord(idx_l_to, idx_n_to);
                __node_coords_t * from_node_coord = index_to_node_coord(idx_l_to-0x01, idx_n_from);
                new_line->__ln_coord->__ln_s_coord->__line_index=ln_ctx;
                new_line->__ln_coord->__xyz_coord->__coord_x=(get_node_x(_tsinuu, from_node_coord)+get_node_x(_tsinuu, to_node_coord))/2.0;
                new_line->__ln_coord->__xyz_coord->__coord_y=(get_node_y(_tsinuu, from_node_coord)+get_node_y(_tsinuu, to_node_coord))/2.0;
                new_line->__ln_coord->__xyz_coord->__coord_z=(get_node_z(_tsinuu, from_node_coord)+get_node_z(_tsinuu, to_node_coord))/2.0;
                new_line->__from_node=node(_tsinuu, from_node_coord);
                new_line->__to_node=node(_tsinuu, to_node_coord);
                new_line->__type = SCALAR; // #FIXME allow for other types
                reset_line_kemu(new_line);
                new_tsinuu->__lines[ln_ctx]=new_line;
                ln_ctx++;
                free(new_line);
            }
        }
    }
    #ifdef TSINUU_DEBUG
        printf(">> node count: %d must be eq to %d\n", total_nodes(new_tsinuu), n_ctx);
        printf(">> line count: %d must be eq to %d\n", new_tsinuu->__attributes->__NUM_TOTAL_LINES, ln_ctx);
        printf(">> : %d\n", );
    #endif
    return new_tsinuu;
}
void tsinuu_destroy(__tsinuu_t * _tsinuu){
    fprintf(stdout, "<<_tsinuu_destry still in develpment, remmember malloc check utside function.>>");
    for(unsigned int idx_n=0; idx_n<_tsinuu->__attributes->__NUM_TOTAL_NODES;idx_n++){
        free(_tsinuu->__nodes[idx_n]->__n_kemu);
        free(_tsinuu->__nodes[idx_n]);
    }
    for(unsigned int idx_l=0; idx_l<_tsinuu->__attributes->__NUM_TOTAL_LINES;idx_l++){
        free(_tsinuu->__lines[idx_l]);
    }
    free(_tsinuu->__nodes);
    free(_tsinuu->__lines);
    free(_tsinuu->__attributes);
    free(_tsinuu);
    #ifdef TSINUU_DEBUG
    // fprintf(stdout, ">>>> suspect element value _ %d  must be equal to _ %d\n",);
    // fprintf(stdout, ">>>> suspect element address _ %p  must be equal to _ %p\n",);
    #endif
}
