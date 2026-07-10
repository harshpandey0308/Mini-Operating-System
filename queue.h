#include"PCB.h"

#ifndef QUEUE_H
#define QUEUE_H

typedef struct qnode{
    PROCESS P;
    struct qnode *next;
}NODE;
typedef struct Q{
    NODE* head; 
    NODE* tail;
}QUEUE;

extern QUEUE ready_queue;
extern QUEUE waiting_queue;

NODE* create_node(PROCESS *p);

void enque(PROCESS *p , QUEUE *queue);

NODE *deque(QUEUE *queue);

NODE *peek(QUEUE *queue);

int is_empty(QUEUE *queue);

void print_queue(QUEUE *queue);

#endif