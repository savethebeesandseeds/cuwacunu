#ifndef DUURUVA_NEBAJKE_INCLUDED
#define DUURUVA_NEBAJKE_INCLUDED
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define BUGGER_SIZE_DUURUVA (unsigned int) 11
#define NAT_TYPE
typedef _Bool ___cwcn_bool_t;
typedef float (__cwcn_type_t);
#define __cwcn_type_size sizeof(__cwcn_type_t) // #FIXME not in use
typedef __cwcn_type_t (*__function_pointer_t)(__cwcn_type_t);
#define __function_pointer_t_size sizeof(__function_pointer_t)
#define __cwcn_infinite (__cwcn_type_t) 0xFFFFFFFF
#define max(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a > _b ? _a : _b;})
#define min(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a < _b ? _a : _b;})
typedef struct __duuruva_dist_coord {
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
} __duuruva_dist_tensor_t;
typedef struct __duuruva_bolean_parametrics {
    ___cwcn_bool_t __pardon_maxmin;
    ___cwcn_bool_t __pardon_dist;
    ___cwcn_bool_t __pardon_count;
}__duuruva_bolean_parametrics_t;
typedef struct __duuruva {
    unsigned int __num_base_duuruva;
    unsigned int __duuruva_vector_size;
    __cwcn_type_t *__value;
    __duuruva_bolean_parametrics_t * __dvbp;
    __duuruva_dist_tensor_t *__dv_dist;
} __duuruva_t;
void set_duuruvaboleanparametrics(
    __duuruva_t *_duuruva,
    ___cwcn_bool_t _pardon_maxmin,
    ___cwcn_bool_t _pardon_dist,
    ___cwcn_bool_t _pardon_count);
void reset_duuruva(__duuruva_t *_duuruva);
void dist_duuruva(__duuruva_t *_duuruva);
void print_duuruva(__duuruva_t *_duuruva);
__duuruva_t *duuruva_fabric(unsigned int _num_base_duuruva);
void duuruva_destroy(__duuruva_t *_duuruva);
void set_duuruva_value(__duuruva_t *_duuruva, __cwcn_type_t *_set_vector);
#endif