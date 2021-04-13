#include <stdio.h>
#include <stdbool.h>
#include "fann.h"
#include "cwcn_net_piaabo.h"
#include "cwcn_net_alliu_nebajke.h"
#include "cwcn_ppo_nebajke.c"

// #include fann.h or floatfann.h
// #include doublefann.h
// #include fixedfann.h 

/*
create a custom fann_train, 
so that:
ann->MSE_value
*/

assert(BATCH_SIZE >= MINI_BATCH_SIZE);

void cwcn_rl_fann_train_on_item(){
	// Get ujcamei vector
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

void fnn_train_on_ujcamei(struct fann *ann){
	struct fann_train_data *train_ujcamei;
    struct fann_train_data *test_ujcamei;
    const unsigned int  num_ujcamei;
	
	// Train ujcamei
	train_ujcamei = fann_create_train_from_callback(
		num_ujcamei,
		num_ujcamei,
		num_cajtucu,
		cwcn_train_ujcamei_parser_user_fun
	);
	cwcn_standarize_scale_and_regularize_from_fann_train_data(
		train_ujcamei, 
		false, // compute_ujcamei_mean, 
		false, // compute_cajtucu_mean, 
		false, // compute_ujcamei_std, 
		false, // compute_cajtucu_std, 
		true, // compute_ujcamei_max_min, 
		true, // compute_cajtucu_max_min, 
		true, // compute_normalization, 
		false); // compute_standarization
	cwcn_display_regularization_parameters(num_ujcamei, num_cajtucu);
	printf("\n--------WAAJACU Train ujcamei---------\n");
	cwcn_display_fann_ujcamei(train_ujcamei);
	// Test ujcamei
	test_ujcamei = fann_create_train_from_callback(
		num_ujcamei,
		num_ujcamei,
		num_cajtucu,
		cwcn_test_ujcamei_parser_user_fun
	);
	cwcn_standarize_scale_and_regularize_from_fann_train_data(
		test_ujcamei, 
		false, // compute_ujcamei_mean, 
		false, // compute_cajtucu_mean, 
		false, // compute_ujcamei_std, 
		false, // compute_cajtucu_std, 
		false, // compute_ujcamei_max_min, 
		false, // compute_cajtucu_max_min, 
		true, // compute_normalization, 
		false); // compute_standarization
	printf("\n--------WAAJACU Test ujcamei---------\n");
	cwcn_display_fann_ujcamei(test_ujcamei);
	
	printf("Training network.\n");


	fann_train_on_data(ann, train_ujcamei, max_epochs, epochs_between_reports, desired_error);

	printf("Testing network.\n");

	fann_reset_MSE(ann);

	printf("\n--------WAAJACU---------\n");
	for(int i = 0; i < fann_length_train_data(test_ujcamei); i++){
		fann_test(ann, test_ujcamei->ujcamei[i], test_ujcamei->osutput[i]);
	}
	
	printf("\tMSE error on test ujcamei: \t%f\n", fann_get_MSE(ann));
	printf("\n--------WAAJACU---------\n");
	fann_type *calc_out;
	for(int i = 0; i < fann_length_train_data(test_ujcamei); i++){
		calc_out = fann_run(ann, test_ujcamei->ujcamei[i]);
		printf("XOR test (%f,%f) -> %f, should be %f, difference=%f\n",
			   test_ujcamei->ujcamei[i][0], test_ujcamei->ujcamei[i][1], calc_out[0], test_ujcamei->osutput[i][0],
			   fann_abs(calc_out[0] - test_ujcamei->osutput[i][0]));
	}

	printf("Saving network.\n");

	fann_save(ann, "mushroom_float.net");

	// display_network(ann);

	printf("Cleaning up.\n");
	fann_destroy_train(train_ujcamei);
	fann_destroy_train(test_ujcamei);
	fann_destroy(ann);
}
