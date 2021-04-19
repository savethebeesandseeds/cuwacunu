#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "entropy_test.config.h"
#include "cwcn_entropy_nebajke.h"
int main(){
    srand(time(NULL)); // set guarded seed
    float l_ctx=0; 
    float e_ctx=0;
    struct beta_pdf * c_beta_pdf = _ipivye_beta_pdf();
    while(1){
        printf("\n**************");
        if((_Bool) 0x00){
            // printf("\n>> LAMBDA:\t");
            // scanf("%f", & c_beta_pdf->__lambda);
            // printf("\n>> ETA:\t\t");
            // scanf("%f", & c_beta_pdf->__eta);
            // printf("\n");
        } else {
            c_beta_pdf->__lambda=(float) l_ctx*c_beta_pdf->__max_lambda;
            c_beta_pdf->__eta=(float) e_ctx*c_beta_pdf->__max_eta;
            l_ctx+=0.1;
            if(c_beta_pdf->__lambda>=c_beta_pdf->__max_lambda){
                l_ctx=0;
                e_ctx+=0.1;
            }
            if(c_beta_pdf->__eta>=c_beta_pdf->__max_eta){
                e_ctx=0;
            }
        }
        beta_GAMMA_RESOLUTION(c_beta_pdf);
        // direct
        clock_t begin = clock();
        direct_density_beta(c_beta_pdf);
        // differential_entropy_beta(c_beta_pdf, true);
        difference_entropy_beta(c_beta_pdf, 0xFF);
        beta_map_tsane(c_beta_pdf);
        clrscr();
        printf("exe_t : %f\n",(double)(clock()-begin)/CLOCKS_PER_SEC);
        // Plotting histogram
        printf("DIRECT:\n");
        for (int idx = 0; idx < DIRECT_RESOLUTION; idx++){
            printf("x=%0.2f |", (float)idx/(float)DIRECT_RESOLUTION);
            printf("y=%0.2f |", c_beta_pdf->__direct_map[idx]);
            if(c_beta_pdf->__direct_map[idx]<10000){
                for (int jdx = 0; jdx < c_beta_pdf->__direct_map[idx]*2500/DIRECT_RESOLUTION; jdx++){
                    printf("%c", (char)254u);
                }
            }
            if(idx==12){
                printf("\t\tENTROPY: %f", c_beta_pdf->__entropy);
            } else if(idx==15){
                printf("\t\t_lambda_: %3.2f", c_beta_pdf->__lambda);
            } else if(idx==16){
                printf("\t\t_eta_: %3.2f", c_beta_pdf->__eta);
            }
            printf("\n");
        }
        printf("--> TSANE:\n");
        for (int idx = 0; idx < NUM_TSANE; idx++){
            printf("x=%0.2f |", (float)idx/(float)NUM_TSANE);
            printf("y=%0.2f |", c_beta_pdf->__tsane_map[idx]);
            if(c_beta_pdf->__tsane_map[idx]<10000){
                for (int jdx = 0; jdx < c_beta_pdf->__tsane_map[idx]*50/NUM_TSANE; jdx++){
                    printf("%c", (char)254u);
                }
            }
            printf("\n");
        }
        printf(">> _ENTROPY_: %f \t _MAX_KNOWN_ENTROPY_: %f \t _lambda_: %3.2f \t _eta_: %3.2f _\n", c_beta_pdf->__entropy, c_beta_pdf->__max_known_entropy, c_beta_pdf->__lambda, c_beta_pdf->__eta);
        printf(">> hay que resolver GAMMA_RESOLUTION...");
        delay(0.25);
    }
}
