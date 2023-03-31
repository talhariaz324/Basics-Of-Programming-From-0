/*
I/O burst and CPU burst:
CPU burst: is the time when process is using the CPU
I/O burst: is the time when process is using the Input or reading a file or in some state when not using the CPU or when process is 
sleeping when waiting for some resource from the CPU etc.
*/


/*
Life of the Process:
Some time use the CPU burst and some time the I/O burst.
Sometime in wait state and sometime using the resource.

But What is histogram of the process:
If the process is the CPU bound mean then it will take more CPU time and less I/O time.
If the process is the I/O bound mean then it will take more i/O time and less CPU time


But as general we can say that the most of the processes has the small CPU burst.
*/



/*
CPU SCHEDULAR:
=> Short-term scheduler
=> Selects a process from among the processes in the ready queue.
=> Invokes the dispatcher to have the CPU allocated to the selected process.

Dispatcher gives control of the CPU to the process selected by the short-term
scheduler. this involves:
1) Switching of context. 
2) Switching of user mode.
3) Jumping to the proper location in the user program to start (or restart) it.


Dispatcher Latency: 
means time it takes for the dispatcher to stop one process and start another running/
Typically, a few microseconds but it depend on the CPU Architecture etc.
*/



/*
CPU scheduling decisions may take
place when a process:
1) Switches from running to waiting.
2) Switches from running to ready.
3) Switches from waiting to ready/
4) Terminates.

There are 2 types of scheduling:

1) Non-primitive:
1) Primitive:


NoN Primitive: In which we wait for the processor to d one its CPU burst and then we take CPU from it.

Primitive: In which we take the CPU from the process before it reach its CPU burst.
For Example: In priority of the process, you have to do that. So this is Primitive

NOTE:
1st and 4th decisions of CPU scheduling is actually the non primitive.



*/



/*
Scheduling Criteria:
CPU utilization => Keep the CPU as busy as possible.

Throughput => Of processes that complete
their execution per time unit.


TurnAround Time => Amount of time to execute
a particular process. Differential of starting and ending the process.

Waiting Time: Amount of time a process waits in the ready queue. It should be less.

Response Time: Amount of time it takes from when a request was submitted until
the first response is produced, not output (for time-sharing environment)
*/


/*
Optimization Criteria:

Maximize CPU utilization
Maximize throughout
Minimize turnaround time
Minimize waiting time
Minimize response time


NOTE: It can depend a little bit on the environment.
*/




/*
FCFS Scheduling: First come first serve

The process that enters the ready queue first is scheduled first, regardless of the
size of its next CPU burst.

Example: P1 , P2 , P3  processes.
Burst Time: 24, 3, 3

Suppose that processes arrive into the system in the order P1, P2, and P3

First come first serve is non Preemptive Scheduling.

P1 done 1st and then P2 then P3.
 Gantt Chart has stating and ending point of processes. 
 See Gantt Chart in video 14 at 43 min

Waiting Time: p1 = 0, p2 = 24, p3 = 27
TurnAround Time: p1 = 24-0 , p2 = 27 - 0, p3 = 30 - 0
Avg Waiting Time: (0 + 24 + 27) /3 = 17
*/



/*
FCFS Scheduling:
Suppose the p2 , p3, p1 sequence to arrive of processes
Burst Time: 3, 3, 24

Waiting Time: P2 = 0, p3 = 3, p1 = 6
 See Gantt Chart in video 14 at 49 min


Convoy Effect: short process behind the long process.
Long process consume more time and short processes which want
to use CPU only for short time. But they have to wait for long processes to be done in order to get CPU.

*/
