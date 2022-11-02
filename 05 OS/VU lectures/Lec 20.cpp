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


/*
N-Process Critical Section  Problem
=> Consider a system of n processes (p0,p1,p2.... pn-1)

=> Each process has a segment of code called critical section in which the process may change shared data.

*/


/*
Bakery Algorithm:

bakery Algorithm is the solution of the n-process critical section problem.
It is by Leslie Lamport

Before entering its critical section,
process recieves a ticket number.
Holder of the smallest ticket number
enters the critical section.

If processes Pi and Pj receive the same number, if i > j, then Pi is served
first; else Pj is served first. where i and j are the process id numbers.


The ticket numbering scheme always generates numbers in the increasing 
order of enumeration; i.e., 1, 2, 3, 4, 5 ...


Notations:
(ticket #, process id #)
(a,b < c,d) if a < c OR if a == c and b < d
Where a is the ticket number and b is the process id. 
where c is the ticket number and d is the process id.


max(a0,....,an-1) gives the larger number in a. or maybe greater. 


Data Structures
=> boolean choosing[n] // each process has slot in this array and set to true by the process before it is choosing number using max function and after choosing to false
=> int number[n]; // each process has slot in this array and the number which is selected by the process is store in the number array in its own slot.
These data structures are initialized to false and 0, respectively.
*/



/*
do{
    choosing[i] = true;
    number[i] = max(number[0], number[1], ..... number[n-1] + 1); // If largest is 10 then +1 add and store 11 in its slot.
    choosing[i] = false;
    Now we are looping through all the process for entering in the critical section.
    for(j = 0; j < n; j++){
        while(choosing[j]) ; // Means if the process is in mid of choosing number but still not then null(wait) here.
        If process choose slot is false
        while((number[j] != 0) && (number[j],j < number[i],i)); // Here checking ok choosing is false then check that in numbers array its value is 0 or not. if 0 then it means its from start and dont want to enter in critical section and if not zero then mean it want to enter and then we check that no process in process should be larger than my process.

        After this it will enter in critical section.

    }
        number[i] = 0;
         remainder section
}while(1);
*/


/*
Example:
If we have the multiple processes then they have to run simultaneously.
P0 is running in the critical section because of condition as we discussed above.
Simultaneously, P1 req then in the second while loop in for loop checks other processes.
So the condition become true and P2 will null(wait).
Similarly goes for P3, P4.
When P0 left critical section, it sets i to 0 then condition in second while loop of for loop become false and the process enters critical section.
We discussed how they enter now in critical section in next lec
*/