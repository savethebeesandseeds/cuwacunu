#include <stdio.h>
#include <time.h>
#include "cwcn_tsinuu_piaabo.h"
#include "cwcn_tsinuu_nebajke.h"
#define INPUT_SIZE (unsigned int) 1
#define OUTPUT_SIZE (unsigned int) 1
#define TOTAL_LAYERS (unsigned int) 6
#define NUM_EPOCHS (unsigned int) 100
#define DATA_COUNT (unsigned int) 100
/*
    LINEAR: (alpha=0.1, eta=0.1, omega=1.0, w_potency=2)
    {INPUT_SIZE,5,10,25,50,25,10,5,OUTPUT_SIZE}: {LINEAR, RELU, RELU, RELU ,RELU ,RELU ,RELU , RELU , LINEAR }: (alpha=0.1, eta=0.9, omega=1.0, w_potency=0.019)
    {INPUT_SIZE,5,5,OUTPUT_SIZE}: {LINEAR, LINEAR, LINEAR, LINEAR}: (alpha=0.0, eta=1.0, omega=0.1, w_potency=1.0)
*/
int main(void){
    //
    for(int c_wakactx=0x00;c_wakactx>=0x00;c_wakactx--){
        printf(">> -- >> -- > [%d]\n",c_wakactx);
    }
    printf("\n------->------\n");
    set_seed();
    // Configure tsinuu
    unsigned int c_layers_sizes[TOTAL_LAYERS] = {INPUT_SIZE,5,15,15,5,OUTPUT_SIZE};
    __list_activations_t c_activations_iho[TOTAL_LAYERS] = {LINEAR, LINEAR, LINEAR, LINEAR, LINEAR, LINEAR};
    // Fabric tsinuu
    __attribute_tsinuu_t *c_attribute_tsinuu = malloc(sizeof(__attribute_tsinuu_t));
    c_attribute_tsinuu->__NUM_TOTAL_LAYERS=TOTAL_LAYERS;
    // c_attribute_tsinuu->__layers_sizes=c_layers_sizes;
    // c_attribute_tsinuu->__layers_activation=c_activations_iho;
    c_attribute_tsinuu->__layers_sizes=malloc(TOTAL_LAYERS*sizeof(unsigned int));
    c_attribute_tsinuu->__layers_activation=malloc(TOTAL_LAYERS*sizeof(__list_activations_t));
    for(unsigned int idx=0x00;idx<TOTAL_LAYERS;idx++){
        c_attribute_tsinuu->__layers_sizes[idx]=c_layers_sizes[idx];
        c_attribute_tsinuu->__layers_activation[idx]=c_activations_iho[idx];
    }
    c_attribute_tsinuu->__is_symetric=___CWCN_TRUE;
    c_attribute_tsinuu->__alpha=0.0; // alpha assert negative, is a mesure for resisting change; is if you kguht the friction of the learning; required to create new tsinuu
    c_attribute_tsinuu->__eta=1; // eta is the error impulse, required to create new tsinuu
    c_attribute_tsinuu->__omega=0.1; // required to create new tsinuu
    c_attribute_tsinuu->__wapaajco_potency=0.1; // the potency of the wapaajco
    c_attribute_tsinuu->__omega_stiffess=1.0; // #FIXME not in use
    c_attribute_tsinuu->__weight_limits=malloc(sizeof(__limits_t));
    c_attribute_tsinuu->__weight_limits->__max=5.0;
    c_attribute_tsinuu->__weight_limits->__min=-5.0;
    c_attribute_tsinuu->__bias_limits=malloc(sizeof(__limits_t));
    c_attribute_tsinuu->__bias_limits->__max=5.0;
    c_attribute_tsinuu->__bias_limits->__min=-5.0;
    __tsinuu_t *c_tsinuu = tsinuu_fabric(c_attribute_tsinuu);
    // tsinuu_initialize_weights_zero(c_tsinuu);
    // tsinuu_initialize_bias_zero(c_tsinuu);
    tsinuu_initialize_weights_random(c_tsinuu, 0.5, -0.5);
    tsinuu_initialize_bias_random(c_tsinuu, 0.5, -0.5);
    set_all_nodebooleanpardon_parametric(c_tsinuu, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
    pardon_inputoutput_bias(c_tsinuu); // #FIXME check if needed of enabled
    set_all_linebooleanpardon_parametric(c_tsinuu, 0x00, 0x00);
    // pardon_all_bias(c_tsinuu);
    // getchar();
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
    /*
        uwaabo
    */
    // fprintf(stdout, "--------->(PREV TRAINING)<---------\n");
    // for(unsigned int idx_n=0x00;idx_n<INPUT_SIZE;idx_n++){
    //     fprintf(stdout, ">>>>(after uwaabo) suspect elemenet input[%d]=%f\n",idx_n, c_correct_input_vector[idx_n]);
    // }
    // for(unsigned int idx_n=0x00;idx_n<OUTPUT_SIZE;idx_n++){
    //     fprintf(stdout, ">>>>(after uwaabo) suspect elemenet \t\toutput[%d]=%f\n",idx_n, c_output_vector[idx_n]);
    // }
    // fprintf(stdout, "--------->---------\n");
    /*
        TRAIN
    */
    // __cwcn_type_t *c_wapaajco=malloc(OUTPUT_SIZE*sizeof(__cwcn_type_t));
    // __cwcn_type_t c_set_output_vector[6][OUTPUT_SIZE]={{0,0},{0,0},{0,1},{0,1},{0,0}};
    // __cwcn_type_t c_correct_input_vector[6][INPUT_SIZE]={{0,0},{0,0},{1,0},{0,1},{1,1}};
    // __cwcn_type_t c_correct_input_vector[4][INPUT_SIZE]={{0,0,0},{0,1,0},{0,0,1},{0,1,1}};
    // __cwcn_type_t c_set_output_vector[4][OUTPUT_SIZE]={{0},{1},{1},{0}};

    // __cwcn_type_t c_correct_input_vector[DATA_COUNT][INPUT_SIZE]={{0},{1},{2},{3}};
    // __cwcn_type_t c_set_output_vector[DATA_COUNT][OUTPUT_SIZE]={{0},{1},{2},{3}};
    __cwcn_type_t c_correct_input_vector[DATA_COUNT][INPUT_SIZE]={
        {0.00},
        {0.01},{0.02},{0.03},{0.04},{0.05},{0.06},{0.07},{0.08},{0.09},{0.1},
        {0.11},{0.12},{0.13},{0.14},{0.15},{0.16},{0.17},{0.18},{0.19},{0.2},
        {0.21},{0.22},{0.23},{0.24},{0.25},{0.26},{0.27},{0.28},{0.29},{0.3},
        {0.31},{0.32},{0.33},{0.34},{0.35},{0.36},{0.37},{0.38},{0.39},{0.4},
        {0.41},{0.42},{0.43},{0.44},{0.45},{0.46},{0.47},{0.48},{0.49},{0.5},
        {0.51},{0.52},{0.53},{0.54},{0.55},{0.56},{0.57},{0.58},{0.59},{0.6},
        {0.61},{0.62},{0.63},{0.64},{0.65},{0.66},{0.67},{0.68},{0.69},{0.7},
        {0.71},{0.72},{0.73},{0.74},{0.75},{0.76},{0.77},{0.78},{0.79},{0.8},
        {0.81},{0.82},{0.83},{0.84},{0.85},{0.86},{0.87},{0.88},{0.89},{0.9},
        {0.91},{0.92},{0.93},{0.94},{0.95},{0.96},{0.97},{0.98},{0.99}};
    __cwcn_type_t c_set_output_vector[DATA_COUNT][OUTPUT_SIZE];
    for(unsigned int ctx_p=0x00;ctx_p<DATA_COUNT;ctx_p++){
        for(unsigned int idx_v=0x00;idx_v<INPUT_SIZE;idx_v++){
            // c_set_output_vector[ctx_p][idx_v]=0.5*sin(2*3.141592*1.0*c_correct_input_vector[ctx_p][idx_v])+1;
            c_set_output_vector[ctx_p][idx_v]=0.5*tanh(2*3.141592*1.0*c_correct_input_vector[ctx_p][idx_v])+1;
            // c_set_output_vector[ctx_p][idx_v]=0.5*sin(2*3.141592*1.0*c_correct_input_vector[ctx_p][idx_v])/(2*3.141592*1.0*c_correct_input_vector[ctx_p][idx_v])+1;
            fprintf(stdout, "%f -> %f\n",c_correct_input_vector[ctx_p][idx_v],c_set_output_vector[ctx_p][idx_v]);
        }
    }
    __cwcn_type_t aux_output[OUTPUT_SIZE];
    __cwcn_type_t aux_input[INPUT_SIZE];
    unsigned int rand_idx;
    for(unsigned int ctx_epoch=0x00;ctx_epoch<NUM_EPOCHS;ctx_epoch++){
        for(unsigned int ctx_p=0x00;ctx_p<DATA_COUNT;ctx_p++){
            rand_idx = rand() % DATA_COUNT;
            // rand_idx = ctx_p;
            // fprintf(stdout, " --- --- ---epoch:[ %d ] data:[ %d ] --- --- --- --- --- START ---\t",ctx_epoch,ctx_p);
            // uwaabo
            // fprintf(stdout, "%f -> %f\n",c_correct_input_vector[rand_idx][0x00],c_set_output_vector[rand_idx][0x00]);
            set_tsinuu_input(c_tsinuu, c_correct_input_vector[rand_idx]);
            tsinuu_direct_full_parametric(c_tsinuu);
            read_tsinuu_output(c_tsinuu,aux_output);
            fprintf(stdout,"[TESTING DIRECT]\t: input <%f>, output:<%f>\n",c_correct_input_vector[rand_idx][0x0],aux_output[0x0]);
            set_tsinuu_output(c_tsinuu, aux_output);
            tsinuu_inverse_full_parametric(c_tsinuu);
            read_tsinuu_input(c_tsinuu,aux_input);
            fprintf(stdout,"[TESTING INVERSE]\t: input <%f>, output:<%f>\n",aux_input[0x0],aux_output[0x0]);
            getchar();
            ... #INVERSE TSINUU IS UNDONE
        }
        // fprintf(stdout, "--------->END OF EPOCH<---------\n");
    }
    // for(bin_input = -0xF; bin_input<=0xF; bin_input++){
    //     bin_value = c_tsinuu->__nodes[0]->__direct(bin_input);
    //     printf("NAT: \t %f \t %f\n", bin_input, bin_value);
    //     if(bin_input==0xFF){break;}
    // }
    // print_layer_by_coord(_tsinuu, layer_index_to_layer_coord(_tsinuu,0x00));
    // print_node_by_coord(c_tsinuu, node_index_to_node_coord(c_tsinuu,0x00,0x00));
    // print_line_by_coord(c_tsinuu, line_index_to_line_coord(c_tsinuu, 0x00));
    print_all_lines(c_tsinuu);
    print_all_nodes(c_tsinuu);
    tsinuu_destroy(c_tsinuu);
    printf("\033[1;32mwaka dao\033[0m\n");
    printf("\033[1;32mwaka din\033[0m\n");
    printf("\033[1;32mwaka tao\033[0m\n");
}