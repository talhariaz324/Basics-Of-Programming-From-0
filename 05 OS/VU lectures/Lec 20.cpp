/*
Algorithm No 3
This is the algorithm is combination of both
previous which we discussed before.

boolean flag[2];
int turn = 0;
*/


/*
do{
    flag[i] = true; // Means the process which want to enter in critical section. so it make its flag to true.
    turn = j; // Then it make the turn equal to other processes.
                    Suppose process 0 wants to enter critical section then flag[0] = true
                        and turn = 1;
    while(flag[j] && turn == j) ; // It shows that if the other process flag is also true and its turn also equal to its value then make the process to wait which want to enter in critical section
                As per our example, If process 1 flag is also true and obviously turn = 1 then process 0 is waiting until the process 1 set its flag to false. On false this condition fails then process 0 will enter its critical section.
        critical section
    flag[i] = false;
        remainder section
}while(1);


Now Suppose both processes arrive at the same time:

Both flags are true.
p0 wants to enter and p1 also wants to enter.
p1 turn = 1 or maybe p0 turn = 0 // nut here we assuming that turn =1 because it may end after p0 turn = 0
p1 flag also true.
condition is true so p0 waits until the p1 exit its critical section by making its flag to false.
and then p0 enters its critical section.


*/



/*
Mutual Exclusion:
if p0 is running in the critical section then p1 in waiting.
because turn  = 0 and flag of p0 is also true. so it waits to p1 to enter critical section until p0 exists.

So this is mutual exclusion. One process at a time in the critical section.

Progress:
Now Suppose both processes arrive at the same time:

Both flags are true.
p0 wants to enter and p1 also wants to enter.
p1 turn = 1 or maybe p0 turn = 0 // nut here we assuming that turn =1 because it may end after p0 turn = 0
let p1 flag also true.
condition is true so p0 waits until the p1 exit its critical section by making its flag to false.
and then p0 enters its critical section.


So 1 process in critical section must and that is deciding the other to enter in critical section.
There are 2 processes only so it is in finite time.
So also satisfy the condition of progress


Bounded Waiting:
How much time current process which is in the critical section is allowed to go in its critical section when other process req for crititcal section

Suppose p0 is in critical section
p1 sets its flag to true.
turn = 0
p0 flag true as well as turn == 0 so condition is true and p1 waits until the p0 exit its critical section.
Suppose we remove the remainder section and assume process p0 again go in its entry section and make its flag to true.
turn set to 1 now,
Now flag of p1 is true and the turn == 1; condition is true and now p0 stats spinning or waiting and p1 enters critical section

So this algorithm ensures stirct alteration. means when process leaves its critical section then it not come back to its critical section again.
It satisfy the bounded waitng because if process req then it has to wait single turn by the other process.




So good solution for 2 processes in critical section.
 
*/