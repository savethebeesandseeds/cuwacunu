// depends on fann
#include "wikimyei.config.h"
#include "cwcn_jkimyei.h"
void jkimyei_on_alliu_file(struct fann *ann){
	printf(">> jkimyei_on_alliu_file");
	struct fann_train_data *train_alliu;
    struct fann_train_data *test_alliu;
    const unsigned int  NUM_ALLIU;
	unsigned int epochs_between_reports = 10;
	unsigned int max_epochs = 10;
	float desired_error = 0;
	// Train ujcamei
	train_alliu = fann_create_train_from_callback(
		NUM_ALLIU,
		NUM_UJCAMEI,
		NUM_CAJTUCU,
		cwcn_train_alliu_parser_user_fun
	);
	cwcn_standarize_scale_and_regularize_from_fann_train_alliu(
		train_alliu, 
		CWCN_FALSE, // compute_ujcamei_mean, 
		CWCN_FALSE, // compute_cajtucu_mean, 
		CWCN_FALSE, // compute_ujcamei_std, 
		CWCN_FALSE, // compute_cajtucu_std, 
		CWCN_TRUE, // compute_ujcamei_max_min, 
		CWCN_TRUE, // compute_cajtucu_max_min, 
		CWCN_TRUE, // compute_normalization, 
		CWCN_FALSE); // compute_standarization
	cwcn_display_regularization_parameters(NUM_UJCAMEI, NUM_CAJTUCU);
	printf("\n--------WAAJACU Train ujcamei---------\n");
	cwcn_display_fann_alliu(train_alliu);
	// Test alliu
	test_alliu = fann_create_train_from_callback(
		NUM_ALLIU,
		NUM_UJCAMEI,
		NUM_CAJTUCU,
		cwcn_test_alliu_parser_user_fun
	);
	cwcn_standarize_scale_and_regularize_from_fann_train_alliu(
		test_alliu, 
		CWCN_FALSE, // compute_ujcamei_mean, 
		CWCN_FALSE, // compute_cajtucu_mean, 
		CWCN_FALSE, // compute_ujcamei_std, 
		CWCN_FALSE, // compute_cajtucu_std, 
		CWCN_FALSE, // compute_ujcamei_max_min, 
		CWCN_FALSE, // compute_cajtucu_max_min, 
		CWCN_TRUE, // compute_normalization, 
		CWCN_FALSE); // compute_standarization
	printf("\n--------WAAJACU Test alliu---------\n");
	cwcn_display_fann_alliu(test_alliu);
	
	printf("Training network.\n");


	fann_train_on_data(ann, train_alliu, max_epochs, epochs_between_reports, desired_error);

	printf("Testing network.\n");

	fann_reset_MSE(ann);

	printf("\n--------WAAJACU---------\n");
	for(int i = 0; i < fann_length_train_data(test_alliu); i++){
		fann_test(ann, test_alliu->input[i], test_alliu->output[i]);
	}
	
	printf("\tMSE error on test alliu: \t%f\n", fann_get_MSE(ann));
	printf("\n--------WAAJACU---------\n");
	fann_type *calc_out;
	for(int i = 0; i < fann_length_train_data(test_alliu); i++){
		calc_out = fann_run(ann, test_alliu->input[i]);
		printf("XOR test (%f,%f) -> %f, should be %f, difference=%f\n",
			   test_alliu->input[i][0], test_alliu->input[i][1], calc_out[0], test_alliu->output[i][0],
			   fann_abs(calc_out[0] - test_alliu->output[i][0]));
	}

	printf("Saving network.\n");

	fann_save(ann, "mushroom_float.net");

	// display_network(ann);

	printf("Cleaning up.\n");
	fann_destroy_train(train_alliu);
	fann_destroy_train(test_alliu);
	fann_destroy(ann);
}
