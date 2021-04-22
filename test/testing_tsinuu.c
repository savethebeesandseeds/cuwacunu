#include <stdio.h>
#include <time.h>
#include "cwcn_tsinuu_piaabo.h"
#include "cwcn_tsinuu_nebajke.h"
int main(void){
    //
    printf("\n------->------\n");
    srand(time(NULL));
    // Configure tsinuu
    __list_activations_t * __layers_activation;
    unsigned int c_layers_sizes[] = {3,2,1};
    __list_activations_t c_activations_iho[] = {LINEAR, SIGMOID, SIGMOID};
    __attribute_tsinuu_t * c_attribute_tsinuu = malloc(sizeof(__attribute_tsinuu_t));
    c_attribute_tsinuu->__NUM_TOTAL_LAYERS=3;
    c_attribute_tsinuu->__layers_sizes=c_layers_sizes;
    c_attribute_tsinuu->__layers_activation=c_activations_iho;
    c_attribute_tsinuu->__is_symetric=___CWCN_TRUE;
    // Fabric tsinuu
    __tsinuu_t * c_tsinuu = tsinuu_fabric(c_attribute_tsinuu);
    tsinuu_initialize_weights_random(c_tsinuu, 0x05, -0x05);
    // for(bin_input = -0xF; bin_input<=0xF; bin_input++){
    //     bin_value = c_tsinuu->__nodes[0]->__direct(bin_input);
    //     printf("NAT: \t %f \t %f\n", bin_input, bin_value);
    //     if(bin_input==0xFF){break;}
    // }
    tsinuu_destroy(c_tsinuu);
    printf("waka dao\n");
    printf("waka din\n");
}