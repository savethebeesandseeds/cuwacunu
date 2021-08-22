#include "cwcn_uwaabo_piaabo.h"
__uwaabo_t *uwaabo_fabric(unsigned int _uwaabo_base_w_size, unsigned int _uwaabo_state_size, __cwcn_type_t _uwaabo_waapajco_potency){
    // #FIXME add assertions
    __uwaabo_t *new_uwaabo = malloc(sizeof(__uwaabo_t));
    new_uwaabo->__uwaabo_base_w_size=_uwaabo_base_w_size;
    new_uwaabo->__uwaabo_state_size=_uwaabo_state_size;
    new_uwaabo->__uwaabo_w_base=malloc(_uwaabo_base_w_size*sizeof(__cwcn_type_t));
    for(unsigned int idx=0x00;idx<_uwaabo_base_w_size;idx++){new_uwaabo->__uwaabo_w_base[idx]=0x00;}
    /*
        ('ujcamei'->'cajtucu') TSINUU FABRIC
    */
    unsigned int uw_total_layers=0x08;
    unsigned int uw_layers_sizes[0x08] = {_uwaabo_base_w_size,32,32,32,32,32,32,_uwaabo_state_size};
    #ifndef DEBUG_LINEAR_EXPERIMENT
    __list_activations_t uw_activations_iho[0x08] = {\
                            LINEAR,\
                            SIGNEDSIGMOID,\
                            SIGNEDSIGMOID,\
                            SIGNEDSIGMOID,\
                            SIGNEDSIGMOID,\
                            SIGNEDSIGMOID,\
                            SIGNEDSIGMOID,\
                            SIGMOID}; // must be sigmoid
    #else
    __list_activations_t uw_activations_iho[0x05] = {LINEAR, LINEAR, LINEAR, LINEAR, SIGMOID};
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
    c_attribute_tsinuu->__weight_limits->__max=__MAX_TSINUU_HIPERPARAMETER__;
    c_attribute_tsinuu->__weight_limits->__min=-__MAX_TSINUU_HIPERPARAMETER__;
    c_attribute_tsinuu->__bias_limits=malloc(sizeof(__limits_t));
    c_attribute_tsinuu->__bias_limits->__max=__MAX_TSINUU_HIPERPARAMETER__;
    c_attribute_tsinuu->__bias_limits->__min=-__MAX_TSINUU_HIPERPARAMETER__;
    /* fabric */
    new_uwaabo->__uwaabo_tsinuu=tsinuu_fabric(c_attribute_tsinuu);
    new_uwaabo->__uwaabo_tsinuu->__attributes->__wapaajco_potency=_uwaabo_waapajco_potency;
    #ifndef DEBUG_LINEAR_EXPERIMENT
    tsinuu_initialize_weights_random(new_uwaabo->__uwaabo_tsinuu, 0.5, -0.5);
    tsinuu_initialize_bias_random(new_uwaabo->__uwaabo_tsinuu, 0.5, -0.5);
    #else
    tsinuu_initialize_weights_fixed(new_uwaabo->__uwaabo_tsinuu,1.0);
    tsinuu_initialize_bias_fixed(new_uwaabo->__uwaabo_tsinuu,1.0);
    #endif
    // printf("waka\n");
    tsinuu_initialize_bias_zero(new_uwaabo->__uwaabo_tsinuu);
    // tsinuu_initialize_weights_zero(new_uwaabo->__uwaabo_tsinuu);
    // printf("waka\n");
    set_all_nodebooleanpardon_parametric(new_uwaabo->__uwaabo_tsinuu, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00); // #FIXME pardon to make it faster
    pardon_inputoutput_bias(new_uwaabo->__uwaabo_tsinuu); // #FIXME check if needed of enabled
    set_all_linebooleanpardon_parametric(new_uwaabo->__uwaabo_tsinuu, 0x00, 0x00);
    return new_uwaabo;
}
void read_uwaabo_w_base(__wikimyei_t *_wikimyei){
    unsigned int m_ctx=0x00;
    #if defined(__IN_UWAABO_W_BASE_ALLIU_DUURUVA_IS_INCLUDED__)
    #if defined(__EXPEND_ALLIU_DUURUVA__) && defined(__PROPAGATE_ALLIU_DUURUVA__)
    for(unsigned int idx=0x00;idx<_wikimyei->__wajyu->__metric->__alliu_duuruva->__duuruva_vector_size;idx++){
        _wikimyei->__uwaabo->__uwaabo_w_base[m_ctx]=glti(_wikimyei)->__alliu_duuruva_state[idx];
        m_ctx++;
    }
    #else
    fprintf(stderr,"BAD configuration __IN_UWAABO_W_BASE_ALLIU_DUURUVA_IS_INCLUDED__ requires : [__EXPEND_ALLIU_DUURUVA__ && __PROPAGATE_ALLIU_DUURUVA__]");
    assert(0x00);
    #endif
    #endif
    #if defined(__IN_UWAABO_W_BASE_ALLIU_IS_INCLUDED__)
    for(unsigned int idx=0x00;idx<_wikimyei->__alliu->__source_size;idx++){
        _wikimyei->__uwaabo->__uwaabo_w_base[m_ctx]=glti(_wikimyei)->__alliu_state[idx];
        m_ctx++;
    }
    #endif
    assert(_wikimyei->__uwaabo->__uwaabo_base_w_size==m_ctx); // might rise due to a bad #define configuration 
}

void uwaabo_destroy(__uwaabo_t *_uwaabo){
    free(_uwaabo->__uwaabo_w_base);
    tsinuu_destroy(_uwaabo->__uwaabo_tsinuu);
    
}