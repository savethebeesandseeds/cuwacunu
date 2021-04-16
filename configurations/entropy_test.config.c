#include "entropy_test.config.h"
void delay(double dly){
    const time_t start = time(NULL);
    time_t current;
    do{
        time(&current);
    } while(difftime(current,start)<dly);
}