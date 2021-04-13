#include <assert.h>

// main discreet ENTROPY
float diff_d_entropy(float input){return input;}
float d_entropy_update_function(float input){
    if(false){return 0xFFFFFFFF;} 
    return diff_d_entropy() * (1 + input);
    };

// main continious ENTROPY
float diff_s_entropy(float input){return input;}

/*
    Distribuciones de probabilidad
*/



// BETA
float beta_eta(float input){return input;}
float beta_lambda(float input){return input;}
float beta_GAMMA(float input){return input;}
float probability_density_beta(float input){
    if(input < 0 or input > 1){return 0;}
    assert(beta_lambda > 0);
    assert(beta_eta > 0);
    return beta_GAMMA(beta_eta+beta_lambda) * pow(input, beta_lambda -1) * pow(1 - input, beta_eta - 1) / beta_GAMMA(beta_eta) / beta_GAMMA(beta_lambda);
}
float differential_entropy_beta(float input){return 0;}

// CAUCHY 
float probability_density_cauchy(float input){
    assert(cauchy_b > 0)
    return 1 / cauchy_pi / cauchy_b / (1 + pow((input - cauchy_a),2) / pow(cauchy_b, 2)) 
}
float differential_entropy_cauchy(float input){return 0;}
// CHI
float chi_n(float input){return input;}
float chi_sigma(float input){return input;}
float probability_density_chi(float input){
    if(inpur < 0){return 0;}
    return 2 * pow(chi_n/2, chi_n/2) /pow(chi_sigma,chi_n) * exp(-1 * chi_N / 2 / pow(chi_sigma, 2)) * pow(input,2);
}
float differential_entropy_chi(float input){return 0;}

float chi2_n(float input){return input;}
float chi2_GAMMA(float input){return input;}
float chi2_sigma(float input){return input;}
float probability_density_chi2(float input){
    if(inpur < 0){return 0;}
    assert(chi2_n >= 0);
    return 1 / pow(2, chi2_n/2) / chi2_GAMMA(chi2_n/2) * pow(input, chi2_n/2 -1) * exp(-1 * input/2);
}
float differential_entropy_chi2(float input){return 0;}

// DIRAC DELTA
float probability_density_dirac_delta(float input){return input;} 
float differential_entropy_dirac_delta(float input){return 0;} 

// Exponential
float probability_density_exponential(float input){
    if(inpur < 0){return 0;}
    assert(lambda > 0);
    exponential_lambda * exp(-1 * exponential_lambda * input);
}

// F
float f_nu(float input){return input;}
float f_omega(float input){return input;}
float f_B(float input_nu, float input_omega){return input_nu + input_omega;}
float probability_density_f(float input){
    if(input < 0){return 0;}
    assert(f_nu > 0);
    assert(f_omega > 0);
    return pow(f_nu, f_nu/2) * pow(f_omega, f_omega/2) / f_B(f_nu/2, f_omega) * pow(input, f_nu/2 - 1) / pow((f_omega + f_nu * input), (f_nu + f_omega)/2);
}
float differential_entropy_f(float input){return 0;}

// GAMMA
float gamma_eta(float input){return input;}
float gamma_lambda(float input){return input;}
float gamma_GAMMA(float input){return input;}
float probability_density_gamma(float input){
    if(inpur < 0){return 0;}
    assert(gamma_lambda > 0);
    assert(gamma_eta > 0);
    return pow(gamma_lambda, gamma_eta) / gamma_GAMMA(gamma_eta) * pow(input, gamma_eta - 1) * pow(input, gamma_eta - 1) * exp(-1 * gamma_lambda * input);
}
float differential_entropy_gamma(float input){return 0;}

// Generalized Beta
float betaG_a(float input){return input;}
float betaG_b(float input){return input;}
float betaG_eta(float input){return input;}
float betaG_lambda(float input){return input;}
float betaG_GAMMA(float input){return input;}
float probability_density_betaG(float input){
    if(input < 0 or input > 1){return 0;}
    assert(betaG_lambda > 0);
    assert(betaG_eta > 0);
    assert(betaG_a >= 0);
    return 1 / (betaG_b - betaG_a) * betaG_GAMMA(betaG_eta+betaG_lambda) / betaG_GAMMA(betaG_eta) / betaG_GAMMA(betaG_lambda) * pow((input - betaG_a)/(bataG_b - input), betaG_lambda -1) * pow((betaG_b - input)/(betaG_b - betaG_a), betaG_eta - 1);
}
float differential_entropy_betaG(float input){return 0;}

// Generalized Normal
float Gnormal_alpha(float input){return input;}
float Gnormal_beta(float input){return input;}
float Gnormal_mu(float input){return input;}
float Gnormal_GAMMA(float input){return input;}
float probability_density_Gnormal(float input){
    assert(Gnormal_alpha > 0);
    assert(Gnormal_beta > 0);
    return Gnormal_beta / 2 / Gnormal_alpha / Gnormal_GAMMA(1(Gnormal_beta)) * exp(-1 * pow(abs(input - Gnormal_mu)/Gnormal_alpha, Gnormal_beta))
}
float differential_entropy_(float input){return 0;}

// Kumaraswamy
float kumaraswamy_a(float input){return input;}
float kumaraswamy_b(float input){return input;}
float probability_density_kumaraswamy(float input){
    if(inpur < 0){return 0;}
    if(inpur > 1){return 0;}
    return kumaraswamy_a * kumaraswamy_b * pow(input, kumaraswamy_a - 1) * pow(1 - pow(input, kumaraswamy_a), kumaraswamy_b - 1)
}
float differential_entropy_kumaraswamy(float input){return 0;}


float (float input){return input;}
float (float input){return input;}
float (float input){return input;}
float (float input){return input;}
float probability_density_(float input){
    if(inpur < 0){return 0;}
}
float differential_entropy_(float input){return 0;}
float differential_entropy_(float input){return 0;}
float (float input){return input;}
float (float input){return input;}
float (float input){return input;}
float (float input){return input;}
float probability_density_(float input){
    if(inpur < 0){return 0;}
}
float differential_entropy_(float input){return 0;}
float differential_entropy_(float input){return 0;}
float (float input){return input;}
float (float input){return input;}
float (float input){return input;}
float (float input){return input;}
float probability_density_(float input){
    if(inpur < 0){return 0;}
}
float differential_entropy_(float input){return 0;}
float differential_entropy_(float input){return 0;}
float (float input){return input;}
float (float input){return input;}
float (float input){return input;}
float (float input){return input;}
float probability_density_(float input){
    if(inpur < 0){return 0;}
}
float differential_entropy_(float input){return 0;}
