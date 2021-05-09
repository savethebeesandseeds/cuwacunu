#include "wikimyei.config.h"
#include "cwcn_jkimyei_piaabo.h"
// #include <stdio.h>
// #include "cwcn_kemu_piaabo.h"
// #include "cwcn_wikimyei_nebajke.h"
// remmemer PMF[a_idx], from I, from the past ¿do we make it?.

__jk_queue_t *jk_queue_fabric(__jkimyei_t *__jkimyei){
    __jk_queue_t *new_jk_queue=malloc(sizeof(__jk_queue_t));
    new_jk_queue->__trayectory_item=NULL;
    new_jk_queue->__next=NULL;
    return new_jk_queue;
}
__jkimyei_t *jkimyei_fabric(int _jk_size){ // #FIXME assertme arr[i*M+j] yilds arr[j][j]
    __jkimyei_t *new_jkimyei=malloc(sizeof(__jkimyei_t));
    new_jkimyei->__jk_size=_jk_size;
    new_jkimyei->__jk_index=-1;
    new_jkimyei->__jk_batch_head=jk_queue_fabric(new_jkimyei);
    return new_jkimyei;
}
/*
    QUEUE
*/
void jk_enqueue_trayectory(__jkimyei_t *_jkimyei, __trayectory_t *_new_trayectory){

    // if(_jkimyei->__jk_batch_head==NULL){
    //     fprintf(stderr, ">>>> ERROR: jk_enqueue_trayectory head pointer is NULL\n");
    //     assert(0x00);
    // }
    __jk_queue_t *new_head=malloc(sizeof(__jk_queue_t));
    if(!new_head){
        fprintf(stderr, ">>>> ERROR: jk_enqueue_trayectory failed to enqueue\n");
        assert(0x00);
    }
    new_head->__trayectory_item=_new_trayectory;
    new_head->__next=_jkimyei->__jk_batch_head;
    _jkimyei->__jk_batch_head=new_head;
    _jkimyei->__jk_index+=0x01;
    fprintf(stdout, "\t [jk]_enqueue_trayectory -- jk item index [%d]\n", _jkimyei->__jk_index);
}
void jk_enqueue_trayectory_index(__wikimyei_t *_wikimyei, int _index, ___cwcn_bool_t _rneturn){
    jk_enqueue_trayectory(_wikimyei->__jkimyei, get_load_trayectory_item_from_index(_wikimyei, _index, _rneturn));
    fprintf(stdout, "\t [jk]_enqueue_trayectory_index -- load item index [%d]\n", _index);
}
__trayectory_t *jk_dequeue_trayectory(__jkimyei_t *_jkimyei){
    if(_jkimyei->__jk_batch_head==NULL || _jkimyei->__jk_index<0){return NULL;}
    fprintf(stdout, "\t [jk]_dequeue_trayectory -- jk item index [%d]\n", _jkimyei->__jk_index);
    __trayectory_t *retval=NULL;
    __jk_queue_t *c_current=_jkimyei->__jk_batch_head;
    retval=c_current->__trayectory_item;
    _jkimyei->__jk_batch_head=_jkimyei->__jk_batch_head->__next;
    _jkimyei->__jk_index-=0x01;
    return retval;
}
void jk_print_trayectory_queue(__jkimyei_t *_jkimyei){
    fprintf(stdout, ">> [jk]_print_trayectory_queue\n");
    __jk_queue_t *c_current=_jkimyei->__jk_batch_head;
	if(!(c_current != NULL && c_current->__trayectory_item!=NULL)){
        fprintf(stdout, "\t [jk]: jk queue is empty...\n");
	}
    while(c_current != NULL && c_current->__trayectory_item!=NULL){
        fprintf(stdout, "\t [jk]: jk index [%d] FIRST_STATE: %9.2f\n", _jkimyei->__jk_index, c_current->__trayectory_item->__uwaabo_base[0x00]);
        c_current=c_current->__next;
    }
}
__trayectory_t *jk_get_trayectory_item(__jkimyei_t *_jkimyei){
    return _jkimyei->__jk_batch_head->__trayectory_item;
}
/*

*/
void jkimyei_destroy(__jkimyei_t *_jkimyei){
    free(_jkimyei);
}
/*

*/

/*


*/
void release_jk(__wikimyei_t *_wikimyei){
	fprintf(stdout,">> release_[jk]\n");
	while(jk_dequeue_trayectory(_wikimyei->__jkimyei)!=NULL){}
	assert(_wikimyei->__jkimyei->__jk_index==-1);
}
void fill_jk_rand(__wikimyei_t *_wikimyei){ // map __load in a random manner to fill __jk
	fprintf(stdout,">> fill_[jk]_rand\n");
	int rand_idx;
	__jkimyei_t *c_jkimyei=_wikimyei->__jkimyei;
	if(!(c_jkimyei->__jk_index<c_jkimyei->__jk_size)){
		fprintf(stderr,">>> WARNING: __jk_queue is fully loaded on request.");
	}
	while(c_jkimyei->__jk_index<c_jkimyei->__jk_size-0x01){
		rand_idx=rand() % _wikimyei->__load_size;
		jk_enqueue_trayectory_index(_wikimyei, rand_idx, 0x0);
	}
	// 	for(unsigned int idx_2=0x00;idx_2<abs(rand_idx);idx_2++){
	// 		if(rand_idx<0){
	// 			load_go_down(_jkimyei);
	// 		} else {
	// 			load_go_up(_jkimyei);
	// 		}
	// 	jk_enqueue_trayectory(_jkimyei,load_get_trayectory_item(_jkimyei));
	// 	// for(unsigned int itm_x=0x00; itm_x < _jkimyei->__num_states; itm_x++){
	// 	// 	_states_handler[idx][itm_x] 	= _states[rand_idx][itm_x];
	// 	// }
	// 	// for(unsigned int itm_x=0x00; itm_x < NUM_RETURNS; itm_x++){
	// 	// 	_returns_handler[idx][itm_x] 	= _returns[rand_idx][itm_x];
	// 	// }
	// 	// for(unsigned int itm_x=0x00; itm_x < NUM_ACTIONS; itm_x++){
	// 	// 	jk_get_trayectory_item(__jkimyei)->__tsane[idx][itm_x] 	= _actions[rand_idx][itm_x];
	// 	// 	_jk_get_trayectory_item(_jkmiyei)->__tsane_log_prob[idx][itm_x] 	= _log_probs[rand_idx][itm_x];
	// 	// 	__jkimyei->__uwaabo_adventage[idx][itm_x] 	= _adventage[rand_idx][itm_x];
	// 	// }
	// }
}
// void jkimyei_wikimyei(
// 	__cwcn_type_t _states[BATCH_SIZE][NUM_STATES], 
// 	__cwcn_type_t _actions[BATCH_SIZE][NUM_ACTIONS],
// 	__cwcn_type_t _log_probs[BATCH_SIZE][NUM_ACTIONS],
// 	__cwcn_type_t _returns[BATCH_SIZE][NUM_RETURNS],
// 	__cwcn_type_t _adventage[BATCH_SIZE][NUM_ACTIONS]){
// 		fprintf(stdout, ">> skwstr_jkimyei_wikimyei");
// 		__cwcn_type_t ratio_handler;
// 		__cwcn_type_t surr1_handler;
// 		__cwcn_type_t surr2_handler;
// 		__cwcn_type_t loss_handler[NUM_ACTIONS];
// 		__cwcn_type_t actor_loss_handler[NUM_ACTIONS];
// 		__cwcn_type_t munaajpi_loss_handler[NUM_ACTIONS];
// 		__cwcn_type_t old_jk_get_trayectory_item(_jkmiyei)->__tsane_log_prob[NUM_ACTIONS];
// 		__cwcn_type_t new_jk_get_trayectory_item(_jkmiyei)->__tsane_log_prob[NUM_ACTIONS];

// 		__cwcn_type_t states_handler[MINI_BATCH_SIZE][NUM_STATES];
// 		__cwcn_type_t jk_get_trayectory_item(_jkimyei)->__tsane[MINI_BATCH_SIZE][NUM_ACTIONS];
// 		__cwcn_type_t jk_get_trayectory_item(_jkmiyei)->__tsane_log_prob[MINI_BATCH_SIZE][NUM_ACTIONS];
// 		__cwcn_type_t returns_handler[MINI_BATCH_SIZE][NUM_RETURNS];
// 		__cwcn_type_t _jkimyei->__uwaabo_adventage[MINI_BATCH_SIZE][NUM_ACTIONS];

// 		__cwcn_type_t ujcamei_handler[NUM_UJCAMEI];
// 		__cwcn_type_t cajtucu_handler[NUM_CAJTUCU];
// 		for(int train_step=0; train_step<BATCH_SIZE/MINI_BATCH_SIZE; train_step++){
// 			// PPO iterator
// 			jkimyei_iter(
// 				states, 
// 				actions, 
// 				log_probs, 
// 				returns,
// 				adventage,
// 				states_handler,
// 				jk_get_trayectory_item(_jkimyei)->__tsane, 
// 				jk_get_trayectory_item(_jkmiyei)->__tsane_log_prob, 
// 				returns_handler,
// 				_jkimyei->__uwaabo_adventage);
// 			// propagate trought network
// 			for(int b_step=0; b_step<MINI_BATCH_SIZE; b_step++){
// 				cwcn_hash_cognitive(states_handler[b_step], ujcamei_handler);
// 				cwcn_net_uwaabo(ujcamei_handler, cajtucu_handler);
// 				cwcn_dehash_cognitive(cajtucu_handler, jk_get_trayectory_item(_jkimyei)->__tsane);
// 				for(int a_idx=0;a_idx<NUM_ACTIONS;a_idx++){
// 					// new_action was old action in skwstr job, check this... #FIXME?
// 					ratio_handler=exp(log(jk_get_trayectory_item(_jkimyei)->__tsane[a_idx]) - jk_get_trayectory_item(_jkmiyei)->__tsane_log_prob[a_idx]);
// 					surr1_handler=ratio_handler * _jkimyei->__uwaabo_adventage[b_step][a_idx];
// 					surr2_handler=clamp(ratio_handler, 1.0 - PPO_EPSILON, 1.0 + _jkimyei->__uwaabo_adventage[b_step][a_idx]);
// 					actor_loss_handler[a_idx]=- min(surr1_handler, surr2_handler);
// 					// munaajpi_loss_handler[a_idx]=pow(return_ - value, 2);
// 					// // train the network! aja!
// 				}
// 			}
			
// 		}
// 	}


void wikimyei_jkimyei(__wikimyei_t *_wikimyei){
	#ifdef JKIMYEI_DEBUG
		printf(">> request wikimyei_jkimyei");
	#endif
	// __cwcn_type_t ratio_handler;
	// __cwcn_type_t surr1_handler;
	// __cwcn_type_t surr2_handler;
	
	// __cwcn_type_t *loss_handler=malloc(NUM_ACTIONS*sizeof(__cwcn_type_t));
	// __cwcn_type_t *munaajpi_loss_handler=malloc(NUM_ACTIONS*sizeof(__cwcn_type_t));
	// __cwcn_type_t *actor_loss_handler=malloc(NUM_ACTIONS*sizeof(__cwcn_type_t));
	// __cwcn_type_t *old_jk_get_trayectory_item(_jkmiyei)->__tsane_log_prob=malloc(NUM_ACTIONS*sizeof(__cwcn_type_t));
	// __cwcn_type_t *new_jk_get_trayectory_item(_jkmiyei)->__tsane_log_prob=malloc(NUM_ACTIONS*sizeof(__cwcn_type_t));

	// __cwcn_type_t *states_handler=malloc(MINI_BATCH_SIZE*NUM_STATES*sizeof(__cwcn_type_t));
	// __cwcn_type_t *jk_get_trayectory_item(_jkimyei)->__tsane=malloc(MINI_BATCH_SIZE*NUM_ACTIONS*sizeof(__cwcn_type_t));
	// __cwcn_type_t *jk_get_trayectory_item(_jkmiyei)->__tsane_log_prob=malloc(MINI_BATCH_SIZE*NUM_ACTIONS*sizeof(__cwcn_type_t));
	// __cwcn_type_t *returns_handler=malloc(MINI_BATCH_SIZE*NUM_RETURNS*sizeof(__cwcn_type_t));
	// __cwcn_type_t *_jkimyei->__uwaabo_adventage=malloc(MINI_BATCH_SIZE*NUM_ACTIONS*sizeof(__cwcn_type_t));

	// __cwcn_type_t *ujcamei_handler=malloc(NUM_UJCAMEI*sizeof(__cwcn_type_t)); // #FIXME what?
	// __cwcn_type_t *cajtucu_handler=malloc(NUM_CAJTUCU*sizeof(__cwcn_type_t)); // #FIXME what?
	
	// assert(_wikimyei->__load_size%_wikimyei->__jkimyei->__jk_size==0);

	// load_iter(_jkimyei);
	// for(unsigned int train_step=0; train_step<_jkimyei->__load_size/_jkimyei->__jk_size; train_step++){
	// 	jk_iter(_jkimyei);
	// 	for(unsigned int idx_jk=0; idx_jk<_jkimyei->__jk_size; idx_jk++){
	// 		// propagate trought network
	// 		___alliu_hash(_jkimyei);
	// 		___duuruva_hash(_jkimyei);
	// 		___uwaabo_hash(_jkimyei);
	// 		___entropy_hash(_jkimyei);
	// 		___munaajpi_hash(_jkimyei);
	// 		___tsane_dehash(_jkimyei, 0x00);
	// 		/*forward(__wikimyei,_jk_flag=true) */
	// 		for(unsigned int a_idx=0;a_idx<_jkimyei->__tsane_size;a_idx++){
	// 			// new_action was old action in skwstr job, check this... #FIXME?
	// 			ratio_handler=exp(log(jk_get_trayectory_item(_jkimyei)->__tsane[a_idx]) - jk_get_trayectory_item(_jkmiyei)->__tsane_log_prob[a_idx]);
	// 			surr1_handler=ratio_handler * jk_get_trayectory_item(_jkimyei)->__uwaabo_adventage;
	// 			surr2_handler=clamp(ratio_handler, 1.0 - PPO_EPSILON, 1.0 + jk_get_trayectory_item(_jkimyei)->__uwaabo_adventage);
	// 			_jkimyei->__uwaabo_loss[a_idx]=- min(surr1_handler, surr2_handler);
	// 			_jkimyei->__munaajpi_loss[a_idx]=pow(return_ - value, 2);
	// 			// // train the network! aja!
	// 		}
	// 		set_wapaajco(_jkimyei->__uwaabo_tsinuu, _jkimyei->__uwaabo_loss);
	// 		set_wapaajco(_jkimyei->__munaajpi_tsinuu, _jkimyei->__munaajpi_loss);
	// 		jkimyei_tsinuu_bydirectNABLA(c_tsinuu);
	// 		print_results(c_tsinuu);
	// 	}
	// }
	// print_all_lines(c_tsinuu);
    // print_all_nodes(c_tsinuu);
	// // free(loss_handler);
	// // free(munaajpi_loss_handler);
	// // free(old_jk_get_trayectory_item(_jkmiyei)->__tsane_log_prob);
	// free(new_jk_get_trayectory_item(_jkmiyei)->__tsane_log_prob);
	// free(states_handler);
	// free(jk_get_trayectory_item(_jkimyei)->__tsane);
	// free(jk_get_trayectory_item(_jkmiyei)->__tsane_log_prob);
	// free(returns_handler);
	// free(_jkimyei->__uwaabo_adventage);
	// free(ujcamei_handler);
	// free(cajtucu_handler);
	// free(_load_batch);
	// free(actor_loss_handler);
	// (fixmenot) #FIXME? (clearing the buffer is not part of jkimyei_wikimyei) remove the proceed queue elements

	// #FIXME free inmortal and mortal queues
}
