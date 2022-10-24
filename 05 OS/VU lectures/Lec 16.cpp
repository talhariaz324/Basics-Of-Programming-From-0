/*
WHy SJF schedual is optimal in non-premmprive

Because SJF decreases in the wait times for short processes is much more
than increase in the wait times for long processes.

FOR EXAMPLE: 

It do the short process first and then large. Means short processes has
to wait less and increase a little time for the long process. 
So average waiting time is less than others schedualers so it is optimal.

*/



/*
Rounds Robin (RR) Schedualr.
It is preemptive....

Each process gets a small unit odf CPU time, called time slice or
quantum, which is usually 10-100 milliseconds. After this time has elapsed,
the process is preempted and added to the end of the ready queue.
And context switches give CPU to process which is at the head of the Ready queue.

WORST CASE:
=> If there are n processes in the ready queue, the time quantum is q, and 
context switch time is tcm, then no process waits more than (n-1)(q+tcm) time units.


=> Used in time-sharing systems where response time is an important performance criteria.


=> Performance:
    q large => If quantum is large then it will more close to FCFS because more processes will done their CPU burst in their quantum.
    q small => q must be large with respect to context switch, otherwise overhead is too high. Means if q is small then more context switch latency.
*/



/*
EXAMPLE:

Process         Brust Time---- Remainings
P1              53 ---- 33 ---- 13
P2              17
P3              68 ----- 48 ---- 28 --- 8
P4              24 ------ 4


Gantt Chart: 30:57

My Chart:
P1   P2   P3   P4   P1    P3     P4   P1    P3    P3
0 20  37   57   77   97   117    121  134   154    162


TurnAround Time     Waiting Time
134                 134-53 = 81
37                  37-17 = 20
162                 162-68 = 94
121                 121-24 = 97



Average Waiting Time = 73
Average Waiting Time is SJF = 38
Typically, higher average turnaround than SJF, but better response. 


*/



/*
Quantum vs Context Switch
Assume process brust is 10 times unit.
12         0
6          1
1          9


TurnAround Time is best when process done within brust time.
SO General,
Best Quantum size is in which more processes complete their brust.
And again we can caluculate the process CPU brust using history and make quantum,


For choosing Quantum size:
1) The context switch latency should not be more than 10 percent of quantum size.
2) More processes finish their cpu brust within brust.


Some OS make the quantum size variable. If the cpu brust is large then it make quantum size according to it and small then also acc to it.
*/




/*

Multi-Level Queue:

Ready Queue is partitioned into seperate queues:
-> foreground (interactive)
-> background ( batch )

and maybe more ready queue.
Each queue has its own priority and scheduling algorithm:
Here you can use 
foreground ==> RR (fast response)
background ==> FCFS (as good for batch processes)


Scheduling must be done across queues:
-> Fixed priority scheduling: serve all from foreground then from background.
-> Time Slice: each queue gets a certain percentage of CPU time, e.g 80%
to foreground in RR and 20% to background in FCFS.




MultiLevel Queues can be:

1) System Processes
2) interactive Processes
3) interactive editing processes
4) batch processes
5) student processes


More details in next lecture.

*/