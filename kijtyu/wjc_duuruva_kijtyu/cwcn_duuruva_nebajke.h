#ifndef DUURUVA_NEBAJKE_INCLUDED
#define DUURUVA_NEBAJKE_INCLUDED
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// #FIXME fix dependencies
#define __ALLOW_DUURUVA_DUMPFILE__

#define BUGGER_SIZE_DUURUVA (unsigned int) 12
#define BUGGER_READY_DUURUVA_COUNT (unsigned int) 5
#define BUGGER_MAX_DUURUVA_COUNT (__cwcn_type_t) 100.0
#define BUGGER_DUURUVA_MIN_STD (float) 0.0001
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

typedef struct __duuruva_diff_tensor {
    __cwcn_type_t __past_v; // holding value for change computation
    __cwcn_type_t __diff_1; // first derivate (value valocity)
    __cwcn_type_t __diff_2; // second derivate (value aceleration)
    // ...
    // __cwcn_type_t __itg_1; ...
} __duuruva_diff_tensor_t;

typedef struct __duuruva_bolean_parametrics {
    ___cwcn_bool_t __pardon_maxmin;
    ___cwcn_bool_t __pardon_dist;
    ___cwcn_bool_t __pardon_diff;
    ___cwcn_bool_t __pardon_count;
    ___cwcn_bool_t __reset_flag;
}__duuruva_bolean_parametrics_t;
typedef struct __duuruva {
    char *__duuruva_dumpfile;
    unsigned int __duuruva_base_size;
    unsigned int __duuruva_vector_size;
    __cwcn_type_t *__value;
    __duuruva_bolean_parametrics_t * __dvbp;
    __duuruva_dist_tensor_t *__dv_dist;
    __duuruva_diff_tensor_t *__dv_diff;
} __duuruva_t;
void set_duuruvaboleanparametrics(
    __duuruva_t *_duuruva,
    ___cwcn_bool_t _pardon_maxmin,
    ___cwcn_bool_t _pardon_dist,
    ___cwcn_bool_t _pardon_diff,
    ___cwcn_bool_t _pardon_count);

__duuruva_t *duuruva_fabric(unsigned int _num_base_duuruva, char *_dumpfilepath);
void duuruva_destroy(__duuruva_t *_duuruva);
void reset_duuruva(__duuruva_t *_duuruva);
void reset_duuruva_max_min(__duuruva_t *_duurva);
void diff_duuruva(__duuruva_t *_duuruva);
void dist_duuruva(__duuruva_t *_duuruva);
void print_duuruva(__duuruva_t *_duuruva);

void set_duuruva_value(__duuruva_t *_duuruva, __cwcn_type_t *_set_vector);
void read_duuruva_vector(__duuruva_t *_duuruva, __cwcn_type_t *_dvx, ___cwcn_bool_t _norm_or_standar);
__cwcn_type_t *get_duuruva_value(__duuruva_t *_duuruva);
___cwcn_bool_t is_duuruva_ready(__duuruva_t *_duuruva);

__cwcn_type_t duuruva_standarize_inindex(__duuruva_t *_duuruva, __cwcn_type_t _value_scalar, unsigned int _idx);
__cwcn_type_t duuruva_normalize_inindex(__duuruva_t *_duuruva, __cwcn_type_t _value_scalar, unsigned int _idx);
__cwcn_type_t duuruva_destandarize_inindex(__duuruva_t *_duuruva, __cwcn_type_t _value_scalar, unsigned int _idx);
__cwcn_type_t duuruva_denormalize_inindex(__duuruva_t *_duuruva, __cwcn_type_t _value_scalar, unsigned int _idx);

void duuruva_standarize(__duuruva_t *_duuruva, __cwcn_type_t *_value_vect);
void duuruva_normalize(__duuruva_t *_duuruva, __cwcn_type_t *_value_vect);
void duuruva_destandarize(__duuruva_t *_duuruva, __cwcn_type_t *_value_vect);
void duuruva_denormalize(__duuruva_t *_duuruva, __cwcn_type_t *_value_vect);
void normalize_duuruva_values(__duuruva_t *_duuruva);

void reset_dumpfile(__duuruva_t *_duuruva);
void duuruva_value_to_dumpfile(__duuruva_t *_duuruva);
#endif
