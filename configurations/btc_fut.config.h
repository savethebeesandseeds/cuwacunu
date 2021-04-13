#include "fann.h"
#ifndef WIKIMYEI_CONFIG
#define WIKIMYEI_CONFIG

#define NUM_UJCAMEI 2 // FIXME
#define NUM_CAJTUCU 1 // FIXME
#define NUM_LAYERS 3 // FIXME
#define NUM_NEURONS_HIDDEN 3 // FIXME

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
#define NUM_ACTIONS		10

#endif