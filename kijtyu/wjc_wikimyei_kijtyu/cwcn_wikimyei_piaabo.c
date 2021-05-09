#include "cwcn_wikimyei_piaabo.h"

__trayectory_t *trayectory_fabric(__wikimyei_t *_wikimyei){
    __trayectory_t *new_trayectory=malloc(sizeof(__trayectory_t));
    new_trayectory->__uwaabo_base=malloc(_wikimyei->__uwaabo_base_size*sizeof(__cwcn_type_t));
    new_trayectory->__uwaabo_state=malloc(_wikimyei->__uwaabo_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__tsane_state=malloc(_wikimyei->__tsane_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__munaajpi_base=malloc(_wikimyei->__munaajpi_base_size*sizeof(__cwcn_type_t));
    new_trayectory->__munaajpi_state=malloc(_wikimyei->__munaajpi_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__tsane_log_prob=malloc(_wikimyei->__tsane_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__uwaabo_adventage=malloc(_wikimyei->__uwaabo_state_size*sizeof(__cwcn_type_t));
    for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo_base_size;idx++){new_trayectory->__uwaabo_base[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo_state_size;idx++){new_trayectory->__uwaabo_state[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__tsane_state_size;idx++){new_trayectory->__tsane_state[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__munaajpi_base_size;idx++){new_trayectory->__munaajpi_base[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__munaajpi_state_size;idx++){new_trayectory->__munaajpi_state[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__tsane_state_size;idx++){new_trayectory->__tsane_log_prob[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo_state_size;idx++){new_trayectory->__uwaabo_adventage[idx]=0x00;}
    return new_trayectory;
}
__load_queue_t *load_fabric(__wikimyei_t *_wikimyei){
    __load_queue_t *new_load=malloc(sizeof(__load_queue_t));    
    new_load->__trayectory_item=trayectory_fabric(_wikimyei);
    return new_load;
}
__wikimyei_states_t *wikimyei_states_fabric(__wikimyei_t *_wikimyei){
    __wikimyei_states_t *new_states=malloc(sizeof(__wikimyei_states_t));
    new_states->__alliu_state=malloc(_wikimyei->__alliu_state_size*sizeof(__cwcn_type_t));
    new_states->__duuruva_state=malloc(_wikimyei->__uwaabo_base_size*sizeof(__cwcn_type_t));
    new_states->__uwaabo_state=malloc(_wikimyei->__uwaabo_state_size*sizeof(__cwcn_type_t));
    new_states->__munaajpi_state=malloc(_wikimyei->__munaajpi_base_size*sizeof(__cwcn_type_t));
    new_states->__tsane_state=malloc(_wikimyei->__tsane_state_size*sizeof(__cwcn_type_t));
    for(unsigned int idx=0x00;idx<_wikimyei->__alliu_state_size;idx++){new_states->__alliu_state[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo_base_size;idx++){new_states->__duuruva_state[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo_state_size;idx++){new_states->__uwaabo_state[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__munaajpi_base_size;idx++){new_states->__munaajpi_state[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__tsane_state_size;idx++){new_states->__tsane_state[idx]=0x00;}
    return new_states;
}
__wikimyei_t *wikimyei_fabric(
        int _jk_size,
        __alliu_source_t _alliu_source,
        unsigned int _alliu_size,
        unsigned int _tsane_size,
        unsigned int _direct_resolution){
    __wikimyei_t *new_wikimyei=malloc(sizeof(__wikimyei_t));

    new_wikimyei->__load_index=-1;
    new_wikimyei->__load_size=0x00;
    new_wikimyei->__alliu_state_size=_alliu_size;
    new_wikimyei->__tsane_state_size=_tsane_size;
    new_wikimyei->__direct_resolution=_direct_resolution;

    set_seed();
    
    new_wikimyei->__jkimyei=jkimyei_fabric(_jk_size);
    new_wikimyei->__alliu=alliu_fabric(_alliu_source, _alliu_size);
    new_wikimyei->__duuruva=duuruva_fabric(_alliu_size);
    new_wikimyei->__tsane=tsane_fabric(___CWCN_FALSE, _tsane_size);
	new_wikimyei->__ec=entropycosa_fabric(_direct_resolution, _tsane_size);
    
    new_wikimyei->__uwaabo_base_size=new_wikimyei->__duuruva->__duuruva_vector_size;
    new_wikimyei->__uwaabo_state_size=new_wikimyei->__ec->__total_cosa_params;
    new_wikimyei->__munaajpi_base_size=new_wikimyei->__tsane_state_size+new_wikimyei->__uwaabo_state_size+new_wikimyei->__alliu_state_size;
    new_wikimyei->__munaajpi_state_size=new_wikimyei->__uwaabo_state_size;
    
    new_wikimyei->__uwaabo=uwaabo_fabric(new_wikimyei->__uwaabo_base_size, new_wikimyei->__uwaabo_state_size);
    new_wikimyei->__munaajpi=munaajpi_fabric(new_wikimyei->__munaajpi_base_size, new_wikimyei->__munaajpi_state_size);
    
    new_wikimyei->__load_batch_head=load_fabric(new_wikimyei);
    new_wikimyei->__wk_states=wikimyei_states_fabric(new_wikimyei);

    return new_wikimyei;
}


/*
    INMORTAL QUEUE
*/
int load_go_up(__wikimyei_t *_wikimyei){
    if(_wikimyei->__load_batch_head->__up==NULL){return -0x01;}
    _wikimyei->__load_index+=0x01;
    _wikimyei->__load_batch_head=_wikimyei->__load_batch_head->__up;
    return 0x00;
}
int load_go_down(__wikimyei_t *_wikimyei){
    if(_wikimyei->__load_batch_head->__down==NULL){return -0x01;}
    __load_queue_t *c_head=_wikimyei->__load_batch_head;
    _wikimyei->__load_index+=-0x01;
    _wikimyei->__load_batch_head=_wikimyei->__load_batch_head->__down;
    _wikimyei->__load_batch_head->__up=c_head;
    return 0x00;
}
int load_enqueue_trayectory(__wikimyei_t *_wikimyei, __trayectory_t *_new_trayectory){
    printf(">> load_enqueue_trayectory\n");
    __load_queue_t *new_head=malloc(sizeof(__load_queue_t));
    if(!new_head){
        fprintf(stderr, ">>>> ERROR: load_enqueue_trayectory failed to alocate more memory.\n");
        assert(0x00);
    }
    while(load_go_up(_wikimyei)!=-1){}
    new_head->__trayectory_item=_new_trayectory;
    new_head->__down=_wikimyei->__load_batch_head; // #FIXME what ¿*?
    new_head->__up=NULL;
    _wikimyei->__load_batch_head=new_head; // #FIXME what ¿*?
    _wikimyei->__load_index+=0x01;
    _wikimyei->__load_size+=0x01;
    return 0x00;
}
__trayectory_t *get_load_trayectory_item(__wikimyei_t *_wikimyei){
    return _wikimyei->__load_batch_head->__trayectory_item;
}
__trayectory_t *get_load_trayectory_item_from_index(__wikimyei_t *_wikimyei, int _index, ___cwcn_bool_t _rneturn){
    // _rneturn marks the flag to allow load_head displacement to index  
    // fprintf(stdout,"__load_index<_index && __load_index<__load_size \t %d < %d  &&  %d < %d\n",_wikimyei->__load_index,_index, _wikimyei->__load_index,_wikimyei->__load_size);
    // fprintf(stdout,"__load_index>_index && __load_index<__load_size \t %d > %d  &&  %d < %d\n",_wikimyei->__load_index,_index, _wikimyei->__load_index,_wikimyei->__load_size);
    __trayectory_t *rnetrival;
    int start_index=_wikimyei->__load_index;
    while(_wikimyei->__load_index<_index && _wikimyei->__load_index<_wikimyei->__load_size-0x01){load_go_up(_wikimyei);}
    while(_wikimyei->__load_index>_index && _wikimyei->__load_index<_wikimyei->__load_size-0x01){load_go_down(_wikimyei);}
    rnetrival=_wikimyei->__load_batch_head->__trayectory_item;
    if(!_rneturn){
        while(_wikimyei->__load_index<start_index && _wikimyei->__load_index<_wikimyei->__load_size-0x01){load_go_up(_wikimyei);}
        while(_wikimyei->__load_index>start_index && _wikimyei->__load_index<_wikimyei->__load_size-0x01){load_go_down(_wikimyei);}
    }
    return rnetrival;
}
void load_print_up_trayectory_queue(__wikimyei_t *_wikimyei){
    fprintf(stdout,">> load_print_up_trayectory_queue\n");
    __load_queue_t *_current=_wikimyei->__load_batch_head;
    while(_current != NULL){
        fprintf(stdout,"FIRST_STATE: %9.2f\n", _current->__trayectory_item->__uwaabo_base[0x00]);
        _current=_current->__up;
    }
}
void load_print_down_trayectory_queue(__wikimyei_t *_wikimyei){
    printf(">> load_print_down_trayectory_queue\n");
    __load_queue_t *_current=_wikimyei->__load_batch_head;
    while(_current != NULL){
        printf("FIRST_STATE: %9.2f\n", _current->__trayectory_item->__uwaabo_base[0x00]);
        _current=_current->__down;
    }
}

/*
*/
void kill_trayectory(__trayectory_t *_trayectory){
    free(_trayectory->__uwaabo_base);
    free(_trayectory->__uwaabo_state);
    free(_trayectory->__tsane_state);
    free(_trayectory->__tsane_log_prob);
    free(_trayectory->__munaajpi_base);
    free(_trayectory->__munaajpi_state);
    free(_trayectory->__uwaabo_adventage);
    free(_trayectory);
}
void kill_load(__wikimyei_t *_wikimyei){
    while(load_go_up(_wikimyei)!=-1){}
    while(load_go_down(_wikimyei)!=-1){
        kill_trayectory(_wikimyei->__load_batch_head->__up->__trayectory_item);
        free(_wikimyei->__load_batch_head->__up);
    }
    free(_wikimyei->__load_batch_head);
}
void kill_wikimyei_states(__wikimyei_states_t *_wk_states){
    free(_wk_states->__alliu_state);
    free(_wk_states->__duuruva_state);
    free(_wk_states->__uwaabo_state);
    free(_wk_states->__munaajpi_state);
    free(_wk_states->__tsane_state);
    free(_wk_states);
}
/*
*/
void destroy_wikimyei(__wikimyei_t *_wikimyei){
    jkimyei_destroy(_wikimyei->__jkimyei);
    alliu_destroy(_wikimyei->__alliu);
    duuruva_destroy(_wikimyei->__duuruva);
    tsane_destroy(_wikimyei->__tsane);
    entropycosa_destroy(_wikimyei->__ec);
    tsinuu_destroy(_wikimyei->__uwaabo);
    tsinuu_destroy(_wikimyei->__munaajpi);
    kill_wikimyei_states(_wikimyei->__wk_states);
    kill_load(_wikimyei);
    free(_wikimyei);
}
/*

*/
