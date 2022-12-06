/*
Dining Philosophers Problem:
Five philosophers who spend
their lives just thinking and
eating.

Only five chopsticks(chinees earting spoon) are available to the philosophers.

Each philosopher thinks. When he becomes hungry, he sits down and picks up the
2 chopsticks that are closest to him and eats.

After a philosopher finishes eating, he puts down the chopsticks and start to think.


Diagram:

            1                      2
    Think for a while -----> Pick up chopsticks
        ^                              ^
        .                              .
        .                              .
        .                              .
    Put down the chopstick <------ Exit for a while
            4                          3


Solution: We can say that philosopher will take the right chopstick and then left chopstick to eat.
But if all 5 philosophers get hungry at the same time then philosophers will take 5 chopstick and table left with no more chopsticks.
So, all philosophers waiting for the left chopstick, so this is the starvation and deadlock problem. 

Shared data: semaphore chopsticks[5];
initialized to 1
do{
    wait(chopstock[i]) // taking right chopstick
    wait(chopstock[i+1] % 5) // taking left chopstick
        eat
    signal(chopstock[i]); // drop right chopstick
    signal(chopstock[i+1]%5); // drop left chopstick
        think
}while(1);

As we already discuss the solution with this solution. So there are other multiple solutions which are:
1) Allow at most four philosophers to be sitting simultaneously at the table.

2) Allow a philosopher to pick up his chopsticks only if both chopsticks are
available (to do this he must pick them up in a critical section beacause if all philosopher do this then again cause the deadlock so do them in critical section(only 1 allow))

3) Use an asymmetric solution; that is, 

an odd philosopher picks up first
his left chopstick, whereas an even philosopher pick up his right chopstick and
then his left chopstick.
    -> In it, possiblity of starvation.
    Two philosophers who are fast eaters and fast thinkers, and lock the
    chopsticks before others everytime.

*/


/*
High Level Sync Constructs:
Shift the responsibility of enforcing mutual exclusion from the 
programmer (where it resides when semaphores are used) to the
compiler.
Why We need this?
because Above methods can do bugs because of the programmers mistakes.
So, we take this responsibility from the programmer to the compiler.

Now there are 2 types:
1) Critical Region
2) Monitor
*/

/*
Critical Region:
A critical region is a section of code that is always executed under 
mutual exclusion. Means only 1 process can be enter init.

Consists of 2 parts:
1) Variables that must be accessed under mutual exclusion.
2) A new language statement that identifies a critical region in which
the variables are accessed.

A shared variable v of type T, is declared as:
    v: shared T;
    region v when B do S;
Variable v is accessed only inside S when B is true and when S is being
executed, no other processes can access the variable v.
So, S is critical region. and v is variable under mutual exclusion.

When a process tries to execute the region statement, the Boolean
the region statement, the Boolean expression B is evaluated.
If B is true, statement S is executed. If it is false, the process
is delayed until B becomes true and no other process is in the region
associated with v.


Bounded Buffer Example:
Shared Data
struct buffer {
    int pool[n];
    int count, in, out;
}

Producer Process:
Produces process inserts nextP into the shared buffer
region buffer when (count < n){ //condition is B
    pool[in] = nextP; // added
    in:= (in + 1) % n; // increment acc to circular
    count++; // increment count
} 
Consumer Process:
Consumer process removes an item from the buffer and puts it in nextc
region buffer when (count > 0){
    nextc = pool[out];
    out  = (out+1)%n;
    count--;
}

What happens when 2 region statements are executed simultaneously?
region v when B do true S1;
region v when B do true S2;
They will be serialize mean compiler will run the 1st process and then 2nd acc to any scheduler most probably FCFS
*/


/*
Monitors:
High level sync construct that allows the safe sharing of an abstract data
type among concurrent cooperating processes.

NOTE: abstract data is the data whcih is use by the procedures(functions)
and then initialize them

Only one process at a time is active within a monitor.

monitor monitor-name{
    shared variable declaration
    procedure P1(param){...}
    procedure P2(param){...}
    ...
    {
        initialization code
    }
}

Monitor with condition variables:
Additional synchronization constructs are needed to model some
synchronization problems. They can be modeled with condition variables.
NOTE: some synchronization problems need this condition variables.

condition x,y;

Only 2 operations can be performed on condition variables, wait and signal
NOTE: this wait and signal is different from the semaphore wait and signal.

x.wait: Process invoking this operation is suspended until another
process invokes x.signal

x.signal: Resumes exactly 1 suspended process. If no process is suspended,
this will be null operation, i.e: the state of x is unaffected.
NOTE: More than 1 process can be suspended using same condition variable.
so that variable signal will only resume 1 process.

Monitor includes:
shared data
operations
initialization
entry queue of processes which want to enter
queues of processes which are suspended using condition wait.

Dining Philosophers Example:
monitor dp{
    enum {thinking, hungry, eating} state[5];
    condition self[5]; // condition variable array

behaviors
    void pickup(int i)
    void putdown(int i)
    void test(int i)

    initially thinking
    void init(){
        for(int i = 0; i<5;i++){
            state[i] = thinking;
        }
    }
}
*/
