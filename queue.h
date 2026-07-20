#include<stddef.h>
#include<stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_node{
    void *data;
    struct queue_node *next;
}QUEUE_NODE;
typedef struct queue{
    QUEUE_NODE *head; 
    QUEUE_NODE *tail;
    int size;
}QUEUE;

extern QUEUE ready_queue;
extern QUEUE waiting_queue;

void queue_init(QUEUE *Q);

bool queue_enque(QUEUE *Q , void *data);

void *queue_deque(QUEUE *Q);

void *queue_front(const QUEUE *Q);

bool queue_is_empty(const QUEUE *Q);

int queue_size(const QUEUE *Q);

void destroy_queue(QUEUE *Q);

#endif