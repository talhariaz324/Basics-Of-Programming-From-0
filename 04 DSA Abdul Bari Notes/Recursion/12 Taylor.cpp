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