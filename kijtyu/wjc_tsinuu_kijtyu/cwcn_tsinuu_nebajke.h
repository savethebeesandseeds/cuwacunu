
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "cwcn_tsinuu_piaabo.h"
#ifndef NAT_TYPE
#define NAT_TYPE
#endif
#ifndef SYMETRIC_TSINUU
#define SYMETRIC_TSINUU // #FIXME, not in use, but true. (fix both)
#endif
#ifndef TSINUU_NEBAJKE_INCLUDED
#define TSINUU_NEBAJKE_INCLUDED
#ifdef NAT_TYPE
    __cwcn_type_t nat_sigmoid_direct(__cwcn_type_t _input);
    __cwcn_type_t nat_sigmoid_direct_derivate(__cwcn_type_t _input);
    __cwcn_type_t nat_sigmoid_direct_derivate_fast(__cwcn_type_t _output);
    __cwcn_type_t nat_sigmoid_inverse(__cwcn_type_t _input);
    __cwcn_type_t nat_sigmoid_inverse_derivate(__cwcn_type_t _input);
    __cwcn_type_t linear_direct(__cwcn_type_t _input);
    __cwcn_type_t linear_direct_derivate(__cwcn_type_t _input);
    __cwcn_type_t linear_inverse(__cwcn_type_t _input);
    __cwcn_type_t linear_inverse_derivate(__cwcn_type_t _input);

    void dist_node_from_coord(__tsinuu_t *_tsinuu, __node_coords_t *_n_coord, __cwcn_type_t _value);
    void dist_node_form_kemu(__tsinuu_t *_tsinuu, __node_kemu_t *_n_kemu, __cwcn_type_t _value);

    void tsinuu_inverse_propagate_full_parametric(__tsinuu_t *_tsinuu);
    void tsinuu_direct_propagate_full_parametric(__tsinuu_t *_tsinuu);
    void tsinuu_direct_propagate_fast(__tsinuu_t *_tsinuu);
    
    void jkimyei_byinverseNABLA(__tsinuu_t *_tsinuu);
    void jkimyei_bydirectNABLA(__tsinuu_t *_tsinuu, __cwcn_type_t *_output_wapaajco);
    
   __cwcn_type_t *wapaajco_bydifference(__tsinuu_t *_tsinuu, __cwcn_type_t *_correct_output);
   __cwcn_type_t *wapaajco_bynodeentropymax(__tsinuu_t *_tsinuu); // #FIXME inplement
    void set_seed();
#endif
#endif