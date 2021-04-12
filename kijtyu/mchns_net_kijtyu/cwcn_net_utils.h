#include <stdbool.h>
#include <fann.h>
#ifndef FUNCTIONS_NET_UTILS_INCLUDED
#define FUNCTIONS_NET_UTILS_INCLUDED
void cwcn_display_network(struct fann *ann);
float clamp(float d, float min, float max);
#endif
