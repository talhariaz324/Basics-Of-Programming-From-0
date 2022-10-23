// Factorial

#include<iostream>

using namespace std;


int main() {
    int num;
    int fact = 1;
    cout<<"Enter Number for factorial"<<endl;
    cin>>num;
    for(int i = num; i > 0; i--){
            fact *= i; 
    }
    cout<<"Factorial is: "<<fact<<endl;
    return 0;
}