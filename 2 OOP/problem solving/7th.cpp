/*  C++ Program to convert inches to feet yards and inches  */

#include<iostream>
using namespace std;

int main()
{
    int y,f,i;
    cout<<"Enter Inches to Convert ::";
    cin>>i;

    y=i/36; // as 1 yard = 36 inches
    i=i%36; // in the end we have to give the inches so we can calculate it with remainder
    f=i/12; // as 1 feet = 12 inches
    i=i%12; // same do for inches again.

    cout<<"\nAfter Conversion from inches to feet, yards and inches :: \n";
    cout<<"\nYards = "<<y<<"\n\nFeet = "<<f<<"\n\nInches = "<<i<<"\n";

    return 0;
}