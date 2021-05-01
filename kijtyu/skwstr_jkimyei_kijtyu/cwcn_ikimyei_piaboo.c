#include "wikimyei.config.h"
#include "cwcn_jkimyei_piaabo.h"


__tsinuu_t *uwaabo_fabric(__jkimyei_t *_jkimyei){
    /* config */
    unsigned int uw_total_layers=0x04;
    unsigned int uw_input_size=0x01; // huge thing
    unsigned int uw_output_size=_jkimyei->__uw_count; // #FIXME make it entropyparametrizable
    unsigned int uw_layers_sizes[uw_total_layers] = {uw_input_size,5,5,uw_output_size};
    __list_activations_t uw_activations_iho[uw_total_layers] = {LINEAR, LINEAR, LINEAR, LINEAR};
    __attribute_tsinuu_t *c_attribute_tsinuu = malloc(sizeof(__attribute_tsinuu_t));
    c_attribute_tsinuu->__NUM_TOTAL_LAYERS=TOTAL_LAYERS;
    c_attribute_tsinuu->__layers_sizes=_layers_sizes;
    c_attribute_tsinuu->__layers_activation=_activations_iho;
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
    new_jkimyei->__uwaabo_tsinuu = tsinuu_fabric(c_attribute_tsinuu);
    // tsinuu_initialize_weights_zero(new_jkimyei->__uwaabo_tsinuu);
    // tsinuu_initialize_bias_zero(new_jkimyei->__uwaabo_tsinuu);
    tsinuu_initialize_weights_random(new_jkimyei->__uwaabo_tsinuu, 0.5, -0.5);
    tsinuu_initialize_bias_random(new_jkimyei->__uwaabo_tsinuu, 0.5, -0.5);
    set_all_nodebooleanpardon_parametric(new_jkimyei->__uwaabo_tsinuu, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
    pardon_inputoutput_bias(new_jkimyei->__uwaabo_tsinuu); // #FIXME check if needed of enabled
    set_all_linebooleanpardon_parametric(new_jkimyei->__uwaabo_tsinuu, 0x00, 0x00);
    return new_jkimyei;
}
__tsinuu_t *munaajpi_fabric(__jkimyei_t *_jkimyei){
    /* config */
    unsigned int mjpi_total_layers=0x03;
    unsigned int mjpi_input_size=0x01; // huge thing
    unsigned int mjpi_output_size=0x01; // #FIXME make it entropyparametrizable
    unsigned int mjpi_layers_sizes[mjpi_total_layers] = {mjpi_input_size,3,mjpi_output_size};
    __list_activations_t mjpi_activations_iho[mjpi_total_layers] = {LINEAR, LINEAR, LINEAR, LINEAR};
    __attribute_tsinuu_t *c_attribute_tsinuu = malloc(sizeof(__attribute_tsinuu_t));
    c_attribute_tsinuu->__NUM_TOTAL_LAYERS=TOTAL_LAYERS;
    c_attribute_tsinuu->__layers_sizes=_layers_sizes;
    c_attribute_tsinuu->__layers_activation=_activations_iho;
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
    new_jkimyei->__munaajpi_tsinuu = tsinuu_fabric(c_attribute_tsinuu);
    // tsinuu_initialize_weights_zero(new_jkimyei->__munaajpi_tsinuu);
    // tsinuu_initialize_bias_zero(new_jkimyei->__munaajpi_tsinuu);
    tsinuu_initialize_weights_random(new_jkimyei->__munaajpi_tsinuu, 0.5, -0.5);
    tsinuu_initialize_bias_random(new_jkimyei->__munaajpi_tsinuu, 0.5, -0.5);
    set_all_nodebooleanpardon_parametric(new_jkimyei->__munaajpi_tsinuu, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
    pardon_inputoutput_bias(new_jkimyei->__munaajpi_tsinuu); // #FIXME check if needed of enabled
    set_all_linebooleanpardon_parametric(new_jkimyei->__munaajpi_tsinuu, 0x00, 0x00);
    return new_jkimyei;
}
__jkimyei_t *jkimyei_fabric(
        unsigned int _load_size, // the size of the queue
        unsigned int _jk_size, // the size of the jkimyei batch
        unsigned int _uw_size, // the size of the jkimyei batch
        unsigned int _num_states,
        unsigned int _num_actions,
        unsigned int _num_returns){ // #FIXME assertme arr[i*M+j] yilds arr[j][j]
    new_jkimyei=malloc(sizeof(__jkimyei_t));
    new_jkimyei->__load_size=_load_size;
    new_jkimyei->__load_count=0x00;
    new_jkimyei->__jk_size=_jk_size;
    new_jkimyei->__jk_count=0x00;
    new_jkimyei->__uw_count=_uw_size; // #FIXME what?
    new_jkimyei->__num_states=_num_states;
    new_jkimyei->__num_actions=_num_actions;
    new_jkimyei->__num_returns=_num_returns;
    printf("\n------->------\n");
    // Configure tsinuu
    set_seed();
    new_jkimyei->__uwaabo_tsinuu=uwaabo_fabric(new_jkimyei);
    set_seed();
    new_jkimyei->__munaajpi_tsinuu=munaajpi_fabric(new_jkimyei);
    // def queue
    new_jkimyei->__load_batch=malloc(sizeof(__queue_inmortal_t));
    new_jkimyei->__jk_batch=malloc(sizeof(__jk_queue_t));
    return new_jkimyei;
}




/*
    QUEUE
*/
void jk_enqueue_trayectory(__jkimyei_t *_jkimyei, __trayectory_t *_new_trayectory){
    printf(">> jk_enqueue_trayectory\n");
    if(__jk_batch_head == NULL){
        fprintf(stderr, ">>>> ERROR: jk_enqueue_trayectory head pointer is NULL\n");
        assert(0x00);
    }
    __jk_queue_t *new_node = malloc(sizeof(__jk_queue_t));
    if(!new_node){
        fprintf(stderr, ">>>> ERROR: jk_enqueue_trayectory failed to enqueue\n");
        assert(0x00);
    }
    new_node->__trayectory = _new_trayectory;
    new_node->__next = *_jkimyei->__jk_batch_head;
    *__jk_batch_head = new_node;
}

__trayectory_t *jk_dequeue_trayectory(__jkimyei_t *_jkimyei){
    printf(">> jk_dequeue_trayectory\n");
    __jk_queue_t *current, *prev = NULL;
    __trayectory_t retval = -0x01;
    if(*__jk_batch_head == NULL){return -0x01;}
    current = *__jk_batch_head;
    while(current->__next != NULL){
        prev = current;
        current = current->__next;
    }
    retval = current->__trayectory;
    free(current);
    if(prev){
        prev->__next = NULL;
    }else{
        *__jk_batch_head = NULL;
    }
    return retval;
}

void jk_print_trayectory_queue(__jkimyei_t *_jkimyei){
    printf(">> jk_print_trayectory_queue\n");
    __jk_queue_t *_current = __jk_batch_head;
    while(_current != NULL){
        printf("FIRST_STATE: %9.2f\n", _current->__trayectory->states[0]);
        _current = _current->__next;
    }
}

/*
    INMORTAL QUEUE
*/
void load_queue_go_up(__jkimyei_t *_jkimyei){
    if(_jkimyei->__load_batch->__up==NULL){return -0x01;}
    _jkimyei->__load_count+=0x01;
    _jkimyei->__load_batch=_jkimyei->__load_batch->__up;
}
void load_queue_go_down(__jkimyei_t *_jkimyei){
    if(_jkimyei->__load_batch->__down==NULL){return -0x01;}
    _jkimyei->__load_count+=-0x01;
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
    _jkimyei->_load_count+=0x01;
    _jkimyei->_load_total+=0x01;
}

// __trayectory_t *retrival_down_load_trayectory(__jkimyei_t *_jkimyei){
//     printf(">> request retrival_down_load_trayectory\n");
//     __trayectory_t retval=malloc();
//     if(*_jkimyei->__load_batch == NULL){return -0x01;}
//     if(_jkimyei->__load_batch->__down == NULL){return -0x01;}
//     retval=_jkimyei->__load_batch->__trayectory;
//     _jkimyei->__load_batch=_jkimyei->__load_batch->__down;
//     _jkimyei->_load_count+=-0x01;
//     if(retval==NULL){return -0x01;}
//     return retval;
// }// #FIXME makes no sence to malloc a new variable for it, better not.
// __trayectory_t *retrival_up_load_trayectory(__jkimyei_t *_jkimyei){
//     printf(">> request retrival_up_load_trayectory\n");
//     __trayectory_t retval=malloc();
//     if(*_jkimyei->__load_batch == NULL){return -0x01;} // #FIXME what ¿*?
//     if(_jkimyei->__load_batch->__up == NULL){return -0x01;}
//     retval=_jkimyei->__load_batch->__trayectory;
//     _jkimyei->__load_batch=_jkimyei->__load_batch->__up;
//     if(retval==NULL){return -0x01;}
//     _jkimyei->_load_count+=0x01;
//     return retval;
// }// #FIXME makes no sence to malloc a new variable for it, better not.

void load_print_down_trayectory_queue(__jkimyei_t *_jkimyei){
    printf(">> load_print_down_trayectory_queue\n");
    __queue_load_t *_current = _head_t;
    while(_current != NULL){
        printf("FIRST_STATE: %9.2f\n", _current->__trayectory->states[0]);
        _current = _current->__down;
    }
}

__queue_load_t **load_trayecotry_from_queue_load(__jkimyei_t *_jkimyei, unsigned int _size){
    __queue_load_t **_load=malloc(_size*sizeof(__queue_load_t));
    for(unsigned int idx=0x00;idx<_size;idx++){
        _load[idx]=dequeue_load_trayectory(_head_t);
    }
    return _load;
}

void kill_load(__jkimyei_t *_jkimyei){
    while(load_queue_go_up(__jkimyei_t *_jkimyei)!=-1);
    while(load_queue_go_down(__jkimyei_t *_jkimyei)!=-1){
        free(_jkimyei->__load_batch_head->__up);
    }
    free(_jkimyei->__load_batch_head);
}