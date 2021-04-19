#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#ifndef TSINUU_PIAABO_INCLUDED
#define TSINUU_PIAABO_INCLUDED
#define TSINUU_PIAABO_DEBUG
#define ARRAY_SIZE(x) (unsigned int)(sizeof(x)/sizeof((x)[0]))
#define NAT_TYPE
#define SYMETRIC_TSINUU // #FIXME, not in use, but true. (fix both)
// #define BIN_TYPE
#ifdef NAT_TYPE
    typedef enum{
        NAT,
        BIN
    } wbase_t; // not in use #FIXME
    typedef enum{
        SIGMOID,
        LINEAR
    } list_activations_t;
    typedef float (__cwcn_type);
    __cwcn_type nat_sigmoid_direct(__cwcn_type _input);
    __cwcn_type nat_sigmoid_direct_derivate(__cwcn_type _input);
    __cwcn_type nat_sigmoid_inverse(__cwcn_type _input);
    __cwcn_type nat_sigmoid_inverse_derivate(__cwcn_type _input);
    __cwcn_type linear_direct(__cwcn_type _input);
    __cwcn_type linear_direct_derivate(__cwcn_type _input);
    __cwcn_type linear_inverse(__cwcn_type _input);
    __cwcn_type linear_inverse_derivate(__cwcn_type _input);
    typedef __cwcn_type (*__function_pointer)(__cwcn_type);
    #define __cwcn_type_size sizeof(__cwcn_type)
    #define __function_pointer_size sizeof(__function_pointer)
    typedef struct kemu_tsinuu {
        _Bool __cpte_bias_f;
        _Bool __cpte_grad_f;
        _Bool __cpte_error_f;
        _Bool __cpte_maxmin_f;
        _Bool __cpte_std_f;
        _Bool __cpte_mean_f;
        _Bool __cpte_entropy_f;
        __cwcn_type __value;
        __cwcn_type __bias;
        __cwcn_type __grad;
        __cwcn_type __error; 
        __cwcn_type __max;
        __cwcn_type __min;
        __cwcn_type __std;
        __cwcn_type __mean;
        __cwcn_type __entropy;
    } kemu_tsinuu_t;
    typedef struct node_tsinuu {
        list_activations_t __type; 
        __function_pointer __direct;
        __function_pointer __inverse;
        __function_pointer __direct_derivate;   // RL train
        __function_pointer __inverse_derivate;  // IL train
        kemu_tsinuu_t * __kemu;
    } node_tsinuu_t;
    typedef struct line_tsinuu {
        __cwcn_type __weight;
        unsigned int __from_layer;
        unsigned int __from_node;
        unsigned int __to_layer;
        unsigned int __to_node;
    } line_tsinuu_t;
    typedef struct attribute_tsinuu {
        unsigned int *__LAYERS_SIZES; // Include input size and output size // #FIXME waajacu can do better than fixed forward architecture.
        unsigned int __NUM_TOTAL_LAYERS; // INCLUDE INPTU, INCLUDE OUPUT
        unsigned int __NUM_TOTAL_NODES;
        unsigned int __NUM_TOTAL_LINES;
        list_activations_t *__layers_activation;
    } attribute_tsinuu_t;
    typedef struct tsinuu {
        node_tsinuu_t **__nodes;
        line_tsinuu_t **__lines;
        attribute_tsinuu_t *__attributes;
    } tsinuu_t;
    tsinuu_t * tsinuu_fabric(attribute_tsinuu_t * _attributes);
    void tsinuu_initialize_weights(tsinuu_t * _tsinuu);
    void tsinuu_destroy(tsinuu_t * _tsinuu);
    void tsinuu_propagate_forward(tsinuu_t * _tsinuu, __cwcn_type * _input);
    __cwcn_type * read_output_value(tsinuu_t * _tsinuu);
    unsigned int total_layers(tsinuu_t * _tsinuu);
    unsigned int total_nodes(tsinuu_t * _tsinuu);
    unsigned int total_lines(tsinuu_t * _tsinuu);
    unsigned int layer_size(tsinuu_t * _tsinuu, unsigned int idx_l);
    unsigned int input_size(tsinuu_t * _tsinuu);
    unsigned int output_size(tsinuu_t * _tsinuu);
    unsigned int idx_sumupto_layer(tsinuu_t * _tsinuu, unsigned int idx_l);
    unsigned int idx_sumupto_node(tsinuu_t * _tsinuu, unsigned int idx_l ,unsigned int idx_n);
    unsigned int idx_sumupto_line(tsinuu_t * _tsinuu, unsigned int from_l, unsigned int from_n, unsigned int to_l, unsigned int to_n);
    node_tsinuu_t * node(tsinuu_t * _tsinuu, unsigned int idx_l, unsigned int idx_n);
    kemu_tsinuu_t * node_kemu(tsinuu_t * _tsinuu, unsigned int idx_l, unsigned int idx_n);
    line_tsinuu_t * line(tsinuu_t * _tsinuu, unsigned int from_l, unsigned int from_n, unsigned int to_l, unsigned int to_n);
    __cwcn_type line_weight(tsinuu_t * _tsinuu, unsigned int from_l, unsigned int from_n, unsigned int to_l, unsigned int to_n);
    void set_node(tsinuu_t * _tsinuu, node_tsinuu_t * _node, unsigned int idx_l, unsigned int idx_n);
    void set_node_kemu(tsinuu_t * _tsinuu, kemu_tsinuu_t * _kemu,  unsigned int idx_l, unsigned int idx_n);
    void set_input(tsinuu_t * _tsinuu, __cwcn_type * _input_vector);
    void set_output(tsinuu_t * _tsinuu, __cwcn_type * _input_vector);
    void reset_set_node_kemu(tsinuu_t * _tsinuu, unsigned int idx_l, unsigned int idx_n, _Bool _pardon_bias, _Bool _pardon_grad, _Bool _pardon_maxmin, _Bool _pardon_dist);
    void reset_all_nodes_kemu(tsinuu_t * _tsinuu, _Bool _pardon_bias, _Bool _pardon_grad, _Bool _pardon_maxmin, _Bool _pardon_dist);
#else 
    #ifdef BIN_TYPE
        typedef __uint8_t (__cwcn_type);
        __uint8_t bin_sigmoid(__uint8_t _input);
    #endif
#endif
#endif