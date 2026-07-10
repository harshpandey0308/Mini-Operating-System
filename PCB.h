#ifndef PCB_H
#define PCB_H

typedef enum p_state{
    NEW,
    READY,
    RUNNING,
    WAITING,
    BLOCKED,
    TERMINATED
}STATE;

typedef struct p_NODE{
    int PID;
    char P_NAME[20];
    int PC;
    int REG[10];
    int priority;
    STATE state;
}PROCESS;

extern PROCESS p_table[];
extern int p_count;

int incre_pc();

int create_process(char* name);

void display_process(char* name);

void display_pTABLE();

int Process(char *name);

#endif