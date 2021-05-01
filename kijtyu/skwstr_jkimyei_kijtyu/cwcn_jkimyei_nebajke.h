
#ifndef JKMYEI_NEBAJKE_INCLUDED
#define JKMYEI_NEBAJKE_INCLUDED

typedef float (__cwcn_type_t);
typedef _Bool ___cwcn_bool_t;
#define ___CWCN_TRUE (___cwcn_bool_t) 0b1
#define ___CWCN_FALSE (___cwcn_bool_t) 0b0
#define max(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a > _b ? _a : _b;})
#define min(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a < _b ? _a : _b;})

#define NUM_SPACEBASE   (unsigned int) 1
#define NUM_CAJTUCU (unsigned int) 10
#define NUM_TSANE   (unsigned int) 2
#define NUM_UWAABO  (unsigned int) 2
#define NUM_ENTROPY (unsigned int) 1
// #define NUM_MUNAAJPI(unsigned int) 1
#define NUM_PARALELL    (unsigned int) 1 // MAKEME



#define FRQ_JIKIMYEI	(unsigned int) 10
#define LEARNING_RATE   (__cwcn_type_t) 1e-4
#define TIME_GAMMA  (__cwcn_type_t) 0.99
#define GAE_LAMBDA  (__cwcn_type_t) 0.95
#define JKMYEI_EPSILON (__cwcn_type_t) 0.2
#define ACTOR_BETA  (__cwcn_type_t) 1.0
#define IMIBAJCHO_MUNAAJPI_BETA (__cwcn_type_t) 0.5
#define ENTROPY_BETA(__cwcn_type_t) 0.001

#define NUM_RETURNS (unsigned int) 1//
#define NUM_STATES  (unsigned int) 1//
#define NUM_ACTIONS (unsigned int) 1//

#define JKMYEI_STEPS   (unsigned int) 256
#define BATCH_SIZE  (unsigned int) 128//
#define MINI_BATCH_SIZE (unsigned int) 32//
#define TARGET_REWARD   (unsigned int) 2500

void jkimyei_iter(
	__cwcn_type_t states[BATCH_SIZE][NUM_STATES], 
	__cwcn_type_t actions[BATCH_SIZE][NUM_ACTIONS], 
	__cwcn_type_t log_probs[BATCH_SIZE][NUM_ACTIONS], 
	__cwcn_type_t returns[BATCH_SIZE][NUM_RETURNS],
	__cwcn_type_t adventage[BATCH_SIZE][NUM_ACTIONS],
	__cwcn_type_t states_handler[MINI_BATCH_SIZE][NUM_STATES],
	__cwcn_type_t actions_handler[MINI_BATCH_SIZE][NUM_ACTIONS], 
	__cwcn_type_t log_probs_handler[MINI_BATCH_SIZE][NUM_ACTIONS], 
	__cwcn_type_t returns_handler[MINI_BATCH_SIZE][NUM_RETURNS],
	__cwcn_type_t adventage_handler[MINI_BATCH_SIZE][NUM_ACTIONS]);
void jkimyei_wikimyei(
	__cwcn_type_t states[BATCH_SIZE][NUM_STATES], 
	__cwcn_type_t actions[BATCH_SIZE][NUM_ACTIONS], 
	__cwcn_type_t log_probs[BATCH_SIZE][NUM_ACTIONS], 
	__cwcn_type_t returns[BATCH_SIZE][NUM_RETURNS],
	__cwcn_type_t adventage[BATCH_SIZE][NUM_ACTIONS]);

#endif