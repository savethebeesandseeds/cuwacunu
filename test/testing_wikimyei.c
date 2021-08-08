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
    fprintf(stdout,">> > ... waka0x00 empty_load: load size: %d load index: %d\n",c_wikimyei->__load_size,c_wikimyei->__load_index);
    
    // load_print_up_trayectory_queue(c_wikimyei);
    for(unsigned int f_ctx=0x00;f_ctx<3;f_ctx++){
        printf("%s ENTER TO LIVE LOAD:%s",COLOR_GOOD,COLOR_REGULAR);
        // getchar();
        begin=clock();
        wikimyei_live_load(c_wikimyei, c_size_of_load);
        end=clock();
        printf("%s exe time [wikimyei_live_load] %f:%s\n", COLOR_DANGER, (double)(end-begin)/CLOCKS_PER_SEC,COLOR_REGULAR);
        // wikimyei_live_load(c_wikimyei, 1);
        printf("%s ENTER TO JKIMYEI:%s",COLOR_GOOD,COLOR_REGULAR);
        // getchar();
        begin=clock();
        wikimyei_jkimyei(c_wikimyei, c_epochs);
        end=clock();
        printf("%s exe time [wikimyei_jkimyei] %f:%s\n", COLOR_DANGER, (double)(end-begin)/CLOCKS_PER_SEC,COLOR_REGULAR);
        printf("%s ENTER TO PRINT TRAYECOTRY:%s\n",COLOR_GOOD,COLOR_REGULAR);
        // getchar();
        load_print_up_trayectory_queue(c_wikimyei);
        // printf("%s ENTER TO PRINT TRAYECOTRY POINTERS:%s\n",COLOR_GOOD,COLOR_REGULAR);
        // // getchar();
        // load_print_up_trayectory_pointers(c_wikimyei);
        printf("%s ENTER TO PRINT MUNAAJPI REPORT:%s",COLOR_GOOD,COLOR_REGULAR);
        // getchar();
        print_report_munaajpi(c_wikimyei);
        // kill_load(c_wikimyei);
        printf("%s ENTER TO LIVE PRINT UWAABO LINES:%s",COLOR_GOOD,COLOR_REGULAR);
        // getchar();
        
        // print_all_lines(c_wikimyei->__uwaabo);
        // printf("%s ENTER TO LIVE PRINT UWAABO NODEX:%s",COLOR_GOOD,COLOR_REGULAR);
        // // getchar();
        // print_all_nodes(c_wikimyei->__uwaabo);
        // printf("%s ENTER TO LIVE LOAD AGAIN:%s",COLOR_GOOD,COLOR_REGULAR);
        // // getchar();
    }
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
    // //         // getchar();
    //     }
    // }
    destroy_wikimyei(c_wikimyei);
    printf("%s waka tao %s\n",COLOR_GOOD,COLOR_REGULAR);
    // FORGETIT FIRST TEST THE QUEUE
}