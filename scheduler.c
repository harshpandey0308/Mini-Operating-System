#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"PCB.h"
#include"queue.h"
#include"scheduler.h"

CPU c1;


void FCFS(){
    NODE* temp = peek();

    if(temp == NULL){
        printf("NO PROCESS IS IN THE READY QUEUE. CPU IS IN IDLE MODE.\n");
        return;
    }

    while(temp != NULL){
        strcpy(c1.name , temp->P.P_NAME);
        c1.PC = temp->P.PC;
        c1.PID = temp->P.PID;
        for(int i=0 ; i<3 ;i++){
            c1.REG[i] = rand()%10;
        }
        c1.instruct_no = 4;
        c1.cpu_state = RUNNING;

        printf("-------------CPU--------------\n");

        printf("PROCESS NAME : %s\n",c1.name);

        printf("PROCESS ID : %hd\n",c1.PID);

        for(int i=0 ; i<c1.instruct_no ; i++){
            printf("INSTRUCTION %d is executing , PC : %hhd\n",i,c1.PC);
            c1.PC++;
            printf("REG %d : %hhd.\n",i+1 , c1.REG[i]);
        }
        printf("PROCESS EXECUTING.....\n");

        printf("PROCESS IS TERMINATING.\n");

        c1.cpu_state = TERMINATED;

        printf("\n");

        printf("-----------------------END-------------------\n");

        //print_queue();

        printf("\n");

        NODE* temp1 = temp->next;
        deque();
        temp = temp1;
    }
}