#include <time.h>
#include <stdlib.h>
#include "fann.h"
#include "cwcn_security.h"
#include "cwcn_alliu_piaabo.h"
#include "cwcn_cajtucu_nebajke.h"
#include "cwcn_net_nebajke.h"
#include "cwcn_ppo_nebajke.h"
#include "cwcn_kemu_piaabo.h"
// #include fann.h or floatfann.h
// #include doublefann.h
// #include fixedfann.h 
#ifndef WIKIMYEI_CONFIG
#define WIKIMYEI_CONFIG

#define NUM_ALLIU   (int) 3

#define NUM_DUURUVA_LAYERS  (int) 2
#define NUM_DUURUVA_HIDDEN  (int) 5
#define NUM_DUURUVA (int) 3

#define NUM_UWAABO_LAYERS   (int) 2
#define NUM_UWAABO_HIDDEN   (int) 5
#define NUM_UWAABO  (int) 1

#define NUM_UJCAMEI (int) 1

#define NUM_STATES  (int) 1
#define NUM_SPACEBASE   (int) 1
#define NUM_CAJTUCU (int) 10
#define NUM_TSANE   (int) 2
#define NUM_UWAABO  (int) 2
#define NUM_ENTROPY (int) 1
// #define NUM_MUNAAJPI(int) 1

#define NUM_RETURNS     (int) 1
#define NUM_NETLAYERS   (int) 3 // DEFME
#define NUM_NETHIDDEN   (int) 3 // DEFME

#define NUM_PARALELL    (int) 1 // MAKEME

#define FRQ_JIKIMYEI    (int) 10
#define LEARNING_RATE   (float) 1e-4
#define TIME_GAMMA  (float) 0.99
#define GAE_LAMBDA  (float) 0.95
#define PPO_EPSILON (float) 0.2
#define ACTOR_BETA  (float) 1.0
#define IMIBAJCHO_MUNAAJPI_BETA (float) 0.5
#define ENTROPY_BETA(float) 0.001

#define PPO_STEPS   (int) 256
#define BATCH_SIZE  (int) 128
#define MINI_BATCH_SIZE (int) 32
#define TARGET_REWARD   (int) 2500


// ENTROPY
#define DIRECT_RESOLUTION (int) 100
#endif