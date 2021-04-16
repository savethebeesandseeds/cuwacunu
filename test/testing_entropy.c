#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "entropy_test.config.h"
#include "cwcn_entropy_nebajke.h"
int main(){
    float l_ctx=0; 
    float e_ctx=0;
    float a_ctx=0;
    while(1){
        struct beta_pdf * new_beta_pdf = malloc(sizeof(struct beta_pdf));
        printf("\n**************");
        new_beta_pdf->__lambda_index=0;
        new_beta_pdf->__eta_index=0;
        if((_Bool) 0x00){
            printf("\n>> LAMBDA:\t");
            scanf("%f", & new_beta_pdf->__lambda);
            printf("\n>> ETA:\t\t");
            scanf("%f", & new_beta_pdf->__eta);
            printf("\n");
        } else {
            new_beta_pdf->__lambda=(float) l_ctx;
            new_beta_pdf->__eta=(float) e_ctx;
            if(l_ctx==2){
                e_ctx+=0.25*a_ctx;
                l_ctx =0;
                a_ctx += 1;
            } else {
                l_ctx+=0.5;
            }
        }
        new_beta_pdf->__max_lambda=100.0;
        new_beta_pdf->__max_eta=100.0;
        for(int idx=0;idx<NUM_TSANE;idx++){
            new_beta_pdf->__tsane_map[idx]=0;
        }
        new_beta_pdf->__entropy=0;
        beta_GAMMA_RESOLUTION(new_beta_pdf);
        // direct
        clock_t begin = clock();
        direct_density_beta(new_beta_pdf);
        // differential_entropy_beta(new_beta_pdf, true);
        difference_entropy(new_beta_pdf, 0xFF);
        beta_map_tsane(new_beta_pdf);
        clrscr();
        printf("exe_t : %f\n",(double)(clock()-begin)/CLOCKS_PER_SEC);
        // Plotting histogram
        printf("DIRECT:\n");
        for (int idx = 0; idx < DIRECT_RESOLUTION; idx++){
            printf("x=%0.2f |", (float)idx/(float)DIRECT_RESOLUTION);
            printf("y=%0.2f |", new_beta_pdf->__direct_map[idx]);
            if(new_beta_pdf->__direct_map[idx]<10000){
                for (int jdx = 0; jdx < new_beta_pdf->__direct_map[idx]*2500/DIRECT_RESOLUTION; jdx++){
                    printf("%c", (char)254u);
                }
            }
            if(idx==12){
                printf("\t\tENTROPY: %f", new_beta_pdf->__entropy);
            } else if(idx==15){
                printf("\t\t_lambda_: %3.2f", new_beta_pdf->__lambda);
            } else if(idx==16){
                printf("\t\t_eta_: %3.2f", new_beta_pdf->__eta);
            }
            printf("\n");
        }
        printf("--> TSANE:\n");
        for (int idx = 0; idx < NUM_TSANE; idx++){
            printf("x=%0.2f |", (float)idx/(float)NUM_TSANE);
            printf("y=%0.2f |", new_beta_pdf->__tsane_map[idx]);
            if(new_beta_pdf->__tsane_map[idx]<10000){
                for (int jdx = 0; jdx < new_beta_pdf->__tsane_map[idx]*50/NUM_TSANE; jdx++){
                    printf("%c", (char)254u);
                }
            }
            printf("\n");
        }
        printf(">> ENTROPY: %f \t _lambda_: %3.2f \t _eta_: %3.2f _\n", new_beta_pdf->__entropy, new_beta_pdf->__lambda, new_beta_pdf->__eta);
        delay(0.25);
    }
}
