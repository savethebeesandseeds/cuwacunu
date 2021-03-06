#ifndef WIKIMYEI_NEBAJKE_INCLUDED
#define WIKIMYEI_NEBAJKE_INCLUDED

#define NAT_TYPE
#define FRQ_JKIMYEI	(unsigned int) 10
#define LEARNING_RATE   (__cwcn_type_t) 1e-4 // #FXIME wapaajco_potency
#define TIME_GAMMA  (__cwcn_type_t) 0.99
#define GAE_LAMBDA  (__cwcn_type_t) 0.95
#define JKMYEI_EPSILON (__cwcn_type_t) 0.2
#define UWAABO_BETA  (__cwcn_type_t) 1.0
#define MUNAAJPI_BETA (__cwcn_type_t) 0.5
#define ENTROPY_BETA(__cwcn_type_t) 0.001

#define NUM_RETURNS (unsigned int) 1//
#define NUM_DUURUVA  (unsigned int) 1//
#define NUM_TSANE (unsigned int) 1//

#define JKMYEI_STEPS (unsigned int) 256
#define LOAD_SIZE  (unsigned int) 128//
#define JK_SIZE (unsigned int) 32//
#define TARGET_REWARD (unsigned int) 2500 // #FIXME [what!]

#include "cwcn_wikimyei_piaabo.h"
#include "cwcn_duuruva_nebajke.h"
#include "cwcn_wajyu_piaabo.h"
void ___alliu_hash(__wikimyei_t *_wikimyei);
void ___alliu_duuruva_hash(__wikimyei_t *_wikimyei);
void ___uwaabo_hash(__wikimyei_t *_wikimyei);
void ___entropy_hash(__wikimyei_t *_wikimyei);
void ___tsane_dehash(__wikimyei_t *_wikimyei);
void ___jkimyei_uwaabo_munaajpi_hash(__wikimyei_t *_wikimyei);
void ___jkimyei_uwaabo_munaajpi_duuruva_hash(__wikimyei_t *_wikimyei);
void ___imibajcho_munaajpi_hash(__wikimyei_t *_wikimyei);
void ___uwaabo_exploration_hash(__wikimyei_t *_wikimyei);

void wikimyei_live_one(__wikimyei_t *_wikimyei);
void wikimyei_live_load(__wikimyei_t *_wikimyei, int _size_of_load);
void wikimyei_relive_alliu_one(__wikimyei_t *_wikimyei); // does not request next alliu
void wikimyei_relive_alliu_load(__wikimyei_t *_wikimyei); // does not request alliu
void wikimyei_live_uwaabo_exploration_one(__wikimyei_t *_wikimyei);
void wikimyei_live_uwaabo_exploration_load(__wikimyei_t *_wikimyei, int _size_of_load);
#endif