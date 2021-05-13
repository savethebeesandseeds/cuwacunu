#ifndef TSINUU_NEBAJKE_INCLUDED
#define TSINUU_NEBAJKE_INCLUDED
#include "cwcn_tsinuu_piaabo.h"
#define NAT_TYPE
#define SYMETRIC_TSINUU // #FIXME, not in use, but true. (fix both)

#ifdef NAT_TYPE
// #FIXME make a function pointer list of all actions.
    __cwcn_type_t nat_sigmoid_direct(__cwcn_type_t _input);
    __cwcn_type_t nat_sigmoid_direct_derivate(__cwcn_type_t _input);
    __cwcn_type_t nat_sigmoid_direct_derivate_fast(__cwcn_type_t _output);
    __cwcn_type_t nat_sigmoid_inverse(__cwcn_type_t _input);
    __cwcn_type_t nat_sigmoid_inverse_derivate(__cwcn_type_t _input);
    
    __cwcn_type_t nat_signedsigmoid_direct(__cwcn_type_t _input);
    __cwcn_type_t nat_signedsigmoid_direct_derivate(__cwcn_type_t _input); // #FIXME make it fast.
    __cwcn_type_t nat_signedsigmoid_inverse(__cwcn_type_t _input);
    __cwcn_type_t nat_signedsigmoid_inverse_derivate(__cwcn_type_t _input);

    __cwcn_type_t linear_direct(__cwcn_type_t _input);
    __cwcn_type_t linear_direct_derivate(__cwcn_type_t _input);
    __cwcn_type_t linear_inverse(__cwcn_type_t _input);
    __cwcn_type_t linear_inverse_derivate(__cwcn_type_t _input);

    __cwcn_type_t relu_direct(__cwcn_type_t _input);
    __cwcn_type_t relu_direct_derivate(__cwcn_type_t _input);
    __cwcn_type_t relu_inverse(__cwcn_type_t _input);
    __cwcn_type_t relu_inverse_derivate(__cwcn_type_t _input);

    __cwcn_type_t softplus_direct(__cwcn_type_t _input);
    __cwcn_type_t softplus_direct_derivate(__cwcn_type_t _input);
    __cwcn_type_t softplus_inverse(__cwcn_type_t _input);
    __cwcn_type_t softplus_inverse_derivate(__cwcn_type_t _input);

    // void dist_node_from_coord(__tsinuu_t *_tsinuu, __node_coords_t *_n_coord, __cwcn_type_t _value);
    // void dist_node_form_kemu(__tsinuu_t *_tsinuu, __node_kemu_t *_n_kemu, __cwcn_type_t _value);
    void dist_node(__tsinuu_t *_tsinuu, __node_tsinuu_t *_node);

    void tsinuu_inverse_uwaabo_full_parametric(__tsinuu_t *_tsinuu);
    void tsinuu_direct_uwaabo_full_parametric(__tsinuu_t *_tsinuu);
    void tsinuu_direct_uwaabo_fast(__tsinuu_t *_tsinuu);
    
    void jkimyei_tsinuu_byinverseNABLA(__tsinuu_t *_tsinuu);
    void jkimyei_tsinuu_bydirectNABLA(__tsinuu_t *_tsinuu);
    
    void wapaajco_bydifference(__tsinuu_t *_tsinuu, __cwcn_type_t *_correct_output);
    void set_wapaajco(__tsinuu_t *_tsinuu, __cwcn_type_t *_set_wapaajco);
    void set_wapaajco_eq(__tsinuu_t *_tsinuu, __cwcn_type_t _set_wapaajco);
    void set_wapaajco_index_eq(__tsinuu_t *_tsinuu, __cwcn_type_t _set_wapaajco, unsigned int _index);
    void wapaajco_bynodeentropymax(__tsinuu_t *_tsinuu); // #FIXME inplement
    void set_seed();

#endif
#endif