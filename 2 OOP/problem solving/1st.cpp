/*  C++ Program to Swap Two Numbers without using third variable  */

#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cout<<"Enter 1st number"<<endl;
    cin>>a; // 5
    cout<<"Enter 2nd number"<<endl;
    cin>>b; // 9
    cout<<"Before a is: "<<a<<" b is: "<<b<<endl;
    a = a + b; // 14
    b = a - b; // 14 - 9 = 5
    a = a - b; // 14 - 5 = 9
    cout<<"After a is "<<a<< " b is: "<<b<<endl;
    
}

