/*
There are 5 types of recursion:
1) Tail Recursion
2) Head Recursion
3) Tree Recursion
4) Indirect Recursion
5) Nested Recursion
*/


// Tail Recursion

/*
Tail Recursion is one in which there is no returning work is done.
Every operation is perform during call. Means after recusrive function call no more statement.
*/


/*
For Example:
#include <stdio.h>
void fun(int n)
{
 if(n>0)
 {
 printf("%d ",n);
 fun(n-1); // Here is function calling and see there is no more statement after that mean nothing to do in returning so it is call as tail recursion
 
 }
}
int main() {
 int x=3;
 
 fun(x);
 return 0;
}

But Tail Recursion also fails if:
#include <stdio.h>
void fun(int n)
{
 if(n>0)
 {
 printf("%d ",n);
 fun(n-1) + n; // here no statement after call but it has to add the n in function result during returning, so it is not tail recursion.
 
 }
}
int main() {
 int x=3;
 
 fun(x);
 return 0;
}
*/


/*
Tail Recursion are easily convertible to loops.
So tail recursion uses more space as compared to loop so avoid tail recursion and use loop.
Some compiler nowadays auto judge and make object code of loop.
Time complexity of tail recursion and the loop remain same.
Space Complexity of tail recursion is: o(n) because everytime calling
Loop Space Complexity is: O(1) because its not calling itself but repeting.
*/




/*
head Recursion is one in which there is no calling work is done.
Every operation is perform during returning. Means after recusrive function call it just call itself and during returning do operations.
 
*/


/*
For Example:
#include <stdio.h>
void fun(int n)
{
 if(n>0)
 {
 fun(n-1); // As no before statements so it is head. If it has some even 1 statement before calling then it will not be head recursion.
 printf("%d ",n);
 }
}
int main() {
 int x=3;
 
 fun(x);
 return 0;
}
*/


/*
Head Recursion is not easy to convert into the loop. 
It can be but without the same look. and little difficult as well.
*/