#include "cwcn_jkimyei_nebajke.h"
#include "cwcn_tsinuu_nebajke.h"
#include "cwcn_tsinuu_piaabo.h"
#ifndef JKIMYEI_PIAABO_INCLUDED
#define JKIMYEI_PIAABO_INCLUDED
typedef struct __trayectory {
    __cwcn_type_t *__duuruva;//[NUM_DUURUVA];
    __cwcn_type_t *__tsane;//[NUM_TSANE];
    __cwcn_type_t *__tsane_log_prob;// #FIXME maybe is better to have aviable memory.
    __cwcn_type_t *__munaajpi_returns;//[NUM_UWAABO];
} __trayectory_t;
typedef struct __jkimyei {
    __tsinuu_t *__uwaabo_tsinuu;
    __tsinuu_t *__munaajpi_tsinuu;
    __load_queue_t *__load_batch_head;
    __jk_queue_t *__jk_batch_head;
    __cwcn_type_t *__uwaabo_loss;
    __cwcn_type_t *__munaajpi_loss;
    unsigned int __load_size;
    unsigned int __load_count;
    unsigned int __jk_size;
    unsigned int __jk_count;
    unsigned int __num_duuruva;
    unsigned int __num_tsane;
    unsigned int __num_munaajpi_returns;
} __jkimyei_t;
typedef struct __jk_queue {
    __trayectory_t *__trayectory_item;
    struct __jk_queue *__next;
} __jk_queue_t;
typedef struct __load_queue {
    __trayectory_t *__trayectory_item;
    struct __load_queue *__down;
    struct __load_queue *__up;
} __load_queue_t;
/*

*/
__jkimyei_t *jkimyei_fabric(
        unsigned int _load_size, 
        unsigned int _jk_size, 
        unsigned int _num_duuruva, 
        unsigned int _num_tsane, 
        unsigned int _num_munaajpi_returns);
__trayectory_t *dequeue_trayectory(__jkimyei_t *__jkimyei);
void enqueue_trayectory(__jkimyei_t *__jkimyei, __trayectory_t *_new_trayectory);
void print_trayectory_queue(__jkimyei_t *__jkimyei);

void load_go_up(__jkimyei_t *__jkimyei);
void load_go_down(__jkimyei_t *__jkimyei);
void enqueue_load_trayectory(__jkimyei_t *__jkimyei, __trayectory_t *_new_trayectory)
// __trayectory_t *retrival_down_load_trayectory(__jkimyei_t *__jkimyei);
// __trayectory_t *retrival_up_load_trayectory(__jkimyei_t *__jkimyei);
void print_down_trayectory_queue_load(__jkimyei_t *__jkimyei);
void kill_load(__jkimyei_t *__jkimyei);
#endif