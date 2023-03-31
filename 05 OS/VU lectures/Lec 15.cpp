/*
Today we are going to cover process scheduling algorithm is 
SJF => Shortest Job First
=> It will give CPU to the process which has the shortest CPU Burst. 
Two Types of SJF:
1) NON-Preemptive ==> Once CPU given to a process it cannot be preempted until it completes its CPU burst.
2) Preemptive (also known as Shortest remaiaining cpu burst) ==> If a new process arrives with CPU burst length less than
remaining time of current executing process, It stops the process and give process to the process which has less
 CPU Burst or remaining CPU Burst of previous Processes.

 CPU BURST will be check every-time when the new process arrives and when current process terminates/ completes its execution.

 SJF is optimal non-preemtive scheduling algorithm, gives minimum average
 waiting time for a given set of processes.

*/


/*
Example NoN-Preemptive SJF:
Process         Arrival Time        Burst Time
P1              0.0                 7
P2              2.0                 4
P3              4.0                 1
P4              5.0                 4


Gantt Chart: Video 10:29
NOTE: After P1, remaining processes also come in ready queue because p1 ends at 7. 
SJF now look for smallest CPU burst and execute that process which has small CPU burst.

p1 execute, p3 and then p2 and p4 same CPU burst then it will execute the p2 because it arrive first.
Waiting Time: p1 = 0, p3 = 7 - 4 = 3, p2 =  8 -2 = 6, p4 = 12 - 5 = 7
Avg Waiting Time = (0 + 6 + 3 + 7) / 4 = 4
*/




/*
Example Preemptive SJF:

Process         Arrival Time        Burst Time
P1              0.0                 7
P2              2.0                 4
P3              4.0                 1
P4              5.0                 4

Gantt Chart: Video 16:18

CPU BURST will be check every-time when the new process arrives and when current process terminates/ completes its execution.

P1 executes foe 2 CPU Bursts and process arrives.
Schedualer checks CPU Bursts and remaining CPU Bursts.
At 2.0 we have p2 with 4 CPU Bursts and p1 with 5 remaining CPU Bursts.
SJF executes p2, after 2 bursts again new process arrives
Schedualer checks CPU Bursts and remaining CPU Bursts.
At 4.0 we have p2 with 2 CPU Bursts and p1 with 5 remaining CPU Bursts and p3 with 1 burst.
SJF executes p3, after 1 bursts again new process arrives and p3 also done its execution.
At 5.0 we have p2 with 2 CPU Bursts and p1 with 5 remaining CPU Bursts and p4 with 4 burst.
SJF executes p2, now there is no process coming so it executes all.
Then p4 and then p1.


How to calculate Waiting Time of this?

Finalize time of process - arrival time - burst time 

p1 = 16 - 0 - 7 = 9
p2 = 7 - 2 - 4  = 1
p3 = 5 - 4 - 1 = 0
p4 = 11 - 5 - 4 = 2



Avg time = (9  + 1 + 0  + 2) / 4 = 3
 

*/



/*
Question: CPU can only check the CPU burst while it executes the process.
But how schedular will know the CPU Bursts of processes before executing.
Actually, Schedular estimates the CPUBursts of processes.
Schedular can only estimates the length of the next CPU burst.
This estimation is done by using the length of the previous CPU bursts, using exponential averaging.
*/


/*
Exponential averaging:
Estimation based on historical data.
Some symbols:

NOTE: t shows actual CPU burst and τ shows estimate.
I am saying current and recent and previous process for the same process because this is current because we are still estimating next. 

tn = Length of nth CPU burst (current) here is its actual burst not estimate because it is already done.
τn+1 (torque n + 1) = Estimation of n + 1 CPU burst (next and here making estimation)
α should be between 0 and 1. Constant you can say.
τn => Estimation of n (current)
TOTAL Equation for the estimation of next process is:
τn+1 = αtn + (1 - α) τn
estimate of next = alpha *  actual burst of recent process (maybe say current) + 1 - aplha * estimate of recent process (current)


After breaking estimation of the current/ recent process you can get last equation.
Now, alpha value can be 1 or 0;

if aplha = 0
Then according to equation, estimation of next process  = estimation of previous process/ current / recent process 
if alpha  = 1

Then according to equation, estimation of next process  = actual CPU Burst of previous process/ current / recent process 



But for making balance we take 1/2 value for alpha.

When we put alpha value in the last equation we get then we will see that
most recent process CPU burst is divided by 2 and its recent by 4 and its recent 8 and so on.

Its getting low value for more recent processes sp it is known as exponential averaging.


This is how estimating done. 

*/



/*
Priority Scheduling/ Algorithm:

A priority Number (integer) is associated with each process.
Then CPU is allocated to the process with the highest priority( smallest integer is equal to highest priority) 
Types:

preemptive 
non preemptive


SJF example of Priority Scheduling.
Smallest CPU burst is this integer for priority.
In a non preemptive Highest priority process which is actually the CPU burst will be executed first. first it completes its execution and then it will allow other higher priority process to execute in memory.
In preemptive, highest priority process which is actually again the CPU burst execute the process the memory and if any highest priority new process come then it stopped the current process and start executing execution of the new process and this keep going until the new highest priority process coming.


Problems:
Starvation: In priority scheduling we have a problem this problem is known as starvation. 
The problem is that in priority scheduling all the highest priority
processes always executed first and the processes which has low priority
they will not get executed because highest priority processes is coming
again and again and the low process priority process is not getting
executed because of their low priority so this is the problem which we call this starvation.


Solution:
So the solution of this problem is aging. aging is the process in which
we increase the priority of the process after some time this time is set
by the system admin during boot. so all the processes which has low 
priority their priority  are going to be increased/high after some time and they will get
executed because of their new priority.


Mean older processes are also now able to serve by CPU because we increased the priority.

For Example: 15 sec.. AFter every 15 sec, it will increase the priority of older processes.
*/