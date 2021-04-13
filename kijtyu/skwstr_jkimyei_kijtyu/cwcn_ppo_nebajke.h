#ifndef FUNCTIONS_CWCN_PPO_MECH
#define FUNCTIONS_CWCN_PPO_MECH
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
#endif