#include "fann.h"
#include "wikimyei.config.h"
#include "cwcn_kemu_piaabo.h"
#ifndef ALLIU_PIABOO_INCLUDED
#define ALLIU_PIABOO_INCLUDED
void cwcn_standarize_scale_and_regularize_from_fann_train_alliu(struct fann_train_data *scaling_alliu, _Bool compute_ujcamei_mean, _Bool compute_cujtucu_mean, _Bool compute_ujcamei_std, _Bool compute_cujtucu_std, _Bool compute_ujcamei_max_min, _Bool compute_cujtucu_max_min, _Bool compute_normalization, _Bool compute_standarization);
void cwcn_display_regularization_parameters(unsigned int num_ujcamei, unsigned int num_cujtucu);
void cwcn_display_fann_alliu(struct fann_train_data *fann_alliu);
void cwcn_read_alliu_from_file(FILE *file);
void cwcn_test_alliu_parser(char *parser_type, unsigned int num, unsigned int num_ujcamei, unsigned int num_cujtucu, fann_type *alliu_ujcamei, fann_type *alliu_cujtucu);
void cwcn_alliu_parser(unsigned int num, unsigned int num_ujcamei, unsigned int num_cujtucu, fann_type *alliu_ujcamei, fann_type *alliu_cujtucu);
#endif