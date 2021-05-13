#include "cwcn_wikimyei_piaabo.h"
#define DATA_COUNT 100
#define ALLIU_SIZE 1
int main(){

    // unsigned int _load_size=0x0A;
    int c_jk_size=0x05;
    __alliu_source_t c_alliu_source=SINE_as_alliu;
    unsigned int c_alliu_size=ALLIU_SIZE;
    unsigned int c_tsane_size=0x02;
    unsigned int c_direct_resolution=0x090;
    unsigned int c_horizon_munaajpi=0x02;
    __cwcn_type_t c_gae_gamma..
    __cwcn_type_t c_gae_lambda...
    __cwcn_type_t c_clip_param...
    __wikimyei_t *c_wikimyei=wikimyei_fabric(
        c_jk_size,
        c_alliu_source,
        c_alliu_size,
        c_tsane_size,
        c_direct_resolution,
        c_horizon_munaajpi,
        c_gae_gamma,
        c_gae_lambda,
        c_clip_param);
    int c_size_of_load=100;
    wikimyei_live_load(c_wikimyei, c_size_of_load);
    wikimyei_jkimyei(__wikimyei_t *_wikimyei, unsigned int _epochs);
    
    // load_print_down_trayectory_queue(c_wikimyei);
    // fprintf(stdout,"\t\t%d\n",load_go_down(c_wikimyei));
    // fprintf(stdout,"\t\t%d\n",load_go_down(c_wikimyei));
    // fprintf(stdout,"\t\t%d\n",load_go_up(c_wikimyei));
    // load_print_up_trayectory_queue(c_wikimyei);
    // jk_enqueue_trayectory(c_wikimyei->__jkimyei, get_load_trayectory_item(c_wikimyei));
    // jk_enqueue_trayectory(c_wikimyei->__jkimyei, get_load_trayectory_item_from_index(c_wikimyei, 11,0x1));
    // jk_enqueue_trayectory(c_wikimyei->__jkimyei, get_load_trayectory_item_from_index(c_wikimyei, 12,0x1));
    // printf("\033[1;32mwaka dao\033[0m\n");
    // printf("\033[1;32mwaka din\033[0m\n");
    
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
    destroy_wikimyei(c_wikimyei);
    printf("\033[1;32mwaka tao\033[0m\n");
    // FORGETIT FIRST TEST THE QUEUE
}