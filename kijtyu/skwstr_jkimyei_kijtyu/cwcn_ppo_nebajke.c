#include <stdio.h>
#include <stdbool.h>
#include "cwcn_ppo.mech.h"
#include "cwcn_security.h"
// remmemer PMF[a_idx], from I, from the past ¿do we make it?.

void skwstr_ppo_iter(
	float *states, 
	float *actions, 
	float *log_probs, 
	float *returns,
	float *adventage,
	float *states_handler,
	float *actions_handler, 
	float *log_probs_handler, 
	float *returns_handler,
	float *adventage_handler){
		for(int idx=0;idx<MINI_BATCH_SIZE;idx++){
			rand_idx = rand() % BATCH_SIZE;
			states_handler[idx] 	= states[rand_idx];
			actions_handler[idx] 	= actions[rand_idx];
			log_probs_handler[idx] 	= log_probs[rand_idx];
			returns_handler[idx] 	= returns[rand_idx];
			adventage_handler[idx] 	= adventage[rand_idx];
		}
	}
void skwstr_ppo_update(
	unsigned int frame_idx, 
	float *states, 
	float *actions, 
	float *log_probs, 
	float *returns,
	float *adventage){
		float ratio_handler;
		float surr1_handler;
		float surr2_handler;
		float loss_handler[NUM_ACTIONS];
		float actor_loss_handler[NUM_ACTIONS];
		float critic_loss_handler[NUM_ACTIONS];

		float states_handler[MINI_BATCH_SIZE][NUM_STATES];
		float actions_handler[MINI_BATCH_SIZE][NUM_ACTIONS];
		float log_probs_handler[MINI_BATCH_SIZE];
		float returns_handler[MINI_BATCH_SIZE];
		float adventage_handler[MINI_BATCH_SIZE][NUM_ACTIONS];
		float cognitive_handler[MINI_BATCH_SIZE];
		for(int train_step=0; train_step<BATCH_SIZE/MINI_BATCH_SIZE; train_step++){
			// PPO iterator
			skwstr_ppo_iter(
				states, 
				actions, 
				log_probs, 
				returns,
				adventage,
				states_handler,
				actions_handler, 
				log_probs_handler, 
				returns_handler,
				adventage_handler);
			// propagate trought network
			for(int b_step; b_size<MINI_BATCH_SIZE; b_step++){
				cognitive_handler = cwcn_dehash_cognitive(cwcn_net_predict(states_handler[b_step]));
				for(int a_idx=0;a_idx<NUM_ACTIONS;a_idx++){
					ratio_handler = exp(new_log_probs[a_idx] - old_log_probs[a_idx]);
					surr1_handler = ratio_handler * adventage_handler[b_step][a_idx];
					surr2_handler = clamp(ratio_handler, 1.0 - PPO_EPSILON, 1.0 + adventage_handler[b_step][a_idx];
					actor_loss_handler[a_idc] = - min(surr1_handler, surr2_handler);
					critic_loss_handler[a_idx] = pow(return_ - value, 2);
					loss_handler[a_idc] = CRITIC_BETA*citic_loss + ACTOR_BETA*actor_loss - ENTROPY_BETA*cognitive_handler->PMF[a_idx]->sence_entropy;
					// train the network! aja!
					...
				}
			}
			
		}
	}