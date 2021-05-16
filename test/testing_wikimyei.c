#include "cwcn_wikimyei_piaabo.h"
int main(){

    __alliu_source_t c_alliu_source=SINE_as_alliu;
    unsigned int c_alliu_size=0x01;
    unsigned int c_tsane_size=0x02;
    unsigned int c_direct_resolution=0x010;
    unsigned int c_horizon_munaajpi=0x03;
    int c_jk_size=0x03;
    __cwcn_type_t c_gae_gamma=0x01;
    __cwcn_type_t c_gae_lambda=0x01;
    __cwcn_type_t c_clip_param=0x01;
    __cwcn_type_t c_uwaabo_beta=0x01;
    __cwcn_type_t c_munaajpi_beta=0x01;
    __cwcn_type_t c_entropy_beta=0x01;
    __cwcn_type_t c_uwaabo_waapajco_potency=0.5;
    __cwcn_type_t c_munaajpi_waapajco_potency=0.5;
    ___cwcn_bool_t c_take_tsane=___CWCN_FALSE;
    int c_size_of_load=7;
    unsigned int c_epochs=1;

    __wikimyei_t *c_wikimyei=wikimyei_fabric(
        c_alliu_source,
        c_alliu_size,
        c_tsane_size,
        c_direct_resolution,
        c_horizon_munaajpi,
        c_jk_size,
        c_gae_gamma,
        c_gae_lambda,
        c_clip_param,
        c_uwaabo_beta,
        c_munaajpi_beta,
        c_entropy_beta,
        c_uwaabo_waapajco_potency,
        c_munaajpi_waapajco_potency,
        c_take_tsane);
    
    // load_print_up_trayectory_queue(c_wikimyei);
    printf("\033[1;32m ENTER TO LIVE LOAD:\033[0m\n");
    getchar();
    clock_t begin=clock();
    wikimyei_live_load(c_wikimyei, c_size_of_load);
    clock_t end=clock();
    printf("\033[1;31m exe time [wikimyei_live_load] %f:\033[0m\n", (double)(end-begin)/CLOCKS_PER_SEC);
    // wikimyei_live_load(c_wikimyei, 1);
    printf("\033[1;32m ENTER TO JKIMYEI:\033[0m\n");
    getchar();
    wikimyei_jkimyei(c_wikimyei, c_epochs);
    printf("\033[1;32m ENTER TO PRINT TRAYECOTRY:\033[0m\n");
    getchar();
    load_print_up_trayectory_queue(c_wikimyei);
    printf("\033[1;32m ENTER TO LIVE LOAD AGAIN:\033[0m\n");
    getchar();
    wikimyei_live_load(c_wikimyei, c_size_of_load);
    
    printf("\033[1;32mwaka dao\033[0m\n");
    printf("\033[1;32mwaka din\033[0m\n");
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
    //         // getchar();
    //     }
    // }
    printf("\033[1;32mwaka tao\033[0m\n");
    destroy_wikimyei(c_wikimyei);
    // FORGETIT FIRST TEST THE QUEUE
}