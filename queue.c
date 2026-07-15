#include<stdio.h>
#include<stdlib.h>
#include"PCB.h"
#include"queue.h"

QUEUE ready_queue = {NULL , NULL};
QUEUE waiting_queue = {NULL , NULL};

NODE* create_node(PROCESS *p){
    NODE* q = (NODE*)malloc(sizeof(NODE));
    q->P = p;
    q->P->state = READY;
    q->next = NULL;
    return q;
}

void enque(PROCESS *p , QUEUE *queue){
    NODE* p1 = create_node(p);

    if(queue->head == NULL){
        queue->head = p1;
        return;
    }
    
    NODE* temp = queue->head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = p1;
    queue->tail = p1;

}

NODE *deque( QUEUE * queue){
    NODE* temp = queue->head;
    
    if(temp == NULL){
        return NULL;
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
    if(queue->head == NULL){
        printf("THE QUEUE IS EMPTY.\n");
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