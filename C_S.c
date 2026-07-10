#include<stdio.h>
#include<string.h>
#include"scheduler.h"
#include"C_S.h"

CPU *restore_context(CPU *c , PROCESS *p){
    c->current_process = p;
    
    c->PC = p->PC;
    for(int i=0 ; i<c->reg_count ; i++){
        c->REG[i] = p->REG[i];
    }
    c->current_process->state = RUNNING;
    return c;
}

PROCESS *save_context(CPU *c){
    PROCESS *p;
    p = c->current_process;
    p->PC = c->PC;
    for(int i=0 ; i<c->reg_count ; i++){
        p->REG[i] = c->REG[i];
    }

    return p;
}

int execute(CPU *c){
    printf("PROCESS PID = %d is executing.\n",c->current_process->PID);

    for(int i=0 ; i<c->instr_no ; i++){
        printf("PC = %d / INSTRUCTION NO. = %d executed.\n",c->PC , i+1);
        printf("REG %d = %d\n",i , c->REG[i]);
        c->PC++;
    }
    if(c->has_IO_call){
        printf("IO CALL ....\n");
        c->current_process->state = BLOCKED;
        return c->current_process->state;
    }
    printf("PROCESS IS EXECUTING ...\n");

    printf("PROCESS IS COMPLETED.\n");

    c->current_process->state = TERMINATED;

    return c->current_process->state;
}