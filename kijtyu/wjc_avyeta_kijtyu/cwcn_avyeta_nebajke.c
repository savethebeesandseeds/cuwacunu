#include "fann.h"
// depends on fann
#include "cwcn_net_nebajke.h"
#include "cwcn_net_piaabo.h"
#include "wikimyei.config.h"
#include "cwcn_avyeta_nebajke.h"
/*
    HASH
*/

void _wikimyei_alliu_source(__alliu_t * _alliu){
    printf(">> _wikimyei_alliu_source\n");
    // #FIXME get alliu
    for(unsigned int idx=0;idx<NUM_ALLIU;idx++){
        _alliu->__alliu_kemu[idx] = (float)(randn() % 2 -1);
    }
}
void _wikimyei_ujcamei_hash(__alliu_t * _alliu, __duuruva_t * _duuruva){
    printf(">> _wikimyei_ujcamei_hash\n");
    for(unsigned int idx=0; idx<NUM_DUURUVA;idxs++){
        _duuruva->__duuruva_kemu[idx] = _alliu->__alliu_kemu[idx];
    }
}
void _wikimyei_uwaabo_hash(__duuruva_t * _duuruva, __uwaabo_t _uwaabo){
    printf(">> _wikimyei_uwaabo_hash\n");
    printf(">>> ujcamei:");
    for(unsigned int idx=0;idx<NUM_DUURUVA;idx++){printf("\t%f",_duuruva->__duuruva_kemu[idx]);}
    _uwaabo->__uwaabo_kemu = fann_run(_uwaabo->__uwaabo_ann, _duuruva->__duuruva_kemu);
    printf(">>> cajtucu:");
    for(unsigned int idx=0;idx<NUM_UWAABO;idx++){printf("\t%f",_uwaabo->__uwaabo_kemu[idx]);}
}



void _wikimyei_entropy_dehash(c_uwaabo, c_entropy){
    printf(">> wikimyei_entropy_dehash\n");
    // float * __eta = malloc(__sizeof(float));
    // float * __lambda = malloc(__sizeof(float));
    // int integerPart = (int)f;
    // int decimalPart = ((int)(f*1000)%1000);
    float f = 123.456;
    f = f-(float)(int)f;
    enum H {__beta_pdf, __cauchy_pdf};
    for(int idp=__beta_pdf; __beta_pdf<=__cauchy_pdf;idp++){
        switch(idp){
            case idp==__beta_pdf:
                c_entropy->__beta_pdf->__eta = c_uwaabo->__uwaabo_kemu[c_entropy->__beta_pdf->__eta_index];
                c_entropy->__beta_pdf->__lambda = c_uwaabo->__uwaabo_kemu[c_entropy->__beta_pdf->__lambda_index];
                c_entropy->__beta_pdf->__kemu = probability_density_beta();
                float differential_entropy_beta(float input);
            case idp==__cauchy_pdf:

            }

        }
        idf->__beta_eta;
        idf->__beta_lambda;
        idf->idp->__beta_kemu;
    }
    c_entropy->__beta_pdf
    __eta = c_uwaabo;
    
    assert(_eta>0);
    beta_lambda(__lambda);
    float beta_GAMMA(float input);


} // #TELLME ¿MAX or MIN?
    



void _wikimyei_cajtucu_hash(__uwaabo_t * _uwaabo, __entropy_t *_entropy, tsane_t * _tsane){
    printf(">> _wikimyei_cajtucu_hash\n");
    for(unsigned int idx=0; idx<NUM_ENTROPY;idxs++){
        _entropy->__entropy_kemu[idx] = _uwaabo->__uwaabo_kemu[idx];
    }
}
void _wikimyei_munaajpi_hash(__duuruva_t * _duuruva, __uwaabo_t * _uwaabo, munaajpi_t * _munaajpi){
    printf(">> _wikimyei_munaajpi_hash\n");
    float *_aux = _ARRAY_CONCAT(float, (float) _duuruva->__duuruva_kemu, NUM_DUURUVA, (float) _uwaabo->__uwaabo_kemu, NUM_UWAABO);
    printf(">>> ujcamei:");
    for(unsigned int idx=0;idx<NUM_DUURUVA+NUM_UWAABO;idx++){printf("\t%f",_aux[idx]);}
    _munaajpi->__munaajpi_kemu = fann_run(_munaajpi->__munaajpi_ann, _aux);
    printf(">>> cajtucu:");
    for(unsigned int idx=0;idx<NUM_MUNAAJPI;idx++){printf("\t%f",_munaajpi->__munaajpi_kemu [idx]);}
}
void _wikimyei_tsane_dehash(__alliu_t * _alliu, __uwaabo_t * _uwaabo, __entropy_t * _entropy, munaajpi_t * _munaajpi){
    printf(">> _wikimyei_tsane_dehash\n");
    for(unsigned int idx=0; idx<NUM_TSANE;idxs++){
        _tsane->__tsane_kemu[idx] = _entropy->__entropy_kemu[idx];
    }
}
