#include <stdio.h>
#include "fann.h"
#include "cwcn_net_utils.h"
#include "cwcn_net_data_mech.h"
#include <stdbool.h>
// #include fann.h or floatfann.h
// #include doublefann.h
// #include fixedfann.h 

// remmemer PMF[a_idx], from I, from the past ¿do we make it?.

/*
create a custom fann_train, 
so that:
ann->MSE_value
*/

#define NUM_ENVS       	1 
#define HIDDEN_SIZE    	12
#define LEARNING_RATE  	1e-4
#define GAMMA          	0.99
#define GAE_LAMBDA     	0.95
#define PPO_EPSILON    	0.2
#define ACTOR_BETA		1.0
#define CRITIC_BETA		0.5
#define ENTROPY_BETA   	0.001
#define PPO_STEPS      	256
#define BATCH_SIZE		128
#define MINI_BATCH_SIZE	32
#define TARGET_REWARD  	2500

#define NUM_STATES		1
#define NUM_ACTIONS
assert(BATCH_SIZE >= MINI_BATCH_SIZE);

float states[BATCH_SIZE];
float actions[BATCH_SIZE];
float log_probs[BATCH_SIZE];
float returns[BATCH_SIZE];
float adventage[BATCH_SIZE];
float cognitive[BATCH_SIZE]; // FIXME, needed?

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
	float *adventage_handler);
void skwstr_ppo_update(
	unsigned int frame_idx, 
	float *states, 
	float *actions, 
	float *log_probs, 
	float *returns,
	float *adventage);
void cwcn_rl_fann_train_on_item();
