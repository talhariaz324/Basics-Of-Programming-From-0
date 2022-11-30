/*
Factorial of n is: 1 * 2 * 3 ... * n
we can write : 1 * 2 * 3 ...*(n -1) * n
So, fact(n) = fact(n -1) *n

And 0! = 1
And 1! = 1
*/

/*
int fact(int n)
{
 if(n==0)
 return 1;
 return fact(n-1)*n;
}
int Ifact(int n)
{
 int f=1,i; 
 for(i=1;i<=n;i++) 
 f=f*i;
 
 return f;
}
int main()
{
 int r=fact(5);
 printf("%d ",r);
 return 0;
}
*/

