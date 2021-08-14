#include "cwcn_ujcamei_piaabo.h"
__alliu_t *alliu_fabric(__alliu_source_t _source_type, unsigned int _source_size){
    __alliu_t *new_alliu=malloc(sizeof(__alliu_t));
    new_alliu->__source_type=_source_type;
    new_alliu->__source_count=0x00;
    new_alliu->__source_size=_source_size;
    new_alliu->__source_value=malloc(_source_size*sizeof(__cwcn_type_t));
    for(unsigned int idx=0x00;idx<_source_size;idx++){new_alliu->__source_value[idx]=0x00;}
    return new_alliu;
}
void getnext_alliu(__alliu_t *_alliu){
    ___cwcn_bool_t _done=___CWCN_FALSE; // #FIXME add alliu done
    switch(_alliu->__source_type){
        case UNIT_as_alliu:
            for(unsigned int idx=0x00;idx<_alliu->__source_size;idx++){
                _alliu->__source_value[idx]=1.0;
            }
            _alliu->__source_count+=0x01;
            break;
        case negINDEX_as_alliu:
            for(unsigned int idx=0x00;idx<_alliu->__source_size;idx++){
                _alliu->__source_value[idx]=-(__cwcn_type_t)_alliu->__source_count;
            }
            _alliu->__source_count+=0x01;
            break;
        case INDEX_as_alliu:
            for(unsigned int idx=0x00;idx<_alliu->__source_size;idx++){
                _alliu->__source_value[idx]=(__cwcn_type_t)_alliu->__source_count;
            }
            _alliu->__source_count+=0x01;
            break;
        case SINE_as_alliu:
            for(unsigned int idx=0x00;idx<_alliu->__source_size;idx++){
                _alliu->__source_value[idx]=(__cwcn_type_t)sin((__cwcn_type_t)2.0*(__cwcn_type_t)3.141592*(__cwcn_type_t)0.01*(__cwcn_type_t)_alliu->__source_count);
                // printf("waka : _alliu->__source_value[%d] : %d : %f \n",idx,_alliu->__source_count,_alliu->__source_value[idx]);
                // printf("\t\t\twaka alliu: [%d]=%f\n",_alliu->__source_count,sin(3.14+2*3.141592*0.01*_alliu->__source_count));
            }
            _alliu->__source_count+=0x01;
            break;
        default:
            fprintf(stderr, ">> ERROR, encounter unknown <alliu->__source_type> in <get_alliu>\n");
            assert(0x00);
            break;
    }
    if(_done){
        fprintf(stdout,">>> \033[1;32m source alliu agotated succesfully...\033[0m\n CWCN_EXIT...\n");
        exit(0x00);
    }
}
void alliu_destroy(__alliu_t *_alliu){
    free(_alliu->__source_value);
    free(_alliu);
}