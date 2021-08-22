#include "cwcn_wikimyei_piaabo.h"
int main(){
    printf("sizeofVoid: %ld \n",sizeof(void));
    clock_t begin;
    clock_t end;
    __alliu_source_t c_alliu_source=__ALLIU_SOURCE__;
    unsigned int c_alliu_source_size=__ALLIU_SOURCE_SIZE__;
    unsigned int c_tsane_size=__TSANE_SIZE__;
    unsigned int c_direct_resolution=__DIRECT_RESOLUTION__;
    unsigned int c_horizon_munaajpi=__HORIZON_MUNAAJPI__;
    __cwcn_type_t c_gae_gamma=__GAE_GAMMA__;
    __cwcn_type_t c_gae_lambda=__GAE_LAMBDA__;
    __cwcn_type_t c_clip_param=__CLIP_PARAM__;
    __cwcn_type_t c_uwaabo_beta=__UWAABO_BETA__;
    __cwcn_type_t c_munaajpi_beta=__MUNAAJPI_BETA__;
    __cwcn_type_t c_entropy_beta=__ENTROPY_BETA__;
    __cwcn_type_t c_uwaabo_waapajco_potency=__UWAABO_WAAPAJCO_POTENCY__;
    __cwcn_type_t c_munaajpi_waapajco_potency=__MUNAAJPI_WAAPAJCO_POTENCY__;
    ___cwcn_bool_t c_take_tsane=__TAKE_TSANE__;
    int c_size_of_load=__SIZE_OF_LOAD__;
    unsigned int c_epochs=__EPOCHS__;
    unsigned int c_jk_size=__JK_SIZE__;

    __wikimyei_t *c_wikimyei=wikimyei_fabric(
        c_alliu_source,\
        c_alliu_source_size,\
        c_tsane_size,\
        c_direct_resolution,\
        c_horizon_munaajpi,\
        c_jk_size,\
        c_gae_gamma,\
        c_gae_lambda,\
        c_clip_param,\
        c_uwaabo_beta,\
        c_munaajpi_beta,\
        c_entropy_beta,\
        c_uwaabo_waapajco_potency,\
        c_munaajpi_waapajco_potency,\
        c_take_tsane);

    // JK_METHOD_FORWARD_SEQUENTAL,
    // JK_METHOD_RANDOM,
    // JK_METHOD_RANDOM_POSITIVE,
    // JK_METHOD_RANDOM_NEGATIVE,
    // JK_METHOD_RANDOM_2_POSITIVE_1_NEGATIVE
    // JK_METHOD_RANDOM_3_POSITIVE_1_NEGATIVE

    for(unsigned int f_ctx=0x00;f_ctx<1;f_ctx++){       
        printf("%s ENTER TO LIVE EXPLORATION LOAD:%s\n",COLOR_GOOD,COLOR_REGULAR);
        begin=clock();      wikimyei_live_uwaabo_exploration_load       (c_wikimyei, c_size_of_load);                                           end=clock();printf("%s exe time [wikimyei_live_uwaabo_exploration_load] %f:%s\n", COLOR_DANGER, (double)(end-begin)/CLOCKS_PER_SEC,COLOR_REGULAR);
        printf("%s ENTER TO EXPLORATION JK_METHOD_RANDOM_3_POSITIVE_1_NEGATIVE:%s\n",COLOR_GOOD,COLOR_REGULAR);
        begin=clock();      wikimyei_jkimyei                            (c_wikimyei, c_epochs, JK_METHOD_RANDOM_3_POSITIVE_1_NEGATIVE);         end=clock();printf("%s exe time [wikimyei_jkimyei uwaabo exploration] %f:%s\n", COLOR_DANGER, (double)(end-begin)/CLOCKS_PER_SEC,COLOR_REGULAR);
        
        printf("%s ENTER TO LIVE LOAD ... :%s\n",COLOR_GOOD,COLOR_REGULAR);
        begin=clock();      wikimyei_live_load                          (c_wikimyei, c_size_of_load);                                           end=clock();printf("%s exe time [wikimyei_live_load] %f:%s\n", COLOR_DANGER, (double)(end-begin)/CLOCKS_PER_SEC,COLOR_REGULAR);
        printf("%s ENTER TO JK_METHOD_RANDOM_POSITIVE:%s\n",COLOR_GOOD,COLOR_REGULAR);
        begin=clock();      wikimyei_jkimyei                            (c_wikimyei, c_epochs, JK_METHOD_RANDOM_POSITIVE);                      end=clock();printf("%s exe time [wikimyei_jkimyei] %f:%s\n", COLOR_DANGER, (double)(end-begin)/CLOCKS_PER_SEC,COLOR_REGULAR);
    }
    //
    printf("%s ENTER TO LIVE LOAD:%s\n",COLOR_GOOD,COLOR_REGULAR);
    begin=clock();          wikimyei_live_load                          (c_wikimyei, c_size_of_load);                                           end=clock();printf("%s exe time [wikimyei_live_load] %f:%s\n", COLOR_DANGER, (double)(end-begin)/CLOCKS_PER_SEC,COLOR_REGULAR);
    
    printf("uwaabo sum_weights: %f\n",sum_all_weights(c_wikimyei->__uwaabo->__uwaabo_tsinuu));
    printf("uwaabo sum_biases : %f\n",sum_all_biases(c_wikimyei->__uwaabo->__uwaabo_tsinuu));
    printf("munaajpi sum_weights: %f\n",sum_all_weights(c_wikimyei->__munaajpi->__munaajpi_tsinuu));
    printf("munaajpi sum_biases : %f\n",sum_all_biases(c_wikimyei->__munaajpi->__munaajpi_tsinuu));
    // 
    // getchar();

    printf("%s ENTER TO PRINT TRAYECOTRY:%s\n",COLOR_GOOD,COLOR_REGULAR);
    getchar();
    load_print_up_trayectory_queue(c_wikimyei);
    printf("%s ENTER TO PRINT WAJYU METRIC REPORT:%s\n",COLOR_GOOD,COLOR_REGULAR);
    getchar();
    print_wayiu_metric_report(c_wikimyei->__wajyu);
    printf("%s waka dao %s\n",COLOR_GOOD,COLOR_REGULAR);
    printf("%s waka din %s\n",COLOR_GOOD,COLOR_REGULAR);
    // load_print_down_trayectory_queue(c_wikimyei);
    // fprintf(stdout,"\t\t%d\n",load_go_down(c_wikimyei));
    // fprintf(stdout,"\t\t%d\n",load_go_down(c_wikimyei));
    // fprintf(stdout,"\t\t%d\n",load_go_up(c_wikimyei));
    // load_print_up_trayectory_queue(c_wikimyei);
    // jk_enqueue_trayectory(c_wikimyei->__jkimyei, get_load_trayectory_item(c_wikimyei));
    // jk_enqueue_trayectory(c_wikimyei->__jkimyei, get_load_trayectory_item_from_index(c_wikimyei, 11,0x1));
    // jk_enqueue_trayectory(c_wikimyei->__jkimyei, get_load_trayectory_item_from_index(c_wikimyei, 12,0x1));
    
    // fprintf(stdout,"FIRST_STATE: %9.2f\n",c_wikimyei->__jkimyei->__jk_batch_head->__trayectory_item->__uwaabo_base[0x00]);
    // fprintf(stdout,"\t_load_index: %d\n",c_wikimyei->__jkimyei->__jk_index);
    // // fprintf(stdout,"\t\t%2.2f\n",jk_dequeue_trayectory(c_wikimyei->__jkimyei)->__uwaabo_base[0x00]);
    // // fprintf(stdout,"\t\t%2.2f\n",jk_dequeue_trayectory(c_wikimyei->__jkimyei)->__uwaabo_base[0x00]);
    // // fprintf(stdout,"\t\t%2.2f\n",jk_dequeue_trayectory(c_wikimyei->__jkimyei)->__uwaabo_base[0x00]);
    // // fprintf(stdout,"\t\t%2.2f\n",jk_dequeue_trayectory(c_wikimyei->__jkimyei)->__uwaabo_base[0x00]);
    // // fprintf(stdout,"\t\t%2.2f\n",jk_dequeue_trayectory(c_wikimyei->__jkimyei)->__uwaabo_base[0x00]);
    // // fprintf(stdout,"\t\t%2.2f\n",jk_dequeue_trayectory(c_wikimyei->__jkimyei)->__uwaabo_base[0x00]);
    // // fprintf(stdout,"\t\t%2.2f\n",jk_dequeue_trayectory(c_wikimyei->__jkimyei)->__uwaabo_base[0x00]);
    // // fprintf(stdout,"\t\t%2.2f\n",jk_dequeue_trayectory(c_wikimyei->__jkimyei)->__uwaabo_base[0x00]);
    // // fprintf(stdout,"\t\t%2.2f\n",jk_dequeue_trayectory(c_wikimyei->__jkimyei)->__uwaabo_base[0x00]);
    // // // fprintf(stdout,"\t\t%f\n",jk_dequeue_trayectory(c_wikimyei->__jkimyei)->__uwaabo_base[0x00]);
    // fprintf(stdout,"FIRST_STATE: %9.2f\n",c_wikimyei->__jkimyei->__jk_batch_head->__trayectory_item->__uwaabo_base[0x00]);
    // fprintf(stdout,"\t_load_index: %d\n",c_wikimyei->__jkimyei->__jk_index);
    
    // wapaajco_bydifference(c_tsinuu, c_correct_output[ctx_p]);
    // for(unsigned int ctx_epoch=0x00;ctx_epoch<0x01;ctx_epoch++){
    //     for(unsigned int ctx_p=0x00;ctx_p<DATA_COUNT;ctx_p++){
    //         jkimyei_tsinuu_bydirectNABLA(c_tsinuu);
    // //         // 
    // getchar();
    //     }
    // }
    destroy_wikimyei(c_wikimyei);
    printf("%s waka tao %s\n",COLOR_GOOD,COLOR_REGULAR);
    // FORGETIT FIRST TEST THE QUEUE
}