#include"PCB.h"
#include"queue.h"

#ifndef SCHEDULER_H
#define SCHEDULER_H

typedef struct cpu{
    PROCESS *current_process;

    int PC;
    int REG[10];
    int reg_count;
    int instr_no;
    int has_IO_call;
}CPU;

void scheduler(CPU *c , PROCESS *p);

#endif