#include "cwcn_uwaabo_piaabo.h"
__uwaabo_t *uwaabo_fabric(unsigned int _uwaabo_base_size, unsigned int _uwaabo_size){
    // #FIXME add assertions
    __uwaabo_t *new_uwaabo = malloc(sizeof(__uwaabo_t));
    /*
        ('cajtucu') DUURUVA FABRIC
    */
    new_uwaabo->__uwaabo_duuruva=duuruva_fabric(unsigned int _num_base_duuruva); // uwaabo 'cajtucu'
    new_uwaabo->__uwaabo_loss_duuruva=duuruva_fabric(unsigned int _num_base_duuruva); // uwaabo 'cajtucu' loss

    /*
        ('ujcamei'->'cajtucu') TSINUU FABRIC
    */
    unsigned int uw_total_layers=0x05;
    unsigned int uw_input_size=_uwaabo_base_size; // huge thing
    unsigned int uw_output_size=_uwaabo_size;
    unsigned int uw_layers_sizes[0x05] = {uw_input_size,0x05,0x0a,0x05,uw_output_size};
    #ifndef DEBUG_LINEAR_EXPERIMENT
    __list_activations_t uw_activations_iho[0x05] = {\
                            LINEAR,\
                            SIGMOID,\
                            SIGMOID,\
                            SIGMOID,\
                            SIGMOID};
    #else
    __list_activations_t uw_activations_iho[0x05] = {LINEAR, LINEAR, SIGMOID};
    #endif
    __attribute_tsinuu_t *c_attribute_tsinuu = malloc(sizeof(__attribute_tsinuu_t));
    c_attribute_tsinuu->__NUM_TOTAL_LAYERS=uw_total_layers;
    // c_attribute_tsinuu->__layers_sizes=uw_layers_sizes;
    // c_attribute_tsinuu->__layers_activation=uw_activations_iho;
    c_attribute_tsinuu->__layers_sizes=malloc(uw_total_layers*sizeof(unsigned int));
    c_attribute_tsinuu->__layers_activation=malloc(uw_total_layers*sizeof(__list_activations_t));
    for(unsigned int idx=0x00;idx<uw_total_layers;idx++){
        c_attribute_tsinuu->__layers_sizes[idx]=uw_layers_sizes[idx];
        c_attribute_tsinuu->__layers_activation[idx]=uw_activations_iho[idx];
    }
    c_attribute_tsinuu->__is_symetric=___CWCN_TRUE; // meaning fully conected normal Network
    c_attribute_tsinuu->__alpha=0.0; // alpha assert negative, is a mesure for resisting change; is if you kguht the friction of the learning; required to create new tsinuu
    c_attribute_tsinuu->__eta=1.0; // eta is the error impulse, required to create new tsinuu
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
    new_uwaabo->__uwaabo_tsinuu=tsinuu_fabric(c_attribute_tsinuu);

    // tsinuu_initialize_weights_zero(new_uwaabo_tsinuu);
    // tsinuu_initialize_bias_zero(new_uwaabo_tsinuu);
    #ifndef DEBUG_LINEAR_EXPERIMENT
    tsinuu_initialize_weights_random(new_uwaabo_tsinuu, 0.5, -0.5);
    tsinuu_initialize_bias_random(new_uwaabo_tsinuu, 0.5, -0.5);
    #else
    tsinuu_initialize_weights_fixed(new_uwaabo_tsinuu,1.0);
    tsinuu_initialize_bias_fixed(new_uwaabo_tsinuu,1.0);
    #endif
    set_all_nodebooleanpardon_parametric(new_uwaabo_tsinuu, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00); // #FIXME pardon to make it faster
    pardon_inputoutput_bias(new_uwaabo_tsinuu); // #FIXME check if needed of enabled
    set_all_linebooleanpardon_parametric(new_uwaabo_tsinuu, 0x00, 0x00);
    return new_uwaabo_tsinuu;
}