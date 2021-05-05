#include "cwcn_wikimyei_piaabo.h"

__tsinuu_t *uwaabo_fabric(__jkimyei_t *_wikimyei){
    /* config */
    unsigned int uw_total_layers=0x04;
    unsigned int uw_input_size=_wikimyei->__uwaabo_base_size; // huge thing
    unsigned int uw_output_size=_wikimyei->__uwaabo_size; // #FIXME make it entropyparametrizable
    unsigned int uw_layers_sizes[uw_total_layers] = {uw_input_size,5,5,uw_output_size};
    __list_activations_t uw_activations_iho[uw_total_layers] = {LINEAR, LINEAR, LINEAR, LINEAR};
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
    c_attribute_tsinuu->__weight_limits->__max=5.0;
    c_attribute_tsinuu->__weight_limits->__min=-5.0;
    c_attribute_tsinuu->__bias_limits=malloc(sizeof(__limits_t));
    c_attribute_tsinuu->__bias_limits->__max=5.0;
    c_attribute_tsinuu->__bias_limits->__min=-5.0;
    /* fabric */
    new_uwaabo->__uwaabo_tsinuu = tsinuu_fabric(c_attribute_tsinuu);
    // tsinuu_initialize_weights_zero(new_uwaabo->__uwaabo_tsinuu);
    // tsinuu_initialize_bias_zero(new_uwaabo->__uwaabo_tsinuu);
    tsinuu_initialize_weights_random(new_uwaabo->__uwaabo_tsinuu, 0.5, -0.5);
    tsinuu_initialize_bias_random(new_uwaabo->__uwaabo_tsinuu, 0.5, -0.5);
    set_all_nodebooleanpardon_parametric(new_uwaabo->__uwaabo_tsinuu, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
    pardon_inputoutput_bias(new_uwaabo->__uwaabo_tsinuu); // #FIXME check if needed of enabled
    set_all_linebooleanpardon_parametric(new_uwaabo->__uwaabo_tsinuu, 0x00, 0x00);
    return new_uwaabo;
}
__tsinuu_t *munaajpi_fabric(__wikimyei_t *_wikimyei){
    /* config */
    unsigned int mjpi_total_layers=0x03;
    unsigned int mjpi_input_size=_wikimyei->__munaajpi_size; // huge thing
    unsigned int mjpi_output_size=_wikimyei->__munaajpi_base_size;
    unsigned int mjpi_layers_sizes[mjpi_total_layers] = {mjpi_input_size,3,mjpi_output_size};
    __list_activations_t mjpi_activations_iho[mjpi_total_layers] = {LINEAR, LINEAR, LINEAR, LINEAR};
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
    c_attribute_tsinuu->__weight_limits->__max=5.0;
    c_attribute_tsinuu->__weight_limits->__min=-5.0;
    c_attribute_tsinuu->__bias_limits=malloc(sizeof(__limits_t));
    c_attribute_tsinuu->__bias_limits->__max=5.0;
    c_attribute_tsinuu->__bias_limits->__min=-5.0;
    /* fabric */
    new_uwaabo->__munaajpi_tsinuu = tsinuu_fabric(c_attribute_tsinuu);
    // tsinuu_initialize_weights_zero(new_uwaabo->__munaajpi_tsinuu);
    // tsinuu_initialize_bias_zero(new_uwaabo->__munaajpi_tsinuu);
    tsinuu_initialize_weights_random(new_uwaabo->__munaajpi_tsinuu, 0.5, -0.5);
    tsinuu_initialize_bias_random(new_uwaabo->__munaajpi_tsinuu, 0.5, -0.5);
    set_all_nodebooleanpardon_parametric(new_uwaabo->__munaajpi_tsinuu, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
    pardon_inputoutput_bias(new_uwaabo->__munaajpi_tsinuu); // #FIXME check if needed of enabled
    set_all_linebooleanpardon_parametric(new_uwaabo->__munaajpi_tsinuu, 0x00, 0x00);
    return new_uwaabo;
}

__wikimyei_t *wikimyei_fabric(
        unsigned int _load_size,
        unsigned int _jk_size,
        unsigned int _uwaabo_size,
        unsigned int _duuruva_size,
        unsigned int _tsane_size,
        unsigned int _d_res,
        unsigned int _munaajpi_base_size,
        unsigned int _munaajpi_returns_size){
    __wikimyei_t *new_wikimyei=malloc(sizeof(__wikimyei_t));
    new_wikimyei->__load_size=_load_size;
    new_wikimyei->__load_index=0x00;
    

    new_wikimyei->__jkimyei=jkimyei_fabric(
        _jk_size, // the size of the jkimyei batch
        _uwaabo_size, // the size of the uwaabo output
        _duuruva_size,
        _num_tsane,
        _munaajpi_base_size,
        _num_munaajpi_returns);
    
    new_wikimyei->__duuruva_size=_duuruva_size;
    new_wikimyei->__tsane_size=_tsane_size;
    new_wikimyei->__munaajpi_base_size=_munaajpi_base_size;
    new_wikimyei->__munaajpi_returns_size=_munaajpi_returns_size;
    new_wikimyei->__d_res=_d_res;
    printf("\n------->------\n");
    // Configure tsinuu
    set_seed();
    new_wikimyei->__alliu=alliu_fabric(__alliu_source_t _source, unsigned int _source_size);
    set_seed();
    new_wikimyei->__duuruva=duuruva_fabric(new_wikimyei->__duuruva_size);
    set_seed();
    new_wikimyei->__uwaabo_tsinuu=uwaabo_fabric(new_wikimyei);
    set_seed();
    new_wikimyei->__munaajpi_tsinuu=munaajpi_fabric(new_wikimyei);
    set_seed();
	new_wikimyei->__ec=entropycosa_fabric(_d_res, _tsane_size);
    new_wikimyei->__uwaabo_size=new_wikimyei->__ec->__total_cosa_params;
    // def queue
    new_wikimyei->__load_batch=malloc(sizeof(__queue_inmortal_t));
    new_wikimyei->__jk_batch=malloc(sizeof(__jk_queue_t));

    return new_wikimyei;
}
}


/*
    INMORTAL QUEUE
*/
void load_queue_go_up(__jkimyei_t *_jkimyei){
    if(_jkimyei->__load_batch->__up==NULL){return -0x01;}
    _jkimyei->__load_index+=0x01;
    _jkimyei->__load_batch=_jkimyei->__load_batch->__up;
}
void load_queue_go_down(__jkimyei_t *_jkimyei){
    if(_jkimyei->__load_batch->__down==NULL){return -0x01;}
    _jkimyei->__load_index+=-0x01;
    _jkimyei->__load_batch=_jkimyei->__load_batch->__down;
}
void load_enqueue_trayectory(__jkimyei_t *_jkimyei, __trayectory_t *_new_trayectory){
    printf(">> load_enqueue_trayectory\n");
    __queue_inmortal_t *new_node = malloc(sizeof(__queue_inmortal_t));
    if(!new_node){
        fprintf(stderr, ">>>> ERROR: load_enqueue_trayectory failed to alocate more memory.\n");
        assert(0x00);
    }
    new_node->__trayectory = _new_trayectory;
    new_node->__down = *_jkimyei->__load_batch; // #FIXME what ¿*?
    new_node->__up = NULL;
    *_jkimyei->__load_batch = new_node; // #FIXME what ¿*?
    _jkimyei->_load_index+=0x01;
    _jkimyei->_load_total+=0x01;
}
__trayectory_t *load_get_trayectory_item(__jkimyei_t *_jkimyei){
    return _jkimyei->__load_batch_head->__trayectory_item;
}
/*

*/
void kill_load(__jkimyei_t *_jkimyei){
    while(load_queue_go_up(__jkimyei_t *_jkimyei)!=-1);
    while(load_queue_go_down(__jkimyei_t *_jkimyei)!=-1){
        free(_jkimyei->__load_batch_head->__up);
    }
    free(_jkimyei->__load_batch_head);
}
__trayectory_t *trayectory_fabric(
        unsigned int _uwaabo_size,
        unsigned int _uwaabo_base_size,
        unsigned int _tsane_size,
        unsigned int _munaajpi_returns_size,
        unsigned int _munaajpi_base_size){
    __trayectory_t *new_trayectory=malloc(sizeof(__trayectory_t));
    new_trayectory->__uwaabo_base=malloc(_uwaabo_base_size*sizeof(__cwcn_type_t));
    new_trayectory->__uwaabo_returns=malloc(_uwaabo_size*sizeof(__cwcn_type_t));
    new_trayectory->__tsane=malloc(_tsane_size*sizeof(__cwcn_type_t));
    new_trayectory->__munaajpi_base=malloc(_munaajpi_base_size*sizeof(__cwcn_type_t));
    new_trayectory->__munaajpi_returns=malloc(_munaajpi_returns_size*sizeof(__cwcn_type_t));
    new_trayectory->__tsane_log_prob=malloc(_tsane_size*sizeof(__cwcn_type_t));
    new_trayectory->__uwaabo_adventage=malloc(_uwaabo_size*sizeof(__cwcn_type_t));
    return new_trayectory;
}