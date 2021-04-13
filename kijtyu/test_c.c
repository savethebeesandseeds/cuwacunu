#include <stdio.h>
#define LIBERT "stdlib.h"
#include LIBERT
#define BATCH_SIZE 100
#define MINI_BATCH_SIZE 20
#define waki 10
int waka = 10;

void f_waka(int waka1){
    printf("%d\n",waka);
}
int main(){
    int x = 10;
    int *y;
    printf("x:%d, y:%ls\n", x, y);
    x /= 0.0;
    double w = 10;
    w /= 0.0;
    printf("x:%d\n", x);
    printf("w:%f\n", w);
    float states[100];
    int batch_size=(int)sizeof(states)/sizeof(states[0]);
    float rand_idx[100];
    for(int idx=0;idx<batch_size;idx++){
        rand_idx[idx] = rand() % batch_size;
        printf("%d - %f\n",idx, rand_idx[idx]);
    }
    int rand_idx_size=(int)sizeof(states)/sizeof(states[0]);
    printf("batch_size: %d, rand_idx_size: %d\n", batch_size, rand_idx_size);
    f_waka(12);
    printf("%d\n",waka);
    printf("%d\n",BATCH_SIZE/MINI_BATCH_SIZE);
    printf("%d\n", (unsigned int)waki);
}