#ifndef WIKIMYEI_PIAABO_INCLUDED
#define WIKIMYEI_PIAABO_INCLUDED
#define COLOR_TSANE "\x1B[0;34m"
#define COLOR_MUNAAJPI "\x1B[0;33m"
#define COLOR_B_MUNAAJPI "\x1B[1;33m"
#define COLOR_GAE "\033[0;32m"
#define COLOR_GOOD "\033[1;32m"
#define COLOR_DANGER "\033[0;31m"
#define COLOR_ALLIU "\x1B[0;36m"
#define COLOR_REGULAR "\033[0m"
#define COLOR_ENTROPY "\033[0m"
#define COLOR_WARNING "\033[0;31m"
#define COLOR_UWAABO "\x1B[0;35m"
#define COLOR_JKIMYEI "\x1B[0;32m"
// #define DEBUG_LINEAR_EXPERIMENT
// #define TSINUU_DEBUG
#define WIKIMYEI_DEBUG
#define WIKIMYEI_DEBUG_v2
#define WIKIMYEI_DEBUG_v3
#define WIKIMYEI_DEBUG_v4
#define WIKIMYEI_DEBUG_v5
// #define DEBUG_DUURUVA
// #define JKIMYEI_DEBUG
// #define JKIMYEI_DEBUG_v2
// #define MUNAAJPI_DEBUG

#define BUGGER_SIZE_DUURUVA (unsigned int) 10
#define BUGGER_READY_DUURUVA_COUNT (unsigned int) 5
#define BUGGER_MAX_DUURUVA_COUNT (__cwcn_type_t) 100.0
#define BUGGER_DUURUVA_MIN_STD (float) 0.0001

typedef _Bool (___cwcn_bool_t);
#define ___CWCN_TRUE (___cwcn_bool_t) 0b1
#define ___CWCN_FALSE (___cwcn_bool_t) 0b0
typedef float (__cwcn_type_t);
#define __cwcn_type_size sizeof(__cwcn_type_t) // #FIXME not in use
typedef __cwcn_type_t (*__function_pointer_t)(__cwcn_type_t);
#define __function_pointer_t_size sizeof(__function_pointer_t)
#define __cwcn_infinite (__cwcn_type_t) 0xFFFFFFFF

#define _DEFAULT_NORM_STAND_ (___cwcn_bool_t) 0x0

#define max(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a > _b ? _a : _b;})
#define min(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a < _b ? _a : _b;})
typedef struct __wk_flags {
    ___cwcn_bool_t __done;
    ___cwcn_bool_t __nonuwaabo_alliu_done;
    ___cwcn_bool_t __endhead_empty_alliu;
    ___cwcn_bool_t __alliu_duuruva_ready;
    ___cwcn_bool_t __munaajpi_duuruva_ready;
    ___cwcn_bool_t __adventage_duuruva_ready;
    ___cwcn_bool_t __norm_stand; // 
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
    __load_queue_t *__load_down;
    __load_queue_t *__load_up;
    __load_queue_t *__load_head;
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
    ___cwcn_bool_t __take_tsane;
    __wk_flags_t *__flags;
    __cwcn_type_t *__munaajpi_base_w_state; // the temporal base hold in wikimyei struct of a redundant concatenated vector
}__wikimyei_t;
#include "cwcn_munaajpi_piaabo.h"
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
void load_print_up_trayectory_pointers(__wikimyei_t *_wikimyei);
void load_print_up_trayectory_queue(__wikimyei_t *_wikimyei);
void load_print_down_trayectory_queue(__wikimyei_t *_wikimyei);
void kill_load(__wikimyei_t *_wikimyei);
// void kill_queue_item(__load_queue_t *_load_head); // #FIXME if needed
void kill_trayectory(__trayectory_t *_trayectory);
void destroy_wikimyei(__wikimyei_t *_wikimyei);
___cwcn_bool_t all_duuruva_ready(__wikimyei_t *_wikimyei);
___cwcn_bool_t load_is_empty(__wikimyei_t *_wikimyei);
void empty_load(__wikimyei_t *_wikimyei);
void printflags(__wikimyei_t *_wikimyei);
#endif