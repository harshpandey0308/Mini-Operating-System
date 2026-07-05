#include<stdio.h>
#include<stdlib.h>
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
        c1.PC = temp->P.PC;
        c1.PID = temp->P.PID;
        for(int i=0 ; i<10 ;i++){
            c1.REG[i] = rand()%10;
        }
        c1.cpu_state = RUNNING;

        printf("PROCESS ID : %hd\n",c1.PID);

        printf("PROGRAM COUNTER : %hhd\n",c1.PC);

        for(int i=0 ; i<10 ; i++){
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