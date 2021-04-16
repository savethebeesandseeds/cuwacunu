#include "fann"
// remmemer PMF[a_idx], from I, from the past ¿do we make it?.
#ifndef FUNCTIONS_WIKIMYEI_NEBAJKE
#define FUNCTIONS_WIKIMYEI_NEBAJKE
void _wikimyei_alliu_source(alliu_t * _alliu);
void _wikimyei_ujcamei_hash(alliu_t * _alliu, duuruva_t * _duuruva);
void _wikimyei_uwaabo_hash(duuruva_t * _duuruva, uwaabo_t _uwaabo)
void _wikimyei_munaajpi_hash(duuruva_t * _duuruva, uwaabo_t * _uwaabo, munaajpi_t * _munaajpi);
void _wikimyei_cajtucu_hash(uwaabo_t * _uwaabo, entropy_t *_entropy, tsane_t * _tsane)
void _wikimyei_tsane_dehash(alliu_t * _alliu, uwaabo_t * _uwaabo, entropy_t * _entropy, munaajpi_t * _munaajpi);
#endif