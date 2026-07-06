#include<stdio.h>
#include<stdlib.h>
#include"PCB.h"
#include"queue.h"

NODE* head1 = NULL;
NODE* head2 = NULL;

NODE* create_node(PROCESS p){
    NODE* q = (NODE*)malloc(sizeof(NODE));
    q->P = p;
    q->P.state = READY;
    q->next = NULL;
    return q;
}

void enque(PROCESS p){
    if(p.state == NEW){
        NODE* p1 = create_node(p);

        if(head1 == NULL){
            head1 = p1;
            return;
        }
        
        NODE* temp = head1;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = p1;
    }
    else if(p.state == WAITING){
        NODE* p1 = create_node(p);
        p1->P.state = WAITING;

        if(head2 == NULL){
            head2 = p1;
            return;
        }
        NODE* temp1 = head2;
        while(temp1->next != NULL){
            temp1 = temp1->next;
        }
        temp1->next = p1;
    }
    
}

void deque(){
    if(head2->P.is_waiting){
        if(head2 == NULL){
            printf("WAITING QUEUE IS EMPTY.\n");
            return;
        }
        NODE* temp1 = head2;
        head2 = temp1->next;
        free(temp1);
        return;
    }

    if(head1 == NULL){
        printf("QUEUE IS EMPTY.\n");
        return;
    }
    NODE* temp = head1;
    head1 = temp->next;
    free(temp);
}

NODE *peek(){
    if(head2->P.is_waiting){
        return head2;
    }
    return head1;
}

void print_queue(){
    if(head1 == NULL){
        printf("THE QUEUE IS EMPTY.\n");
    }
    NODE* temp = head1;
    printf("%20s\n","---------------QUEUE-PID--------------");
    while(temp != NULL){
        if(temp == head1){
            printf("HEAD->");
        }
        printf("%d->",temp->P.PID);
        temp = temp->next;
        if(temp == NULL){
            printf("NULL\n");
        }
    }
}