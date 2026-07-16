#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"scheduler.h"
#include"C_S.h"

int io_update(PROCESS *p){
    //printf("checking and updating io.\n");
    //printf("process state : %d\n",p->state);
    if(p == NULL || p->state != BLOCKED){
        //printf("Process state : %d\n",p->state);
        return 0;
    }

    //printf("process is not null but blocked.\n");

    if(p->io_remaining > 0){
        p->io_remaining--;
        //printf("io remaining : %d\n",p->io_remaining);
    }
    if(p->io_remaining == 0){
        //printf("io completion.\n");
        return 1;
    }
    //printf("going back to original function...........\n");
    return 0;

}

void remove_completed_io(){
    NODE* prev = NULL;
    NODE* temp = waiting_queue.head;
    PROCESS* finished;

    //printf("checking io completion.\n");

    while(temp != NULL){
        //printf("the temp is %s\n",temp->P->P_NAME);
        int completed = io_update(temp->P);
        //printf("value of complete : %d\n",completed);
        //printf("PID : %d , PROCESS STATE : %d and io_remaining : %d\n",temp->P->PID , temp->P->state , temp->P->io_remaining);

        if(completed == 1){
            NODE* next = temp->next;
            finished = temp->P;

            if(prev == NULL){
                waiting_queue.head = temp->next;
                waiting_queue.tail = prev;
            }
            else{
                prev->next = temp->next;
                waiting_queue.tail = prev;
            }
            free(temp);
            temp = next;
            finished->state = READY;
            enque(finished , &ready_queue);
        }
        else{
            prev = temp;
            temp = temp->next;
            
        }
    }
}

CPU *restore_context(CPU *c , PROCESS *p){

    //printf("A:context storing.\n");
    c->current_process = p;
    //printf("B\n");
    //printf("c\n");
    c->PC = p->PC;

    if(c->current_process->PID == 2 && c->current_process->PC != 4){        //changes
        c->has_IO_call = 1;
    }
    else{
        c->has_IO_call = 0;
    }
    //printf("D\n");
    for(int i=0 ; i<c->reg_count ; i++){
        //printf("COPYING REGISTERS\n");
        c->REG[i] = p->REG[i];
    }
    //printf("state changed.\n");
    c->current_process->state = RUNNING;

    //printf("context restored.\n");
    return c;
}

PROCESS *save_context(CPU *c){
    PROCESS *p;
    p = c->current_process;
    p->PC = c->PC;
    p->state = c->current_process->state;
    printf("saving state , process state : %d\n",c->current_process->state);
    for(int i=0 ; i<c->reg_count ; i++){
        p->REG[i] = c->REG[i];
    }

    return p;
}

int execute(CPU *c){
    //printf("PROCESS PID = %d is executing.\n",c->current_process->PID);

    for(int i=0 ; i<c->instr_no ; i++){
        printf("PC = %d / INSTRUCTION NO. = %d executed.\n",c->PC , i+1);
        printf("REG %d = %d\n",i , c->REG[i]);
        c->PC++;

        if(c->has_IO_call){
            printf("IO CALL = %d\n",c->has_IO_call);
            c->current_process->io_remaining = 5;
            printf("-----------I/O CALL -> NEXT PROCESS IS SCHEDULING------------\n");
            c->current_process->state = BLOCKED;
            return c->current_process->state;
        }
        
    }
    
    printf("PROCESS IS EXECUTING ...\n");

    printf("PROCESS IS COMPLETED.\n");

    c->current_process->state = TERMINATED;

    return c->current_process->state;
}

