#include "cwcn_wikimyei_nebajke.h"
void ___alliu_hash(__wikimyei_t *_wikimyei){
	/*	ujcamei */
	/*	 */
    if(glti(_wikimyei)->__alliu_state!=NULL){ // #FIXME this might cause problems, if reset is forgoten
        fprintf(stdout,">>> ERROR: ___alliu_hash has been set twice\n");
        assert(0x00);
    }
    glti(_wikimyei)->__alliu_state=getnext_alliu(_wikimyei->__alliu);
}
void ___duuruva_hash(__wikimyei_t *_wikimyei){
	/*	duuruva */
	/*	 */
    set_duuruva_value(_wikimyei->__alliu_duuruva, glti(_wikimyei)->__alliu_state);
	dist_duuruva(_wikimyei->__alliu_duuruva);
	// print_duuruva(_wikimyei->__alliu_duuruva);
	glti(_wikimyei)->__alliu_duuruva_state=get_duuruva_value(_wikimyei->__alliu_duuruva);
}
void ___uwaabo_hash(__wikimyei_t *_wikimyei){
	/*	tsinuu */
	/*	 */
    set_input(_wikimyei->__uwaabo, glti(_wikimyei)->__alliu_duuruva_state);
	tsinuu_direct_uwaabo_full_parametric(_wikimyei->__uwaabo);
	read_output(_wikimyei->__uwaabo, glti(_wikimyei)->__uwaabo_state);
}
void ___entropy_hash(__wikimyei_t *_wikimyei){
	/*	entropy */
	/*	 */
    glti(_wikimyei)->__entropy_uwaabo_state=_wikimyei->__ec->__forward(_wikimyei->__ec, glti(_wikimyei)->__uwaabo_state);
    glti(_wikimyei)->__uwaabo_entropy=_wikimyei->__ec->__entropy;
}
void ___tsane_dehash(__wikimyei_t *_wikimyei, ___cwcn_bool_t _take_tsane){
	/*  entropy */
	/*	 */
    glti(_wikimyei)->__tsane_state=_wikimyei->__ec->__tsane;
    __cwcn_type_t c_sum=0x00;
    for(unsigned int idx=0x00;idx<_wikimyei->__tsane_state_size;idx++){
        // glti(_wikimyei)->__tsane_log_prob=log(glti(_wikimyei)->__tsane_state[idx]); // #FIXME not, is uwaabo state instead
        c_sum+=glti(_wikimyei)->__tsane_state[idx]/0.01*_wikimyei->__tsane_state_size;
    }
    idx=0x00;
    while(0x01){
        set_seed();
        if(glti(_wikimyei)->__tsane_state[idx]<(__cwcn_type_t)rand()%(unsigned int)c_sum){break;}else{idx++;}if(idx<_wikimyei->__tsane_state_size){idx=0x00;}// undependent bernouly or whatever
    }
    glti(_wikimyei)->__pending_munaajpi=___CWCN_TRUE;
}
void ___munaajpi_hash(__wikimyei_t *_wikimyei){
	/*	tsinuu (entropy) */
	/*	tsinuu */
	/*	 */
    set_input(_wikimyei->__munaajpi, read_munaajpi_base(_wikimyei));
	tsinuu_direct_uwaabo_full_parametric(_wikimyei->__munaajpi);
    read_output(_wikimyei->__munaajpi, glti(_wikimyei)->__munaajpi_state);
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
    glti(_wikimyei)->__imibajcho_munaajpi_state=0x00;
    for(unsigned int m_idx=0x00;m_idx<_wikimyei->__alliu_state_size;m_idx++){
        glti(_wikimyei)->__imibajcho_munaajpi_state+=\
        glti(_wikimyei)->__nonuwaabo_alliu_state[m_idx]-\
        glti(_wikimyei)->__alliu_state[m_idx];
        glti(_wikimyei)->__imibajcho_munaajpi_state/=\
        _wikimyei->__alliu_state_size;
    }
    imibajcho_munaajpi_cajtucu_transformation(_wikimyei);
    glti(_wikimyei)->__pending_munaajpi=___CWCN_FALSE;
}
___cwcn_bool_t are_munaajpi_pending(__wikimyei_t *_wikimyei){
    int start_index=_wikimyei->__load_index;
    ___cwcn_bool_t c_stillpending=___CWCN_FALSE;
    load_to_start(_wikimyei); // go down
    while(load_go_up(_wikimyei)!=-1){ // go up
        if(glti(_wikimyei)->__pending_munaajpi_index<_wikimyei->__horizon_munaajpi){
            c_stillpending=___CWCN_TRUE;
        }
    }
    load_to_index(_wikimyei,start_index);
    return c_stillpending; // if any item in load is still pending
}
___cwcn_bool_t set_load_pending_munaajpi(__wikimyei_t *_wikimyei){
    // #FIXME include mask
    int start_index=_wikimyei->__load_index;
    int c_index;
    __trayectory_t *c_item;
    load_to_start(_wikimyei); // go down
    while(load_go_up(_wikimyei)!=-1){ // go up
        c_item=glti(_wikimyei);
        c_index=_wikimyei->__load_index;
        while(load_go_up(_wikimyei)!=-1){ // go up the horizon
            if(!c_item->__pending_munaajpi){break;}
            if(c_item->__pending_munaajpi_index<_wikimyei->__horizon_munaajpi){
                c_item->__pending_munaajpi_index++;
                for(unsigned int m_idx=0x00;m_idx<_wikimyei->__alliu_state_size;m_idx++){
                    c_item->__nonuwaabo_alliu_state[m_idx]+=glti(_wikimyei)->__alliu_state[m_idx]/_wikimyei->__horizon_munaajpi; // #FIXME lacking gamma
                }
            } else {
                compute_imibajcho_munaajpi(_wikimyei);
                set_duuruva_value(_wikimyei->__munaajpi_duuruva, c_item->__imibajcho_munaajpi_state);
                dist_duuruva(_wikimyei->__munaajpi_duuruva);
                c_item->__imibajcho_munaajpi_duuruva_state=get_duuruva_value(_wikimyei->__munaajpi_duuruva);
                // print_duuruva(_wikimyei->__munaajpi_duuruva);
                ___munaajpi_hash(_wikimyei);
                break;
            }
        }
        load_to_index(_wikimyei,c_index);
    }
    load_to_index(_wikimyei,start_index);
    return are_munaajpi_pending(_wikimyei);
}
/*

*/
void wikimyei_nolive_forward(__wikimyei_t *_wikimyei){
    assert(!glti(_wikimyei)->__pending_munaajpi_index<_wikimyei->__horizon_munaajpi); // no live requires munaajpi done
    ___uwaabo_hash(_wikimyei);
    ___entropy_hash(_wikimyei);
    ___tsane_dehash(_wikimyei);
    ___munaajpi_hash(_wikimyei);
}
void wikimyei_live_one(__wikimyei_t *_wikimyei){
    // #FIXME where else is the new trayectory?, seems fine
    __trayectory_t *c_new_trayectory=trayectory_fabric(_wikimyei);
    assert(!load_enqueue_trayectory(_wikimyei, c_new_trayectory));
    ___alliu_hash(_wikimyei);
    ___duuruva_hash(_wikimyei);
    ___uwaabo_hash(_wikimyei);
    ___entropy_hash(_wikimyei);
    ___tsane_dehash(_wikimyei);
    set_load_pending_munaajpi(_wikimyei);
}
/*

*/
void wikimyei_live_load(__wikimyei_t *_wikimyei, int _size_of_load){
    while(_wikimyei->__load_size<_size_of_load-0x01){
        wikimyei_live_one(_wikimyei);
    }
    assert(_wikimyei->__load_size<_size_of_load);
}
