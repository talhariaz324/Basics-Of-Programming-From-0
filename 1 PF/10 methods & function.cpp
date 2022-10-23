// Methods/Functions: Library functions, Modular Approach, Functions, and Function definitions.
// Function prototypes.

/* Library function
Library functions which are also called as “built-in” functions are the functions that are already available and implemented in C++.
 ... Library functions in C++ are declared and defined in special files called “Header Files” which we can reference in our C++ programs
 using the “include” directive.




 Modular approach:
  is an approach in which the entire program will be spitted into different parts or modules so that the execution process
  is made easier. Explanation: The modular programming helps the user to save more amount of memory space and also makes the program to
  execute in a smarter way.
*/

#include <iostream>
using namespace std;

// Function prototype
// type function-name (arguments);
// int sum(int a, int b); //--> Acceptable prototype
// int sum(int a, b); //--> Not Acceptable  prototype
int sum(int, int); //--> Acceptable prototype
// void g(void); //--> Acceptable  prototype
void g(); //--> Acceptable  prototype

//  NOTE: we can declare and define function here also. e.g;
// int sum(int a, int b){
//     // Formal Parameters a and b will be taking values from actual parameters num1 and num2.
//     int c = a+b;
//     return c;
// }

// But in case you want to define them below the main function then you should must be declare them before main function.
// This declartion is called prototype.

int main()
{
    int num1, num2;
    cout << "Enter first number" << endl;
    cin >> num1;
    cout << "Enter second number" << endl;
    cin >> num2;
    // num1 and num2 are actual parameters (when we call function then it is called as actual parameters )
    cout << "The sum is " << sum(num1, num2);
    g();
    return 0;
}

int sum(int a, int b)
{ // Parameters of defination of function are called as formal parameters.
    // Formal Parameters a and b will be taking values from actual parameters num1 and num2.
    int c = a + b;
    return c;
}

void g()
{
    cout << "\nHello, Good Morning";
}

// NOTE: Do slides for  details. (bsf2000500 wali mail ma PF) week 12