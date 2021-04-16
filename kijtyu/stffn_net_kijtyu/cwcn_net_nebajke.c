#include "fann.h"
#include "cwcn_net_nebajke.h"
#include "wikimyei.config.h"
void cwcn_net_uwaabo(float *ujcamei, float *cajtucu){
	// standarize
	printf(">> cwcn_net_uwaabo\n");
	cajtucu = ujcamei;
}

struct fann * cwcn_ipivye_net(
    const unsigned int  num_layers,
    const unsigned int  num_ujcamei,
    const unsigned int  num_neurons_hidden,
    const unsigned int  num_cajtucu){
	printf(">> cwcn_ipivye_net\n");
	// NETWORK
	printf("\n--------WAAJACU---------\n");
	struct fann *ann = fann_create_standard(
		num_layers, 
		num_ujcamei, 
		num_neurons_hidden, 
		num_cajtucu
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

	// fann_destroy_train(data);
	fann_save(ann, "mushroom_float.net");
	printf("\n--------WAAJACU---------\n");

	return ann;
}

