#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cwcn_entropy_nebajke.h"

void test_beta(){
    __beta_pdf_t *c_beta_pdf = _ipivye_beta_pdf(DIRECT_RESOLUTION, NUM_TSANE);
    __cwcn_type_t l_ctx=0;
    __cwcn_type_t e_ctx=0;
    while(1){
        printf("\n*******BETA*******");
        set_beta_lambda(c_beta_pdf, l_ctx);
        set_beta_eta(c_beta_pdf, e_ctx);
        l_ctx+=0.1;
        if(c_beta_pdf->__lambda>=c_beta_pdf->__max_lambda){l_ctx=0;e_ctx+=0.1;}
        if(c_beta_pdf->__eta>=c_beta_pdf->__max_eta){e_ctx=0;}
        clock_t begin = clock();
        beta_forward(c_beta_pdf);
        printf("forward method execution time : %f\n",(double)(clock()-begin)/CLOCKS_PER_SEC);
        clrscr();
        // getchar();
        // Plotting histogram
        beta_plot_direct_resolution(c_beta_pdf);
        beta_plot_tsane(c_beta_pdf);
        beta_plot_statistics(c_beta_pdf);
        printf(">> hay que resolver GAMMA_RESOLUTION...");
        delay(0.025);
    }
}
void test_cauchy(){
    __cauchy_pdf_t *c_cauchy_pdf = _ipivye_cauchy_pdf(DIRECT_RESOLUTION, NUM_TSANE);
    __cwcn_type_t a_ctx=0.0; 
    __cwcn_type_t b_ctx=0.0;
    while(1){
        printf("\n******CAUCHY********");
        // for exibition porpouses
    printf("\ta:%f \tb:%f\n",c_cauchy_pdf->__cauchy_a, c_cauchy_pdf->__cauchy_b);
        set_cauchy_a(c_cauchy_pdf, a_ctx);
        set_cauchy_b(c_cauchy_pdf, b_ctx);
        a_ctx+=0.05;
        if(c_cauchy_pdf->__cauchy_a>=c_cauchy_pdf->__cauchy_a_max){a_ctx=0x00;b_ctx+=0.05;}
        if(c_cauchy_pdf->__cauchy_b>=c_cauchy_pdf->__cauchy_b_max){b_ctx=0x00;}
        printf("\ta:%f/%f \tb:%f/%f\n",c_cauchy_pdf->__cauchy_a, a_ctx, c_cauchy_pdf->__cauchy_b, b_ctx);
        // direct
        clock_t begin = clock();
        cauchy_forward(c_cauchy_pdf);
        printf("forward method execution time : %f\n",(double)(clock()-begin)/CLOCKS_PER_SEC);
        // clrscr();
        // getchar();
        // Plotting histogram
        cauchy_plot_direct_resolution(c_cauchy_pdf);
        cauchy_plot_tsane(c_cauchy_pdf);
        cauchy_plot_statistics(c_cauchy_pdf);
        delay(0.025);
    }
}
int main(){
    set_seed();
    printf("\033[1;32mwaka dao\033[0m\n");
    test_beta();
    printf("\033[1;32mwaka din\033[0m\n");
    printf("\033[1;32mwaka tao\033[0m\n");
}
