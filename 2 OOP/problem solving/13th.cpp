/*  C++ program to Find Cube of Number using MACROS  */

#include<iostream>
using namespace std;

#define CUBE(x) (x*x*x)

int main()
{
    int n,cube;

    cout<<"Enter any positive number :: ";
    cin>>n;

    cube=CUBE(n);

    cout<<"\nThe Cube of Entered Number [ "<<n<<" ] is :: [ "<<cube<<" ]\n";

    return 0;
}

/*

A macro is defined as the piece of code that is replaced by the value of the macro in the program. We can define the macro by using the
 #define directive. Whenever a compiler encounters the macro name, it replaces it with the definition of the macro.
*/