#include "cwcn_jkimyei_nebajke.h"
// #include <stdio.h>
// #include "cwcn_kemu_piaabo.h"
// #include "cwcn_wikimyei_nebajke.h"
// remmemer PMF[a_idx], from I, from the past ¿do we make it?.

void copy_c_cwcn_blocks_from_b_to_a(__cwcn_type_t *_a, __cwcn_type_t *_b, unsigned int _n_blocks){
    for(unsigned int idx=0x00;idx<_n_blocks;idx++){
        _a[idx]=_b[idx];
    }
}
__cwcn_type_t sign_j_fun(__cwcn_type_t x){
    return (__cwcn_type_t)((x > 0) ? 1 : ((x < 0) ? -1 : 0));
}

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
    // assumes __imibajcho_munaajpi_state[0x00] has been computed
    are_munaajpi_pending(_wikimyei);
    #ifdef JKIMYEI_DEBUG
    fprintf(stdout,"%s>> > ... request GAE\n",COLOR_GAE);
    #endif
    assert(_wikimyei->__munaajpi->__jkimyei_uwaabo_munaajpi_state_size==0x01);
    int c_index=_wikimyei->__load_index;
    __cwcn_type_t *delta=malloc(0x01*sizeof(__cwcn_type_t));
    __cwcn_type_t *aux_jums=malloc(0x01*sizeof(__cwcn_type_t));
    __cwcn_type_t *gae=malloc(_wikimyei->__munaajpi->__jkimyei_uwaabo_munaajpi_state_size*sizeof(__cwcn_type_t));

    for(unsigned int idx=0x00;idx<_wikimyei->__munaajpi->__jkimyei_uwaabo_munaajpi_state_size;idx++){gae[0x00]=0x00;}
    load_to_start(_wikimyei);
    do{ // reset trayectory gae variables 
       for(unsigned int idx=0x00;idx<_wikimyei->__munaajpi->__jkimyei_uwaabo_munaajpi_state_size;idx++){
            glti(_wikimyei)->__uwaabo_gae_adventage[idx]=0x00;
            glti(_wikimyei)->__uwaabo_gae_returns[idx]=0x00;
       } 
    }while(load_go_up(_wikimyei)!=-1);
    // load_to_index(_wikimyei, _wikimyei->__load_size-_wikimyei->__horizon_munaajpi); // never reaches the terminal state?
    load_to_end(_wikimyei);
    load_go_up(_wikimyei); // #FIX LOAD GO UP
    do{
        if(!glti(_wikimyei)->__pending_munaajpi){
            aux_jums[0x00]=glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_state[0x00];
            break; // just to capture the first aviable (backward)
        }
    }while(load_go_down(_wikimyei)!=-1);
    assert(load_go_down(_wikimyei)!=-1); // Load is really short problem.
    do{
        if(!glti(_wikimyei)->__pending_munaajpi){
            // #FIXME add mask usage, mask is allways on
            delta[0x00]=glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]+\
                _wikimyei->__gae_gamma*aux_jums[0x00]*glti(_wikimyei)->__uwaabo_mask-\
                glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_state[0x00];
            gae[0x00]=delta[0x00]+\
                _wikimyei->__gae_gamma*_wikimyei->__gae_lambda*glti(_wikimyei)->__uwaabo_mask*\
                gae[0x00];
            glti(_wikimyei)->__uwaabo_gae_returns[0x00]=gae[0x00]+glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_state[0x00]; // #FIXME this sum is redundant, algebra on the full expression to see it; leave it here for graph visualization
            glti(_wikimyei)->__uwaabo_gae_adventage[0x00]=glti(_wikimyei)->__uwaabo_gae_returns[0x00]-glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_state[0x00];
            fprintf(stdout,"%s>> > ... [%d] :: %s uwaabo_gae_adventage: %s%.4f,%s uwaabo_gae_returns: %s%.4f, %s jk_w_munaajpi_state:%s%.4f, %simibajcho_munaajpi: %s%.4f, delta: %.4f, gae: %.4f\n",COLOR_GAE,_wikimyei->__load_index,COLOR_UWAABO,COLOR_REGULAR,glti(_wikimyei)->__uwaabo_gae_adventage[0x00],COLOR_UWAABO,COLOR_REGULAR,glti(_wikimyei)->__uwaabo_gae_returns[0x00],COLOR_MUNAAJPI,COLOR_REGULAR,glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_state[0x00],COLOR_MUNAAJPI,COLOR_REGULAR,glti(_wikimyei)->__imibajcho_munaajpi_state[0x00],delta[0x00],gae[0x00]);
            #ifdef JKIMYEI_DEBUG
            // fprintf(stdout,"%s>> > ... [%d] :: [%d], %s uwaabo_gae_adventage: %s%.4f,%s uwaabo_gae_returns: %s%.4f, %s munaajpi_state:%s%.4f\n",COLOR_GAE,_wikimyei->__load_index,0x00,COLOR_UWAABO,COLOR_REGULAR,glti(_wikimyei)->__uwaabo_gae_adventage[0x00],COLOR_UWAABO,COLOR_REGULAR,glti(_wikimyei)->__uwaabo_gae_returns[0x00],COLOR_MUNAAJPI,COLOR_REGULAR,glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_state[0x00]);
            #endif
            aux_jums[0x00]=glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_state[0x00];
        }
    }while(load_go_down(_wikimyei)!=-1);
    do{
        #if defined(__EXPEND_UWAABO_GAE_RETURNS_DUURUVA__)
        set_duuruva_value(_wikimyei->__wajyu->__metric->__uwaabo_gae_returns_duuruva, glti(_wikimyei)->__uwaabo_gae_returns);
        diff_duuruva(_wikimyei->__wajyu->__metric->__uwaabo_gae_returns_duuruva);
        dist_duuruva(_wikimyei->__wajyu->__metric->__uwaabo_gae_returns_duuruva);
        #endif
        #if defined(__EXPEND_UWAABO_GAE_ADVENTAGE_DUURUVA__)
        set_duuruva_value(_wikimyei->__wajyu->__metric->__uwaabo_gae_adventage_duuruva, glti(_wikimyei)->__uwaabo_gae_adventage);
        diff_duuruva(_wikimyei->__wajyu->__metric->__uwaabo_gae_adventage_duuruva);
        dist_duuruva(_wikimyei->__wajyu->__metric->__uwaabo_gae_adventage_duuruva);
        #endif
        #if defined(__NORM_STAND_DUURUVA_ADVENTAGE__)
        duuruva_normalize(_wikimyei->__wajyu->__metric->__uwaabo_gae_adventage_duuruva, glti(_wikimyei)->__uwaabo_gae_adventage);
        // normalize_duuruva_value(_wikimyei->__wajyu->__metric->__alliu_duuruva);
        #endif
    }while(load_go_up(_wikimyei)!=-1 && _wikimyei->__load_index<_wikimyei->__load_size-_wikimyei->__horizon_munaajpi-0x01);
    load_to_index(_wikimyei, c_index);
    free(gae); // #FIXME might bring upclear memory holes (check here memory overflow)
    free(aux_jums);
    free(delta);
}
int jk_rand_index(__wikimyei_t *_wikimyei){
    return rand() % (_wikimyei->__load_size-_wikimyei->__horizon_munaajpi+0x01); // FIXME ¿yes?
}
__cwcn_type_t jk_clamp(__cwcn_type_t d, __cwcn_type_t min, __cwcn_type_t max){
    __cwcn_type_t t = d < min ? min : d;
    return t > max ? max : t;
}
/*

*/
void jkimyei_one(void *_wikimyei){
    __cwcn_type_t *_uwaabo_loss_handler=malloc(((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_state_size*sizeof(__cwcn_type_t));
    __cwcn_type_t *_munaajpi_loss_handler=malloc(((__wikimyei_t *)_wikimyei)->__munaajpi->__jkimyei_uwaabo_munaajpi_state_size*sizeof(__cwcn_type_t));
    __cwcn_type_t *_entropy_loss_handler=malloc(sizeof(__cwcn_type_t));
    __cwcn_type_t *_old_uwaabo_handler=malloc(((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_state_size*sizeof(__cwcn_type_t));
    __cwcn_type_t *_surr1_handler=malloc(((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_state_size*sizeof(__cwcn_type_t));
    __cwcn_type_t *_surr2_handler=malloc(((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_state_size*sizeof(__cwcn_type_t));
    __cwcn_type_t *_ratio_handler=malloc(((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_state_size*sizeof(__cwcn_type_t));
    __cwcn_type_t pow_aux_arg;
    fprintf(stdout,"%s>> request jkimyei_one, on load index [%d]%s\n",COLOR_JKIMYEI,((__wikimyei_t *)_wikimyei)->__load_index,COLOR_REGULAR);
    #ifdef JKIMYEI_DEBUG
    fprintf(stdout,"%s>> > ... --- --- --- --- --- ---%s ",COLOR_DANGER,COLOR_REGULAR);
    // fprintf(stdout,"%sENTER TO STEP JKIMYEI:%s",COLOR_GOOD,COLOR_REGULAR);
    // getchar();
    fprintf(stdout," %s",COLOR_JKIMYEI);
    #endif
    if(((__wikimyei_t *)_wikimyei)->__load_index%99==0){
        fprintf(stdout,">> jk on load_index: [%d], total_uwaabo_waapajco: %f, total_munaajpi_waapajco:%f\n",\
        ((__wikimyei_t *)_wikimyei)->__load_index,\
        ((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_tsinuu->__wapaajco->__total_wapaajco,
        ((__wikimyei_t *)_wikimyei)->__munaajpi->__munaajpi_tsinuu->__wapaajco->__total_wapaajco);
    }
    /*
        CATCH UWAABO STATE FOR SOME RANDOM INDEX WITH NOT PENDING MUNAAJPI
    */
    copy_c_cwcn_blocks_from_b_to_a(\
        _old_uwaabo_handler, \
        glti(((__wikimyei_t *)_wikimyei))->__uwaabo_state, \
        ((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_state_size);
    #ifdef JKIMYEI_DEBUG
    fprintf(stdout,"%s>> > ... (rand idx: [%d] with imibajcho_munaajpi: %f, start as:) alliu_state: [ ",COLOR_ALLIU,((__wikimyei_t*)_wikimyei)->__load_index,glti(((__wikimyei_t*)_wikimyei))->__imibajcho_munaajpi_state[0x00]);
    for(unsigned int idx=0x00;idx<((__wikimyei_t *)_wikimyei)->__alliu->__source_size;idx++){
        fprintf(stdout," %.4f,",glti((__wikimyei_t *)_wikimyei)->__alliu_state[idx]);
    }
    fprintf(stdout," ]%s\n",COLOR_REGULAR);
    #endif
    /*
        LIVE THE SELECTED (#FIXME not)-RANDOM INDEX
    */
    // glti(_wikimyei)->__pending_munaajpi=___CWCN_TRUE;
    // glti(_wikimyei)->__pending_munaajpi_index=0x00; 
    wikimyei_relive_alliu_one(((__wikimyei_t *)_wikimyei));
    // set_load_pending_munaajpi(((__wikimyei_t *)_wikimyei)); // #FIXME was the constant wuwaabo munaajpi validated nor fix? 
    /*
        -- -- -- 
    */
    // printf("waka : glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]: %f\n",glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]);
    if(is_wajyu_ready(((__wikimyei_t *)_wikimyei)->__wajyu)){
        for(unsigned int idx=0x00;idx<((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_state_size;idx++){
            _ratio_handler[idx]=exp(log(glti(((__wikimyei_t *)_wikimyei))->__uwaabo_state[idx])-log(_old_uwaabo_handler[idx]));
            _surr1_handler[idx]=_ratio_handler[idx]*glti(((__wikimyei_t *)_wikimyei))->__uwaabo_gae_adventage[0x00];
            _surr2_handler[idx]=\
                jk_clamp(_ratio_handler[idx], \
                    0x01-((__wikimyei_t *)_wikimyei)->__clip_param,\
                    0x01+((__wikimyei_t *)_wikimyei)->__clip_param)*\
                glti(((__wikimyei_t *)_wikimyei))->__uwaabo_gae_adventage[0x00];
            // fprintf(stdout,"index: %d, uwaabo beta: %.2f, uwaabo: %.2fm ");
            #ifdef JKIMYEI_DEBUG_v2
            fprintf(stdout,">> > ... ratio[%d]: %.4f, adventage: %.4f\n",idx,_ratio_handler[idx],glti(((__wikimyei_t *)_wikimyei))->__uwaabo_gae_adventage[0x00]);
            fprintf(stdout,"%s",COLOR_JKIMYEI);
            fprintf(stdout,">> > ... uwaabo_index: [%d], value:%f\n",idx,glti(((__wikimyei_t *)_wikimyei))->__uwaabo_state[idx]);
            fprintf(stdout,">> > ... log(uwaabo_state[idx]): %f, log(old_uwaabo): %f\n",log(glti(((__wikimyei_t *)_wikimyei))->__uwaabo_state[idx]),log(_old_uwaabo_handler[idx]));
            fprintf(stdout,">> > ... uwaabo_beta: %.4f, surr1: %.4f, surr2: %.4f\n",((__wikimyei_t *)_wikimyei)->__uwaabo_beta,_surr1_handler[idx],_surr2_handler[idx]);
            fprintf(stdout,">> > ... entropy_beta: %.4f, entropy: %.4f\n",((__wikimyei_t *)_wikimyei)->__entropy_beta,glti(((__wikimyei_t *)_wikimyei))->__entropy_state[0x00]);
            fprintf(stdout,">> > ... uwaabo_gae_returns: %.4f, munaajpi_state: %.4f\n",glti(((__wikimyei_t *)_wikimyei))->__uwaabo_gae_returns[0x00],glti(((__wikimyei_t *)_wikimyei))->__jkimyei_uwaabo_munaajpi_state[0x00]);
            fprintf(stdout,"%s",COLOR_REGULAR);
            #endif
            _entropy_loss_handler[0x00]=((__wikimyei_t *)_wikimyei)->__entropy_beta*glti(((__wikimyei_t *)_wikimyei))->__entropy_state[0x00];
            _uwaabo_loss_handler[idx]=((__wikimyei_t *)_wikimyei)->__uwaabo_beta*min(_surr1_handler[idx],_surr2_handler[idx]) - _entropy_loss_handler[0x00];
            #ifdef JKIMYEI_DEBUG_v2
            fprintf(stdout,"%s>> > ... jkimyei_one: set_uwaabo:\t(uw_beta*min(sur1,sur2)-h_beta*H)%s\n",COLOR_JKIMYEI,COLOR_REGULAR);
            fprintf(stdout,"%s>> > ... jkimyei_one: munaajpi_loss:\t(mjpi_beta*(uw_returns-mjpi_state)^2-h_beta*H)%s\n",COLOR_JKIMYEI,COLOR_REGULAR);
            #endif
            set_wapaajco_index_eq(\
                ((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_tsinuu, \
                _uwaabo_loss_handler[idx], \
                idx);
        }
        // This way the loss is cuadratic but keeps the sign
        pow_aux_arg=glti(((__wikimyei_t *)_wikimyei))->__uwaabo_gae_returns[0x00]-glti(((__wikimyei_t *)_wikimyei))->__jkimyei_uwaabo_munaajpi_state[0x00];
        _munaajpi_loss_handler[0x00]=((__wikimyei_t *)_wikimyei)->__munaajpi_beta*sign_j_fun(pow_aux_arg)*pow(pow_aux_arg,2) - _entropy_loss_handler[0x00];
        // printf("waka: -> munaajpi_loss [%d] : %f\n",0x00,_munaajpi_loss_handler[0x00]);
        set_wapaajco_index_eq(\
        ((__wikimyei_t *)_wikimyei)->__munaajpi->__munaajpi_tsinuu, \
            _munaajpi_loss_handler[0x00],
            0x00);
        // COMPUTE THE UPDATE (by direct nabla, nabla as in grek for gradient)
        jkimyei_tsinuu_bydirectNABLA(((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_tsinuu);
        jkimyei_tsinuu_bydirectNABLA(((__wikimyei_t *)_wikimyei)->__munaajpi->__munaajpi_tsinuu);
        // UPDATE WAJYU
        #if defined(__EXPEND_RATIO_HANDLER_DUURUVA__)
        set_duuruva_value(((__wikimyei_t *)_wikimyei)->__wajyu->__metric->__ratio_handler_duuruva, _ratio_handler);
        diff_duuruva(((__wikimyei_t *)_wikimyei)->__wajyu->__metric->__ratio_handler_duuruva);
        dist_duuruva(((__wikimyei_t *)_wikimyei)->__wajyu->__metric->__ratio_handler_duuruva);
        #endif
        #if defined(__EXPEND_SURR1_HANDLER_DUURUVA__)
        set_duuruva_value(((__wikimyei_t *)_wikimyei)->__wajyu->__metric->__surr1_handler_duuruva, _surr1_handler);
        diff_duuruva(((__wikimyei_t *)_wikimyei)->__wajyu->__metric->__surr1_handler_duuruva);
        dist_duuruva(((__wikimyei_t *)_wikimyei)->__wajyu->__metric->__surr1_handler_duuruva);
        #endif
        #if defined(__EXPEND_SURR2_HANDLER_DUURUVA__)
        set_duuruva_value(((__wikimyei_t *)_wikimyei)->__wajyu->__metric->__surr2_handler_duuruva, _surr2_handler);
        diff_duuruva(((__wikimyei_t *)_wikimyei)->__wajyu->__metric->__surr2_handler_duuruva);
        dist_duuruva(((__wikimyei_t *)_wikimyei)->__wajyu->__metric->__surr2_handler_duuruva);
        #endif
        #if defined(__EXPEND_UWAABO_LOSS_DUURUVA__)
        set_duuruva_value(((__wikimyei_t *)_wikimyei)->__wajyu->__metric->__uwaabo_loss_duuruva, _uwaabo_loss_handler);
        dist_duuruva(((__wikimyei_t *)_wikimyei)->__wajyu->__metric->__uwaabo_loss_duuruva);
        diff_duuruva(((__wikimyei_t *)_wikimyei)->__wajyu->__metric->__uwaabo_loss_duuruva);
        #endif
        #if defined(__EXPEND_JKIMYEI_UWAABO_MUNAAJPI_LOSS_DUURUVA__)
        set_duuruva_value(((__wikimyei_t *)_wikimyei)->__wajyu->__metric->__jkimyei_uwaabo_munaajpi_loss_duuruva, _munaajpi_loss_handler);
        diff_duuruva(((__wikimyei_t *)_wikimyei)->__wajyu->__metric->__jkimyei_uwaabo_munaajpi_loss_duuruva);
        dist_duuruva(((__wikimyei_t *)_wikimyei)->__wajyu->__metric->__jkimyei_uwaabo_munaajpi_loss_duuruva);
        #endif
        // --- --- 
        #ifdef TSINUU_DEBUG
        fprintf(stdout,"%sUWAABO:\n",COLOR_UWAABO);print_tsninuu_jkimyei_results(((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_tsinuu);
        fprintf(stdout,"%sMUNAAJPI:\n",COLOR_MUNAAJPI);print_tsninuu_jkimyei_results(((__wikimyei_t *)_wikimyei)->__munaajpi->__munaajpi_tsinuu);
        #endif
        #ifdef JKIMYEI_DEBUG
        fprintf(stdout,"%s>> > [%d] %simibajcho_munaajpi: %.4f, JKIMYEI LOSSES: %s _entropy_loss: %.4f, \t %s_munaajpi_loss: %.4f%s\t",\
            COLOR_JKIMYEI,((__wikimyei_t *)_wikimyei)->__load_index,\
            COLOR_MUNAAJPI,glti(_wikimyei)->__imibajcho_munaajpi_state[0x00],\
            COLOR_ENTROPY,_entropy_loss_handler[0x00],\
            COLOR_MUNAAJPI,_munaajpi_loss_handler[0x00],\
            COLOR_REGULAR);
        fprintf(stdout,"%s_uwaabo_loss: [",COLOR_UWAABO);
        for(unsigned int idx=0x00;idx<((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_state_size;idx++){fprintf(stdout,"%.4f, ",_uwaabo_loss_handler[idx]);}
        fprintf(stdout,"]%s\n",COLOR_REGULAR);
        fprintf(stdout,">> > jkimyei_one, jkimyei ready for load index %d\n",((__wikimyei_t *)_wikimyei)->__load_index);
        #endif
        // RESET HANDLERS // #FIXME trust it, there is on need to reset
        for(unsigned int idx=0x00;idx<((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_state_size;idx++){
            if(fabs(_uwaabo_loss_handler[idx])>1){
                fprintf(stdout,"%suwaabo too high%s\n",COLOR_DANGER,COLOR_REGULAR);
                getchar();
            }
            _uwaabo_loss_handler[idx]=0x00;
            _ratio_handler[idx]=0x00;
            _surr1_handler[idx]=0x00;
            _surr2_handler[idx]=0x00;
        }
        _munaajpi_loss_handler[0x00]=0x00;
        _entropy_loss_handler[0x00]=0x00;
    }else{
        #ifdef JKIMYEI_DEBUG
        fprintf(stdout,">> > jkimyei_one, skip jkimyei; wajyu not ready, load index %d\n",((__wikimyei_t *)_wikimyei)->__load_index);
        #endif
    }
    #ifdef JKIMYEI_DEBUG
        fprintf(stdout,"%s",COLOR_REGULAR);
    #endif
    free(_surr1_handler);
    free(_surr2_handler);
    free(_ratio_handler);
    free(_old_uwaabo_handler);
    free(_uwaabo_loss_handler);
    free(_munaajpi_loss_handler);
    free(_entropy_loss_handler);
}
/*
    JKIMYEI (jk)

        JK_return means the flag state for more aviable elements for jk over the whole load.
*/
/*
    LOAD NEXT
*/
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_NEXT(__wikimyei_t *_wikimyei){
    fprintf(stdout, "___JK_COMPUTE_FOR_AVIABLE_NEXT\n");
    ___cwcn_bool_t jk_noBreak_flag_aux_2=load_go_up(_wikimyei)!=-1;
    ___cwcn_bool_t jk_noBreak_flag_aux_1=___JK_ONE_JK_SIZE_WRAPPER(_wikimyei);
    return jk_noBreak_flag_aux_1 && jk_noBreak_flag_aux_2;
}
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_NEXT_POSITIVE(__wikimyei_t *_wikimyei){
    fprintf(stdout, "___JK_COMPUTE_FOR_AVIABLE_NEXT_POSITIVE\n");
    ___cwcn_bool_t jk_noBreak_flag_aux_1=___CWCN_FALSE;
    ___cwcn_bool_t jk_noBreak_flag_aux_2=___CWCN_FALSE;
    do{jk_noBreak_flag_aux_2=(load_go_up(_wikimyei)!=-1);
    }while(glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]<0x00 && jk_noBreak_flag_aux_2);
    if(!jk_noBreak_flag_aux_2){jk_noBreak_flag_aux_1=___JK_ONE_JK_SIZE_WRAPPER(_wikimyei);}
    return jk_noBreak_flag_aux_1 && jk_noBreak_flag_aux_2;
}
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_NEXT_NEGATIVE(__wikimyei_t *_wikimyei){
    fprintf(stdout, "___JK_COMPUTE_FOR_AVIABLE_NEXT_NEGATIVE\n");
    ___cwcn_bool_t jk_noBreak_flag_aux_1=___CWCN_FALSE;
    ___cwcn_bool_t jk_noBreak_flag_aux_2=___CWCN_FALSE;
    do{jk_noBreak_flag_aux_2=(load_go_up(_wikimyei)!=-1);
    }while(glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]>0x00 && jk_noBreak_flag_aux_2);
    if(!jk_noBreak_flag_aux_2){jk_noBreak_flag_aux_1=___JK_ONE_JK_SIZE_WRAPPER(_wikimyei);}
    return jk_noBreak_flag_aux_1 && jk_noBreak_flag_aux_2;
}
/*
    LOAD PAST
*/
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_PAST(__wikimyei_t *_wikimyei){
    fprintf(stdout, "___JK_COMPUTE_FOR_AVIABLE_PAST\n");
    ___cwcn_bool_t jk_noBreak_flag_aux_2=load_go_down(_wikimyei)!=-1;
    ___cwcn_bool_t jk_noBreak_flag_aux_1=___JK_ONE_JK_SIZE_WRAPPER(_wikimyei);
    return jk_noBreak_flag_aux_1 && jk_noBreak_flag_aux_2;
}
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_PAST_POSITIVE(__wikimyei_t *_wikimyei){
    ___cwcn_bool_t jk_noBreak_flag_aux_1=___CWCN_FALSE;
    ___cwcn_bool_t jk_noBreak_flag_aux_2=___CWCN_FALSE;
    do{jk_noBreak_flag_aux_2=(load_go_down(_wikimyei)!=-1);
    }while(glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]<0x00 && jk_noBreak_flag_aux_2);
    if(!jk_noBreak_flag_aux_2){jk_noBreak_flag_aux_1=___JK_ONE_JK_SIZE_WRAPPER(_wikimyei);}
    return jk_noBreak_flag_aux_1 && jk_noBreak_flag_aux_2;
}
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_PAST_NEGATIVE(__wikimyei_t *_wikimyei){
    fprintf(stdout, "___JK_COMPUTE_FOR_AVIABLE_PAST_NEGATIVE\n");
    ___cwcn_bool_t jk_noBreak_flag_aux_1=___CWCN_FALSE;
    ___cwcn_bool_t jk_noBreak_flag_aux_2=___CWCN_FALSE;
    do{jk_noBreak_flag_aux_2=(load_go_down(_wikimyei)!=-1);
    }while(glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]>0x00 && jk_noBreak_flag_aux_2);
    if(!jk_noBreak_flag_aux_2){jk_noBreak_flag_aux_1=___JK_ONE_JK_SIZE_WRAPPER(_wikimyei);}
    return jk_noBreak_flag_aux_1 && jk_noBreak_flag_aux_2;
}
/*
    RANDOM
*/
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_RANDOM(__wikimyei_t *_wikimyei){// #FIXME assert jk_rand_index gives valid values
    fprintf(stdout, "___JK_COMPUTE_FOR_AVIABLE_RANDOM\n");
    load_to_index(_wikimyei, jk_rand_index(_wikimyei));
    ___cwcn_bool_t jk_noBreak_flag_aux_1=___JK_ONE_JK_SIZE_WRAPPER(_wikimyei);
    return jk_noBreak_flag_aux_1;
}
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_RANDOM_POSITIVE(__wikimyei_t *_wikimyei){
    fprintf(stdout, "___JK_COMPUTE_FOR_AVIABLE_RANDOM_POSITIVE\n");
    unsigned int c_break_counter_c=0x00;
    ___cwcn_bool_t jk_noBreak_flag_aux_1=___CWCN_TRUE;
    do{c_break_counter_c++;
        if(c_break_counter_c>_JK_BREAK_COUNTER_){
            fprintf(stderr,"\n\n\t\t%s[_JK_BREAK_COUNTER_ INTERRUPT] : unable to find aviable random positive.%s\n\n",COLOR_DANGER,COLOR_REGULAR);
            jk_noBreak_flag_aux_1=___CWCN_FALSE;
            break;
        }
        load_to_index(_wikimyei, jk_rand_index(_wikimyei));
    }while(glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]<0x00);
    if(jk_noBreak_flag_aux_1){jk_noBreak_flag_aux_1=___JK_ONE_JK_SIZE_WRAPPER(_wikimyei);}
    return jk_noBreak_flag_aux_1;
}
___cwcn_bool_t ___JK_COMPUTE_FOR_AVIABLE_RANDOM_NEGATIVE(__wikimyei_t *_wikimyei){
    fprintf(stdout, "___JK_COMPUTE_FOR_AVIABLE_RANDOM_NEGATIVE\n");
    unsigned int c_break_counter_c=0x00;
    ___cwcn_bool_t jk_noBreak_flag_aux_1=___CWCN_TRUE;
    do{c_break_counter_c++;
        if(c_break_counter_c>_JK_BREAK_COUNTER_){
            fprintf(stderr,"\n\n\t\t%s[_JK_BREAK_COUNTER_ INTERRUPT] : unable to find aviable random negative.%s\n\n",COLOR_DANGER,COLOR_REGULAR);
            jk_noBreak_flag_aux_1=___CWCN_FALSE;
            break;
        }
        load_to_index(_wikimyei, jk_rand_index(_wikimyei));
    }while(glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]>0x00);
    if(jk_noBreak_flag_aux_1){jk_noBreak_flag_aux_1=___JK_ONE_JK_SIZE_WRAPPER(_wikimyei);}
    return jk_noBreak_flag_aux_1;
}

/*
    WRAPPERS
*/
___cwcn_bool_t ___JK_ONE_JK_SIZE_WRAPPER(__wikimyei_t *_wikimyei){
    if(!glti(_wikimyei)->__pending_munaajpi && \
        (_wikimyei->__load_size-_wikimyei->__load_index)>(_wikimyei->__horizon_munaajpi+0x01)){
        for(unsigned int jk_ctx=0x00;jk_ctx<((__wikimyei_t *)_wikimyei)->__jkimyei->__jk_size;jk_ctx++){
            _wikimyei->__jkimyei->__jk_one(((void *)_wikimyei));
        }
    }
    return ___CWCN_TRUE; // allways aviable
}
___cwcn_bool_t ___JK_ONE_JK_COMPUTE_MULTIPLEXER_WRAPPER(__wikimyei_t *_wikimyei, __list_jk_load_method_t _jk_load_method){
    ___cwcn_bool_t jk_noBreak_flag_m=___CWCN_FALSE;
    switch(_jk_load_method){
        case JK_LOAD_AVIABLE_NEXT:  jk_noBreak_flag_m=___JK_COMPUTE_FOR_AVIABLE_NEXT(_wikimyei);break;
        case JK_LOAD_AVIABLE_NEXT_POSITIVE:jk_noBreak_flag_m=___JK_COMPUTE_FOR_AVIABLE_NEXT_POSITIVE(_wikimyei);break;
        case JK_LOAD_AVIABLE_NEXT_NEGATIVE:jk_noBreak_flag_m=___JK_COMPUTE_FOR_AVIABLE_NEXT_NEGATIVE(_wikimyei);break;
        case JK_LOAD_AVIABLE_PAST:jk_noBreak_flag_m=___JK_COMPUTE_FOR_AVIABLE_PAST(_wikimyei);break;
        case JK_LOAD_AVIABLE_PAST_POSITIVE:jk_noBreak_flag_m=___JK_COMPUTE_FOR_AVIABLE_PAST_POSITIVE(_wikimyei);break;
        case JK_LOAD_AVIABLE_PAST_NEGATIVE:jk_noBreak_flag_m=___JK_COMPUTE_FOR_AVIABLE_PAST_NEGATIVE(_wikimyei);break;
        case JK_LOAD_AVIABLE_RANDOM:jk_noBreak_flag_m=___JK_COMPUTE_FOR_AVIABLE_RANDOM(_wikimyei);break;
        case JK_LOAD_AVIABLE_RANDOM_POSITIVE:jk_noBreak_flag_m=___JK_COMPUTE_FOR_AVIABLE_RANDOM_POSITIVE(_wikimyei);break;
        case JK_LOAD_AVIABLE_RANDOM_NEGATIVE:jk_noBreak_flag_m=___JK_COMPUTE_FOR_AVIABLE_RANDOM_NEGATIVE(_wikimyei);break;
        default:
            fprintf(stderr,">> ERROR, encounter unknown <_jk_load_method> on <__JK_ONE_JK_MULTIPLEXER_WRAPPER>\n\n");
            assert(0x00);
            break;
    }
    return jk_noBreak_flag_m;

}
void ___JK_EPOCH_JK_METHOD_MULTIPLEXER_WRAPPER(__wikimyei_t *_wikimyei, __list_jk_method_t _jk_method){
    // This method operates over all epoch
    unsigned int l_ctx_e=0x00;
    ___cwcn_bool_t c_noBreak_flag_e=0x00;
    switch(_jk_method){
        case JK_METHOD_FORWARD_SEQUENTAL: // training is done in a forward sequential manner, as if it where reliving the network
            load_to_start(_wikimyei);
            do{if(l_ctx_e>_wikimyei->__load_size){break;}else{l_ctx_e++;}
            }while(___JK_ONE_JK_COMPUTE_MULTIPLEXER_WRAPPER(_wikimyei,\
            JK_LOAD_AVIABLE_NEXT));
            break;
        case JK_METHOD_RANDOM: // training is done by random sampling
            do{if(l_ctx_e>_wikimyei->__load_size){break;}else{l_ctx_e++;}
            }while(___JK_ONE_JK_COMPUTE_MULTIPLEXER_WRAPPER(_wikimyei,\
            JK_LOAD_AVIABLE_RANDOM));
            break;
        case JK_METHOD_RANDOM_POSITIVE: // training is done on random sampling of positive imibajcho_munaajpi, 
            do{if(l_ctx_e>_wikimyei->__load_size){break;}else{l_ctx_e++;}
            }while(___JK_ONE_JK_COMPUTE_MULTIPLEXER_WRAPPER(_wikimyei,\
            JK_LOAD_AVIABLE_RANDOM_POSITIVE));
            break;
        case JK_METHOD_RANDOM_NEGATIVE: // training is done on random sampling of positive imibajcho_munaajpi, 
            do{if(l_ctx_e>_wikimyei->__load_size){break;}else{l_ctx_e++;}
            }while(___JK_ONE_JK_COMPUTE_MULTIPLEXER_WRAPPER(_wikimyei,\
            JK_LOAD_AVIABLE_RANDOM_NEGATIVE));
            break;
        case JK_METHOD_RANDOM_2_POSITIVE_1_NEGATIVE:
            do{
                if(l_ctx_e%3!=0)    {   c_noBreak_flag_e=___JK_ONE_JK_COMPUTE_MULTIPLEXER_WRAPPER(_wikimyei,JK_LOAD_AVIABLE_RANDOM_POSITIVE);}
                else                {   c_noBreak_flag_e=___JK_ONE_JK_COMPUTE_MULTIPLEXER_WRAPPER(_wikimyei,JK_LOAD_AVIABLE_RANDOM_NEGATIVE);}
                if(l_ctx_e>_wikimyei->__load_size){break;}else{l_ctx_e++;}
            }while(c_noBreak_flag_e);
            break;
        case JK_METHOD_RANDOM_3_POSITIVE_1_NEGATIVE:
            do{
                if(l_ctx_e%4!=0)    {   c_noBreak_flag_e=___JK_ONE_JK_COMPUTE_MULTIPLEXER_WRAPPER(_wikimyei,JK_LOAD_AVIABLE_RANDOM_POSITIVE);}
                else                {   c_noBreak_flag_e=___JK_ONE_JK_COMPUTE_MULTIPLEXER_WRAPPER(_wikimyei,JK_LOAD_AVIABLE_RANDOM_NEGATIVE);}
                if(l_ctx_e>_wikimyei->__load_size){break;}else{l_ctx_e++;}
            }while(c_noBreak_flag_e);
            break;
        default:
            fprintf(stderr, ">> ERROR, encounter unknown <__list_jk_method_t> in <wikimyei_jkimyei>\n\n");
            assert(0x00);
            break;
    }
}
/*
        JKIMYEI THE WIKIMYEI
*/
void wikimyei_jkimyei(__wikimyei_t *_wikimyei, unsigned int _epochs, __list_jk_method_t _jk_method){ // Asumes load is full
    // #FIXME add breaks for infinite loops when searching for load item
	#ifdef JKIMYEI_DEBUG
	fprintf(stdout,">> request wikimyei_jkimyei\n");
	#endif
    // int c_index=_wikimyei->__load_index;
    for(unsigned int e_ctx=0x00;e_ctx<_epochs;e_ctx++){
        fprintf(stdout,"%s>> > ... --- --- --- --- --- --- EPOCH : [%d] %s - JK_METHOD : [%d]\n",COLOR_DANGER,e_ctx,COLOR_REGULAR,_jk_method);
        if(_wikimyei->__load_size<_wikimyei->__horizon_munaajpi){fprintf(stdout,">> > ... [WARNING] [skipin] wikimyei_jkimyei, load size is too small, for horizon munaajpi.\n");}
        GAE(_wikimyei); // #FIXME maybe, ¿changes with epoch? ¿not redundant? ¿aint it the same for every epoch?
        ___JK_EPOCH_JK_METHOD_MULTIPLEXER_WRAPPER(_wikimyei, _jk_method);
    }
    // load_to_index(_wikimyei,c_index); // #FIXME, might rise to many index displacements, slow.
    // #FIXME train on random iter
    // #FIXME 
}
/*

*/
__jkimyei_t *jkimyei_fabric(unsigned int _jk_size){ // #FIXME assertme arr[i*M+j] yilds arr[j][j]
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