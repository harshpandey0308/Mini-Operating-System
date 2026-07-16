#include<stdio.h>
#include<stdlib.h>
#include"PCB.h"
#include"queue.h"
#include"scheduler.h"
#include"C_S.h"

void scheduler(CPU *c , PROCESS *p){
    printf("\n");
    printf("\n ---------------------PROCESS START------------------\n");
    printf("scheduling of process %s and pid %d.\n",p->P_NAME , p->PID);

    printf("STORING PROCESS IN CPU.\n");
    restore_context(c , p);

    //printf("PROCESS STORED , NOW PROCESS IS EXECUTING\n");

    STATE current_state = execute(c);

    if(current_state == BLOCKED){
        PROCESS *q = save_context(c);
        enque(q , &waiting_queue);
        q->state = BLOCKED;
        //printf("the process state is %d\n",q->state);
    }
    else if(current_state == TERMINATED){
        save_context(c);
        printf("THE PROCESS IS TERMINATED.\n");
        printf("-------------------process finished--------------------\n");
        printf("\n");
    }
}