MINI OPERATING SYSTEM

This repository exploring all the concepts of operating system by implementing those concepts in c.

CONCEPTS EXPLORED:
   Process Control Block
   Ready Queue
   Scheduling algorithm : use FCFS (First Come First Serve) scheduling algorithm to schedule the processes to the CPU.FCFS is a type of scheduling algorithm where , the process which comes first in the RAM has a      chance to execute first. FCFS is non preempting and non priority based algorithm. Non priority means that if there is a process whose priority is greater than the priority of the process which comes first in       the RAM , still the second process(which comes first) will execute.
  
  Context Switch : This is a method which is used to preempt the process safely. Context switch first save the content of currently running process and insert that process in the waiting queue , after that it        starts the execution of the next process which preempts the previous process.  
