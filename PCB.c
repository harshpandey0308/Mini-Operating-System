#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"PCB.h"

PROCESS p_table[10];
int p_count;

static short nextPID = 0;

char *p_st[] = {"NEW" , "READY" , "RUNNING" , "BLOCKED" , "WAITING" , "TERMINATING"};

int incre_pc(int init_pc){
    init_pc++;
    return init_pc;
}

int create_process(char* name){
    PROCESS p = {0};
    p.PID = rand()%10;
    for(int i=0 ; i<p_count ; i++){
        if(p.PID == p_table[i].PID){
            p.PID = nextPID++;
        }
    }
    strcpy(p.P_NAME , name);
    p.PC = incre_pc(0);
    p.priority = p_count;
    p.state = NEW;
    p_table[p_count] = p;
    p_count++;
    return p.PID;
}

void display_process(char* name){
    for(int i=0 ; i<p_count ; i++){
        if(strcmp(p_table[i].P_NAME , name) == 0){
            printf("%s %15s %15s %15s %15s\n","PID","P_NAME" , "PRIORITY","STATE" , "PC");
            printf("%d %15s %10d %20s %17d.\n",p_table[i].PID , p_table[i].P_NAME , p_table[i].priority , p_st[p_table[i].state] , p_table[i].PC);
            return;
        }
    }
    printf("PROCESS IS NOT IN THE PROCESS TABLE.\n");
}

void display_pTABLE(){
    printf("%s %15s %15s %15s %15s\n","PID","P_NAME" , "PRIORITY","STATE" , "PC");
    for(int i=0 ; i<p_count ; i++){
        printf("%d %15s %10d %20s %17d.\n",p_table[i].PID , p_table[i].P_NAME , p_table[i].priority , p_st[p_table[i].state] , p_table[i].PC);
    }
}

int Process(char *name){
    return create_process(name);
}