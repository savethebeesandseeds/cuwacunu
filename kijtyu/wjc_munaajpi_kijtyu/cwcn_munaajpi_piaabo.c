#include "cwcn_munaajpi_piaabo.h"
__munaajpi_t *munaajpi_fabric(\
            unsigned int _munaajpi_base_size, \
            unsigned int _munaajpi_state_size, \
            __cwcn_type_t _munaajpi_waapajco_potency){
    /* config */
    __munaajpi_t *new_munaajpi=malloc(sizeof(__munaajpi_t));
    new_munaajpi->__jkimyei_uwaabo_munaajpi_state_size=_munaajpi_state_size; // 0x01 equal to the size of imibajcho_munaajpi
    new_munaajpi->__munaajpi_base_w_size=_munaajpi_base_size;
    new_munaajpi->__munaajpi_w_base=malloc(new_munaajpi->__munaajpi_base_w_size*sizeof(__cwcn_type_t));
    for(unsigned int idx=0x00;idx<_munaajpi_base_size;idx++){new_munaajpi->__munaajpi_w_base[idx]=0x00;}
    /* tsinuu */
    unsigned int mjpi_total_layers=0x04;
    unsigned int mjpi_input_size=_munaajpi_base_size; // huge thing
    unsigned int mjpi_output_size=_munaajpi_state_size;
    unsigned int mjpi_layers_sizes[0x04] = {mjpi_input_size,32,16,mjpi_output_size};
    #ifndef DEBUG_LINEAR_EXPERIMENT
    __list_activations_t mjpi_activations_iho[0x04] = {
                            LINEAR, 
                            SIGNEDSIGMOID, 
                            SIGNEDSIGMOID, 
                            SIGNEDSIGMOID}; // must be signed sigmoid
    #else
    __list_activations_t mjpi_activations_iho[0x05] = {LINEAR, LINEAR, SIGMOID, SIGMOID, SIGNEDSIGMOID};
    #endif
    __attribute_tsinuu_t *c_attribute_tsinuu=malloc(sizeof(__attribute_tsinuu_t));
    c_attribute_tsinuu->__NUM_TOTAL_LAYERS=mjpi_total_layers;
    // c_attribute_tsinuu->__layers_sizes=mjpi_layers_sizes;
    // c_attribute_tsinuu->__layers_activation=mjpi_activations_iho;
    c_attribute_tsinuu->__layers_sizes=malloc(mjpi_total_layers*sizeof(unsigned int));
    c_attribute_tsinuu->__layers_activation=malloc(mjpi_total_layers*sizeof(__list_activations_t));
    for(unsigned int idx=0x00;idx<mjpi_total_layers;idx++){
        c_attribute_tsinuu->__layers_sizes[idx]=mjpi_layers_sizes[idx];
        c_attribute_tsinuu->__layers_activation[idx]=mjpi_activations_iho[idx];
    }
    c_attribute_tsinuu->__is_symetric=___CWCN_TRUE; // meaning fully conected normal Network
    c_attribute_tsinuu->__alpha=0.0; // alpha assert negative, is a mesure for resisting change; is if you kguht the friction of the learning; required to create new tsinuu
    c_attribute_tsinuu->__eta=1.0; // eta is the error impulse, required to create new tsinuu
    c_attribute_tsinuu->__omega=0.1; // required to create new tsinuu
    c_attribute_tsinuu->__wapaajco_potency=1.0; // the potency of the wapaajco
    c_attribute_tsinuu->__omega_stiffess=1.0; // #FIXME not in use
    c_attribute_tsinuu->__weight_limits=malloc(sizeof(__limits_t));
    c_attribute_tsinuu->__weight_limits->__max=__MAX_TSINUU_HIPERPARAMETER__;
    c_attribute_tsinuu->__weight_limits->__min=-__MAX_TSINUU_HIPERPARAMETER__;
    c_attribute_tsinuu->__bias_limits=malloc(sizeof(__limits_t));
    c_attribute_tsinuu->__bias_limits->__max=__MAX_TSINUU_HIPERPARAMETER__;
    c_attribute_tsinuu->__bias_limits->__min=-__MAX_TSINUU_HIPERPARAMETER__;
    /* fabric */
    new_munaajpi->__munaajpi_tsinuu=tsinuu_fabric(c_attribute_tsinuu);

    new_munaajpi->__munaajpi_tsinuu->__attributes->__wapaajco_potency=_munaajpi_waapajco_potency;

    #ifndef DEBUG_LINEAR_EXPERIMENT
    tsinuu_initialize_weights_random(new_munaajpi->__munaajpi_tsinuu, 0.5, -0.5);
    // tsinuu_initialize_bias_random(new_munaajpi->__munaajpi_tsinuu, 0.5, -0.5);
    // tsinuu_initialize_weights_zero(new_munaajpi->__munaajpi_tsinuu);
    tsinuu_initialize_bias_zero(new_munaajpi->__munaajpi_tsinuu);
    #else
    tsinuu_initialize_weights_fixed(new_munaajpi->__munaajpi_tsinuu,1.0);
    tsinuu_initialize_bias_fixed(new_munaajpi->__munaajpi_tsinuu,1.0);
    #endif
    set_all_nodebooleanpardon_parametric(new_munaajpi->__munaajpi_tsinuu, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
    pardon_inputoutput_bias(new_munaajpi->__munaajpi_tsinuu); // #FIXME check if needed of enabled
    set_all_linebooleanpardon_parametric(new_munaajpi->__munaajpi_tsinuu, 0x00, 0x00);
    return new_munaajpi;
}
/*

*/
___cwcn_bool_t set_load_pending_munaajpi(__wikimyei_t *_wikimyei){
    #if defined(WIKIMYEI_DEBUG) || defined(MUNAAJPI_DEBUG)
    fprintf(stdout,"%s>> > request to set_load_pending_munaajpi %s\n",COLOR_MUNAAJPI,COLOR_REGULAR);
    #endif
    if(_wikimyei->__load_size<_wikimyei->__horizon_munaajpi){
        fprintf(stdout,">> > WARNING, request to (set_load_pending_munaajpi) on load_size [%d] to short for horizon_munaajpi [%d]...\n",_wikimyei->__load_size,_wikimyei->__horizon_munaajpi);
        return are_munaajpi_pending(_wikimyei);
    }
    // #FIXME include mask
    int start_index=_wikimyei->__load_index;
    int c_index;
    __trayectory_t *c_item;
    load_to_start(_wikimyei); // go down
    do{ // go up
        #ifdef MUNJAAPI_DEBUG
        fprintf(stdout,"%s>> > for load_index: [%d] set_load_pending_munaajpi%s\n",COLOR_MUNAAJPI,_wikimyei->__load_index,COLOR_REGULAR);
        #endif
        #ifdef MUNJAAPI_DEBUG
        fprintf(stdout,"%s>> > \033[0;32m--- --- --- --- --- --- --- --- --- --- --- BASE UP: %d%s\n",COLOR_MUNAAJPI,_wikimyei->__load_index,COLOR_REGULAR);
        #endif
        c_item=glti(_wikimyei);
        c_index=_wikimyei->__load_index;
        do{ // go up the horizon
            #ifdef MUNJAAPI_DEBUG
            fprintf(stdout,"%s>> > \033[0;36m--- --- --- --- --- --- --- --- --- --- --- GO UP (sec): %d%s\n",COLOR_MUNAAJPI,_wikimyei->__load_index,COLOR_REGULAR);
            #endif
            if(!c_item->__pending_munaajpi){break;} // skip
            if(_wikimyei->__load_size-c_index<_wikimyei->__horizon_munaajpi){break;} // skip
            if(c_item->__pending_munaajpi_index<_wikimyei->__horizon_munaajpi){
                c_item->__pending_munaajpi_index++;
                for(unsigned int m_idx=0x00;m_idx<_wikimyei->__alliu->__source_size;m_idx++){
                    c_item->__nonuwaabo_alliu_state[m_idx]+=glti(_wikimyei)->__alliu_state[m_idx]/((__cwcn_type_t)(_wikimyei->__horizon_munaajpi)); // #FIXME lacking gamma
                    // c_item->__nonuwaabo_alliu_state[m_idx]+=glti(_wikimyei)->__alliu_state[m_idx]/((__cwcn_type_t)(_wikimyei->__horizon_munaajpi)); // #FIXME lacking gamma
                }
                #ifdef MUNJAAPI_DEBUG
                    printf("%s>> > .g. nonuwaabo alliu update: [",COLOR_ALLIU);
                    for(unsigned int m_idx=0x00;m_idx<_wikimyei->__alliu->__source_size;m_idx++){
                        printf(" nonuwaabo_alliu_state [%d/%d]: %f, alliu_state [%d/%d]: %f\t ", c_index, m_idx, c_item->__nonuwaabo_alliu_state[m_idx], _wikimyei->__load_index, m_idx, glti(_wikimyei)->__alliu_state[m_idx]);
                    }
                    printf(" ]%s\n",COLOR_REGULAR);
                #endif
            }if(c_item->__pending_munaajpi_index>=_wikimyei->__horizon_munaajpi){
                load_to_index(_wikimyei,c_index);
                _wikimyei->__flags->__nonuwaabo_alliu_done=___CWCN_TRUE; // #FIXME makes no sence
                // STAND FOR IMIBAJCHO MUNAAJPI
                ___imibajcho_munaajpi_hash(_wikimyei);
                break;
            }
        }while(load_go_up(_wikimyei)!=-1); // here one might try to make time go backward
        load_to_index(_wikimyei,c_index);
    }while(load_go_up(_wikimyei)!=-1);
    load_to_index(_wikimyei,start_index);
    return are_munaajpi_pending(_wikimyei);
}
void reset_load_pending_munaajpi(__wikimyei_t *_wikimyei){
    int start_index=_wikimyei->__load_index;
    load_to_start(_wikimyei); // go down
    do{
        glti(_wikimyei)->__pending_munaajpi_index=0x00;
    }while(load_go_up(_wikimyei)!=-1);
    load_to_index(_wikimyei,start_index);
    assert(are_munaajpi_pending(_wikimyei));
}
/*

*/
void print_munaajpi_w_base(__wikimyei_t *_wikimyei){
    fprintf(stdout,"%s>> > ... munaajpi_w_base: [%s",COLOR_MUNAAJPI,COLOR_REGULAR);
    for(unsigned int idx=0x00;idx<_wikimyei->__munaajpi->__munaajpi_base_w_size;idx++){
        if(!(idx%9)&&idx!=0x00){fprintf(stdout,"\n\t\t\t");}
        fprintf(stdout, "\t%.2f,",_wikimyei->__munaajpi->__munaajpi_w_base[idx]);
    }
    fprintf(stdout," %s]%s\n",COLOR_MUNAAJPI,COLOR_REGULAR);
}
void read_munaajpi_w_base(__wikimyei_t *_wikimyei){
    unsigned int m_ctx=0x00;
    #if defined(__IN_MUNAAJPI_W_BASE_ALLIU_IS_INCLUDED__) // ALLIU
    for(unsigned int idx=0x00;idx<_wikimyei->__alliu->__source_size;idx++){
        _wikimyei->__munaajpi->__munaajpi_w_base[m_ctx]=glti(_wikimyei)->__alliu_state[idx];
        m_ctx++;
    }
    #endif
    #if defined(__IN_MUNAAJPI_W_BASE_ALLIU_DUURUVA_IS_INCLUDED__) // ALLIU_DUURUVA
    #if defined(__EXPEND_ALLIU_DUURUVA__) && defined(__PROPAGATE_ALLIU_DUURUVA__)
    for(unsigned int idx=0x00;idx<_wikimyei->__wajyu->__metric->__alliu_duuruva->__duuruva_vector_size;idx++){
        _wikimyei->__munaajpi->__munaajpi_w_base[m_ctx]=glti(_wikimyei)->__alliu_duuruva_state[idx];
        m_ctx++;
    }
    #else
    fprintf(stderr,"BAD CONFIGURATION: __IN_MUNAAJPI_W_BASE_ALLIU_DUURUVA_IS_INCLUDED__ needs [__EXPEND_ALLIU_DUURUVA__ && __PROPAGATE_ALLIU_DUURUVA__]")
    assert(0x00);
    #endif
    #endif
    #if defined(__IN_MUNAAJPI_W_BASE_nonuwaaboALLIU_IS_INCLUDED__) // nonuwaaboALLIU
    for(unsigned int idx=0x00;idx<_wikimyei->__alliu->__source_size;idx++){
        _wikimyei->__munaajpi->__munaajpi_w_base[m_ctx]=glti(_wikimyei)->__nonuwaabo_alliu_state[idx];
        m_ctx++;
    }
    #endif
    #if defined(__IN_MUNAAJPI_W_BASE_UAWAABO_IS_INCLUDED__) // UWAABO
    for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo->__uwaabo_state_size;idx++){
        _wikimyei->__munaajpi->__munaajpi_w_base[m_ctx]=glti(_wikimyei)->__uwaabo_state[idx];
        m_ctx++;
    }
    #endif
    #if defined(__IN_MUNAAJPI_W_BASE_TASNE_IS_INCLUDED__) // TSANE
    for(unsigned int idx=0x00;idx<_wikimyei->__tsane->__tsane_size;idx++){
        _wikimyei->__munaajpi->__munaajpi_w_base[m_ctx]=glti(_wikimyei)->__tsane_state[idx];
        m_ctx++;
    }
    #endif
    #if defined(__IN_MUNAAJPI_W_BASE_IMIBAJCHO_MUNAAJPI_IS_INCLUDED__) // IMIBAJCHO MUNAAJPI
    _wikimyei->__munaajpi->__munaajpi_w_base[m_ctx]=glti(_wikimyei)->__imibajcho_munaajpi_state[0x00];
    m_ctx++;
    #endif
    #if defined(__IN_MUNAAJPI_W_BASE_ENTROPY_IS_INCLUDED__)
    _wikimyei->__munaajpi->__munaajpi_w_base[m_ctx]=glti(_wikimyei)->__entropy_state[0x00];
    m_ctx++;
    #endif
    assert(_wikimyei->__munaajpi->__munaajpi_base_w_size==m_ctx); // might be due to a bad #define configuration 
}
/*

*/

/*

*/
// void imibajcho_step_munaajpi(__wikimyei_t *_wikimyei){ // #FIXME broken not in use
//     for(unsigned int m_idx=0x00;m_idx<_wikimyei->__alliu->__source_size;m_idx++){
//         glti(_wikimyei)->__nonuwaabo_alliu_state[m_idx]+=g...etnext_alliu(_wikimyei->__alliu)[m_idx]/_wikimyei->__horizon_munaajpi;
//     }
// }
__cwcn_type_t sign_m_fun(__cwcn_type_t x){
    return (__cwcn_type_t)((x > 0) ? 1 : ((x < 0) ? -1 : 0));
}
void compute_imibajcho_munaajpi(__wikimyei_t *_wikimyei){ // J, meaning the state difference
    // Assumes __nonuwaabo_alliu_state is ready
    assert(_wikimyei->__flags->__nonuwaabo_alliu_done);
    assert(_wikimyei->__alliu->__source_size==1);
    glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]=0x00; // is this the problem?
    for(unsigned int m_idx=0x00;m_idx<_wikimyei->__alliu->__source_size;m_idx++){
        glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]+=\
        (glti(_wikimyei)->__nonuwaabo_alliu_state[m_idx]-\
        glti(_wikimyei)->__alliu_state[m_idx])\
        ;
        // /(__cwcn_type_t)fabs(_wikimyei->__wajyu->__metric->__alliu_duuruva->__dv_diff[m_idx].__diff_1);
    }
    glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]/=\
    (__cwcn_type_t)_wikimyei->__alliu->__source_size;
    
    #ifdef WIKIMYEI_DEBUG
    fprintf(stdout,"%s>> > load_index: [%d] ... request to compute_imibajcho_munaajpi%s\n",COLOR_MUNAAJPI,_wikimyei->__load_index,COLOR_REGULAR);
    #endif
    #ifdef MUNAAJPI_DEBUG
    fprintf(stdout,"\t[%d] %simibajcho_munaajpi_state: %.4f%s",_wikimyei->__load_index,COLOR_MUNAAJPI,glti(_wikimyei)->__imibajcho_munaajpi_state[0x00],COLOR_REGULAR);
    fprintf(stdout,"\t%s nonuwaabo_alliu_state: [ ",COLOR_ALLIU);
    for(unsigned int m_idx=0x00;m_idx<_wikimyei->__alliu->__source_size;m_idx++){
        fprintf(stdout," %.2f,",glti(_wikimyei)->__nonuwaabo_alliu_state[m_idx]);
    }
    fprintf(stdout," ]\t alliu_state: [ ");
    for(unsigned int m_idx=0x00;m_idx<_wikimyei->__alliu->__source_size;m_idx++){
        fprintf(stdout," %.2f,",glti(_wikimyei)->__alliu_state[m_idx]);
    }
    fprintf(stdout," ]%s\n",COLOR_REGULAR);
    #endif
    #ifdef MUNJAAPI_DEBUG
    printf(">> > .g. nonuwaabo alliu state:\t[");
    for(unsigned int m_idx=0x00;m_idx<_wikimyei->__alliu->__source_size;m_idx++){
        printf(" %.2f",glti(_wikimyei)->__nonuwaabo_alliu_state[m_idx]);
    }
    printf(" ]\n");
    #endif
}
void imibajcho_munaajpi_cajtucu_transformation(__wikimyei_t *_wikimyei){
    // #FIXME, enum class tsane
    // tsane_state[0] == call
    // tsane_state[1] == put
    assert(_wikimyei->__tsane->__tsane_size==0x02);
    __cwcn_type_t tsn_aux=glti(_wikimyei)->__tsane_state[0x00]-glti(_wikimyei)->__tsane_state[0x01];
    __cwcn_type_t ims_aux=sign_m_fun(glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]);
    // __cwcn_type_t ims_aux=duuruva_normalize_inindex(_wikimyei->__wajyu->__metric->__imibajcho_munaajpi_duuruva, glti(_wikimyei)->__imibajcho_munaajpi_state[0x00],0x00);
    // #if defined(__EXPEND_IMIBAJCHO_MUNAAJPI_DUURUVA__)
    // #else
    // fprintf(stdout,"WARNING: please allow for __EXPEND_IMIBAJCHO_MUNAAJPI_DUURUVA__, for a more stable cajtucu transformation\n");
    // __cwcn_type_t ims_aux=5.0*glti(_wikimyei)->__imibajcho_munaajpi_state[0x00];
    // #endif
    // ims_aux=nat_signedsigmoid_direct(10*glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]);
    /*
        Calculated as the distance of a point to a line (vlx), (line of slope 1 and intercept in zero)
    */
    __cwcn_type_t a=1;
    __cwcn_type_t b=-1;
    __cwcn_type_t c=0;
    __cwcn_type_t vlx_aux=fabs(a*tsn_aux+b*ims_aux+c)/sqrt(pow(a,2)+pow(b,2));
    /*
        Calculate the point on the line
    */
    __cwcn_type_t xlx=(b*(b*tsn_aux-a*ims_aux)-a*c)/(pow(a,2)+pow(b,2));
    __cwcn_type_t ylx=(a*(-b*tsn_aux+a*ims_aux)-b*c)/(pow(a,2)+pow(b,2));
    /*
        Calculate the distance to the origin
    */
   __cwcn_type_t dlx_aux=sqrt(pow(xlx,2)+pow(ylx,2));
    /*
        This distance is used to compute the growth slope on a cuadratic hibercolic secant space
    */
    printf("vlx_aux: %f, dlx_aux: %f, xlx:%f, ylx: %f\n",vlx_aux,dlx_aux,xlx,ylx);
    dlx_aux = 2.0-dlx_aux*1.0;
    // vlx_aux=8.0/pow(exp(-3*vlx_aux)+exp(3*vlx_aux),3);
    vlx_aux=8.0/pow(exp(-dlx_aux*vlx_aux)+exp(dlx_aux*vlx_aux),3);
    /*
        Scale and move
    */
    glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]=__IMIBAJCHO_MUNAAJPI_POTENCY__*(2.0*vlx_aux-1.0);

    // glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]=max(glti(_wikimyei)->__imibajcho_munaajpi_state[0x00],-1.0);
    // glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]=min(glti(_wikimyei)->__imibajcho_munaajpi_state[0x00],1.0);

    glti(_wikimyei)->__pending_munaajpi=___CWCN_FALSE; // means not lacking compute_imibajcho
    // #FIXME, try the experiment to normalize after ims
    printf("%s>> > load_index: [%d] : tsn: %f, ims: %f, vlx: %f, __imibajcho_munaajpi_state: %f%s\n",COLOR_MUNAAJPI,_wikimyei->__load_index,tsn_aux,ims_aux,vlx_aux,glti(_wikimyei)->__imibajcho_munaajpi_state[0x00],COLOR_REGULAR);
    #if defined(WIKIMYEI_DEBUG) || defined(MUNJAAPI_DEBUG)
        fprintf(stdout,"%s>> > load_index: [%d] ... (result of) imibajcho munaajpi cajtucu transformation: %f%s\n",COLOR_MUNAAJPI,_wikimyei->__load_index,\
            glti(_wikimyei)->__imibajcho_munaajpi_state[0x00],\
            COLOR_REGULAR);
    #endif
}

___cwcn_bool_t are_munaajpi_pending(__wikimyei_t *_wikimyei){
    
    int start_index=_wikimyei->__load_index;
    unsigned int ctx=0x00;
    ___cwcn_bool_t c_stillpending=___CWCN_FALSE;
    load_to_start(_wikimyei); // go down
    do{ // go up
        if(glti(_wikimyei)->__pending_munaajpi_index<_wikimyei->__horizon_munaajpi){
            glti(_wikimyei)->__pending_munaajpi=___CWCN_TRUE;
            c_stillpending=___CWCN_TRUE;
            ctx++;
            #ifdef MUNJAAPI_DEBUG 
            fprintf(stdout,"%s>> > load_index: [%d] ... load [%d] \t%sTRUE  %s(munaajpi_pending)%s\n",COLOR_MUNAAJPI,_wikimyei->__load_index,_wikimyei->__load_index,COLOR_DANGER,COLOR_MUNAAJPI,COLOR_REGULAR); // hug from the past
            #endif
        } else {
            #ifdef MUNJAAPI_DEBUG  
            fprintf(stdout,"%s>> > load_index: [%d] ... load [%d] \t%sFALSE %s(munaajpi_pending)%s\n",COLOR_MUNAAJPI,_wikimyei->__load_index,_wikimyei->__load_index,COLOR_B_MUNAAJPI,COLOR_MUNAAJPI,COLOR_REGULAR);
            #endif
        }
    }while(load_go_up(_wikimyei)!=-1);
    load_to_index(_wikimyei,start_index);
    #if defined(WIKIMYEI_DEBUG) || defined(MUNJAAPI_DEBUG)
    fprintf(stdout,"%s>> > load_index: [%d] ... load have still %sctx: %d munaajpi_pending%s\n",COLOR_REGULAR,_wikimyei->__load_index,COLOR_MUNAAJPI,ctx,COLOR_REGULAR);
    #endif
    return c_stillpending; // if any item in load is still pending
}
/*

*/
void print_report_munaajpi(__wikimyei_t *_wikimyei){
    fprintf(stdout,"\t THE ONE AND ONLY, REPORT MUNAAJPI:\n\t(MUNAAJPI)\n");
    fprintf(stdout,"%s",COLOR_MUNAAJPI);
    int c_index=_wikimyei->__load_index;
    // FEATURING THE IMIBAJCHO
    fprintf(stdout,"\t FEATURING THE IMIBAJCHO DUURUVA\n");
    load_to_start(_wikimyei);
    print_duuruva(_wikimyei->__wajyu->__metric->__imibajcho_munaajpi_duuruva);
    do{
        if(fabs(fabs(glti(_wikimyei)->__imibajcho_munaajpi_state[0x00])-fabs(_wikimyei->__wajyu->__metric->__imibajcho_munaajpi_duuruva->__dv_dist[0x00].__mean))>fabs(_wikimyei->__wajyu->__metric->__imibajcho_munaajpi_duuruva->__dv_dist[0x00].__std)){
            fprintf(stdout,"\t[%d] load_index:[%d]\t imibajcho_munaajpi_state:[0x00] %s%f%s\n",0x00,_wikimyei->__load_index,COLOR_DANGER,glti(_wikimyei)->__imibajcho_munaajpi_state[0x00],COLOR_MUNAAJPI);
        }else{
            fprintf(stdout,"\t[%d] load_index:[%d]\t imibajcho_munaajpi_state:[0x00] %s%f%s\n",0x00,_wikimyei->__load_index,COLOR_GOOD,glti(_wikimyei)->__imibajcho_munaajpi_state[0x00],COLOR_MUNAAJPI);
        }
    }while(load_go_up(_wikimyei)!=-1);
    // JKIMYEI UWAABO
    // fprintf(stdout,"\t FEATURING THE JKIMYEI UWAABO DUURUVA\n");
    // load_to_start(_wikimyei);
    // print_duuruva(_wikimyei->__wajyu->__metric->__jkimyei_uwaabo_duuruva);
    // do{
    //     for(unsigned int mjpi_idx=0x00;mjpi_idx<0x01;mjpi_idx++){
    //         if(fabs(fabs(glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_state[mjpi_idx])-fabs(_wikimyei->__wajyu->__metric->__jkimyei_uwaabo_duuruva->__dv_dist[mjpi_idx].__mean))>fabs(_wikimyei->__wajyu->__metric->__jkimyei_uwaabo_duuruva->__dv_dist[mjpi_idx].__std)){
    //             fprintf(stdout,"\t[%d] load_index:[%d]\t imibajcho_munaajpi_state:[0x00] %s%f%s\n",mjpi_idx,_wikimyei->__load_index,COLOR_DANGER,glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_state[mjpi_idx],COLOR_MUNAAJPI);
    //         }else{
    //             fprintf(stdout,"\t[%d] load_index:[%d]\t imibajcho_munaajpi_state:[0x00] %s%f%s\n",mjpi_idx,_wikimyei->__load_index,COLOR_GOOD,glti(_wikimyei)->__jkimyei_uwaabo_duuruva_state[mjpi_idx],COLOR_MUNAAJPI);
    //         }
    //     }
    // }while(load_go_up(_wikimyei)!=-1);
    // fprintf(stdout,"%s\n",COLOR_REGULAR);
    
    load_to_index(_wikimyei,c_index);
}
// 
void munaajpi_destroy(__munaajpi_t *_munaajpi){
    free(_munaajpi->__munaajpi_w_base);
    tsinuu_destroy(_munaajpi->__munaajpi_tsinuu);
}