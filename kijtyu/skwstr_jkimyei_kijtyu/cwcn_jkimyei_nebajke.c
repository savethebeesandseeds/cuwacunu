#include <stdio.h>
#include "cwcn_security.h"
#include "cwcn_kemu_piaabo.h"
#include "cwcn_ppo_nebajke.h"
#include "cwcn_net_nebajke.h"
#include "cwcn_wikimyei_nebajke.h"
// remmemer PMF[a_idx], from I, from the past ¿do we make it?.
___uwaabo_hash(__jkimyei_t *_jkimyei){
	_jkimyei->__uwaabo_tsinuu;
    
}
___munaajpi_hash(){
	_jkimyei->__munaajpi_tsinuu;

}

void jkimyei_iter(
	__jkimyei_t *_jkimyei){
	// // __cwcn_type_t _states[BATCH_SIZE][NUM_STATES], 
	// // __cwcn_type_t _actions[BATCH_SIZE][NUM_ACTIONS],
	// // __cwcn_type_t _log_probs[BATCH_SIZE][NUM_ACTIONS], 
	// // __cwcn_type_t _returns[BATCH_SIZE][NUM_RETURNS],
	// // __cwcn_type_t _adventage[BATCH_SIZE][NUM_ACTIONS],
	// __cwcn_type_t *_states_handler,
	// __cwcn_type_t *_actions_handler,
	// __cwcn_type_t *_log_probs_handler,
	// __cwcn_type_t *_returns_handler,
	// __cwcn_type_t *_adventage_handler
	printf(">> request jkimyei_iter\n");
	int rand_idx;
	for(unsigned int idx=0x00;idx<_jkimyei->_jk_size;idx++){
		rand_idx = rand() % (_jkimyei->_load_size - _jkimyei->_load_count) - rand() % (_jkimyei->_load_count);
		for(unsigned int idx_2=0x00;idx_2<abs(rand_idx);idx_2++){
			if(rand_idx<0){
				load_go_down(_jkimyei);
			}
			 else {
				load_go_up(_jkimyei);
			}
		}
		_jk_batch[idx]=enqueue_trayectory(_jkimyei,_jkimyei->__load_batch_head);
		_jk_batch = enqueue_trayectory();
		retrival_down_load_trayectory(__jkimyei_t *_jkimyei);
		retrival_up_load_trayectory(__jkimyei_t *_jkimyei);
		// for(unsigned int itm_x=0x00; itm_x < _jkimyei->__num_states; itm_x++){
		// 	_states_handler[idx][itm_x] 	= _states[rand_idx][itm_x];
		// }
		// for(unsigned int itm_x=0x00; itm_x < NUM_RETURNS; itm_x++){
		// 	_returns_handler[idx][itm_x] 	= _returns[rand_idx][itm_x];
		// }
		// for(unsigned int itm_x=0x00; itm_x < NUM_ACTIONS; itm_x++){
		// 	_actions_handler[idx][itm_x] 	= _actions[rand_idx][itm_x];
		// 	_log_probs_handler[idx][itm_x] 	= _log_probs[rand_idx][itm_x];
		// 	_adventage_handler[idx][itm_x] 	= _adventage[rand_idx][itm_x];
		// }
	}
	return _jk_batch;
}
// void jkimyei_wikimyei(
// 	__cwcn_type_t _states[BATCH_SIZE][NUM_STATES], 
// 	__cwcn_type_t _actions[BATCH_SIZE][NUM_ACTIONS],
// 	__cwcn_type_t _log_probs[BATCH_SIZE][NUM_ACTIONS],
// 	__cwcn_type_t _returns[BATCH_SIZE][NUM_RETURNS],
// 	__cwcn_type_t _adventage[BATCH_SIZE][NUM_ACTIONS]){
// 		printf(">> skwstr_jkimyei_wikimyei");
// 		__cwcn_type_t ratio_handler;
// 		__cwcn_type_t surr1_handler;
// 		__cwcn_type_t surr2_handler;
// 		__cwcn_type_t loss_handler[NUM_ACTIONS];
// 		__cwcn_type_t actor_loss_handler[NUM_ACTIONS];
// 		__cwcn_type_t munaajpi_loss_handler[NUM_ACTIONS];
// 		__cwcn_type_t old_log_probs_handler[NUM_ACTIONS];
// 		__cwcn_type_t new_log_probs_handler[NUM_ACTIONS];

// 		__cwcn_type_t states_handler[MINI_BATCH_SIZE][NUM_STATES];
// 		__cwcn_type_t actions_handler[MINI_BATCH_SIZE][NUM_ACTIONS];
// 		__cwcn_type_t log_probs_handler[MINI_BATCH_SIZE][NUM_ACTIONS];
// 		__cwcn_type_t returns_handler[MINI_BATCH_SIZE][NUM_RETURNS];
// 		__cwcn_type_t adventage_handler[MINI_BATCH_SIZE][NUM_ACTIONS];

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
// 				actions_handler, 
// 				log_probs_handler, 
// 				returns_handler,
// 				adventage_handler);
// 			// propagate trought network
// 			for(int b_step=0; b_step<MINI_BATCH_SIZE; b_step++){
// 				cwcn_hash_cognitive(states_handler[b_step], ujcamei_handler);
// 				cwcn_net_uwaabo(ujcamei_handler, cajtucu_handler);
// 				cwcn_dehash_cognitive(cajtucu_handler, actions_handler);
// 				for(int a_idx=0;a_idx<NUM_ACTIONS;a_idx++){
// 					// new_action was old action in skwstr job, check this... #FIXME?
// 					ratio_handler = exp(log(actions_handler[a_idx]) - log_probs_handler[a_idx]);
// 					surr1_handler = ratio_handler * adventage_handler[b_step][a_idx];
// 					surr2_handler = clamp(ratio_handler, 1.0 - PPO_EPSILON, 1.0 + adventage_handler[b_step][a_idx]);
// 					actor_loss_handler[a_idx] = - min(surr1_handler, surr2_handler);
// 					// munaajpi_loss_handler[a_idx] = pow(return_ - value, 2);
// 					// // train the network! aja!
// 				}
// 			}
			
// 		}
// 	}

void jkimyei_wikimyei(__jkimyei_t *_jkimyei){
	#ifdef JKIMYEI_DEBUG
		printf(">> request jkimyei_wikimyei");
	#endif
	__cwcn_type_t ratio_handler;
	__cwcn_type_t surr1_handler;
	__cwcn_type_t surr2_handler;
	
	// __cwcn_type_t *loss_handler=malloc(NUM_ACTIONS*sizeof(__cwcn_type_t));
	// __cwcn_type_t *munaajpi_loss_handler=malloc(NUM_ACTIONS*sizeof(__cwcn_type_t));
	// __cwcn_type_t *actor_loss_handler=malloc(NUM_ACTIONS*sizeof(__cwcn_type_t));
	// __cwcn_type_t *old_log_probs_handler=malloc(NUM_ACTIONS*sizeof(__cwcn_type_t));
	// __cwcn_type_t *new_log_probs_handler=malloc(NUM_ACTIONS*sizeof(__cwcn_type_t));

	// __cwcn_type_t *states_handler=malloc(MINI_BATCH_SIZE*NUM_STATES*sizeof(__cwcn_type_t));
	// __cwcn_type_t *actions_handler=malloc(MINI_BATCH_SIZE*NUM_ACTIONS*sizeof(__cwcn_type_t));
	// __cwcn_type_t *log_probs_handler=malloc(MINI_BATCH_SIZE*NUM_ACTIONS*sizeof(__cwcn_type_t));
	// __cwcn_type_t *returns_handler=malloc(MINI_BATCH_SIZE*NUM_RETURNS*sizeof(__cwcn_type_t));
	// __cwcn_type_t *adventage_handler=malloc(MINI_BATCH_SIZE*NUM_ACTIONS*sizeof(__cwcn_type_t));

	// __cwcn_type_t *ujcamei_handler=malloc(NUM_UJCAMEI*sizeof(__cwcn_type_t)); // #FIXME what?
	// __cwcn_type_t *cajtucu_handler=malloc(NUM_CAJTUCU*sizeof(__cwcn_type_t)); // #FIXME what?
	
	assert(_jkimyei->__load_size%_jkimyei->__jk_size==0);

	load_iter(_jkimyei);
	for(unsigned int train_step=0; train_step<_jkimyei->__load_size/_jkimyei->__jk_size; train_step++){
		jkimyei_iter(_jkimyei);
		// propagate trought network
		for(unsigned int idx_jk=0; idx_jk<_jkimyei->__jk_size; idx_jk++){
			
			// cwcn_hash_cognitive(states_handler[idx_jk], ujcamei_handler);
			// cwcn_net_uwaabo(ujcamei_handler, cajtucu_handler);
			// cwcn_dehash_cognitive(cajtucu_handler, actions_handler);
			// _wikimyei_uwaabo_hash(c_duuruva, c_uwaabo);
			// _wikimyei_munaajpi_hash(c_duuruva, c_uwaabo, c_munaajpi);
			___uwaabo_hash(_jkimyei);
			___munaajpi_hash(_jkimyei);
			for(unsigned int a_idx=0;a_idx<NUM_ACTIONS;a_idx++){
				// new_action was old action in skwstr job, check this... #FIXME?
				ratio_handler = exp(log(actions_handler[a_idx]) - log_probs_handler[a_idx]);
				surr1_handler = ratio_handler * adventage_handler[idx_jk][a_idx];
				surr2_handler = clamp(ratio_handler, 1.0 - PPO_EPSILON, 1.0 + adventage_handler[idx_jk][a_idx]);
				_jkimyei->uwaabo_loss[a_idx] = - min(surr1_handler, surr2_handler);
				_jkimyei->munaajpi_loss[a_idx] = pow(return_ - value, 2);
				// // train the network! aja!
			}
		}
	}
	// free(loss_handler);
	// free(munaajpi_loss_handler);
	// free(old_log_probs_handler);
	// free(new_log_probs_handler);
	// free(states_handler);
	// free(actions_handler);
	// free(log_probs_handler);
	// free(returns_handler);
	// free(adventage_handler);
	// free(ujcamei_handler);
	// free(cajtucu_handler);
	// free(_load_batch);
	// free(actor_loss_handler);
	// (fixmenot) #FIXME? (clearing the buffer is not part of jkimyei_wikimyei) remove the proceed queue elements

	// #FIXME free inmortal and mortal queues
}

