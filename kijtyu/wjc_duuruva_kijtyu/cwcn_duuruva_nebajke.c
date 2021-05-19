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
        _duuruva->__dv_dist[idx].__max=-__cwcn_infinite;
        _duuruva->__dv_dist[idx].__count=0x00; // is not so much count as is the back span of the load
        _duuruva->__dv_dist[idx].__min=__cwcn_infinite;
        _duuruva->__dv_dist[idx].__std=0x00;
        _duuruva->__dv_dist[idx].__mean=0x00;
        _duuruva->__dv_dist[idx].__M2=0x00;
        _duuruva->__dv_dist[idx].__M3=0x00;
        _duuruva->__dv_dist[idx].__M4=0x00;
        _duuruva->__dv_dist[idx].__kurtosis=0x00;
        _duuruva->__dv_dist[idx].__skewness=0x00;
    }
}
void reset_duuruva_max_min(__duuruva_t *_duuruva){
    for(unsigned int idx=0x00;idx<_duuruva->__num_base_duuruva;idx++){
        _duuruva->__dv_dist[idx].__max=-__cwcn_infinite;
        _duuruva->__dv_dist[idx].__min=__cwcn_infinite;
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
            __cwcn_type_t _n;
            if(_duuruva->__dv_dist[idx].__count<BUGGER_MAX_DUURUVA_COUNT){
                _n = _duuruva->__dv_dist[idx].__count;
            }else{
                _n = BUGGER_MAX_DUURUVA_COUNT;
            }
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
__cwcn_type_t duuruva_standarize_inindex(__duuruva_t *_duuruva, __cwcn_type_t _value_scalar, unsigned int _idx){
    return (_value_scalar) / (_duuruva->__dv_dist[_idx].__std+BUGGER_DUURUVA_MIN_STD);
}
__cwcn_type_t duuruva_normalize_inindex(__duuruva_t *_duuruva, __cwcn_type_t _value_scalar, unsigned int _idx){
    return (_value_scalar-_duuruva->__dv_dist[_idx].__mean) / (_duuruva->__dv_dist[_idx].__std+BUGGER_DUURUVA_MIN_STD);
}
void duuruva_standarize(__duuruva_t *_duuruva, __cwcn_type_t *_value_vect){
    for(unsigned int _idx=0x00;_idx<_duuruva->__num_base_duuruva;_idx++){
        _value_vect[_idx]=duuruva_standarize_inindex(_duuruva, _value_vect[_idx],_idx);
    }
}
void duuruva_normalize(__duuruva_t *_duuruva, __cwcn_type_t *_value_vect){
    for(unsigned int _idx=0x00;_idx<_duuruva->__num_base_duuruva;_idx++){
        _value_vect[_idx]=duuruva_normalize_inindex(_duuruva, _value_vect[_idx],_idx);
    }
}
/*
*/
__cwcn_type_t duuruva_destandarize_inindex(__duuruva_t *_duuruva, __cwcn_type_t _value_scalar, unsigned int _idx){
    return (_value_scalar) * (_duuruva->__dv_dist[_idx].__std+BUGGER_DUURUVA_MIN_STD);
}
__cwcn_type_t duuruva_denormalize_inindex(__duuruva_t *_duuruva, __cwcn_type_t _value_scalar, unsigned int _idx){
    return (_value_scalar) * (_duuruva->__dv_dist[_idx].__std+BUGGER_DUURUVA_MIN_STD)+_duuruva->__dv_dist[_idx].__mean;
}
void duuruva_destandarize(__duuruva_t *_duuruva, __cwcn_type_t *_value_vect){
    for(unsigned int _idx=0x00;_idx<_duuruva->__num_base_duuruva;_idx++){
        _value_vect[_idx]=duuruva_destandarize_inindex(_duuruva, _value_vect[_idx],_idx);
    }
}
void duuruva_denormalize(__duuruva_t *_duuruva, __cwcn_type_t *_value_vect){
    for(unsigned int _idx=0x00;_idx<_duuruva->__num_base_duuruva;_idx++){
        _value_vect[_idx]=duuruva_denormalize_inindex(_duuruva, _value_vect[_idx],_idx);
    }
}
/*
*/
___cwcn_bool_t is_duuruva_ready(__duuruva_t *_duuruva){
    // #FIXME might yield problems due to forcing group state from item 0x00 reading
    if(!_duuruva->__dvbp->__reset_flag && _duuruva->__dv_dist[0x00].__count>=BUGGER_READY_DUURUVA_COUNT){
        _duuruva->__dvbp->__reset_flag=0x01; // #FIXME, not in use
    }
    return _duuruva->__dv_dist[0x00].__count>=BUGGER_READY_DUURUVA_COUNT;
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
    new_duuruva->__dvbp->__reset_flag=0x00;
    reset_duuruva(new_duuruva);
    return new_duuruva;
}

void print_duuruva(__duuruva_t *_duuruva){
    for(unsigned int _idx=0x00;_idx<_duuruva->__num_base_duuruva;_idx++){
        fprintf(stdout, "PRINTING DUURUVA [ %d ]\t\t\t(actual)\t\t(regularized)\n",_idx);
        fprintf(stdout, "DUURUVA [ %d ] __value: \t\t\t%f\t\t%f \n",_idx,_duuruva->__value[_idx],duuruva_standarize_inindex(_duuruva, _duuruva->__value[_idx],_idx));
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __count: \t%f\n",_idx,_duuruva->__dv_dist[_idx].__count);
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __max: \t\t%f\t\t%f\n",_idx,_duuruva->__dv_dist[_idx].__max,duuruva_normalize_inindex(_duuruva, _duuruva->__dv_dist[_idx].__max,_idx));
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __min: \t\t%f\t\t%f\n",_idx,_duuruva->__dv_dist[_idx].__min,duuruva_normalize_inindex(_duuruva, _duuruva->__dv_dist[_idx].__min,_idx));
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __std: \t\t%f\n",_idx,_duuruva->__dv_dist[_idx].__std);
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __mean: \t%f\t\t%f\n",_idx,_duuruva->__dv_dist[_idx].__mean,duuruva_standarize_inindex(_duuruva, _duuruva->__dv_dist[_idx].__mean,_idx));
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __M2: \t\t%f\n",_idx,_duuruva->__dv_dist[_idx].__M2);
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __M3: \t\t%f\n",_idx,_duuruva->__dv_dist[_idx].__M3);
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __M4: \t\t%f\n",_idx,_duuruva->__dv_dist[_idx].__M4);
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __kurtosis: \t%f\n",_idx,_duuruva->__dv_dist[_idx].__kurtosis);
        fprintf(stdout, "DUURUVA [ %d ] __dv_dist __skewness: \t%f\n",_idx,_duuruva->__dv_dist[_idx].__skewness);
        fprintf(stdout, "\n");
    }
}

void read_duuruva_vector(__duuruva_t *_duuruva, __cwcn_type_t *_dvx, ___cwcn_bool_t _norm_or_standar){
    unsigned int ctx_check=0x00;
    for(unsigned int _idx=0x00;_idx<_duuruva->__num_base_duuruva;_idx++){
        // if(!isnan(_duuruva->__dv_dist[_idx].__count)){_dvx[_idx+0x01]=_duuruva->__dv_dist[_idx].__count;}else{_dvx[_idx+0x01]=0x00;}
        if(!isnan(_duuruva->__value[_idx])){
            if(_norm_or_standar){
                _dvx[_idx+0x00]=duuruva_standarize_inindex(_duuruva, _duuruva->__value[_idx],_idx);
            }else{_dvx[_idx+0x00]=_duuruva->__value[_idx];}
        }else{_dvx[_idx+0x00]=0x00;}
        if(!isnan(_duuruva->__dv_dist[_idx].__max)){
            if(_norm_or_standar){
                _dvx[_idx+0x01]=duuruva_normalize_inindex(_duuruva, _duuruva->__dv_dist[_idx].__max,_idx);
            }else{_dvx[_idx+0x01]=_duuruva->__dv_dist[_idx].__max;}
        }else{_dvx[_idx+0x01]=0x00;}
        if(!isnan(_duuruva->__dv_dist[_idx].__min)){
            if(_norm_or_standar){
                _dvx[_idx+0x02]=duuruva_normalize_inindex(_duuruva, _duuruva->__dv_dist[_idx].__min,_idx);
            }else{_dvx[_idx+0x02]=_duuruva->__dv_dist[_idx].__min;}
        }else{_dvx[_idx+0x02]=0x00;}
        if(!isnan(_duuruva->__dv_dist[_idx].__mean)){
            if(_norm_or_standar){
                _dvx[_idx+0x03]=duuruva_standarize_inindex(_duuruva, _duuruva->__dv_dist[_idx].__mean,_idx);
            }else{_dvx[_idx+0x03]=_duuruva->__dv_dist[_idx].__mean;}
        }else{_dvx[_idx+0x03]=0x00;}
        if(!isnan(_duuruva->__dv_dist[_idx].__std)){_dvx[_idx+0x04]=_duuruva->__dv_dist[_idx].__std;}else{_dvx[_idx+0x04]=0x00;}
        if(!isnan(_duuruva->__dv_dist[_idx].__M2)){_dvx[_idx+0x05]=_duuruva->__dv_dist[_idx].__M2;}else{_dvx[_idx+0x05]=0x00;}
        if(!isnan(_duuruva->__dv_dist[_idx].__M3)){_dvx[_idx+0x06]=_duuruva->__dv_dist[_idx].__M3;}else{_dvx[_idx+0x06]=0x00;}
        if(!isnan(_duuruva->__dv_dist[_idx].__M4)){_dvx[_idx+0x07]=_duuruva->__dv_dist[_idx].__M4;}else{_dvx[_idx+0x07]=0x00;}
        if(!isnan(_duuruva->__dv_dist[_idx].__kurtosis)){_dvx[_idx+0x08]=_duuruva->__dv_dist[_idx].__kurtosis;}else{_dvx[_idx+0x08]=0x00;}
        if(!isnan(_duuruva->__dv_dist[_idx].__skewness)){_dvx[_idx+0x09]=_duuruva->__dv_dist[_idx].__skewness;}else{_dvx[_idx+0x09]=0x00;}
        ctx_check++;
    }
    assert(ctx_check==_duuruva->__num_base_duuruva);
    assert(BUGGER_SIZE_DUURUVA==0x09+0x01); // nine plus ommited count
}

void set_duuruva_value(__duuruva_t *_duuruva, __cwcn_type_t *_set_vector){
    for(unsigned int idx=0x00;idx<_duuruva->__num_base_duuruva;idx++){
        _duuruva->__value[idx]=_set_vector[idx];
    }
}
__cwcn_type_t *get_duuruva_value(__duuruva_t *_duuruva){
    return _duuruva->__value;
}

void duuruva_destroy(__duuruva_t *_duuruva){
    // for(unsigned int idx=0x00;idx<_duuruva->__num_base_duuruva;idx++){
    // }
    free(_duuruva->__dv_dist);
    free(_duuruva->__value);
    free(_duuruva->__dvbp);
    free(_duuruva);
        
}