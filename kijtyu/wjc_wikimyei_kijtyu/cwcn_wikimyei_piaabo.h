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
/* GENERAL CONFIGURATIONS */ // #FIXME unify the configuration file
// #define DEBUG_LINEAR_EXPERIMENT // for constant input and unit transitions in all tsinuu
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
#define COLOR_WAJYU "\x1B[0;37m"
#define COLOR_JKIMYEI "\x1B[0;32m"
#define COLOR_HEALT "\033[0;31m"
/*
    DEGGUG OPTIONS
*/
// #define UWAABO_DEBUG
// #define TSINUU_DEBUG
// #define TSINUU_DEBUG_v2
// #define WIKIMYEI_DEBUG
// #define WIKIMYEI_DEBUG_v2
// #define ENTROPY_DEBUG
// #define ENTROPY_DEBUG_v1
// #define ENTROPY_DEBUG_v2
// #define ALOCATION_DEBUG
// #define WIKIMYEI_DEBUG_LOAD
// #define WIKIMYEI_DEBUG_HEALT
// #define DUURUVA_DEBUG
#define JKIMYEI_DEBUG
// #define JKIMYEI_DEBUG_v2
// #define MUNAAJPI_DEBUG

#define __ALLOW_DUURUVA_DUMPFILE__

#define __WAJYU_DUMPFOLDER__ "wajyu_data/"
#define __DUMPFILE_WAJYU_SIMPLE_VALUE_DUURUVA__ __WAJYU_DUMPFOLDER__ "wajyu.wajyu_simple_value.dumpfile"
#define __DUMPFILE_ALLIU_DUURUVA__ __WAJYU_DUMPFOLDER__ "wajyu.alliu.dumpfile"
#define __DUMPFILE_UWAABO_DUURUVA__ __WAJYU_DUMPFOLDER__ "wajyu.uwaabo.dumpfile"
#define __DUMPFILE_TSANE_DUURUVA__ __WAJYU_DUMPFOLDER__ "wajyu.tsane.dumpfile"
#define __DUMPFILE_ENTROPY_DUURUVA__ __WAJYU_DUMPFOLDER__ "wajyu.entropy.dumpfile"
#define __DUMPFILE_IMIBAJCHO_MUNAAJPI_DUURUVA__ __WAJYU_DUMPFOLDER__ "wajyu.imibajcho_munaajpi.dumpfile"
#define __DUMPFILE_JKIMYEI_UWAABO_MUNAAJPI_DUURUVA__ __WAJYU_DUMPFOLDER__ "wajyu.jkimyei_uwaabo_munaajpi.dumpfile"
#define __DUMPFILE_UWAABO_GAE_RETURNS_DUURUVA__ __WAJYU_DUMPFOLDER__ "wajyu.uwaabo_gae_returns.dumpfile"
#define __DUMPFILE_UWAABO_GAE_ADVENTAGE_DUURUVA__ __WAJYU_DUMPFOLDER__ "wajyu.uwaabo_gae_adventage.dumpfile"
#define __DUMPFILE_UWAABO_LOSS_DUURUVA__ __WAJYU_DUMPFOLDER__ "wajyu.uwaabo_loss.dumpfile"
#define __DUMPFILE_JKIMYEI_UWAABO_MUNAAJPI_LOSS_DUURUVA__ __WAJYU_DUMPFOLDER__ "wajyu.jkimyei_uwaabo_munaajpi_loss.dumpfile"
#define __DUMPFILE_RATIO_HANDLER_DUURUVA__ __WAJYU_DUMPFOLDER__ "wajyu.ratio_handler.dumpfile"
#define __DUMPFILE_SURR1_HANDLER_DUURUVA__ __WAJYU_DUMPFOLDER__ "wajyu.surr1_handler.dumpfile"
#define __DUMPFILE_SURR2_HANDLER_DUURUVA__ __WAJYU_DUMPFOLDER__ "wajyu.surr2_handler.dumpfile"

#define UWAABO_EXPLORATION_RANDOM
#define _JK_BREAK_COUNTER_ (unsigned int) 0x999

#define __JK_SIZE__ (unsigned int) 0x01
#define __EPOCHS__ (unsigned int) 0x01
#define __SIZE_OF_LOAD__ (int) 10

#define __GAE_GAMMA__ (__cwcn_type_t) 0.99
#define __GAE_LAMBDA__ (__cwcn_type_t) 0.095
#define __CLIP_PARAM__ (__cwcn_type_t) 0.2
#define __UWAABO_BETA__ (__cwcn_type_t) 0.1
#define __MUNAAJPI_BETA__ (__cwcn_type_t) 0.1
#define __ENTROPY_BETA__ (__cwcn_type_t) 0.01 // #FIXME findme

#define __UWAABO_WAAPAJCO_POTENCY__ (__cwcn_type_t) 1.0
#define __MUNAAJPI_WAAPAJCO_POTENCY__ (__cwcn_type_t) 1.0
#define __IMIBAJCHO_MUNAAJPI_POTENCY__ (__cwcn_type_t) 1.0

#define __MAX_TSINUU_HIPERPARAMETER__ (__cwcn_type_t) 10.0

#define __TAKE_TSANE__ (___cwcn_bool_t) ___CWCN_FALSE
#define __TSANE_SIZE__ (unsigned int) 0x02 // not configurable! do not change
#define __ALLIU_SOURCE_SIZE__ (unsigned int) 0x01 // vector dimension size

#define __NUM_BASE_DUURUVA__ (unsigned int) 0x11 // not configurable! == 0x11
#define __HORIZON_MUNAAJPI__ (unsigned int) 0x02
#define __DIRECT_RESOLUTION__ (unsigned int) 0x20

#ifndef DEBUG_LINEAR_EXPERIMENT
// #define __ALLIU_SOURCE__ (__alliu_source_t) negINDEX_as_alliu;
#define __ALLIU_SOURCE__ (__alliu_source_t) INDEX_as_alliu;
// #define __ALLIU_SOURCE__ (__alliu_source_t) SINE_as_alliu;
// #define __ALLIU_SOURCE__ (__alliu_source_t) UNIT_as_alliu;
#else
#define __ALLIU_SOURCE__ (__alliu_source_t) UNIT_as_alliu;
#endif

#define _ENTROPY_GAMMA_RESOLUTION_ (unsigned int) 1024

// #define _DUURUVA_NORM_STAND_JKIMYEI_UWAABO_
// #define _DUURUVA_NORM_STAND_JKIMYEI_UWAABO_DUURUVA_
// #define _DUURUVA_NORM_STAND_ALLIU_ // do not define
// #define _DUURUVA_NORM_STAND_ALLIU_DUURUVA_
// #define __NORM_STAND_DUURUVA_ADVENTAGE__ // #FIXME acivate 
/* set the expenses * expend is to compute, "to expend the computing effort"  */

#define __EXPEND_WAJYU_SIMPLE_VALUE_DUURUVA__
#define __EXPEND_ALLIU_DUURUVA__
#define __EXPEND_UWAABO_DUURUVA__
#define __EXPEND_TSANE_DUURUVA__
#define __EXPEND_ENTROPY_DUURUVA__
#define __EXPEND_JKIMYEI_UWAABO_MUNAAJPI_DUURUVA__
#define __EXPEND_IMIBAJCHO_MUNAAJPI_DUURUVA__
#define __EXPEND_UWAABO_GAE_RETURNS_DUURUVA__ // #FIXME is it beeing used?
#define __EXPEND_UWAABO_GAE_ADVENTAGE_DUURUVA__
#define __EXPEND_UWAABO_LOSS_DUURUVA__
#define __EXPEND_JKIMYEI_UWAABO_MUNAAJPI_LOSS_DUURUVA__
#define __EXPEND_RATIO_HANDLER_DUURUVA__
#define __EXPEND_SURR1_HANDLER_DUURUVA__
#define __EXPEND_SURR2_HANDLER_DUURUVA__
/* set the propg * propagate is to propagate (needed expend to propagate) to propagate includes duuruva vector in trayectoy */
#if defined(__EXPEND_ALLIU_DUURUVA__)
#define __PROPAGATE_ALLIU_DUURUVA__
#endif
#if defined(__EXPEND_IMIBAJCHO_MUNAAJPI_DUURUVA__)
#define __PROPAGATE_JKIMYEI_UWAABO_MUNAAJPI_DUURUVA__
#endif
/* UAWABO_W_BASE
BUILD ON : fixme
        [0x0] : __IN_UWAABO_W_BASE_ALLIU_IS_INCLUDED__
        [0x1] : __IN_UWAABO_W_BASE_ALLIU_DUURUVA_IS_INCLUDED__
*/
#if defined(__EXPEND_ALLIU_DUURUVA__) && defined(__PROPAGATE_ALLIU_DUURUVA__)
#define __IN_UWAABO_W_BASE_ALLIU_DUURUVA_IS_INCLUDED__
#endif
#define __IN_UWAABO_W_BASE_ALLIU_IS_INCLUDED__
/* MUNAAJPI_W_BASE
BUILD ON : fixme
    BASE_W_MUNAAJPI:
        [0x0] : __IN_MUNAAJPI_W_BASE_ALLIU_IS_INCLUDED__
        [0x1] : __IN_MUNAAJPI_W_BASE_ALLIU_DUURUVA_IS_INCLUDED__
        [0x2] : __IN_MUNAAJPI_W_BASE_nonuwaaboALLIU_IS_INCLUDED__
        [0x3] : __IN_MUNAAJPI_W_BASE_UAWAABO_IS_INCLUDED__
        [0x5] : __IN_MUNAAJPI_W_BASE_TASNE_IS_INCLUDED__
        [0x6] : __IN_MUNAAJPI_W_BASE_ENTROPY_IS_INCLUDED__
        [0x7] : __IN_MUNAAJPI_W_BASE_IMIBAJCHO_MUNAAJPI_IS_INCLUDED__
*/
#if defined(__EXPEND_ALLIU_DUURUVA__) && defined(__PROPAGATE_ALLIU_DUURUVA__)
// #define __IN_MUNAAJPI_W_BASE_ALLIU_DUURUVA_IS_INCLUDED__
#endif
#define __IN_MUNAAJPI_W_BASE_ALLIU_IS_INCLUDED__
// #define __IN_MUNAAJPI_W_BASE_nonuwaaboALLIU_IS_INCLUDED__
#define __IN_MUNAAJPI_W_BASE_UAWAABO_IS_INCLUDED__
#define __IN_MUNAAJPI_W_BASE_TASNE_IS_INCLUDED__
// #define __IN_MUNAAJPI_W_BASE_ENTROPY_IS_INCLUDED__
#define __IN_MUNAAJPI_W_BASE_IMIBAJCHO_MUNAAJPI_IS_INCLUDED__
/* set the masks for the trayectory */
/*
    DUURUVA: (pay attention : this instruct how to set mask)
        [0x0] : value               ###   MUNAAJPI --- [TEST] ... [DISABLED] experiments found in neg/index_as_alliu  ### [TEST] 
        [0x1] : __diff_1
        [0x2] : __diff_2
        [0x3] : __max
        [0x4] : __min
        [0x5] : __std               ###   MUNAAJPI --- [TEST] ... [DISABLED] experiment found in neg/index_as_aslliu 
        [0x6] : __mean              ###   MUNAAJPI --- [TEST] ... [DISABLED] experiment found in neg/index_as_aslliu 
        [0x7] : __M2
        [0x8] : __M3
        [0x9] : __M4
        [0xA] : __kurtosis
        [0xB] : __skewness
*/
#if defined(__EXPEND_ALLIU_DUURUVA__) && defined(__PROPAGATE_ALLIU_DUURUVA__)
#define _ALLIU_DUURUVA_MASK_ (__cwcn_type_t[BUGGER_SIZE_DUURUVA]){\
        0x1, \
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
        0x0}
#endif
#if defined(__EXPEND_JKIMYEI_UWAABO_MUNAAJPI_DUURUVA__) && defined(__PROPAGATE_JKIMYEI_UWAABO_MUNAAJPI_DUURUVA__)
#define _JKIMYEI_UWAABO_MUNAAJPI_DUURUVA_MASK_ (__cwcn_type_t[BUGGER_SIZE_DUURUVA]){\
        0x0, \
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
        0x0}
#endif
/* WIKIMYEI DEFINITIONS */
typedef struct __wk_flags {
    ___cwcn_bool_t __done;
    ___cwcn_bool_t __nonuwaabo_alliu_done;
    ___cwcn_bool_t __endhead_empty_alliu;
    ___cwcn_bool_t __wajyu_duuruva_ready;
    ___cwcn_bool_t __norm_stand; // about norm & standarizing alliu and imibajcho munaajpi propagation results, valid if __EXPEND_* is defined
} __wk_flags_t;
typedef struct __trayectory { // #FIXME too many fields
    #if defined(__EXPEND_ALLIU_DUURUVA__) && defined(__PROPAGATE_ALLIU_DUURUVA__)
    __cwcn_type_t *__alliu_state;
    __cwcn_type_t *__nonuwaabo_alliu_state;
    __cwcn_type_t *__alliu_duuruva_state;
    #else
    __cwcn_type_t *__alliu_state;
    __cwcn_type_t *__nonuwaabo_alliu_state;
    #endif
    __cwcn_type_t __uwaabo_mask;
    __cwcn_type_t *__uwaabo_state;
    __cwcn_type_t *__uwaabo_gae_returns;
    __cwcn_type_t *__uwaabo_gae_adventage; // generalized adv'a'ntage estimation
    __cwcn_type_t *__tsane_state;
    __cwcn_type_t *__entropy_state;
    #if defined(__EXPEND_JKIMYEI_UWAABO_MUNAAJPI_DUURUVA__) && defined(__PROPAGATE_JKIMYEI_UWAABO_MUNAAJPI_DUURUVA__)
    unsigned int __pending_munaajpi_index;
    ___cwcn_bool_t __pending_munaajpi;
    __cwcn_type_t *__imibajcho_munaajpi_state;// this is J, varies while pending_munaajpi_index
    __cwcn_type_t *__jkimyei_uwaabo_munaajpi_state; //... these are the uwaabo waapajco parameteres, munaajpi wapaajco is imibajcho_munaajpi
    __cwcn_type_t *__jkimyei_uwaabo_munaajpi_duuruva_state;// this is J, varies while pending_munaajpi_index
    #else
    unsigned int __pending_munaajpi_index;
    ___cwcn_bool_t __pending_munaajpi;
    __cwcn_type_t *__imibajcho_munaajpi_state;// this is J, varies while pending_munaajpi_index
    __cwcn_type_t *__jkimyei_uwaabo_munaajpi_state; //... these are the uwaabo waapajco parameteres, munaajpi wapaajco is imibajcho_munaajpi
    #endif
}__trayectory_t;
// typedef struct __jk_queue { // jk is but a regular queue
//     __trayectory_t *__trayectory_item;
//     struct __jk_queue *__next;
// } __jk_queue_t;
typedef void (*__void_function_pointer_t)(void*);
#include "cwcn_cajtucu_piaabo.h"
#include "cwcn_ujcamei_piaabo.h"
#include "cwcn_entropy_nebajke.h"
#include "cwcn_duuruva_nebajke.h"
#include "cwcn_tsinuu_piaabo.h"
#include "cwcn_tsinuu_nebajke.h"
#include "cwcn_wajyu_piaabo.h"
#include "cwcn_kemu_piaabo.h"
typedef struct __jkimyei {
    // __jk_queue_t *__jk_batch_head;
    // int __jk_index;
    int __jk_size;
    __void_function_pointer_t __jk_one;
} __jkimyei_t;
typedef struct __uwaabo {
    unsigned int __uwaabo_base_w_size;
    unsigned int __uwaabo_state_size;
    __cwcn_type_t *__uwaabo_w_base;
    __tsinuu_t *__uwaabo_tsinuu;
}__uwaabo_t;
typedef struct __munaajpi {
    unsigned int __munaajpi_base_w_size;
    unsigned int __jkimyei_uwaabo_munaajpi_state_size;
    __cwcn_type_t *__munaajpi_w_base;
    __tsinuu_t *__munaajpi_tsinuu;
}__munaajpi_t;
typedef struct __load_queue { // load is a chain of pointers
    __trayectory_t *__trayectory_item;
    struct __load_queue **__down;
    struct __load_queue **__up;
} __load_queue_t;
typedef struct __wikimyei {
    int __load_index;
    int __load_size;
    __load_queue_t *__load_head;
    // __load_queue_t **__load_down; // these two are redundant (on NON_C.__load_queue_t*[(_down)__load_head]) but usefull
    // __load_queue_t **__load_up; // these two are redundant (on NON_C.__load_queue_t*[(_up)__load_head]) but usefull
    unsigned int __jk_size;
    unsigned int __horizon_munaajpi;
    unsigned int __direct_resolution;
    __cwcn_type_t __gae_gamma;
    __cwcn_type_t __gae_lambda;
    __cwcn_type_t __clip_param;
    __cwcn_type_t __uwaabo_beta;
    __cwcn_type_t __munaajpi_beta;
    __cwcn_type_t __entropy_beta;
    __wk_flags_t *__flags;
    __wajyu_t *__wajyu;
    __jkimyei_t *__jkimyei;
    __entropycosa_t *__ec;
    __alliu_t *__alliu;
    __tsane_t *__tsane;
    __uwaabo_t *__uwaabo;
    __munaajpi_t *__munaajpi;
}__wikimyei_t;
#include "cwcn_uwaabo_piaabo.h"
#include "cwcn_munaajpi_piaabo.h"
#include "cwcn_jkimyei_nebajke.h"
#include "cwcn_wikimyei_nebajke.h"
__wikimyei_t *wikimyei_fabric(
        __alliu_source_t _alliu_source,
        unsigned int _alliu_source_size,
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
void print_wikimyei_flags(__wikimyei_t *_wikimyei);
#endif