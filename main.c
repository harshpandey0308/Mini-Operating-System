#include<stdio.h>
#include"PCB.h"
#include"scheduler.h"
#include"queue.h"

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

    deque(&ready_queue);

    print_queue(&ready_queue);

    NODE *temp = ready_queue.head;

    while(temp != NULL){
        scheduler(&temp->P);
        temp = peek(&ready_queue);
    }

    print_queue(&ready_queue);

    return 0;

}