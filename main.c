#include<stdio.h>
#include<stdlib.h>
#include"PCB.h"
#include"scheduler.h"
#include"C_S.h"
#include"queue.h"

CPU c = {0};

int main(){
    Process("chrome");
    Process("META");
    Process("Instagram");
    Process("Facebook");
    Process("vscode");
    Process("Anthropic");
    Process("Chatgpt");
    Process("Google");

    printf("******BEFORE ENTERING READY QUEUE*******\n");
    printf("\n");
    display_pTABLE();
    printf("\n");

    enque(&p_table[0] , &ready_queue);
    enque(&p_table[2] , &ready_queue);
    enque(&p_table[5] , &ready_queue);
    enque(&p_table[7] , &ready_queue);

    print_queue(&ready_queue);

    c.reg_count = 4;
    c.instr_no = 5;
    c.has_IO_call = 0;

    NODE *temp;

    while(!is_empty(&ready_queue) || !is_empty(&waiting_queue)){
        //printf("the new process is %s with pid %d\n",ready_queue.head->P->P_NAME , ready_queue.head->P->PID);
        printf("===========KERNEL TICK===========\n");
        print_queue(&waiting_queue);
        remove_completed_io();
        printf("checking ready queue.\n");

        if(ready_queue.head == NULL){
            printf("IDLE CPU\n");
            continue;
        }
        
        temp = deque(&ready_queue);
        PROCESS *p = temp->P;

        scheduler(&c , p);
        printf("process %s is executed\n",temp->P->P_NAME);
        //print_queue(&ready_queue);
        free(temp);
        //print_queue(&waiting_queue);
    }

    printf("all process scheduled and executed properly.\n");

    print_queue(&ready_queue);

    print_queue(&waiting_queue);

    display_pTABLE();

    return 0;

}