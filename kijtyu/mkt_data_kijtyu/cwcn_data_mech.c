#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "fann.h"
#include "cwcn_net_utils.h"
#include "cwcn_net_data_mech.h"

fann_type mean_input_vector[4]; // FIXME
fann_type mean_output_vector[4]; // FIXME
fann_type std_input_vector[4]; // FIXME
fann_type std_output_vector[4]; // FIXME

fann_type max_input_vector[4] = {-INFINITY, -INFINITY, -INFINITY, -INFINITY}; // FIXME
fann_type min_input_vector[4] = {INFINITY, INFINITY, INFINITY, INFINITY}; // FIXME
fann_type max_output_vector[4] = {-INFINITY, -INFINITY, -INFINITY, -INFINITY}; // FIXME
fann_type min_output_vector[4] = {INFINITY, INFINITY, -INFINITY, INFINITY}; // FIXME

fann_type input_source_array_train[4][2] = {// FIXME
    {-4,-4},
    {-4,4},
    {4,-4},
    {4,4}
};
fann_type output_source_array_train[4][1] = {// FIXME
    {-4},
    {4},
    {4},
    {-4}
};

fann_type input_source_array_test[4][2] = {// FIXME
    {-4,-4},
    {-4,4},
    {4,-4},
    {4,4}
};
fann_type output_source_array_test[4][1] = {// FIXME
    {-4},
    {4},
    {4},
    {-4}
};

void cwcn_train_data_parser_user_fun(unsigned int num, unsigned int num_input, unsigned int num_output, fann_type *data_input, fann_type *data_output){
	int idx;
	for(idx=0; idx<num_input; idx++){
		data_input[idx] = input_source_array_train[num][idx];
	}
	for(idx=0; idx<num_output; idx++){
		data_output[idx] = output_source_array_train[num][idx];
	}
}
void cwcn_test_data_parser_user_fun(unsigned int num, unsigned int num_input, unsigned int num_output, fann_type *data_input, fann_type *data_output){
	int idx;
	for(idx=0; idx<num_input; idx++){
		data_input[idx] = input_source_array_test[num][idx];
	}
	for(idx=0; idx<num_output; idx++){
		data_output[idx] = output_source_array_test[num][idx];
	}
}
void cwcn_standarize_scale_and_regularize_from_fann_train_data(
    struct fann_train_data *scaling_data, 
    bool compute_input_mean, 
    bool compute_output_mean, 
    bool compute_input_std, 
    bool compute_output_std, 
    bool compute_input_max_min, 
    bool compute_output_max_min, 
    bool compute_normalization, 
    bool compute_standarization)
    {
    int ni;
    int no;
    int nd;
    if(compute_input_mean){
        // MEAN input
        for(ni=0; ni < scaling_data->num_input; ni++){
            mean_input_vector[ni] = (fann_type) 0.0;
            for(nd=0; nd < scaling_data->num_data; nd++){
                mean_input_vector[ni] += scaling_data->input[nd][ni];
            }
            mean_input_vector[ni] /= scaling_data->num_data;
        }
    }
    if(compute_output_mean){
        // MEAN output
        for(no=0; no < scaling_data->num_output; no++){
            mean_output_vector[no] = (fann_type) 0.0;
            for(nd=0; nd < scaling_data->num_data; nd++){
                mean_output_vector[no] += scaling_data->output[nd][no];
            }
            mean_output_vector[no] /= scaling_data->num_data;
        }
    }
    if(compute_input_std){
        // STD input
        for(ni=0; ni < scaling_data->num_input; ni++){
            std_input_vector[ni] = (fann_type) 0.0;
            for(nd=0; nd < scaling_data->num_data; nd++){
                std_input_vector[ni] += pow(scaling_data->input[nd][ni] - mean_input_vector[ni], 2);
            }
            std_input_vector[ni] = sqrt(std_input_vector[ni]/scaling_data->num_data);
        }
    }
    if(compute_output_std){
        // STD output
        for(no=0; no < scaling_data->num_output; no++){
            std_output_vector[no] = (fann_type) 0.0;
            for(nd=0; nd < scaling_data->num_data; nd++){
                std_output_vector[no] += pow(scaling_data->output[nd][no] - mean_output_vector[no], 2);
            }
            std_output_vector[no] = sqrt(std_output_vector[no]/scaling_data->num_data);
        }
    }
    if(compute_input_max_min){
        // MAX/MIN input
        for(ni=0; ni < scaling_data->num_input; ni++){
            for(nd=0; nd < scaling_data->num_data; nd++){
                if(scaling_data->input[nd][ni] > max_input_vector[ni]){
                    max_input_vector[ni] = scaling_data->input[nd][ni];
                }
                if(scaling_data->input[nd][ni] < min_input_vector[ni]){
                    min_input_vector[ni] = scaling_data->input[nd][ni];
                }
            }
        }
    }
    if(compute_output_max_min){
        // MAX/MIN output
        for(no=0; no < scaling_data->num_output; no++){
            for(nd=0; nd < scaling_data->num_data; nd++){
                if(scaling_data->output[nd][no] > max_output_vector[no]){
                    max_output_vector[no] = scaling_data->output[nd][no];
                }
                if(scaling_data->output[nd][no] < min_output_vector[no]){
                    min_output_vector[no] = scaling_data->output[nd][no];
                }
            }
        }
    }
    if(compute_normalization){
        // [-1,1] Normalization
        for(nd=0; nd < scaling_data->num_data; nd++){
            for(ni=0; ni < scaling_data->num_input; ni++){
                scaling_data->input[nd][ni] = -1 + 2*(scaling_data->input[nd][ni]-min_input_vector[ni])/(max_input_vector[ni]-min_input_vector[ni]);
            }
            for(no=0; no < scaling_data->num_output; no++){
                scaling_data->output[nd][no] = -1 + 2*(scaling_data->output[nd][no]-min_output_vector[no])/(max_output_vector[no]-min_output_vector[no]);
            }
        }
    }
    if(compute_standarization){
        // [-n*sigma, +n*sigma] Standarization
        for(nd=0; nd < scaling_data->num_data; nd++){
            for(ni=0; ni < scaling_data->num_input; ni++){
                scaling_data->input[nd][ni] = (scaling_data->input[nd][ni]-mean_input_vector[ni])/(std_input_vector[ni]);
            }
            for(no=0; no < scaling_data->num_output; no++){
                scaling_data->output[nd][ni] = (scaling_data->output[nd][ni]-mean_output_vector[ni])/(std_output_vector[ni]);
            }
        }
    }
}
void cwcn_display_fann_data(struct fann_train_data *fann_data){
	printf("\n--------WAAJACU prints data---------\n");
	for(int nd = 0; nd < fann_data->num_data; nd++){
		printf("\n>> (%d) NETOWK:", nd);
		printf("\n\tINPUT:\t");
		for(int ni=0; ni < fann_data->num_input; ni++){
			printf("%9.1f,", (float)fann_data->input[nd][ni]);
		}
		printf("\n\tOUTPUT:\t");
		for(int no=0; no < fann_data->num_output; no++){
			printf("%9.1f,", (float)fann_data->output[nd][no]);
		}
	}
	printf("\n");
}
void cwcn_display_regularization_parameters(unsigned int num_input, unsigned int num_output){
    int ni;
    int no;
    // MEAN
    printf("\n--------WAAJACU displays regularization data---------\n");
    printf("\n > mean_input_vector:\n\t");
    for(ni=0; ni < num_input; ni++){
        printf("%f, ", mean_input_vector[ni]);
    }
    printf("\n > mean_output_vector:\n\t");
	for(no=0; no < num_output; no++){
		printf("%f, ", mean_output_vector[no]);
    }
    // STD
    printf("\n > std_input_vector:\n\t");
    for(ni=0; ni < num_input; ni++){
        printf("%f, ", std_input_vector[ni]);
    }
    printf("\n > std_output_vector:\n\t");
	for(no=0; no < num_output; no++){
		printf("%f, ", std_output_vector[no]);
    }
    // MAX
    printf("\n > max_input_vector:\n\t");
	for(ni=0; ni < num_input; ni++){
		printf("%f, ", max_input_vector[ni]);
    }
    printf("\n > max_output_vector:\n\t");
	for(no=0; no < num_output; no++){
		printf("%f, ", max_output_vector[no]);
    }
    // MIN
    printf("\n > min_input_vector:\n\t");
	for(ni=0; ni < num_input; ni++){
		printf("%f, ", min_input_vector[ni]);
    }
    printf("\n > min_output_vector:\n\t");
	for(no=0; no < num_output; no++){
		printf("%f, ", min_output_vector[no]);
    }
    printf("\n");
}