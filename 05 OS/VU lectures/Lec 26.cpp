/*
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

Definations of functions

void pickup(int i) {
    state[i] = hungry; 
    test(i);
    if(state[i] != eating){
        self[i].wait();
    }
}

void test(int i){
          
    if((state[i+4]%5)!=eating) && (state[i] == hungry)  // check right side philossphor eating or not and my state  hungry or not
    && 
    (state[(i+1)%5] != eating) // check left side philossphor eating or not
    {
        state[i] = eating; // if not, then make self to eating
        self[i].signal(); // get out from wait state.
    }

}

void putdown(int i) {
    state[i] = thinking;
    left and right neighbors testing
    test((i+4)%5); // call test function to the right neighbor of i process. This will go in test function def and check that right right neighbor eating or not. and then check param passed process hungry or not. If hungry and right side is not eating then make it to eating. What about its left? its left is definately mine who finish and then checking
    test((i+1)%5);  // Same goes for left
}

*/


/*
Deadlock:
In simple words, When 1 process waiting for resource to continue its execution but that resource is
already occupied by another process which is also waiting for the resource which is occupied by 
the 1st process. So both never complete. So they are in deadlock

Def:
A set of blocked processes each holding a resource and waiting to
acquire a resource held by another process in a set.

Example:
System has 2 tape drives.
-> P1 and P2 each hold one tape drive and each needs another one. So deadlock.

2) Semaphore A and B.
Initializing to 1
            p0           p1
            wait(A);      wait(B);
            wait(B);      wait(A); 
At some point, p0 will wait for B and P1 wait for A, so deadlock.
*/

/*
The dining philosophers problem,,,
All philosophers become hungry at the same time, pick up the chopsticks on their
right and wait for getting the chopsticks on their left.
So all will remain wait.
This is deadlock.

4) A single road having 2 cars in front of each other. Both are waiting to
take reverse by another. so this is deadlock.


If deadlock occurs then it can be resolved if one car backup (preempt resources and rollback)
Several cars may have to be backed up if a deadlock occurs.
Starvation(same car always go back) is possible.
*/



/*
System Model:
Resources types R1, R2, ... Rm (CPU cycles, memory space, I/O devices).
Each Resources type Ri has Wi instance. Means R1 is resource of disk drives. Then it can have 3 disk drives in it which can be written as W3.
Each process utilizes a resource as follows:

                    request -> use -> release
*/

/*
Deadlock characterization:
Deadlock can arise if 4 conditions hold simultaneously.

Mutual Exclusion: Only 1 process at a time can use a resource

Hold and Wait: A process holding at least one resource is waiting to 
acquire additional resources held by other processes.

No Preemption: A resource can be released only voluntarily by the process
holding it, after that process has completed its task.

Circular wait:  There exists a set {p0, p1, ... pn, p0} of waiting processes
such that p0 is waiting for a resource that is held by P1, P1 is waiting
for a resource held by P2 ... ,Pn-1 is waiting for a resource held by Pn,
and p0 is waiting for a resource held by P0.
SO,
p0 => p1 => p2 => ... => pn => p0
*/


/*
Resource Allocation Graph:
A set of vertices V and a set of edges E. 
V is partitioned into 2 types:
P = {P1, P2, Pn}
R = {R1, R2, Rm}

E = {Request edges, Assignment edges}
-> Request edge: Pi --> Rj
-> Assignment edge: Rj --> Pi
*/

/*
Resource Allocation Graph:
process ==> Circle
Resource ===> Rectangle with small dots showing instances
Pi requests instance of Rj ==> Circle ----> Rectangle
Pi holding an instance of Rj ==> Circle <---- Rectangle

Lec 26 time 41:06,,, See graphically last 10 mints.
*/


/*
Graph is given you have to check weather the deadlock occur or not?

P1, P2, P3
R1(1 instance), R2(2 instance), R3(1 instance), R4(3 instance)

Let's start from p1;

P1  having R2(1) and requesting R1. But R1(1) and R2(2) is occupied by the P2.
P2 is requesting R3 but R3 is occupied by the P3.
So, Will deadlock occurs?
No, Because  p3 will release the R3 after sometime.
P2 will get run and release its resources R1 and R2.
P1 will use R1 and finish.
Reason:
Mutual Exclusion: Each process having single resource
Hold and wait: P3 is not waiting
no preemptive: Not taking forcefully the resource from process.
Circular: A complete cycle is making.



Deadlock can occur in the same situation when P3 is also requesting a
resource which is occupied by some other process.
For example, Take above and add P3 is requesting R2.
R2 had only 2 instances which is already allocated. And they will get free
when p1 and p2 get run. They will only run when p3 release the R3. SO deadlock.
Reason:
Mutual Exclusion: Each process having single resource
Hold and wait: Every process is on hold and wait.
no preemptive: Not taking forcefully the resource from process.
Circular (cycle): A complete circle is making.
*/

/*
Generally we can say that whenever we have to find the deadlock then
we can check these things:
1) if graph contains no cycles => no deadlock
2) if graph contains a cycle => 
    -> If only 1 instance per resource type then deadlock
    -> if several instances per resource type, possibiliy of deadlock.
*/

// NOTE: Maybe have cycle but no deadlock.