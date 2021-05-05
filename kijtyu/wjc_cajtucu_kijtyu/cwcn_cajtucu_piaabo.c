#include "cwcn_cajtucu_piaabo.h" 
typedef enum {
    PLACED_tsane_state,
    FILLED_tsane_state,
    NONE_tsane_state
}__tsane_state_t;
__cajtucu_t cajtucu_fabric(__cwcn_bool_t _take_tsane, unsigned int _tsane_size){
    __cajtucu_t *new_cajtucu=malloc(sizeof(__cajtucu_t));
    new_cajtucu->__tsane_size=_tsane_size;
    new_cajtucu->__take_tsane=_take_tsane;
    new_cajtucu->__tsane_value=malloc(_tsane_size*sizeof(__cwcn_type_t));
    new_cajtucu->__tsane_state_value=NONE_tsane_state;
}
void cajtucu_tsane(__cajtucu_t *_cajtucu); // #FIXME what?
void putc_tsane(__cajtucu_t *_cajtucu);