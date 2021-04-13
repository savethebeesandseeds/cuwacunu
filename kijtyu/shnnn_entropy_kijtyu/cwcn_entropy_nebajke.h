#ifndef FUNCTIONS_NET_MECH
#define FUNCTIONS_NET_MECH
// main discreet ENTROPY
float diff_d_entropy(float input);
float d_entropy_update_function(float input);

// main continious ENTROPY
float diff_s_entropy(float input);

/*
    Distribuciones de probabilidad
*/

// BETA
float beta_eta(float input);
float beta_lambda(float input);
float beta_GAMMA(float input);
float probability_density_beta(float input);
float differential_entropy_beta(float input);

// CAUCHY 
float probability_density_cauchy(float input);
float differential_entropy_cauchy(float input);

// CHI
float chi_n(float input);
float chi_sigma(float input);
float probability_density_chi(float input);
float differential_entropy_chi(float input);

float chi2_n(float input);
float chi2_GAMMA(float input);
float chi2_sigma(float input);
float probability_density_chi2(float input);
float differential_entropy_chi2(float input);

// DIRAC DELTA
float probability_density_dirac_delta(float input);
float differential_entropy_dirac_delta(float input);

// Exponential
float probability_density_exponential(float input);

// F
float f_nu(float input);
float f_omega(float input);
float f_B(float input_nu, float input_omega);
float probability_density_f(float input);
float differential_entropy_f(float input);

// GAMMA
float gamma_eta(float input);
float gamma_lambda(float input);
float gamma_GAMMA(float input);
float probability_density_gamma(float input);
float differential_entropy_gamma(float input);

// Generalized Beta
float betaG_a(float input);
float betaG_b(float input);
float betaG_eta(float input);
float betaG_lambda(float input);
float betaG_GAMMA(float input);
float probability_density_betaG(float input);
float differential_entropy_betaG(float input);

// Generalized Normal
float Gnormal_alpha(float input);
float Gnormal_beta(float input);
float Gnormal_mu(float input);
float Gnormal_GAMMA(float input);
float probability_density_Gnormal(float input);
float differential_entropy_(float input);

// Kumaraswamy
float kumaraswamy_a(float input);
float kumaraswamy_b(float input);
float probability_density_kumaraswamy(float input);
float differential_entropy_kumaraswamy(float input);


float (float input);
float (float input);
float (float input);
float (float input);
float probability_density_(float input);
float differential_entropy_(float input);
float differential_entropy_(float input);
float (float input);
float (float input);
float (float input);
float (float input);
float probability_density_(float input);
float differential_entropy_(float input);
float differential_entropy_(float input);
float (float input);
float (float input);
float (float input);
float (float input);
float probability_density_(float input);
float differential_entropy_(float input);
float differential_entropy_(float input);
float (float input);
float (float input);
float (float input);
float (float input);
float probability_density_(float input);
float differential_entropy_(float input);
#endif