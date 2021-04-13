#include <stdio.h>
#include <stdlib.h>
#include "wikimyei.config.h"
#include "cwcn_security.h"
#include "cwcn_wikimyei.mech.h"

int main() {
	// ¿what about gpu?
	// ¿what about paralelism?
	// --> 
	// define the model 
	wikimyei_jkimyei_neural();
	
	// define optimizer
	// 
	
	while(cwcn_dehash_step()){
		printf("step\n");
		jkimyei_wikimyei();
	}
	return 0;
}