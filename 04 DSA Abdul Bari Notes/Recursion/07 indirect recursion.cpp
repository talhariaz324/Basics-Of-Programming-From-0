/*
A recurison which is not directly but indirect.
For example
A function call  the function with name B.
B Calls the function with name C.
C then calls the function with name A. So here it become circle.
So this type of recurison is known as indirect recurison.
*/


/*

#include <stdio.h>
void funB(int n);
void funA(int n)
{
 if(n>0)
 {
 printf("%d ",n);
 funB(n-1);
 }
}
void funB(int n)
{
 if(n>1)
 {
 printf("%d ",n);
 funA(n/2);
 }
}
int main()
{
 funA(20);
 return 0;
}

    FuncA(20) ==> print 20 and call B(19)
    FuncB(19) ==> print 19 and call A(9)
    FuncA(9) ==> print 9 and call B(8)
    FuncB(8) ==> print 8 and call A(4)
    FuncA(4) ==> print 4 and call B(3)
    FuncB(3) ==> print 3 and call A(1)
    FuncA(1) ==> print 1 and call B(0) terminate and goes back
    

*/