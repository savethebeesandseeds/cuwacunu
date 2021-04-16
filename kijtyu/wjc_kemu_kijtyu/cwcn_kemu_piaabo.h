#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "wikimyei.config.h"
#define clrscr() printf("\e[1;1H\e[2J")
#ifndef KEMU_INCLUDED
#define KEMU_INCLUDED
_Bool CWCN_TRUE = 0b1;
_Bool CWCN_FALSE = 0b0;
// typedef enum{CWCN_TRUE, CWCN_FALSE} bool;
#define max(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a > _b ? _a : _b;})
#define min(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a < _b ? _a : _b;})
#define array_size(a)({__typeof__(a) *_a=(a);__sizeof__(_a)/(__sizeof__(_a[0]));})
#define _ASSERT_EXPR(test, message) assert(((void)(message), test))
#define _ARRAY_CONCAT(_TYPE, A, An, B, Bn) (_TYPE *)array_concat((const void *)(A), (An), (const void *)(B), (Bn), sizeof(_TYPE));
void * array_concat(const void *a, size_t an,const void *b, size_t bn, size_t s);
// int *total = _ARRAY_CONCAT(int, (int) a, NUM_a, (int) b, NUM_b);
typedef struct trayectory {
    float __duuruva_kemu[NUM_DUURUVA];
    float __tsane_kemu[NUM_TSANE];
    float __tsane_log_prob[NUM_TSANE];
    float __munaajpi_returns[NUM_UWAABO];
} trayectory_t;
typedef struct tryectory_queue {
    trayectory_t *__trayectory;
    struct tryectory_queue *next;
} queue_t;
void delay(double dly);
float clamp(float d, float min, float max);
trayectory_t * dequeue_trayectory(queue_t **head_t);
void enqueue_trayectory(queue_t **head_t, trayectory_t *new_trayectory);
void print_trayectory_queue(queue_t *head_t);
#endif