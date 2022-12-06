/*
Types of semaphores:
Counting semaphore: integer value can range
over an unrestricted integer domain.

Binary semaphore: integer value cannot be > 1;
can be simpler to implement.
*/

/*
Implementing a counting semaphore
Data Structure:
binary-semaphore S1, S2;
int C;

initialization:
S1 = 1
S2 = 0;
C = initial value of semaphore S


NOTE: Remember whenever make the semaphore 1 then it means here we are make sure the mutual exclusion that no other process can do this while 1 process is already doing.
Semantics of wait for this:
wait(S):

        wait(S1); // S1 is 1 and set to wait so here is mutual exclusion handling
        C--; // suppose the value of C is 5 (now 4)
        if(C < 0){
            signal(S1); // release the S1 for other processes
            wait(S2); // the calling process is going to start waiting on S2.
        }
        signal(S1); // release the S1 for other processes

Semantics of signal for this:
wait(S1); // mutual exclusion
C++; // increment
if(C <= 0){ // if less or equal then it means the some process is waiting on the semaphore S2
    signal(S2); // spining processes comes out of it
}else{ 
    signal(S1); // release for other processes
}
*/


/*
Classical Problems of Synchronization:
1) Bounded Buffer Problem
2) Readers and Writers Problem
3) Dining Philosophers Problem
*/


/*
Bounded Buffer Problem
Producer 
Consumer
Buffer can be full or empty

Solution using the semaphore.
Shared Data:
semaphore full, empty, mutex;

initialization:
full = 0, empty = n, mutex = 1;
NOTE: initially full is 0 because buffer has nothing.
      empty is to n means buffer is complete empty.
      mutex is set to 1 for ensure the mutual exclusion.

Producer Process:
do{
    produce an item in nextP
    wait(empty); // call wait to decrement the value of empty of buffer
    wait(mutex); // call wait to check for mutual exclusion
    ...
    add nextP to buffer
    ...
    signal(mutex); // to release for the other processes
    signal(full); // increment the value of full by 1 because producer add  
}while(1);

Consumer Process:
do{
    wait(full); // decrement the value of full
    wait(mutex); // mutual exclusion
    ...
    remove an item from buffer to nextP
    ...
    signal(mutex); // available for other proccess 
    signal(empty); // increment the empty value
    ...
    consume the item in nextC
    ...
}while(1);
*/


/*
Readers and Writers Problem:
Shared Resource
We want to readers to read. But dont want writer to write when 
readers are reading.
So we can say,
Multiple readers can read but only 1 write can use the shared resource.

2 Types of Readers and Writers Problem:
1) First Readers and Writers Problem
2) Second Readers and writers Problem

First Readers and Writers Problem:
If a reader is ready, it waits for the minimum amount of time.
No reader will be kept waiting unless a writer has already obtained
permission to use the shared object.


Second Readers and writers Problem:
If a writer is ready, it waits for the minimum amount of time.
Means, writer has to wait for the readers to read and then it
will be allowed to write. Other new requests will not be entertain
after writer request.

Solution First Readers and Writers Problem:
Shared data:
    semaphore mutex, wrt;
initialization:  
mutex = 1, wrt = 1; // Both will be use for mutual exclusion
readcount = 0;

Writer Process:
wait(wrt); // mutual exclusion
...
writing is performed
...
signal(wrt); // release 


Reader Process:
wait(mutex); // mutual exclusion
readcount++; // maintaining counter to check how many reads
if(readcount == 1){ // if 1st read then 
    wait(wrt); // make sure to wait the wrt
}else{
    signal(mutex); // otherwise release
}
...
reading is performed
...
wait(mutex); // mutual exclusion
readcount--; // decrement reading counter
if(readcount == 0){ // now last read
    signal(wrt); // last read will release for the writer
}else{
    signal(mutex); // release for other readers
}
*/


/*
Dining Philosophers Problem:
Five philosophers who spend
their lives just thinking and
eating.

Only five chopsticks(chinees earting spoon) are available to the philosophers.

Each philosopher thinks. When he becomes hungry, he sits down and picks up the
2 chopsticks that are closest to him and eats.

After a philosopher finishes eating, he puts down the chopsticks and stat to think.


Diagram:

            1                      2
    Think for a while -----> Pick up chopsticks
        ^                              ^
        .                              .
        .                              .
        .                              .
    Put down the chopstick <------ Exit for a while
            4                          3

Shared data: semaphore chopsticks[5];
initialized to 1
do{
    wait(chopstock[i]) // right
    wait(chopstock[i+1] % 5) // left
        eat
    signal(chopstock[i]);
    signal(chopstock[i+1]%5);
        think
}while(1);
*/