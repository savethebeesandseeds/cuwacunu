#include "cwcn_duuruva_nebajke.h"
#define LOAD_SIZE 1000
#define ALLIU_SIZE 1
/*
it seems (for experiement in loadsize 100):
                            for cosine wave:        for sine wave:      for exponential:        no seed pseudo random/seed pseudo random


    (value_as_0x00)                 cos             sin             noseedrandom           seedrandom
DUURUVA [ 0x00 ]   __value:         0.998027       -0.062792            0.390000            0.~~0000
DUURUVA [ 0x00 ]   __count:         100.000000      100.000000          100.000000          100.000000
DUURUVA [ 0x00 ]   __max:           1.000000        1.000000            0.990000            0.9~0000
DUURUVA [ 0x00 ]   __min:          -1.000000       -1.000000            0.000000            0.000000
DUURUVA [ 0x00 ]   __std:           0.494848        0.505050            0.080401            0.08~~~~
DUURUVA [ 0x00 ]   __mean:         -0.010000       -0.000000            0.510100            0.48~~~~
DUURUVA [ 0x00 ]   __M2             48.989990       49.999992           7.959698            ~.~~~~~~
DUURUVA [ 0x00 ]   __M3             0.469813       -0.000005           -0.036191            0.~~~~~~
DUURUVA [ 0x00 ]   __M4             36.489376       37.499985           1.101642            1.~~~~~~
DUURUVA [ 0x00 ]   __kurtosis      -1.479621       -1.500000           -1.261210           -1.~~~~~~
DUURUVA [ 0x00 ]   __skewness       0.000006       -0.000000           -0.000254            0.000~~~


(velocity_as_0x01); and so on on any creative manner (they all work, market is easy). #FIXME ¿sure about that? (says the devil...)
(¿what other non redudant measures there are of is of a given coin?---many, ... #FIXME)
*/ 

#include <time.h>
int main(){
    srand(time(NULL));
    unsigned int c_num_duuruva=0x01;
    __duuruva_t *c_duuruva = duuruva_fabric(c_num_duuruva,"testingduuruva.dumpfile");
    __cwcn_type_t c_input_vector[LOAD_SIZE][ALLIU_SIZE]={
        {0.00},
        {0.01},{0.02},{0.03},{0.04},{0.05},{0.06},{0.07},{0.08},{0.09},{0.1},
        {0.11},{0.12},{0.13},{0.14},{0.15},{0.16},{0.17},{0.18},{0.19},{0.2},
        {0.21},{0.22},{0.23},{0.24},{0.25},{0.26},{0.27},{0.28},{0.29},{0.3},
        {0.31},{0.32},{0.33},{0.34},{0.35},{0.36},{0.37},{0.38},{0.39},{0.4},
        {0.41},{0.42},{0.43},{0.44},{0.45},{0.46},{0.47},{0.48},{0.49},{0.5},
        {0.51},{0.52},{0.53},{0.54},{0.55},{0.56},{0.57},{0.58},{0.59},{0.6},
        {0.61},{0.62},{0.63},{0.64},{0.65},{0.66},{0.67},{0.68},{0.69},{0.7},
        {0.71},{0.72},{0.73},{0.74},{0.75},{0.76},{0.77},{0.78},{0.79},{0.8},
        {0.81},{0.82},{0.83},{0.84},{0.85},{0.86},{0.87},{0.88},{0.89},{0.9},
        {0.91},{0.92},{0.93},{0.94},{0.95},{0.96},{0.97},{0.98},{0.99}};
    for(unsigned int ctx_p=0x00;ctx_p<LOAD_SIZE;ctx_p++){
        for(unsigned int idx_v=0x00;idx_v<ALLIU_SIZE;idx_v++){
            // c_input_vector[ctx_p][idx_v]=sin(2*3.141592*c_input_vector[ctx_p][idx_v]);
            c_input_vector[ctx_p][idx_v]=(float)(rand()%100)/100.0;
            fprintf(stdout, "%f -> %f\n",c_input_vector[ctx_p][idx_v],c_input_vector[ctx_p][idx_v]);
        }
    }
    for(unsigned int ctx=0x00;ctx<100;ctx++){
        set_duuruva_value(c_duuruva, c_input_vector[idx]);
        dist_duuruva(c_duuruva);
        print_duuruva(c_duuruva);
    }
    reset_duuruva(c_duuruva);
    destroy_duuruva(c_duuruva);
    
    printf("\033[1;32mwaka dao\033[0m\n");
    printf("\033[1;32mwaka din\033[0m\n");
    printf("\033[1;32mwaka tao\033[0m\n");
}