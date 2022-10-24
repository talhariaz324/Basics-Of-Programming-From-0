/*
MultiLevel Queues:
MultiLevel Queues can be:

1) System Processes
2) interactive Processes
3) interactive editing processes
4) batch processes
5) student processes


Suppose our process is of type interactive editing type so it will place in this queue.
It will remain in this queue during its lifetime.

If the process is in the some priority queue, then it will execute that particular again and again.
For fixing this starvation problem, we can do 2 things:
1) We can give fix time to each queue like 70% to this queue and 20% to this queue.
2) We can do aging, Mean process moves from queue to queue beacause of its priority.

This second step in which process is moving from 1 queue to other is actually the MultiLevel FeedBack Queue.

*/


/*
Multi level feedback queue scheduler defined by the following parameters:

A process can move between the various queues; aging can be implemented
this way:
1) How many Number of Queues
2) Scheduling algorithm for each queue


Method used to determine when to upgrade a process

Method used to determine when to demote a process.

Method used to determine which queue a process will enter when that
process needs service.

Remember that when process arrives then it will be first place in the 
top queue.

Example:
3 Queues:
        => quantum = 8
        => quantum = 16
        => FCFS

When a process arrives then it will be first place in the top queue whose 
algo is rounds robin whose quantum is 8.
If the process CPU brust is 8 or less then it will execute and terminate.
If not then it will place in next queue whose algo is rounds robin
whose quantum is 16.
If the process remaining CPU brust is less or equal to 16 then it will
execute and terminate. If not then it will place in next queue which 
algo is is FCFS.
*/



/*
UNIX System V Scheduling Algorithm:

=> MultiLevel Queue, priority queues with round-robin within each queue.
=> Quantum = 1 second
=> Priorites are divided into two groups/bands.
1) Kernel Group
2) User Group


Priorities in the Kernel Group are
assigned in a manner to minimize bottlenecks
We can minimize bottleneck by:
processes waiting in a lower-level routine higher priorites than those waiting
at relatively higher level routine.

For Example: In structure of OS device drivers has high priroty than File system etc.


In kernel priority:
High to Low priority, the bands are:
=> Swapper
=> Block I/O device control processes
=> File Manipulation
=> Character I/O device control processes
=>  User Processes



Priorities of processes in the kernel group remain fixed.

Priorities of processes in the user group are recalculated every second.

Inside the user group, CPU-bound processes has less priority than I/O bound processes.
*/
