#include "cwcn_wikimyei_nebajke.h"
void ___alliu_hash(__wikimyei_t *_wikimyei){
	/*	ujcamei */
	/*	 */
    if(!_wikimyei->__flags->__endhead_empty_alliu){ // #FIXME this might cause problems, if reset is forgoten
        fprintf(stdout,">> > ERROR: ___alliu_hash has been set twice\n");
        assert(0x00);
    }
    getnext_alliu(_wikimyei->__alliu);
    _wikimyei->__flags->__endhead_empty_alliu=___CWCN_FALSE;
    copy_c_cwcn_blocks_from_b_to_a(glti(_wikimyei)->__alliu_state, _wikimyei->__alliu->__source_value, _wikimyei->__alliu->__source_size);
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > ... ___alliu_hash\t [");
        for(unsigned int idx=0x00;idx<_wikimyei->__alliu_state_size;idx++){
            fprintf(stdout," %.2f",glti(_wikimyei)->__alliu_state[idx]);
        }
        fprintf(stdout," ]\n");
    #endif
}
void ___alliu_duuruva_hash(__wikimyei_t *_wikimyei){
	/*	duuruva */
	/*	 */
    set_duuruva_value(_wikimyei->__alliu_duuruva, glti(_wikimyei)->__alliu_state);
	dist_duuruva(_wikimyei->__alliu_duuruva);
    #ifdef DEBUG_DUURUVA
	fprintf(stdout,"__ALLIU_DUURUVA:\n");
    print_duuruva(_wikimyei->__alliu_duuruva);
    #endif
	read_duuruva_vector(_wikimyei->__alliu_duuruva,glti(_wikimyei)->__alliu_duuruva_state);
    _wikimyei->__flags->__alliu_duuruva_ready=is_duuruva_ready(_wikimyei->__alliu_duuruva);
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > ... ___alliu_duuruva_hash\t [");
        for(unsigned int idx=0x00;idx<_wikimyei->__alliu_duuruva_state_size;idx++){
            fprintf(stdout," %.2f",glti(_wikimyei)->__alliu_duuruva_state[idx]);
        }
        fprintf(stdout," ]\n");
    #endif
}
void ___uwaabo_hash(__wikimyei_t *_wikimyei){
	/*	tsinuu */
	/*	 */
    set_input(_wikimyei->__uwaabo, glti(_wikimyei)->__alliu_duuruva_state);
	tsinuu_direct_uwaabo_full_parametric(_wikimyei->__uwaabo);
	read_output(_wikimyei->__uwaabo, glti(_wikimyei)->__uwaabo_state);
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > ... ___uwaabo_hash\t [");
        for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo_state_size;idx++){
            fprintf(stdout," %.2f",glti(_wikimyei)->__uwaabo_state[idx]);
        }
        fprintf(stdout," ]\n");
    #endif
}
void ___entropy_hash(__wikimyei_t *_wikimyei){
	/*	entropy */
	/*	 */
    _wikimyei->__ec->__forward(_wikimyei->__ec, glti(_wikimyei)->__uwaabo_state);
    glti(_wikimyei)->__entropy=_wikimyei->__ec->__entropy;
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > ... ___entropy_hash,\tentropy:%f\n",glti(_wikimyei)->__entropy);
    #endif
}
void ___tsane_dehash(__wikimyei_t *_wikimyei){
	/*  entropy */
	/*	 */
    glti(_wikimyei)->__tsane_state=_wikimyei->__ec->__tsane;
    __cwcn_type_t c_sum=0x00;
    unsigned int idx;
    unsigned int ctx=0x00;
    __cwcn_type_t c_bern=0x00;
    for(idx=0x00;idx<_wikimyei->__tsane_state_size;idx++){
        // glti(_wikimyei)->__tsane_log_prob=log(glti(_wikimyei)->__tsane_state[idx]); // #FIXME not, is uwaabo state instead
        c_sum+=glti(_wikimyei)->__tsane_state[idx]/0.01;//*_wikimyei->__tsane_state_size;
    }
    idx=0x00;
    while(0x01){ // #FIXME, save the action
        ctx++;
        c_bern=(__cwcn_type_t)(rand()%(int)c_sum);
        #ifdef WIKIMYEI_DEBUG
            printf("--- dehash experiemnt: %f > %f\n", glti(_wikimyei)->__tsane_state[idx]/0.01, c_bern);
        #endif
        if(glti(_wikimyei)->__tsane_state[idx]/0.01>c_bern){
            break;
        }else{
            idx++;
        }if(idx>=_wikimyei->__tsane_state_size){
            idx=0x00;
        }// undependent bernouly or whatever
    }
    // #FIXME ... include take_tsane bool setence
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > ... ___tsane_dehash\t");
        fprintf(stdout,"tsane selected==%d, found in ctx: %d, with sum: %d and tsane values:\t[",idx, ctx,(int)c_sum);
        for(unsigned int idx=0x00;idx<_wikimyei->__tsane_state_size;idx++){
            fprintf(stdout," %.2f",glti(_wikimyei)->__tsane_state[idx]);
        }
        fprintf(stdout," ]\n");
    #endif
    #ifdef WIKIMYEI_DEBUG_v3
        _wikimyei->__ec->__print(_wikimyei->__ec);
    #endif
}
void ___munaajpi_hash(__wikimyei_t *_wikimyei){
	/*	tsinuu (entropy) */
	/*	tsinuu */
	/*	 */
    read_munaajpi_w_base(_wikimyei);
    set_input(_wikimyei->__munaajpi, _wikimyei->__munaajpi_base_w_state);
	tsinuu_direct_uwaabo_full_parametric(_wikimyei->__munaajpi);
    read_output(_wikimyei->__munaajpi, glti(_wikimyei)->__munaajpi_state);
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,"\x1B[0;33m>> > ... ___munaajpi_hash\t [");
        for(unsigned int idx=0x00;idx<_wikimyei->__munaajpi_state_size;idx++){
            fprintf(stdout," %.2f",glti(_wikimyei)->__munaajpi_state[idx]);
        }
        fprintf(stdout," ]\033[0m\n");
    #endif
}
void ___munaajpi_duuruva_hash(__wikimyei_t *_wikimyei){
	/*	duuruva */
	/*	 */
    set_duuruva_value(_wikimyei->__munaajpi_duuruva, glti(_wikimyei)->__imibajcho_munaajpi_state);
    dist_duuruva(_wikimyei->__munaajpi_duuruva);
    read_duuruva_vector(_wikimyei->__munaajpi_duuruva, glti(_wikimyei)->__imibajcho_munaajpi_duuruva_state);
    #ifdef DEBUG_DUURUVA
    fprintf(stdout,"__MUNAAJPI_DUURUVA:\n");
    print_duuruva(_wikimyei->__munaajpi_duuruva);
    #endif
    _wikimyei->__flags->__munaajpi_duuruva_ready=is_duuruva_ready(_wikimyei->__munaajpi_duuruva);
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,"\x1B[0;33m>> > ... ___munaajpi_duuruva_hash\t [");
        for(unsigned int idx=0x00;idx<_wikimyei->__munaajpi_duuruva_state_size;idx++){
            fprintf(stdout," %.2f",glti(_wikimyei)->__imibajcho_munaajpi_duuruva_state[idx]);
        }
        fprintf(stdout," ]\033[0m\n");
    #endif
}
/*

*/
// void imibajcho_step_munaajpi(__wikimyei_t *_wikimyei){ // #FIXME broken not in use
//     for(unsigned int m_idx=0x00;m_idx<_wikimyei->__alliu_state_size;m_idx++){
//         glti(_wikimyei)->__nonuwaabo_alliu_state[m_idx]+=g...etnext_alliu(_wikimyei->__alliu)[m_idx]/_wikimyei->__horizon_munaajpi;
//     }
// }
// void load_first_nonuwaabo(__wikimyei_t *_wikimyei){
//     assert(glti(_wikimyei)->__nonuwaabo_alliu_state==NULL);
//     glti(_wikimyei)->__nonuwaabo_alliu_state=0x00;
//     for(unsigned int idx=0x00;idx<_wikimyei->__horizon_munaajpi;idx++){
//         imibajcho_step_munaajpi(_wikimyei);
//         ...
//     }
// }
void compute_imibajcho_munaajpi(__wikimyei_t *_wikimyei){ // J
    // Assumes __nonuwaabo_alliu_state is ready
    assert(_wikimyei->__flags->__nonuwaabo_alliu_done); 
    glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]=0x00; // is this the problem?
    for(unsigned int m_idx=0x00;m_idx<_wikimyei->__alliu_state_size;m_idx++){
        glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]+=\
        glti(_wikimyei)->__nonuwaabo_alliu_state[m_idx]-\
        glti(_wikimyei)->__alliu_state[m_idx];
        glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]/=\
        (__cwcn_type_t)_wikimyei->__alliu_state_size;
    }
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,"\x1B[0;33m>> > ... compute_imibajcho_munaajpi\t\timibajcho_munaajpi_state[%d/0x00]: %f\033[0m\n",_wikimyei->__load_index,glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]);
    #endif
    imibajcho_munaajpi_cajtucu_transformation(_wikimyei);
    glti(_wikimyei)->__pending_munaajpi=___CWCN_FALSE; // means not lacking compute_imibajcho
    #ifdef WIKIMYEI_DEBUG_v2
        printf(">> > .g. nonuwaabo_alliu_state:\t[");
        for(unsigned int m_idx=0x00;m_idx<_wikimyei->__alliu_state_size;m_idx++){
            printf(" %.2f",glti(_wikimyei)->__nonuwaabo_alliu_state[m_idx]);
        }
        printf(" ]\n");
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
            #ifdef WIKIMYEI_DEBUG_v2
            fprintf(stdout,"\x1B[0;33m>> > ... load [%d] \t\x1B[1;33mTRUE  \x1B[0;33m(munaajpi_pending)\033[0m\n",_wikimyei->__load_index);
            #endif
        } else {
            #ifdef WIKIMYEI_DEBUG_v2
            fprintf(stdout,"\x1B[0;33m>> > ... load [%d] \t\x1B[1;33mFALSE \x1B[0;33m(munaajpi_pending)\033[0m\n",_wikimyei->__load_index);
            #endif
        }
    }while(load_go_up(_wikimyei)!=-1);
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,"\x1B[0;33m>> > ... load have still ctx: %d munaajpi_pending\033[0m\n",ctx);
    #endif
    load_to_index(_wikimyei,start_index);
    return c_stillpending; // if any item in load is still pending
}
___cwcn_bool_t set_load_pending_munaajpi(__wikimyei_t *_wikimyei){
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > ... set_load_pending_munaajpi\n");
    #endif
    if(_wikimyei->__load_size<_wikimyei->__horizon_munaajpi){
        return are_munaajpi_pending(_wikimyei);
    }
    // #FIXME include mask
    int start_index=_wikimyei->__load_index;
    int c_index;
    __trayectory_t *c_item;
    load_to_start(_wikimyei); // go down
    do{ // go up
        #ifdef WIKIMYEI_DEBUG_v2
            fprintf(stdout,"\033[0;32m>> > --- --- --- --- --- --- --- --- --- --- --- BASE UP: %d\033[0m\n",_wikimyei->__load_index);
        #endif
        c_item=glti(_wikimyei);
        c_index=_wikimyei->__load_index;
        do{ // go up the horizon
            #ifdef WIKIMYEI_DEBUG_v2
                fprintf(stdout,"\033[0;36m>> > --- --- --- --- --- --- --- --- --- --- --- GO UP (sec): %d\033[0m\n",_wikimyei->__load_index);
            #endif
            if(!c_item->__pending_munaajpi){break;} // skip
            if(_wikimyei->__load_size-c_index<_wikimyei->__horizon_munaajpi){break;} // skip
            if(c_item->__pending_munaajpi_index<_wikimyei->__horizon_munaajpi){
                c_item->__pending_munaajpi_index++;
                for(unsigned int m_idx=0x00;m_idx<_wikimyei->__alliu_state_size;m_idx++){
                    c_item->__nonuwaabo_alliu_state[m_idx]+=glti(_wikimyei)->__alliu_state[m_idx]/((__cwcn_type_t)_wikimyei->__horizon_munaajpi); // #FIXME lacking gamma
                }
                #ifdef WIKIMYEI_DEBUG_v2
                    printf(">> > .g. update: \t[");
                    for(unsigned int m_idx=0x00;m_idx<_wikimyei->__alliu_state_size;m_idx++){
                        printf(" nonuwaabo_state [%d/%d]: %f, from alliu_state [%d/%d]: %f || ", c_index, m_idx, c_item->__nonuwaabo_alliu_state[m_idx], _wikimyei->__load_index, m_idx, glti(_wikimyei)->__alliu_state[m_idx]);
                    }
                    printf(" ]\n");
                #endif
            }if(c_item->__pending_munaajpi_index==_wikimyei->__horizon_munaajpi){
                load_to_index(_wikimyei,c_index);
                _wikimyei->__flags->__nonuwaabo_alliu_done=___CWCN_TRUE;
                compute_imibajcho_munaajpi(_wikimyei);
                ___munaajpi_duuruva_hash(_wikimyei);
                ___munaajpi_hash(_wikimyei);
                break;
            }
        }while(load_go_up(_wikimyei)!=-1);
        load_to_index(_wikimyei,c_index);
    }while(load_go_up(_wikimyei)!=-1);
    // printf("waka nokingenmh prev \tglti(_wikimyei)->__alliu_state[m_idx==%d]: %f\n",0x00, glti(_wikimyei)->__alliu_state[0x00]);
    load_to_index(_wikimyei,start_index);
    // printf("waka nokingenmh past \tglti(_wikimyei)->__alliu_state[m_idx==%d]: %f\n",0x00, glti(_wikimyei)->__alliu_state[0x00]);
    return are_munaajpi_pending(_wikimyei);
}
/*

*/
void wikimyei_nolive_one(__wikimyei_t *_wikimyei){
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > ... wikimyei_nolive_one\n");
    #endif
    assert(glti(_wikimyei)->__pending_munaajpi_index<=_wikimyei->__horizon_munaajpi); // no live requires munaajpi done
    ___alliu_duuruva_hash(_wikimyei);
    ___uwaabo_hash(_wikimyei);
    ___entropy_hash(_wikimyei);
    ___tsane_dehash(_wikimyei);
    ___munaajpi_hash(_wikimyei);
}
void wikimyei_live_one(__wikimyei_t *_wikimyei){
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > ... wikimyei_live_one\n");
    #endif
    // #FIXME where else is the new trayectory?, seems fine
    if(_wikimyei->__flags->__done){
        _wikimyei->__flags->__done=___CWCN_FALSE;
        _wikimyei->__flags->__nonuwaabo_alliu_done=___CWCN_FALSE;
        assert(!load_enqueue_trayectory(_wikimyei, trayectory_fabric(_wikimyei)));
    }
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,"\033[0;31m>> > --- --- --- --- --- --- --- --- --- --- --- LOAD: %d\033[0m\n",_wikimyei->__load_size);
    #endif
    clock_t begin;
    clock_t end;
    ___alliu_hash(_wikimyei);
    ___alliu_duuruva_hash(_wikimyei);
    ___uwaabo_hash(_wikimyei);
    ___entropy_hash(_wikimyei);
    begin=clock();
    ___tsane_dehash(_wikimyei);
    end=clock();
    printf("\033[1;31m exe time [___tsane_dehash] %f:\033[0m\n", (double)(end-begin)/CLOCKS_PER_SEC);
    set_load_pending_munaajpi(_wikimyei);
    _wikimyei->__flags->__done=___CWCN_TRUE;
}
/*

*/
void wikimyei_live_load(__wikimyei_t *_wikimyei, int _size_of_load){
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,">> > ... wikimyei_live_load\n");
    #endif
    clock_t begin;
    clock_t end;
    while(_wikimyei->__load_size<_size_of_load){
        begin=clock();
        wikimyei_live_one(_wikimyei);
        end=clock();
        printf("\033[1;31m exe time [wikimyei_live_one] %f:\033[0m\n", (double)(end-begin)/CLOCKS_PER_SEC);
    }
    assert(_wikimyei->__load_size<=_size_of_load);
}
/*

*/
void read_munaajpi_w_base(__wikimyei_t *_wikimyei){
    unsigned int m_ctx=0x00;
    for(unsigned int idx=0x00;idx<_wikimyei->__alliu_state_size;idx++){
        _wikimyei->__munaajpi_base_w_state[m_ctx]=glti(_wikimyei)->__alliu_state[idx];
        m_ctx++;
    }
    for(unsigned int idx=0x00;idx<_wikimyei->__alliu_state_size;idx++){
        _wikimyei->__munaajpi_base_w_state[m_ctx]=glti(_wikimyei)->__nonuwaabo_alliu_state[idx];
        m_ctx++;
    }
    for(unsigned int idx=0x00;idx<_wikimyei->__uwaabo_state_size;idx++){
        _wikimyei->__munaajpi_base_w_state[m_ctx]=glti(_wikimyei)->__uwaabo_state[idx];
        m_ctx++;
    }
    for(unsigned int idx=0x00;idx<_wikimyei->__tsane_state_size;idx++){
        _wikimyei->__munaajpi_base_w_state[m_ctx]=glti(_wikimyei)->__tsane_state[idx];
        m_ctx++;
    }
    for(unsigned int idx=0x00;idx<_wikimyei->__munaajpi_duuruva->__duuruva_vector_size;idx++){
        _wikimyei->__munaajpi_base_w_state[m_ctx]=glti(_wikimyei)->__imibajcho_munaajpi_duuruva_state[idx];
        m_ctx++;
    }
    #ifdef WIKIMYEI_DEBUG_v2
        fprintf(stdout,"\x1B[0;33m>> > ... read_munaajpi_w_base\t[");
        for(unsigned int idx=0x00;idx<_wikimyei->__munaajpi_base_size;idx++){
            fprintf(stdout, " %.2f,",_wikimyei->__munaajpi_base_w_state[m_ctx]);
        }
        fprintf(stdout," ]\033[0m\n");
    #endif
    assert(_wikimyei->__munaajpi_base_size==m_ctx);
}
void imibajcho_munaajpi_cajtucu_transformation(__wikimyei_t *_wikimyei){
    // #FIXME, enum class tsane
    // tsane_state[0] == call
    // tsane_state[1] == put
    assert(_wikimyei->__tsane_state_size==0x02);
    __cwcn_type_t ims_aux=0x00;
    ims_aux+=glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]*(+1)*glti(_wikimyei)->__tsane_state[0x00];
    ims_aux+=glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]*(-1)*glti(_wikimyei)->__tsane_state[0x01];
    glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]=ims_aux;
    #ifdef WIKIMYEI_DEBUG
        fprintf(stdout,"\x1B[0;33m>> > ... imibajcho_munaajpi_cajtucu_transformation ---\t imibajcho_munaajpi_state: %f\033[0m\n",glti(_wikimyei)->__imibajcho_munaajpi_state[0x00]);
    #endif
}