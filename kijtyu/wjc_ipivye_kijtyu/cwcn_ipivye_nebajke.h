#include "fann.h"
// depends on fann
trayectory_t * fill_trayectory(alliu_t * _alliu, duuruva_t *_duuruva, tsane_t *_tsane, uwaabo_t *_uwaabo, munaajpi_t *_munaajpi, entropy_t * _entropy);

void _ipivye_jkimyei();

typedef struct alliu{
	float __alliu_kemu[NUM_ALLIU];
} alliu_t;
alliu_t * _ipivye_alliu(float _alliu[NUM_ALLIU]);

typedef struct duuruva{
	float __duuruva_kemu[NUM_DUURUVA];
} duuruva_t;
duuruva_t * _ipivye_duuruva(float _duuruva[NUM_DUURUVA]);

typedef struct uwaabo{
	float __uwaabo_kemu[NUM_UWAABO]; // #FIXME make uwaabo struct map to entropy structs
	float __entropy_kemu[NUM_ENTROPY];
	struct beta_pdf *__beta_pdf;
	struct fann *__uwaabo_ann;
} uwaabo_t;
uwaabo_t * _ipivye_uwaabo(float _uwaabo[NUM_UWAABO]);


typedef struct dehash_entropy{
	float __entropy_kemu[NUM_ENTROPY];
} entropy_t;
entropy_t * _ipivye_entropy(float _entropy[NUM_ENTROPY]);

typedef struct munaajpi{
	float __munaajpi_kemu[NUM_UWAABO];
	float __munaajpi_returns[NUM_UWAABO];
	float __munaajpi_adventage[NUM_TSANE];
} munaajpi_t;
munaajpi_t * _ipivye_munaajpi(float _munaajpi[NUM_UWAABO]);

typedef struct tsane{
	float __tsane_kemu[NUM_TSANE];
	float __tsane_log_prob_kemu[NUM_TSANE];
} tsane_t;
tsane_t * _ipivye_tsane(float _tsane[NUM_TSANE]);

typedef struct dehash_tsane{
	int tsane;
	char config = "read config..";
} dehash_tsane_t;
