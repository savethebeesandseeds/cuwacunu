#include <stdio.h>
#include <time.h>
#include "cwcn_tsinuu_piaabo.h"
#include "cwcn_tsinuu_nebajke.h"
#define INPUT_SIZE (unsigned int) 3
#define OUTPUT_SIZE (unsigned int) 2
#define TOTAL_LAYERS (unsigned int) 3
int main(void){
    //
    printf("\n------->------\n");
    set_seed();
    // Configure tsinuu
    unsigned int c_layers_sizes[TOTAL_LAYERS] = {INPUT_SIZE,3,OUTPUT_SIZE};
    __list_activations_t c_activations_iho[TOTAL_LAYERS] = {LINEAR, SIGMOID, SIGMOID};
    // Fabric tsinuu
    __attribute_tsinuu_t *c_attribute_tsinuu = malloc(sizeof(__attribute_tsinuu_t));
    c_attribute_tsinuu->__NUM_TOTAL_LAYERS=TOTAL_LAYERS;
    c_attribute_tsinuu->__layers_sizes=c_layers_sizes;
    c_attribute_tsinuu->__layers_activation=c_activations_iho;
    c_attribute_tsinuu->__is_symetric=___CWCN_TRUE;
    c_attribute_tsinuu->__alpha=0.9; // required to create new tsinuu
    c_attribute_tsinuu->__eta=0.9; // required to create new tsinuu
    __tsinuu_t *c_tsinuu = tsinuu_fabric(c_attribute_tsinuu);
    // tsinuu_initialize_weights_zero(c_tsinuu);
    // tsinuu_initialize_bias_zero(c_tsinuu);
    tsinuu_initialize_weights_random(c_tsinuu, 0.5, -0.5);
    tsinuu_initialize_bias_random(c_tsinuu, 0.5, -0.5);
    pardon_inputoutput_bias(c_tsinuu);
    /* 
        SET THE PARAMETRICS:
        __nodeboolean_parametric_t {
            __pardon_value
            __pardon_grad   =0x0X
            __pardon_bias
            __pardon_maxmin
            __pardon_entrop
            __pardon_dist
            __pardon_count
            __pardon_error
            __has_value
            __has_grad      =0x0X
            __is_input      =0x0X
            __is_output     =0x0X
            __is_reset      =0x0X
        }
        __lineboolean_parametric_t {
            __pardon_grad   =0x0X
            __pardon_weight
            __has_grad      =0x0X
        }
    */
    set_all_nodebooleanpardon_parametric(c_tsinuu, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
    set_all_linebooleanpardon_parametric(c_tsinuu, 0x00, 0x00);
    /*
        PROPAGATE
    */
    // fprintf(stdout, "--------->(PREV TRAINING)<---------\n");
    // for(unsigned int idx_n=0x00;idx_n<INPUT_SIZE;idx_n++){
    //     fprintf(stdout, ">>>>(after propagate) suspect elemenet input[%d]=%f\n",idx_n, c_input_vector[idx_n]);
    // }
    // for(unsigned int idx_n=0x00;idx_n<OUTPUT_SIZE;idx_n++){
    //     fprintf(stdout, ">>>>(after propagate) suspect elemenet \t\toutput[%d]=%f\n",idx_n, c_output_vector[idx_n]);
    // }
    // fprintf(stdout, "--------->---------\n");
    /*
        TRAIN
    */
    __cwcn_type_t *c_wapaajco;
    // __cwcn_type_t *c_input_vector = malloc(INPUT_SIZE*sizeof(__cwcn_type_t));
    __cwcn_type_t *c_output_vector = malloc(OUTPUT_SIZE*sizeof(__cwcn_type_t));
    __cwcn_type_t c_input_vector[5][INPUT_SIZE]={{0,0,0},{0,0,0},{0,1,0},{0,0,1},{0,1,1}};
    __cwcn_type_t c_correct_output[5][OUTPUT_SIZE]={{0,0},{0,0},{0,1},{0,1},{0,0}};
    for(unsigned int ctx_epoch=0x00;ctx_epoch<10000;ctx_epoch++){
        for(unsigned int ctx_p=0x00;ctx_p<5;ctx_p++){
            // Propagate
            set_input(c_tsinuu, c_input_vector[ctx_p]);
            tsinuu_direct_propagate_full_parametric(c_tsinuu);
            c_wapaajco=wapaajco_bydifference(c_tsinuu, c_correct_output[ctx_p]);
            // for(unsigned int idx_n=0x00;idx_n<OUTPUT_SIZE;idx_n++){
            //     c_wapaajco[idx_n]=c_wapaajco[idx_n];
            // }
            jkimyei_bydirectNABLA(c_tsinuu, c_wapaajco);
            // read_input(c_tsinuu, *c_input_vector);
            read_output(c_tsinuu, c_output_vector);
            fprintf(stdout, "--------->(POST <%d>[%d])<---------\n",ctx_epoch,ctx_p);
            for(unsigned int idx_n=0x00;idx_n<INPUT_SIZE;idx_n++){
                fprintf(stdout, ">>>>[%d](after propagate) suspect elemenet input[%d]=%f\n",ctx_p,idx_n, c_input_vector[ctx_p][idx_n]);
            }
            for(unsigned int idx_n=0x00;idx_n<OUTPUT_SIZE;idx_n++){
                fprintf(stdout, ">>>>[%d](after propagate) suspect elemenet \t\toutput[%d]=%f\n",ctx_p,idx_n, c_output_vector[idx_n]);
            }
            fprintf(stdout, "--------->---------\n");
        }
    }
    // for(bin_input = -0xF; bin_input<=0xF; bin_input++){
    //     bin_value = c_tsinuu->__nodes[0]->__direct(bin_input);
    //     printf("NAT: \t %f \t %f\n", bin_input, bin_value);
    //     if(bin_input==0xFF){break;}
    // }
    // print_layer_by_coord(_tsinuu, layer_index_to_layer_coord(_tsinuu,0x00));
    // print_node_by_coord(c_tsinuu, node_index_to_node_coord(c_tsinuu,0x00,0x00));
    // print_line_by_coord(c_tsinuu, line_index_to_line_coord(c_tsinuu, 0x00));
    printf("waka dao\n");
    printf("waka din\n");
    tsinuu_destroy(c_tsinuu);
    printf("waka tao\n");
}