#ifndef WIKIMYEI_PIAABO_INCLUDED
#define WIKIMYEI_PIAABO_INCLUDED
#include "cwcn_cajtucu_piaabo.h"
#include "cwcn_ujcamei_piaabo.h"
#include "cwcn_entropy_nebajke.h"
#include "cwcn_duuruva_nebajke.h"
#include "cwcn_kemu_piaabo.h"
#include "cwcn_munaajpi_piaabo.h"
#include "cwcn_tsinuu_piaabo.h"
#include "cwcn_tsinuu_nebajke.h"
#include "cwcn_uwaabo_piaabo.h"
typedef _Bool (___cwcn_bool_t);
#define ___CWCN_TRUE (___cwcn_bool_t) 0b1
#define ___CWCN_FALSE (___cwcn_bool_t) 0b0
#define max(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a > _b ? _a : _b;})
#define min(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a < _b ? _a : _b;})
typedef struct __wikimyei_states {
    __cwcn_type_t *__alliu_state;
    __cwcn_type_t *__duuruva_state;
    __cwcn_type_t *__uwaabo_state;
    __cwcn_type_t *__munaajpi_state;
    __cwcn_type_t *__tsane_state;
}__wikimyei_states_t;
typedef struct __trayectory { // #FIXME too many fields
    __cwcn_type_t *__uwaabo_base;//uwaabo base;
    __cwcn_type_t *__uwaabo_state; // #FIXME needed?
    __cwcn_type_t *__tsane_state;//[NUM_TSANE];
    __cwcn_type_t *__tsane_log_prob;// #FIXME maybe is better to have aviable memory.
    __cwcn_type_t *__munaajpi_base;//
    __cwcn_type_t *__munaajpi_state;//[NUM_UWAABO];
    __cwcn_type_t *__uwaabo_adventage; // #FIXME needed?
} __trayectory_t;
typedef struct __jk_queue { // jk is a regular queue
    __trayectory_t *__trayectory_item;
    struct __jk_queue *__next;
} __jk_queue_t;
typedef struct __jkimyei {
    __jk_queue_t *__jk_batch_head;
    int __jk_size;
    int __jk_index;
} __jkimyei_t;
// #include "cwcn_wikimyei_piaabo.h"
typedef struct __load_queue { // load is a chain of pointers
    __trayectory_t *__trayectory_item;
    struct __load_queue *__down;
    struct __load_queue *__up;
} __load_queue_t;
typedef struct __wikimyei {
    int __load_index;
    int __load_size;
    unsigned int __direct_resolution;
    unsigned int __alliu_state_size;
    unsigned int __uwaabo_base_size;
    unsigned int __uwaabo_state_size;
    unsigned int __tsane_state_size;
    unsigned int __munaajpi_base_size;
    unsigned int __munaajpi_state_size;
    __jkimyei_t *__jkimyei;
    __alliu_t *__alliu;
    __duuruva_t *__duuruva;
    __tsane_t *__tsane;
    __entropycosa_t *__ec;
    __tsinuu_t *__uwaabo;
    __tsinuu_t *__munaajpi;
    __load_queue_t *__load_batch_head;
    __wikimyei_states_t *__wk_states;
}__wikimyei_t;
#include "cwcn_jkimyei_piaabo.h"
#include "cwcn_wikimyei_nebajke.h"
__wikimyei_t *wikimyei_fabric(
        int _jk_size,
        __alliu_source_t _alliu_source,
        unsigned int _alliu_size,
        unsigned int _tsane_size,
        unsigned int _direct_resolution);
int load_go_up(__wikimyei_t *_wikimyei);
int load_go_down(__wikimyei_t *_wikimyei);
int load_enqueue_trayectory(__wikimyei_t *_wikimyei, __trayectory_t *_new_trayectory);
__trayectory_t *get_load_trayectory_item(__wikimyei_t *_wikimyei);
__trayectory_t *get_load_trayectory_item_from_index(__wikimyei_t *_wikimyei, int _index, ___cwcn_bool_t _rneturn); // #FIXME stabilize the non unsigned (needed by load/jk fabrics)
__trayectory_t *trayectory_fabric(__wikimyei_t *_wikimyei);
__load_queue_t *load_fabric(__wikimyei_t *_wikimyei);
void load_print_up_trayectory_queue(__wikimyei_t *_wikimyei);
void load_print_down_trayectory_queue(__wikimyei_t *_wikimyei);
__wikimyei_states_t *wikimyei_states_fabric(__wikimyei_t *_wikimyei);
void kill_load(__wikimyei_t *_wikimyei);
void kill_trayectory(__trayectory_t *_trayectory);
void kill_wikimyei_states(__wikimyei_states_t *_wk_states);
void destroy_wikimyei(__wikimyei_t *_wikimyei);

#endif