#ifndef WIKIMYEI_PIAABO_INCLUDED
#define WIKIMYEI_PIAABO_INCLUDED
#define WIKIMYEI_DEBUG
// #define WIKIMYEI_DEBUG_v2
// #define WIKIMYEI_DEBUG_v3
// #define DEBUG_DUURUVA
typedef _Bool (___cwcn_bool_t);
#define ___CWCN_TRUE (___cwcn_bool_t) 0b1
#define ___CWCN_FALSE (___cwcn_bool_t) 0b0
#define max(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a > _b ? _a : _b;})
#define min(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a < _b ? _a : _b;})
#include "cwcn_munaajpi_piaabo.h"
typedef struct __wk_flags {
    ___cwcn_bool_t __done;
    ___cwcn_bool_t __nonuwaabo_alliu_done;
    ___cwcn_bool_t __endhead_empty_alliu;
    ___cwcn_bool_t __alliu_duuruva_ready;
    ___cwcn_bool_t __munaajpi_duuruva_ready;
    ___cwcn_bool_t __adventage_duuruva_ready;
} __wk_flags_t;
typedef struct __trayectory { // #FIXME too many fields
    __cwcn_type_t *__alliu_state;// ...
    __cwcn_type_t *__nonuwaabo_alliu_state;
    __cwcn_type_t *__alliu_duuruva_state;
    __cwcn_type_t __uwaabo_mask;
    __cwcn_type_t *__uwaabo_state;
    __cwcn_type_t *__uwaabo_returns;
    __cwcn_type_t *__uwaabo_adventage;
    __cwcn_type_t *__tsane_state;
    __cwcn_type_t __entropy;
    __cwcn_type_t *__munaajpi_state; //... these are the uwaabo waapajco parameteres, munaajpi wapaajco is imibajcho_munaajpi
    unsigned int __pending_munaajpi_index;
    ___cwcn_bool_t __pending_munaajpi;
    __cwcn_type_t *__imibajcho_munaajpi_state;// this is J, varies while pending_munaajpi_index
    __cwcn_type_t *__imibajcho_munaajpi_duuruva_state;
} __trayectory_t;
// typedef struct __jk_queue { // jk is but a regular queue
//     __trayectory_t *__trayectory_item;
//     struct __jk_queue *__next;
// } __jk_queue_t;
typedef void (*__jk_function_pointer_t)(
        void*,
        __cwcn_type_t*,
        __cwcn_type_t*,
        __cwcn_type_t*,
        __cwcn_type_t*);
typedef struct __jkimyei {
    // __jk_queue_t *__jk_batch_head;
    // int __jk_index;
    int __jk_size;
    __jk_function_pointer_t __jk_one;
} __jkimyei_t;
typedef struct __load_queue { // load is a chain of pointers
    __trayectory_t *__trayectory_item;
    struct __load_queue *__down;
    struct __load_queue *__up;
} __load_queue_t;
#include "cwcn_cajtucu_piaabo.h"
#include "cwcn_ujcamei_piaabo.h"
#include "cwcn_entropy_nebajke.h"
#include "cwcn_duuruva_nebajke.h"
#include "cwcn_kemu_piaabo.h"
#include "cwcn_tsinuu_piaabo.h"
#include "cwcn_tsinuu_nebajke.h"
#include "cwcn_uwaabo_piaabo.h"
typedef struct __wikimyei {
    int __load_index;
    int __load_size;
    unsigned int __jk_size;
    unsigned int __horizon_munaajpi;
    unsigned int __direct_resolution;
    unsigned int __alliu_state_size;
    unsigned int __alliu_duuruva_state_size;
    unsigned int __munaajpi_duuruva_state_size;
    unsigned int __adventage_duuruva_state_size;
    unsigned int __uwaabo_base_size;
    unsigned int __uwaabo_state_size;
    unsigned int __tsane_state_size;
    unsigned int __munaajpi_base_size;
    unsigned int __munaajpi_state_size;
    unsigned int __imibajcho_munaajpi_duuruva_state_size;
    __cwcn_type_t __gae_gamma;
    __cwcn_type_t __gae_lambda;
    __cwcn_type_t __clip_param;
    __cwcn_type_t __uwaabo_beta;
    __cwcn_type_t __munaajpi_beta;
    __cwcn_type_t __entropy_beta;
    __jkimyei_t *__jkimyei;
    __entropycosa_t *__ec;
    __alliu_t *__alliu;
    __duuruva_t *__alliu_duuruva;
    __tsinuu_t *__uwaabo;
    __tsane_t *__tsane;
    __tsinuu_t *__munaajpi;
    __duuruva_t *__munaajpi_duuruva;
    __duuruva_t *__adventage_duuruva;
    __load_queue_t *__load_batch_head;
    ___cwcn_bool_t __take_tsane;
    __wk_flags_t *__flags;
    __cwcn_type_t *__munaajpi_base_w_state; // the temporal base hold in wikimyei struct of a redundant concatenated vector
}__wikimyei_t;
#include "cwcn_jkimyei_nebajke.h"
#include "cwcn_wikimyei_nebajke.h"
__wikimyei_t *wikimyei_fabric(
        __alliu_source_t _alliu_source,
        unsigned int _alliu_size,
        unsigned int _tsane_size,
        unsigned int _direct_resolution,
        unsigned int _horizon_munaajpi,
        int _jk_size,
        __cwcn_type_t _gae_gamma,
        __cwcn_type_t _gae_lambda,
        __cwcn_type_t _clip_param,
        __cwcn_type_t _uwaabo_beta,
        __cwcn_type_t _munaajpi_beta,
        __cwcn_type_t _entropy_beta,
        __cwcn_type_t _uwaabo_waapajco_potency,
        __cwcn_type_t _munaajpi_waapajco_potency,
        ___cwcn_bool_t _take_tsane);
int load_go_up(__wikimyei_t *_wikimyei);
int load_go_down(__wikimyei_t *_wikimyei);
void load_to_start(__wikimyei_t *_wikimyei);
void load_to_end(__wikimyei_t *_wikimyei);
void load_to_index(__wikimyei_t *_wikimyei, int _index);
int load_enqueue_trayectory(__wikimyei_t *_wikimyei, __trayectory_t *_new_trayectory);
__trayectory_t *get_load_trayectory_item(__wikimyei_t *_wikimyei);
__trayectory_t *glti(__wikimyei_t *_wikimyei);
__trayectory_t *get_load_trayectory_item_from_index(__wikimyei_t *_wikimyei, int _index, ___cwcn_bool_t _rneturn); // #FIXME stabilize the non unsigned (needed by load/jk fabrics)
__trayectory_t *trayectory_fabric(__wikimyei_t *_wikimyei);
__load_queue_t *load_fabric(__wikimyei_t *_wikimyei);
void load_print_up_trayectory_queue(__wikimyei_t *_wikimyei);
void load_print_down_trayectory_queue(__wikimyei_t *_wikimyei);
void kill_load(__wikimyei_t *_wikimyei);
void kill_trayectory(__trayectory_t *_trayectory);
void destroy_wikimyei(__wikimyei_t *_wikimyei);
___cwcn_bool_t all_duuruva_ready(__wikimyei_t *_wikimyei);
#endif