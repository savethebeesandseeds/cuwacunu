#include "cwcn_wikimyei_nebajke.h"
void ___alliu_hash(__wikimyei_t *_wikimyei){
	/*	ujcamei */
	/*	 */
    // #FIXME add assertions
    if(!_wikimyei->__flags->__endhead_empty_alliu){ // #FIXME this might cause problems, if reset is forgoten
        fprintf(stdout,"%s>> > ERROR: ___alliu_hash has been set twice%s\n",COLOR_DANGER,COLOR_REGULAR);
        assert(0x00);
    }
    getnext_alliu(_wikimyei->__alliu);
    _wikimyei->__flags->__endhead_empty_alliu=___CWCN_FALSE;
    copy_c_cwcn_blocks_from_b_to_a(glti(_wikimyei)->__alliu_state, _wikimyei->__alliu->__source_value, _wikimyei->__alliu->__source_size);
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,"%s>> > load_index: [%d] ... ___alliu_hash\t [",COLOR_ALLIU,_wikimyei->__load_index);
        for(unsigned int idx=0x00;idx<_wikimyei->__alliu->__source_size;idx++){
            fprintf(stdout," %.2f",glti(_wikimyei)->__alliu_state[idx]);
        }
        fprintf(stdout," ]%s\n",COLOR_REGULAR);
    #endif
}
void ___alliu_duuruva_hash(__wikimyei_t *_wikimyei){
	/* duuruva */
	// #FIXME add assertions
    #if defined(__PROPAGATE_ALLIU_DUURUVA__) && !defined(__EXPEND_ALLIU_DUURUVA__)
    fprintf(stderr,"BAD CONFIGURATION: if defined __PROPAGATE_ALLIU_DUURUVA__ then define also __EXPEND_ALLIU_DUURUVA__")
    #endif
    #if defined(__EXPEND_ALLIU_DUURUVA__)
    set_duuruva_value(_wikimyei->__wajyu->__metric->__alliu_duuruva,glti(_wikimyei)->__alliu_state);
	diff_duuruva(_wikimyei->__wajyu->__metric->__alliu_duuruva);
	dist_duuruva(_wikimyei->__wajyu->__metric->__alliu_duuruva);
    #if defined(_DUURUVA_NORM_STAND_ALLIU_)
    fprintf(stdout,"%s",COLOR_MUNAAJPI);
    duuruva_normalize(_wikimyei->__wajyu->__metric->__alliu_duuruva,glti(_wikimyei)->__alliu_state);
    fprintf(stdout,"%s",COLOR_REGULAR);
    #endif
    #if defined(__PROPAGATE_ALLIU_DUURUVA__)
    #if defined(_DUURUVA_NORM_STAND_ALLIU_)
    read_duuruva_vector(_wikimyei->__wajyu->__metric->__alliu_duuruva,glti(_wikimyei)->__alliu_duuruva_state,0x01);
    #else
    read_duuruva_vector(_wikimyei->__wajyu->__metric->__alliu_duuruva,glti(_wikimyei)->__alliu_duuruva_state,0x00);
    #endif
    for(unsigned int idx=0x00; idx<BUGGER_SIZE_DUURUVA; idx++){ // apply uwaabo mask
        glti(_wikimyei)->__alliu_duuruva_state[idx]=\
            _ALLIU_DUURUVA_MASK_[idx]*glti(_wikimyei)->__alliu_duuruva_state[idx];
    }
    #if defined(WIKIMYEI_DEBUG) || defined(UWAABO_DEBUG)
    fprintf(stdout,"%s>> > load_index: [%d] ... alliu duuruva state: [",COLOR_ALLIU,_wikimyei->__load_index);
    for(unsigned int idx=0x00;idx<_wikimyei->__wajyu->__metric->__alliu_duuruva->__duuruva_vector_size;idx++){
        fprintf(stdout," %.2f",glti(_wikimyei)->__alliu_duuruva_state[idx]);
    }
    fprintf(stdout," ]%s\n",COLOR_REGULAR);
    #endif
    #endif
    #endif
}
void ___uwaabo_hash(__wikimyei_t *_wikimyei){
    /*	tsinuu */
    /*	 */
    // #FIXME add assertions
    read_uwaabo_w_base(_wikimyei);
    set_tsinuu_input(_wikimyei->__uwaabo->__uwaabo_tsinuu, _wikimyei->__uwaabo->__uwaabo_w_base);
    tsinuu_direct_uwaabo_full_parametric(_wikimyei->__uwaabo->__uwaabo_tsinuu);
    read_tsinuu_output(_wikimyei->__uwaabo->__uwaabo_tsinuu, glti(_wikimyei)->__uwaabo_state);
    #if defined(__EXPEND_UWABO_DUURUVA__)
    set_duuruva_value(_wikimyei->__wajyu->__metric->__uwaabo_duuruva,glti(_wikimyei)->__uwaabo_state);
	diff_duuruva(_wikimyei->__wajyu->__metric->__uwaabo_duuruva);
	dist_duuruva(_wikimyei->__wajyu->__metric->__uwaabo_duuruva);
    #endif
    #if defined(WIKIMYEI_DEBUG) || defined(UWAABO_DEBUG)
    fprintf(stdout,"%s>> > load_index: [%d] ... request uwaabo_hash\t uwaabo_state: [",COLOR_UWAABO,_wikimyei->__load_index);
    for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo->__uwaabo_state_size;idx++){
        fprintf(stdout," %.2f",glti(_wikimyei)->__uwaabo_state[idx]);
    }
    fprintf(stdout," ]%s\n",COLOR_REGULAR);
    #endif
}
void ___entropy_hash(__wikimyei_t *_wikimyei){
	/*	entropy */
	/*	 */
    // #FIXME add assertions
    _wikimyei->__ec->__forward(_wikimyei->__ec, glti(_wikimyei)->__uwaabo_state);
    glti(_wikimyei)->__entropy_state[0x00]=_wikimyei->__ec->__entropy; // #FIXME asigment is safe for now cus' entropy is scalar
    #if defined(__EXPEND_ENTROPY_DUURUVA__)
    set_duuruva_value(_wikimyei->__wajyu->__metric->__entropy_duuruva,glti(_wikimyei)->__entropy_state);
	diff_duuruva(_wikimyei->__wajyu->__metric->__entropy_duuruva);
	dist_duuruva(_wikimyei->__wajyu->__metric->__entropy_duuruva);
    #endif
    #ifdef WIKIMYEI_DEBUG
    fprintf(stdout,">> > load_index: [%d] ... ___entropy_hash,\tentropy:%f\n",_wikimyei->__load_index,glti(_wikimyei)->__entropy_state[0x00]);
    #endif
}
void ___tsane_dehash(__wikimyei_t *_wikimyei){
	/*  entropy */
	/*	 */
    // #FIXME add assertions
    __cwcn_type_t c_sum=0x00;
    unsigned int idx;
    unsigned int ctx=0x00;
    __cwcn_type_t _bern_dude=0x00;
    __cwcn_type_t *c_tsane_nondecimal=malloc(_wikimyei->__tsane->__tsane_size*sizeof(__cwcn_type_t));
    for(idx=0x00;idx<_wikimyei->__tsane->__tsane_size;idx++){
        glti(_wikimyei)->__tsane_state[idx]=_wikimyei->__ec->__tsane[idx];
        c_tsane_nondecimal[idx]=glti(_wikimyei)->__tsane_state[idx]/0.01;
    }
    #if defined(__EXPEND_TSANE_DUURUVA__)
    set_duuruva_value(_wikimyei->__wajyu->__metric->__tsane_duuruva,glti(_wikimyei)->__tsane_state);
	diff_duuruva(_wikimyei->__wajyu->__metric->__tsane_duuruva);
	dist_duuruva(_wikimyei->__wajyu->__metric->__tsane_duuruva);
    #endif
    for(idx=0x00;idx<_wikimyei->__tsane->__tsane_size;idx++){
        // glti(_wikimyei)->__tsane_log_prob=log(glti(_wikimyei)->__tsane_state[idx]); // #FIXME not, is uwaabo state instead
        c_sum+=c_tsane_nondecimal[idx];//*_wikimyei->__tsane->__tsane_size; //#FIXME
    }
    idx=0x00;
    while(0x01){ // #FIXME, save the action
        ctx++;
        _bern_dude=(__cwcn_type_t)(rand()%(int)c_sum);
        #if defined(WIKIMYEI_DEBUG) || defined(ENTROPY_DEBUG)
        printf("%s-- - dehash experiemnt [%d]: attempt: [%d], \t%srvalue: %f > %f\n",COLOR_TSANE, idx, ctx, COLOR_REGULAR,c_tsane_nondecimal[idx], _bern_dude);
        #endif
        if(c_tsane_nondecimal[idx]>_bern_dude){break;}
        else{idx++;}
        if(idx>=_wikimyei->__tsane->__tsane_size){idx=0x00;}// undependent bernouly or whatever
    }
    // #FIXME ... include take_tsane bool setence
    #if defined(WIKIMYEI_DEBUG) || defined(ENTROPY_DEBUG)
        fprintf(stdout,"%s>> > load_index: [%d] ... ___tsane_dehash\n",COLOR_TSANE,_wikimyei->__load_index);
        fprintf(stdout,"-- - tsane selected==%d, found in ctx: %d, with sum: %d and tsane values:\t[",idx, ctx,(int)c_sum);
        for(unsigned int idx=0x00;idx<_wikimyei->__tsane->__tsane_size;idx++){
            fprintf(stdout," %.2f",glti(_wikimyei)->__tsane_state[idx]);
        }
        fprintf(stdout," ]%s\n",COLOR_REGULAR);
    #endif
    #if defined(ENTROPY_DEBUG_v2)
    _wikimyei->__ec->__print(_wikimyei->__ec,2);
    #elif defined(ENTROPY_DEBUG_v1)
    _wikimyei->__ec->__print(_wikimyei->__ec,1);
    #elif defined(ENTROPY_DEBUG)
    _wikimyei->__ec->__print(_wikimyei->__ec,0);
    #endif
    free(c_tsane_nondecimal);
}
void ___jkimyei_uwaabo_munaajpi_hash(__wikimyei_t *_wikimyei){
	/*	tsinuu (entropy) */
	/*	tsinuu */
	/*	 */
    // #FIXME add assertions
    read_munaajpi_w_base(_wikimyei);
    set_tsinuu_input(_wikimyei->__munaajpi->__munaajpi_tsinuu, _wikimyei->__munaajpi->__munaajpi_w_base);
	tsinuu_direct_uwaabo_full_parametric(_wikimyei->__munaajpi->__munaajpi_tsinuu);
    read_tsinuu_output(_wikimyei->__munaajpi->__munaajpi_tsinuu, glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_state);
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,"%s>> > load_index: [%d] ... request jkimyei uwaabo munaajpi_hash:\n",COLOR_MUNAAJPI,_wikimyei->__load_index);
        fprintf(stdout,">> > load_index: [%d] ... jkimyei uwaabo munaajpi_state: [",_wikimyei->__load_index);
        for(unsigned int idx=0x00;idx<_wikimyei->__jkimyei_uwaabo_munaajpi_state_size;idx++){
            fprintf(stdout," %.2f",glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_state[idx]);
        }
        fprintf(stdout," ]%s\n",COLOR_REGULAR);
    #endif
}
void ___jkimyei_uwaabo_munaajpi_duuruva_hash(__wikimyei_t *_wikimyei){
	/*	duuruva */
	/*	 */
    // #FIXME add assertions
    #if defined(__PROPAGATE_JKIMYEI_UWAABO_MUNAAJPI_DUURUVA__) && !defined(__EXPEND_IMIBAJCHO_MUNAAJPI_DUURUVA__)
    fprintf(stderr,"BAD CONFIGURATION: if defined __PROPAGATE_JKIMYEI_UWAABO_MUNAAJPI_DUURUVA__ then define also __EXPEND_IMIBAJCHO_MUNAAJPI_DUURUVA__")
    #endif
    #if defined(__EXPEND_IMIBAJCHO_MUNAAJPI_DUURUVA__)
    set_duuruva_value(_wikimyei->__wajyu->__jkimyei_uwaabo_munaajpi_duuruva, glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_state);
    diff_duuruva(_wikimyei->__wajyu->__jkimyei_uwaabo_munaajpi_duuruva);
    dist_duuruva(_wikimyei->__wajyu->__jkimyei_uwaabo_munaajpi_duuruva);
    #if defined(_DUURUVA_NORM_STAND_JKIMYEI_UWAABO_)
    fprintf(stdout,"%s",COLOR_MUNAAJPI);
    duuruva_normalize(_wikimyei->__wajyu->__jkimyei_uwaabo_munaajpi_duuruva, glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_state);
    fprintf(stdout,"%s",COLOR_REGULAR);
    #endif
    #if defined(__PROPAGATE_JKIMYEI_UWAABO_MUNAAJPI_DUURUVA__)
    #if defined(_DUURUVA_NORM_STAND_JKIMYEI_UWAABO_)
    read_duuruva_vector(_wikimyei->__wajyu->__jkimyei_uwaabo_munaajpi_duuruva, glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_duuruva_state,0x01);
    #else
    read_duuruva_vector(_wikimyei->__wajyu->__jkimyei_uwaabo_munaajpi_duuruva, glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_duuruva_state,0x00);
    #endif
    for(unsigned int idx=0x00; idx<BUGGER_SIZE_DUURUVA; idx++){ // apply uwaabo mask
        glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_duuruva_state[idx]=\
            _IMIBAJCHO_MUNAAJPI_DUURUVA_MASK_[idx]*glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_duuruva_state[idx];
    }
    #if defined(WIKIMYEI_DEBUG) || defined(MUNAAJPI_DEBUG)
        fprintf(stdout,"%s>> > load_index: [%d] ... munaajpi duuruva hash:\t [",COLOR_MUNAAJPI,_wikimyei->__load_index);
        for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo->__munaajpi_duuruva_state_size;idx++){
            fprintf(stdout," %.2f",glti(_wikimyei)->__jkimyei_uwaabo_munaajpi_duuruva_state[idx]);
        }
        fprintf(stdout," ]%s\n",COLOR_REGULAR);
    #endif
    #endif
    #endif
}
void ___imibajcho_munaajpi_hash(__wikimyei_t *_wikimyei){
    compute_imibajcho_munaajpi(_wikimyei);
    imibajcho_munaajpi_cajtucu_transformation(_wikimyei);
    #if defined(__EXPEND_IMIBAJCHO_MUNAAJPI_DUURUVA__)
    set_duuruva_value(_wikimyei->__wajyu->__metric->__imibajcho_munaajpi_duuruva,glti(_wikimyei)->__imibajcho_munaajpi_state);
    diff_duuruva(_wikimyei->__wajyu->__metric->__imibajcho_munaajpi_duuruva);
    dist_duuruva(_wikimyei->__wajyu->__metric->__imibajcho_munaajpi_duuruva);
    #endif
}
/*

*/

// void load_first_nonuwaabo(__wikimyei_t *_wikimyei){
//     assert(glti(_wikimyei)->__nonuwaabo_alliu_state==NULL);
//     glti(_wikimyei)->__nonuwaabo_alliu_state=0x00;
//     for(unsigned int idx=0x00;idx<_wikimyei->__horizon_munaajpi;idx++){
//         imibajcho_step_munaajpi(_wikimyei);
//         ...
//     }
// }

/*
*/

/*
    NEBAJKE ACTUAL FUNCTIONS
*/
void wikimyei_relive_one(__wikimyei_t *_wikimyei){
    // #FIXME add assertions
    assert(_wikimyei->__flags->__done);
    assert(glti(_wikimyei)->__pending_munaajpi_index<=_wikimyei->__horizon_munaajpi); // no live requires munaajpi done
    #ifdef WIKIMYEI_DEBUG
    fprintf(stdout,">> > ... %s wikimyei_[RE]-live_one --- --- --- --- --- --- --- --- --- --- --- LOAD: %s%d\n",COLOR_DANGER,COLOR_REGULAR,_wikimyei->__load_size);
    fprintf(stdout,">> > ... load_index: [%d] ... wikimyei_relive_one\n",_wikimyei->__load_index);
    #endif
    _wikimyei->__flags->__done=___CWCN_FALSE;
    ___alliu_duuruva_hash(_wikimyei); //for duuruva update porpouses, must be defined activated
    ___uwaabo_hash(_wikimyei);
    ___entropy_hash(_wikimyei);
    ___tsane_dehash(_wikimyei); // #FIXME maybe one wants to keep track
    // # no set pending munaajpi seems correct
    _wikimyei->__flags->__done=___CWCN_TRUE;
}
void wikimyei_live_one(__wikimyei_t *_wikimyei){
    // #FIXME add assertions
    #ifdef WIKIMYEI_DEBUG
    fprintf(stdout,">> > ... %s wikimyei_live_one --- --- --- --- --- --- --- --- --- --- --- LOAD: %s%d\n",COLOR_DANGER,COLOR_REGULAR,_wikimyei->__load_size);
    fprintf(stdout,">> > ... load_index: [%d] ... wikimyei_live_one\n",_wikimyei->__load_index);
    #endif
    #ifdef WIKIMYEI_DEBUG
    fprintf(stdout,">> > ... load_index: [%d] ... starting with flags:\n",_wikimyei->__load_index);
    printflags(_wikimyei);
    #endif
    assert(!yield_next_trayectory(_wikimyei)); // mallocs the next item
    _wikimyei->__flags->__done=___CWCN_FALSE;
    // clock_t begin;
    // clock_t end;
    ___alliu_hash(_wikimyei);
    ___alliu_duuruva_hash(_wikimyei); // defined activated
    ___uwaabo_hash(_wikimyei);
    ___entropy_hash(_wikimyei);
    ___tsane_dehash(_wikimyei);
    // begin=clock();
    // end=clock();
    // printf("\033[1;31m exe time [___tsane_dehash] %f:\033[0m\n", (double)(end-begin)/CLOCKS_PER_SEC);
    set_load_pending_munaajpi(_wikimyei);
    _wikimyei->__flags->__done=___CWCN_TRUE;
}
/*
    WIKIMYEI ON LOADS
*/
void wikimyei_live_load(__wikimyei_t *_wikimyei, int _size_of_load){
    // #FIXME add assertions
    #ifdef WIKIMYEI_DEBUG
    fprintf(stdout,">> > ... request to [live_load]\n");
    #endif
    if(!load_is_empty(_wikimyei)){
        #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > ... load found %s[not empty]%s -> ask to kill current load\n",COLOR_WARNING,COLOR_REGULAR);
        #endif
        kill_load(_wikimyei);
    }
    #ifdef WIKIMYEI_DEBUG
    else{fprintf(stdout,">> > ... load found [empty]\n");}
    #endif
    assert(load_is_empty(_wikimyei));
    // clock_t begin;
    // clock_t end;
    while(_wikimyei->__load_size<_size_of_load){
        if(_wikimyei->__load_index%100==0){fprintf(stdout, ">> > ... living load index: [%d]\n",_wikimyei->__load_index);}
        wikimyei_live_one(_wikimyei);
        // begin=clock();
        // end=clock();
        // printf("\033[1;31m exe time [wikimyei_live_one] %f:\033[0m\n", (double)(end-begin)/CLOCKS_PER_SEC);
    }
    assert(!load_is_empty(_wikimyei));
    assert(_wikimyei->__load_size==_size_of_load);
}

void wikimyei_relive_load(__wikimyei_t *_wikimyei){
    // #FIXME add assertions
    assert(_wikimyei->__load_size>0);
    assert(!load_is_empty(_wikimyei));
    if(_wikimyei->__load_size<BUGGER_READY_DUURUVA_COUNT){
        fprintf(stdout,">> > %sWARNING\t%s load size too small for duuruva ready state...\n",COLOR_WARNING,COLOR_REGULAR);
    }
    load_to_start(_wikimyei);
    do{
        if(_wikimyei->__load_index%100==0){
            fprintf(stdout, ">> > ... re-living load index: [%d]\n",_wikimyei->__load_index);
        }
        wikimyei_relive_one(_wikimyei);
    }while(_wikimyei->__load_index<_wikimyei->__load_size);
}
/*

*/