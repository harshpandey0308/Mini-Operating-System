#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"PCB.h"
#include"queue.h"

QUEUE ready_queue;
QUEUE waiting_queue;

void queue_init(QUEUE *Q){
    Q->head = NULL;
    Q->tail = NULL;
    Q->size = 0;
}

bool queue_enque(QUEUE *Q , void *data){
    if(Q == NULL){
        return false;
    }

    QUEUE_NODE *q_node = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));

    if(q_node == NULL){
        return false;
    }
    
    q_node->data = data;
    q_node->next = NULL;

    if(Q->head == NULL){
        Q->head = q_node;
        Q->tail = q_node;
    }
    else{
        Q->tail->next = q_node;
        Q->tail = q_node;
    }
    Q->size++;
    return true;
}

bool queue_deque(QUEUE *Q , void **out_data){
    if(Q == NULL){
        return false;
    }

    if(out_data == NULL){
        return false;
    }

    if(queue_is_empty(Q)){
        return false;
    }

    *out_data = Q->head->data;
    QUEUE_NODE *temp = Q->head;
    Q->head = Q->head->next;
    if(Q->head == NULL){
        Q->tail = NULL;
    }
    free(temp);
    temp = NULL;
    Q->size--;
    return true;
}

bool queue_is_empty(const QUEUE *Q){
    if(Q == NULL){
        return true;
    }
    return (Q->size == 0);
}

size_t queue_size(const QUEUE *Q){
    if(Q == NULL){
        return 0;
    }
    return Q->size;
}

bool queue_front(const QUEUE *Q , void **out_data){
    if(Q == NULL){
        return false;
    }
    if(out_data == NULL){
        return false;
    }
    if(queue_is_empty(Q)){
        return false;
    }

    *out_data = Q->head->data;
    return true;
}

void queue_destroy(QUEUE *Q){
    if(Q == NULL){
        return ;
    }
    
    QUEUE_NODE *current = Q->head;
    
    while(current != NULL){
        QUEUE_NODE *next = current->next;
        free(current);
        current = next;
    }
    Q->head = NULL;
    Q->tail = NULL;
    Q->size = 0;
    
}