/*
Fibonacci Series:
0,1,1,2,3,5,8,13
So, first two numbers are fixed and then next number is obtain by their sum
so this is fibonacci series.
So,
fib(n) =    0                      n=0
            1                      n=1
            fib(n-2)+fib(n-1) when n>1

int fib(int n){
    if(n<=1){
        return n;
    }else{
        return fib(n-2)+fib(n-1);
    }
}
Time complexity is 2^n approximately
If we trace it then we will find that there are calls which are repeating.
Means 
fib(5) calls fib(3) and fib(4)
fib(3) calls fib(1) and fib(2) and here fib(1) returns 1 and fib(2) calls fib(0) and fib(1)
fib(4) calls fib(2) and fib(3) and here fib(2) calls fib(0) and fib(1) and fib(3) calls fib(1) and fib(2) and fib(2) calls fib(0) and fib(1)

So here we can see that for fib(5) we are making multiple calls.
In these multiple calls some of the calls are repeating mostly.
So its time is also going exponential. This type of recursion is known as
Excessive Recursion.
So Can we avoid it? 
Yes, We can by using memorization method.
Memorization method is to store the result for each call.
Initialize the array with -1.
During each call store its result in array by overwriting -1.
Make check if -1 then call else not.


int F[10];
int mfib(int n)
{
 if(n<=1)
 {
 F[n]=n;
 return n;
 }
 else
 {
 if(F[n-2]==-1)
 F[n-2]=mfib(n-2);
 if(F[n-1]==-1)
 F[n-1]=mfib(n-1);
 F[n]=F[n-2]+F[n-1];
 return F[n-2]+F[n-1];
 }
}
int main()
{
 int i;
 for(i=0;i<10;i++)
 F[i]=-1;
 
 printf("%d \n",mfib(5));
 return 0;


*/