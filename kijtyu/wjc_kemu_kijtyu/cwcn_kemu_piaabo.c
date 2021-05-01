#include "cwcn_kemu_piaabo.h"

void delay(double dly){
    const time_t start = time(NULL);
    time_t current;
    do{
        time(&current);
    } while(difftime(current,start)<dly);
}

float clamp(float d, float min, float max) {
    printf(">> clamp");
    const float t = d < min ? min : d;
    return t > max ? max : t;
}

void *array_concat(const void *a, size_t an,const void *b, size_t bn, size_t s){
    char *p = malloc(s * (an + bn));
    memcpy(p, a, an*s);
    memcpy(p + an*s, b, bn*s);
    return p;
}

// int main() {
//     queue_t *head_t = NULL;
//     int ret;
//     printf("waka 1 \n");
//     enqueue(&head_t, def_trayectory(11));
//     enqueue(&head_t, def_trayectory(22));
//     enqueue(&head_t, def_trayectory(33));
//     enqueue(&head_t, def_trayectory(44));
//     printf("waka 2 \n");
//     print_queue(head_t);
//     printf("waka 2 \n");
    
//     while ((ret=dequeue(&head_t)) > 0) {
//         printf("dequeued %d\n", ret);
//     }
//     printf("done. head_t=%p\n", head_t);

//     return 0;
// }