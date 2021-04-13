#include <stdio.h>
#include <stdbool.h>
#include "fann.h"
#include "cwcn_net_piaabo.h"
#include "cwcn_net_alliu_nebajke.h"
// #include fann.h or floatfann.h
// #include doublefann.h
// #include fixedfann.h 

// remmemer PMF[a_idx], from I, from the past ¿do we make it?.

/*
create a custom fann_train, 
so that:
ann->MSE_value
*/
#ifndef FUNCTIONS_NET_JKIMYEI
#define FUNCTIONS_NET_JKIMYEI
void cwcn_rl_fann_train_on_item();
void fnn_train_on_alliu(struct fann *ann);
#endif