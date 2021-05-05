#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
// #FIXME fix dependencies
#define BUGGER_ENTROPYCOSA_SIZE (unsgined int 2) // cauchy + beta=2

#define DIRECT_RESOLUTION (int) 25
#define NUM_TSANE (int) 2

#define GAMMA_SCALE (__cwcn_type_t) 1

#ifndef ENTROPY_DEBUG
// #define ENTROPY_DEBUG
#endif
#ifndef ENTROPY_NEBAJKE_INCLUDED
#define ENTROPY_NEBAJKE_INCLUDED
#define clrscr() printf("\e[1;1H\e[2J")

typedef _Bool ___cwcn_bool_t;
#define ___CWCN_TRUE (___cwcn_bool_t) 0b1
#define ___CWCN_FALSE (___cwcn_bool_t) 0b0
typedef float (__cwcn_type_t);
#define __cwcn_infinite (__cwcn_type_t) 0xFFFFFFFF
typedef __cwcn_type_t (*__function_pointer_t)(__cwcn_type_t);
#define __cwcn_type_size sizeof(__cwcn_type_t) // #FIXME not in use
#define __function_pointer_t_size sizeof(__function_pointer_t)
#define max(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a > _b ? _a : _b;})
#define min(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a < _b ? _a : _b;})

/*
    UTILS
*/
void set_seed();
void delay(double dly);
__cwcn_type_t GAMMA(__cwcn_type_t input, __cwcn_type_t gamma_res);
__cwcn_type_t DIGAMMA(__cwcn_type_t input);
__cwcn_type_t B_fun(__cwcn_type_t alpha, __cwcn_type_t beta, __cwcn_type_t gamma_res, _Bool allow_div);
/*
    BETA distribution
*/
typedef void (*__beta_forward_pointer_t)(void *_beta_pdf, __cwcn_type_t _beta_lambda, __cwcn_type_t _beta_eta);
typedef struct beta_pdf{
    int __eta_index; // #FIXME
    int __lambda_index; // #FIXME
    __cwcn_type_t __eta;
    __cwcn_type_t __lambda;
    __cwcn_type_t __max_eta;
    __cwcn_type_t __max_lambda;
    __cwcn_type_t __gamma_res;
    double __entropy;
    double __max_known_entropy;
    __cwcn_type_t __beta_kemu;
    __cwcn_type_t __beta_input;
    __cwcn_type_t *__direct_map;
    __cwcn_type_t *__tsane_map;
    unsigned int __beta_lambda_tsinuu_index;
    unsigned int __beta_eta_tsinuu_index;
    unsigned int __num_tsane;
    unsigned int __direct_resolution;
    unsigned int __num_params; // lambda + eta = 2
    __beta_forward_pointer_t __forward;
} __beta_pdf_t;
__beta_pdf_t *_ipivye_beta_pdf(unsigned int _d_res, unsigned int _n_tsane);

typedef void (*__cauchy_forward_pointer_t)(void *_cauchy_pdf, __cwcn_type_t _cauchy_a, __cwcn_type_t _cauchy_b);
typedef struct cauchy_pdf{
    __cwcn_type_t *__direct_map;
	__cwcn_type_t *__tsane_map;
    __cwcn_type_t __entropy;
    __cwcn_type_t __max_known_entropy;
    __cwcn_type_t __cauchy_kemu;
    __cwcn_type_t __cauchy_input;
    __cwcn_type_t __cauchy_a;
    __cwcn_type_t __cauchy_b;
    __cwcn_type_t __cauchy_a_max;
    __cwcn_type_t __cauchy_b_max;
    __cwcn_type_t __cauchy_a_min;
    __cwcn_type_t __cauchy_input_max;
    __cwcn_type_t __cauchy_input_min;
    unsigned int __cauchy_a_tsinuu_index;
    unsigned int __cauchy_b_tsinuu_index;
    unsigned int __num_tsane;
    unsigned int __direct_resolution;
    __cauchy_forward_pointer_t __forward;
    unsigned int __num_params;
} __cauchy_pdf_t;
__cauchy_pdf_t *_ipivye_cauchy_pdf(unsigned int _d_res, unsigned int _n_tsane);

typedef void (*__entropycosa_forward_pointer_t)(void _ec, __cwcn_type_t *_param_vect);
typedef struct __entropycosa{
    void **__cosa;
    unsigned int __total_cosa_params;
    unsigned int __cosa_size;
    __entropycosa_forward_pointer_t __forward;
}__entropycosa_t;
__entropycosa_t *entropycosa_fabric(unsigned int _d_res, unsigned int _n_tsane);
void entropycosa_destroy(__entropycosa_t *_ec);

/*
    MAIN ENTROPY FUNCS
*/

// // BETA
void beta_plot_direct_resolution(__beta_pdf_t *_beta_pdf);
void beta_plot_tsane(__beta_pdf_t *_beta_pdf);
void beta_plot_statistics(__beta_pdf_t *_beta_pdf);
void beta_difference_entropy(__beta_pdf_t *_beta_pdf, _Bool _in_nats);
void beta_map_tsane(__beta_pdf_t *_beta_pdf);
void beta_GAMMA_RESOLUTION(__beta_pdf_t *_beta_pdf);
void beta_probability_density(__beta_pdf_t *_beta_pdf);
void beta_inverse_density(__beta_pdf_t *_beta_pdf);
void beta_direct_density(__beta_pdf_t *_beta_pdf);
void beta_differential_entropy(__beta_pdf_t *_beta_pdf, _Bool _in_nats);
void set_beta_lambda(__beta_pdf_t *_beta_pdf, __cwcn_type_t _lambda);
void set_beta_eta(__beta_pdf_t *_beta_pdf, __cwcn_type_t _eta);
void set_beta_input(__beta_pdf_t *_beta_pdf, __cwcn_type_t _input);
void set_beta_num_tsane(__beta_pdf_t *_beta_pdf, unsigned int _n_tsane);
void set_beta_direct_resolution(__beta_pdf_t *_beta_pdf, unsigned int _d_res);
void beta_forward(void *_beta_pdf, __cwcn_type_t _beta_lambda, __cwcn_type_t _beta_eta);
// // CAUCHY 
void set_cauchy_a(__cauchy_pdf_t *_cauchy_pdf, __cwcn_type_t _cauchy_a);
void set_cauchy_b(__cauchy_pdf_t *_cauchy_pdf, __cwcn_type_t _cauchy_b);
void set_cauchy_input(__cauchy_pdf_t *_cauchy_pdf, __cwcn_type_t _input);
void set_cauchy_num_tsane(__cauchy_pdf_t *_cauchy_pdf, unsigned int _n_tsane);
void set_cauchy_direct_resolution(__cauchy_pdf_t *_cauchy_pdf, unsigned int _d_res);
void cauchy_probability_density(__cauchy_pdf_t *_cauchy_pdf);
void cauchy_direct_density(__cauchy_pdf_t *_cauchy_pdf);
void cauchy_difference_entropy(__cauchy_pdf_t *_cauchy_pdf, _Bool _in_nats);
void cauchy_map_tsane(__cauchy_pdf_t *_cauchy_pdf);
void cauchy_plot_direct_resolution(__cauchy_pdf_t *_cauchy_pdf);
void cauchy_plot_tsane(__cauchy_pdf_t *_cauchy_pdf);
void cauchy_plot_statistics(__cauchy_pdf_t *_cauchy_pdf);
void cauchy_forward(void *_cauchy_pdf, __cwcn_type_t _cauchy_a, __cwcn_type_t _cauchy_b);


// // CHI
// __cwcn_type_t chi_n(__cwcn_type_t input);
// __cwcn_type_t chi_sigma(__cwcn_type_t input);
// __cwcn_type_t probability_density_chi(__cwcn_type_t input);
// __cwcn_type_t differential_entropy_chi(__cwcn_type_t input);

// __cwcn_type_t chi2_n(__cwcn_type_t input);
// __cwcn_type_t chi2_GAMMA(__cwcn_type_t input);
// __cwcn_type_t chi2_sigma(__cwcn_type_t input);
// __cwcn_type_t probability_density_chi2(__cwcn_type_t input);
// __cwcn_type_t differential_entropy_chi2(__cwcn_type_t input);

// // DIRAC DELTA
// __cwcn_type_t probability_density_dirac_delta(__cwcn_type_t input);
// __cwcn_type_t differential_entropy_dirac_delta(__cwcn_type_t input);

// // Exponential
// __cwcn_type_t probability_density_exponential(__cwcn_type_t input);

// // F
// __cwcn_type_t f_nu(__cwcn_type_t input);
// __cwcn_type_t f_omega(__cwcn_type_t input);
// __cwcn_type_t f_B(__cwcn_type_t input_nu, __cwcn_type_t input_omega);
// __cwcn_type_t probability_density_f(__cwcn_type_t input);
// __cwcn_type_t differential_entropy_f(__cwcn_type_t input);

// // GAMMA
// __cwcn_type_t gamma_eta(__cwcn_type_t input);
// __cwcn_type_t gamma_lambda(__cwcn_type_t input);
// __cwcn_type_t gamma_GAMMA(__cwcn_type_t input);
// __cwcn_type_t probability_density_gamma(__cwcn_type_t input);
// __cwcn_type_t differential_entropy_gamma(__cwcn_type_t input);

// // Generalized Beta
// __cwcn_type_t betaG_a(__cwcn_type_t input);
// __cwcn_type_t betaG_b(__cwcn_type_t input);
// __cwcn_type_t betaG_eta(__cwcn_type_t input);
// __cwcn_type_t betaG_lambda(__cwcn_type_t input);
// __cwcn_type_t betaG_GAMMA(__cwcn_type_t input);
// __cwcn_type_t probability_density_betaG(__cwcn_type_t input);
// __cwcn_type_t differential_entropy_betaG(__cwcn_type_t input);

// // Generalized Normal
// __cwcn_type_t Gnormal_alpha(__cwcn_type_t input);
// __cwcn_type_t Gnormal_beta(__cwcn_type_t input);
// __cwcn_type_t Gnormal_mu(__cwcn_type_t input);
// __cwcn_type_t Gnormal_GAMMA(__cwcn_type_t input);
// __cwcn_type_t probability_density_Gnormal(__cwcn_type_t input);
// __cwcn_type_t differential_entropy_(__cwcn_type_t input);

// // Kumaraswamy
// __cwcn_type_t kumaraswamy_a(__cwcn_type_t input);
// __cwcn_type_t kumaraswamy_b(__cwcn_type_t input);
// __cwcn_type_t probability_density_kumaraswamy(__cwcn_type_t input);
// __cwcn_type_t differential_entropy_kumaraswamy(__cwcn_type_t input);


// __cwcn_type_t (__cwcn_type_t input);
// __cwcn_type_t (__cwcn_type_t input);
// __cwcn_type_t (__cwcn_type_t input);
// __cwcn_type_t (__cwcn_type_t input);
// __cwcn_type_t probability_density_(__cwcn_type_t input);
// __cwcn_type_t differential_entropy_(__cwcn_type_t input);
// __cwcn_type_t differential_entropy_(__cwcn_type_t input);
// __cwcn_type_t (__cwcn_type_t input);
// __cwcn_type_t (__cwcn_type_t input);
// __cwcn_type_t (__cwcn_type_t input);
// __cwcn_type_t (__cwcn_type_t input);
// __cwcn_type_t probability_density_(__cwcn_type_t input);
// __cwcn_type_t differential_entropy_(__cwcn_type_t input);
// __cwcn_type_t differential_entropy_(__cwcn_type_t input);
// __cwcn_type_t (__cwcn_type_t input);
// __cwcn_type_t (__cwcn_type_t input);
// __cwcn_type_t (__cwcn_type_t input);
// __cwcn_type_t (__cwcn_type_t input);
// __cwcn_type_t probability_density_(__cwcn_type_t input);
// __cwcn_type_t differential_entropy_(__cwcn_type_t input);
// __cwcn_type_t differential_entropy_(__cwcn_type_t input);
// __cwcn_type_t (__cwcn_type_t input);
// __cwcn_type_t (__cwcn_type_t input);
// __cwcn_type_t (__cwcn_type_t input);
// __cwcn_type_t (__cwcn_type_t input);
// __cwcn_type_t probability_density_(__cwcn_type_t input);
// __cwcn_type_t differential_entropy_(__cwcn_type_t input);
#endif