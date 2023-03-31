/*
Taylor series: e^x = 1  + x/1 + x^2/2! +  x^3/3! +  x^4/4! ... + x^n/n!

So, if we can observe then it shows the 3 operations:
1) sum 
2) power
3) factorial

So, let's check
int 

NOTE: Function can return only 1. So for handling the power and factorial
we take the static variables for both.

                                e(x, 4)
                                /   \ 1+x/1+x^2/2!+x^3/3!+x^4/4!
  x*x*x*x   1*2*3*4          e(x, 3)
                            /     \  1+x/1+x^2/2!+x^3/3!
  x*x*x      1*2*3        e(x ,2)
                          /     \ 1+x/1+x^2/2!
  x*x        1*2         e(x, 1)
                         /       \ 
  p=1         f=1       e(x, 0)  p = p*x and f = f*x => 1 +  x/1
  x            1         |
                        1   
 

 So, function:
 int e(int x, int n){
    static int p = 1, f = 1;
    int r;
    if(n==0){
        return 1;
    }else{
      r =  e(x, n-1); // store 1 and then go back with returning statements and give end result
      returning statements
      p = p*x;
      f = f*n;
     return r + p/f;
    }
 }
*/


/*
Let's reduce the number of multiplication for taylor's series:
 e^x = 1  + x/1 + x^2/2! +  x^3/3! +  x^4/4! ... + x^n/n!
 So we can make it reduce by common:
    1 + x/1 [1+x/2+x^2/2*3+x^3/2*3*4
    1 + x/1 [1+x/2[1+x/3+x^2/3*4]
    1 + x/1 [1+x/2[1+x/3[1+x/4]]]
  So, from this last equation we can make formula:
  start from right because bracket.
  so sequence is:
      1* x/4 + 1 then its result * x/3 + 1 then its result * x/2 + 1
      So,
                 1+x/n*S where S is initially is 1
    Taylor Series Horner’s Rule 
double e(int x, int n)
{
 static double s;
 if(n==0)
 return s;
 s=1+x*s/n;
 return e(x,n-1);
 
}
int main()
{
 printf("%lf \n",e(2,10));
 return 0;

*/