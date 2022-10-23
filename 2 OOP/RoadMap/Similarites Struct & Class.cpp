/*
Struct and class both are container which are used to store the bunch of data types in it.
When to use struct over class?
When we dont have need of features of class such as private or protected members, non-default constructors and operators, etc.
*/


// LAB for struct:



#include <iostream>

using namespace std;

struct Date {
    private:
    int day1;
    int month1;
    int year1;
    int day2;
    int month2;
    int year2;
    public:
    void enterDate1(){
        cout<<"Enter Day"<<endl;
        cin>>day1;
        cout<<"Enter Month"<<endl;
        cin>>month1;
        cout<<"Enter year"<<endl;
        cin>>year1;
    }
    void enterDate2(){
        cout<<"Enter Day"<<endl;
        cin>>day2;
        cout<<"Enter Month"<<endl;
        cin>>month2;
        cout<<"Enter year"<<endl;
        cin>>year2;
    }
    void compareDates(){
        if(day1 == day2 && month1 == month2 && year1 == year2){
            cout<<"Dates are equal"<<endl;
        }else{
         cout<<"Dates are not equal"<<endl;   
        }
        
    }
};

int main()
{
    Date obj;
    obj.enterDate1();
    obj.enterDate2();
    obj.compareDates();

    return 0;
}
