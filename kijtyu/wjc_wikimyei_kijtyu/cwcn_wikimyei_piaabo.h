#ifndef WIKIMYEI_PIAABO_INCLUDED
#define WIKIMYEI_PIAABO_INCLUDED

/* MACRO UTILS */

typedef _Bool (___cwcn_bool_t);
#define ___CWCN_TRUE (___cwcn_bool_t) 0b1
#define ___CWCN_FALSE (___cwcn_bool_t) 0b0
#define print_cwcn_bool(a)((!!a == !!___CWCN_TRUE)?"TRUE":"FALSE")
typedef float (__cwcn_type_t); // #FIXME double is necesary for float in pow(.) deb.
#define __cwcn_type_size sizeof(__cwcn_type_t) // #FIXME not in use
typedef __cwcn_type_t (*__function_pointer_t)(__cwcn_type_t);
#define __function_pointer_t_size sizeof(__function_pointer_t)
#define __cwcn_infinite (__cwcn_type_t) 0xFFFFFFFF
#define max(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a > _b ? _a : _b;})
#define min(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a < _b ? _a : _b;})

/* GENERAL CONFIGURATIONS */

// #define DEBUG_LINEAR_EXPERIMENT

#define COLOR_TSANE "\x1B[0;34m"
#define COLOR_MUNAAJPI "\x1B[0;33m"
#define COLOR_B_MUNAAJPI "\x1B[1;33m"
#define COLOR_GAE "\033[0;32m"
#define COLOR_L_GOOD "\033[0;32m"
#define COLOR_ALOCATION_ADD "\033[0;32m"
#define COLOR_ALOCATION_KIL "\033[0;31m"
#define COLOR_GOOD "\033[1;32m"
#define COLOR_DANGER "\033[0;31m"
#define COLOR_ALLIU "\x1B[0;36m"
#define COLOR_REGULAR "\033[0m"
#define COLOR_ENTROPY "\033[0m"
#define COLOR_DUURUVA "\033[0m"
#define COLOR_WARNING "\033[0;31m"
#define COLOR_UWAABO "\x1B[0;35m"
#define COLOR_JKIMYEI "\x1B[0;32m"
#define COLOR_HEALT "\033[0;31m"
// #define UWAABO_DEBUG
// #define TSINUU_DEBUG
// #define TSINUU_DEBUG_v2
// #define WIKIMYEI_DEBUG
// #define WIKIMYEI_DEBUG_v2
#define ENTROPY_DEBUG
// #define ENTROPY_DEBUG_v1
// #define ENTROPY_DEBUG_v2
// #define ALOCATION_DEBUG
// #define WIKIMYEI_DEBUG_LOAD
// #define WIKIMYEI_DEBUG_HEALT
// #define DUURUVA_DEBUG
// #define JKIMYEI_DEBUG
// #define JKIMYEI_DEBUG_v2
// #define MUNAAJPI_DEBUG

#define __JK_SIZE__ (unsigned int) 0x0F
#define __EPOCHS__ (unsigned int) 0x01

#define __GAE_GAMMA__ (__cwcn_type_t) 0.99
#define __GAE_LAMBDA__ (__cwcn_type_t) 0.95
#define __CLIP_PARAM__ (__cwcn_type_t) 0.2
#define __UWAABO_BETA__ (__cwcn_type_t) 0.01
#define __MUNAAJPI_BETA__ (__cwcn_type_t) 0.01
#define __ENTROPY_BETA__ (__cwcn_type_t) 0.001 // #FIXME findme
#define __UWAABO_WAAPAJCO_POTENCY__ (__cwcn_type_t) 10.0
#define __MUNAAJPI_WAAPAJCO_POTENCY__ (__cwcn_type_t) 10.0

#define __TAKE_TSANE__ (___cwcn_bool_t) ___CWCN_FALSE
#define __TSANE_SIZE__ (usingied int) 0x02 
#define __ALLIU_SIZE__ (unsigned int) 0x01 // vector dimension size
#define __SIZE_OF_LOAD__ (int) 0x0A

#define __NUM_BASE_DUURUVA__ (unsigned int) 0x11
#define __HORIZON_MUNAAJPI__ (unsigned int) 0x02
#define __DIRECT_RESOLUTION__ (unsigned int) 0x20

#ifndef DEBUG_LINEAR_EXPERIMENT
#define __ALLIU_SOURCE__ (__alliu_source_t) SINE_as_alliu;
#else
#define __ALLIU_SOURCE__ (__alliu_source_t) UNIT_as_alliu;
#endif

#define __EXPAND_ALLIU_DUURUVA__ // apply duuruva transformation to alliu 
#define __EXPAND_IMIBAJCHO_MUNAAJPI_DUURUVA__ // apply duuruva transformation to imibacho munaajpi

#define BUGGER_SIZE_DUURUVA (unsigned int) 12
#define BUGGER_READY_DUURUVA_COUNT (unsigned int) 5
#define BUGGER_MAX_DUURUVA_COUNT (__cwcn_type_t) 100.0
#define BUGGER_DUURUVA_MIN_STD (float) 0.0001

#define _DEFAULT_NORM_STAND_ (___cwcn_bool_t) 0x0
/*
    UWAABO_DUURUVA: (use to set mask)
        [0x0] : value
        [0x1] : __diff_1
        [0x2] : __diff_2
        [0x3] : __max
        [0x4] : __min
        [0x5] : __std
        [0x6] : __mean
        [0x7] : __M2
        [0x8] : __M3
        [0x9] : __M4
        [0xA] : __kurtosis
        [0xB] : __skewness
*/
#ifdef __EXPAND_ALLIU_DUURUVA__
#define _UWABO_DUURUVA_MASK_ (__cwcn_type_t[BUGGER_SIZE_DUURUVA]) {\ // to be use in trayectory
        0x1, \
        0x1, \
        0x0, \
        0x0, \
        0x0, \
        0x0, \
        0x0, \
        0x0, \
        0x0, \
        0x0, \
        0x0, \
        0x0}
#endif
#ifdef __EXPAND_IMIBAJCHO_MUNAAJPI_DUURUVA__
#define _IMIBAJCHO_MUNAAJPI_DUURUVA_MASK_ (__cwcn_type_t[BUGGER_SIZE_DUURUVA]) {\ // to be use in trayectory
        0x1, \
        0x0, \
        0x0, \
        0x0, \
        0x0, \
        0x0, \
        0x0, \
        0x0, \
        0x0, \
        0x0, \
        0x0, \
        0x0}
#endif

/* WIKIMYEI DEFINITIONS */

typedef struct __wk_flags {
    ___cwcn_bool_t __done;
    ___cwcn_bool_t __nonuwaabo_alliu_done;
    ___cwcn_bool_t __endhead_empty_alliu;
    ___cwcn_bool_t ...__wajyu_duuruva_ready;
    ___cwcn_bool_t __norm_stand; // 
} __wk_flags_t;
typedef struct __trayectory { // #FIXME too many fields
    __cwcn_type_t *__alliu_state;// ...
    __cwcn_type_t *__nonuwaabo_alliu_state;
    __cwcn_type_t __uwaabo_mask; // #FIXME assert if is used
    __cwcn_type_t *__uwaabo_state;
    __cwcn_type_t *__uwaabo_returns;
    __cwcn_type_t *__uwaabo_adventage;
    __cwcn_type_t *__tsane_state;
    __cwcn_type_t __entropy;
    __cwcn_type_t *__munaajpi_state; //... these are the uwaabo waapajco parameteres, munaajpi wapaajco is imibajcho_munaajpi
    ___cwcn_bool_t __pending_munaajpi;
    __cwcn_type_t *__imibajcho_munaajpi_state;// this is J, varies while pending_munaajpi_index
    unsigned int __pending_munaajpi_index;
    #ifdef __EXPAND_ALLIU_DUURUVA__
    __cwcn_type_t *__alliu_duuruva_state;
    #endif
    #ifdef __EXPAND_IMIBAJCHO_MUNAAJPI_DUURUVA__
    __cwcn_type_t *__imibajcho_munaajpi_duuruva_state;
    #endif
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
    struct __load_queue **__down;
    struct __load_queue **__up;
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
    __load_queue_t *__load_head;
    // __load_queue_t **__load_down; // these two are redundant (on NON_C.__load_queue_t*[(_down)__load_head]) but usefull
    // __load_queue_t **__load_up; // these two are redundant (on NON_C.__load_queue_t*[(_up)__load_head]) but usefull
    unsigned int __jk_size;
    unsigned int __horizon_munaajpi;
    unsigned int __direct_resolution;
    unsigned int __alliu_state_size;
    unsigned int __uwaabo_base_size;
    unsigned int __uwaabo_state_size;
    unsigned int __tsane_state_size;
    unsigned int __munaajpi_base_size;
    unsigned int __munaajpi_state_size;
    #ifdef __EXPAND_ALLIU_DUURUVA_
    unsigned int ...__alliu_duuruva_state_size;
    #endif
    __wajyu_t *__wajyu;
    __cwcn_type_t __gae_gamma;
    __cwcn_type_t __gae_lambda;
    __cwcn_type_t __clip_param;
    __cwcn_type_t __uwaabo_beta;
    __cwcn_type_t __munaajpi_beta;
    __cwcn_type_t __entropy_beta;
    __jkimyei_t *__jkimyei;
    __entropycosa_t *__ec;
    __alliu_t *__alliu;
    __uwaabo_t *__uwaabo;
    __tsane_t *__tsane;
    ___cwcn_bool_t __take_tsane;
    __wk_flags_t *__flags;
    __cwcn_type_t *__munaajpi_base_w_state; // the temporal base hold in wikimyei struct of a redundant concatenated vector (what?)
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
int yield_next_trayectory(__wikimyei_t *_wikimyei);
__load_queue_t *queue_item_fabric(__wikimyei_t *_wikimyei,__trayectory_t *_trayectory);
__trayectory_t *get_load_trayectory_item(__wikimyei_t *_wikimyei);
__trayectory_t *glti(__wikimyei_t *_wikimyei);
__trayectory_t *get_load_trayectory_item_from_index(__wikimyei_t *_wikimyei, int _index, ___cwcn_bool_t _rneturn); // #FIXME stabilize the non unsigned (needed by load/jk fabrics)
__trayectory_t *trayectory_fabric(__wikimyei_t *_wikimyei);
__load_queue_t *load_fabric(__wikimyei_t *_wikimyei);
void load_print_up_trayectory_pointers(__wikimyei_t *_wikimyei);
void load_print_up_trayectory_queue(__wikimyei_t *_wikimyei);
void load_print_down_trayectory_queue(__wikimyei_t *_wikimyei);
void empty_queue_on_last(__wikimyei_t *_wikimyei);
void kill_load(__wikimyei_t *_wikimyei);
void kill_queue(__load_queue_t *_queue);
void kill_trayectory(__trayectory_t *_trayectory);
void destroy_wikimyei(__wikimyei_t *_wikimyei);
___cwcn_bool_t all_wajyu_duuruva_ready(__wikimyei_t *_wikimyei);
___cwcn_bool_t load_on_noob(__wikimyei_t *_wikimyei);
___cwcn_bool_t load_on_end(__wikimyei_t *_wikimyei);
___cwcn_bool_t load_on_start(__wikimyei_t *_wikimyei);
___cwcn_bool_t load_is_healty(__wikimyei_t *_wikimyei);
___cwcn_bool_t load_is_empty(__wikimyei_t *_wikimyei);
void printflags(__wikimyei_t *_wikimyei);
#endif