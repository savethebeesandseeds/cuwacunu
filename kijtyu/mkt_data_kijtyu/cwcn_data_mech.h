#include "fann.h"
#ifndef FUNCTIONS_NET_DATA_MECH_INCLUDED
#define FUNCTIONS_NET_DATA_MECH_INCLUDED
void cwcn_train_data_parser_user_fun(unsigned int num, unsigned int num_input, unsigned int num_output, fann_type *data_input, fann_type *data_output);
void cwcn_test_data_parser_user_fun(unsigned int num, unsigned int num_input, unsigned int num_output, fann_type *data_input, fann_type *data_output);
void cwcn_standarize_scale_and_regularize_from_fann_train_data(struct fann_train_data *scaling_data, bool compute_input_mean, bool compute_output_mean, bool compute_input_std, bool compute_output_std, bool compute_input_max_min, bool compute_output_max_min, bool compute_normalization, bool compute_standarization);
void cwcn_display_regularization_parameters(unsigned int num_input, unsigned int num_output);
void cwcn_display_fann_data(struct fann_train_data *fann_data);
#endif