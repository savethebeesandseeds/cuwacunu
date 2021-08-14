#ifndef WAJYU_PIAABO_INCLUDED
#define WAJYU_PIAABO_INCLUDED
#define WAJYU_INCLUDED
#include "cwcn_duuruva_nebajke.h"

typedef struct __wajyu_metric {
    __cwcn_type_t __wajyu_simple_value; // 'this is the show' # FIXME add the show, there is no use of this variable
    __duuruva_t *__wajyu_simple_value_duuruva;
    __duuruva_t *__alliu_duuruva;
    __duuruva_t *__uwaabo_duuruva;
    __duuruva_t *__tsane_duuruva;
    __duuruva_t *__entropy_duuruva;
    __duuruva_t *__imibajcho_munaajpi_duuruva;
    __duuruva_t *__jkimyei_uwaabo_munaajpi_duuruva;
    __duuruva_t *__uwaabo_gae_returns_duuruva;
    __duuruva_t *__uwaabo_gae_adventage_duuruva;
    __duuruva_t *__uwaabo_loss_duuruva;
    __duuruva_t *__jkimyei_uwaabo_munaajpi_loss_duuruva;
    __duuruva_t *__ratio_handler_duuruva;
    __duuruva_t *__surr1_handler_duuruva;
    __duuruva_t *__surr2_handler_duuruva;
}__wajyu_metric_t;
typedef struct __hiperdimensional_heat_map {
    unsigned int __process_size; // constant model variables count
    // __cwcn_wajyu_meaning_t **__wajyu_map; // map to the values (wajyu_munaajpi)
    // __cwcn_type_t **__first_map; // variational experimen results
    // __cwcn_type_t ***__diff1_map; // jacobian(first_map)
    // __cwcn_type_t **__first_imaginary_map; // cos(real)+sin(real)=exp(imaginary)
    // __cwcn_type_t **__second_imaginary_map; // cos(first_imaginary)+sin(first_imaginary)=exp(second_imaginary)
}__hiperdimencional_heat_map_t;
typedef struct __wajyu_sufficient_plot {
    unsigned int __num_of_val;
    unsigned int __size_of_plot;
    __cwcn_type_t **__plot_val_vector; // #FIXME assert cast for if ploting integers
}__wajyu_sufficient_plot_t;
typedef struct __wajyu_sufficient_map {
    __hiperdimencional_heat_map_t *__wajyu_munaajpi_heat_map;
}__wajyu_sufficient_map_t;
typedef struct __wajyu_flags {
    ___cwcn_bool_t __is_wajyu_ready;
    ___cwcn_bool_t __is_wajyu_simple_value_ready;
    ___cwcn_bool_t __is_alliu_ready;
    ___cwcn_bool_t __is_uwaabo_ready;
    ___cwcn_bool_t __is_tsane_ready;
    ___cwcn_bool_t __is_entropy_ready;
    ___cwcn_bool_t __is_uwaabo_gae_returns_ready;
    ___cwcn_bool_t __is_uwaabo_gae_adventage_ready;
    ___cwcn_bool_t __is_imibajcho_munaajpi_ready;
    ___cwcn_bool_t __is_jkimyei_uwaabo_munaajpi_ready;
    ___cwcn_bool_t __is_uwaabo_loss_ready;
    ___cwcn_bool_t __is_jkimyei_uwaabo_munaajpi_loss_ready;
    ___cwcn_bool_t __is_ratio_handler_ready;
    ___cwcn_bool_t __is_surr1_handler_ready;
    ___cwcn_bool_t __is_surr2_handler_ready;
}__wajyu_flags_t;
typedef struct __wajyu {
    __wajyu_metric_t *__metric;
    __wajyu_flags_t *__flags;
    // __wajyu_sufficient_plot_t *__sufficient_plot;
    // __wajyu_sufficient_map_t *__sufficient_map;
}__wajyu_t;
/*
*/
__wajyu_metric_t *wajyu_metric_fabric(void *_wikimyei);
void print_wayiu_metric_report(__wajyu_t *_wajyu);
___cwcn_bool_t is_wajyu_ready(__wajyu_t *_wajyu);
void update_wajyu_flags(__wajyu_t *_wajyu);
__wajyu_t *wajyu_fabric(void *_wikimyei);
void wajyu_destroy(__wajyu_t *_wajyu);
#endif