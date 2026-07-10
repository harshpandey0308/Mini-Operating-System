#include"queue.h"
#include"PCB.h"
#include"scheduler.h"

#ifndef C_S_H
#define C_S_H

CPU *restore_context(CPU *c , PROCESS *p);

int execute(CPU *c);

PROCESS *save_context(CPU *c);

#endif