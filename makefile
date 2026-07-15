output : main.o PCB.o scheduler.o queue.o C_S.o
	gcc main.o PCB.o scheduler.o queue.o C_S.o -o os

main.o: main.c
	gcc -c main.c

PCB.o : PCB.c PCB.h
	gcc -c PCB.c 

queue.o : queue.c queue.h
	gcc -c queue.c

scheduler.o : scheduler.c scheduler.h
	gcc -c scheduler.c

C_S.o : C_S.c C_S.h
	gcc -c C_S.c 


clean : 
	rm *.o os
