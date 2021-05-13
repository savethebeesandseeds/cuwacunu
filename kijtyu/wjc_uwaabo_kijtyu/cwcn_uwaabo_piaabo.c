#include "cwcn_uwaabo_piaabo.h"
__tsinuu_t *uwaabo_fabric(unsigned int _uwaabo_base_size, unsigned int _uwaabo_size){
    /* config */
    unsigned int uw_total_layers=0x04;
    unsigned int uw_input_size=_uwaabo_base_size; // huge thing
    unsigned int uw_output_size=_uwaabo_size;
    unsigned int uw_layers_sizes[0x04] = {uw_input_size,5,5,uw_output_size};
    __list_activations_t uw_activations_iho[0x04] = {LINEAR, LINEAR, LINEAR, LINEAR};
    __attribute_tsinuu_t *c_attribute_tsinuu = malloc(sizeof(__attribute_tsinuu_t));
    c_attribute_tsinuu->__NUM_TOTAL_LAYERS=uw_total_layers;
    c_attribute_tsinuu->__layers_sizes=uw_layers_sizes;
    c_attribute_tsinuu->__layers_activation=uw_activations_iho;
    c_attribute_tsinuu->__is_symetric=___CWCN_TRUE;
    c_attribute_tsinuu->__alpha=0.0; // alpha assert negative, is a mesure for resisting change; is if you kguht the friction of the learning; required to create new tsinuu
    c_attribute_tsinuu->__eta=1; // eta is the error impulse, required to create new tsinuu
    c_attribute_tsinuu->__omega=0.1; // required to create new tsinuu
    c_attribute_tsinuu->__wapaajco_potency=1.0; // the potency of the wapaajco
    c_attribute_tsinuu->__omega_stiffess=1.0; // #FIXME not in use
    c_attribute_tsinuu->__weight_limits=malloc(sizeof(__limits_t));
    c_attribute_tsinuu->__weight_limits->__max=__cwcn_infinite_t;
    c_attribute_tsinuu->__weight_limits->__min=-__cwcn_infinite_t;
    c_attribute_tsinuu->__bias_limits=malloc(sizeof(__limits_t));
    c_attribute_tsinuu->__bias_limits->__max=__cwcn_infinite_t;
    c_attribute_tsinuu->__bias_limits->__min=-__cwcn_infinite_t;
    /* fabric */
    __tsinuu_t *new_uwaabo_tsinuu=malloc(sizeof(__tsinuu_t));
    new_uwaabo_tsinuu=tsinuu_fabric(c_attribute_tsinuu);
    // tsinuu_initialize_weights_zero(new_uwaabo_tsinuu);
    // tsinuu_initialize_bias_zero(new_uwaabo_tsinuu);
    tsinuu_initialize_weights_random(new_uwaabo_tsinuu, 0.5, -0.5);
    tsinuu_initialize_bias_random(new_uwaabo_tsinuu, 0.5, -0.5);
    set_all_nodebooleanpardon_parametric(new_uwaabo_tsinuu, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
    pardon_inputoutput_bias(new_uwaabo_tsinuu); // #FIXME check if needed of enabled
    set_all_linebooleanpardon_parametric(new_uwaabo_tsinuu, 0x00, 0x00);
    return new_uwaabo_tsinuu;
}