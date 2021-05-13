#include "cwcn_cajtucu_piaabo.h" 
typedef enum {
    PLACED_tsane_state,
    FILLED_tsane_state,
    NONE_tsane_state
}__tsane_state_t;
__tsane_t *tsane_fabric(___cwcn_bool_t _take_tsane, unsigned int _tsane_size){
    __tsane_t *new_tsane=malloc(sizeof(__tsane_t));
    new_tsane->__tsane_size=_tsane_size;
    new_tsane->__take_tsane=_take_tsane;
    new_tsane->__tsane_value=malloc(_tsane_size*sizeof(__cwcn_type_t));
    for(unsigned int idx=0x00;idx<_tsane_size;idx++){new_tsane->__tsane_value[idx]=0x00;}
    new_tsane->__tsane_index=0x00;
    new_tsane->__tsane_status_value=NONE_tsane_state;
    return new_tsane;
}
void putc_tsane(__tsane_t *_tsane){
    // #FIXME, enum class tsane    
}
void imibajcho_munaajpi_cajtucu_transformation(__wikimyei_t *_wikimyei){
    // tsane_state[0] == call
    // tsane_state[1] == put
    assert(_wikimyei->__tsane_state_size==0x02);
    __cwcn_type_t ims_aux=0x00;
    ims_aux+=glti(_wikimyei)->__imibajcho_munaajpi_state*(+1)*glti(_wikimyei)->__tsane_state[0];
    ims_aux+=glti(_wikimyei)->__imibajcho_munaajpi_state*(-1)*glti(_wikimyei)->__tsane_state[0];
    glti(_wikimyei)->__imibajcho_munaajpi_state=ims_aux;
}
void tsane_destroy(__tsane_t *_tsane){
    free(_tsane->__tsane_value);
    free(_tsane);
}