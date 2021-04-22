
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cwcn_tsinuu_piaabo.h"
#ifndef TSINUU_DEBUG
#define TSINUU_DEBUG
#endif
#ifndef NAT_TYPE
#define NAT_TYPE
#endif
#ifndef SYMETRIC_TSINUU
#define SYMETRIC_TSINUU // #FIXME, not in use, but true. (fix both)
#endif
#ifndef TSINUU_NEBAJKE_INCLUDED
#define TSINUU_NEBAJKE_INCLUDED
#ifdef NAT_TYPE
    typedef __cwcn_type_t (*__function_pointer_t)(__cwcn_type_t);
    __cwcn_type_t nat_sigmoid_direct(__cwcn_type_t _input);
    __cwcn_type_t nat_sigmoid_direct_derivate(__cwcn_type_t _input);
    __cwcn_type_t nat_sigmoid_inverse(__cwcn_type_t _input);
    __cwcn_type_t nat_sigmoid_inverse_derivate(__cwcn_type_t _input);
    __cwcn_type_t linear_direct(__cwcn_type_t _input);
    __cwcn_type_t linear_direct_derivate(__cwcn_type_t _input);
    __cwcn_type_t linear_inverse(__cwcn_type_t _input);
    __cwcn_type_t linear_inverse_derivate(__cwcn_type_t _input);
    void tsinuu_inverse_propagate(__tsinuu_t * _tsinuu, __cwcn_type_t * _output);
    void jkimyei_weight_byinversediff(__tsinuu_t _tsinuu);
    void jkimyei_bias_byinversediff(__tsinuu_t _tsinuu);
    void tsinuu_direct_propagate(__tsinuu_t * _tsinuu, __cwcn_type_t * _input);
    void jkimyei_weight_bydirectdiff(__tsinuu_t _tsinuu);
    void jkimyei_bias_bydirectdiff(__tsinuu_t _tsinuu);
    void cpte_kemu_firstordedgrad(__tsinuu_t _tsinuu, ___cwcn_bool_t cpte_direct, ___cwcn_bool_t cpte_inverse);
    void cpte_kemu_bias(__tsinuu_t _tsinuu);
    void cpte_kemu_maxmin(__tsinuu_t _tsinuu);
    void cpte_kemu_dist(__tsinuu_t _tsinuu);
#endif
#endif