#include "cwcn_duuruva_nebajke.h"

void set_duuruvaboleanparametrics(
        __duuruva_t *_duuruva,
        ___cwcn_bool_t _pardon_maxmin,
        ___cwcn_bool_t _pardon_dist,
        ___cwcn_bool_t _pardon_count){
    _duuruva->__dvbp->__pardon_maxmin=_pardon_maxmin;
    _duuruva->__dvbp->__pardon_dist=_pardon_dist;
    _duuruva->__dvbp->__pardon_count=_pardon_count;
}
void reset_duuruva(__duuruva_t *_duuruva){
    for(unsigned int idx=0x00;idx<_duuruva->__num_base_duuruva;idx++){
        _duuruva->__value[idx]=0x00;
        _duuruva->__dv_dist[idx].__max=0x00;
        _duuruva->__dv_dist[idx].__count=0x00; // is not so much count as is the back span of the load
        _duuruva->__dv_dist[idx].__min=0x00;
        _duuruva->__dv_dist[idx].__std=0x00;
        _duuruva->__dv_dist[idx].__mean=0x00;
        _duuruva->__dv_dist[idx].__M2=0x00;
        _duuruva->__dv_dist[idx].__M3=0x00;
        _duuruva->__dv_dist[idx].__M4=0x00;
        _duuruva->__dv_dist[idx].__kurtosis=0x00;
        _duuruva->__dv_dist[idx].__skewness=0x00;
    }
}

void dist_duuruva(__duuruva_t *_duuruva){ // #FIXME might be util to check for __is_reset 
    /* ASSUMES _duuruva->__value has been computed.  
        ___duuruva_bolean_parametrics {
            __pardon_maxmin
            __pardon_dist
            __pardon_count
        }
        __dv_dist_coord_t {
            __max
            __min
            __std
            __M2
            __M3
            __M4
            __kurtosis
            __skewness
            __mean
            __count
        }
    */
    for(unsigned int idx=0x00;idx<_duuruva->__num_base_duuruva;idx++){
        if(!_duuruva->__dvbp->__pardon_count){
            _duuruva->__dv_dist[idx].__count ++;
        } if(!_duuruva->__dvbp->__pardon_maxmin){
            _duuruva->__dv_dist[idx].__max=max(_duuruva->__dv_dist[idx].__max, _duuruva->__value[idx]);
            _duuruva->__dv_dist[idx].__min=min(_duuruva->__dv_dist[idx].__min, _duuruva->__value[idx]);
        } if(!_duuruva->__dvbp->__pardon_dist && _duuruva->__dv_dist[idx].__count>1){
            /*
                https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance#cite_note-11
            */
            __cwcn_type_t _n = _duuruva->__dv_dist[idx].__count;
            __cwcn_type_t _delta = _duuruva->__value[idx] - _duuruva->__dv_dist[idx].__mean;
            __cwcn_type_t _delta_n = _delta/_n;
            __cwcn_type_t _delta_n2 = _delta_n*_delta_n;
            __cwcn_type_t _term1 = _delta*_delta_n*(_n-1);
            _duuruva->__dv_dist[idx].__mean += _delta_n;
            _duuruva->__dv_dist[idx].__M4 += _term1*_delta_n2*(_n*_n-3*_n+3)+6*_delta_n2*_duuruva->__dv_dist[idx].__M2-4*_delta_n*_duuruva->__dv_dist[idx].__M3;
            _duuruva->__dv_dist[idx].__M3 += _term1*_delta_n*(_n-2)-3*_delta_n*_duuruva->__dv_dist[idx].__M2;
            _duuruva->__dv_dist[idx].__M2 += _term1;
            _duuruva->__dv_dist[idx].__std = _duuruva->__dv_dist[idx].__M2/(_n-1);
            _duuruva->__dv_dist[idx].__kurtosis = (_n*_duuruva->__dv_dist[idx].__M4)/(_duuruva->__dv_dist[idx].__M2*_duuruva->__dv_dist[idx].__M2)-3;
            _duuruva->__dv_dist[idx].__skewness = sqrt(_n)*_duuruva->__dv_dist[idx].__M3/(pow(_duuruva->__dv_dist[idx].__M2,3)*sqrt(_duuruva->__dv_dist[idx].__M2)); // #FIXME check if is right
        }
    }
}

/*

*/
__duuruva_t *duuruva_fabric(unsigned int _num_base_duuruva){
    __duuruva_t* new_duuruva=malloc(sizeof(__duuruva_t));
    new_duuruva->__num_base_duuruva=_num_base_duuruva;
    new_duuruva->__duuruva_vector_size=_num_base_duuruva*BUGGER_SIZE_DUURUVA;
    new_duuruva->__dv_dist=malloc(_num_base_duuruva*sizeof(__duuruva_dist_tensor_t));
    // for(unsigned int idx=0x00;idx<_num_base_duuruva;idx++){
    //     new_duuruva->__dv_dist[idx]=malloc(sizeof(__duuruva_dist_tensor_t));
    // }
    new_duuruva->__value=malloc(_num_base_duuruva*sizeof(__cwcn_type_t));
    new_duuruva->__dvbp=malloc(sizeof(__duuruva_bolean_parametrics_t));
    set_duuruvaboleanparametrics(new_duuruva,0x00,0x00,0x00);
    reset_duuruva(new_duuruva);
    return new_duuruva;
}

void print_duuruva(__duuruva_t *_duuruva){
    for(unsigned int idx=0x00;idx<_duuruva->__num_base_duuruva;idx++){
        fprintf(stdout, "DUURUVA [ %d ]\n",idx);
        fprintf(stdout, "DUURUVA [ %d ] __value: %f \n",idx,_duuruva->__value[idx]);
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __count: %f\n",idx,_duuruva->__dv_dist[idx].__count);
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __max: %f\n",idx,_duuruva->__dv_dist[idx].__max);
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __min: %f\n",idx,_duuruva->__dv_dist[idx].__min);
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __std: %f\n",idx,_duuruva->__dv_dist[idx].__std);
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __mean: %f\n",idx,_duuruva->__dv_dist[idx].__mean);
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __M2: %f\n",idx,_duuruva->__dv_dist[idx].__M2);
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __M3: %f\n",idx,_duuruva->__dv_dist[idx].__M3);
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __M4: %f\n",idx,_duuruva->__dv_dist[idx].__M4);
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __kurtosis: %f\n",idx,_duuruva->__dv_dist[idx].__kurtosis);
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __skewness: %f\n",idx,_duuruva->__dv_dist[idx].__skewness);
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n\n");
}

void read_duuruva_vector(__duuruva_t *_duuruva, __cwcn_type_t *__dv_vect){
    unsigned int ctx_check=0x00;
    for(unsigned int idx=0x00;idx<_duuruva->__num_base_duuruva;idx++){
        if(!isnan(_duuruva->__value[idx])){__dv_vect[idx+0x00]=_duuruva->__value[idx];}else{__dv_vect[idx+0x00]=0x00;}
        if(!isnan(_duuruva->__dv_dist[idx].__count)){__dv_vect[idx+0x01]=_duuruva->__dv_dist[idx].__count;}else{__dv_vect[idx+0x01]=0x00;}
        if(!isnan(_duuruva->__dv_dist[idx].__max)){__dv_vect[idx+0x02]=_duuruva->__dv_dist[idx].__max;}else{__dv_vect[idx+0x02]=0x00;}
        if(!isnan(_duuruva->__dv_dist[idx].__min)){__dv_vect[idx+0x03]=_duuruva->__dv_dist[idx].__min;}else{__dv_vect[idx+0x03]=0x00;}
        if(!isnan(_duuruva->__dv_dist[idx].__std)){__dv_vect[idx+0x04]=_duuruva->__dv_dist[idx].__std;}else{__dv_vect[idx+0x04]=0x00;}
        if(!isnan(_duuruva->__dv_dist[idx].__mean)){__dv_vect[idx+0x05]=_duuruva->__dv_dist[idx].__mean;}else{__dv_vect[idx+0x05]=0x00;}
        if(!isnan(_duuruva->__dv_dist[idx].__M2)){__dv_vect[idx+0x06]=_duuruva->__dv_dist[idx].__M2;}else{__dv_vect[idx+0x06]=0x00;}
        if(!isnan(_duuruva->__dv_dist[idx].__M3)){__dv_vect[idx+0x07]=_duuruva->__dv_dist[idx].__M3;}else{__dv_vect[idx+0x07]=0x00;}
        if(!isnan(_duuruva->__dv_dist[idx].__M4)){__dv_vect[idx+0x09]=_duuruva->__dv_dist[idx].__M4;}else{__dv_vect[idx+0x09]=0x00;}
        if(!isnan(_duuruva->__dv_dist[idx].__kurtosis)){__dv_vect[idx+0x0A]=_duuruva->__dv_dist[idx].__kurtosis;}else{__dv_vect[idx+0x0A]=0x00;}
        if(!isnan(_duuruva->__dv_dist[idx].__skewness)){__dv_vect[idx+0x0B]=_duuruva->__dv_dist[idx].__skewness;}else{__dv_vect[idx+0x0B]=0x00;}
        ctx_check++;
    }
    assert(ctx_check==_duuruva->__duuruva_vector_size);
}

void set_duuruva_value(__duuruva_t *_duuruva, __cwcn_type_t *_set_vector){
    for(unsigned int idx=0x00;idx<_duuruva->__num_base_duuruva;idx++){
        _duuruva->__value[idx]=_set_vector[idx];
    }
}

void duuruva_destroy(__duuruva_t *_duuruva){
    // for(unsigned int idx=0x00;idx<_duuruva->__num_base_duuruva;idx++){
    // }
    free(_duuruva->__dv_dist);
    free(_duuruva->__value);
    free(_duuruva->__dvbp);
    free(_duuruva);
        
}