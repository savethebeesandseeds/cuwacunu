#include "wikimyei.config.h"
#ifndef ALLIU_PIABOO_INCLUDED
#define ALLIU_PIABOO_INCLUDED
typedef enum{
    SINE,
    MARKET
} __alliu_source_t; // not in use #FIXME
typedef __alliu{
    __alliu_source_t __source_type;
    __cwcn_type_t *__source_value;
    unsigned int __source_size;
    unsigned int __source_count;
}__alliu_t;
__alliu_t *alliu_fabric(__alliu_source_t _source, unsigned int _source_size);
void getnext_alliu(__alliu_t *_alliu);
#endif