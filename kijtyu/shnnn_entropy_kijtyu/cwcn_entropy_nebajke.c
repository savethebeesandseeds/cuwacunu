#include "cwcn_entropy_nebajke.h"
// Discreet ENTROPY
void difference_entropy(struct beta_pdf * _pdf, _Bool _in_nats){
    if(_in_nats){ // in nats!
        _pdf->__entropy = 0;
        for(int idx=0; idx < DIRECT_RESOLUTION;idx++){
            if(_pdf->__direct_map[idx]>0.001*DIRECT_RESOLUTION){
                _pdf->__entropy += (-1)*_pdf->__direct_map[idx]*log(_pdf->__direct_map[idx]);
            }
        }
    } else{ // in bits
        _pdf->__entropy = 0;
        for(int idx=0; idx < DIRECT_RESOLUTION;idx++){
            if(_pdf->__direct_map[idx]>0.001*DIRECT_RESOLUTION){
                _pdf->__entropy += (-1)*_pdf->__direct_map[idx]*log2(_pdf->__direct_map[idx]);
            }
        }
    }
}
/*
    UTILS
*/
float GAMMA(float input, float gamma_res){ // FIXME, find the optimal range of discrete GAMMA
    float g_v = 1;
    for(unsigned short fact=1;fact<=input * gamma_res - 1; fact++){
        g_v = g_v * (fact);
    }
    // printf("FACTORIAL: >> input: %f, gamma_res: %f, goesto: %f == %f.\n",input, gamma_res, input * gamma_res - 1, g_v);
    return g_v;
}
float DIGAMMA(float input){
    return log(input)-1/2/input;
}
float B_fun(float alpha, float beta, float gamma_res, _Bool allow_div){
    if(allow_div){
        return GAMMA((float)alpha/2.0, gamma_res)*GAMMA(beta/2.0, gamma_res)/GAMMA((alpha+beta)/2.0, gamma_res);
    } else {
        return GAMMA(alpha, gamma_res)*GAMMA(beta, gamma_res)/GAMMA((alpha+beta), gamma_res);
    }
}
/*
    Distribuciones de probabilidad
*/
/*
    BETA distribution
*/
void beta_map_tsane(struct beta_pdf * _beta_pdf){
    // FIXME, this computational method can be better
    unsigned int ctx=0;
    for(unsigned int idx=0; idx<NUM_TSANE;idx++){
        _beta_pdf->__tsane_map[idx] = 0;
        for(unsigned int idy=0; idy<(int)DIRECT_RESOLUTION/NUM_TSANE;idy++){
            _beta_pdf->__tsane_map[idx] += _beta_pdf->__direct_map[ctx];
            // printf(">> ctd %d, dir: %f\n", idx, _beta_pdf->__direct_map[ctx]);
            ctx++;
        }
    }
}
void beta_GAMMA_RESOLUTION(struct beta_pdf * _beta_pdf){
    _beta_pdf->__gamma_res = (float) \
    (_beta_pdf->__lambda + _beta_pdf->__eta)*((_beta_pdf->__max_lambda+1)*(_beta_pdf->__max_eta+1))/\
    ((_beta_pdf->__eta+1)*(_beta_pdf->__lambda+1))/(_beta_pdf->__max_lambda+_beta_pdf->__max_eta) * 0.1;
    // printf(">> _beta_pdf->__gamma_res: %f\n", _beta_pdf->__gamma_res);
}
// BETA
void beta_probability_density(float input, struct beta_pdf * _beta_pdf){
    if(input < 0 || input > 1){return;}
    assert(_beta_pdf->__lambda > 0);
    assert(_beta_pdf->__eta > 0);
    _beta_pdf->__kemu_beta = 1/B_fun(_beta_pdf->__lambda,_beta_pdf->__eta, _beta_pdf->__gamma_res, 0xFF)*pow(input, _beta_pdf->__lambda -1) * pow(1 - input, _beta_pdf->__eta - 1);
    
}
void inverse_density_beta(struct beta_pdf * _beta_pdf){
    // not implemented
}
void direct_density_beta(struct beta_pdf * _beta_pdf){
    float c_1 = 1/B_fun(_beta_pdf->__lambda, _beta_pdf->__eta, _beta_pdf->__gamma_res, 0xFF);
    unsigned long count=0;
    for(unsigned short idx=0;idx<DIRECT_RESOLUTION;idx++){
        float input = ((float)idx+0.5)/(float)DIRECT_RESOLUTION;
        _beta_pdf->__direct_map[idx] = c_1*pow(input,_beta_pdf->__lambda-1)*pow(1-input, _beta_pdf->__eta-1);
        count += _beta_pdf->__direct_map[idx];
    }
    for(unsigned short idx=0;idx<DIRECT_RESOLUTION;idx++){
        _beta_pdf->__direct_map[idx] /= count;
    }
    
}
void differential_entropy_beta(struct beta_pdf * _beta_pdf, _Bool _in_nats){
    // #FIXME -- due to gamma_res, entropy is not in nats or ¿bits?
    double numerator = \
        B_fun(_beta_pdf->__eta, _beta_pdf->__lambda,_beta_pdf->__gamma_res, 0xFF) *\
        exp(_beta_pdf->__eta+_beta_pdf->__lambda-2) *\
        DIGAMMA(_beta_pdf->__eta+_beta_pdf->__lambda);
    double denominator = \
        exp(_beta_pdf->__lambda-1)*\
        DIGAMMA(_beta_pdf->__lambda)*\
        exp(_beta_pdf->__eta-1)*\
        DIGAMMA(_beta_pdf->__eta);
    if(_in_nats){ // in nats!
        _beta_pdf->__entropy = log(numerator/denominator); // #FIXME, nat or bit?
    } else{ // in bits
        _beta_pdf->__entropy = log2(numerator/denominator); // #FIXME, nat or bit?
    }
    // printf(">> DIFFENTIAL ENTROPY: numeator: %f, denominator: %f, entropy: %f\n", numerator, denominator, _beta_pdf->__entropy);
}

// // CAUCHY
// float probability_density_cauchy(float input){
//     assert(cauchy_b > 0);
//     return 1 / cauchy_pi / cauchy_b / (1 + pow((input - cauchy_a),2) / pow(cauchy_b, 2))
// }
// void inverse_probability_density_cauchy(float cauchy_a)
// float differential_entropy_cauchy(float input){return 0;}
// // CHI
// float chi_n(float input){return input;}
// float chi_sigma(float input){return input;}
// float probability_density_chi(float input){
//     if(inpur < 0){return 0;}
//     return 2 * pow(chi_n/2, chi_n/2) /pow(chi_sigma,chi_n) * exp(-1 * chi_N / 2 / pow(chi_sigma, 2)) * pow(input,2);
// }
// float differential_entropy_chi(float input){return 0;}

// float chi2_n(float input){return input;}
// float chi2_GAMMA(float input){return input;}
// float chi2_sigma(float input){return input;}
// float probability_density_chi2(float input){
//     if(inpur < 0){return 0;}
//     assert(chi2_n >= 0);
//     return 1 / pow(2, chi2_n/2) / chi2_GAMMA(chi2_n/2) * pow(input, chi2_n/2 -1) * exp(-1 * input/2);
// }
// float differential_entropy_chi2(float input){return 0;}

// // DIRAC DELTA
// float probability_density_dirac_delta(float input){return input;}
// float differential_entropy_dirac_delta(float input){return 0;}

// // Exponential
// float probability_density_exponential(float input){
//     if(inpur < 0){return 0;}
//     assert(lambda > 0);
//     exponential_lambda * exp(-1 * exponential_lambda * input);
// }

// // F
// float f_nu(float input){return input;}
// float f_omega(float input){return input;}
// float f_B(float input_nu, float input_omega){return input_nu + input_omega;}
// float probability_density_f(float input){
//     if(input < 0){return 0;}
//     assert(f_nu > 0);
//     assert(f_omega > 0);
//     return pow(f_nu, f_nu/2) * pow(f_omega, f_omega/2) / f_B(f_nu/2, f_omega) * pow(input, f_nu/2 - 1) / pow((f_omega + f_nu * input), (f_nu + f_omega)/2);
// }
// float differential_entropy_f(float input){return 0;}

// // GAMMA
// float gamma_eta(float input){return input;}
// float gamma_lambda(float input){return input;}
// float gamma_GAMMA(float input){return input;}
// float probability_density_gamma(float input){
//     if(inpur < 0){return 0;}
//     assert(gamma_lambda > 0);
//     assert(gamma_eta > 0);
//     return pow(gamma_lambda, gamma_eta) / gamma_GAMMA(gamma_eta) * pow(input, gamma_eta - 1) * pow(input, gamma_eta - 1) * exp(-1 * gamma_lambda * input);
// }
// float differential_entropy_gamma(float input){return 0;}

// // Generalized Beta
// float betaG_a(float input){return input;}
// float betaG_b(float input){return input;}
// float betaG_eta(float input){return input;}
// float betaG_lambda(float input){return input;}
// float (float input){return input;}
// float probability_density_betaG(float input){
//     if(input < 0 or input > 1){return 0;}
//     assert(betaG_lambda > 0);
//     assert(betaG_eta > 0);
//     assert(betaG_a >= 0);
//     return 1 / (betaG_b - betaG_a) * (betaG_eta+betaG_lambda) / (betaG_eta) / (betaG_lambda) * pow((input - betaG_a)/(bataG_b - input), betaG_lambda -1) * pow((betaG_b - input)/(betaG_b - betaG_a), betaG_eta - 1);
// }
// float differential_entropy_betaG(float input){return 0;}

// // Generalized Normal
// float Gnormal_alpha(float input){return input;}
// float Gnormal_beta(float input){return input;}
// float Gnormal_mu(float input){return input;}
// float Gnormal_GAMMA(float input){return input;}
// float probability_density_Gnormal(float input){
//     assert(Gnormal_alpha > 0);
//     assert(Gnormal_beta > 0);
//     return Gnormal_beta / 2 / Gnormal_alpha / Gnormal_GAMMA(1(Gnormal_beta)) * exp(-1 * pow(abs(input - Gnormal_mu)/Gnormal_alpha, Gnormal_beta))
// }
// float differential_entropy_(float input){return 0;}

// // Kumaraswamy
// float kumaraswamy_a(float input){return input;}
// float kumaraswamy_b(float input){return input;}
// float probability_density_kumaraswamy(float input){
//     if(inpur < 0){return 0;}
//     if(inpur > 1){return 0;}
//     return kumaraswamy_a * kumaraswamy_b * pow(input, kumaraswamy_a - 1) * pow(1 - pow(input, kumaraswamy_a), kumaraswamy_b - 1)
// }
// float differential_entropy_kumaraswamy(float input){return 0;}


// // float (float input){return input;}
// // float (float input){return input;}
// // float (float input){return input;}
// // float (float input){return input;}
// // float probability_density_(float input){
// //     if(inpur < 0){return 0;}
// // }
// // float differential_entropy_(float input){return 0;}
// // float differential_entropy_(float input){return 0;}
// // float (float input){return input;}
// // float (float input){return input;}
// // float (float input){return input;}
// // float (float input){return input;}
// // float probability_density_(float input){
// //     if(inpur < 0){return 0;}
// // }
// // float differential_entropy_(float input){return 0;}
// // float differential_entropy_(float input){return 0;}
// // float (float input){return input;}
// // float (float input){return input;}
// // float (float input){return input;}
// // float (float input){return input;}
// // float probability_density_(float input){
// //     if(inpur < 0){return 0;}
// // }
// // float differential_entropy_(float input){return 0;}
// // float differential_entropy_(float input){return 0;}
// // float (float input){return input;}
// // float (float input){return input;}
// // float (float input){return input;}
// // float (float input){return input;}
// // float probability_density_(float input){
// //     if(inpur < 0){return 0;}
// // }
// // float differential_entropy_(float input){return 0;}
