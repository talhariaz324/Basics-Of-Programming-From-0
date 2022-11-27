/*
Recursion in which funcion is calling itself and pass the param of its own function.
Called as nested function.

int fun(int n){
    if(n  > 100){
        n- 10;
    }else{
        fun(fun(n+11))
    }
}
*/



/*

Nested Recursion 
#include <stdio.h>
int fun(int n)
{
 if(n>100)
 return n-10;
 return fun(fun(n+11));
}
int main()
{
 int r;
 r=fun(95);
 printf("%d\n",r);
 return 0;
}


Tracing:
fun(95)=> not greater than 100 so else fun(fun(95+11))  so inner call fun(106) gives 96
fun(96)=> not greater than 100 so else fun(fun(96+11))  so inner call fun(107) gives 97
fun(97)=> not greater than 100 so else fun(fun(97+11))  so inner call fun(108) gives 98
fun(98)=> not greater than 100 so else fun(fun(98+11))  so inner call fun(109) gives 99
fun(99)=> not greater than 100 so else fun(fun(99+11))  so inner call fun(110) gives 100
fun(100)=> not greater than 100 so else fun(fun(100+11))  so inner call fun(111) gives 101
fun(101)=> greater than so gives 91

and from here go back and give result 91

*/