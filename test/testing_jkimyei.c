#include "cwcn_jkimyei_piaabo.h"
#include "cwcn_jkimyei_nebajke.h"
int main(){
    unsigned int _load_size=0x01;
    unsigned int _jk_size=0x01;
    unsigned int _num_states=0x01;
    unsigned int _num_actions=0x01;
    unsigned int _num_returns=0x01;
    __jkimyei_t *c_jkimyei = jkimyei_fabric(
        _load_size,
        _jk_size, 
        _num_states, 
        _num_actions, 
        _num_returns)
    // skwstr_jkimyei_wikimyei(c_jkimyei);
    
    
    
    // FORGETIT FIRST TEST THE QUEUE


    
}