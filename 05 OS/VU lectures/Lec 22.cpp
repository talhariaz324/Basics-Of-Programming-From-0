/*
A good hardware solution for the critical section is this.
Algorithm variables are:
key --> local
lock var and waiting array --> global 

All variables are set to false.

do{
    waiting[i] = true; // When 1st process come make its array var to true.
    key = true; // key also make true
    while (waiting[i] && key){ // condition true.

        key = TestAndSet(lock); // key is false now because function return the lock actual value as here is false. As this while loop it again check condition and condition become false.
    }
    waiting[i] = false; // AFter getting condition false it come out the loop and make its waiting array var to false and then enter the CS.
        Critical Section
}

NOTE: What if some other process come for entering in the CS. Lets discuss after discussing the remaining part of algorithm

After CS what process will do:
j = (i + 1) % n; // i is the process which come from the CS. Now incrementing that i to +1 and make modulus and store in j. You can say that j is the next process
while( ( j != i) && !waiting[j]){ // here we are looping through all the processes after i. Suppose i process was 3 then we loop from 4 to 6 and then 1 and 2. at 3 condition become false. !waiting condition checking either the process waiting for the CS or not.
    j = (j + 1) % n; // If above condition true then next process check.
}
if (j == i){ // If no other process want to enter then of-course j process will become to i. after looping.
    lock = false; // make lock to false and allow neutral behaviour to enter.
}else{ // if some process wants to enter the CS
    waiting[j] = false; // make its waiting to false which will allow this process to enter CS because above while loop become false and allow it to enter the CS.
}

*/


/*
Is that algo good?

Mutual Exclusion: Satisfied, because if some process is in CS then it already run the testAndSet. testAndSet make the lock true. For the next process testAndSet return true. so key remain true. Each process in CS.
Progress:Satisfied,  Finite Time, and no remainder section is contributing in the process entering in the CS.
Bounded Time: Satisfied, Single Statement allow the other process to enter the CS. because we loop for all processes 
*/

/*

Now see Operating system solution for CS. It has system calls for handling.

Semaphores:
-> Synchronization tool
-> Available in OS
-> Semaphore S - integer variable that can only be accessed via 2 indivisible (atomic)
operations, called wait and signal.

wait semantics:
wait(s){
    while (S <= 0){
        ;
    }
    S--;
}

Signal(S){
    S++;
}
*/


/*
n-processes CS problem:
Share data:
    semaphore mutex = 1;
Structure:
do{
    wait(mutex); //  mutex is 1 which is not <=0 so false so it will decrement to 0 and enter the  CS
        CS
    signal(mutex); // After CS again increment to 1
    remainder section 
}while(1);

NOTE: when process enter then wait make mutex to 0 and enter CS. At the same time when other process want to enter then while condition of wait true because mutex is 0. so it will wait.
But When after CS process make the mutex to 1 and then wait condition false.
*/


/*
Is it Good?
Mutual Exclusion: satisfied because each at time
Progress: Finite time and no involve remainder section
Bounded Waiting: Maybe the process after CS again go and again enter the CS and other process may remain stop because we are not handling this hole. so not satisfied.
*/


/*
Operations (wait and signal operations) are the parts of OS.
How can we perform them atomically?
2 Conditions:
Uni-Processor Environment:
    inhibit interrupts before executing codes for wait() and signal()
Bus Based Multi Processor Environment:
    Lock the data bus
    Use a software solution (If we think its a CS problem itself and we can solve it with previous solutions like bakery algo)
*/


/*
Busy Waiting:
Processes wait by executing CPU instruction

Problem? Wasted CPU cycles

Solution? Modify the definition of semaphore.
*/


/*
We can solve this busy waiting problem with semaphore modification
Make it struct


typedef struct {
    int value;
    struct process *L; // Addition of list
} semaphore;


Assume 2 simple operations:

block() => suspends the process that involves it.
wakeup(P) => resumes the execution of a blocked process P.


The negative value of S, value indicates the number of processes waiting to the semaphore

A pointer in the PCB needed to maintain a queue of processes waiting for a semaphore. 

NOTE: Queue addition with semaphore is for that whenever process is wait instead of using CPU cycles send them to semaphore list and block using block() and again get when turn using wakeup(p)
*/