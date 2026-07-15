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

    while((temp = deque(&ready_queue)) != NULL){
        printf("scheduling process %s to cpu\n",temp->P->P_NAME);
        scheduler(&c , temp->P);
        free(temp);
    }

    printf("all process scheduled and executed properly.\n");

    if(is_empty(&waiting_queue)){
        printf("NO PROCESS IN THE WAITING QUEUE , ALL PROCESS EXECUTES SUCCESSFULLY.\n");
    }
    else{
        NODE* temp1;
        int itr = 1;
        while(waiting_queue.head != NULL){
            remove_completed_io();

            PROCESS *p = deque(&ready_queue)->P;

            scheduler(&c , p);
        }
    }

    print_queue(&ready_queue);

    print_queue(&waiting_queue);

    display_pTABLE();

    return 0;

}