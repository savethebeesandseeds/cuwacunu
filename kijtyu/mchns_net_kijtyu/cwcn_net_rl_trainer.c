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
void cwcn_rl_fann_train_on_item(){
	// Get input vector
	// Forward network
	// Form max entropy distributions
	// Get observation vector
	// Decide 
	// Act
	// Calculate reward (J)
	// Train network
	skwstr_ppo_update(
		unsigned int frame_idx, 
		float *states, 
		float *actions, 
		float *log_probs, 
		float *returns,
		float *adventage);
}

float* cwcn_net_predict(float *state){
	// standarize
	return &();
}
void define_network(){
	const unsigned int 
	const unsigned int 
	const unsigned int 
	const unsigned int 
	const unsigned int 
	const unsigned int 
	const unsigned int 
	struct 
	struct 
	struct 

	unsigned int i = 0;
	
	printf("Creating network.\n");
	// fann_destroy_train(data);
	// // data->input
	// // data->output

	printf("\n--------WAAJACU---------\n");
	
	// Train data
	train_data = fann_create_train_from_callback(
		num_data,
		num_input,
		num_output,
		cwcn_train_data_parser_user_fun
	);
	cwcn_standarize_scale_and_regularize_from_fann_train_data(
		train_data, 
		false, // compute_input_mean, 
		false, // compute_output_mean, 
		false, // compute_input_std, 
		false, // compute_output_std, 
		true, // compute_input_max_min, 
		true, // compute_output_max_min, 
		true, // compute_normalization, 
		false); // compute_standarization
	cwcn_display_regularization_parameters(num_input, num_output);
	printf("\n--------WAAJACU Train DATA---------\n");
	cwcn_display_fann_data(train_data);
	// Test data
	test_data = fann_create_train_from_callback(
		num_data,
		num_input,
		num_output,
		cwcn_test_data_parser_user_fun
	);
	cwcn_standarize_scale_and_regularize_from_fann_train_data(
		test_data, 
		false, // compute_input_mean, 
		false, // compute_output_mean, 
		false, // compute_input_std, 
		false, // compute_output_std, 
		false, // compute_input_max_min, 
		false, // compute_output_max_min, 
		true, // compute_normalization, 
		false); // compute_standarization
	printf("\n--------WAAJACU Test DATA---------\n");
	cwcn_display_fann_data(test_data);
	
	// NETWORK
	printf("\n--------WAAJACU---------\n");
	ann = fann_create_standard(
		num_layers, 
		num_input, 
		num_neurons_hidden, 
		num_output
	);
	/*
	FANN_LINEAR_PIECE_SYMMETRIC
    FANN_THRESHOLD_SYMMETRIC
    FANN_SIGMOID_SYMMETRIC
    FANN_SIGMOID_SYMMETRIC_STEPWISE
    FANN_ELLIOT_SYMMETRIC
    FANN_GAUSSIAN_SYMMETRIC
    FANN_SIN_SYMMETRIC
    FANN_COS_SYMMETRIC
    FANN_THRESHOLD
    FANN_LINEAR
    FANN_SIGMOID
    FANN_SIGMOID_STEPWISE
    FANN_GAUSSIAN
    FANN_GAUSSIAN_STEPWISE
    FANN_ELLIOT
    FANN_LINEAR_PIECE
    FANN_SIN
    FANN_COS
	*/
	fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
	fann_set_activation_steepness_hidden(ann, 1);
	fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);
	fann_set_activation_steepness_output(ann, 1);
	fann_set_train_stop_function(ann, FANN_STOPFUNC_BIT);
	fann_set_bit_fail_limit(ann, 0.01f);

	fann_set_training_algorithm(ann, FANN_TRAIN_RPROP);
	/* FANN_TRAIN_INCREMENTAL
	FANN_TRAIN_INCREMENTAL	(fann_update_weights)			// Standar Backpropagation
	FANN_TRAIN_BATCH		(fann_update_weights_batch)		// Standar Backpropagation batch-wise
	FANN_TRAIN_RPROP		(fann_update_weights_irpropm)	// (does not use learning rate)
	FANN_TRAIN_QUICKPROP	(fann_update_weights_quickprop)	// 
	FANN_TRAIN_SARPROP		(fann_update_weights_sarprop)	// THE SARPROP ALGORITHM
	*/ // fann_set_training_algorithm, fann_get_training_algorithm
    
	// float new_input_min = -0.25;
	// float new_input_max = 0.25;
	// float new_output_min = -0.25;
	// float new_output_max = 0.25;
	// int waka;
	// waka = fann_set_input_scaling_params(
   	// 	ann,
   	// 	train_data,
   	// 	new_input_min,
   	// 	new_input_max
	// );
	// printf("waka (input): %d\n",waka);
	// waka = fann_set_output_scaling_params(
   	// 	ann,
   	// 	train_data,
   	// 	new_output_min,
   	// 	new_output_max
	// );
	// printf("waka (output): %d\n",waka);
	
	// display_network(ann);

	printf("Training network.\n");


	fann_train_on_data(ann, train_data, max_epochs, epochs_between_reports, desired_error);

	printf("Testing network.\n");

	fann_reset_MSE(ann);

	printf("\n--------WAAJACU---------\n");
	for(i = 0; i < fann_length_train_data(test_data); i++){
		fann_test(ann, test_data->input[i], test_data->output[i]);
	}
	
	printf("\tMSE error on test data: \t%f\n", fann_get_MSE(ann));
	printf("\n--------WAAJACU---------\n");
	fann_type *calc_out;
	for(i = 0; i < fann_length_train_data(test_data); i++){
		calc_out = fann_run(ann, test_data->input[i]);
		printf("XOR test (%f,%f) -> %f, should be %f, difference=%f\n",
			   test_data->input[i][0], test_data->input[i][1], calc_out[0], test_data->output[i][0],
			   fann_abs(calc_out[0] - test_data->output[i][0]));
	}

	printf("Saving network.\n");

	fann_save(ann, "mushroom_float.net");

	// display_network(ann);

	printf("Cleaning up.\n");
	fann_destroy_train(train_data);
	fann_destroy_train(test_data);
	fann_destroy(ann);

}

