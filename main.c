#include<stdio.h>
#include"PCB.h"
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

    display_pTABLE();
    printf("\n");

    enque(p_table[0]);
    enque(p_table[2]);
    enque(p_table[5]);
    enque(p_table[7]);

    print_queue();

    deque();

    print_queue();

    return 0;

}