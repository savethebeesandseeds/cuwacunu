#include "cwcn_wikimyei_piaabo.h"
#define DATA_COUNT 100
#define ALLIU_SIZE 1
int main(){

    // unsigned int _load_size=0x0A;
    int c_jk_size=0x05;
    __alliu_source_t c_alliu_source=SINE_as_alliu;
    unsigned int c_alliu_size=ALLIU_SIZE;
    unsigned int c_tsane_size=0x02;
    unsigned int c_direct_resolution=0x100;

    __wikimyei_t *c_wikimyei=wikimyei_fabric(
        c_jk_size,
        c_alliu_source,
        c_alliu_size,
        c_tsane_size,
        c_direct_resolution);
    
    __cwcn_type_t c_input_vector[DATA_COUNT][ALLIU_SIZE]={
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
    for(unsigned int ctx_p=0x00;ctx_p<DATA_COUNT;ctx_p++){
        __trayectory_t *c_trayectory=trayectory_fabric(c_wikimyei);
        c_trayectory->__uwaabo_base[0x00]=c_input_vector[ctx_p][0x00];
        load_enqueue_trayectory(c_wikimyei, c_trayectory);
        // getchar();
        fprintf(stdout,"\t_load_index: %d\n",c_wikimyei->__load_index);
    }
    load_print_down_trayectory_queue(c_wikimyei);
    fprintf(stdout,"\t\t%d\n",load_go_down(c_wikimyei));
    fprintf(stdout,"\t\t%d\n",load_go_down(c_wikimyei));
    fprintf(stdout,"\t\t%d\n",load_go_up(c_wikimyei));
    load_print_up_trayectory_queue(c_wikimyei);
    jk_enqueue_trayectory(c_wikimyei->__jkimyei, get_load_trayectory_item(c_wikimyei));
    jk_enqueue_trayectory(c_wikimyei->__jkimyei, get_load_trayectory_item_from_index(c_wikimyei, 11,0x1));
    jk_enqueue_trayectory(c_wikimyei->__jkimyei, get_load_trayectory_item_from_index(c_wikimyei, 12,0x1));
    jk_print_trayectory_queue(c_wikimyei->__jkimyei);
    release_jk(c_wikimyei);
    jk_print_trayectory_queue(c_wikimyei->__jkimyei);
    fill_jk_rand(c_wikimyei);
    jk_print_trayectory_queue(c_wikimyei->__jkimyei);
    printf("\033[1;32mwaka dao\033[0m\n");
    printf("\033[1;32mwaka din\033[0m\n");
    
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