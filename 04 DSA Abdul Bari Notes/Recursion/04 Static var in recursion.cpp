/*
Let's 1st do for the normal variable

#include <stdio.h>
int fun(int n)
{
 if(n>0)
 {
 return fun(n-1)+n;
 }
 return 0;
}
int main() {
 int r;
 r=fun(5);
 printf("%d\n",r);

 return 0;
}

Its tracing will be:
  fun(5) end result is 15
  /
  fun(4) + 5 + 10 = 15 // This plus will add after returning
  /
  fun(3) + 4 + 6 = 10 // This plus will add after
  /
  fun(2) + 3 + 3 = 6// This plus will add after
  /
  fun(1) + 2 + 1 (Result of below ) // This plus will add after
  /
  fun(0) + 1 and result is 1 // This plus will add after
  /
  0
*/



/*
Static Variables are those who have only 1 copy in global section of memory.(Global Section is actually sub-section of the code section)

#include <stdio.h>
int fun(int n)
{
 static int x=0;
 if(n>0)
 {
 x++;
 return fun(n-1)+x;
 }
 return 0;
}
int main() {
 int r;
 r=fun(5);
 printf("%d\n",r);
 
 r=fun(5);
 printf("%d\n",r);
 
 return 0;
}

Here we are incrementing x at each call and acc to our condition x will be 5 at the end and remain same for all remaining calls. Because
it has only one copy.

Its tracing will be:
  fun(5) end result is 25
  /
  fun(4) + 20 + 5 = 25 // This plus will add after returning
  /
  fun(3) + 15 + 5= 20 // This plus will add after
  /
  fun(2) + 10 + 5 =  15// This plus will add after
  /
  fun(1) => 5 (pre result) + 5 (x val) = 10 (Result of below ) // This plus will add after
  /
  fun(0) 0 + 5 => 5 and result is 1 // This plus will add after
  /
  0
*/


/*
Same goes for the global variables, because they also have the 1 copy and also in the global section of memory..
*/



