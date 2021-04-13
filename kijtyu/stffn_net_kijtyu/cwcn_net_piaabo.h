#include <stdbool.h>
#include <fann.h>
#ifndef FUNCTIONS_NET_piaabo
#define FUNCTIONS_NET_piaabo
void cwcn_display_network(struct fann *ann);
float clamp(float d, float min, float max);
#endif
