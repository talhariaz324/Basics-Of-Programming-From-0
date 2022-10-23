// Reverse number without array

#include<iostream>
using namespace std;

int main()
{
    int no,rev=0,r,n;

    cout<<"Enter any positive number :: ";
    cin>>n;

    no=n;

    while(no>0)
    {
         r=no%10; // reminder
         rev=rev*10+r; // reverse
         no=no/10; // at each reverse
    }
    cout<<"\nReverse of a Number [ "<<n<<" ] is :: [ "<<rev<<" ] \n";

    return 0;
}