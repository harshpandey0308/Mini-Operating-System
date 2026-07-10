#include<stdio.h>
#include"PCB.h"
#include"queue.h"
#include"scheduler.h"
#include"C_S.h"


void scheduler(PROCESS *p){
    CPU *c;

    c->instr_no = 4;
    c->reg_count = 4;
    c->has_IO_call = 0;

    restore_context(&c , &p);

    STATE current_state = execute(&c);

    if(current_state == BLOCKED){
        PROCESS *q = save_context(c);
        q->state = BLOCKED;
        enque(q , &waiting_queue);
        deque(&ready_queue);
        restore_context(&c , &p);
    }
    else if(current_state == TERMINATED){
        deque(&ready_queue);
        restore_context(&c , &ready_queue.head->P);
    }
    else{
        printf("PROCESS FINISHED.\n");
        c->current_process->state = TERMINATED;
    }

}