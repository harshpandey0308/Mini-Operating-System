#include<stdio.h>
#include"PCB.h"
#ifndef SCHEDULER_H
#define SCHEDULER_H

typedef struct cpu{
    __int16 PID;
    __int8 PC;
    __int16 REG[10];
    STATE cpu_state;
}CPU;

extern CPU c1;

void FCFS();

#endif