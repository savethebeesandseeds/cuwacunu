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
        for(unsigned int idx=0x00;idx<_wikimyei->__alliu_state_size;idx++){
            fprintf(stdout," %.2f",glti(_wikimyei)->__alliu_state[idx]);
        }
        fprintf(stdout," ]%s\n",COLOR_REGULAR);
    #endif
}
void ___alliu_duuruva_hash(__wikimyei_t *_wikimyei){
	/*	duuruva */
	/*	 */
    // #FIXME add assertions
    set_duuruva_value(_wikimyei->__alliu_duuruva,glti(_wikimyei)->__alliu_state);
	dist_duuruva(_wikimyei->__alliu_duuruva);
    if(_wikimyei->__flags->__norm_stand){
        fprintf(stdout,"%s",COLOR_MUNAAJPI);
        duuruva_normalize(_wikimyei->__alliu_duuruva,glti(_wikimyei)->__alliu_state);
        fprintf(stdout,"%s",COLOR_REGULAR);
    }
    read_duuruva_vector(_wikimyei->__alliu_duuruva,glti(_wikimyei)->__alliu_duuruva_state,_wikimyei->__flags->__norm_stand);
    _wikimyei->__flags->__alliu_duuruva_ready=is_duuruva_ready(_wikimyei->__alliu_duuruva);
    #ifdef DEBUG_DUURUVA
	fprintf(stdout,"%s>> > load_index: [%d] ... request ___alliu_duuruva_hash:\n",COLOR_ALLIU,_wikimyei->__load_index);
    print_duuruva(_wikimyei->__alliu_duuruva);
    #endif
    #ifdef WIKIMYEI_DEBUG
    fprintf(stdout,"%s>> > load_index: [%d] ... alliu duuruva state: [",COLOR_ALLIU,_wikimyei->__load_index);
    for(unsigned int idx=0x00;idx<_wikimyei->__alliu_duuruva_state_size;idx++){
        fprintf(stdout," %.2f",glti(_wikimyei)->__alliu_duuruva_state[idx]);
    }
    fprintf(stdout," ]%s\n",COLOR_REGULAR);
    #endif
}
void ___uwaabo_hash(__wikimyei_t *_wikimyei){
	/*	tsinuu */
	/*	 */
    // #FIXME add assertions
    set_input(_wikimyei->__uwaabo, glti(_wikimyei)->__alliu_duuruva_state);
	tsinuu_direct_uwaabo_full_parametric(_wikimyei->__uwaabo);
	read_output(_wikimyei->__uwaabo, glti(_wikimyei)->__uwaabo_state);
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,"%s>> > load_index: [%d] ... request uwaabo_hash\t uwaabo_state: [",COLOR_UWAABO,_wikimyei->__load_index);
        for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo_state_size;idx++){
            fprintf(stdout," %.2f",glti(_wikimyei)->__uwaabo_state[idx]);
        }
        fprintf(stdout," ]%s\n",COLOR_REGULAR);
    #endif
}
void ___entropy_hash(__wikimyei_t *_wikimyei){
	/*	entropy */
	/*	 */
    // #FIXME add assertions
    printf("waka dao\n");
    printf("waka din 2.0 head: %p, tryry: %p, sizeof trayectory pointer %ld, sizeof queue pointer: %ld\n",_wikimyei->__load_head,_wikimyei->__load_head->__trayectory_item,sizeof(__trayectory_t), sizeof(__load_queue_t));
    printf("waka diybke  glti(_wikimyei): %p, glti(_wikimyei)->__uwaabo_state: %p\n",glti(_wikimyei),glti(_wikimyei)->__uwaabo_state);
    _wikimyei->__ec->__forward(_wikimyei->__ec, glti(_wikimyei)->__uwaabo_state);
    printf("waka din\n");
    printf("waka diybke  glti(_wikimyei): %p\n",glti(_wikimyei));
    printf("waka din 2 head: %p, tryry: %p, sizeof trayectory pointer %ld, sizeof queue pointer: %ld\n",_wikimyei->__load_head,_wikimyei->__load_head->__trayectory_item,sizeof(__trayectory_t), sizeof(__load_queue_t));
    printf("waka diybke  glti(_wikimyei)->__uwaabo_state: %p\n",glti(_wikimyei)->__uwaabo_state);
    printf("waka diybke  glti(_wikimyei)->__uwaabo_state: %p\n",glti(_wikimyei)->__uwaabo_state);
    printf("waka din 1 %f\n",_wikimyei->__ec->__entropy);
    printf("waka din 3 %f\n",glti(_wikimyei)->__entropy);
    glti(_wikimyei)->__entropy=_wikimyei->__ec->__entropy;
    printf("waka tao\n");
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > load_index: [%d] ... ___entropy_hash,\tentropy:%f\n",_wikimyei->__load_index,glti(_wikimyei)->__entropy);
    #endif
}
void ___tsane_dehash(__wikimyei_t *_wikimyei){
	/*  entropy */
	/*	 */
    // #FIXME add assertions
    glti(_wikimyei)->__tsane_state=_wikimyei->__ec->__tsane;
    __cwcn_type_t c_sum=0x00;
    unsigned int idx;
    unsigned int ctx=0x00;
    __cwcn_type_t _bern_dude=0x00;
    __cwcn_type_t *c_tsane_nondecimal=malloc(_wikimyei->__tsane_state_size*sizeof(__cwcn_type_t));
    for(idx=0x00;idx<_wikimyei->__tsane_state_size;idx++){
        c_tsane_nondecimal[idx]=glti(_wikimyei)->__tsane_state[idx]/0.01;
    }
    for(idx=0x00;idx<_wikimyei->__tsane_state_size;idx++){
        // glti(_wikimyei)->__tsane_log_prob=log(glti(_wikimyei)->__tsane_state[idx]); // #FIXME not, is uwaabo state instead
        c_sum+=c_tsane_nondecimal[idx];//*_wikimyei->__tsane_state_size; //#FIXME
    }
    idx=0x00;
    while(0x01){ // #FIXME, save the action
        ctx++;
        _bern_dude=(__cwcn_type_t)(rand()%(int)c_sum);
        #ifdef WIKIMYEI_DEBUG
        printf("%s-- - dehash experiemnt [%d]: attempt: [%d], \t%srvalue: %f > %f\n",COLOR_TSANE, idx, ctx, COLOR_REGULAR,c_tsane_nondecimal[idx], _bern_dude);
        #endif
        if(c_tsane_nondecimal[idx]>_bern_dude){break;}
        else{idx++;}
        if(idx>=_wikimyei->__tsane_state_size){idx=0x00;}// undependent bernouly or whatever
    }
    // #FIXME ... include take_tsane bool setence
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,"%s>> > load_index: [%d] ... ___tsane_dehash\n",COLOR_TSANE,_wikimyei->__load_index);
        fprintf(stdout,"-- - tsane selected==%d, found in ctx: %d, with sum: %d and tsane values:\t[",idx, ctx,(int)c_sum);
        for(unsigned int idx=0x00;idx<_wikimyei->__tsane_state_size;idx++){
            fprintf(stdout," %.2f",glti(_wikimyei)->__tsane_state[idx]);
        }
        fprintf(stdout," ]%s\n",COLOR_REGULAR);
    #endif
    #ifdef WIKIMYEI_DEBUG_v3
    _wikimyei->__ec->__print(_wikimyei->__ec);
    #endif
    free(c_tsane_nondecimal);
}
void ___munaajpi_hash(__wikimyei_t *_wikimyei){
	/*	tsinuu (entropy) */
	/*	tsinuu */
	/*	 */
    // #FIXME add assertions
    read_munaajpi_w_base(_wikimyei);
    set_input(_wikimyei->__munaajpi, _wikimyei->__munaajpi_base_w_state);
	tsinuu_direct_uwaabo_full_parametric(_wikimyei->__munaajpi);
    read_output(_wikimyei->__munaajpi, glti(_wikimyei)->__munaajpi_state);
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,"%s>> > load_index: [%d] ... request munaajpi_hash:\n",COLOR_MUNAAJPI,_wikimyei->__load_index);
        fprintf(stdout,">> > load_index: [%d] ... munaajpi_state: [",_wikimyei->__load_index);
        for(unsigned int idx=0x00;idx<_wikimyei->__munaajpi_state_size;idx++){
            fprintf(stdout," %.2f",glti(_wikimyei)->__munaajpi_state[idx]);
        }
        fprintf(stdout," ]%s\n",COLOR_REGULAR);
    #endif
}
void ___munaajpi_duuruva_hash(__wikimyei_t *_wikimyei){
	/*	duuruva */
	/*	 */
    // #FIXME add assertions
    set_duuruva_value(_wikimyei->__munaajpi_duuruva, glti(_wikimyei)->__imibajcho_munaajpi_state);
    dist_duuruva(_wikimyei->__munaajpi_duuruva);
    if(_wikimyei->__flags->__norm_stand){
        fprintf(stdout,"%s",COLOR_MUNAAJPI);
        duuruva_normalize(_wikimyei->__munaajpi_duuruva, glti(_wikimyei)->__imibajcho_munaajpi_state);
        fprintf(stdout,"%s",COLOR_REGULAR);
    }
    read_duuruva_vector(_wikimyei->__munaajpi_duuruva, glti(_wikimyei)->__imibajcho_munaajpi_duuruva_state,_wikimyei->__flags->__norm_stand);
    #ifdef DEBUG_DUURUVA
    fprintf(stdout,"%s>> > load_index: [%d] ... request munaajpi_duuruva_hash:\n",COLOR_MUNAAJPI,_wikimyei->__load_index);
    fprintf(stdout,">> > load_index: [%d] ... MUNAAJPI DUURUVA STATE:\n",_wikimyei->__load_index);
    print_duuruva(_wikimyei->__munaajpi_duuruva);
    #endif
    _wikimyei->__flags->__munaajpi_duuruva_ready=is_duuruva_ready(_wikimyei->__munaajpi_duuruva);
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,"%s>> > load_index: [%d] ... munaajpi duuruva hash:\t [",COLOR_MUNAAJPI,_wikimyei->__load_index);
        for(unsigned int idx=0x00;idx<_wikimyei->__munaajpi_duuruva_state_size;idx++){
            fprintf(stdout," %.2f",glti(_wikimyei)->__imibajcho_munaajpi_duuruva_state[idx]);
        }
        fprintf(stdout," ]%s\n",COLOR_REGULAR);
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
    ___alliu_duuruva_hash(_wikimyei); //for duuruva update porpouses
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
    printf(">> > ... load_index: [%d] ... request to enqueue...\n",_wikimyei->__load_index);
    assert(!load_enqueue_trayectory(_wikimyei, trayectory_fabric(_wikimyei)));
    _wikimyei->__flags->__done=___CWCN_FALSE;
    // clock_t begin;
    // clock_t end;
    printf("waka din 2 head: %p, tryry: %p, sizeof trayectory pointer %ld, sizeof queue pointer: %ld\n",_wikimyei->__load_head,_wikimyei->__load_head->__trayectory_item,sizeof(__trayectory_t), sizeof(__load_queue_t));
    ___alliu_hash(_wikimyei);
    printf("waka din 2 head: %p, tryry: %p, sizeof trayectory pointer %ld, sizeof queue pointer: %ld\n",_wikimyei->__load_head,_wikimyei->__load_head->__trayectory_item,sizeof(__trayectory_t), sizeof(__load_queue_t));
    ___alliu_duuruva_hash(_wikimyei);
    printf("waka din 2 head: %p, tryry: %p, sizeof trayectory pointer %ld, sizeof queue pointer: %ld\n",_wikimyei->__load_head,_wikimyei->__load_head->__trayectory_item,sizeof(__trayectory_t), sizeof(__load_queue_t));
    ___uwaabo_hash(_wikimyei);
    printf("waka din 2 head: %p, tryry: %p, sizeof trayectory pointer %ld, sizeof queue pointer: %ld\n",_wikimyei->__load_head,_wikimyei->__load_head->__trayectory_item,sizeof(__trayectory_t), sizeof(__load_queue_t));
    ___entropy_hash(_wikimyei);
    printf("waka din 2 head: %p, tryry: %p, sizeof trayectory pointer %ld, sizeof queue pointer: %ld\n",_wikimyei->__load_head,_wikimyei->__load_head->__trayectory_item,sizeof(__trayectory_t), sizeof(__load_queue_t));
    ___tsane_dehash(_wikimyei);
    // begin=clock();
    // end=clock();
    // printf("\033[1;31m exe time [___tsane_dehash] %f:\033[0m\n", (double)(end-begin)/CLOCKS_PER_SEC);
    set_load_pending_munaajpi(_wikimyei);
    _wikimyei->__flags->__done=___CWCN_TRUE;
}
/*

*/
void wikimyei_live_load(__wikimyei_t *_wikimyei, int _size_of_load){
    // #FIXME add assertions
    assert(_size_of_load>0);
    empty_load(_wikimyei);
    printf("%s ENTER TO PRINT TRAYECOTRY POINTERS (after empty):%s\n",COLOR_GOOD,COLOR_REGULAR);
    getchar();
    load_print_up_trayectory_pointers(_wikimyei);
    getchar();
    if(_size_of_load<BUGGER_READY_DUURUVA_COUNT){fprintf(stdout,">> > %sWARNING\t%s w load size too small for duuruva ready state...\n",COLOR_WARNING,COLOR_REGULAR);}
    load_to_start(_wikimyei);
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