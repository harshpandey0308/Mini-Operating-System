#include<stdio.h>
#include<stdlib.h>
#include"PCB.h"
#include"queue.h"



NODE* head = NULL;

NODE* create_node(PROCESS p){
    NODE* q = (NODE*)malloc(sizeof(NODE));
    q->P = p;
    q->P.state = READY;
    q->next = NULL;
    return q;
}

void enque(PROCESS p){
    NODE* p1 = create_node(p);

    if(head == NULL){
        head = p1;
        return;
    }
    
    NODE* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = p1;
}

void deque(){
    if(head == NULL){
        printf("QUEUE IS EMPTY.\n");
        return;
    }
    if(head->next == NULL){
        free(head);
        return;
    }
    NODE* temp = head;
    head = temp->next;
    free(temp);
}

NODE *peek(){
    return head;
}

void print_queue(){
    if(head == NULL){
        printf("THE QUEUE IS EMPTY.\n");
    }
    NODE* temp = head;
    printf("%20s\n","---------------QUEUE-PID--------------");
    while(temp != NULL){
        if(temp == head){
            printf("HEAD->");
        }
        printf("%d->",temp->P.PID);
        temp = temp->next;
        if(temp == NULL){
            printf("NULL\n");
        }
    }
}