#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
// #include <ncurses.h>
#define _BUGGER_KALAMAR_LEVELS_N_ (int) 0x4
#define _KALAMAR_BUFFER_LEN_ (int) 0xA
#define _GUI_CARRIER_ERRASE_ "\33[2K"
#define _GUI_CARRIER_ERRASE_UP_ "\033[A\33[2K"
#define _GUI_CARRIER_ERRASE_DOWN_ "\n\33[2K"
#define _GUI_CARRIER_DELETE_ "\b"
#define _GUI_CARRIER_DELETE_UP_ "\033[A\b"
#define _GUI_CARRIER_DELETE_DOWN_ "\n\b"
#define _GUI_CARRIER_UP_ "\033[A"
#define _GUI_CARRIER_DOWN_ "\n"
#define _GUI_CARRIER_START_ "\r"
#define _GUI_CLEAR_SCREEN_ "\e[1;1H\e[2J"
#define _DALTA_H_ (int) 0x10
#define _DALTA_V_ (int) 0x02
typedef void (*__function_void_pointer_t)(void);
typedef enum{
    __KL_KALAMAR,
    __KL_WIKIMYEI,
    __KL_JKIMYEI,
    __KL_LOAD,
    __KL_ALLIU, // #FIXME include nonalliu
    __KL_UWAABO,
    __KL_ENTROPY,
    __KL_TSANE,
    __KL_MUNAAJPI,
    __KL_DUURUVA
}__kalamar_itm_t;
typedef enum{
    __KL_ALLIU_STATE,
    __KL_UWAABO_STATE,
    __KL_TSANE_STATE,
    __KL_MUNAAJPI_STATE,
    __KL_IVIVAJCHO_MUNAAJPI,
    // __KL_UWAABO_DUURUVA_STATE,
}__kalamar_state_t;
typedef enum{
    __KL_ALLIU_DUURUVA_STATE,
    __KL_MUNAAJPI_DUURUVA_STATE,
    __KL_ADVENTAGE_DUURUVA_STATE
}__kalamar_duuruva_t;
typedef enum{
    __KL_UP,
    __KL_DOWN,
    __KL_LEFT,
    __KL_RIGHT,
    __KL_LOAD_UP,
    __KL_LOAD_DOWN,
    __KL_PREV,
    __KL_NEXT,
    __KL_EXIT
}__kalamar_tsane_t;
typedef enum{
    __KL_0,
    __KL_1,
    __KL_2,
    __KL_3 // _BUGGER_KALAMAR_LEVELS_N_
}__kalamar_level_t;
typedef struct __kalamar{
    int __nrow;
    int __ncol;
    FILE *__kl_stdin;
    FILE *__kl_stdout;
    WINDOW *__kl_stdscr;
    void *__wikimyei;//#FIXME
    int *__kl_item;
    int *__kl_item_max;
}__kalamar_t;
__kalamar_t *kalamar_fabric(void *_wikimyei);
void kill_kalamar(__kalamar_t *_kalamar);
void klmp_clear_stdout(__kalamar_t *_kalamar);
void klmp_kalamar_level_0(__kalamar_t *_kalamar);
void klmp_clear_stdin(__kalamar_t *_kalamar);
void klmp_help(__kalamar_t *_kalamar);
void klmp_problem(__kalamar_t *_kalamar, char *_problem);
void kalamar_gui(__kalamar_t *_kalamar);
void print_kamar_seven(__kalamar_t *_kalamar);
void update_screen_dims(__kalamar_t *_kalamar);
void goto_klm_duuruva(__kalamar_t *_kalamar,__kalamar_duuruva_t _klmduuruva);
void klmp_duuruva(__kalamar_t *_kalamar,__kalamar_duuruva_t _klmduuruva);
void get_itm_key(__kalamar_t *_kalamar);