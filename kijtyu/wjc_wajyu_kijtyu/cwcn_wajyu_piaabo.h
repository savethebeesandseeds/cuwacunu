#ifndef WAJYU_PIAABO_INCLUDED
#define WAJYU_PIAABO_INCLUDED
#define WAJYU_INCLUDED
__cwcn_wajyu_meaning_t
typedef struct __wajyu_metric {
    ___cwcn_type_t __wajyu_simple_value; // 'this is the show'
    __duuruva_t *__wajyu_simple_value_duuruva;
    __duuruva_t *__alliu_duuruva;
    __duuruva_t *__uwaabo_duuruva;
    __duuruva_t *__uwaabo_loss_duuruva; // to study the variance of the tsinuu loss
    __duuruva_t *__uwaabo_adventage_duuruva; // (this is the adventage)
    __duuruva_t *__imibajcho_munaajpi_duuruva;
    __duuruva_t *__imibajcho_munaajpi_loss_duuruva; // to study the variance of the tsinuu loss
}__wajyu_metric_t;
typedef struct __hiperdimensional_heat_map {
    unsigned int __process_size; // constant model variables count
    __cwcn_wajyu_meaning_t **__wajyu_map; // map to the values (wajyu_munaajpi)
    // __cwcn_type_t **__first_map; // variational experimen results
    // __cwcn_type_t ***__diff1_map; // jacobian(first_map)
    // __cwcn_type_t **__first_imaginary_map; // cos(real)+sin(real)=exp(imaginary)
    // __cwcn_type_t **__second_imaginary_map; // cos(first_imaginary)+sin(first_imaginary)=exp(second_imaginary)
    unsigned int **
}__hiperdimencional_heat_map_t;
typedef struct __wajyu_sufficient_plot {
    unsigned int __num_of_val;
    unsigned int __size_of_plot;
    __cwcn_type_t **__plot_val_vector; // #FIXME assert cast for if ploting integers
}__wajyu_sufficient_plot_t;
typedef struct __wajyu_sufficient_map {
    __hiperdimencional_heat_map_t *__wajyu_munaajpi_heat_map;
}__wajyu_sufficient_map_t;
typedef struct __wajyu {
    __wajyu_metric_t *__metric;
    // __wajyu_sufficient_plot_t *__sufficient_plot;
    // __wajyu_sufficient_map_t *__sufficient_map;
}__wajyu_t;
__metric_t *wajyu_metric_fabric(__wikimyei_t *_wikimyei);
__wajyu_t *wajyu_fabric(__wikimyei_t *_wikimyei);
#endif