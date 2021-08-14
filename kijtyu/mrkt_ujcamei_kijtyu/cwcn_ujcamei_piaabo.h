#ifndef UJCAMEI_PIABOO_INCLUDED
#define UJCAMEI_PIABOO_INCLUDED
#include "wikimyei.config.h" // #FIXME
#include <math.h>
#include <assert.h>
#include <stdlib.h>
typedef _Bool ___cwcn_bool_t;
typedef float (__cwcn_type_t);
#define __cwcn_infinite (__cwcn_type_t) 0xFFFFFFFF
#define ___CWCN_TRUE (___cwcn_bool_t) 0b1
#define ___CWCN_FALSE (___cwcn_bool_t) 0b0
#define max(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a > _b ? _a : _b;})
#define min(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a < _b ? _a : _b;})
typedef enum{
    UNIT_as_alliu,
    SINE_as_alliu,
    INDEX_as_alliu,
    negINDEX_as_alliu,
    MARKET_as_alliu
} __alliu_source_t; // not in use #FIXME
typedef struct __alliu {
    __alliu_source_t __source_type;
    __cwcn_type_t *__source_value;
    unsigned int __source_size;
    unsigned int __source_count;
}__alliu_t;
__alliu_t *alliu_fabric(__alliu_source_t _source_type, unsigned int _source_size);
void getnext_alliu(__alliu_t *_alliu);
void alliu_destroy(__alliu_t *_alliu);
#endif

