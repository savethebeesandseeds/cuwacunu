#include "cwcn_jkimyei_nebajke.h"
#include "cwcn_tsinuu_nebajke.h"
#include "cwcn_tsinuu_piaabo.h"
#ifndef JKIMYEI_PIAABO_INCLUDED
#define JKIMYEI_PIAABO_INCLUDED
typedef struct __jkimyei {
    __tsinuu_t *__uwaabo_tsinuu;
    __tsinuu_t *__munaajpi_tsinuu;
    __entropycosa_t *__ec;
    __load_queue_t *__load_batch_head;
    __jk_queue_t *__jk_batch_head;
    __cwcn_type_t *__uwaabo_loss;
    __cwcn_type_t *__munaajpi_loss;
    unsigned int __load_size;
    unsigned int __load_count;
    unsigned int __jk_size;
    unsigned int __jk_count;
    unsigned int __uwaabo_base_size;
    unsigned int __uwaabo_size;
    unsigned int __tsane_size;
    unsigned int __munaajpi_base_size;
    unsigned int __munaajpi_size;
    unsigned int __munaajpi_returns_size; // #FIXME
} __jkimyei_t;
typedef struct __jk_queue { // jk is a regular queue
    __trayectory_t *__trayectory_item;
    struct __jk_queue *__next;
} __jk_queue_t;
/*

*/
__jkimyei_t *jkimyei_fabric(...);
void jkimyei_destroy(__jkimyei_t *_jkimyei);
/*

*/
__trayectory_t *jk_dequeue_trayectory(__jkimyei_t *_jkimyei);
void jk_enqueue_trayectory(__jkimyei_t *_jkimyei, __trayectory_t *_new_trayectory);
void jk_print_trayectory_queue(__jkimyei_t *_jkimyei);
void jk_kill_queue(__jkimyei_t *_jkimyei);
__trayectory_t *jk_get_trayectory_item(__jkimyei_t *_jkimyei);

#endif