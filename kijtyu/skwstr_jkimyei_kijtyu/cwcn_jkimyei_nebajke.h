
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


#define FRQ_JIKIMYEI	(unsigned int) 10
#define LEARNING_RATE   (__cwcn_type_t) 1e-4 // #FXIME wapaajco_potency
#define TIME_GAMMA  (__cwcn_type_t) 0.99
#define GAE_LAMBDA  (__cwcn_type_t) 0.95
#define JKMYEI_EPSILON (__cwcn_type_t) 0.2
#define UWAABO_BETA  (__cwcn_type_t) 1.0
#define MUNAAJPI_BETA (__cwcn_type_t) 0.5
#define ENTROPY_BETA(__cwcn_type_t) 0.001

#define NUM_RETURNS (unsigned int) 1//
#define NUM_DUURUVA  (unsigned int) 1//
#define NUM_TSANE (unsigned int) 1//

#define JKMYEI_STEPS (unsigned int) 256
#define LOAD_SIZE  (unsigned int) 128//
#define JK_SIZE (unsigned int) 32//
#define TARGET_REWARD (unsigned int) 2500 // #FIXME [what!]

void jk_iter(__jkimyei_t __jkimyei);
void wikimyei_jkimyei(__jkimyei_t __jkimyei);

#endif