
#import <stdio.h>
#import <stdlib.h>
#import "fann.h"
#import "wikimyei.config.h"
// depends on fann

__trayectory_t *fill_trayectory(__alliu_t *_alliu, __duuruva_t *_duuruva, __tsane_t *_tsane, __uwaabo_t *_uwaabo, __munaajpi_t *_munaajpi, __entropy_t *_entropy){
    printf(">> fill_trayectory\n");
    __trayectory_t *new_trayectory = malloc(__sizeof(__trayectory_t));
    new_trayectory->__duuruva_kemu=_duuruva->__duuruva_kemu;
    new_trayectory->__tsane_kemu=_tsane->__tsane_kemu;
    new_trayectory->__tsane_log_prob=_uwaabo->__uwaabo_kemu;
    new_trayectory->__munaajpi_returns=_munaajpi->__munaajpi_returns;
    new_trayectory->__munaajpi_adventage=_munaajpi->__munaajpi_adventage;
    return new_trayectory;
}

void _ipivye_cajtucu(){}
void _ipivye_jkimyei(){}


__alliu_t *_ipivye_alliu(){
    printf(">> _ipivye_alliu\n");
	__alliu_t *new_t = malloc(__sizeof(__alliu_t));
	return new_t;
}

__duuruva_t *_ipivye_duuruva(){
    printf(">> _ipivye_duuruva\n");
	__duuruva_t *new_t = malloc(__sizeof(__duuruva_t));
	return new_t;
}

__uwaabo_t *_ipivye_uwaabo(){
    printf(">> _ipivye_uwaabo\n");
	__uwaabo_t *new_t = malloc(__sizeof(__uwaabo_t));
	struct fann *_uwaabo_ann = fann_create_standard(
        NUM_UWAABO_LAYERS,
		NUM_DUURUVA,
        NUM_UWAABO_HIDDEN,
        NUM_UWAABO);
    fann_set_activation_function_hidden(_uwaabo_ann, FANN_SIGMOID_SYMMETRIC);
	fann_set_activation_function_output(_uwaabo_ann, FANN_SIGMOID);
	new_t->__uwaabo_ann = _uwaabo_ann;
	return new_t;
}

__munaajpi_t *_ipivye_munaajpi(){
     printf(">> _ipivye_ipivye\n");
	__munaajpi_t *new_t = malloc(__sizeof(__munaajpi_t));
	struct fann *_munaajpi_ann = fann_create_standard(
        NUM_MUNAAJPI_LAYERS,
		NUM_DUURUVA,
        NUM_MUNAAJPI_HIDDEN,
        NUM_MUNAAJPI);
    fann_set_activation_function_hidden(_ipivye_ann, FANN_SIGMOID_SYMMETRIC);
	fann_set_activation_function_output(_ipivye_ann, FANN_SIGMOID);
	new_t->__munaajpi_ann = _munaajpi_ann;
	return new_t;
}

__entropy_t *_ipivye_entropy(){
    printf(">> _ipivye_entropy\n");
	__entropy_t *new_t = malloc(__sizeof(__entropy_t));
	struct beta_pdf *new_beta_pdf = malloc(__sizeof(struct beta_pdf);
	new_t->__beta_pdf = new_beta_pdf;
	return new_t;
}

__tsane_t *_ipivye_tsane(){
    printf(">> _ipivye_tsane\n");
	__tsane_t *new_t = malloc(__sizeof(__tsane_t));
	new_t->__tsane_kemu = _tsane;
	for(unsigned int idx=0;idx<NUM_TSANE;idx++){
		new_t->__tsane_log_prob_kemu[idx] = log(_tsane[idx]);
	}
	return new_t;
}

__dehash_tsane_t *_ipivye_dtsane(){
	//READCONFIG//CONSTRUCSCPECIFICTORDER//
	__dehash_tsane_t *new_t = malloc(__sizeof(__dehash_tsane_t));
	return new_t;
}



