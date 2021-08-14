#include "cwcn_entropy_nebajke.h"
// Discreet ENTROPY
// void difference_entropy(__cwcn_type_t *__direct_map[DIRECT_RESOLUTION], double *__entropy, double *__max_known_entropy, _Bool _in_nats){

/*
    UTILS
*/
__cwcn_type_t GAMMA(__cwcn_type_t input, __cwcn_type_t gamma_res){ // FIXME, find the optimal range of discrete GAMMA
    __cwcn_type_t g_v = 1;
    for(unsigned short fact=1;fact<=input * gamma_res * GAMMA_SCALE - 1; fact++){
        g_v = g_v * (fact);
    }
    // fprintf(stdout, "FACTORIAL: >> input: %f, gamma_res: %f, goesto: %f == %f.\n",input, gamma_res, input * gamma_res - 1, g_v);
    return g_v;
}
__cwcn_type_t DIGAMMA(__cwcn_type_t input){
    return log(input)-1/2/input;
}
__cwcn_type_t B_fun(__cwcn_type_t A, __cwcn_type_t Z, __cwcn_type_t gamma_res, _Bool allow_div){
    if(allow_div){
        return GAMMA((__cwcn_type_t)A/2.0, gamma_res)*GAMMA(Z/2.0, gamma_res)/GAMMA((A+Z)/2.0, gamma_res);
    } else {
        return GAMMA(A, gamma_res)*GAMMA(Z, gamma_res)/GAMMA((A+Z), gamma_res);
    }
}


/*
    Distribuciones de probabilidad
*/

/*
    BETA distribution
*/
void beta_difference_entropy(__beta_pdf_t *_beta_pdf, _Bool _in_nats){
    if(_in_nats){ // in nats!
        _beta_pdf->__entropy = 0;
        for(unsigned int idx=0x00; idx < _beta_pdf->__direct_resolution;idx++){
            if(_beta_pdf->__direct_map[idx]>0.00001*_beta_pdf->__direct_resolution){ // avoid zero log
                _beta_pdf->__entropy += (-1)*_beta_pdf->__direct_map[idx]*log(_beta_pdf->__direct_map[idx]);
            }
        }
    } else{ // in bits
        _beta_pdf->__entropy = 0;
        for(unsigned int idx=0x00; idx < _beta_pdf->__direct_resolution;idx++){
            if(_beta_pdf->__direct_map[idx]>0.00001*_beta_pdf->__direct_resolution){ // avoid zero log
                _beta_pdf->__entropy += (-1)*_beta_pdf->__direct_map[idx]*log2(_beta_pdf->__direct_map[idx]);
            }
        }
    }
    if(_beta_pdf->__entropy>_beta_pdf->__max_known_entropy){
        _beta_pdf->__max_known_entropy=_beta_pdf->__entropy;
    }
}
void beta_map_tsane(__beta_pdf_t *_beta_pdf){
    // FIXME, this computational method can be better
    unsigned int ctx=0x00;
    for(unsigned int idx=0x00; idx<_beta_pdf->__num_tsane;idx++){
        _beta_pdf->__tsane_map[idx] = 0;
        for(unsigned int idy=0x00; idy<(unsigned int)_beta_pdf->__direct_resolution/_beta_pdf->__num_tsane;idy++){
            _beta_pdf->__tsane_map[idx] += _beta_pdf->__direct_map[ctx];
            // fprintf(stdout, ">> ctd %d, dir: %f\n", idx, _beta_pdf->__direct_map[ctx]);
            ctx++;
        }
    }
}
void beta_GAMMA_RESOLUTION(__beta_pdf_t *_beta_pdf){
    // _beta_pdf->__gamma_res = (__cwcn_type_t) (_beta_pdf->__lambda + _beta_pdf->__eta)*((_beta_pdf->__max_lambda+1)*(_beta_pdf->__max_eta+1))/((_beta_pdf->__eta+1)*(_beta_pdf->__lambda+1))/(_beta_pdf->__max_lambda+_beta_pdf->__max_eta) * 0.1;
    _beta_pdf->__gamma_res = (__cwcn_type_t) (_beta_pdf->__max_lambda + _beta_pdf->__max_eta);
    // fprintf(stdout, ">> _beta_pdf->__gamma_res: %f\n", _beta_pdf->__gamma_res);
}
// BETA
void beta_probability_density(__beta_pdf_t *_beta_pdf){
    assert(_beta_pdf->__lambda > 0);
    assert(_beta_pdf->__eta > 0);
    _beta_pdf->__beta_kemu = 1/B_fun(_beta_pdf->__lambda,_beta_pdf->__eta, _beta_pdf->__gamma_res, 0xFF)*pow(_beta_pdf->__beta_input, _beta_pdf->__lambda -1) * pow(1 - _beta_pdf->__beta_input, _beta_pdf->__eta - 1);
}
void beta_inverse_density(__beta_pdf_t *_beta_pdf){
    // not implemented
}
void beta_direct_density(__beta_pdf_t *_beta_pdf){
    __cwcn_type_t c_1 = 1/B_fun(_beta_pdf->__lambda, _beta_pdf->__eta, _beta_pdf->__gamma_res, 0xFF);
    __cwcn_type_t count=0x00;
    _beta_pdf->__is_nan=___CWCN_FALSE;
    for(unsigned short idx=0x00;idx<_beta_pdf->__direct_resolution;idx++){
        // __cwcn_type_t input = ((__cwcn_type_t)idx+0.5)/(__cwcn_type_t)_beta_pdf->__direct_resolution; // #FIXME??? why the +0.5
        _beta_pdf->__beta_input = ((__cwcn_type_t)idx)/(__cwcn_type_t)_beta_pdf->__direct_resolution;
        _beta_pdf->__direct_map[idx] = c_1*pow(_beta_pdf->__beta_input,_beta_pdf->__lambda-1)*pow(1-_beta_pdf->__beta_input, _beta_pdf->__eta-1);
        count += _beta_pdf->__direct_map[idx];
    }
    // fprintf(stdout,"DIRECT DENSITY BETA count: %f\n", count);
    //     fprintf(stdout,"DIRECT DENSITY BETA -1- index[%d] : %f\n", idx, _beta_pdf->__direct_map[idx]);
    //     fprintf(stdout,"DIRECT DENSITY BETA -2- index[%d] : %f - \n", idx, _beta_pdf->__direct_map[idx]);
    for(unsigned short idx=0x00;idx<_beta_pdf->__direct_resolution;idx++){
        _beta_pdf->__direct_map[idx] /= (__cwcn_type_t) count;
        if(_beta_pdf->__direct_map[idx]!=_beta_pdf->__direct_map[idx]){
            _beta_pdf->__is_nan=___CWCN_TRUE;
        }
    }
    // count=0x00;
    // for(unsigned short idx=0x00;idx<_beta_pdf->__direct_resolution;idx++){
    //     count += _beta_pdf->__direct_map[idx];
    // }
    // fprintf(stdout,"DIRECT DENSITY FINAL COUNTDOWN %f\n", count);
}
void beta_differential_entropy(__beta_pdf_t *_beta_pdf, _Bool _in_nats){
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
    // fprintf(stdout, ">> DIFFENTIAL ENTROPY: numeator: %f, denominator: %f, entropy: %f\n", numerator, denominator, _beta_pdf->__entropy);
}
void set_beta_lambda(__beta_pdf_t *_beta_pdf, __cwcn_type_t _lambda){
    _beta_pdf->__lambda=fabs(sin(0.5*3.141592*_lambda));
    _beta_pdf->__lambda=_beta_pdf->__lambda*_beta_pdf->__max_lambda;
    assert(_beta_pdf->__lambda<=_beta_pdf->__max_lambda);
    assert(_beta_pdf->__lambda>0);
}
void set_beta_eta(__beta_pdf_t *_beta_pdf, __cwcn_type_t _eta){
    _beta_pdf->__eta=fabs(sin(0.5*3.141592*_eta));
    _beta_pdf->__eta=_beta_pdf->__eta*_beta_pdf->__max_eta;
    assert(_beta_pdf->__eta<=_beta_pdf->__max_eta);
    assert(_beta_pdf->__eta>0);
}
void set_beta_input(__beta_pdf_t *_beta_pdf, __cwcn_type_t _input){
    assert(_input>=0-0.01);
    assert(_input<=1+0.01);
    _beta_pdf->__beta_input = _input+0.001;
    assert(_beta_pdf->__beta_input>0);
}
void set_num_tsane(__beta_pdf_t *_beta_pdf, unsigned int _n_tsane){
    _beta_pdf->__num_tsane=_n_tsane;
}
void set_direct_resolution(__beta_pdf_t *_beta_pdf, unsigned int _d_res){
    _beta_pdf->__direct_resolution=_d_res;
}

void beta_plot_direct_resolution(__beta_pdf_t *_beta_pdf){
    fprintf(stdout, "DIRECT:\n");
    for (int idx = 0; idx < _beta_pdf->__direct_resolution; idx++){
        fprintf(stdout, "x=%0.2f |", (__cwcn_type_t)idx/(__cwcn_type_t)_beta_pdf->__direct_resolution);
        fprintf(stdout, "y=%0.2f |", _beta_pdf->__direct_map[idx]);
        if(_beta_pdf->__direct_map[idx]<10000){
            for (int jdx = 0; jdx < _beta_pdf->__direct_map[idx]*2000/_beta_pdf->__direct_resolution; jdx++){
                fprintf(stdout, "%c", (char)254u);
            }
        }
        if(idx==4){
            fprintf(stdout, "\t\tENTROPY: %f", _beta_pdf->__entropy);
        } else if(idx==5){
            fprintf(stdout, "\t\t_lambda_: %3.2f", _beta_pdf->__lambda);
        } else if(idx==6){
            fprintf(stdout, "\t\t_eta_: %3.2f", _beta_pdf->__eta);
        }
        fprintf(stdout, "\n");
    }
}
void beta_plot_tsane(__beta_pdf_t *_beta_pdf){
    fprintf(stdout, "--> TSANE:\n");
    for (int idx = 0; idx < _beta_pdf->__num_tsane; idx++){
        fprintf(stdout, "x=%0.2f |", (__cwcn_type_t)idx/(__cwcn_type_t)_beta_pdf->__num_tsane);
        fprintf(stdout, "y=%0.2f |", _beta_pdf->__tsane_map[idx]);
        if(_beta_pdf->__tsane_map[idx]<10000){
            for (int jdx = 0; jdx < _beta_pdf->__tsane_map[idx]*50/_beta_pdf->__num_tsane; jdx++){
                fprintf(stdout, "%c", (char)254u);
            }
        }
        fprintf(stdout, "\n");
    }
}
void beta_plot_statistics(__beta_pdf_t *_beta_pdf){
    fprintf(stdout, "         (BETA) \t_ENTROPY_: %f, _MAX_KNOWN_ENTROPY_: %f, _lambda_: %3.2f, _eta_: %3.2f \n", _beta_pdf->__entropy, _beta_pdf->__max_known_entropy, _beta_pdf->__lambda, _beta_pdf->__eta);
}
void beta_print(void *_beta_pdf, int _print_lvel){
    assert(_print_lvel==1 || _print_lvel==2);
    if(_print_lvel==1){
        beta_plot_tsane(((__beta_pdf_t *)_beta_pdf));
        beta_plot_statistics(((__beta_pdf_t *)_beta_pdf));
    } else if(_print_lvel==2){
        beta_plot_direct_resolution(((__beta_pdf_t *)_beta_pdf));
        beta_plot_tsane(((__beta_pdf_t *)_beta_pdf));
        beta_plot_statistics(((__beta_pdf_t *)_beta_pdf));
    }
}
void beta_forward(void *_beta_pdf, __cwcn_type_t _beta_lambda, __cwcn_type_t _beta_eta){
    set_beta_lambda(_beta_pdf, _beta_lambda);
    set_beta_eta(_beta_pdf, _beta_eta);
    beta_GAMMA_RESOLUTION(_beta_pdf);
    // direct
    beta_direct_density(_beta_pdf);
    // beta_differential_entropy(_beta_pdf, true);
    beta_difference_entropy(_beta_pdf, 0xFF);
    beta_map_tsane(_beta_pdf);
}
__beta_pdf_t *_ipivye_beta_pdf(unsigned int _d_res, unsigned int _n_tsane){
    fprintf(stdout,">> _ipivye_beta_pdf\n");
    
	__beta_pdf_t * new_beta_pdf = malloc(sizeof(__beta_pdf_t));
    new_beta_pdf->__beta_lambda_tsinuu_index=0x00;
    new_beta_pdf->__beta_eta_tsinuu_index=0x00;
    new_beta_pdf->__lambda=0x00;
    new_beta_pdf->__eta=0x00;
    new_beta_pdf->__max_lambda=5.0;
    new_beta_pdf->__max_eta=5.0;
	new_beta_pdf->__direct_map = malloc(_d_res*sizeof(__cwcn_type_t));
	new_beta_pdf->__tsane_map = malloc(_n_tsane*sizeof(__cwcn_type_t));
    new_beta_pdf->__direct_resolution=_d_res;
    new_beta_pdf->__num_tsane=_n_tsane;
    new_beta_pdf->__beta_input=0x00;
    for(unsigned int idx=0x00;idx<_d_res;idx++){
        new_beta_pdf->__direct_map[idx]=0x00;
    }
    for(unsigned int idx=0x00;idx<_n_tsane;idx++){
        new_beta_pdf->__tsane_map[idx]=0x00;
    }
    new_beta_pdf->__entropy=0x00;
    new_beta_pdf->__max_known_entropy = -__cwcn_infinite;
    new_beta_pdf->__beta_kemu = 0x00;
	new_beta_pdf->__forward= &beta_forward;
	new_beta_pdf->__print= &beta_print;
    new_beta_pdf->__num_params=0x02;
    new_beta_pdf->__is_nan=___CWCN_FALSE;

    beta_GAMMA_RESOLUTION(new_beta_pdf);

	return new_beta_pdf;
}




/*
    CAUCHY
*/
void set_cauchy_a(__cauchy_pdf_t *_cauchy_pdf, __cwcn_type_t _cauchy_a){
    // fprintf(stdout, "CAUCHY a:::: %f\n",_cauchy_a);
    _cauchy_pdf->__cauchy_a=fabs(sin(0.5*3.141592*_cauchy_a));
    _cauchy_pdf->__cauchy_a=\
        (_cauchy_pdf->__cauchy_a)*\
        (_cauchy_pdf->__cauchy_a_max-_cauchy_pdf->__cauchy_a_min)+\
        _cauchy_pdf->__cauchy_a_min;
    assert(_cauchy_pdf->__cauchy_a>=_cauchy_pdf->__cauchy_a_min);
    assert(_cauchy_pdf->__cauchy_a<=_cauchy_pdf->__cauchy_a_max);
}
void set_cauchy_b(__cauchy_pdf_t *_cauchy_pdf, __cwcn_type_t _cauchy_b){
    // fprintf(stdout, "CAUCHY b:::: %f\n",_cauchy_b);
    _cauchy_pdf->__cauchy_b=fabs(sin(0.5*3.141592*_cauchy_b));
    _cauchy_pdf->__cauchy_b=_cauchy_pdf->__cauchy_b*_cauchy_pdf->__cauchy_b_max;
    assert(_cauchy_pdf->__cauchy_b>0x00);
    assert(_cauchy_pdf->__cauchy_b<=_cauchy_pdf->__cauchy_b_max);
}
void set_cauchy_input(__cauchy_pdf_t *_cauchy_pdf, __cwcn_type_t _input){
    // #FIXME input [0-1]
    assert(_input>=0-0.01);
    assert(_input<=1+0.01);
    _cauchy_pdf->__cauchy_input=\
        _input*\
        (_cauchy_pdf->__cauchy_input_max-_cauchy_pdf->__cauchy_input_min)+\
        _cauchy_pdf->__cauchy_input_min;
    assert(_cauchy_pdf->__cauchy_input>=_cauchy_pdf->__cauchy_input_min);
    assert(_cauchy_pdf->__cauchy_input<=_cauchy_pdf->__cauchy_input_max);
}
void cauchy_probability_density(__cauchy_pdf_t *_cauchy_pdf){
    assert(_cauchy_pdf->__cauchy_b > 0);
    _cauchy_pdf->__cauchy_kemu = \
        1.0 / 3.141592 / _cauchy_pdf->__cauchy_b / \
        (1 + pow((_cauchy_pdf->__cauchy_input - _cauchy_pdf->__cauchy_a),2) / \
        pow(_cauchy_pdf->__cauchy_b, 2));
    #ifdef ENTROPY_DEBUG
        fprintf(stdout, "probability densitiy for cauchy: %f \t a: %f, b:%f\tpow_1: %f\tpow_2: %f\n",_cauchy_pdf->__cauchy_kemu,_cauchy_pdf->__cauchy_a,_cauchy_pdf->__cauchy_b,pow((_cauchy_pdf->__cauchy_input - _cauchy_pdf->__cauchy_a),2),pow(_cauchy_pdf->__cauchy_b, 2));
    #endif
}
void cauchy_direct_density(__cauchy_pdf_t *_cauchy_pdf){
    __cwcn_type_t count=0x00;
    _cauchy_pdf->__is_nan=___CWCN_FALSE;
    for(unsigned short idx=0x00;idx<_cauchy_pdf->__direct_resolution;idx++){
        #ifdef ENTROPY_DEBUG
            fprintf(stdout,"-> input [%f]\t",(__cwcn_type_t)idx/(__cwcn_type_t)_cauchy_pdf->__direct_resolution);
        #endif
        set_cauchy_input(_cauchy_pdf, ((__cwcn_type_t)idx)/(__cwcn_type_t)_cauchy_pdf->__direct_resolution);
        cauchy_probability_density(_cauchy_pdf);
        _cauchy_pdf->__direct_map[idx] = _cauchy_pdf->__cauchy_kemu;
        count += _cauchy_pdf->__direct_map[idx];
    }
    // fprintf(stdout,"DIRECT DENSITY CAUCHY count: %f\n", count);
    // fprintf(stdout,"DIRECT DENSITY CAUCHY -1- index[%d]: %f\n", idx, _cauchy_pdf->__direct_map[idx]);
    // fprintf(stdout,"DIRECT DENSITY CAUCHY -2- index[%d]: %f -\n", idx, _cauchy_pdf->__direct_map[idx]);
    for(unsigned short idx=0x00;idx<_cauchy_pdf->__direct_resolution;idx++){
        _cauchy_pdf->__direct_map[idx] /= (__cwcn_type_t) count;
        if(_cauchy_pdf->__direct_map[idx]!=_cauchy_pdf->__direct_map[idx]){
            _cauchy_pdf->__is_nan=___CWCN_TRUE;
        }
    }
    // count=0x00;
    // for(unsigned short idx=0x00;idx<_cauchy_pdf->__direct_resolution;idx++){
    //     count += _cauchy_pdf->__direct_map[idx];
    // }
    // fprintf(stdout,"DIRECT DENSITY FINAL COUNTDOWN %f\n", count);
    
}
void cauchy_difference_entropy(__cauchy_pdf_t *_cauchy_pdf, _Bool _in_nats){
    if(_in_nats){ // in nats!
        _cauchy_pdf->__entropy = 0;
        for(unsigned int idx=0x00; idx < _cauchy_pdf->__direct_resolution;idx++){
            if(_cauchy_pdf->__direct_map[idx]>0.00001*_cauchy_pdf->__direct_resolution){ // avoid zero log
                _cauchy_pdf->__entropy += (-1)*_cauchy_pdf->__direct_map[idx]*log(_cauchy_pdf->__direct_map[idx]);
            }
        }
    } else{ // in bits
        _cauchy_pdf->__entropy = 0;
        for(unsigned int idx=0x00; idx < _cauchy_pdf->__direct_resolution;idx++){
            if(_cauchy_pdf->__direct_map[idx]>0.00001*_cauchy_pdf->__direct_resolution){ // avoid zero log
                _cauchy_pdf->__entropy += (-1)*_cauchy_pdf->__direct_map[idx]*log2(_cauchy_pdf->__direct_map[idx]);
            }
        }
    }
    if(_cauchy_pdf->__entropy>_cauchy_pdf->__max_known_entropy){
        _cauchy_pdf->__max_known_entropy=_cauchy_pdf->__entropy;
    }

}
void cauchy_map_tsane(__cauchy_pdf_t *_cauchy_pdf){
    // FIXME, this computational method can be better
    unsigned int ctx=0x00;
    for(unsigned int idx=0x00; idx<_cauchy_pdf->__num_tsane;idx++){
        _cauchy_pdf->__tsane_map[idx] = 0;
        for(unsigned int idy=0x00; idy<(unsigned int)_cauchy_pdf->__direct_resolution/_cauchy_pdf->__num_tsane;idy++){
            _cauchy_pdf->__tsane_map[idx] += _cauchy_pdf->__direct_map[ctx];
            #ifdef ENTROPY_DEBUG
                fprintf(stdout, ">>>> cauchy_map_tsane ctd %d, dir: %f\n", idx, _cauchy_pdf->__direct_map[ctx]);
            #endif
            ctx++;
        }
    }
}
void set_cauchy_num_tsane(__cauchy_pdf_t *_cauchy_pdf, unsigned int _n_tsane){
    _cauchy_pdf->__num_tsane=_n_tsane;
}
void set_cauchy_direct_resolution(__cauchy_pdf_t *_cauchy_pdf, unsigned int _d_res){
    _cauchy_pdf->__direct_resolution=_d_res;
}
void cauchy_plot_direct_resolution(__cauchy_pdf_t *_cauchy_pdf){
    fprintf(stdout, "DIRECT:\n");
    for (int idx = 0; idx < _cauchy_pdf->__direct_resolution; idx++){
        fprintf(stdout, "x=%0.2f |", (__cwcn_type_t)idx/(__cwcn_type_t)_cauchy_pdf->__direct_resolution);
        fprintf(stdout, "y=%0.2f |", _cauchy_pdf->__direct_map[idx]);
        if(_cauchy_pdf->__direct_map[idx]<10000){
            for (int jdx = 0; jdx < _cauchy_pdf->__direct_map[idx]*1000/_cauchy_pdf->__direct_resolution; jdx++){
                fprintf(stdout, "%c", (char)254u);
            }
        }
        if(idx==4){
            fprintf(stdout, "\t\tENTROPY: %f", _cauchy_pdf->__entropy);
        } else if(idx==5){
            fprintf(stdout, "\t\t_a_: %3.2f", _cauchy_pdf->__cauchy_a);
        } else if(idx==6){
            fprintf(stdout, "\t\t_b_: %3.2f", _cauchy_pdf->__cauchy_b);
        }
        fprintf(stdout, "\n");
    }
}
void cauchy_plot_tsane(__cauchy_pdf_t *_cauchy_pdf){
    fprintf(stdout, "--> TSANE:\n");
    for (int idx = 0; idx < _cauchy_pdf->__num_tsane; idx++){
        fprintf(stdout, "x=%0.2f |", (__cwcn_type_t)idx/(__cwcn_type_t)_cauchy_pdf->__num_tsane);
        fprintf(stdout, "y=%0.2f |", _cauchy_pdf->__tsane_map[idx]);
        if(_cauchy_pdf->__tsane_map[idx]<10000){
            for (int jdx = 0; jdx < _cauchy_pdf->__tsane_map[idx]*50/_cauchy_pdf->__num_tsane; jdx++){
                fprintf(stdout, "%c", (char)254u);
            }
        }
        fprintf(stdout, "\n");
    }
}
void cauchy_plot_statistics(__cauchy_pdf_t *_cauchy_pdf){
    fprintf(stdout, "         (CAUCHY)\t_ENTROPY_: %f, _MAX_KNOWN_ENTROPY_: %f, _cauchy_a_: %3.2f, _cauchy_b_: %3.2f \n", _cauchy_pdf->__entropy, _cauchy_pdf->__max_known_entropy, _cauchy_pdf->__cauchy_a, _cauchy_pdf->__cauchy_b);
}
void cauchy_print(void *_cauchy_pdf, int _print_lvel){
    printf("waka : %d\n",_print_lvel);
    assert(_print_lvel==1 || _print_lvel==2);
    if(_print_lvel==1){
        cauchy_plot_tsane(((__cauchy_pdf_t *)_cauchy_pdf));
        cauchy_plot_statistics(((__cauchy_pdf_t *)_cauchy_pdf));
    } else if(_print_lvel==2){
        cauchy_plot_direct_resolution(((__cauchy_pdf_t *)_cauchy_pdf));
        cauchy_plot_tsane(((__cauchy_pdf_t *)_cauchy_pdf));
        cauchy_plot_statistics(((__cauchy_pdf_t *)_cauchy_pdf));
    }
}
void cauchy_forward(void *_cauchy_pdf, __cwcn_type_t _cauchy_a, __cwcn_type_t _cauchy_b){
    set_cauchy_a(_cauchy_pdf, _cauchy_a);
    set_cauchy_b(_cauchy_pdf, _cauchy_b);
    cauchy_direct_density(_cauchy_pdf);
    // cauchy_differential_entropy(_cauchy_pdf, true);
    cauchy_difference_entropy(_cauchy_pdf, 0xFF);
    cauchy_map_tsane(_cauchy_pdf);    
}
__cauchy_pdf_t *_ipivye_cauchy_pdf(unsigned int _d_res, unsigned int _n_tsane){
    fprintf(stdout, ">> _ipivye_cauchy_pdf\n");
	__cauchy_pdf_t * new_cauchy_pdf = malloc(sizeof(__cauchy_pdf_t));
    new_cauchy_pdf->__direct_map = malloc(_d_res*sizeof(__cwcn_type_t));
	new_cauchy_pdf->__tsane_map = malloc(_n_tsane*sizeof(__cwcn_type_t));
    for(unsigned int idx=0x00;idx<_d_res;idx++){
        new_cauchy_pdf->__direct_map[idx]=0x00;
    }
    for(unsigned int idx=0x00;idx<_n_tsane;idx++){
        new_cauchy_pdf->__tsane_map[idx]=0x00;
    }
    new_cauchy_pdf->__direct_resolution=_d_res;
    new_cauchy_pdf->__num_tsane=_n_tsane;
    new_cauchy_pdf->__entropy=0x00;
    new_cauchy_pdf->__max_known_entropy = -__cwcn_infinite;
    new_cauchy_pdf->__cauchy_kemu = 0x00;
    new_cauchy_pdf->__cauchy_input = 0x00;
    new_cauchy_pdf->__cauchy_a = 0x00;
    new_cauchy_pdf->__cauchy_b = 0x00;
    new_cauchy_pdf->__cauchy_a_max = 100.0;
    new_cauchy_pdf->__cauchy_b_max = 150.0;
    new_cauchy_pdf->__cauchy_a_min = -100.0;
    new_cauchy_pdf->__cauchy_input_min = -100;
    new_cauchy_pdf->__cauchy_input_max = 100;
    new_cauchy_pdf->__cauchy_a_tsinuu_index=0x00;
    new_cauchy_pdf->__cauchy_b_tsinuu_index=0x00;
    new_cauchy_pdf->__forward=&cauchy_forward;
    new_cauchy_pdf->__print=&cauchy_print;
    new_cauchy_pdf->__num_params=0x02;
    new_cauchy_pdf->__is_nan=___CWCN_FALSE;

	return new_cauchy_pdf;
}


/*
    GENERALIZED NORMAL
*/
void set_normal_a(__normal_pdf_t *_normal_pdf, __cwcn_type_t _normal_a){
    // fprintf(stdout, "normal a:::: %f\n",_normal_a);
    _normal_pdf->__normal_a=fabs(sin(0.5*3.141592*_normal_a));
    _normal_pdf->__normal_a=\
        (_normal_pdf->__normal_a)*\
        (_normal_pdf->__normal_a_max);
    assert(_normal_pdf->__normal_a>0x00);
    assert(_normal_pdf->__normal_a<=_normal_pdf->__normal_a_max);
}
void set_normal_b(__normal_pdf_t *_normal_pdf, __cwcn_type_t _normal_b){
    // fprintf(stdout, "normal b:::: %f\n",_normal_b);
    _normal_pdf->__normal_b=fabs(sin(0.5*3.141592*_normal_b));
    _normal_pdf->__normal_b=_normal_pdf->__normal_b*_normal_pdf->__normal_b_max;
    assert(_normal_pdf->__normal_b>0x00);
    assert(_normal_pdf->__normal_b<=_normal_pdf->__normal_b_max);
}
void set_normal_mean(__normal_pdf_t *_normal_pdf, __cwcn_type_t _mean){
    // #FIXME mean [0-1]
    _mean=fabs(sin(0.5*3.141592*_mean));
    assert(_mean>=0.0);
    assert(_mean<=1.0);
    _normal_pdf->__normal_mean=(_mean)*\
        (_normal_pdf->__normal_input_max-_normal_pdf->__normal_input_min)+\
        _normal_pdf->__normal_input_min;
    assert(_normal_pdf->__normal_mean>=_normal_pdf->__normal_input_min);
    assert(_normal_pdf->__normal_mean<=_normal_pdf->__normal_input_max);
}
void set_normal_input(__normal_pdf_t *_normal_pdf, __cwcn_type_t _input){
    // #FIXME input [0-1]
    _input=fabs(sin(0.5*3.141592*_input));
    assert(_input>=0.0);
    assert(_input<=1.0);
    _normal_pdf->__normal_input=\
        (_input)*\
        (_normal_pdf->__normal_input_max-_normal_pdf->__normal_input_min)+\
        _normal_pdf->__normal_input_min;
    assert(_normal_pdf->__normal_input>=_normal_pdf->__normal_input_min);
    assert(_normal_pdf->__normal_input<=_normal_pdf->__normal_input_max);
}
void normal_probability_density(__normal_pdf_t *_normal_pdf){
    assert(_normal_pdf->__normal_a>0);
    assert(_normal_pdf->__normal_b>0);
    _normal_pdf->__normal_kemu = \
        _normal_pdf->__normal_b / \
        (2.0*_normal_pdf->__normal_a*GAMMA(1.0/_normal_pdf->__normal_b, _normal_pdf->__gamma_res))*\
        exp(-1.0*pow(\
        (fabs(_normal_pdf->__normal_input-_normal_pdf->__normal_mean)/_normal_pdf->__normal_a),\
        _normal_pdf->__normal_b));
    #ifdef ENTROPY_DEBUG
    fprintf(stdout, \
        "probability densitiy for normal: %f \t a: %f, b:%f\n",\
        _normal_pdf->__normal_kemu,\
        _normal_pdf->__normal_a,\
        _normal_pdf->__normal_b)
    #endif
}
void normal_direct_density(__normal_pdf_t *_normal_pdf){
    __cwcn_type_t count=0x00;
    _normal_pdf->__is_nan=___CWCN_FALSE;
    for(unsigned short idx=0x00;idx<_normal_pdf->__direct_resolution;idx++){
        #ifdef ENTROPY_DEBUG
        fprintf(stdout,"-> input [%f]\t",(__cwcn_type_t)idx/(__cwcn_type_t)_normal_pdf->__direct_resolution);
        #endif
        set_normal_input(_normal_pdf, ((__cwcn_type_t)idx)/(__cwcn_type_t)_normal_pdf->__direct_resolution);
        normal_probability_density(_normal_pdf);
        _normal_pdf->__direct_map[idx] = _normal_pdf->__normal_kemu;
        count += _normal_pdf->__direct_map[idx];
    }
    for(unsigned short idx=0x00;idx<_normal_pdf->__direct_resolution;idx++){
        _normal_pdf->__direct_map[idx] /= (__cwcn_type_t) count;
        if(_normal_pdf->__direct_map[idx]!=_normal_pdf->__direct_map[idx]){
            _normal_pdf->__is_nan=___CWCN_TRUE;
        }
    }
    
}
void normal_difference_entropy(__normal_pdf_t *_normal_pdf, _Bool _in_nats){
    if(_in_nats){ // in nats!
        _normal_pdf->__entropy = 0;
        for(unsigned int idx=0x00; idx < _normal_pdf->__direct_resolution;idx++){
            if(_normal_pdf->__direct_map[idx]>0.00001*_normal_pdf->__direct_resolution){ // avoid zero log
                _normal_pdf->__entropy += (-1)*_normal_pdf->__direct_map[idx]*log(_normal_pdf->__direct_map[idx]);
            }
        }
    } else{ // in bits
        _normal_pdf->__entropy = 0;
        for(unsigned int idx=0x00; idx < _normal_pdf->__direct_resolution;idx++){
            if(_normal_pdf->__direct_map[idx]>0.00001*_normal_pdf->__direct_resolution){ // avoid zero log
                _normal_pdf->__entropy += (-1)*_normal_pdf->__direct_map[idx]*log2(_normal_pdf->__direct_map[idx]);
            }
        }
    }
    if(_normal_pdf->__entropy>_normal_pdf->__max_known_entropy){
        _normal_pdf->__max_known_entropy=_normal_pdf->__entropy;
    }

}
void normal_map_tsane(__normal_pdf_t *_normal_pdf){
    // FIXME, this computational method can be better
    unsigned int ctx=0x00;
    for(unsigned int idx=0x00; idx<_normal_pdf->__num_tsane;idx++){
        _normal_pdf->__tsane_map[idx] = 0;
        for(unsigned int idy=0x00; idy<(unsigned int)_normal_pdf->__direct_resolution/_normal_pdf->__num_tsane;idy++){
            _normal_pdf->__tsane_map[idx] += _normal_pdf->__direct_map[ctx];
            #ifdef ENTROPY_DEBUG
                fprintf(stdout, ">>>> normal_map_tsane ctd %d, dir: %f\n", idx, _normal_pdf->__direct_map[ctx]);
            #endif
            ctx++;
        }
    }
}
void set_normal_num_tsane(__normal_pdf_t *_normal_pdf, unsigned int _n_tsane){
    _normal_pdf->__num_tsane=_n_tsane;
}
void set_normal_direct_resolution(__normal_pdf_t *_normal_pdf, unsigned int _d_res){
    _normal_pdf->__direct_resolution=_d_res;
}
void normal_plot_direct_resolution(__normal_pdf_t *_normal_pdf){
    fprintf(stdout, "DIRECT:\n");
    for (int idx = 0; idx < _normal_pdf->__direct_resolution; idx++){
        fprintf(stdout, "x=%0.2f |", (__cwcn_type_t)idx/(__cwcn_type_t)_normal_pdf->__direct_resolution);
        fprintf(stdout, "y=%0.2f |", _normal_pdf->__direct_map[idx]);
        if(_normal_pdf->__direct_map[idx]<10000){
            for (int jdx = 0; jdx < _normal_pdf->__direct_map[idx]*1000/_normal_pdf->__direct_resolution; jdx++){
                fprintf(stdout, "%c", (char)254u);
            }
        }
        if(idx==4){
            fprintf(stdout, "\t\tENTROPY: %f", _normal_pdf->__entropy);
        } else if(idx==5){
            fprintf(stdout, "\t\t_a_: %3.2f", _normal_pdf->__normal_a);
        } else if(idx==6){
            fprintf(stdout, "\t\t_b_: %3.2f", _normal_pdf->__normal_b);
        } else if(idx==8){
            fprintf(stdout, "\t\t_mean_: %3.2f", _normal_pdf->__normal_mean);
        }
        fprintf(stdout, "\n");
    }
}
void normal_plot_tsane(__normal_pdf_t *_normal_pdf){
    fprintf(stdout, "--> TSANE:\n");
    for (int idx = 0; idx < _normal_pdf->__num_tsane; idx++){
        fprintf(stdout, "x=%0.2f |", (__cwcn_type_t)idx/(__cwcn_type_t)_normal_pdf->__num_tsane);
        fprintf(stdout, "y=%0.2f |", _normal_pdf->__tsane_map[idx]);
        if(_normal_pdf->__tsane_map[idx]<10000){
            for (int jdx = 0; jdx < _normal_pdf->__tsane_map[idx]*50/_normal_pdf->__num_tsane; jdx++){
                fprintf(stdout, "%c", (char)254u);
            }
        }
        fprintf(stdout, "\n");
    }
}
void normal_plot_statistics(__normal_pdf_t *_normal_pdf){
    fprintf(stdout, "         \
        (normal)\t_ENTROPY_: %f, _MAX_KNOWN_ENTROPY_: %f, _a_: %3.2f, _b_: %3.2f, _mean_: %3.2f \n",\
        _normal_pdf->__entropy, \
        _normal_pdf->__max_known_entropy, \
        _normal_pdf->__normal_a, \
        _normal_pdf->__normal_b, \
        _normal_pdf->__normal_mean);
}
void normal_print(void *_normal_pdf, int _print_lvel){
    assert(_print_lvel==1 || _print_lvel==2);
    if(_print_lvel==1){
        normal_plot_tsane(((__normal_pdf_t *)_normal_pdf));
        normal_plot_statistics(((__normal_pdf_t *)_normal_pdf));
    } else if(_print_lvel==2){
        normal_plot_direct_resolution(((__normal_pdf_t *)_normal_pdf));
        normal_plot_tsane(((__normal_pdf_t *)_normal_pdf));
        normal_plot_statistics(((__normal_pdf_t *)_normal_pdf));
    }
}
void normal_forward(void *_normal_pdf, __cwcn_type_t _normal_a, __cwcn_type_t _normal_b, __cwcn_type_t _normal_mean){
    set_normal_a(_normal_pdf, _normal_a);
    set_normal_b(_normal_pdf, _normal_b);
    set_normal_mean(_normal_pdf, _normal_mean);
    normal_direct_density(_normal_pdf);
    // normal_differential_entropy(_normal_pdf, true);
    normal_difference_entropy(_normal_pdf, 0xFF);
    normal_map_tsane(_normal_pdf);
}
void normal_GAMMA_RESOLUTION(__normal_pdf_t *_normal_pdf){
    _normal_pdf->__gamma_res = (__cwcn_type_t) (_normal_pdf->__normal_a_max + _normal_pdf->__normal_b_max);
    // fprintf(stdout, ">> _normal_pdf->__gamma_res: %f\n", _normal_pdf->__gamma_res);
}
__normal_pdf_t *_ipivye_normal_pdf(unsigned int _d_res, unsigned int _n_tsane){
    fprintf(stdout, ">> _ipivye_normal_pdf\n");
	__normal_pdf_t * new_normal_pdf = malloc(sizeof(__normal_pdf_t));
    new_normal_pdf->__direct_map = malloc(_d_res*sizeof(__cwcn_type_t));
	new_normal_pdf->__tsane_map = malloc(_n_tsane*sizeof(__cwcn_type_t));
    for(unsigned int idx=0x00;idx<_d_res;idx++){
        new_normal_pdf->__direct_map[idx]=0x00;
    }
    for(unsigned int idx=0x00;idx<_n_tsane;idx++){
        new_normal_pdf->__tsane_map[idx]=0x00;
    }
    new_normal_pdf->__direct_resolution=_d_res;
    new_normal_pdf->__num_tsane=_n_tsane;
    new_normal_pdf->__entropy=0x00;
    new_normal_pdf->__max_known_entropy = -__cwcn_infinite;
    new_normal_pdf->__normal_kemu = 0x00;
    new_normal_pdf->__normal_input = 0x00;
    new_normal_pdf->__normal_mean = 0x00;
    new_normal_pdf->__normal_a = 0x00;
    new_normal_pdf->__normal_b = 0x00;
    new_normal_pdf->__normal_a_max = 100.0;
    new_normal_pdf->__normal_b_max = 150.0;
    new_normal_pdf->__normal_input_min = -100;
    new_normal_pdf->__normal_input_max = 100;
    new_normal_pdf->__normal_a_tsinuu_index=0x00;
    new_normal_pdf->__normal_b_tsinuu_index=0x00;
    new_normal_pdf->__forward=&normal_forward;
    new_normal_pdf->__print=&normal_print;
    new_normal_pdf->__num_params=0x03;
    new_normal_pdf->__is_nan=___CWCN_FALSE;

    normal_GAMMA_RESOLUTION(new_normal_pdf);

	return new_normal_pdf;
}



// void inverse_probability_density_cauchy(__cwcn_type_t cauchy_a)
// __cwcn_type_t differential_entropy_cauchy(__cwcn_type_t input){return 0;}
// // CHI
// __cwcn_type_t chi_n(__cwcn_type_t input){return input;}
// __cwcn_type_t chi_sigma(__cwcn_type_t input){return input;}
// __cwcn_type_t probability_density_chi(__cwcn_type_t input){
//     if(inpur < 0){return 0;}
//     return 2 * pow(chi_n/2, chi_n/2) /pow(chi_sigma,chi_n) * exp(-1 * chi_N / 2 / pow(chi_sigma, 2)) * pow(input,2);
// }
// __cwcn_type_t differential_entropy_chi(__cwcn_type_t input){return 0;}

// __cwcn_type_t chi2_n(__cwcn_type_t input){return input;}
// __cwcn_type_t chi2_GAMMA(__cwcn_type_t input){return input;}
// __cwcn_type_t chi2_sigma(__cwcn_type_t input){return input;}
// __cwcn_type_t probability_density_chi2(__cwcn_type_t input){
//     if(inpur < 0){return 0;}
//     assert(chi2_n >= 0);
//     return 1 / pow(2, chi2_n/2) / chi2_GAMMA(chi2_n/2) * pow(input, chi2_n/2 -1) * exp(-1 * input/2);
// }
// __cwcn_type_t differential_entropy_chi2(__cwcn_type_t input){return 0;}

// // DIRAC DELTA
// __cwcn_type_t probability_density_dirac_delta(__cwcn_type_t input){return input;}
// __cwcn_type_t differential_entropy_dirac_delta(__cwcn_type_t input){return 0;}

// // Exponential
// __cwcn_type_t probability_density_exponential(__cwcn_type_t input){
//     if(inpur < 0){return 0;}
//     assert(lambda > 0);
//     exponential_lambda * exp(-1 * exponential_lambda * input);
// }

// // F
// __cwcn_type_t f_nu(__cwcn_type_t input){return input;}
// __cwcn_type_t f_omega(__cwcn_type_t input){return input;}
// __cwcn_type_t f_B(__cwcn_type_t input_nu, __cwcn_type_t input_omega){return input_nu + input_omega;}
// __cwcn_type_t probability_density_f(__cwcn_type_t input){
//     if(input < 0){return 0;}
//     assert(f_nu > 0);
//     assert(f_omega > 0);
//     return pow(f_nu, f_nu/2) * pow(f_omega, f_omega/2) / f_B(f_nu/2, f_omega) * pow(input, f_nu/2 - 1) / pow((f_omega + f_nu * input), (f_nu + f_omega)/2);
// }
// __cwcn_type_t differential_entropy_f(__cwcn_type_t input){return 0;}

// // GAMMA
// __cwcn_type_t gamma_eta(__cwcn_type_t input){return input;}
// __cwcn_type_t gamma_lambda(__cwcn_type_t input){return input;}
// __cwcn_type_t gamma_GAMMA(__cwcn_type_t input){return input;}
// __cwcn_type_t probability_density_gamma(__cwcn_type_t input){
//     if(inpur < 0){return 0;}
//     assert(gamma_lambda > 0);
//     assert(gamma_eta > 0);
//     return pow(gamma_lambda, gamma_eta) / gamma_GAMMA(gamma_eta) * pow(input, gamma_eta - 1) * pow(input, gamma_eta - 1) * exp(-1 * gamma_lambda * input);
// }
// __cwcn_type_t differential_entropy_gamma(__cwcn_type_t input){return 0;}

// // Generalized Beta
// __cwcn_type_t betaG_a(__cwcn_type_t input){return input;}
// __cwcn_type_t betaG_b(__cwcn_type_t input){return input;}
// __cwcn_type_t betaG_eta(__cwcn_type_t input){return input;}
// __cwcn_type_t betaG_lambda(__cwcn_type_t input){return input;}
// __cwcn_type_t (__cwcn_type_t input){return input;}
// __cwcn_type_t probability_density_betaG(__cwcn_type_t input){
//     if(input < 0 or input > 1){return 0;}
//     assert(betaG_lambda > 0);
//     assert(betaG_eta > 0);
//     assert(betaG_a >= 0);
//     return 1 / (betaG_b - betaG_a) * (betaG_eta+betaG_lambda) / (betaG_eta) / (betaG_lambda) * pow((input - betaG_a)/(bataG_b - input), betaG_lambda -1) * pow((betaG_b - input)/(betaG_b - betaG_a), betaG_eta - 1);
// }
// __cwcn_type_t differential_entropy_betaG(__cwcn_type_t input){return 0;}

// // Generalized Normal
// __cwcn_type_t Gnormal_alpha(__cwcn_type_t input){return input;}
// __cwcn_type_t Gnormal_beta(__cwcn_type_t input){return input;}
// __cwcn_type_t Gnormal_mu(__cwcn_type_t input){return input;}
// __cwcn_type_t Gnormal_GAMMA(__cwcn_type_t input){return input;}
// __cwcn_type_t probability_density_Gnormal(__cwcn_type_t input){
//     assert(Gnormal_alpha > 0);
//     assert(Gnormal_beta > 0);
//     return Gnormal_beta / 2 / Gnormal_alpha / Gnormal_GAMMA(1(Gnormal_beta)) * exp(-1 * pow(abs(input - Gnormal_mu)/Gnormal_alpha, Gnormal_beta))
// }
// __cwcn_type_t differential_entropy_(__cwcn_type_t input){return 0;}

// // Kumaraswamy
// __cwcn_type_t kumaraswamy_a(__cwcn_type_t input){return input;}
// __cwcn_type_t kumaraswamy_b(__cwcn_type_t input){return input;}
// __cwcn_type_t probability_density_kumaraswamy(__cwcn_type_t input){
//     if(inpur < 0){return 0;}
//     if(inpur > 1){return 0;}
//     return kumaraswamy_a * kumaraswamy_b * pow(input, kumaraswamy_a - 1) * pow(1 - pow(input, kumaraswamy_a), kumaraswamy_b - 1)
// }
// __cwcn_type_t differential_entropy_kumaraswamy(__cwcn_type_t input){return 0;}


// // __cwcn_type_t (__cwcn_type_t input){return input;}
// // __cwcn_type_t (__cwcn_type_t input){return input;}
// // __cwcn_type_t (__cwcn_type_t input){return input;}
// // __cwcn_type_t (__cwcn_type_t input){return input;}
// // __cwcn_type_t probability_density_(__cwcn_type_t input){
// //     if(inpur < 0){return 0;}
// // }
// // __cwcn_type_t differential_entropy_(__cwcn_type_t input){return 0;}
// // __cwcn_type_t differential_entropy_(__cwcn_type_t input){return 0;}
// // __cwcn_type_t (__cwcn_type_t input){return input;}
// // __cwcn_type_t (__cwcn_type_t input){return input;}
// // __cwcn_type_t (__cwcn_type_t input){return input;}
// // __cwcn_type_t (__cwcn_type_t input){return input;}
// // __cwcn_type_t probability_density_(__cwcn_type_t input){
// //     if(inpur < 0){return 0;}
// // }
// // __cwcn_type_t differential_entropy_(__cwcn_type_t input){return 0;}
// // __cwcn_type_t differential_entropy_(__cwcn_type_t input){return 0;}
// // __cwcn_type_t (__cwcn_type_t input){return input;}
// // __cwcn_type_t (__cwcn_type_t input){return input;}
// // __cwcn_type_t (__cwcn_type_t input){return input;}
// // __cwcn_type_t (__cwcn_type_t input){return input;}
// // __cwcn_type_t probability_density_(__cwcn_type_t input){
// //     if(inpur < 0){return 0;}
// // }
// // __cwcn_type_t differential_entropy_(__cwcn_type_t input){return 0;}
// // __cwcn_type_t differential_entropy_(__cwcn_type_t input){return 0;}
// // __cwcn_type_t (__cwcn_type_t input){return input;}
// // __cwcn_type_t (__cwcn_type_t input){return input;}
// // __cwcn_type_t (__cwcn_type_t input){return input;}
// // __cwcn_type_t (__cwcn_type_t input){return input;}
// // __cwcn_type_t probability_density_(__cwcn_type_t input){
// //     if(inpur < 0){return 0;}
// // }
// // __cwcn_type_t differential_entropy_(__cwcn_type_t input){return 0;}


/*
*/
void entropycosa_plot_tsane(void *_ec){
    fprintf(stdout, "--> ENTROPYCOSA COMBINED TSANE:\n");
    for (int idx = 0; idx<((__entropycosa_t *)_ec)->__num_tsane; idx++){
        fprintf(stdout, "x=%0.2f |", (__cwcn_type_t)idx/(__cwcn_type_t)((__entropycosa_t *)_ec)->__cosa_size);
        fprintf(stdout, "y=%0.2f |", ((__entropycosa_t *)_ec)->__tsane[idx]);
        if(((__entropycosa_t *)_ec)->__tsane[idx]<10000){
            for (int jdx = 0; jdx < ((__entropycosa_t *)_ec)->__tsane[idx]*50/((__entropycosa_t *)_ec)->__cosa_size; jdx++){
                fprintf(stdout, "%c", (char)254u);
            }
        }
        fprintf(stdout, "\n");
    }
}
void entropycosa_plot_statistics(void *_ec){
    beta_plot_statistics(((__beta_pdf_t *)((__entropycosa_t *)_ec)->__cosa[0]));
    cauchy_plot_statistics(((__cauchy_pdf_t *)((__entropycosa_t *)_ec)->__cosa[1]));
    normal_plot_statistics(((__normal_pdf_t *)((__entropycosa_t *)_ec)->__cosa[2]));
}
void entropycosa_tsane(void *_ec){
    __cwcn_type_t c_sum=0x00;
    for(unsigned int idx_tsane=0x00;idx_tsane<((__entropycosa_t *)_ec)->__num_tsane;idx_tsane++){
		((__entropycosa_t *)_ec)->__tsane[idx_tsane]=0x00;
		((__entropycosa_t *)_ec)->__tsane[idx_tsane]+=((__beta_pdf_t*)((__entropycosa_t *)_ec)->__cosa[0])->__tsane_map[idx_tsane];
        c_sum+=((__entropycosa_t *)_ec)->__tsane[idx_tsane];
		((__entropycosa_t *)_ec)->__tsane[idx_tsane]+=((__cauchy_pdf_t*)((__entropycosa_t *)_ec)->__cosa[1])->__tsane_map[idx_tsane];
        c_sum+=((__entropycosa_t *)_ec)->__tsane[idx_tsane];
        ((__entropycosa_t *)_ec)->__tsane[idx_tsane]+=((__cauchy_pdf_t*)((__entropycosa_t *)_ec)->__cosa[2])->__tsane_map[idx_tsane];
        c_sum+=((__entropycosa_t *)_ec)->__tsane[idx_tsane];
	}
    for(unsigned int idx_tsane=0x00;idx_tsane<((__entropycosa_t *)_ec)->__num_tsane;idx_tsane++){
        ((__entropycosa_t *)_ec)->__tsane[idx_tsane]/=(__cwcn_type_t)((__entropycosa_t *)_ec)->__cosa_size;
    }
}
void entropycosa_print(void *_ec, int _print_lvel){
    assert(_print_lvel==0 || _print_lvel==1 || _print_lvel==2);
    fprintf(stdout,">> > ... ENTROPYCOSA:\n");
    if(_print_lvel==0){
        entropycosa_plot_tsane(_ec);
        entropycosa_plot_statistics(_ec);
    } else{
        fprintf(stdout,">> > ... printing BETA:\n");
        ((__beta_pdf_t *)((__entropycosa_t *)_ec)->__cosa[0])->__print(((__beta_pdf_t *)((__entropycosa_t *)_ec)->__cosa[0]),_print_lvel);
        fprintf(stdout,">> > ... printing CAUCHY:\n");
        ((__cauchy_pdf_t *)((__entropycosa_t *)_ec)->__cosa[1])->__print(((__cauchy_pdf_t *)((__entropycosa_t *)_ec)->__cosa[1]),_print_lvel);
        fprintf(stdout,">> > ... printing NORMAL:\n");
        ((__normal_pdf_t *)((__entropycosa_t *)_ec)->__cosa[2])->__print(((__normal_pdf_t *)((__entropycosa_t *)_ec)->__cosa[2]),_print_lvel);
        fprintf(stdout,">> > ... printing ENTROPYCOSA TSNAE:\n");
        entropycosa_plot_tsane(_ec);
    }
}
void entropycosa_forward(void *_ec, __cwcn_type_t *_param_vect){
    __cwcn_type_t _ec_delta;
    __cwcn_type_t *c_param=malloc(0x0F*sizeof(__cwcn_type_t)); // #FIXME might overflow
    _ec_delta=0x00;
    while(0x01){ // beta
        c_param[0]=_param_vect[0]+_ec_delta;
        c_param[1]=_param_vect[1]+_ec_delta;
        ((__beta_pdf_t *)((__entropycosa_t *)_ec)->__cosa[0])->__forward(\
            ((__entropycosa_t *)_ec)->__cosa[0], \
                c_param[0], \
                c_param[1]);
        if(!((__beta_pdf_t *)((__entropycosa_t *)_ec)->__cosa[0])->__is_nan){break;}
        _ec_delta+=0.05;
    }
    _ec_delta=0x00;
    while(0x01){ // cauchy
        c_param[2]=_param_vect[2]+_ec_delta;
        c_param[3]=_param_vect[3]+_ec_delta;
	    ((__cauchy_pdf_t *)((__entropycosa_t *)_ec)->__cosa[1])->__forward(
            ((__entropycosa_t *)_ec)->__cosa[1], \
                c_param[2], \
                c_param[3]);
        if(!((__cauchy_pdf_t *)((__entropycosa_t *)_ec)->__cosa[1])->__is_nan){break;}
        _ec_delta+=0.01;
    }
    _ec_delta=0x00;
    while(0x01){ // normal
        c_param[4]=_param_vect[4]+_ec_delta;
        c_param[5]=_param_vect[5]+_ec_delta;
        c_param[6]=_param_vect[6]+_ec_delta;
	    ((__normal_pdf_t *)((__entropycosa_t *)_ec)->__cosa[2])->__forward(
            ((__entropycosa_t *)_ec)->__cosa[2], \
                c_param[4], \
                c_param[5], \
                c_param[6]);
        if(!((__normal_pdf_t *)((__entropycosa_t *)_ec)->__cosa[2])->__is_nan){break;}
        _ec_delta+=0.01;
    }
    ((__entropycosa_t *)_ec)->__entropy=\
        (\
        ((__beta_pdf_t *)((__entropycosa_t *)_ec)->__cosa[0])->__entropy+\
        ((__cauchy_pdf_t *)((__entropycosa_t *)_ec)->__cosa[1])->__entropy+\
        ((__normal_pdf_t *)((__entropycosa_t *)_ec)->__cosa[2])->__entropy\
        )/(__cwcn_type_t)((__entropycosa_t *)_ec)->__cosa_size;
    entropycosa_tsane(_ec);
    free(c_param);
    c_param=NULL;
}
__entropycosa_t *entropycosa_fabric(unsigned int _d_res, unsigned int _n_tsane){
    __entropycosa_t *new_ec = malloc(sizeof(__entropycosa_t));
    new_ec->__cosa_size=BUGGER_ENTROPYCOSA_SIZE;
    new_ec->__num_tsane=_n_tsane;
    new_ec->__cosa=malloc(new_ec->__cosa_size*sizeof(void));
    new_ec->__cosa[0]=malloc(sizeof(__beta_pdf_t));
    new_ec->__cosa[1]=malloc(sizeof(__cauchy_pdf_t));
    new_ec->__cosa[2]=malloc(sizeof(__normal_pdf_t));
    new_ec->__cosa[0]=_ipivye_beta_pdf(_d_res,_n_tsane);
    new_ec->__cosa[1]=_ipivye_cauchy_pdf(_d_res,_n_tsane);
    new_ec->__cosa[2]=_ipivye_normal_pdf(_d_res,_n_tsane);
    new_ec->__total_cosa_params=0x00;
    new_ec->__total_cosa_params+=((__beta_pdf_t *)new_ec->__cosa[0])->__num_params;
    new_ec->__total_cosa_params+=((__cauchy_pdf_t *)new_ec->__cosa[1])->__num_params;
    new_ec->__total_cosa_params+=((__normal_pdf_t *)new_ec->__cosa[2])->__num_params;
    new_ec->__forward=&entropycosa_forward;
    new_ec->__print=&entropycosa_print;
    new_ec->__tsane=malloc(_n_tsane*sizeof(__cwcn_type_t));
    new_ec->__entropy=0x00;
    return new_ec;
}
void entropycosa_destroy(__entropycosa_t *_ec){
    free(((__normal_pdf_t *)_ec->__cosa[2])->__direct_map);
    free(((__normal_pdf_t *)_ec->__cosa[2])->__tsane_map);
    free(((__normal_pdf_t *)_ec->__cosa[2]));
    free(((__cauchy_pdf_t *)_ec->__cosa[1])->__direct_map);
    free(((__cauchy_pdf_t *)_ec->__cosa[1])->__tsane_map);
    free(((__cauchy_pdf_t *)_ec->__cosa[1]));
    free(((__beta_pdf_t *)_ec->__cosa[0])->__direct_map);
    free(((__beta_pdf_t *)_ec->__cosa[0])->__tsane_map);
    free(((__beta_pdf_t *)_ec->__cosa[0]));
    free(_ec->__tsane);
    free(_ec->__cosa);
    free(_ec);
}