#ifndef JKIMYEI_PIAABO_INCLUDED
#define JKIMYEI_PIAABO_INCLUDED
#include "cwcn_wajyu_piaabo.h"
#include "cwcn_tsinuu_piaabo.h"
#include "cwcn_wikimyei_piaabo.h"
// #define JKIMYEI_DEBUG
typedef float (__cwcn_type_t);
typedef _Bool (___cwcn_bool_t);
// typedef __wikimyei_t;
#define ___CWCN_TRUE (___cwcn_bool_t) 0b1
#define ___CWCN_FALSE (___cwcn_bool_t) 0b0
#define max(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a > _b ? _a : _b;})
#define min(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a < _b ? _a : _b;})
void copy_c_cwcn_blocks_from_b_to_a(__cwcn_type_t *_a, __cwcn_type_t *_b, unsigned int _n_blocks);
/*

*/
typedef enum{
    JK_METHOD_FORWARD_SEQUENTAL,
    JK_METHOD_RANDOM,
    JK_METHOD_RANDOM_POSITIVE,
    JK_METHOD_RANDOM_NEGATIVE,
    JK_METHOD_RANDOM_2_POSITIVE_1_NEGATIVE,
    JK_METHOD_RANDOM_3_POSITIVE_1_NEGATIVE
} __list_jk_method_t;
typedef enum{
    JK_LOAD_AVIABLE_NEXT,
    JK_LOAD_AVIABLE_NEXT_POSITIVE,
    JK_LOAD_AVIABLE_NEXT_NEGATIVE,
    JK_LOAD_AVIABLE_PAST,
    JK_LOAD_AVIABLE_PAST_POSITIVE,
    JK_LOAD_AVIABLE_PAST_NEGATIVE,
    JK_LOAD_AVIABLE_RANDOM,
    JK_LOAD_AVIABLE_RANDOM_POSITIVE,
    JK_LOAD_AVIABLE_RANDOM_NEGATIVE
} __list_jk_load_method_t;
/*

*/
__cwcn_type_t sign_j_fun(__cwcn_type_t x);
/*

*/
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_NEXT(__wikimyei_t *_wikimyei);
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_NEXT_POSITIVE(__wikimyei_t *_wikimyei);
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_NEXT_NEGATIVE(__wikimyei_t *_wikimyei);
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_PAST(__wikimyei_t *_wikimyei);
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_PAST_POSITIVE(__wikimyei_t *_wikimyei);
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_PAST_NEGATIVE(__wikimyei_t *_wikimyei);
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_RANDOM(__wikimyei_t *_wikimyei);
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_RANDOM_POSITIVE(__wikimyei_t *_wikimyei);
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_RANDOM_NEGATIVE(__wikimyei_t *_wikimyei);

___cwcn_bool_t ___JK_ONE_JK_SIZE_WRAPPER(__wikimyei_t *_wikimyei);
___cwcn_bool_t ___JK_ONE_JK_COMPUTE_MULTIPLEXER_WRAPPER(__wikimyei_t *_wikimyei, __list_jk_load_method_t _jk_load_method);
void ___JK_EPOCH_JK_METHOD_MULTIPLEXER_WRAPPER(__wikimyei_t *_wikimyei, __list_jk_method_t _jk_method);
/*

*/
__jkimyei_t *jkimyei_fabric(unsigned int _jk_size);
void jkimyei_destroy(__jkimyei_t *_jkimyei);
/*

*/
// void release_jk(__wikimyei_t *_wikimyei);
// void fill_jk_rand(__wikimyei_t *_wikimyei);
/*

*/
int jk_rand_index(__wikimyei_t *_wikimyei);
void wikimyei_jkimyei(__wikimyei_t *_wikimyei, unsigned int _epochs, __list_jk_method_t _jk_method);
/*

*/
// __trayectory_t *jk_dequeue_trayectory(__jkimyei_t *_jkimyei);
// void jk_enqueue_trayectory(__jkimyei_t *_jkimyei, __trayectory_t *_new_trayectory);
// void jk_enqueue_trayectory_index(__wikimyei_t *_wikimyei, int _index, ___cwcn_bool_t _rneturn);
// void jk_print_trayectory_queue(__jkimyei_t *_jkimyei);
// __trayectory_t *jk_get_trayectory_item(__jkimyei_t *_jkimyei);
__cwcn_type_t jk_clamp(__cwcn_type_t d, __cwcn_type_t min, __cwcn_type_t max);
#endif
