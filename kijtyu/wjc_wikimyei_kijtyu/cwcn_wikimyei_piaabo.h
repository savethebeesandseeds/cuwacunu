#ifndef WIKIMYEI_PIAABO_INCLUDED
#define WIKIMYEI_PIAABO_INCLUDED
typedef struct __wikimyei{
    __alliu_t *__alliu;
    __duuruva_t *__duuruva;
    __cajtucu_t *__cajtucu;
    __jkimyei_t *__jkimyei;
}__wikimyei_t;
typedef struct __trayectory {
    __cwcn_type_t *__uwaabo_base;//uwaabo base;
    __cwcn_type_t *__uwaabo; // #FIXME needed?
    __cwcn_type_t *__tsane;//[NUM_TSANE];
    __cwcn_type_t *__tsane_log_prob;// #FIXME maybe is better to have aviable memory.
    __cwcn_type_t *__munaajpi_base;//
    __cwcn_type_t *__munaajpi;//[NUM_UWAABO];
    __cwcn_type_t *__uwaabo_adventage; // #FIXME needed?
} __trayectory_t;
typedef struct __load_queue { // load is a chain of pointers
    __trayectory_t *__trayectory_item;
    struct __load_queue *__down;
    struct __load_queue *__up;
} __load_queue_t;

void load_go_up(__jkimyei_t *_jkimyei);
void load_go_down(__jkimyei_t *_jkimyei);
void enqueue_load_trayectory(__jkimyei_t *_jkimyei, __trayectory_t *_new_trayectory)
// __trayectory_t *retrival_down_load_trayectory(__jkimyei_t *_jkimyei);
// __trayectory_t *retrival_up_load_trayectory(__jkimyei_t *_jkimyei);
void print_down_trayectory_queue_load(__jkimyei_t *_jkimyei);
__trayectory_t *load_get_trayectory_item(__jkimyei_t *_jkimyei);
void kill_load(__jkimyei_t *_jkimyei);

__wikimyei_t *wikimyei_fabric();
#endif