#include<stdio.h>
#include"PCB.h"
#include"queue.h"

void save_context(PROCESS p){
    PROCESS q = {0};
    strcpy(q.P_NAME , p.P_NAME);
    q.PID = p.PID;
    q.priority = p.priority;
    q.PC = p.PC;
    for(int i=0 ; i<10 ; i++){
        q.REG[i] = p.REG[i];
    }
    q.state = WAITING;
}

void restore_context(){
    NODE* temp = head;

    while(temp->next != NULL){
        if(temp->P.state == WAITING){
            break;
        }
        temp = temp->next;
    }

}

void context_switch(){
    
}