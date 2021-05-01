#include "cwcn_tsinuu_nebajke.h"
#include "cwcn_tsinuu_piaabo.h"
// depends on fann
__trayectory_t * fill_trayectory(__alliu_t * _alliu, __duuruva_t *_duuruva, __tsane_t *_tsane, __uwaabo_t *_uwaabo, __munaajpi_t *_munaajpi, __entropy_t * _entropy);

void _ipivye_jkimyei();

typedef struct __alliu{
	float __alliu_kemu[NUM_ALLIU];
} __alliu_t;
__alliu_t * _ipivye_alliu(float _alliu[NUM_ALLIU]);

typedef struct __duuruva{
	float __duuruva_kemu[NUM_DUURUVA];
} __duuruva_t;
__duuruva_t * _ipivye_duuruva(float _duuruva[NUM_DUURUVA]);

typedef struct __uwaabo{
	float __uwaabo_kemu[NUM_UWAABO]; // #FIXME make uwaabo struct map to entropy structs
	float __entropy_kemu[NUM_ENTROPY];
	__beta_pdf_t *__beta_pdf;
	__tsinuu_t *__uwaabo_tsinuu;
} __uwaabo_t;
__uwaabo_t * _ipivye_uwaabo(float _uwaabo[NUM_UWAABO]);


typedef struct __dehash_entropy{
	float __entropy_kemu[NUM_ENTROPY];
} __dehash_entropy_t;
__dehash_entropy_t * _ipivye_entropy(float _entropy[NUM_ENTROPY]);

typedef struct __munaajpi{
	float __munaajpi_kemu[NUM_UWAABO];
	float __munaajpi_returns[NUM_UWAABO];
	float __munaajpi_adventage[NUM_TSANE];
} __munaajpi_t;
__munaajpi_t * _ipivye_munaajpi(float _munaajpi[NUM_UWAABO]);

typedef struct __tsane{
	float __tsane_kemu[NUM_TSANE];
	float __tsane_log_prob_kemu[NUM_TSANE];
} __tsane_t;
__tsane_t * _ipivye_tsane(float _tsane[NUM_TSANE]);

typedef struct __dehash_tsane{
	int tsane;
	char config = "read config..";
} __dehash_tsane_t;
