/*
Busy Waiting:

Processes wait by executing COU instructions:
Problem: Wasted CPU cycles
Solution: Modify the defination of the semaphore
*/

/*
Sempahore new implementation:

typedef struct {
    int value;
    struct process *L; // Addition of list
} semaphore;

Assume 2 simple operations:

block() => suspends the process that involves it.
wakeup(P) => resumes the execution of a blocked process P.
*/

/*
The negative value of S, value indicates the number of processes waiting to the semaphore

A pointer in the PCB needed to maintain a queue of processes waiting for a semaphore. 

NOTE: Queue addition with semaphore is for that whenever process is wait instead of using CPU cycles send them to semaphore list and block using block() and again get when turn using wakeup(p)
*/


/*
Semaphore operations are defined as:
void wait(semaphore S){
    S.value--; // decrement the value (if value is -1 then means 1 process in list waiting for CS, and similarly for other processes)
    if(S.value < 0) {
        add this process to S.L;
        block(); // which calls the kernel to add the process to the list associated with the semaphore
    }
}


void signal(semaphore S){
    S.value++;
    if(S.value <= 0){
        remove process P from S.L;
        wakeup(P); 
    }
}
*/

/*
Two implementation:
-> Busy waiting version is better when critical sections are small
and queue-waiting version is better for long critical sections (when
waiting is for longer periods of time).
*/

/*
Process Synchronization:
-> Execution statement B in Pj only after statement A has been
executed in Pi.

SO,
Semaphore S is initialized to 0.
    pi              pj
    .               .
    .               .                
    A              wait(S)  
    signal(S)       B

Pi and Pj executed concurrently. For example Pj is faster than Pi then it
may run the B statement first. But this is what we do not want.
So we make wait call. which decrement the S to -1 and add the process in L
while on the other A would be executed as we want.After A, its call signal
which increase the -1 to 0 and its condition get true which make it to call the wakeup.
*/

/*

Now we have 3 processes. P1, P2 and P3 having S1, S2 and S3 respectively.
We want to execute S3, S2 and S1 sequenetically.
So,
Semaphore A =0 and B = 0.
    p1              p2          p3
    .               .           .
    .               .           .     
    .               .           .
    wait(S)       wait(B)       S3
    S1                S2          signal(B)
    .                signal(A)    .
    .                .            .
    .                .            .
*/

/*
Problems with semaphores:

-> Semaphores provide a powerful tool for enforcing mutual exclusion
and coordinating processes.
-> But wait(s) and signal(s) are scattered among several processes.
Hence, difficult to understand their effects.

NOTE: DeadLock, Starvation and mutual exclusion can happen because of the
incorrect use of wait and signal operations.
*/ 


/*
DeadLock and Starvation:
A set of processes are said to be in a deadlock state if every process
is writing for an event that can be caused only by another process in the
set.
Mean: Both processes waiting for each other to done something so that they can do their furthur processes.
=> Traffic deadlock
=> One-Way bridqe crossing

Starvation(infinite blocking) due to unavailability of resources.
For Example: 1 process call wait 2 times. then it will not allow the
other process to enter the CS. Detail agay ha
*/


/*
DeadLock:
p0              p1
wait(S);        wait(Q);
wait(Q);        wait(S);
.                  .
.                  .
.                  .
signal(S);        signal(Q);
signal(Q);        signal(S);

Suppose process are running with same speed.
p0 make the S sempahore to -1. and waiting in queue.
p1 make the Q sempahore to -1 and waiting in queue.
p0 is waiting from p1 to perform signal on the Q semaphore
p1 is waiting from p1 to perform signal on the S semaphore

SO, waiting for a signal but they are not able to do that.
SO this deadlock.

*/


/*
Starvation (infinite Blocking)
p0                  p1
wait(s)             wait(s);
.
.
.
wait(s)             signal(s)

p1 is correct.
p0 is incorrect.
because p0 has wait after wait but instead should have signal after wait.

SO, 
p0 make wait and add process to L.
Next it has to call signal but instead call wait again then condition of p1 
remain incorrect so remain spinning.
Similary, p0 also remain spinning.
SO no furthur can done.
*/

/*
Violation of Mutual Exclusion:
p0                  p1
signal(s)         wait(s);
.
.
.
wait(s)             signal(s)


wait instead of signal in p0. but here p1 is in CS and p0 also call the
signal and enter the CS.
DO no mutual exclusion.
*/


/*
Cause: Programming errors due to the incorrect use of wait() and signal()
operations.

Solution: Higher level language constructs such as critical region (region statements) and moniter.
*/

/*
Types of semaphores:
Counting semaphores: integer value can range over an unrestricted integer domain.
Binary  semaphores: integer value cannot be > 1; can be simpler to implement.
*/