#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#ifdef WIKIMYEI_PIAABO_INCLUDED
#include "cwcn_wikimyei_piaabo.h"
#endif
#ifndef TSINUU_PIAABO_INCLUDED
#define TSINUU_PIAABO_INCLUDED
// #define TSINUU_DEBUG
#define NAT_TYPE
#define SYMETRIC_TSINUU // #FIXME, not in use, but true. (fix both)
#define TSINUU_FORWARD

#define __MIN_SUM_NABLA__ (__cwcn_type_t) 0.0
#define __TSINUU_NODE_SUM_MAX__ (__cwcn_type_t) 5.0
#define __TSINUU_MAX_DELTA_WEIGHT__ (__cwcn_type_t) 0.1
#define __TSINUU_MAX_DELTA_BIAS__ (__cwcn_type_t) 0.1

// #define TSINUU_VERBOSE_1
// #define TSINUU_VERBOSE_2
// #ifdef TSINUU_BACKWARD
// #define TSINUU_BACKWARD
// #endif
// #define TSINUU_DEBUG
// #define TSINUU_DEBUG_v2
typedef _Bool ___cwcn_bool_t;
#define ___CWCN_TRUE (___cwcn_bool_t) 0b1
#define ___CWCN_FALSE (___cwcn_bool_t) 0b0
#define max(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a > _b ? _a : _b;})
#define min(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a < _b ? _a : _b;})
#ifdef NAT_TYPE
    typedef enum{
        NAT, // NATS is a measure of entropy.
        BIN // BITS is a measure of entropy.
    } __wbase_t; // not in use #FIXME
    typedef enum{
        SIGMOID,  // pretty powerfull sigmoid.
        SIGNEDSIGMOID, // a sigmoid that goes from negative one to one.
        SCALAR, // y=a.x
        LINEAR,  // y=x
        RELU,  // y=max(0,x)
        SOFTPLUS // a suavizated relu
    } __list_activations_t;
    typedef float (__cwcn_type_t);
    #define __cwcn_type_size sizeof(__cwcn_type_t) // #FIXME not in use
    typedef __cwcn_type_t (*__function_pointer_t)(__cwcn_type_t);
    #define __function_pointer_t_size sizeof(__function_pointer_t)
    #define __cwcn_infinite (__cwcn_type_t) 0xFFFFFFFF
    typedef struct __cartecian_tensor {
        __cwcn_type_t __coord_x;
        __cwcn_type_t __coord_y;
        __cwcn_type_t __coord_z;
    } __cartecian_tensor_t;
    typedef struct __dist_coord {
        __cwcn_type_t __count; // is not so much count as is the back span of the load
        __cwcn_type_t __max;
        __cwcn_type_t __min;
        __cwcn_type_t __std;
        __cwcn_type_t __mean;
        __cwcn_type_t __M2;
        __cwcn_type_t __M3;
        __cwcn_type_t __M4;
        __cwcn_type_t __kurtosis;
        __cwcn_type_t __skewness;
        __cwcn_type_t __entropy;
    } __dist_tensor_t;
    typedef struct __limits {
        __cwcn_type_t __max;
        __cwcn_type_t __min;
    } __limits_t;
    typedef struct __node_stack_coord { // the coordinate of node in layer
        unsigned int __node_index;
    } __node_stack_coord_t;
    typedef struct __line_stack_coord { // line, given two node coords
        unsigned int __line_index;
    } __line_stack_coord_t;
    typedef struct __layer_stack_coord { // layer in tsinuu
        unsigned int __layer_index;
    } __layer_stack_coord_t; // coord specify index in stack.
    typedef struct __nodeboolean_parametric {
        ___cwcn_bool_t __pardon_value;
        ___cwcn_bool_t __pardon_grad;
        ___cwcn_bool_t __pardon_bias;
        ___cwcn_bool_t __pardon_maxmin;
        ___cwcn_bool_t __pardon_entropy;
        ___cwcn_bool_t __pardon_dist;
        ___cwcn_bool_t __pardon_count;
        ___cwcn_bool_t __pardon_error;
        ___cwcn_bool_t __has_value;
        ___cwcn_bool_t __has_grad;
        ___cwcn_bool_t __is_input;
        ___cwcn_bool_t __is_output;
        ___cwcn_bool_t __is_reset;
    } __nodeboolean_parametric_t;
    typedef struct __layerboolean_parametric { // #FIXME make layerbooleanpardon
        ___cwcn_bool_t __is_input;
        ___cwcn_bool_t __is_output;
    } __layerboolean_parametric_t;
    typedef struct __lineboolean_parametric {
        ___cwcn_bool_t __pardon_weight;
        ___cwcn_bool_t __pardon_grad;
    } __lineboolean_parametric_t;
    typedef struct __node_kemu {
        __cwcn_type_t __value;
        __cwcn_type_t __error;
        __cwcn_type_t __bias;
        __cwcn_type_t __bias_delta; // delta actual change
        __cwcn_type_t __nodeactivation_grad; // the node acitvation function derivate evaluated in the forward pass.
        __cwcn_type_t __nabla; // nabla is the error propagated by differential chain backward.
        __dist_tensor_t *__dist;
    } __node_kemu_t;
    typedef struct __line_kemu {
        __cwcn_type_t __weight;
        __cwcn_type_t __weight_delta;
    } __line_kemu_t;
    typedef struct __layer_kemu { // #FIXME empty
    } __layer_kemu_t;
    typedef struct __attribute_tsinuu { // to create a new tsinuu define input attribute with at least __NUM_TOTAL_LAYERS, __layers_sizes, __is_symetric and __layers_activation;
        unsigned int __NUM_TOTAL_NODES; // optional to create new
        unsigned int __NUM_TOTAL_LINES; // optional to create new
        unsigned int __NUM_TOTAL_LAYERS; // count INPUT, count HIDDEN, count OUTPUT
        unsigned int *__layers_sizes; // Include input size, each hidden size and output size in a vector
        ___cwcn_bool_t __is_symetric;
        __list_activations_t *__layers_activation;
        __cwcn_type_t __alpha; // required to create new tsinuu
        __cwcn_type_t __eta; // required to create new tsinuu
        __cwcn_type_t __omega; // required to create new tsinuu
        __cwcn_type_t __omega_stiffess; // requiresd to create new tsinuu
        __cwcn_type_t __wapaajco_potency; // required to create new tsinuu
        __limits_t *__weight_limits; // requiresd to create new tsinuu
        __limits_t *__bias_limits; // requiresd to create new tsinuu
        __cwcn_type_t *__layerweight_density;
        __cwcn_type_t *__layerbias_density;
        unsigned int *__forward_ln_index_list;
        unsigned int *__backward_ln_index_list;
    } __attribute_tsinuu_t;
    typedef struct __layer_coords {
        __layer_stack_coord_t *__l_s_coord; // used for confirmation porpouses
    } __layer_coords_t;
    typedef struct __node_coords {
        __layer_coords_t *__l_coord; // use in confirmation porpouses
        __node_stack_coord_t *__n_s_coord;
        __cartecian_tensor_t *__xyz_coord;
    } __node_coords_t;
    typedef struct __line_coords {
        __line_stack_coord_t *__ln_s_coord;
        __cartecian_tensor_t *__xyz_coord;
        __node_coords_t *__to_node;
        __node_coords_t *__from_node;
    } __line_coords_t;
    typedef struct __wapaajco_tsinuu {
        __cwcn_type_t *__w_vector;
        __cwcn_type_t __total_wapaajco;
    } __wapaajco_tsinuu_t;
    typedef struct __node_tsinuu {
        __node_kemu_t *__n_kemu;
        __node_coords_t *__n_coord;
        __list_activations_t __type; 
        __function_pointer_t __direct;
        __function_pointer_t __inverse;
        __function_pointer_t __direct_derivate;   // RL train
        __function_pointer_t __inverse_derivate;  // IL train
        __nodeboolean_parametric_t *__nbp;
    } __node_tsinuu_t;
    typedef struct __line_tsinuu {
        __line_kemu_t *__ln_kemu;
        __line_coords_t *__ln_coord;
        __list_activations_t __type;
        __lineboolean_parametric_t *__lnbp;
    } __line_tsinuu_t;
    typedef struct __layer_tsinuu {
        unsigned int __node_count;
        __node_tsinuu_t **__nodes;
        __layer_coords_t *__l_coord;
        __list_activations_t __layer_activation;
        __layerboolean_parametric_t *__lbp;
    } __layer_tsinuu_t;
    typedef struct __tsinuu {
        __layer_tsinuu_t **__layers;
        __line_tsinuu_t **__lines;
        __attribute_tsinuu_t *__attributes;
        __wapaajco_tsinuu_t *__wapaajco;
    } __tsinuu_t;
    
    __tsinuu_t *tsinuu_fabric(__attribute_tsinuu_t *_attributes);
    void tsinuu_destroy(__tsinuu_t *_tsinuu);

    void read_tsinuu_output(__tsinuu_t *_tsinuu, __cwcn_type_t *_result_vector);
    void read_tsinuu_input(__tsinuu_t *_tsinuu, __cwcn_type_t *_result_vector);
    void read_wapaajco(__tsinuu_t *_tsinuu, __cwcn_type_t *_wapaajco_vector);
    
    unsigned int total_layers(__tsinuu_t *_tsinuu);
    unsigned int total_nodes(__tsinuu_t *_tsinuu);
    unsigned int total_lines(__tsinuu_t *_tsinuu);
    
    unsigned int input_size(__tsinuu_t *_tsinuu);
    unsigned int output_size(__tsinuu_t *_tsinuu);
    
    __node_tsinuu_t *node(__tsinuu_t *_tsinuu, __node_coords_t *_n_coord);
    __node_kemu_t *node_kemu(__tsinuu_t *_tsinuu, __node_coords_t *_n_coord);
    __cwcn_type_t node_bias(__tsinuu_t *_tsinuu, __node_coords_t *_n_coord);
    
    __line_tsinuu_t *line(__tsinuu_t *_tsinuu, __line_coords_t *_ln_coord);
    __line_kemu_t *line_kemu(__tsinuu_t *_tsinuu, __line_coords_t *_ln_coord);
    __cwcn_type_t line_weight(__tsinuu_t *_tsinuu, __line_coords_t *_ln_coord);
    
    void read_layer_value_as_vector_from_coord(__tsinuu_t *_tsinuu, __layer_coords_t *_l_coord, __cwcn_type_t *_result_vector);
    void read_layer_value_as_vector_from_stack_coord(__tsinuu_t *_tsinuu, __layer_stack_coord_t *_l_s_coord, __cwcn_type_t *_result_vector);
    
    void tsinuu_initialize_weights_random(__tsinuu_t *_tsinuu, __cwcn_type_t _v_max, __cwcn_type_t _v_min);
    void tsinuu_initialize_weights_fixed(__tsinuu_t *_tsinuu, __cwcn_type_t _v_fixed);
    void tsinuu_initialize_weights_zero(__tsinuu_t *_tsinuu);
    void tsinuu_initialize_bias_random(__tsinuu_t *_tsinuu, __cwcn_type_t _v_max, __cwcn_type_t _v_min);
    void tsinuu_initialize_bias_fixed(__tsinuu_t *_tsinuu, __cwcn_type_t _v_fixed);
    void tsinuu_initialize_bias_zero(__tsinuu_t *_tsinuu);
    
    unsigned int l_coord_to_l_index(__layer_coords_t *_l_coord);
    unsigned int ln_coord_to_ln_index(__line_coords_t *_ln_coord);
    unsigned int n_coord_to_n_index(__node_coords_t *_n_coord);
    unsigned int n_coord_to_l_index(__node_coords_t *_n_coord);

    __layer_coords_t *n_coord_to_l_coord(__node_coords_t *_n_coord);
    
    __layer_stack_coord_t *layer_index_to_layer_stack_coord(__tsinuu_t *_tsinuu, unsigned int _l_s_index);
    __line_stack_coord_t *line_index_to_line_stack_coord(__tsinuu_t *_tsinuu, unsigned int _ln_s_index);
    __node_stack_coord_t *node_index_to_node_stack_coord(__tsinuu_t *_tsinuu, unsigned int _l_s_index, unsigned int _n_s_index);
    
    __layer_coords_t *layer_index_to_layer_coord(__tsinuu_t *_tsinuu, unsigned int _l_s_index);
    __line_coords_t *line_index_to_line_coord(__tsinuu_t *_tsinuu, unsigned int _ln_s_index);
    __node_coords_t *node_index_to_node_coord(__tsinuu_t *_tsinuu, unsigned int _l_s_index, unsigned int _n_s_index);
    
    ___cwcn_bool_t is_layer_index_input(__tsinuu_t *_tsinuu, unsigned int __l_index);
    ___cwcn_bool_t is_layer_index_output(__tsinuu_t *_tsinuu, unsigned int __l_index);

    unsigned int layer_size_from_layer_coord(__tsinuu_t *_tsinuu, __layer_coords_t *_l_coord);
    unsigned int layer_size_from_layer_stack_index(__tsinuu_t *_tsinuu, unsigned int _l_s_index);

    unsigned int count_total_nodes(__tsinuu_t *_tsinuu);
    unsigned int count_total_lines(__tsinuu_t *_tsinuu);
    
    __cartecian_tensor_t *get_node_xyz(__tsinuu_t *_tsinuu, __node_coords_t *_n_coord);
    __cwcn_type_t get_node_x(__tsinuu_t *_tsinuu, __node_coords_t *_n_coord);
    __cwcn_type_t get_node_y(__tsinuu_t *_tsinuu, __node_coords_t *_n_coord);
    __cwcn_type_t get_node_z(__tsinuu_t *_tsinuu, __node_coords_t *_n_coord);
    __cartecian_tensor_t *get_line_xyz(__tsinuu_t *_tsinuu, __line_coords_t *_ln_coord);
    __cwcn_type_t get_line_x(__tsinuu_t *_tsinuu, __line_coords_t *_ln_coord);
    __cwcn_type_t get_line_y(__tsinuu_t *_tsinuu, __line_coords_t *_ln_coord);
    __cwcn_type_t get_line_z(__tsinuu_t *_tsinuu, __line_coords_t *_ln_coord);
    __node_coords_t *node_coords_from_xyz(__tsinuu_t *_tsinuu, __cartecian_tensor_t *_xyz);
    
    void set_nodebooleanpardon_parametric(__tsinuu_t *_tsinuu,__node_coords_t *_n_coord,___cwcn_bool_t _pardon_value,___cwcn_bool_t _pardon_grad,___cwcn_bool_t _pardon_bias,___cwcn_bool_t _pardon_maxmin,___cwcn_bool_t _pardon_entropy,___cwcn_bool_t _pardon_dist, ___cwcn_bool_t _pardon_count, ___cwcn_bool_t _pardon_error);
    void set_layerbooleanpardon_parametric(__tsinuu_t *_tsinuu, __layer_coords_t *_l_coord); // there are non.
    void set_linebooleanpardon_parametric(__tsinuu_t *_tsinuu, __line_coords_t *_ln_coord,___cwcn_bool_t _pardon_grad,___cwcn_bool_t _pardon_weight);
    
    void set_all_nodebooleanpardon_parametric(__tsinuu_t *_tsinuu, ___cwcn_bool_t _pardon_value,___cwcn_bool_t _pardon_grad,___cwcn_bool_t _pardon_bias,___cwcn_bool_t _pardon_maxmin,___cwcn_bool_t _pardon_entropy,___cwcn_bool_t _pardon_dist, ___cwcn_bool_t _pardon_count,___cwcn_bool_t _pardon_error);
    void set_all_layerbooleanpardon_parametric(__tsinuu_t *_tsinuu); // there are non.
    void set_all_linebooleanpardon_parametric(__tsinuu_t *_tsinuu,___cwcn_bool_t _pardon_grad,___cwcn_bool_t _pardon_weight);

    void set_node(__tsinuu_t *_tsinuu, __node_tsinuu_t *_node, __node_coords_t *_n_coord);
    void set_node_kemu(__tsinuu_t *_tsinuu, __node_kemu_t *_n_kemu,  __node_coords_t *_n_coord);
    void set_tsinuu_input(__tsinuu_t *_tsinuu, __cwcn_type_t *_input_vector);
    void set_tsinuu_output(__tsinuu_t *_tsinuu, __cwcn_type_t *_output_vector);
    
    void reset_node_kemu(__node_tsinuu_t *_node);
    void reset_all_nodes_kemu(__tsinuu_t *_tsinuu);
    void reset_line_kemu(__line_tsinuu_t *_line);
    void reset_all_lines_kemu(__tsinuu_t *_tsinuu);
    void reset_layerdentities(__tsinuu_t *_tsinuu);
    
    void print_node_by_coord(__tsinuu_t *_tsinuu, __node_coords_t *_n_coord);
    void print_node_by_coord_with_argument(__tsinuu_t *_tsinuu, __node_coords_t *_n_coord, __cwcn_type_t _arg);
    void print_line_by_coord(__tsinuu_t *_tsinuu, __line_coords_t *_ln_coord);
    void print_layer_by_coord(__tsinuu_t *_tsinuu, __layer_coords_t *_l_coord);
    void print_tsninuu_jkimyei_results(__tsinuu_t *_tsinuu);
    void print_all_lines(__tsinuu_t *_tsinuu);
    void print_all_nodes(__tsinuu_t *_tsinuu);

    void reset_node_value(__node_tsinuu_t *_node);
    void reset_node_grad(__node_tsinuu_t *_node);
    void reset_node_error(__node_tsinuu_t *_node);
    void reset_all_nodes_value(__tsinuu_t *_tsinuu);
    void reset_all_nodes_grad(__tsinuu_t *_tsinuu);
    void reset_all_nodes_error(__tsinuu_t *_tsinuu);
    void reset_all_noninputnodes_values(__tsinuu_t *_tsinuu);
    void reset_all_nonoutputnodes_values(__tsinuu_t *_tsinuu);

    void reset_line_grad(__line_tsinuu_t *_line);
    void reset_all_lines_grad(__tsinuu_t *_tsinuu);

    void pardon_inputoutput_bias(__tsinuu_t *_tsinuu);
    void pardon_all_bias(__tsinuu_t *_tsinuu);

    unsigned int output_layer_index(__tsinuu_t *_tsinuu);
    __layer_coords_t *output_layer_coord(__tsinuu_t *_tsinuu);

    void clamp_all_bias(__tsinuu_t *_tsinuu);
    void clamp_bias(__tsinuu_t *_tsinuu, __node_kemu_t *_n_kemu);
    void clamp_all_weights(__tsinuu_t *_tsinuu);
    void clamp_weight(__tsinuu_t *_tsinuu, __line_kemu_t *_ln_kemu);
    
    __cwcn_type_t sum_all_weights(__tsinuu_t *_tsinuu);
    __cwcn_type_t sum_all_biases(__tsinuu_t *_tsinuu);
#else 
    #ifdef BIN_TYPE
        typedef __uint8_t (__cwcn_type_t);
        __uint8_t bin_sigmoid(__uint8_t _input);
    #endif
#endif
#endif