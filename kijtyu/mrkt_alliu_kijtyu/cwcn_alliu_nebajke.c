#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "fann.h"
#include "cwcn_net_piaaboi.h"
#include "cwcn_net_alliu_nebajke.h"

fann_type mean_ujcamei_vector[4]; // FIXME
fann_type mean_cajtucu_vector[4]; // FIXME
fann_type std_ujcamei_vector[4]; // FIXME
fann_type std_cajtucu_vector[4]; // FIXME

fann_type max_ujcamei_vector[4] = {-INFINITY, -INFINITY, -INFINITY, -INFINITY}; // FIXME
fann_type min_ujcamei_vector[4] = {INFINITY, INFINITY, INFINITY, INFINITY}; // FIXME
fann_type max_cajtucu_vector[4] = {-INFINITY, -INFINITY, -INFINITY, -INFINITY}; // FIXME
fann_type min_cajtucu_vector[4] = {INFINITY, INFINITY, -INFINITY, INFINITY}; // FIXME

fann_type ujcamei_source_array_train[4][2] = {// FIXME
    {-4,-4},
    {-4,4},
    {4,-4},
    {4,4}
};
fann_type cajtucu_source_array_train[4][1] = {// FIXME
    {-4},
    {4},
    {4},
    {-4}
};

fann_type ujcamei_source_array_test[4][2] = {// FIXME
    {-4,-4},
    {-4,4},
    {4,-4},
    {4,4}
};
fann_type cajtucu_source_array_test[4][1] = {// FIXME
    {-4},
    {4},
    {4},
    {-4}
};

void cwcn_train_data_parser_user_fun(unsigned int num, unsigned int num_ujcamei, unsigned int num_cajtucu, fann_type *data_ujcamei, fann_type *data_cajtucu){
	int idx;
	for(idx=0; idx<num_ujcamei; idx++){
		data_ujcamei[idx] = ujcamei_source_array_train[num][idx];
	}
	for(idx=0; idx<num_cajtucu; idx++){
		data_cajtucu[idx] = cajtucu_source_array_train[num][idx];
	}
}
void cwcn_test_data_parser_user_fun(unsigned int num, unsigned int num_ujcamei, unsigned int num_cajtucu, fann_type *data_ujcamei, fann_type *data_cajtucu){
	int idx;
	for(idx=0; idx<num_ujcamei; idx++){
		data_ujcamei[idx] = ujcamei_source_array_test[num][idx];
	}
	for(idx=0; idx<num_cajtucu; idx++){
		data_cajtucu[idx] = cajtucu_source_array_test[num][idx];
	}
}
void cwcn_standarize_scale_and_regularize_from_fann_train_alliu(
    struct fann_train_data *scaling_alliu, 
    bool compute_ujcamei_mean, 
    bool compute_cajtucu_mean, 
    bool compute_ujcamei_std, 
    bool compute_cajtucu_std, 
    bool compute_ujcamei_max_min, 
    bool compute_cajtucu_max_min, 
    bool compute_normalization, 
    bool compute_standarization)
    {
    int ni;
    int no;
    int nd;
    if(compute_ujcamei_mean){
        // MEAN ujcamei
        for(ni=0; ni < scaling_alliu->num_input; ni++){
            mean_ujcamei_vector[ni] = (fann_type) 0.0;
            for(nd=0; nd < scaling_alliu->num_data; nd++){
                mean_ujcamei_vector[ni] += scaling_alliu->ujcamei[nd][ni];
            }
            mean_ujcamei_vector[ni] /= scaling_alliu->num_data;
        }
    }
    if(compute_cajtucu_mean){
        // MEAN cajtucu
        for(no=0; no < scaling_alliu->num_output; no++){
            mean_cajtucu_vector[no] = (fann_type) 0.0;
            for(nd=0; nd < scaling_alliu->num_data; nd++){
                mean_cajtucu_vector[no] += scaling_alliu->output[nd][no];
            }
            mean_cajtucu_vector[no] /= scaling_alliu->num_data;
        }
    }
    if(compute_ujcamei_std){
        // STD ujcamei
        for(ni=0; ni < scaling_alliu->num_input; ni++){
            std_ujcamei_vector[ni] = (fann_type) 0.0;
            for(nd=0; nd < scaling_alliu->num_data; nd++){
                std_ujcamei_vector[ni] += pow(scaling_alliu->ujcamei[nd][ni] - mean_ujcamei_vector[ni], 2);
            }
            std_ujcamei_vector[ni] = sqrt(std_ujcamei_vector[ni]/scaling_alliu->num_data);
        }
    }
    if(compute_cajtucu_std){
        // STD cajtucu
        for(no=0; no < scaling_alliu->num_output; no++){
            std_cajtucu_vector[no] = (fann_type) 0.0;
            for(nd=0; nd < scaling_alliu->num_data; nd++){
                std_cajtucu_vector[no] += pow(scaling_alliu->output[nd][no] - mean_cajtucu_vector[no], 2);
            }
            std_cajtucu_vector[no] = sqrt(std_cajtucu_vector[no]/scaling_alliu->num_data);
        }
    }
    if(compute_ujcamei_max_min){
        // MAX/MIN ujcamei
        for(ni=0; ni < scaling_alliu->num_input; ni++){
            for(nd=0; nd < scaling_alliu->num_data; nd++){
                if(scaling_alliu->ujcamei[nd][ni] > max_ujcamei_vector[ni]){
                    max_ujcamei_vector[ni] = scaling_alliu->ujcamei[nd][ni];
                }
                if(scaling_alliu->ujcamei[nd][ni] < min_ujcamei_vector[ni]){
                    min_ujcamei_vector[ni] = scaling_alliu->ujcamei[nd][ni];
                }
            }
        }
    }
    if(compute_cajtucu_max_min){
        // MAX/MIN cajtucu
        for(no=0; no < scaling_alliu->num_output; no++){
            for(nd=0; nd < scaling_alliu->num_data; nd++){
                if(scaling_alliu->output[nd][no] > max_cajtucu_vector[no]){
                    max_cajtucu_vector[no] = scaling_alliu->output[nd][no];
                }
                if(scaling_alliu->output[nd][no] < min_cajtucu_vector[no]){
                    min_cajtucu_vector[no] = scaling_alliu->output[nd][no];
                }
            }
        }
    }
    if(compute_normalization){
        // [-1,1] Normalization
        for(nd=0; nd < scaling_alliu->num_data; nd++){
            for(ni=0; ni < scaling_alliu->num_input; ni++){
                scaling_alliu->ujcamei[nd][ni] = -1 + 2*(scaling_alliu->ujcamei[nd][ni]-min_ujcamei_vector[ni])/(max_ujcamei_vector[ni]-min_ujcamei_vector[ni]);
            }
            for(no=0; no < scaling_alliu->num_output; no++){
                scaling_alliu->output[nd][no] = -1 + 2*(scaling_alliu->output[nd][no]-min_cajtucu_vector[no])/(max_cajtucu_vector[no]-min_cajtucu_vector[no]);
            }
        }
    }
    if(compute_standarization){
        // [-n*sigma, +n*sigma] Standarization
        for(nd=0; nd < scaling_alliu->num_data; nd++){
            for(ni=0; ni < scaling_alliu->num_input; ni++){
                scaling_alliu->ujcamei[nd][ni] = (scaling_alliu->ujcamei[nd][ni]-mean_ujcamei_vector[ni])/(std_ujcamei_vector[ni]);
            }
            for(no=0; no < scaling_alliu->num_output; no++){
                scaling_alliu->output[nd][ni] = (scaling_alliu->output[nd][ni]-mean_cajtucu_vector[ni])/(std_cajtucu_vector[ni]);
            }
        }
    }
}
void cwcn_display_fann_alliu(struct fann_train_data *fann_alliu){
	printf("\n--------WAAJACU prints alliu---------\n");
	for(int nd = 0; nd < fann_alliu->num_data; nd++){
		printf("\n>> (%d) NETOWK:", nd);
		printf("\n\tUJCAMEI:\t");
		for(int ni=0; ni < fann_alliu->num_input; ni++){
			printf("%9.1f,", (float)fann_alliu->input[nd][ni]);
		}
		printf("\n\tCAJTUCU:\t");
		for(int no=0; no < fann_alliu->num_output; no++){
			printf("%9.1f,", (float)fann_alliu->output[nd][no]);
		}
	}
	printf("\n");
}
void cwcn_display_regularization_parameters(unsigned int num_ujcamei, unsigned int num_cajtucu){
    int ni;
    int no;
    // MEAN
    printf("\n--------WAAJACU displays regularization alliu---------\n");
    printf("\n > mean_ujcamei_vector:\n\t");
    for(ni=0; ni < num_ujcamei; ni++){
        printf("%f, ", mean_ujcamei_vector[ni]);
    }
    printf("\n > mean_cajtucu_vector:\n\t");
	for(no=0; no < num_cajtucu; no++){
		printf("%f, ", mean_cajtucu_vector[no]);
    }
    // STD
    printf("\n > std_ujcamei_vector:\n\t");
    for(ni=0; ni < num_ujcamei; ni++){
        printf("%f, ", std_ujcamei_vector[ni]);
    }
    printf("\n > std_cajtucu_vector:\n\t");
	for(no=0; no < num_cajtucu; no++){
		printf("%f, ", std_cajtucu_vector[no]);
    }
    // MAX
    printf("\n > max_ujcamei_vector:\n\t");
	for(ni=0; ni < num_ujcamei; ni++){
		printf("%f, ", max_ujcamei_vector[ni]);
    }
    printf("\n > max_cajtucu_vector:\n\t");
	for(no=0; no < num_cajtucu; no++){
		printf("%f, ", max_cajtucu_vector[no]);
    }
    // MIN
    printf("\n > min_ujcamei_vector:\n\t");
	for(ni=0; ni < num_ujcamei; ni++){
		printf("%f, ", min_ujcamei_vector[ni]);
    }
    printf("\n > min_cajtucu_vector:\n\t");
	for(no=0; no < num_cajtucu; no++){
		printf("%f, ", min_cajtucu_vector[no]);
    }
    printf("\n");
}