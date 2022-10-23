
/*  C++ Program to Convert Days Into Years Weeks and Days  */
#include <iostream>

using namespace std;

int main()
{
    int days,years,weeks;
    cout<<"Enter no days"<<endl;
    cin>>days;
    years = days/365;
    days = days%365;
    weeks = days/7;
    days = days%7;
    
    cout<<"Year are: "<<years<<" Week are: "<<weeks<<" Days are: "<<days<<endl;
    

    return 0;
}
