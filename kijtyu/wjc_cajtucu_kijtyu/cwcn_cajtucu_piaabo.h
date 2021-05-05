// remmemer PMF[a_idx], from I, from the past ¿do we make it?.
#ifndef FUNCTIONS_WIKIMYEI_NEBAJKE
#define FUNCTIONS_WIKIMYEI_NEBAJKE
typedef enum {
    PLACED_tsane_state,
    FILLED_tsane_state,
    NONE_tsane_state
}__tsane_state_t;
typedef struct __cajtucu {
    unsigned int __tsane_size;
    __cwcn_bool_t __take_tsane; // set to perform actual order
    __cwcn_type_t *__tsane_value;
    __tsane_state_t *__tsane_state_value;
}__cajtucu_t;
void cajtucu_fabric(__cwcn_bool_t _take_tsane);
void cajtucu_tsane(__cajtucu_t *_cajtucu); // #FIXME what?
void putc_tsane(__cajtucu_t *_cajtucu);
#endif