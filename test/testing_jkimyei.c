#include "cwcn_jkimyei_piaabo.h"
#include "cwcn_jkimyei_nebajke.h"
int main()
    unsigned int _load_size=0x01;
    unsigned int _jk_size=0x01;
    unsigned int _uwaabo_size=0x01;
    unsigned int _duuruva_size=0x01;
    unsigned int _tsane_size=0x01;
    unsigned int _d_res=0x100;
    unsigned int _munaajpi_base_size=_tsane_size+0x01; // #FIXME 0x01 is the number for earnings 
    unsigned int _munaajpi_returns_size=_uwaabo_size; // this is fine
    __jkimyei_t *c_jkimyei = jkimyei_fabric(
        _load_size, // the size of the queue
        _jk_size, // the size of the jkimyei batch
        _uwaabo_size, // the size of the uwaabo output
        _duuruva_size,
        _num_tsane,
        _munaajpi_base_size,
        _num_munaajpi_returns);
    // skwstr_jkimyei_wikimyei(c_jkimyei);
    ujcamei
            // wapaajco_bydifference(c_tsinuu, c_correct_output[ctx_p]);
    for(unsigned int ctx_epoch=0x00;ctx_epoch<0x01;ctx_epoch++){
        for(unsigned int ctx_p=0x00;ctx_p<DATA_COUNT;ctx_p++){
            
            jkimyei_tsinuu_bydirectNABLA(c_tsinuu);
            // getchar();
        }
    }
    jkimyei_destroy(c_jkimyei);
    // FORGETIT FIRST TEST THE QUEUE
    printf("\033[1;32mwaka dao\033[0m\n");
    printf("\033[1;32mwaka din\033[0m\n");
    printf("\033[1;32mwaka tao\033[0m\n");
    ...
}