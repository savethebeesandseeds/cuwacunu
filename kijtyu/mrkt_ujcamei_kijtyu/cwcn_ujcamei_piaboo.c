#include "cwcn_alliu_piaabo.h"
__alliu_t *alliu_fabric(__alliu_source_t _source_type, unsigned int _source_size){
    __alliu_t *new_alliu=malloc(sizeof(__alliu_t));
    new_alliu->__source_type=_source_type;
    new_alliu->__source_count=0x00;
    new_alliu->__source_size=_source_size;
    new_alliu->__source_value=malloc(_source_size*sizeof(__cwcn_type_t));
    for(unsigned int idx=0x00;idx<_source_size;idx++){new_alliu->__source_value[idx]=0x00;}
}
void getnext_alliu(__alliu_t *_alliu){
    switch(_alliu->__source){
        case SINE:
            for(unsigned int idx=0x00;idx<_alliu->__source_size;idx++){
                _alliu->__source_value[idx]=0.5*sin(2*3.141592*0.01*new_alliu->__source_count)+1;
            }
            _alliu->__source_count+=0x01;
            break;
        default:
            fprintf(stderr, ">> ERROR, encounter unknown <alliu->__source_type> in <get_alliu>\n");
            assert(0x00);
            break;
    }
}