// Metrics are Duuruvas
__metric_t *wajyu_metric_fabric(__wikimyei_t *_wikimyei){
    /*
        NEW METRIC
    */
    __metric_t *new_wajyu_metric=malloc(sizeof(__wajyu_t));
    /* WAJYU SIMPLE VALUE METRIC */
    new_wajyu_metric->__wajyu_simple_value_duuruva=duuruva_fabric(0x01);
    reset_duuruva(new_wajyu_metric->__wajyu_simple_value_duuruva);
    /* ALLIU METRIC */
    new_wajyu_metric->__alliu_duuruva=duuruva_fabric(_wikimyei->__alliu_state_size);
    reset_duuruva(new_wajyu_metric->__alliu_duuruva);
    /* UWAABO METRIC */
    new_wajyu_metric->__uwaabo_duuruva=duuruva_fabric(_wikimyei->__uwaabo_state_size);
    reset_duuruva(new_wajyu_metric->__uwaabo_duuruva);
    /* UWAABO LOSS METRIC */
    new_wajyu_metric->__uwaabo_loss_duuruva=duuruva_fabric(_wikimyei->__uwaabo_state_size);
    reset_duuruva(new_wajyu_metric->__uwaabo_loss_duuruva);
    /* IBAJCHO MUNAAJIPI METRIC */
    new_wajyu_metric->__imibajcho_munaajpi_duuruva=duuruva_fabric(0x01); // #FIXME fix the onedimensional J 
    reset_duuruva(new_wajyu_metric->__imibajcho_munaajpi_duuruva);
    /* IBAJCHO MUNAAJIPI LOSS METRIC */
    new_wajyu_metric->__imibajcho_munaajpi_loss_duuruva=duuruva_fabric(\
        _wikimyei->__wajyu->__metric->__imibajcho_munaajpi_loss_duuruva->__duuruva_vector_size);
    reset_duuruva(new_wajyu_metric->__imibajcho_munaajpi_loss_duuruva);
    new_wajyu_metric->__imibajcho_munaajpi_loss_duuruva_state_size=new_wajyu_metric->__imibajcho_munaajpi_loss_duuruva->__duuruva_vector_size;
    /* UWAABO ADVENTAGE METRIC */
    new_wajyu_metric->__uwaabo_adventage_duuruva=duuruva_fabric(_uwaabo_state_size);
    reset_duuruva(new_wajyu_metric->__uwaabo_adventage_duuruva);
    new_wajyu_metric->__uwaabo_adventage_duuruva_state_size=new_wajyu_metric->__uwaabo_adventage_duuruva->__duuruva_vector_size;
    return new_wajyu_metric;
}

__wajyu_t *wajyu_fabric(__wikimyei_t *_wikimyei){
    /*
        NEW WAJYU
    */
    __wajyu_t *new_wajyu=malloc(sizeof(__wajyu_t));
    // new_wajyu->__sufficient_map=malloc(sizeof(__wajyu_sufficient_map_t)); // #FIXME add or remove
    // new_wajyu->__sufficient_plot=malloc(sizeof(__wajyu_sufficient_plot_t)); // #FIXME add or remove
    new_wajyu->__metric=wajyu_metric_fabric(_wikimyei);
}
void print_wayiu_metric_report(__wajyu_t *_wajyu){   
    fprintf(stdout,"\t . . . %s silence, waiju -> %s[__alliu_duuruva:] \n",COLOR_WAJYU,COLOR_ALLIU);
    print_duuruva(_wajyu->__metric->__alliu_duuruva);
    fprintf(stdout,"\t . . . %s silence, waiju -> %s[__uwaabo_adventage_duuruva:] \n",COLOR_WAJYU,COLOR_ADVENTAJE);
    print_duuruva(_wajyu->__metric->__uwaabo_adventage_duuruva);
    fprintf(stdout,"\t . . . %s silence, waiju -> %s[__uwaabo_duuruva:] \n",COLOR_WAJYU,COLOR_UWAABO);
    print_duuruva(_wajyu->__metric->__uwaabo_duuruva);
    fprintf(stdout,"\t . . . %s silence, waiju -> %s[__uwaabo_loss_duuruva:] \n",COLOR_WAJYU,COLOR_UWAABO);
    print_duuruva(_wajyu->__metric->__uwaabo_loss_duuruva);
    fprintf(stdout,"\t . . . %s silence, waiju -> %s[__munaajpi_duuruva:] \n",COLOR_WAJYU,COLOR_MUNAAJPI);
    print_duuruva(_wajyu->__metric->__munaajpi_duuruva);
    fprintf(stdout,"\t . . . %s silence, waiju -> %s[__munaajpi_loss_duuruva:] \n",COLOR_WAJYU,COLOR_MUNAAJPI);
    print_duuruva(_wajyu->__metric->__munaajpi_loss_duuruva);
}