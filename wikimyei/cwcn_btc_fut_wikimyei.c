#include "wikimyei.config.h"

int main() {
	start_enviroment();
	printf(">> cwcn_btc_fut_wikimyei");
	// ¿what about gpu?
	// ¿what about paralelism?
	// --> 
	// define the model 
	/*
		DEFINITONS
	*/
	__alliu_t *c_alliu = _ipivye_alliu();
	__duuruva_t *c_duuruva = _ipivye_duuruva();
	__uwaabo_t *c_uwaabo = _ipivye_uwaabo();
	__entropy_t *c_entropy = _ipivye_entropy();
	__munaajpi_t *c_munaajpi = _ipivye_munaajpi();
	__tsane_t *c_tsane = _ipivye_tsane();
	__dehasj_tsane_t *c_dehash_tsane = _ipivye_dtsane();
	_ipivye_jkimyei();
	// how to define optimizer in fann?
	// 
	__queue_t *head = NULL;
	unsigned int step_count = 0;
	unsigned int jikimyei_count = 0;
	while(cwcn_dehash_step()){
		step_count ++;
		printf("--> step (%d)--------------------------------------\n", step_count);
		break;
		for(unsigned int prlll_idx=0;prlll_idx<NUM_PARALLEL;prlll_idx++){ // #FIXME, use well the machie resources, make this a parallel type loop
			
			_wikimyei_alliu_source	(c_alliu);
			_wikimyei_ujcamei_hash	(c_alliu, c_duuruva);
			_wikimyei_uwaabo_hash	(c_duuruva, c_uwaabo);
			_wikimyei_entropy_dehash(c_uwaabo, c_entropy); // #TELLME ¿MAX or MIN?
			_wikimyei_cajtucu_hash	(c_uwaabo, c_entropy);
			_wikimyei_munaajpi_hash	(c_alliu, c_uwaabo, c_entropy, c_munaajpi);
			_wikimyei_tsane_dehash	(c_tsane, c_dehash_tsane);
			
			// 	float states[BATCH_SIZE][NUM_STATES], 
			// 	float actions[BATCH_SIZE][NUM_ACTIONS],
			// 	float log_probs[BATCH_SIZE][NUM_ACTIONS],
			// 	float returns[BATCH_SIZE][NUM_RETURNS],
			// 	float adventage[BATCH_SIZE][NUM_ACTIONS]

			enqueue_trayectory(&head, fill_trayectory(c_duuruva, c_munaajpi, c_tsane)); // #FIXME?
			if(randn() % FRQ_JIKIMYEI % step_count){ // #MAYOR? optimize time.
				jikimyei_count ++;
				printf(">> \tJikimyei %d\n", jikimyei_count);
				_wikimyei_jkimyei(head);
				}
			}
		}
	return 0;
}