/*
Linear recursion are those which call itself only 1 time.
But calling more than 1 time the function itself then it is known as the tree recursion.


NOTE: If the function is doing operations on the statements which are before and after the function call then it is known simple
linear recursion.
*/


/*
Tree Recursion 
#include <stdio.h>
void fun(int n)
{
 if(n>0)
 {
 printf("%d ",n);
 fun(n-1);
 fun(n-1);
 }
}
int main() {
 fun(3);
 return 0;
}



Tracing tree:

            YOu can see it on the lecture 10 in recursion folder of the ABDUL BARI SB

Time Complexity:
Time Complexity can be get by calculating the no of calls of the function for both calling and returning. It is total 15 for fun(3).
But if we calcualte for each level call then it becomes: 1+2+4+8 = 15
                                                        2^0 + 2^1 + 2^2 + 2^3  = 2 ^ 3+1 and - 1
                                                        So for n call then 2 ^ n and - 1
                                                        SO O(2^n)
Space complexity: is the space which taken in the stack. SO we see that once created activation record use again and again.
so for the call fun(3) it makes 4 stacks. So n+1
SO space complexity:  O(n)    

*/