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
    size_t size;
}QUEUE;

extern QUEUE ready_queue;
extern QUEUE waiting_queue;

void queue_init(QUEUE *Q);

bool queue_enque(QUEUE *Q , void *data);

bool queue_deque(QUEUE *Q , void **out_data);

bool queue_front(const QUEUE *Q);

bool queue_is_empty(const QUEUE *Q);

size_t queue_size(const QUEUE *Q);

void destroy_queue(QUEUE *Q);

#endif