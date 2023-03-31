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
Process will enter in its relevant queue acc to its priroty and choose queue of its priority.
If the process is in the some priority queue, then it will execute that particular again and again.
For fixing this starvation problem, we can do 2 things:
1) We can give fix time to each queue like 70% to this queue and 20% to this queue. (Means Algorithm  scheduler for scheduling queues themeselves) and each queue also has scheduler. 
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


/*
Unix System V Scheduling Algorithm

Kernel Priroty Levels:
Swapper                  |               
Waiting for I/O drivers  |  not interruptable
Waiting for Buffer       |
Waiting for inode.       |

Buffer Cache Management: is the part of the kernel whenever get read call from user it request buffer from some part of kernel. 
After getting buffer, disk driver read data using disk controller. This reading is of 1 sector. 1 sector contains 512 bytes. This bytes store into the buffer.
Suppose read system call request data of 20 bytes then 20 bytes from buffer sends to user and remaining bytes will remain in the buffer. Main purpose of this is that
next processes maybe required more 30 bytes then instead of doing mechnical work again of disk controller etc, we can directly send it from buffer.

inode: inode is the code which is given to unique file when created.
This code is given by the system.


Assumption: Suppose buffer is not available. Now buffer cache manager has to wait. As we know from above the disk I/O has high priority than buffer.
Suppose buffer is occupied by the write system call. As disk I\O has high priority than buffer so 
it will write file first and then release buffer and this buffer is use by the buffer cache manager which was in wait.

Now, What if we change to priority of disk I/O low and buffer to high.
Then buffer will require buffer but buffer occupied by the write system call.
and write system call is not done by disk I/O because disk I/O has less priority and waiting to done buffer first.
SO, This continues.  This lock is known as dead lock. 
More discussion later but the reason to discuss here is that we arrange
kernel level process in such a way to avoid dead locks and to minimize
bottlenecks.

                  |               
Waiting for TTT drivers  |   interruptable
Waiting for TTT input    |
Waiting for request.     |


Thershold Priority (int number) ===> is the number which is between the user and kernel processes priorty. User processes must be below the threshold priority so that
kernel processes and user processes not get mix. 

User Level Processes ==> Their Priority can change, They continues to change their priority. 


*/





/*
UNIX System V Scheduling Algorithm:
I/O processes has high priority than CPU processes in it.

=> The CPU usage of each process is updated every clock tick by the clock ISR. (interrupt service routine)
        Clock Tick is value which is increase by one at every 1/ powerLine of the process
        Power Line is different from region to region. Pakistan is 50 but we are assuming of 60 which north america.

=> Every Second (After 60 clockTicks), a decay function is applied to the CPU usage of each process in  the ready queue and current process.
        Decay (CPU Usage) = CPU Usage/ 2

=> Priority Number of each process is recomputed every second. 

=> Every second, the priority number of all those processes that are in the
main memory and ready to run is updated by using the following formula:

Priority# = (Recent CPU Usage) /2 + Threshold.Priority + nice
      NOTE:  High CPU usage will have higher priority number

nice: Positive value. nice is the number which is given by user. This is for increasing the priority number. 
User can increase the nice value but decrease at a specific level.
NOTE: Higher priority number then less priority.
NOTE: Low level routines/ software in kerne will have higher priority than upper level routines
NOTE: If 2 processes have same priority number and they are in same queue then 1st will run which arrives first. This can be in start and at end.
NOTE: FCFS and SJF is good for batch systems. Rounds Robin is good for time sharing systems
*/




/*
Example of clock tick, decay and priority:
45 mint Lec 17.
*/

