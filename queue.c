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
    Q = (QUEUE*)malloc(sizeof(QUEUE));

    if(Q == NULL){
        return false;
    }
    if(Q->head == NULL){
        Q->head = data;
        Q->tail = data;
        Q->tail->next = NULL;
    }
    else{
        Q->tail->next = data;
        Q->tail = data;
    }
    Q->size++;
    return true;
}

NODE *deque( QUEUE * queue){
    NODE* temp = queue->head;
    
    if(temp == NULL){
        return NULL;
    }

    if(queue->head == queue->tail){
        queue->head = temp->next;
        queue->tail = temp->next;
    }

    queue->head = temp->next;
    return temp;
}

NODE *peek(QUEUE *queue){
    return queue->head;
}

int is_empty(QUEUE *queue){
    if(queue->head == NULL){
        return 1;
    }
    return 0;
}

void print_queue(QUEUE *queue){
    if(queue->head == NULL && queue->tail == NULL){
        printf("THE QUEUE IS EMPTY.\n");
        return;
    }
    NODE* temp = queue->head;
    printf("%20s\n","---------------QUEUE-PID--------------");
    while(temp != NULL){
        if(temp == queue->head){
            printf("HEAD->");
        }
        printf("%d->",temp->P->PID);
        temp = temp->next;
        if(temp == NULL){
            printf("NULL\n");
        }
    }
}