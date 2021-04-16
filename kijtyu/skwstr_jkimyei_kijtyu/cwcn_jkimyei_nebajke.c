#include <stdio.h>
#include "cwcn_security.h"
#include "cwcn_kemu_piaabo.h"
#include "cwcn_ppo_nebajke.h"
#include "cwcn_net_nebajke.h"
#include "cwcn_wikimyei_nebajke.h"
// remmemer PMF[a_idx], from I, from the past ¿do we make it?.

void cwcn_jkimyei_iter(
	float states[BATCH_SIZE][NUM_STATES], 
	float actions[BATCH_SIZE][NUM_ACTIONS],
	float log_probs[BATCH_SIZE][NUM_ACTIONS], 
	float returns[BATCH_SIZE][NUM_RETURNS],
	float adventage[BATCH_SIZE][NUM_ACTIONS],
	float states_handler[MINI_BATCH_SIZE][NUM_STATES],
	float actions_handler[MINI_BATCH_SIZE][NUM_ACTIONS], 
	float log_probs_handler[MINI_BATCH_SIZE][NUM_ACTIONS], 
	float returns_handler[MINI_BATCH_SIZE][NUM_RETURNS],
	float adventage_handler[MINI_BATCH_SIZE][NUM_ACTIONS]){
	printf(">> cwcn_jkimyei_iter");
	unsigned int rand_idx;
	for(int idx=0;idx<MINI_BATCH_SIZE;idx++){
		rand_idx = rand() % BATCH_SIZE;
		for(int itm_x=0; itm_x < NUM_STATES; itm_x++){
			states_handler[idx][itm_x] 	= states[rand_idx][itm_x];
		}
		for(int itm_x=0; itm_x < NUM_RETURNS; itm_x++){
			returns_handler[idx][itm_x] 	= returns[rand_idx][itm_x];
		}
		for(int itm_x=0; itm_x < NUM_ACTIONS; itm_x++){
			actions_handler[idx][itm_x] 	= actions[rand_idx][itm_x];
			log_probs_handler[idx][itm_x] 	= log_probs[rand_idx][itm_x];
			adventage_handler[idx][itm_x] 	= adventage[rand_idx][itm_x];
		}
	}
}
// void cwcn_jkimyei_wikimyei(
// 	float states[BATCH_SIZE][NUM_STATES], 
// 	float actions[BATCH_SIZE][NUM_ACTIONS],
// 	float log_probs[BATCH_SIZE][NUM_ACTIONS],
// 	float returns[BATCH_SIZE][NUM_RETURNS],
// 	float adventage[BATCH_SIZE][NUM_ACTIONS]){
// 		printf(">> skwstr_jkimyei_wikimyei");
// 		float ratio_handler;
// 		float surr1_handler;
// 		float surr2_handler;
// 		float loss_handler[NUM_ACTIONS];
// 		float actor_loss_handler[NUM_ACTIONS];
// 		float critic_loss_handler[NUM_ACTIONS];
// 		float old_log_probs_handler[NUM_ACTIONS];
// 		float new_log_probs_handler[NUM_ACTIONS];

// 		float states_handler[MINI_BATCH_SIZE][NUM_STATES];
// 		float actions_handler[MINI_BATCH_SIZE][NUM_ACTIONS];
// 		float log_probs_handler[MINI_BATCH_SIZE][NUM_ACTIONS];
// 		float returns_handler[MINI_BATCH_SIZE][NUM_RETURNS];
// 		float adventage_handler[MINI_BATCH_SIZE][NUM_ACTIONS];

// 		float ujcamei_handler[NUM_UJCAMEI];
// 		float cajtucu_handler[NUM_CAJTUCU];
// 		for(int train_step=0; train_step<BATCH_SIZE/MINI_BATCH_SIZE; train_step++){
// 			// PPO iterator
// 			cwcn_jkimyei_iter(
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
// 					// critic_loss_handler[a_idx] = pow(return_ - value, 2);
// 					// // train the network! aja!
// 				}
// 			}
			
// 		}
// 	}

void cwcn_jkimyei_wikimyei(queue_t * head_t){
	printf(">> skwstr_jkimyei_wikimyei");
	float ratio_handler;
	float surr1_handler;
	float surr2_handler;
	
	float loss_handler[NUM_ACTIONS];
	float actor_loss_handler[NUM_ACTIONS];
	float critic_loss_handler[NUM_ACTIONS];
	float old_log_probs_handler[NUM_ACTIONS];
	float new_log_probs_handler[NUM_ACTIONS];

	float states_handler[MINI_BATCH_SIZE][NUM_STATES];
	float actions_handler[MINI_BATCH_SIZE][NUM_ACTIONS];
	float log_probs_handler[MINI_BATCH_SIZE][NUM_ACTIONS];
	float returns_handler[MINI_BATCH_SIZE][NUM_RETURNS];
	float adventage_handler[MINI_BATCH_SIZE][NUM_ACTIONS];

	float ujcamei_handler[NUM_UJCAMEI];
	float cajtucu_handler[NUM_CAJTUCU];
	for(int train_step=0; train_step<BATCH_SIZE/MINI_BATCH_SIZE; train_step++){
		// PPO iterator
		cwcn_jkimyei_iter();
		// propagate trought network
		for(int b_step=0; b_step<MINI_BATCH_SIZE; b_step++){
			// cwcn_hash_cognitive(states_handler[b_step], ujcamei_handler);
			// cwcn_net_uwaabo(ujcamei_handler, cajtucu_handler);
			// cwcn_dehash_cognitive(cajtucu_handler, actions_handler);
			_wikimyei_uwaabo_hash	(c_duuruva, c_uwaabo);
			_wikimyei_munaajpi_hash	(c_duuruva, c_uwaabo, c_munaajpi);
			for(int a_idx=0;a_idx<NUM_ACTIONS;a_idx++){
				// new_action was old action in skwstr job, check this... #FIXME?
				ratio_handler = exp(log(actions_handler[a_idx]) - log_probs_handler[a_idx]);
				surr1_handler = ratio_handler * adventage_handler[b_step][a_idx];
				surr2_handler = clamp(ratio_handler, 1.0 - PPO_EPSILON, 1.0 + adventage_handler[b_step][a_idx]);
				actor_loss_handler[a_idx] = - min(surr1_handler, surr2_handler);
				// critic_loss_handler[a_idx] = pow(return_ - value, 2);
				// // train the network! aja!
			}
		}
	}
}

