#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "entropy_test.config.h"
#ifdef IS_ENTROPY_TEST
#endif
#ifndef ENTROPY_NEBAJKE_INCLUDED
#define ENTROPY_NEBAJKE_INCLUDED
#define clrscr() printf("\e[1;1H\e[2J")
/*
    UTILS
*/
float GAMMA(float input, float gamma_res);
float DIGAMMA(float input);
float B_fun(float alpha, float beta, float gamma_res, _Bool allow_div);
/*
    BETA distribution
*/
struct beta_pdf{
    int __eta_index;
    int __lambda_index;
    float __eta;
    float __lambda;
    float __max_eta;
    float __max_lambda;
    float __gamma_res;
    double __entropy;
    float __kemu_beta;
    float __direct_map[DIRECT_RESOLUTION];
    float __tsane_map[NUM_TSANE];
};
/*
    MAIN ENTROPY FUNCS
*/
void difference_entropy(struct beta_pdf * _pdf, _Bool _in_nats);
void beta_map_tsane(struct beta_pdf * _beta_pdf);
void beta_GAMMA_RESOLUTION(struct beta_pdf * _beta_pdf);
void beta_probability_density(float input, struct beta_pdf * _beta_pdf);
void inverse_density_beta(struct beta_pdf * _beta_pdf);
void direct_density_beta(struct beta_pdf * _beta_pdf);
void differential_entropy_beta(struct beta_pdf * _beta_pdf, _Bool _in_nats);


// // CAUCHY 
// float probability_density_cauchy(float input);
// float differential_entropy_cauchy(float input);

// // CHI
// float chi_n(float input);
// float chi_sigma(float input);
// float probability_density_chi(float input);
// float differential_entropy_chi(float input);

// float chi2_n(float input);
// float chi2_GAMMA(float input);
// float chi2_sigma(float input);
// float probability_density_chi2(float input);
// float differential_entropy_chi2(float input);

// // DIRAC DELTA
// float probability_density_dirac_delta(float input);
// float differential_entropy_dirac_delta(float input);

// // Exponential
// float probability_density_exponential(float input);

// // F
// float f_nu(float input);
// float f_omega(float input);
// float f_B(float input_nu, float input_omega);
// float probability_density_f(float input);
// float differential_entropy_f(float input);

// // GAMMA
// float gamma_eta(float input);
// float gamma_lambda(float input);
// float gamma_GAMMA(float input);
// float probability_density_gamma(float input);
// float differential_entropy_gamma(float input);

// // Generalized Beta
// float betaG_a(float input);
// float betaG_b(float input);
// float betaG_eta(float input);
// float betaG_lambda(float input);
// float betaG_GAMMA(float input);
// float probability_density_betaG(float input);
// float differential_entropy_betaG(float input);

// // Generalized Normal
// float Gnormal_alpha(float input);
// float Gnormal_beta(float input);
// float Gnormal_mu(float input);
// float Gnormal_GAMMA(float input);
// float probability_density_Gnormal(float input);
// float differential_entropy_(float input);

// // Kumaraswamy
// float kumaraswamy_a(float input);
// float kumaraswamy_b(float input);
// float probability_density_kumaraswamy(float input);
// float differential_entropy_kumaraswamy(float input);


// float (float input);
// float (float input);
// float (float input);
// float (float input);
// float probability_density_(float input);
// float differential_entropy_(float input);
// float differential_entropy_(float input);
// float (float input);
// float (float input);
// float (float input);
// float (float input);
// float probability_density_(float input);
// float differential_entropy_(float input);
// float differential_entropy_(float input);
// float (float input);
// float (float input);
// float (float input);
// float (float input);
// float probability_density_(float input);
// float differential_entropy_(float input);
// float differential_entropy_(float input);
// float (float input);
// float (float input);
// float (float input);
// float (float input);
// float probability_density_(float input);
// float differential_entropy_(float input);
#endif