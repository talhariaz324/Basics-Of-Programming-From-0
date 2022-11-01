/*
Critical Section Problem:
It can be occur in 2 type of processes.
1) Between 2 Processes 
1) Between N Processes 


Ok before discussing the algorithms of solution, let's discuss which parameters make solution good.
They are 3 numbers.
1) Mutual Exclusion: If a process is executing in its critical section, 
then no other processes can be executing in their critical sections.

2) Progress: If no process is executing in its critical section and some processes
wish to enter their critical sections, then only those processes that are not
executing in their remainder sections can decide which process will enter its critical section next
(The process which are in their remainder section can't take part in decision making of processes)
and this decision cannot be postponed indefinitely (decide within time).


3) Bounded Waiting: A bound must exist on the number of times that their processes are allowed
to enter their critical sections after a process has made a request to enter its
critical section and before that request is granted.
(If some process req to enter a critical section then other process which are already in critical section then how many time they should in critical section after the request of new process ).
*/



/*
Assumptions before talking about solution:
1) Assume that each process executes at a non zero speed. (Means every process will run maybe very small but run)
2) No assumption can be made regarding the relative speeds of the N processes. (Means we cant say that if p1 is running 5 times faster than p2 then my solution is good. Our solution should be free from this assumption)
*/

/*
Only 2 processes, p0 and p1
=> Processes may share some common variables to synchronize their actions. (in entry code may share variables.)
This is sharing but not updating the variables, because if update then it will be critical section code.
*/



// Solution of software base of critical section ======> 2 processes critical section problem

/*
Algorithm 1

initially turn = 0;
i is the value of processes which want to enter.
If value not equal to i then it means its not my turn. Other process is already running.
then ; this semicolon is means null and do nothing.
Other process which was in critical section after exit from critical section it set turn value to j means other process value.

do{
    while(turn != i)
        ;
    critical section
    turn = j;
        remainder section
}while(1);



Is this good?
No, Because it is satisfying 1st condition of mutual exclusion but not progress/
Because here other process is deciding to enter next process to enter in critical section after exit from critical section.

*/



/*
Algorithm 2

boolean flag[2]; // set initially to false
flag[i] = true // process i is ready to enter its critical section


flag is initially set to false.
When process want to enter in critical section then it make its flag is true.
then check either other process flag is true or false. if false then go for critical section.
If other process flag is true then null mean stop and wait other process to exit.
Other process while exit from critical section make its flag to false.
Then other process will start.
Code:
do
{
    flag[i] = true;
    while(flag[j])
        ;
    critical section
flag[i] = false;
    remainder section
}while(1);

Is it good?
No,
Its good for mutually exclusion.
Its also have satisfying remainder part of progress. But second part
of time which should be define. But here if 2 process arrive at same time
to use critical section then both sections true at same time. and no process in critical section and no allow other process to enter.
*/

// Good solution is next lecture.