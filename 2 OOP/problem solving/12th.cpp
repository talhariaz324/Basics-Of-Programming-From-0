/*  C++ Program to Calculate Compound Interest  */

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double amount,rate,reqTime,compundInterest;
    cout<<"Enter A,R,T"<<endl;
    cin>>amount>>rate>>reqTime;
    compundInterest = amount*(pow(1+rate/100,reqTime));
    
    cout<<"Interst is: "<<compundInterest<<endl;
    

    return 0;
}
