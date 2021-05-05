#include "wikimyei.config.h"
#include "cwcn_jkimyei_piaabo.h"

__jkimyei_t *jkimyei_fabric(
        unsigned int _jk_size, // the size of the jkimyei batch
        unsigned int _duuruva_size,
        unsigned int _tsane_size,
        unsigned int _d_res,
        unsigned int _munaajpi_base_size, 
        unsigned int _munaajpi_returns_size){ // #FIXME assertme arr[i*M+j] yilds arr[j][j]
    new_jkimyei=malloc(sizeof(__jkimyei_t));
    new_jkimyei->__jk_size=_jk_size;
    new_jkimyei->__jk_count=0x00;
    new_jkimyei->__duuruva_size=_duuruva_size;
    new_jkimyei->__tsane_size=_tsane_size;
    new_jkimyei->__munaajpi_base_size=_munaajpi_base_size;
    new_jkimyei->__munaajpi_returns_size=_munaajpi_returns_size;
    new_jkimyei->__d_res=_d_res;
    printf("\n------->------\n");
    // Configure tsinuu
    set_seed();
    new_jkimyei->__alliu=alliu_fabric(__alliu_source_t _source, unsigned int _source_size);
    set_seed();
    new_jkimyei->__uwaabo_tsinuu=uwaabo_fabric(new_jkimyei);
    set_seed();
    new_jkimyei->__munaajpi_tsinuu=munaajpi_fabric(new_jkimyei);
    set_seed();
	new_jkimyei->__ec=entropycosa_fabric(_d_res, _tsane_size);
    new_jkimyei->__uwaabo_size=new_jkimyei->__ec->__total_cosa_params;
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
    // if(_jkimyei->__jk_batch_head == NULL){
    //     fprintf(stderr, ">>>> ERROR: jk_enqueue_trayectory head pointer is NULL\n");
    //     assert(0x00);
    // }
    __jk_queue_t *new_node = malloc(sizeof(__jk_queue_t));
    if(!new_node){
        fprintf(stderr, ">>>> ERROR: jk_enqueue_trayectory failed to enqueue\n");
        assert(0x00);
    }
    new_node->__trayectory_item = _new_trayectory;
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
__trayectory_t *jk_get_trayectory_item(__jkimyei_t *_jkimyei){
    return _jkimyei->__jk_batch_head->__trayectory_item;
}

// __trayectory_t *retrival_down_load_trayectory(__jkimyei_t *_jkimyei){
//     printf(">> request retrival_down_load_trayectory\n");
//     __trayectory_t retval=malloc();
//     if(*_jkimyei->__load_batch == NULL){return -0x01;}
//     if(_jkimyei->__load_batch->__down == NULL){return -0x01;}
//     retval=_jkimyei->__load_batch->__trayectory;
//     _jkimyei->__load_batch=_jkimyei->__load_batch->__down;
//     _jkimyei->__load_index+=-0x01;
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
//     _jkimyei->__load_index+=0x01;
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

// __queue_load_t **load_trayecotry_from_queue_load(__jkimyei_t *_jkimyei, unsigned int _size){
//     __queue_load_t **_load=malloc(_size*sizeof(__queue_load_t));
//     for(unsigned int idx=0x00;idx<_size;idx++){
//         _load[idx]=dequeue_load_trayectory(_head_t);
//     }
//     return _load;
// }

/*

*/
void kill_jk_queue(__jkimyei_t *_jkimyei){
    __trayectory_t *c_head;
    while(0x1){
        c_head=_jkmyei->__jk_batch_head->__next;
        if(c_head==NULL){break;}
        free(_jkmyei->__jk_batch_head);
        _jkmyei->__jk_batch_head=c_head;
    }
}
void jkimyei_destroy(__jkimyei_t *_jkimyei){
    // #FIXME finish
    tsinuu_destroy(_jkimyei->__uwaabo_tsinuu);
    tsinuu_destroy(_jkimyei->__piaabo_tsinuu);
    entropycosa_destroy(_jkimyei->__ec);
}
/*

*/
