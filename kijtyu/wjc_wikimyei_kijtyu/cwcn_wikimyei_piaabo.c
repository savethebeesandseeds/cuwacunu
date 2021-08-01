#include "cwcn_wikimyei_piaabo.h"

__trayectory_t *trayectory_fabric(__wikimyei_t *_wikimyei){
    __trayectory_t *new_trayectory=malloc(sizeof(__trayectory_t));
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > ... request trayectory_fabric, alocated address: %p\n",new_trayectory);
    #endif
    if(!new_trayectory){
        fprintf(stderr,"ERROR, program seems unable to allocate memory for requested new trayectory\n");
        assert(new_trayectory!=NULL);
    }
    new_trayectory->__pending_munaajpi_index=0x00;
    new_trayectory->__pending_munaajpi=___CWCN_TRUE;
    new_trayectory->__alliu_state=malloc(_wikimyei->__alliu_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__nonuwaabo_alliu_state=malloc(_wikimyei->__alliu_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__uwaabo_state=malloc(_wikimyei->__uwaabo_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__uwaabo_returns=malloc(_wikimyei->__uwaabo_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__uwaabo_adventage=malloc(_wikimyei->__uwaabo_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__tsane_state=malloc(_wikimyei->__tsane_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__munaajpi_state=malloc(_wikimyei->__munaajpi_state_size*sizeof(__cwcn_type_t));
    new_trayectory->__imibajcho_munaajpi_state=malloc(0x01*sizeof(__cwcn_type_t)); // #FIXME, is one
    for(unsigned int idx=0x00;idx<_wikimyei->__alliu_state_size;idx++){new_trayectory->__alliu_state[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__alliu_state_size;idx++){new_trayectory->__nonuwaabo_alliu_state[idx]=0x00;}
    new_trayectory->__imibajcho_munaajpi_state[0x00]=0x00; // this is J, varies while pending_munaajpi_index
    new_trayectory->__entropy=0x00;
    new_trayectory->__uwaabo_mask=0x01; // #FIXME
    for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo_state_size;idx++){new_trayectory->__uwaabo_state[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__tsane_state_size;idx++){new_trayectory->__tsane_state[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__munaajpi_state_size;idx++){new_trayectory->__munaajpi_state[idx]=0x00;}
    #ifdef __EXPAND_ALLIU__DUURUVA__
    new_trayectory->__alliu_duuruva_state=malloc(_wikimyei->__wajyu->__metric->__alliu_duuruva->__duuruva_vector_size*sizeof(__cwcn_type_t));
    for(unsigned int idx=0x00;idx<_wikimyei->__wajyu->__metric->__alliu_duuruva->__duuruva_vector_size;idx++){new_trayectory->__alliu_duuruva_state[idx]=0x00;}
    #endif
    #ifdef __EXPAND_IMIBAJCHO_MUNAAJPI_DUURUVA__
    new_trayectory->__imibajcho_munaajpi_duuruva_state=malloc(_wikimyei->__wajyu->__metric->__imibajcho_munaajpi_duuruva->__duuruva_vector_size*sizeof(__cwcn_type_t));
    for(unsigned int idx=0x00;idx<_wikimyei->__wajyu->__metric->__imibajcho_munaajpi_duuruva->__duuruva_vector_size;idx++){new_trayectory->__imibajcho_munaajpi_duuruva_state[idx]=0x00;}
    #endif
    for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo_state_size;idx++){new_trayectory->__uwaabo_adventage[idx]=0x00;}
    for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo_state_size;idx++){new_trayectory->__uwaabo_returns[idx]=0x00;}
    #ifdef ALOCATION_DEBUG // #FIXME this is only used here!
    fprintf(stdout,"%s     +++ [trayectory_fabric]:\n%s",COLOR_ALOCATION_ADD,COLOR_REGULAR);
    fprintf(stdout,"%s\t __alliu_state: %s%p:\n",COLOR_ALOCATION_ADD,COLOR_REGULAR,new_trayectory->__alliu_state);
    fprintf(stdout,"%s\t __tsane_state: %s%p:\n",COLOR_ALOCATION_ADD,COLOR_REGULAR,new_trayectory->__tsane_state);
    fprintf(stdout,"%s\t __munaajpi_state: %s%p:\n",COLOR_ALOCATION_ADD,COLOR_REGULAR,new_trayectory->__munaajpi_state);
    fprintf(stdout,"%s\t __nonuwaabo_alliu_state: %s%p:\n",COLOR_ALOCATION_ADD,COLOR_REGULAR,new_trayectory->__nonuwaabo_alliu_state);
    fprintf(stdout,"%s\t __uwaabo_state: %s%p:\n",COLOR_ALOCATION_ADD,COLOR_REGULAR,new_trayectory->__uwaabo_state);
    fprintf(stdout,"%s\t __uwaabo_returns: %s%p:\n",COLOR_ALOCATION_ADD,COLOR_REGULAR,new_trayectory->__uwaabo_returns);
    fprintf(stdout,"%s\t __uwaabo_adventage: %s%p:\n",COLOR_ALOCATION_ADD,COLOR_REGULAR,new_trayectory->__uwaabo_adventage);
    #ifdef __EXPAND_ALLIU__DUURUVA__
    fprintf(stdout,"%s\t __alliu_duuruva_state: %s%p:\n",COLOR_ALOCATION_ADD,COLOR_REGULAR,new_trayectory->__alliu_duuruva_state);
    #endif
    fprintf(stdout,"%s\t __imibajcho_munaajpi_state: %s%p:\n",COLOR_ALOCATION_ADD,COLOR_REGULAR,new_trayectory->__imibajcho_munaajpi_state);
    #ifdef __EXPAND_IMIBAJCHO_MUNAAJPI_DUURUVA__
    fprintf(stdout,"%s\t __imibajcho_munaajpi_duuruva_state: %s%p:\n",COLOR_ALOCATION_ADD,COLOR_REGULAR,new_trayectory->__imibajcho_munaajpi_duuruva_state);
    #endif
    #endif
    return new_trayectory;
}
__load_queue_t *queue_item_fabric(__wikimyei_t *_wikimyei,__trayectory_t *_trayectory){
    __load_queue_t *new_queue_item=malloc(sizeof(__load_queue_t));
    new_queue_item->__trayectory_item=NULL; // #FIXME, queue_fabric seems unstable by allowing ty_item null
    new_queue_item->__up=malloc(sizeof(__load_queue_t*));
    new_queue_item->__down=malloc(sizeof(__load_queue_t*));
    #ifdef WIKIMYEI_DEBUG_LOAD
    fprintf(stdout,">> > ... request to queue_item_fabric\n");
    #endif
    new_queue_item->__trayectory_item=_trayectory;
    #ifdef ALOCATION_DEBUG
    fprintf(stdout,"     +++ [queue [%d] fabric]: \t %s[head:]%p,%s [up:]%p, [down:]%p, [ty:]%p\n",_wikimyei->__load_index,COLOR_ALOCATION_ADD,new_queue_item,COLOR_REGULAR,*new_queue_item->__up,*new_queue_item->__down,new_queue_item->__trayectory_item);
    #endif
    assert(new_queue_item!=NULL);
    assert(new_queue_item->__up!=NULL);
    assert(new_queue_item->__down!=NULL);
    
    
    return new_queue_item;
}
__load_queue_t *load_fabric(__wikimyei_t *_wikimyei){
    // if(_wikimyei->__load_index!=-1){
    //     fprintf(stderr,">> > ERROR, unable to fabric load, fabric has been set");
    //     assert(0x00);
    // }
    assert(load_is_empty(_wikimyei));

    #if defined(WIKIMYEI_DEBUG) || defined(WIKIMYEI_DEBUG_LOAD)
        fprintf(stdout,">> > ... request to [load_fabric], at load_index: %d\n",_wikimyei->__load_index);
    #endif
    __load_queue_t *new_head=queue_item_fabric(_wikimyei,trayectory_fabric(_wikimyei));
    #ifdef ALOCATION_DEBUG
    fprintf(stdout,"\t load_fabric %s[new head alocation:]%p%s\n",COLOR_L_GOOD,new_head,COLOR_REGULAR);
    #endif
    _wikimyei->__load_index=0x00;
    _wikimyei->__load_size=0x01;
    _wikimyei->__flags->__endhead_empty_alliu=___CWCN_TRUE;
    _wikimyei->__flags->__nonuwaabo_alliu_done=___CWCN_FALSE;
    return new_head;
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
    #ifdef ALOCATION_DEBUG
    fprintf(stdout,">> > ... wikimyei_fabric [#FIXME alocation cleaning]\n");
    #endif
    __wikimyei_t *new_wikimyei=malloc(sizeof(__wikimyei_t));
    if(!new_wikimyei){
        fprintf(stderr,"ERROR, unable to allocate new wikimyei\n");
        assert(0x00);
    } // declaration WIKIMYEI FABRIC order is set, do not shuffle.
    #ifdef ALOCATION_DEBUG
    new_wikimyei->__alocation_bunddle=malloc(sizeof(__alocation_bunddle_t));
    #endif
    new_wikimyei->__take_tsane=__TAKE_TSANE__;
    new_wikimyei->__jk_size=__JK_SIZE__; // jk_size is times each load item is jk
    new_wikimyei->__horizon_munaajpi=__HORIZON_MUNAAJPI__;
    new_wikimyei->__gae_gamma=_gae_gamma;
    new_wikimyei->__gae_lambda=_gae_lambda;
    new_wikimyei->__clip_param=_clip_param;
    new_wikimyei->__uwaabo_beta=_uwaabo_beta;
    new_wikimyei->__munaajpi_beta=_munaajpi_beta;
    new_wikimyei->__entropy_beta=_entropy_beta;
    
    new_wikimyei->__load_index=-1; // redundant (due to fabric load)
    new_wikimyei->__load_size=0x00; // redundant (due to fabric load)
    new_wikimyei->__alliu_state_size=__ALLIU_SIZE__;
    new_wikimyei->__tsane_state_size=__TSANE_SIZE__;
    new_wikimyei->__direct_resolution=__DIRECT_RESOLUTION__;

    set_seed(); // woooooooo! frikin better set it correct
    
    new_wikimyei->__jkimyei=jkimyei_fabric(new_wikimyei);
    new_wikimyei->__alliu=alliu_fabric(__ALLIU_SOURCE__, new_wikimyei);
    new_wikimyei->__tsane=tsane_fabric(__TAKE_TSANE__, new_wikimyei);
    new_wikimyei->__wayju
	new_wikimyei->__ec=entropycosa_fabric(__DIRECT_RESOLUTION__, new_wikimyei);
    new_wikimyei->__uwaabo_state_size=new_wikimyei->__ec->__total_cosa_params; // do not play with position
    
    #ifdef __EXPAND_ALLIU__DUURUVA__
    new_wikimyei->__uwaabo_base_size=new_wikimyei->__wajyu->__metric->__alliu_duuruva->__duuruva_vector_size;
    #else 
    new_wikimyei->__uwaabo_base_size=new_wikimyei->__alliu_state_size
    #endif 
    #ifdef __EXPAND_IMIBAJCHO_MUNAAJPI_DUURUVA__
    new_wikimyei->__munaajpi->__imibajcho_munaajpi_duuruva_state_size=\
        new_wikimyei->__wajyu->__metric->__munaajpi_duuruva->__duuruva_vector_size;
    #else
    new_wikimyei->__munaajpi->__imibajcho_munaajpi_duuruva_state_size=0x01; // #FIXME unidimensional J
    #endif
    new_wikimyei->__munaajpi_base_size=\
        new_wikimyei->__tsane_state_size\
        +new_wikimyei->__uwaabo_state_size\
        +new_wikimyei->__uwaabo_base_size\
        +new_wikimyei->__wajyu->__metric->__alliu_duuruva->__duuruva_vector_size\
        +new_wikimyei->__munaajpi->__imibajcho_munaajpi_duuruva_state_size\
        +new_wikimyei->__wajyu->__metric->__imibajcho_munaajpi_duuruva->__duuruva_vector_size;
    new_wikimyei->__munaajpi_state_size=new_wikimyei->__uwaabo_state_size;

    new_wikimyei->__uwaabo=uwaabo_fabric(new_wikimyei->__uwaabo_base_size, new_wikimyei->__uwaabo_state_size);
    new_wikimyei->__munaajpi=munaajpi_fabric(new_wikimyei->__munaajpi_base_size, new_wikimyei->__munaajpi_state_size);
    new_wikimyei->__uwaabo->__attributes->__wapaajco_potency=_uwaabo_waapajco_potency;
    new_wikimyei->__munaajpi->__attributes->__wapaajco_potency=_munaajpi_waapajco_potency;
    
    new_wikimyei->__flags=malloc(sizeof(__wk_flags_t));
    new_wikimyei->__flags->__done=___CWCN_FALSE;
    new_wikimyei->__flags->__wajyu_ready;
    #ifndef DEBUG_LINEAR_EXPERIMENT
    new_wikimyei->__flags->__norm_stand=_DEFAULT_NORM_STAND_;
    #else
    new_wikimyei->__flags->__norm_stand=0x00;
    #endif
    // new_wikimyei->__load_head=malloc(sizeof(__load_queue_t)); // DO NOT USE
    new_wikimyei->__load_head=NULL;//load_fabric(new_wikimyei);

    /* load on wikimyei was deprecated, load_head has all the props */
    // new_wikimyei->__load_up=malloc(sizeof(*__load_queue_t));
    // new_wikimyei->__load_down=malloc(sizeof(*__load_queue_t));
    // assert(new_wikimyei->__load_up!=NULL);
    // assert(new_wikimyei->__load_down!=NULL);
    // new_wikimyei->__load_up=NULL;
    // new_wikimyei->__load_down=NULL;
    /* load on wikimyei was deprecated, load_head has all the props */
    
    assert(load_is_healty(new_wikimyei));
    assert(load_is_empty(new_wikimyei));

    new_wikimyei->__munaajpi_base_w_state=malloc(new_wikimyei->__munaajpi_base_size*sizeof(__cwcn_type_t));

    return new_wikimyei;
}
___cwcn_bool_t all_...wajyu_duuruva_ready(__wikimyei_t *_wikimyei){
    #if defined(JKIMYEI_DEBUG) || defined(DUURUVA_DEBUG)
        fprintf(stdout,"%s>> > adventage_duuruva_ready: %d, munaajpi_duuruva_ready: %d, alliu_duuruva_ready: %d %s\n",COLOR_DUURUVA,_wikimyei->__flags->__uwaabo_adventage_duuruva_ready, _wikimyei->__flags->__munaajpi_duuruva_ready,_wikimyei->__flags->__alliu_duuruva_ready,COLOR_REGULAR);
    #endif
    return  _wikimyei->__flags->__uwaabo_adventage_duuruva_ready&&\
            _wikimyei->__flags->__munaajpi_duuruva_ready &&\
            _wikimyei->__flags->__alliu_duuruva_ready;
}
/*
    LOAD QUEUE
*/
int load_go_up(__wikimyei_t *_wikimyei){
    #ifdef WIKIMYEI_DEBUG_LOAD
    fprintf(stdout,">> > ... request to go [up] on load index [%d]\n",_wikimyei->__load_index);
    #endif
    if(load_is_empty(_wikimyei)){
        #ifdef WIKIMYEI_DEBUG_LOAD
        fprintf(stdout,"\t [return -1] load is empty\n");
        #endif
        return -0x01;
    }
    #ifdef WIKIMYEI_DEBUG_LOAD
    if(load_on_end(_wikimyei)){fprintf(stdout,"\t[go_up will return -1] on load index [%d] \t (is NULL)  load_up: %p\n",_wikimyei->__load_index,*_wikimyei->__load_head->__up);}
    #endif
    if(load_on_end(_wikimyei)){
        assert(load_on_end(_wikimyei));
        return -0x01;
    }
    _wikimyei->__load_index+=0x01;
    _wikimyei->__load_head=*_wikimyei->__load_head->__up;
    return 0x00;
}
int load_go_down(__wikimyei_t *_wikimyei){
    #ifdef WIKIMYEI_DEBUG_LOAD
    fprintf(stdout,">> > ... request to go [down] on load index [%d]\n",_wikimyei->__load_index);
    #endif
    if(load_is_empty(_wikimyei)){
        #ifdef WIKIMYEI_DEBUG_LOAD
        fprintf(stdout,"\t [return -1] load is empty\n");
        #endif
        return -0x01;
    }
    #ifdef WIKIMYEI_DEBUG_LOAD
    if(load_on_start(_wikimyei)){fprintf(stdout,"\t load_go_down will [return -1] for load index [%d] (is NULL): [load_down:] %p\n",_wikimyei->__load_index,*_wikimyei->__load_head->__down);}
    #endif
    if(load_on_start(_wikimyei)){
        assert(load_on_start(_wikimyei));
        return -0x01;
    }
    _wikimyei->__load_index+=-0x01;
    _wikimyei->__load_head=*_wikimyei->__load_head->__down;
    return 0x00;
}
void load_to_start(__wikimyei_t *_wikimyei){
    #ifdef WIKIMYEI_DEBUG_LOAD
        fprintf(stdout,">> > ... load_to_start ; c_index: [%d]\n",_wikimyei->__load_index);
    #endif
    while(load_go_down(_wikimyei)!=-1){}
    assert(load_on_start(_wikimyei));
}
void load_to_end(__wikimyei_t *_wikimyei){
    #ifdef WIKIMYEI_DEBUG_LOAD
        fprintf(stdout,">> > ... load_to_end ; c_index: [%d]\n",_wikimyei->__load_index);
    #endif
    while(load_go_up(_wikimyei)!=-1){}
    assert(load_on_end(_wikimyei));
}
void load_to_index(__wikimyei_t *_wikimyei, int _index){
    assert(_index<_wikimyei->__load_size);
    if(!load_is_empty(_wikimyei)){
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
        #ifdef WIKIMYEI_DEBUG_LOAD
            fprintf(stdout,">> > ... load_to_index ; commanded: [%d] ; c_index: [%d]\n",_index, _wikimyei->__load_index);
        #endif
    }
    #ifdef WIKIMYEI_DEBUG_LOAD
    else{fprintf(stdout,">> > ... load_to_index avoided due to noob load, load_to_index ; commanded: [%d] ; c_index: [%d]\n",_index, _wikimyei->__load_index);}
    #endif
}
int yield_next_trayectory(__wikimyei_t *_wikimyei){
    // #FIXME do something when with int 
    #ifdef WIKIMYEI_DEBUG
    fprintf(stdout,">> > ... request to yield_next_trayectory\n");
    #endif
    assert(load_is_healty(_wikimyei));
    if(load_is_empty(_wikimyei)){
        assert(load_is_empty(_wikimyei));
        _wikimyei->__load_head=load_fabric(_wikimyei);
        *_wikimyei->__load_head->__down=NULL;
        *_wikimyei->__load_head->__up=NULL;
    }else{
        load_to_end(_wikimyei);
        __load_queue_t *new_head=queue_item_fabric(_wikimyei,trayectory_fabric(_wikimyei));
        *new_head->__down=_wikimyei->__load_head;
        *new_head->__up=NULL;
        *_wikimyei->__load_head->__up=new_head;
        _wikimyei->__load_head=new_head;
        _wikimyei->__load_index+=0x01;
        _wikimyei->__load_size+=0x01;
        _wikimyei->__flags->__endhead_empty_alliu=___CWCN_TRUE;
        _wikimyei->__flags->__nonuwaabo_alliu_done=___CWCN_FALSE;
    }
    #ifdef WIKIMYEI_DEBUG_LOAD
    fprintf(stdout,"\t +++ [trayectory enqueued]: \t [head:] %p, \t [up:] %p, \t [down:] %p, \t [trayectory:] %p\n",_wikimyei->__load_head,*_wikimyei->__load_head->__up,*_wikimyei->__load_head->__down, _wikimyei->__load_head->__trayectory_item);
    #endif
    // #ifdef ALOCATION_DEBUG
    // fprintf(stdout,"\t[yield_next_trayectory:]\n");
    // load_print_up_trayectory_pointers(_wikimyei);
    // #endif
    #ifdef WIKIMYEI_DEBUG_v2
    fprintf(stdout,">> > ... yield_next_trayectory, c_load_index:%d, c_load_size:%d\n", _wikimyei->__load_index, _wikimyei->__load_size);
    #endif
    return 0x00;
}
__trayectory_t *get_load_trayectory_item(__wikimyei_t *_wikimyei){
    return _wikimyei->__load_head->__trayectory_item;
}
__trayectory_t *glti(__wikimyei_t *_wikimyei){
    return get_load_trayectory_item(_wikimyei);
}
__trayectory_t *get_load_trayectory_item_from_index(__wikimyei_t *_wikimyei, int _index, ___cwcn_bool_t _rneturn){
    // _rneturn holds the flag to rever the head index displacement

    // fprintf(stdout,"__load_index<_index && __load_index<__load_size \t %d < %d  &&  %d < %d\n",_wikimyei->__load_index,_index, _wikimyei->__load_index,_wikimyei->__load_size);
    // fprintf(stdout,"__load_index>_index && __load_index<__load_size \t %d > %d  &&  %d < %d\n",_wikimyei->__load_index,_index, _wikimyei->__load_index,_wikimyei->__load_size);
    #ifdef WIKIMYEI_DEBUG_v2
        fprintf(stdout,">> > ... get_load_trayectory_item_from_index\n");
    #endif
    __trayectory_t *rnetrival=NULL; // #FIXME, c noob knows not about this function
    if(load_is_empty(_wikimyei)){return rnetrival;}
    int start_index=_wikimyei->__load_index;
    load_to_index(_wikimyei, _index);
    rnetrival=_wikimyei->__load_head->__trayectory_item;
    if(!_rneturn){
        load_to_index(_wikimyei,start_index);
    }
    return rnetrival;
}
void load_print_up_trayectory_pointers(__wikimyei_t *_wikimyei){
    fprintf(stdout,">> > ... request to load_print_up_trayectory_pointers: \n");
    if(load_is_empty(_wikimyei)){fprintf(stdout,">> > ... \t [no load found]\n");}
    else{
        int c_index=_wikimyei->__load_index;
        load_to_start(_wikimyei);
        if(!load_is_empty(_wikimyei)){do{
            fprintf(stdout,"   .     [%d] :: %s[head:]%p,%s \t[up:]%p, \t[down:]%p \t[ty:]%p\n", _wikimyei->__load_index, COLOR_L_GOOD,_wikimyei->__load_head, COLOR_REGULAR, _wikimyei->__load_head->__up, _wikimyei->__load_head->__down, _wikimyei->__load_head->__trayectory_item);
            fprintf(stdout,"   .     [%d] :: [*head]\t\t, \t%s[*up]%p,%s \t%s[*down]%p,%s \t[*ty]\t\t\n",_wikimyei->__load_index, COLOR_L_GOOD,*_wikimyei->__load_head->__up, COLOR_REGULAR, COLOR_L_GOOD,*_wikimyei->__load_head->__down,COLOR_REGULAR);
        }while(load_go_up(_wikimyei)!=-1);}
        load_to_index(_wikimyei, c_index);
    }
}
void load_print_up_trayectory_queue(__wikimyei_t *_wikimyei){
    fprintf(stdout,">> > ... request to load_print_up_trayectory_queue: \n");
    if(load_is_empty(_wikimyei)){fprintf(stdout,">> > ... \t [no load found]\n");}
    else{
        int c_index=_wikimyei->__load_index;
        load_to_start(_wikimyei);
        if(!load_is_empty(_wikimyei)){do{
            fprintf(stdout,"   |     [index:]%d :: alliu[0]: %.2f, imibajcho_munaajpi: %.2f, pending_munaajpi: %d, entropy: %.2f\n", _wikimyei->__load_index, glti(_wikimyei)->__alliu_state[0x00], glti(_wikimyei)->__imibajcho_munaajpi_state[0x00], glti(_wikimyei)->__pending_munaajpi, glti(_wikimyei)->__entropy);
        }while(load_go_up(_wikimyei)!=-1);}
        load_to_index(_wikimyei, c_index);
    }
}
void load_print_down_trayectory_queue(__wikimyei_t *_wikimyei){
    printf(">> > ... request to load_print_down_trayectory_queue: \n");
    if(load_is_empty(_wikimyei)){fprintf(stdout,">> > ... \t [no load found]\n");}
    else{
        int c_index=_wikimyei->__load_index;
        load_to_end(_wikimyei);
        if(!load_is_empty(_wikimyei)){do{
            fprintf(stdout,">> > load index: [%d] :: alliu_state[0]: %.2f, imibajcho_munaajpi_state: %.2f, pending_munaajpi: %d, entropy: %.2f\n", _wikimyei->__load_index, glti(_wikimyei)->__alliu_state[0x00], glti(_wikimyei)->__imibajcho_munaajpi_state[0x00], glti(_wikimyei)->__pending_munaajpi, glti(_wikimyei)->__entropy);
        }while(load_go_down(_wikimyei)!=-1);}
        load_to_index(_wikimyei, c_index);
    }
}
/*
*/
___cwcn_bool_t load_on_end(__wikimyei_t *_wikimyei){
    return _wikimyei->__load_index-_wikimyei->__load_size==-1;
}
___cwcn_bool_t load_on_start(__wikimyei_t *_wikimyei){
    return _wikimyei->__load_index==0;
}
___cwcn_bool_t load_on_noob(__wikimyei_t *_wikimyei){
    return load_on_start(_wikimyei) && load_on_end(_wikimyei);
}
___cwcn_bool_t load_is_healty(__wikimyei_t *_wikimyei){
    if(load_is_empty(_wikimyei)){
        #ifdef WIKIMYEI_DEBUG_HEALT
        fprintf(stdout,"%s\t [empty load]: \tH E A L T\
        \n\t\tindex: \t\t\t\t\t\t%d, \
        \n\t\tload_is_empty(): \t\t\t\t\t%s %s\n", \
        COLOR_HEALT,\
        _wikimyei->__load_index,\
        print_cwcn_bool((load_is_empty(_wikimyei))),\
        COLOR_REGULAR\
        );
        #endif
        return ___CWCN_TRUE;
    } else {
        if(load_on_noob(_wikimyei)){
            #ifdef WIKIMYEI_DEBUG_HEALT
fprintf(stdout,"\t %s[noob load]: \tH E A L T\
\n\t\tindex: \t\t\t\t\t\t%d, \
\n\t\t_wikimyei->__load_head!=NULL: \t\t\t\t%s \t&&\
\n\t\t_wikimyei->__load_head->__trayectory_item!=NULL: \t%s \t&&\
\n\t\t*_wikimyei->__load_head->__up==NULL: \t\t\t%s \t&&\
\n\t\t*_wikimyei->__load_head->__down==NULL, \t\t\t%s \t&&\
\n\t\t_wikimyei->__load_index<_wikimyei->__load_size: \t%s \t&&\
\n\t\t!load_is_empty: \t\t\t\t\t%s%s\n",\
                            COLOR_HEALT,
                            _wikimyei->__load_index,\
                            print_cwcn_bool((_wikimyei->__load_head!=NULL)),\
                            print_cwcn_bool((_wikimyei->__load_head->__trayectory_item!=NULL)),\
                            print_cwcn_bool((*_wikimyei->__load_head->__up==NULL)),\
                            print_cwcn_bool((*_wikimyei->__load_head->__down==NULL)),\
                            print_cwcn_bool((_wikimyei->__load_index<_wikimyei->__load_size)),\
                            print_cwcn_bool((!load_is_empty(_wikimyei))),
                            COLOR_REGULAR
                            );
            #endif
            return  _wikimyei->__load_head!=NULL &&\
                    _wikimyei->__load_head->__trayectory_item!=NULL &&\
                    *_wikimyei->__load_head->__up==NULL &&\
                    *_wikimyei->__load_head->__down==NULL &&\
                    _wikimyei->__load_index<_wikimyei->__load_size &&\
                    !load_is_empty(_wikimyei);
        }else if(load_on_end(_wikimyei)){
            #ifdef WIKIMYEI_DEBUG_HEALT
fprintf(stdout,"%s\t [up extrema]: \tH E A L T\
\n\t\tindex: \t\t\t\t\t\t%d, \
\n\t\t_wikimyei->__load_head!=NULL: \t\t\t\t%s \t&&\
\n\t\t_wikimyei->__load_head->__trayectory_item!=NULL: \t%s \t&&\
\n\t\t*_wikimyei->__load_head->__up==NULL: \t\t\t%s \t&&\
\n\t\t_wikimyei->__load_index<_wikimyei->__load_size: \t%s \t&&\
\n\t\t!load_is_empty: \t\t\t\t\t%s%s\n",\
                            COLOR_HEALT,
                            _wikimyei->__load_index,\
                            print_cwcn_bool((_wikimyei->__load_head!=NULL)),\
                            print_cwcn_bool((_wikimyei->__load_head->__trayectory_item!=NULL)),\
                            print_cwcn_bool((*_wikimyei->__load_head->__up==NULL)),\
                            print_cwcn_bool((_wikimyei->__load_index<_wikimyei->__load_size)),\
                            print_cwcn_bool((!load_is_empty(_wikimyei))),
                            COLOR_REGULAR);
            #endif
            return  _wikimyei->__load_head!=NULL &&\
                    _wikimyei->__load_head->__trayectory_item!=NULL &&\
                    *_wikimyei->__load_head->__up==NULL &&\
                    _wikimyei->__load_index<_wikimyei->__load_size &&\
                    !load_is_empty(_wikimyei);
        } else if(load_on_start(_wikimyei)){
            #ifdef WIKIMYEI_DEBUG_HEALT
fprintf(stdout,"%s\t [down extrema]: \tH E A L T\
\n\t\tindex: \t\t\t\t\t\t%d, \
\n\t\t_wikimyei->__load_head!=NULL: \t%s \t&&\
\n\t\t_wikimyei->__load_head->__trayectory_item!=NULL: \t%s \t&&\
\n\t\t*_wikimyei->__load_head->__down==NULL: \t\t\t%s \t&&\
\n\t\t_wikimyei->__load_index<_wikimyei->__load_size: \t%s \t&&\
\n\t\t!load_is_empty: \t\t\t\t\t%s%s\n",\
                            COLOR_HEALT,
                            (_wikimyei->__load_index),
                            print_cwcn_bool((_wikimyei->__load_head!=NULL)),\
                            print_cwcn_bool((_wikimyei->__load_head->__trayectory_item!=NULL)),\
                            print_cwcn_bool((*_wikimyei->__load_head->__down==NULL)),\
                            print_cwcn_bool((_wikimyei->__load_index<_wikimyei->__load_size)),\
                            print_cwcn_bool((!load_is_empty(_wikimyei))),
                            COLOR_REGULAR);
            #endif
            return  _wikimyei->__load_head!=NULL &&\
                    _wikimyei->__load_head->__trayectory_item!=NULL &&\
                    *_wikimyei->__load_head->__down==NULL &&\
                    _wikimyei->__load_index<_wikimyei->__load_size &&\
                    !load_is_empty(_wikimyei);
        } else {
            #ifdef WIKIMYEI_DEBUG_HEALT
fprintf(stdout,"%s\t[no extrema]: \tH E A L T\
\n\t\tindex: \t\t\t\t\t\t%d, \
\n\t\t_wikimyei->__load_head!=NULL: \t\t\t\t%s \t&&\
\n\t\t_wikimyei->__load_head->__trayectory_item!=NULL: \t%s \t&&\
\n\t\t_wikimyei->__load_index<_wikimyei->__load_size: \t%s \t&&\
\n\t\t!load_is_empty: \t\t\t\t\t%s%s\n",\
                            COLOR_HEALT,
                            _wikimyei->__load_index,\
                            print_cwcn_bool((_wikimyei->__load_head!=NULL)),\
                            print_cwcn_bool((_wikimyei->__load_head->__trayectory_item!=NULL)),\
                            print_cwcn_bool((_wikimyei->__load_index<_wikimyei->__load_size)),\
                            print_cwcn_bool((!load_is_empty(_wikimyei))),
                            COLOR_REGULAR);
            #endif
            return  _wikimyei->__load_head!=NULL &&\
                    _wikimyei->__load_head->__trayectory_item!=NULL &&\
                    _wikimyei->__load_index<_wikimyei->__load_size &&\
                    !load_is_empty(_wikimyei); // empty load is NOT healty
        }
    }
}
___cwcn_bool_t load_is_empty(__wikimyei_t *_wikimyei){
    assert(_wikimyei->__load_index<_wikimyei->__load_size);
    if(_wikimyei->__load_head==NULL){ // #FIXME, add checks for ** pointer chain
        assert(_wikimyei->__load_head==NULL);
        assert(_wikimyei->__load_index==-0x01);
        assert(_wikimyei->__load_size==0);
        return ___CWCN_TRUE;
    }else{
        assert(_wikimyei->__load_head!=NULL);
        assert(_wikimyei->__load_index>=0);
        assert(_wikimyei->__load_size>0);
        return ___CWCN_FALSE;
    }
}
/*
*/
void kill_trayectory(__trayectory_t *_trayectory){
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > ... request to kill_trayectory: %p\n",_trayectory);
    #endif
    free(_trayectory->__alliu_state);                       _trayectory->__alliu_state=NULL;
    free(_trayectory->__nonuwaabo_alliu_state);             _trayectory->__nonuwaabo_alliu_state=NULL;
    free(_trayectory->__uwaabo_state);                      _trayectory->__uwaabo_state=NULL;
    free(_trayectory->__uwaabo_returns);                    _trayectory->__uwaabo_returns=NULL;
    free(_trayectory->__uwaabo_adventage);                  _trayectory->__uwaabo_adventage=NULL;
    free(_trayectory->__imibajcho_munaajpi_state);          _trayectory->__imibajcho_munaajpi_state=NULL;
    free(_trayectory->__tsane_state);                       _trayectory->__tsane_state=NULL;
    free(_trayectory->__munaajpi_state);                    _trayectory->__munaajpi_state=NULL;
    #ifdef __EXPAND_ALLIU__DUURUVA__
    free(_trayectory->__alliu_duuruva_state);               _trayectory->__alliu_duuruva_state=NULL;
    #endif
    #ifdef __EXPAND_IMIBAJCHO_MUNAAJPI_DUURUVA__
    free(_trayectory->__imibajcho_munaajpi_duuruva_state);  _trayectory->__imibajcho_munaajpi_duuruva_state=NULL;
    #endif
}
void kill_queue(__load_queue_t *_queue){
    #ifdef ALOCATION_DEBUG
    fprintf(stdout,">> > --- [killin queue] \n\t(pass)[head:]%p, (kill)[up:]%p (kill)[down:]%p (kill)[ty:]%p\n",\
                    _queue,\
                    _queue->__up,\
                    _queue->__down,\
                    _queue->__trayectory_item);
    #endif
    kill_trayectory(_queue->__trayectory_item);
    free(_queue->__trayectory_item);    _queue->__trayectory_item=NULL;
    free(_queue->__down);               _queue->__down=NULL;
    free(_queue->__up);                 _queue->__up=NULL;
}
void empty_queue_on_last(__wikimyei_t *_wikimyei){
    assert(load_is_healty(_wikimyei));
    load_to_end(_wikimyei);
    if(_wikimyei->__load_size>=0x02){
        load_go_down(_wikimyei); // head is null
        #if defined(WIKIMYEI_DEBUG) || defined(ALOCATION_DEBUG)
        fprintf(stdout,"\t [killing load in]: [%d]->__up (load size: %d)\n",_wikimyei->__load_index,_wikimyei->__load_size);
        #endif
        assert(!load_on_end(_wikimyei));
        kill_queue(*_wikimyei->__load_head->__up);
        #ifdef ALOCATION_DEBUG
        fprintf(stdout,">> > --- [killin *up] \n\t(kill)[*head->__up:]%p",*_wikimyei->__load_head->__up);
        #endif
        free(*_wikimyei->__load_head->__up);
        *_wikimyei->__load_head->__up=NULL;
        assert(_wikimyei->__load_head->__up!=NULL);
        assert(*_wikimyei->__load_head->__up==NULL);
        assert(_wikimyei->__load_head!=NULL);
        assert(_wikimyei->__load_size>=0x02);
        _wikimyei->__load_size--;
        assert(load_is_healty(_wikimyei));
    } else if(_wikimyei->__load_size==1){
        #if defined(WIKIMYEI_DEBUG) || defined(ALOCATION_DEBUG)
        #endif
        #if defined(WIKIMYEI_DEBUG) || defined(ALOCATION_DEBUG)
        fprintf(stdout,"\t [killing last queue]: [%d] with (load size: %d)\n",_wikimyei->__load_index,_wikimyei->__load_size);
        #endif
        assert(load_on_start(_wikimyei) && load_on_end(_wikimyei));
        kill_queue(_wikimyei->__load_head);
        #ifdef ALOCATION_DEBUG
        fprintf(stdout,">> > --- [killin head] \n\t(kill)[head:]%p",_wikimyei->__load_head);
        #endif
        free(_wikimyei->__load_head);
        _wikimyei->__load_head=NULL;
        _wikimyei->__load_size--;
        _wikimyei->__load_index--;
        assert(load_is_empty(_wikimyei));
        assert(load_is_healty(_wikimyei)); // #FIXME an empty load is a healty load?
    }
    #ifdef ALOCATION_DEBUG
    else{fprintf(stdout,">> > /// [skippin up queue] \t(item found to be NULL)\t at load index: [%d]\t with address: %p\n",_wikimyei->__load_index,_wikimyei->__load_head->__up);}
    #endif
}
void kill_load(__wikimyei_t *_wikimyei){
    #if defined(WIKIMYEI_DEBUG) || defined(ALOCATION_DEBUG)
    fprintf(stdout,">> > ... request to kill_load\n");
    #endif
    if(load_is_empty(_wikimyei)){
        #if defined(WIKIMYEI_DEBUG)  || defined(ALOCATION_DEBUG)
        fprintf(stdout, "\t [found empty load]\n");
        #endif
    } else {
        do{
            empty_queue_on_last(_wikimyei);
            // #ifdef ALOCATION_DEBUG
            // printf("\t [current queue pointer state:]\n");
            // load_print_up_trayectory_pointers(_wikimyei);
            // #endif
        }while(!load_is_empty(_wikimyei));
    }
    assert(load_is_empty(_wikimyei));
    _wikimyei->__flags->__done=___CWCN_FALSE;
}
/*

*/
void destroy_wikimyei(__wikimyei_t *_wikimyei){
    // #FIXME end it
    #if defined(WIKIMYEI_DEBUG) || defined(ALOCATION_DEBUG)
        fprintf(stdout,">> > ... destroy_wikimyei [#FIXME alocation cleaning]\n");
    #endif
    free(_wikimyei->__munaajpi_base_w_state);
    kill_load(_wikimyei);
    free(_wikimyei->__load_head);
    alliu_destroy(_wikimyei->__alliu);
    duuruva_destroy(_wikimyei->__alliu_duuruva);
    ...__EXPAND_IMIBAJCHO_MUNAAJPI_DUURUVA__
    duuruva_destroy(_wikimyei->__wayju->__metric->__munaajpi_duuruva);
    duuruva_destroy(_wikimyei->__adventage_duuruva);
    tsane_destroy(_wikimyei->__tsane);
    entropycosa_destroy(_wikimyei->__ec);
    tsinuu_destroy(_wikimyei->__uwaabo);
    tsinuu_destroy(_wikimyei->__munaajpi);
    free(_wikimyei->__flags);
    if(_wikimyei->__load_head!=NULL){free(_wikimyei->__load_head);}
    // free(_wikimyei); // #FIXME assert me outside
}

void print...flags(__wikimyei_t *_wikimyei){
    fprintf(stdout,">> > Wikimyei Flags:\n");
    fprintf(stdout,">> > ... done: %d \t\n",_wikimyei->__flags->__done);
    fprintf(stdout,">> > ... nonuwaabo_alliu_done: %d \t\n",_wikimyei->__flags->__nonuwaabo_alliu_done);
    fprintf(stdout,">> > ... endhead_empty_alliu: %d \t\n",_wikimyei->__flags->__endhead_empty_alliu);
    fprintf(stdout,">> > ... %salliu_duuruva_ready: %d %s\t\n",COLOR_ALLIU,_wikimyei->__flags->__alliu_duuruva_ready,COLOR_REGULAR);
    fprintf(stdout,">> > ... %smunaajpi_duuruva_ready: %d %s\t\n",COLOR_MUNAAJPI, _wikimyei->__flags->__munaajpi_duuruva_ready,COLOR_REGULAR);
    fprintf(stdout,">> > ... adventage_duuruva_ready: %d \t\n",_wikimyei->__flags->__uwaabo_adventage_duuruva_ready);
}