#ifndef UWAABO_PIAABO_INCLUDED
#define UWAABO_PIAABO_INCLUDED
#include "cwcn_tsinuu_piaabo.h"
#include "cwcn_tsinuu_nebajke.h"
typedef struct __uwaabo {
    __tsinuu_t *__uwaabo_tsinuu;
    __duuruva_t *__uwaabo_duuruva;
    __duuruva_t *__uwaabo_loss_duuruva;
}__uwaabo_t;
__uwaabo_t *uwaabo_fabric(unsigned int _uwaabo_base_size, unsigned int _uwaabo_size);
#endif