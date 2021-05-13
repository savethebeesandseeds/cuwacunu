#include "wikimyei.config.h"
#include "cwcn_jkimyei_nebajke.h"
// #include <stdio.h>
// #include "cwcn_kemu_piaabo.h"
// #include "cwcn_wikimyei_nebajke.h"
// remmemer PMF[a_idx], from I, from the past ¿do we make it?.

// __jk_queue_t *jk_queue_fabric(__jkimyei_t *__jkimyei){
//     __jk_queue_t *new_jk_queue=malloc(sizeof(__jk_queue_t));
//     new_jk_queue->__trayectory_item=NULL;
//     new_jk_queue->__next=NULL;
//     return new_jk_queue;
// }

// /*
//     QUEUE
// */
// void jk_enqueue_trayectory(__jkimyei_t *_jkimyei, __trayectory_t *_new_trayectory){
// 	__jk_queue_t *new_head=malloc(sizeof(__jk_queue_t));
//     if(!new_head){
//         fprintf(stderr, ">>>> ERROR: jk_enqueue_trayectory failed to enqueue\n");
//         assert(0x00);
//     }
//     new_head->__trayectory_item=_new_trayectory;
//     new_head->__next=_jkimyei->__jk_batch_head;
//     _jkimyei->__jk_batch_head=new_head;
//     _jkimyei->__jk_index+=0x01;
//     fprintf(stdout, "\t [jk]_enqueue_trayectory -- jk item index [%d]\n", _jkimyei->__jk_index);
// }
// void jk_enqueue_trayectory_index(__wikimyei_t *_wikimyei, int _index, ___cwcn_bool_t _rneturn){
//     jk_enqueue_trayectory(_wikimyei->__jkimyei, get_load_trayectory_item_from_index(_wikimyei, _index, _rneturn));
//     fprintf(stdout, "\t [jk]_enqueue_trayectory_index -- load item index [%d]\n", _index);
// }
// __trayectory_t *jk_dequeue_trayectory(__jkimyei_t *_jkimyei){
//     if(_jkimyei->__jk_batch_head==NULL || _jkimyei->__jk_index<0){return NULL;}
//     fprintf(stdout, "\t [jk]_dequeue_trayectory -- jk item index [%d]\n", _jkimyei->__jk_index);
//     __trayectory_t *retval=NULL;
//     __jk_queue_t *c_current=_jkimyei->__jk_batch_head;
//     retval=c_current->__trayectory_item;
//     _jkimyei->__jk_batch_head=_jkimyei->__jk_batch_head->__next;
//     _jkimyei->__jk_index-=0x01;
//     return retval;
// }
// void jk_print_trayectory_queue(__jkimyei_t *_jkimyei){
//     fprintf(stdout, ">> [jk]_print_trayectory_queue\n");
//     __jk_queue_t *c_current=_jkimyei->__jk_batch_head;
// 	if(!(c_current != NULL && c_current->__trayectory_item!=NULL)){
//         fprintf(stdout, "\t [jk]: jk queue is empty...\n");
// 	}
//     while(c_current != NULL && c_current->__trayectory_item!=NULL){
//         fprintf(stdout, "\t [jk]: jk index [%d] FIRST_STATE: %9.2f\n", _jkimyei->__jk_index, c_current->__trayectory_item->__uwaabo_base[0x00]);
//         c_current=c_current->__next;
//     }
// }
// __trayectory_t *jk_get_trayectory_item(__jkimyei_t *_jkimyei){
//     return _jkimyei->__jk_batch_head->__trayectory_item;
// }
// /*

// */
// void release_jk(__wikimyei_t *_wikimyei){
// 	fprintf(stdout,">> release_[jk]\n");
// 	while(jk_dequeue_trayectory(_wikimyei->__jkimyei)!=NULL){}
// 	assert(_wikimyei->__jkimyei->__jk_index==-1);
// }
// void fill_jk_rand(__wikimyei_t *_wikimyei){ // map __load in a random manner to fill __jk
// 	fprintf(stdout,">> fill_[jk]_rand\n");
// 	int rand_idx;
// 	__jkimyei_t *c_jkimyei=_wikimyei->__jkimyei;
// 	if(!(c_jkimyei->__jk_index<c_jkimyei->__jk_size)){fprintf(stderr,">>> WARNING: __jk_queue is fully loaded on request.");}
// 	while(c_jkimyei->__jk_index<c_jkimyei->__jk_size-0x01){
// 		rand_idx=jk_rand_index(_wikimyei);
// 		jk_enqueue_trayectory_index(_wikimyei, rand_idx, 0x0);
// 	}
// }

void GAE(__wikimyei_t *_wikimyei){
    int c_index=_wikimyei->__load_index;
    __cwcn_type_t delta=malloc(sizeof(__cwcn_type_t));
    __cwcn_type_t aux=malloc(sizeof(__cwcn_type_t));
    __cwcn_type_t *gae=malloc(_wikimyei->__uwaabo_state_size*sizeof(__cwcn_type_t));
    load_to_index(_wikimyei, _wikimyei->__load_size-_wikimyei->__horizon_munaajpi-0x01);
    while(load_go_down(_wikimyei)!=-1){
        if(!glti(_wikimyei)->__pending_munaajpi){
            for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo_state_size;idx++){
                load_go_up(_wikimyei);
                aux=_wikimyei->__gae_gamma*glti(_wikimyei)->__munaajpi_state[idx];
                load_go_down(_wikimyei);
                delta=glti(_wikimyei)->__imibajcho_munaajpi_state+\
                    aux*glti(_wikimyei)->__uwaabo_mask-\
                    glti(_wikimyei)->__munaajpi_state[idx];
                gae[idx]=delta+_wikimyei->__gae_gamma*_wikimyei->__gae_lambda*glti(_wikimyei)->__uwaabo_mask*gae[idx];
                glti(_wikimyei)->__uwaabo_returns[idx]=gae[idx]+glti(_wikimyei)->__munaajpi_state[idx];
                glti(_wikimyei)->__uwaabo_adventage[idx]=glti(_wikimyei)->__uwaabo_returns[idx]-glti(_wikimyei)->__munaajpi_state[idx];
            }
            set_duuruva_value(_wikimyei->__adventage_duuruva, glti(_wikimyei)->__uwaabo_adventage);
            dist_duuruva(_wikimyei->__adventage_duuruva);
        }
    }
    while(load_go_up(_wikimyei)!=-1 && _wikimyei->__load_index<_wikimyei->__load_size-_wikimyei->__horizon_munaajpi-0x01){
        duuruva_normalize(_wikimyei->__adventage_duuruva, glti(_wikimyei)->__uwaabo_adventage);
    }
    load_go_index(_wikimyei, c_index);
    free(gae);
    free(aux);
    free(delta);
}
int jk_rand_index(__wikimyei_t *_wikimyei){
    return rand() % (_wikimyei->__load_size-_wikimyei->__horizon_munaajpi-0x01); // FIXME ¿yes?
}
__cwcn_type_t jk_clamp(__cwcn_type_t d, __cwcn_type_t min, __cwcn_type_t max){
    __cwcn_type_t t = d < min ? min : d;
    return t > max ? max : t;
}
/*

*/
void jkimyei_one(void _wikimyei,
        __cwcn_type_t surr1_handler,
        __cwcn_type_t surr2_handler,
        __cwcn_type_t ratio_handler,
        __cwcn_type_t *old_uwaabo_handler){
    do{
        load_to_index(((__wikimyei_t *)_wikimyei), jk_rand_index(((__wikimyei_t *)_wikimyei)));
    }while(glti(((__wikimyei_t *)_wikimyei))->__pending_munaajpi);
    old_uwaabo_handler=glti(((__wikimyei_t *)_wikimyei))->__uwaabo_state;
    wikimyei_nolive_forward(((__wikimyei_t *)_wikimyei));
    for(unsigned int idx=0x00;idx<((__wikimyei_t *)_wikimyei)->__uawabo_state_size;idx++){
        ratio_handler=exp(log(glti(((__wikimyei_t *)_wikimyei))->__uwaabo_state[idx])-log(old_uwaabo_handler[idx]));
        surr1_handler=ratio_handler*glti(((__wikimyei_t *)_wikimyei))->__uwaabo_adventage[idx];
        surr2_handler=\
            jk_clamp(ratio_handler, \
                0x01-((__wikimyei_t *)_wikimyei)->__clip_param,\
                0x01+((__wikimyei_t *)_wikimyei)->__clip_param)*\
            glti(((__wikimyei_t *)_wikimyei))->__uwaabo_adventage[idx];
        set_wapaajco_index_eq(/
            ((__wikimyei_t *)_wikimyei)->__uwaabo, \
            _wikimyei->__uwaabo_beta*min(surr1_handler,surr2_handler) - \
            _wikimyei->__entropy_beta*_wikimyei->__ec->__entropy, \
            idx);
        set_wapaajco_index_eq(/
        ((__wikimyei_t *)_wikimyei)->__munaajpi, \
            _wikimyei->__munaajpi_beta*pow(glti(_wikimyei)->__uwaabo_returns[idx]-glti(_wikimyei)->__munaajpi_state[idx],2) - \
            _wikimyei->__entropy_beta*_wikimyei->__ec->__entropy, \
        idx);
        jkimyei_tsinuu_bydirectNABLA(((__wikimyei_t *)_wikimyei)->__uwaabo);
        jkimyei_tsinuu_bydirectNABLA(((__wikimyei_t *)_wikimyei)->__munaajpi);
        // print_results(((__wikimyei_t *)_wikimyei)->__uwaabo);
        // print_results(((__wikimyei_t *)_wikimyei)->__munaajpi);
    }
}
void wikimyei_jkimyei(__wikimyei_t *_wikimyei, unsigned int _epochs){ // Asumes load is full
	#ifdef JKIMYEI_DEBUG
		printf(">> request wikimyei_jkimyei");
	#endif
    // int c_index=_wikimyei->__load_index;
	__cwcn_type_t surr1_handler=malloc(sizeof(__cwcn_type_t));
	__cwcn_type_t surr2_handler=malloc(sizeof(__cwcn_type_t));
	__cwcn_type_t ratio_handler=malloc(sizeof(__cwcn_type_t));
	__cwcn_type_t *old_uwaabo_handler=malloc(_wikimyei->__uwaabo_state_size*sizeof(__cwcn_type_t));
    for(unsigned int e_ctx=0x00;e_ctx<_epochs;e_ctx++){
	    GAE(_wikimyei); // #FIXME maybe, ¿changes with epoch? ¿not redundant?
        for(unsigned int l_ctx=0x00;l_ctx<_wikimyei->__load_size;l_ctx++){ // not with while due to rand
            for(unsigned int jk_ctx=0x00;jk_ctx<((__wikimyei_t *)_wikimyei)->__jkimyei->__jk_size;jk_ctx++){
		        _wikimyei->__jkimyei->__jk_one(
                    ((void *)_wikimyei),
                    surr1_handler
                    surr2_handler,
                    ratio_handler,
                    old_uwaabo_handler);
            }
        }
	}
    // load_go_index(_wikimyei,c_index); // #FIXME, might rise to many index displacements, slow.
    free(ratio_handler);
    free(old_uwaabo_handler);
    free(surr1_handler);
    free(surr2_handler);
}


/*

*/
__jkimyei_t *jkimyei_fabric(int _jk_size){ // #FIXME assertme arr[i*M+j] yilds arr[j][j]
    __jkimyei_t *new_jkimyei=malloc(sizeof(__jkimyei_t));
    new_jkimyei->__jk_size=_jk_size;
    // new_jkimyei->__jk_index=-1;
    // new_jkimyei->__jk_batch_head=jk_queue_fabric(new_jkimyei);
    new_jkimyei->__jk_one=&jkimyei_one;
    return new_jkimyei;
}
void jkimyei_destroy(__jkimyei_t *_jkimyei){
    free(_jkimyei);
}