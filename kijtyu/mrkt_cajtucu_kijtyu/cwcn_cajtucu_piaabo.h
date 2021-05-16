// remmemer PMF[a_idx], from I, from the past ¿do we make it?.
#ifndef CUJTUCU_PIAABO_INCLUDED
#define CUJTUCU_PIAABO_INCLUDED
#include <stdlib.h>
#include <assert.h>
typedef _Bool ___cwcn_bool_t;
typedef float (__cwcn_type_t);
#define __cwcn_infinite (__cwcn_type_t) 0xFFFFFFFF
#define ___CWCN_TRUE (___cwcn_bool_t) 0b1
#define ___CWCN_FALSE (___cwcn_bool_t) 0b0
#define max(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a > _b ? _a : _b;})
#define min(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a < _b ? _a : _b;})
typedef enum {
    PLACED_tsane_status,
    FILLED_tsane_status,
    NONE_tsane_status
}__tsane_status_t;
typedef struct __tsane {
    unsigned int __tsane_size;
    unsigned int __tsane_index;
    ___cwcn_bool_t __take_tsane; // set to perform actual order
    __cwcn_type_t *__tsane_value;
    __tsane_status_t __tsane_status_value;
}__tsane_t;
__tsane_t *tsane_fabric(___cwcn_bool_t _take_tsane, unsigned int _tsane_size);
void putc_tsane(__tsane_t *_tsane);
void tsane_destroy(__tsane_t *_tsane);
#endif
