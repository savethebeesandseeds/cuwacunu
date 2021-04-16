#include <stdio.h>
#include <stdlib.h>

typedef struct trayectory {
    int val;
} trayectory_t;

typedef struct queue {
    trayectory_t *trayectory;
    struct queue *next;
} queue_t;

trayectory_t * define_trayectory(int val){
    trayectory_t *new_trayectory = malloc(sizeof(trayectory_t));
    new_trayectory->val = val;
    return new_trayectory;
}

void enqueue(queue_t **head, trayectory_t *new_trayectory) {
    queue_t *new_node = malloc(sizeof(queue_t));
    if (!new_node) return;
    new_node->trayectory = new_trayectory;
    new_node->next = *head;
    *head = new_node;
}

int dequeue(queue_t **head) {
    queue_t *current, *prev = NULL;
    int retval = -1;
    if (*head == NULL) return -1;
    current = *head;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    retval = current->trayectory->val;
    free(current);
    if (prev)
        prev->next = NULL;
    else
        *head = NULL;
    return retval;
}

void print_queue(queue_t *head) {
    queue_t *current = head;
    while (current != NULL) {
        printf("%d\n", current->trayectory->val);
        current = current->next;
    }
}

int main() {
    queue_t *head = NULL;
    int ret;
    printf("waka 1 \n");
    enqueue(&head, define_trayectory(11));
    enqueue(&head, define_trayectory(22));
    enqueue(&head, define_trayectory(33));
    enqueue(&head, define_trayectory(44));
    printf("waka 2 \n");
    print_queue(head);
    printf("waka 2 \n");
    
    while ((ret=dequeue(&head)) > 0) {
        printf("dequeued %d\n", ret);
    }
    printf("done. head=%p\n", head);

    return 0;
}