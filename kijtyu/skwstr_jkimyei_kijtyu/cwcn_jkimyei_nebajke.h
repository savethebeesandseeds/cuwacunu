#ifndef JKIMYEI_PIAABO_INCLUDED
#define JKIMYEI_PIAABO_INCLUDED
#include "cwcn_tsinuu_piaabo.h"
#include "cwcn_wikimyei_piaabo.h"

typedef float (__cwcn_type_t);
typedef _Bool (___cwcn_bool_t);
// typedef __wikimyei_t;
#define ___CWCN_TRUE (___cwcn_bool_t) 0b1
#define ___CWCN_FALSE (___cwcn_bool_t) 0b0
#define max(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a > _b ? _a : _b;})
#define min(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a < _b ? _a : _b;})
/*

*/
__jkimyei_t *jkimyei_fabric(int _jk_size);
void jkimyei_destroy(__jkimyei_t *_jkimyei);
/*

*/
// void release_jk(__wikimyei_t *_wikimyei);
// void fill_jk_rand(__wikimyei_t *_wikimyei);
/*

*/
int jk_rand_index(__wikimyei_t *_wikimyei);
void wikimyei_jkimyei(__wikimyei_t *_wikimyei);
/*

*/
// __trayectory_t *jk_dequeue_trayectory(__jkimyei_t *_jkimyei);
// void jk_enqueue_trayectory(__jkimyei_t *_jkimyei, __trayectory_t *_new_trayectory);
// void jk_enqueue_trayectory_index(__wikimyei_t *_wikimyei, int _index, ___cwcn_bool_t _rneturn);
// void jk_print_trayectory_queue(__jkimyei_t *_jkimyei);
// __trayectory_t *jk_get_trayectory_item(__jkimyei_t *_jkimyei);
...
__cwcn_type_t jk_clamp(__cwcn_type_t d, __cwcn_type_t min, __cwcn_type_t max);
#endif
