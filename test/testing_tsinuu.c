#include <stdio.h>
#include "cwcn_tsinuu_piaabo.h"

int main(void){
    //
    printf("\n------->------\n");
    //
    srand(time(NULL));
    unsigned int c_layers_sizes[] = {3,2,1};
    list_activations_t c_activations_iho[] = {LINEAR, SIGMOID, SIGMOID};
    attribute_tsinuu_t * c_attribute_tsinuu = malloc(sizeof(attribute_tsinuu_t));
    c_attribute_tsinuu->__NUM_TOTAL_LAYERS=3;
    c_attribute_tsinuu->__LAYERS_SIZES=c_layers_sizes;
    c_attribute_tsinuu->__layers_activation=c_activations_iho;
    // 
    __cwcn_type bin_input=0;
    __cwcn_type bin_value=0;
    //
    tsinuu_t * c_tsinuu = tsinuu_fabric(c_attribute_tsinuu);
    free(c_attribute_tsinuu);
    tsinuu_initialize_weights(c_tsinuu);
    for(bin_input = -0xF; bin_input<=0xF; bin_input++){
        bin_value = c_tsinuu->__nodes[0]->__direct(bin_input);
        printf("NAT: \t %f \t %f\n", bin_input, bin_value);
        if(bin_input==0xFF){break;}
    }
    // printf("weights - shownonoe: %f\n", c_tsinuu->__weights[0][0]);
    // printf("act     - shownonoe: %f\n", c_tsinuu->__hidden_activation_forward(0x02));
    // tsinuu_destroy(c_tsinuu);
    // printf("--------*--------\n");
    // printf("weights - shownonoe: %f\n", c_tsinuu->__weights[0][0]);
    // printf("act     - shownonoe: %f\n", c_tsinuu->__hidden_activation_forward(0x02));
}