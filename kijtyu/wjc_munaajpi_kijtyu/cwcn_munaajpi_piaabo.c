#include "cwcn_munaajpi_piaabo.h"
__tsinuu_t *munaajpi_fabric(unsigned int _munaajpi_base_size, unsigned int _munaajpi_returns_size){
    /* config */
    unsigned int mjpi_total_layers=0x03;
    unsigned int mjpi_input_size=_munaajpi_base_size; // huge thing
    unsigned int mjpi_output_size=_munaajpi_returns_size;
    unsigned int mjpi_layers_sizes[0x03] = {mjpi_input_size,3,mjpi_output_size};
    __list_activations_t mjpi_activations_iho[0x03] = {LINEAR, LINEAR, LINEAR};
    __attribute_tsinuu_t *c_attribute_tsinuu = malloc(sizeof(__attribute_tsinuu_t));
    c_attribute_tsinuu->__NUM_TOTAL_LAYERS=mjpi_total_layers;
    c_attribute_tsinuu->__layers_sizes=mjpi_layers_sizes;
    c_attribute_tsinuu->__layers_activation=mjpi_activations_iho;
    c_attribute_tsinuu->__is_symetric=___CWCN_TRUE;
    c_attribute_tsinuu->__alpha=0.0; // alpha assert negative, is a mesure for resisting change; is if you kguht the friction of the learning; required to create new tsinuu
    c_attribute_tsinuu->__eta=1; // eta is the error impulse, required to create new tsinuu
    c_attribute_tsinuu->__omega=0.1; // required to create new tsinuu
    c_attribute_tsinuu->__wapaajco_potency=1.0; // the potency of the wapaajco
    c_attribute_tsinuu->__omega_stiffess=1.0; // #FIXME not in use
    c_attribute_tsinuu->__weight_limits=malloc(sizeof(__limits_t));
    c_attribute_tsinuu->__weight_limits->__max=__cwcn_infinite;
    c_attribute_tsinuu->__weight_limits->__min=-__cwcn_infinite;
    c_attribute_tsinuu->__bias_limits=malloc(sizeof(__limits_t));
    c_attribute_tsinuu->__bias_limits->__max=__cwcn_infinite;
    c_attribute_tsinuu->__bias_limits->__min=-__cwcn_infinite;
    /* fabric */
    __tsinuu_t *new_munaajpi_tsinuu=malloc(sizeof(__tsinuu_t));
    new_munaajpi_tsinuu = tsinuu_fabric(c_attribute_tsinuu);
    // tsinuu_initialize_weights_zero(new_munaajpi_tsinuu);
    // tsinuu_initialize_bias_zero(new_munaajpi_tsinuu);
    tsinuu_initialize_weights_random(new_munaajpi_tsinuu, 0.5, -0.5);
    tsinuu_initialize_bias_random(new_munaajpi_tsinuu, 0.5, -0.5);
    set_all_nodebooleanpardon_parametric(new_munaajpi_tsinuu, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
    pardon_inputoutput_bias(new_munaajpi_tsinuu); // #FIXME check if needed of enabled
    set_all_linebooleanpardon_parametric(new_munaajpi_tsinuu, 0x00, 0x00);
    return new_munaajpi_tsinuu;
}