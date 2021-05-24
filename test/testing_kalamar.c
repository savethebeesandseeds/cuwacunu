#include "cwcn_kalamar_piaabo.h"
int main(){
    clock_t begin;
    clock_t end;
    char *c_kalamar_ujcamei=malloc(_KALAMAR_BUFFER_LEN_*sizeof(char));
    void *c_wikimyei=malloc(sizeof(void));
    __kalamar_t *c_kalamar=kalamar_fabric(c_wikimyei);
    while(0x1){
        mvwprintw(c_kalamar->__kl_stdscr,3,20,"\t\tkalamar_itm: '%d'",c_kalamar->__kl_itm);
        mvwprintw(c_kalamar->__kl_stdscr,4,20,"\t\tkalamar_level: '%d'",c_kalamar->__kl_level);
        begin=clock();
        kalamar_gui(c_kalamar);
        end=clock();
        mvwprintw(c_kalamar->__kl_stdscr,1,10,"exe time [kalamar_gui] %f:", (double)(end-begin)/CLOCKS_PER_SEC);
        /*  */
        klmg_key(c_kalamar);

    }
    // klmp_problem(c_kalamar,">> > <.> kalamar hellow world");
    kill_kalamar(c_kalamar);
    free(c_kalamar_ujcamei);
    free(c_wikimyei);
}