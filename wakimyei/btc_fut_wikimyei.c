#include <stdio.h>
#include "cwcn_net_utils.h"
#include "cwcn_net_data_mech.h"
#include "cwcn_net_rl_trainer.h"
int main() {
	// ¿what about gpu?
	// ¿what about paralelism?
	// --> 
	// define the model 
	define_network();
	// define optimizer
	// 
	while(cwcn_dehash_step()){
		wikimyei_reinforced_neutal();
	}
	return 0;
}