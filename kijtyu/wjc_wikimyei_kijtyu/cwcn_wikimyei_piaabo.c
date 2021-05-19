#include "cwcn_wikimyei_piaabo.h"

__trayectory_t *trayectory_fabric(__wikimyei_t *_wikimyei){
    __trayectory_t *new_trayectory=malloc(sizeof(__trayectory_t));
    if(!new_trayectory){
        fprintf(stderr,"ERROR, unable to allocate memory for new trayectory\n");
    }
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > ... trayectory_fabric\n");
    #endif
    new_trayectory->__pending_munaajpi_index=0x00;
    new_trayectory->__pending_munaajpi=___CWCN_TRUE;
    new_trayectory->__alliu_state=malloc(_wikimyei->__alliu_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__nonuwaabo_alliu_state=malloc(_wikimyei->__alliu_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__alliu_duuruva_state=malloc(_wikimyei->__alliu_duuruva_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__uwaabo_state=malloc(_wikimyei->__uwaabo_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__uwaabo_returns=malloc(_wikimyei->__uwaabo_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__uwaabo_adventage=malloc(_wikimyei->__uwaabo_state_size*sizeof(__cwcn_type_t));
    printf("wakaaa din!!!\n");
    new_trayectory->__tsane_state=malloc(_wikimyei->__tsane_state_size*sizeof(__cwcn_type_t));
    printf("wakaaa dao!!!\n");
    new_trayectory->__munaajpi_state=malloc(_wikimyei->__munaajpi_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__uwaabo_adventage=malloc(_wikimyei->__uwaabo_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__imibajcho_munaajpi_state=malloc(0x01*sizeof(__cwcn_type_t)); // #FIXME, is one
    new_trayectory->__imibajcho_munaajpi_state[0x00]=0x00; // this is J, varies while pending_munaajpi_index
    new_trayectory->__imibajcho_munaajpi_duuruva_state=malloc(_wikimyei->__imibajcho_munaajpi_duuruva_state_size*sizeof(__cwcn_type_t));
    for(unsigned int idx=0x00;idx<_wikimyei->__alliu_state_size;idx++){new_trayectory->__alliu_state[idx]=-1;}
    for(unsigned int idx=0x00;idx<_wikimyei->__alliu_state_size;idx++){new_trayectory->__nonuwaabo_alliu_state[idx]=0x00;}
    new_trayectory->__entropy=0x00;
    new_trayectory->__uwaabo_mask=0x00;
    for(unsigned int idx=0x00;idx<_wikimyei->__alliu_duuruva_state_size;idx++){new_trayectory->__alliu_duuruva_state[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo_state_size;idx++){new_trayectory->__uwaabo_state[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__tsane_state_size;idx++){new_trayectory->__tsane_state[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__munaajpi_state_size;idx++){new_trayectory->__munaajpi_state[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__imibajcho_munaajpi_duuruva_state_size;idx++){new_trayectory->__imibajcho_munaajpi_duuruva_state[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo_state_size;idx++){new_trayectory->__uwaabo_adventage[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo_state_size;idx++){new_trayectory->__uwaabo_returns[idx]=0x00;}
    
    return new_trayectory;
}
__load_queue_t *load_fabric(__wikimyei_t *_wikimyei){
    #ifdef WIKIMYEI_DEBUG_v2
        fprintf(stdout,">> > ... load_fabric, load_index: %d\n",_wikimyei->__load_index);
    #endif
    // if(_wikimyei->__load_index!=-1){
    //     fprintf(stderr,">> > ERROR, unable to fabric load, fabric has been set");
    //     assert(0x00);
    // }
    __load_queue_t *new_load=malloc(sizeof(__load_queue_t));    
    new_load->__trayectory_item=trayectory_fabric(_wikimyei);
    new_load->__up=NULL;
    new_load->__down=NULL;
    _wikimyei->__load_index=0x00;
    _wikimyei->__load_size=0x01;
    _wikimyei->__flags->__virgin_load=___CWCN_TRUE;
    _wikimyei->__flags->__endhead_empty_alliu=___CWCN_TRUE;
    _wikimyei->__flags->__nonuwaabo_alliu_done=___CWCN_FALSE;
    return new_load;
}
__wikimyei_t *wikimyei_fabric(
        __alliu_source_t _alliu_source,
        unsigned int _alliu_size,
        unsigned int _tsane_size,
        unsigned int _direct_resolution,
        unsigned int _horizon_munaajpi,
        int _jk_size,
        __cwcn_type_t _gae_gamma,
        __cwcn_type_t _gae_lambda,
        __cwcn_type_t _clip_param,
        __cwcn_type_t _uwaabo_beta,
        __cwcn_type_t _munaajpi_beta,
        __cwcn_type_t _entropy_beta,
        __cwcn_type_t _uwaabo_waapajco_potency,
        __cwcn_type_t _munaajpi_waapajco_potency,
        ___cwcn_bool_t _take_tsane){
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > ... wikimyei_fabric\n");
    #endif
    __wikimyei_t *new_wikimyei=malloc(sizeof(__wikimyei_t));
    if(!new_wikimyei){
        fprintf(stderr,"ERROR, unable to allocate new wikimyei\n");
        assert(0x00);
    } // declaration WIKIMYEI FABRIC order is set, do not shuffle.
    new_wikimyei->__take_tsane=_take_tsane;
    new_wikimyei->__jk_size=_jk_size; // jk_size is times each load item is jk
    new_wikimyei->__horizon_munaajpi=_horizon_munaajpi;
    new_wikimyei->__gae_gamma=_gae_gamma;
    new_wikimyei->__gae_lambda=_gae_lambda;
    new_wikimyei->__clip_param=_clip_param;
    new_wikimyei->__uwaabo_beta=_uwaabo_beta;
    new_wikimyei->__munaajpi_beta=_munaajpi_beta;
    new_wikimyei->__entropy_beta=_entropy_beta;
    
    new_wikimyei->__load_index=-1; // redundant (due to fabric load)
    new_wikimyei->__load_size=0x00; // redundant (due to fabric load)
    new_wikimyei->__alliu_state_size=_alliu_size;
    new_wikimyei->__tsane_state_size=_tsane_size;
    new_wikimyei->__direct_resolution=_direct_resolution;

    set_seed();
    
    new_wikimyei->__jkimyei=jkimyei_fabric(_jk_size);
    new_wikimyei->__alliu=alliu_fabric(_alliu_source, _alliu_size);
    new_wikimyei->__tsane=tsane_fabric(___CWCN_FALSE, _tsane_size);
	new_wikimyei->__ec=entropycosa_fabric(_direct_resolution, _tsane_size);
    new_wikimyei->__uwaabo_state_size=new_wikimyei->__ec->__total_cosa_params; // do not play with position
    

    new_wikimyei->__alliu_duuruva=duuruva_fabric(_alliu_size);
    new_wikimyei->__munaajpi_duuruva=duuruva_fabric(0x01); // #FIXME later, onedimensional J
    new_wikimyei->__adventage_duuruva=duuruva_fabric(new_wikimyei->__uwaabo_state_size);
    reset_duuruva(new_wikimyei->__alliu_duuruva);
    reset_duuruva(new_wikimyei->__munaajpi_duuruva);
    reset_duuruva(new_wikimyei->__adventage_duuruva);
    new_wikimyei->__alliu_duuruva_state_size=new_wikimyei->__alliu_duuruva->__duuruva_vector_size;
    new_wikimyei->__munaajpi_duuruva_state_size=new_wikimyei->__munaajpi_duuruva->__duuruva_vector_size;
    new_wikimyei->__adventage_duuruva_state_size=new_wikimyei->__adventage_duuruva->__duuruva_vector_size;

    new_wikimyei->__uwaabo_base_size=new_wikimyei->__alliu_duuruva_state_size;

    new_wikimyei->__imibajcho_munaajpi_duuruva_state_size=new_wikimyei->__munaajpi_duuruva_state_size;
    new_wikimyei->__munaajpi_base_size=\
        new_wikimyei->__tsane_state_size+\
        new_wikimyei->__uwaabo_state_size+\
        new_wikimyei->__alliu_state_size+\
        new_wikimyei->__alliu_duuruva_state_size+\
        new_wikimyei->__imibajcho_munaajpi_duuruva_state_size;
    new_wikimyei->__munaajpi_state_size=new_wikimyei->__uwaabo_state_size;

    new_wikimyei->__uwaabo=uwaabo_fabric(new_wikimyei->__uwaabo_base_size, new_wikimyei->__uwaabo_state_size);
    new_wikimyei->__munaajpi=munaajpi_fabric(new_wikimyei->__munaajpi_base_size, new_wikimyei->__munaajpi_state_size);
    new_wikimyei->__uwaabo->__attributes->__wapaajco_potency=_uwaabo_waapajco_potency;
    new_wikimyei->__munaajpi->__attributes->__wapaajco_potency=_munaajpi_waapajco_potency;
    
    new_wikimyei->__flags=malloc(sizeof(__wk_flags_t));
    new_wikimyei->__flags->__done=___CWCN_FALSE;
    new_wikimyei->__flags->__nonuwaabo_alliu_done=___CWCN_FALSE;
    new_wikimyei->__flags->__endhead_empty_alliu=___CWCN_TRUE;
    new_wikimyei->__flags->__alliu_duuruva_ready=___CWCN_FALSE;
    new_wikimyei->__flags->__munaajpi_duuruva_ready=___CWCN_FALSE;
    new_wikimyei->__flags->__adventage_duuruva_ready=___CWCN_FALSE;
    new_wikimyei->__flags->__virgin_load=___CWCN_TRUE; // redindant (dur to fabric load)
    new_wikimyei->__flags->__norm_stand=_DEFAULT_NORM_STAND_;

    new_wikimyei->__load_batch_head=load_fabric(new_wikimyei);
    new_wikimyei->__munaajpi_base_w_state=malloc(new_wikimyei->__munaajpi_base_size*sizeof(__cwcn_type_t));

    return new_wikimyei;
}
___cwcn_bool_t all_duuruva_ready(__wikimyei_t *_wikimyei){
    #ifdef JKIMYEI_DEBUG
        fprintf(stdout,"\x1B[0;35m>> > adventage_duuruva_ready: %d, munaajpi_duuruva_ready: %d, alliu_duuruva_ready: %d %s\n",_wikimyei->__flags->__adventage_duuruva_ready, _wikimyei->__flags->__munaajpi_duuruva_ready,_wikimyei->__flags->__alliu_duuruva_ready,COLOR_REGULGAR);
    #endif
    return  _wikimyei->__flags->__adventage_duuruva_ready&&\
            _wikimyei->__flags->__munaajpi_duuruva_ready &&\
            _wikimyei->__flags->__alliu_duuruva_ready;
}
/*
    LOAD QUEUE
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
void load_to_start(__wikimyei_t *_wikimyei){
    while(load_go_down(_wikimyei)!=-1){}
    #ifdef WIKIMYEI_DEBUG_v2
        fprintf(stdout,">> > ... load_to_start ; c_index: [%d]\n",_wikimyei->__load_index);
    #endif
}
void load_to_end(__wikimyei_t *_wikimyei){
    while(load_go_up(_wikimyei)!=-1){}
    #ifdef WIKIMYEI_DEBUG_v2
        fprintf(stdout,">> > ... load_to_end ; c_index: [%d]\n",_wikimyei->__load_index);
    #endif
}
void load_to_index(__wikimyei_t *_wikimyei, int _index){
    if(_wikimyei->__load_size<_index){
        fprintf(stdout, ">> WARNING: requested load index [%d] is unreachable on load size [%d].\n",_index,_wikimyei->__load_size);
    }
    if(_wikimyei->__load_index<_index){
        while(_wikimyei->__load_index!=_index){
            if(load_go_up(_wikimyei)==-1){
                break;
            }
        }
    }else if(_wikimyei->__load_index>_index){
        while(_wikimyei->__load_index!=_index){
            if(load_go_down(_wikimyei)==-1){
                break;
            }
        }
    }
    #ifdef WIKIMYEI_DEBUG_v2
        fprintf(stdout,">> > ... load_to_index ; commanded: [%d] ; c_index: [%d]\n",_index, _wikimyei->__load_index);
    #endif
}
int load_enqueue_trayectory(__wikimyei_t *_wikimyei, __trayectory_t *_new_trayectory){
    __load_queue_t *new_head=malloc(sizeof(__load_queue_t));
    if(!new_head){
        fprintf(stderr, ">>>> ERROR: load_enqueue_trayectory failed to alocate memory\n");
        assert(0x00);
    }
    load_to_end(_wikimyei);
    new_head->__trayectory_item=_new_trayectory;
    new_head->__down=_wikimyei->__load_batch_head;
    new_head->__up=NULL;
    _wikimyei->__load_batch_head=new_head;
    _wikimyei->__load_index+=0x01;
    _wikimyei->__load_size+=0x01;
    _wikimyei->__flags->__endhead_empty_alliu=___CWCN_TRUE;
    _wikimyei->__flags->__nonuwaabo_alliu_done=___CWCN_FALSE;
    #ifdef WIKIMYEI_DEBUG_v2
        fprintf(stdout,">> > .+. load_enqueue_trayectory, c_load_index:%d, c_load_size:%d\n", _wikimyei->__load_index, _wikimyei->__load_size);
    #endif
    return 0x00;
}
__trayectory_t *get_load_trayectory_item(__wikimyei_t *_wikimyei){
    return _wikimyei->__load_batch_head->__trayectory_item;
}
__trayectory_t *glti(__wikimyei_t *_wikimyei){
    return get_load_trayectory_item(_wikimyei);
}
__trayectory_t *get_load_trayectory_item_from_index(__wikimyei_t *_wikimyei, int _index, ___cwcn_bool_t _rneturn){
    // _rneturn marks the flag to allow load_head displacement to index  
    // fprintf(stdout,"__load_index<_index && __load_index<__load_size \t %d < %d  &&  %d < %d\n",_wikimyei->__load_index,_index, _wikimyei->__load_index,_wikimyei->__load_size);
    // fprintf(stdout,"__load_index>_index && __load_index<__load_size \t %d > %d  &&  %d < %d\n",_wikimyei->__load_index,_index, _wikimyei->__load_index,_wikimyei->__load_size);
    #ifdef WIKIMYEI_DEBUG_v2
        fprintf(stdout,">> > ... get_load_trayectory_item_from_index\n");
    #endif
    __trayectory_t *rnetrival;
    int start_index=_wikimyei->__load_index;
    while(_wikimyei->__load_index<_index && _wikimyei->__load_index<_wikimyei->__load_size-0x01){load_go_up(_wikimyei);}// #FIXME assert this method insted of load_go_index
    while(_wikimyei->__load_index>_index && _wikimyei->__load_index<_wikimyei->__load_size-0x01){load_go_down(_wikimyei);}
    rnetrival=_wikimyei->__load_batch_head->__trayectory_item;
    if(!_rneturn){
        while(_wikimyei->__load_index<start_index && _wikimyei->__load_index<_wikimyei->__load_size-0x01){load_go_up(_wikimyei);}
        while(_wikimyei->__load_index>start_index && _wikimyei->__load_index<_wikimyei->__load_size-0x01){load_go_down(_wikimyei);}
    }
    return rnetrival;
}
void load_print_up_trayectory_queue(__wikimyei_t *_wikimyei){
    fprintf(stdout,">> > ... load_print_up_trayectory_queue: \n");
    int c_index=_wikimyei->__load_index;
    load_to_start(_wikimyei);
    do{
        fprintf(stdout,"\tFIRST_STATE: [%d] :: %.2f, imibajcho_munaajpi_state: %.2f, pending_munaajpi: %d, entropy: %.2f\n", _wikimyei->__load_index, glti(_wikimyei)->__alliu_state[0x00], glti(_wikimyei)->__imibajcho_munaajpi_state[0x00], glti(_wikimyei)->__pending_munaajpi, glti(_wikimyei)->__entropy);
    }while(load_go_up(_wikimyei)!=-1);
    load_to_index(_wikimyei, c_index);
}
void load_print_down_trayectory_queue(__wikimyei_t *_wikimyei){
    printf(">> > ... load_print_down_trayectory_queue: \n");
    int c_index=_wikimyei->__load_index;
    load_to_end(_wikimyei);
    do{
        fprintf(stdout,"\tFIRST_STATE: [%d] :: %.2f, imibajcho_munaajpi_state: %.2f, pending_munaajpi: %d, entropy: %.2f\n", _wikimyei->__load_index, glti(_wikimyei)->__alliu_state[0x00], glti(_wikimyei)->__imibajcho_munaajpi_state[0x00], glti(_wikimyei)->__pending_munaajpi, glti(_wikimyei)->__entropy);
    }while(load_go_down(_wikimyei)!=-1);
    load_to_index(_wikimyei, c_index);
}
/*
*/
___cwcn_bool_t load_is_empty(__wikimyei_t *_wikimyei){
    #ifdef WIKIMYEI_DEBUG_v2
    fprintf(stdout,"load_size== %d, && (flag)load_batch_head->__up==NULL: %d, && (flag)load_batch_head->__down==NULL: %d\n",_wikimyei->__load_size, _wikimyei->__load_batch_head->__up==NULL, _wikimyei->__load_batch_head->__down==NULL);
    #endif
    return _wikimyei->__load_size==1 && _wikimyei->__load_batch_head->__up==NULL && _wikimyei->__load_batch_head->__down==NULL;
}
void empty_load(__wikimyei_t *_wikimyei){
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > ... empty_load\n");
    #endif
    if(!load_is_empty(_wikimyei)){
        kill_load(_wikimyei);
    }
    printflags(_wikimyei);
    _wikimyei->__load_batch_head=load_fabric(_wikimyei);
    assert(load_is_empty(_wikimyei));
}

/*
*/
void kill_trayectory(__trayectory_t *_trayectory){
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > ... kill_trayectory\n");
    #endif
    free(_trayectory->__alliu_state);
    free(_trayectory->__nonuwaabo_alliu_state);
    free(_trayectory->__alliu_duuruva_state);
    free(_trayectory->__uwaabo_state);
    free(_trayectory->__uwaabo_returns);
    free(_trayectory->__uwaabo_adventage);
    free(_trayectory->__munaajpi_state);
    free(_trayectory->__imibajcho_munaajpi_state);
    free(_trayectory->__imibajcho_munaajpi_duuruva_state);
    free(_trayectory->__tsane_state);
    free(_trayectory);
}
void kill_load(__wikimyei_t *_wikimyei){
    #ifdef WIKIMYEI_DEBUG_v2
        fprintf(stdout,">> > ... kill_load\n");
    #endif
    load_to_end(_wikimyei);
    do{
        if(_wikimyei->__load_batch_head->__up!=NULL){
            #ifdef WIKIMYEI_DEBUG
            fprintf(stdout,"\t killin index: %d\n",_wikimyei->__load_index+1);
            #endif
            kill_trayectory(_wikimyei->__load_batch_head->__up->__trayectory_item);
            // free(_wikimyei->__load_batch_head->__up);
        }
        _wikimyei->__load_size-=1;
    }while(load_go_down(_wikimyei)!=-1);
    free(_wikimyei->__load_batch_head->__up);
    free(_wikimyei->__load_batch_head->__down);
    assert(_wikimyei->__load_size==0x00);
    _wikimyei->__load_index=-1;
}
/*

*/
void destroy_wikimyei(__wikimyei_t *_wikimyei){
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > ... destroy_wikimyei\n");
    #endif
    free(_wikimyei->__munaajpi_base_w_state);
    alliu_destroy(_wikimyei->__alliu);
    duuruva_destroy(_wikimyei->__alliu_duuruva);
    duuruva_destroy(_wikimyei->__munaajpi_duuruva);
    duuruva_destroy(_wikimyei->__adventage_duuruva);
    tsane_destroy(_wikimyei->__tsane);
    entropycosa_destroy(_wikimyei->__ec);
    tsinuu_destroy(_wikimyei->__uwaabo);
    tsinuu_destroy(_wikimyei->__munaajpi);
    free(_wikimyei->__flags);
    kill_load(_wikimyei);
    free(_wikimyei);
}

void printflags(__wikimyei_t *_wikimyei){
    fprintf(stdout,">> > ... PRINT WK FLGAS\n");
    fprintf(stdout,">> > ... done: %d \t\n",_wikimyei->__flags->__done);
    fprintf(stdout,">> > ... nonuwaabo_alliu_done: %d \t\n",_wikimyei->__flags->__nonuwaabo_alliu_done);
    fprintf(stdout,">> > ... endhead_empty_alliu: %d \t\n",_wikimyei->__flags->__endhead_empty_alliu);
    fprintf(stdout,">> > ... %salliu_duuruva_ready: %d %s\t\n",COLOR_ALLIU,_wikimyei->__flags->__alliu_duuruva_ready,COLOR_REGULGAR);
    fprintf(stdout,">> > ... %smunaajpi_duuruva_ready: %d %s\t\n",COLOR_MUNAAJPI, _wikimyei->__flags->__munaajpi_duuruva_ready,COLOR_REGULGAR);
    fprintf(stdout,">> > ... adventage_duuruva_ready: %d \t\n",_wikimyei->__flags->__adventage_duuruva_ready);
    fprintf(stdout,">> > ... virgin_load: %d \t\n",_wikimyei->__flags->__virgin_load);
}