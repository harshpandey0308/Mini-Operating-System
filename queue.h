#include"PCB.h"

#ifndef QUEUE_H
#define QUEUE_H

typedef struct qnode{
    PROCESS P;
    struct qnode *next;
}NODE;

extern NODE* head1;
extern NODE* head2;

NODE* create_node(PROCESS p);

void enque(PROCESS p);

void deque();

NODE *peek();

void print_queue();

#endif