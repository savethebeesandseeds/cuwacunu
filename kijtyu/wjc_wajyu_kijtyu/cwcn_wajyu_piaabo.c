#include "cwcn_wajyu_piaabo.h"
#include "cwcn_wikimyei_piaabo.h"
// Metrics are Duuruvas
__wajyu_metric_t *wajyu_metric_fabric(void *_wikimyei){
    /*
        NEW METRIC
    */
    __wajyu_metric_t *new_wajyu_metric=malloc(sizeof(__wajyu_metric_t));
    /*
        VALUE & METRICs
    */
    new_wajyu_metric->__wajyu_simple_value=0x00;
    char *aux_dumpfile;
    /* WAJYU SIMPLE VALUE METRIC */
    aux_dumpfile=__DUMPFILE_WAJYU_SIMPLE_VALUE_DUURUVA__;
    new_wajyu_metric->__wajyu_simple_value_duuruva=duuruva_fabric(0x01,aux_dumpfile);
    reset_duuruva(new_wajyu_metric->__wajyu_simple_value_duuruva);
    /* ALLIU METRIC */
    aux_dumpfile=__DUMPFILE_ALLIU_DUURUVA__;
    new_wajyu_metric->__alliu_duuruva=duuruva_fabric(((__wikimyei_t *)_wikimyei)->__alliu->__source_size,aux_dumpfile);
    reset_duuruva(new_wajyu_metric->__alliu_duuruva);
    /* UWAABO METRIC */
    aux_dumpfile=__DUMPFILE_UWAABO_DUURUVA__;
    new_wajyu_metric->__uwaabo_duuruva=duuruva_fabric(((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_state_size,aux_dumpfile);
    reset_duuruva(new_wajyu_metric->__uwaabo_duuruva);
    /* TSANE METRIC */
    aux_dumpfile=__DUMPFILE_TSANE_DUURUVA__;
    new_wajyu_metric->__tsane_duuruva=duuruva_fabric(((__wikimyei_t *)_wikimyei)->__tsane->__tsane_size,aux_dumpfile);
    reset_duuruva(new_wajyu_metric->__tsane_duuruva);
    /* ENTROPY METRIC */
    aux_dumpfile=__DUMPFILE_ENTROPY_DUURUVA__;
    new_wajyu_metric->__entropy_duuruva=duuruva_fabric(0x01,aux_dumpfile);
    reset_duuruva(new_wajyu_metric->__entropy_duuruva);
    /* IBAJCHO MUNAAJIPI METRIC */
    aux_dumpfile=__DUMPFILE_IMIBAJCHO_MUNAAJPI_DUURUVA__;
    new_wajyu_metric->__imibajcho_munaajpi_duuruva=duuruva_fabric(0x01,aux_dumpfile); // #FIXME fix the onedimensional J 
    reset_duuruva(new_wajyu_metric->__imibajcho_munaajpi_duuruva);
    /* JKIMYEI UWAABO MUNAAJIPI METRIC */
    aux_dumpfile=__DUMPFILE_JKIMYEI_UWAABO_MUNAAJPI_DUURUVA__;
    new_wajyu_metric->__jkimyei_uwaabo_munaajpi_duuruva=duuruva_fabric(((__wikimyei_t *)_wikimyei)->__munaajpi->__jkimyei_uwaabo_munaajpi_state_size,aux_dumpfile);
    reset_duuruva(new_wajyu_metric->__jkimyei_uwaabo_munaajpi_duuruva);
    /* UWAABO GAE RETURNS METRIC */
    aux_dumpfile=__DUMPFILE_UWAABO_GAE_RETURNS_DUURUVA__;
    new_wajyu_metric->__uwaabo_gae_returns_duuruva=duuruva_fabric(((__wikimyei_t *)_wikimyei)->__munaajpi->__jkimyei_uwaabo_munaajpi_state_size,aux_dumpfile);
    reset_duuruva(new_wajyu_metric->__uwaabo_gae_returns_duuruva);
    /* UWAABO GAE ADVENTAGE METRIC */
    aux_dumpfile=__DUMPFILE_UWAABO_GAE_ADVENTAGE_DUURUVA__;
    new_wajyu_metric->__uwaabo_gae_adventage_duuruva=duuruva_fabric(((__wikimyei_t *)_wikimyei)->__munaajpi->__jkimyei_uwaabo_munaajpi_state_size,aux_dumpfile);
    reset_duuruva(new_wajyu_metric->__uwaabo_gae_adventage_duuruva);
    /*
        LOSSES METRIC
    */
    /* UWAABO LOSS */
    aux_dumpfile=__DUMPFILE_UWAABO_LOSS_DUURUVA__;
    new_wajyu_metric->__uwaabo_loss_duuruva=duuruva_fabric(((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_state_size,aux_dumpfile);
    reset_duuruva(new_wajyu_metric->__uwaabo_loss_duuruva);
    /* IJIMYEI UWAABO MUNAAJIPI LOSS */
    aux_dumpfile=__DUMPFILE_JKIMYEI_UWAABO_MUNAAJPI_LOSS_DUURUVA__;
    new_wajyu_metric->__jkimyei_uwaabo_munaajpi_loss_duuruva=duuruva_fabric(((__wikimyei_t *)_wikimyei)->__munaajpi->__jkimyei_uwaabo_munaajpi_state_size,aux_dumpfile);
    reset_duuruva(new_wajyu_metric->__jkimyei_uwaabo_munaajpi_loss_duuruva);
    /*
        HANDLERS
    */
    aux_dumpfile=__DUMPFILE_RATIO_HANDLER_DUURUVA__;
    new_wajyu_metric->__ratio_handler_duuruva=duuruva_fabric(((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_state_size,aux_dumpfile);
    reset_duuruva(new_wajyu_metric->__ratio_handler_duuruva);
    aux_dumpfile=__DUMPFILE_SURR1_HANDLER_DUURUVA__;
    new_wajyu_metric->__surr1_handler_duuruva=duuruva_fabric(((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_state_size,aux_dumpfile);
    reset_duuruva(new_wajyu_metric->__surr1_handler_duuruva);
    aux_dumpfile=__DUMPFILE_SURR2_HANDLER_DUURUVA__;
    new_wajyu_metric->__surr2_handler_duuruva=duuruva_fabric(((__wikimyei_t *)_wikimyei)->__uwaabo->__uwaabo_state_size,aux_dumpfile);
    reset_duuruva(new_wajyu_metric->__surr2_handler_duuruva);

    return new_wajyu_metric;
}
__wajyu_t *wajyu_fabric(void *_wikimyei){
    /*
        NEW WAJYU
    */
    __wajyu_t *new_wajyu=malloc(sizeof(__wajyu_t));
    new_wajyu->__flags=malloc(sizeof(__wajyu_flags_t));
    // new_wajyu->__sufficient_map=malloc(sizeof(__wajyu_sufficient_map_t)); // #FIXME add or remove
    // new_wajyu->__sufficient_plot=malloc(sizeof(__wajyu_sufficient_plot_t)); // #FIXME add or remove
    new_wajyu->__metric=wajyu_metric_fabric(_wikimyei);
    ___cwcn_bool_t is_wajyu_ready(__wajyu_t *_wajyu);
    return new_wajyu;
}
void print_wayiu_metric_report(__wajyu_t *_wajyu){
    fprintf(stdout,"\t %s . . . silence, wajyu -> %s[__wajyu_simple_value_duuruva] \n",COLOR_WAJYU,COLOR_WAJYU);
    print_duuruva(_wajyu->__metric->__wajyu_simple_value_duuruva);
    fprintf(stdout,"\t %s . . . silence, wajyu -> %s[__alliu_duuruva] \n",COLOR_WAJYU,COLOR_ALLIU);
    print_duuruva(_wajyu->__metric->__alliu_duuruva);
    fprintf(stdout,"\t %s . . . silence, wajyu -> %s[__uwaabo_duuruva] \n",COLOR_WAJYU,COLOR_UWAABO);
    print_duuruva(_wajyu->__metric->__uwaabo_duuruva);
    fprintf(stdout,"\t %s . . . silence, wajyu -> %s[__tsane_duuruva] \n",COLOR_WAJYU,COLOR_TSANE);
    print_duuruva(_wajyu->__metric->__tsane_duuruva);
    fprintf(stdout,"\t %s . . . silence, wajyu -> %s[__entropy_duuruva] \n",COLOR_WAJYU,COLOR_ENTROPY);
    print_duuruva(_wajyu->__metric->__entropy_duuruva);
    fprintf(stdout,"\t %s . . . silence, wajyu -> %s[__uwaabo_loss_duuruva] \n",COLOR_WAJYU,COLOR_UWAABO);
    print_duuruva(_wajyu->__metric->__uwaabo_loss_duuruva);
    fprintf(stdout,"\t %s . . . silence, wajyu -> %s[__imibajcho_munaajpi_duuruva] \n",COLOR_WAJYU,COLOR_MUNAAJPI);
    print_duuruva(_wajyu->__metric->__imibajcho_munaajpi_duuruva);
    fprintf(stdout,"\t %s . . . silence, wajyu -> %s[__jkimyei_uwaabo_munaajpi_loss_duuruva] \n",COLOR_WAJYU,COLOR_MUNAAJPI);
    print_duuruva(_wajyu->__metric->__jkimyei_uwaabo_munaajpi_loss_duuruva);
    fprintf(stdout,"\t %s . . . silence, wajyu -> %s[__uwaabo_gae_returns_duuruva] \n",COLOR_WAJYU,COLOR_UWAABO);
    print_duuruva(_wajyu->__metric->__uwaabo_gae_returns_duuruva);
    fprintf(stdout,"\t %s . . . silence, wajyu -> %s[__uwaabo_gae_adventage_duuruva] \n",COLOR_WAJYU,COLOR_UWAABO);
    print_duuruva(_wajyu->__metric->__uwaabo_gae_adventage_duuruva);  
    fprintf(stdout,"\t %s . . . silence, wajyu -> %s[__ratio_handler_duuruva] \n",COLOR_WAJYU,COLOR_JKIMYEI);
    print_duuruva(_wajyu->__metric->__ratio_handler_duuruva);
    fprintf(stdout,"\t %s . . . silence, wajyu -> %s[__surr1_handler_duuruva] \n",COLOR_WAJYU,COLOR_JKIMYEI);
    print_duuruva(_wajyu->__metric->__surr1_handler_duuruva);
    fprintf(stdout,"\t %s . . . silence, wajyu -> %s[__surr2_handler_duuruva] \n",COLOR_WAJYU,COLOR_JKIMYEI);
    print_duuruva(_wajyu->__metric->__surr2_handler_duuruva);
}
void update_wajyu_flags(__wajyu_t *_wajyu){
    _wajyu->__flags->__is_wajyu_simple_value_ready=is_duuruva_ready(_wajyu->__metric->__wajyu_simple_value_duuruva);
    _wajyu->__flags->__is_alliu_ready=is_duuruva_ready(_wajyu->__metric->__alliu_duuruva);
    _wajyu->__flags->__is_uwaabo_ready=is_duuruva_ready(_wajyu->__metric->__uwaabo_duuruva);
    _wajyu->__flags->__is_tsane_ready=is_duuruva_ready(_wajyu->__metric->__tsane_duuruva);
    _wajyu->__flags->__is_entropy_ready=is_duuruva_ready(_wajyu->__metric->__entropy_duuruva);
    _wajyu->__flags->__is_uwaabo_loss_ready=is_duuruva_ready(_wajyu->__metric->__uwaabo_loss_duuruva);
    _wajyu->__flags->__is_imibajcho_munaajpi_ready=is_duuruva_ready(_wajyu->__metric->__imibajcho_munaajpi_duuruva);
    _wajyu->__flags->__is_jkimyei_uwaabo_munaajpi_loss_ready=is_duuruva_ready(_wajyu->__metric->__jkimyei_uwaabo_munaajpi_loss_duuruva);
    _wajyu->__flags->__is_uwaabo_gae_returns_ready=is_duuruva_ready(_wajyu->__metric->__uwaabo_gae_returns_duuruva);
    _wajyu->__flags->__is_uwaabo_gae_adventage_ready=is_duuruva_ready(_wajyu->__metric->__uwaabo_gae_adventage_duuruva);
    _wajyu->__flags->__is_ratio_handler_ready=is_duuruva_ready(_wajyu->__metric->__ratio_handler_duuruva);
    _wajyu->__flags->__is_surr1_handler_ready=is_duuruva_ready(_wajyu->__metric->__surr1_handler_duuruva);
    _wajyu->__flags->__is_surr2_handler_ready=is_duuruva_ready(_wajyu->__metric->__surr2_handler_duuruva);
}
___cwcn_bool_t is_wajyu_ready(__wajyu_t *_wajyu){
    update_wajyu_flags(_wajyu);
    return _wajyu->__flags->__is_alliu_ready;
    // _wajyu->__flags->__is_uwaabo_ready && 
    // _wajyu->__flags->__is_tsane_ready && 
    // _wajyu->__flags->__is_entropy_ready && 
    // _wajyu->__flags->__is_jkimyei_uwaabo_munaajpi_ready && 
    // _wajyu->__flags->__is_wajyu_simple_value_ready && 
    // _wajyu->__flags->__is_imibajcho_munaajpi_ready && 
    // _wajyu->__flags->__is_uwaabo_gae_adventage_ready && 
    // _wajyu->__flags->__is_uwaabo_gae_returns_ready && 
    // _wajyu->__flags->__is_uwaabo_loss_ready && 
    // _wajyu->__flags->__is_jkimyei_uwaabo_munaajpi_loss_ready && 
    // _wajyu->__flags->__is_ratio_handler_ready && 
    // _wajyu->__flags->__is_surr1_handler_ready && 
    // _wajyu->__flags->__is_surr2_handler_ready && 
}

void wajyu_destroy(__wajyu_t *_wajyu){
    duuruva_destroy(_wajyu->__metric->__alliu_duuruva);
    duuruva_destroy(_wajyu->__metric->__uwaabo_duuruva);
    duuruva_destroy(_wajyu->__metric->__wajyu_simple_value_duuruva);
    duuruva_destroy(_wajyu->__metric->__tsane_duuruva);
    duuruva_destroy(_wajyu->__metric->__entropy_duuruva);
    duuruva_destroy(_wajyu->__metric->__uwaabo_loss_duuruva);
    duuruva_destroy(_wajyu->__metric->__imibajcho_munaajpi_duuruva);
    duuruva_destroy(_wajyu->__metric->__jkimyei_uwaabo_munaajpi_loss_duuruva);
    duuruva_destroy(_wajyu->__metric->__uwaabo_gae_returns_duuruva);
    duuruva_destroy(_wajyu->__metric->__uwaabo_gae_adventage_duuruva);
    duuruva_destroy(_wajyu->__metric->__ratio_handler_duuruva);
    duuruva_destroy(_wajyu->__metric->__surr1_handler_duuruva);
    duuruva_destroy(_wajyu->__metric->__surr2_handler_duuruva);
    free(_wajyu->__metric);
    free(_wajyu->__flags);
}