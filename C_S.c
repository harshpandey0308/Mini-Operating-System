#include<stdio.h>
#include"PCB.h"
#include"queue.h"
#include"scheduler.h"

void save_context(CPU c){
    PROCESS q = {0};
    strcpy(q.P_NAME , c.name);
    q.PID = c.PID;
    q.PC = c.PC;
    for(int i=0 ; i<10 ; i++){
        q.REG[i] = c.REG[i];
    }
    q.state = WAITING;
    enque(q);
}

NODE* restore_context(NODE* t){
    NODE* temp = t;
    
    CPU c = {0};
    c.PID = temp->P.PID;
    strcpy(c.name , temp->P.P_NAME);
    c.PC = temp->P.PC;
    for(int i=0 ; i<10 ; i++){
        c.REG[i] = temp->P.REG[i];
    }
    c.cpu_state = RUNNING;
}

void context_switch(CPU c){
    save_context(c);
    if(head1->P.priority > head2->P.priority){
        restore_context(head1);
    }
    else{
        restore_context(head2);
    }

}