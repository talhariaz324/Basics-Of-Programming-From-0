// Recursion Implement with Debug.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
#include <iostream>
using namespace std;
void func1(int n) { // Assume function takes T(n) time
    if (n > 0) { // 1 
        cout << n << endl; // 1
        func1(n - 1); // As we assume that above function takes T(n) time then this function absolutlely takes T(n-1) as per its param
    }
}

int main() {
    int x = 3;
    func1(x);
}


*/



// Static Varibale in recursion


/*

#include <stdio.h>
int fun(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}
int main() {
    int r;
    r = fun(5);
    printf("%d\n", r);

    r = fun(5);
    printf("%d\n", r);

    return 0;

}




//Tree Recursion
#include <stdio.h>
void fun(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        fun(n - 1);
        fun(n - 1);
    }
}
int main() {
    fun(3);
    return 0;
}
*/

//Indirect Recursion
#include <stdio.h>
void funB(int n);
void funA(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        funB(n - 1);
    }
}
void funB(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        funA(n / 2);
    }
}
int main()
{
    funA(20);
    return 0;
}