/*
 Relationships b/w classes are:
 1) Inheritance (IS_A)
 2) Compostion (HAS-A)
 3) Aggregation (HAS-A)
 Do slides too.


 For aggregation use this program:
 // Online C++ compiler to run C++ program online
#include <iostream>


using namespace std;

class Address{
    private:
             int house_num;
             int street_num;
    public:
    void set_house_num(int i)
    {
    house_num = i;
    }
    int get_house_num(){
    return house_num;
    }
    void set_street_num(int i)
    {
    street_num = i;
    }
    int get_street_num(){
    return street_num;
    }

};
class Student{
    private:
    string name;
    Address *address;

    public:
    Student(Address* address1, string name1)
    {
    name=name1;
    address=address1;
    address->set_house_num(1);
    address->set_street_num(5);
    }
void show()
    {
    cout<<name<<endl;
    cout<< address->get_house_num()<<endl;
    cout<< address->get_street_num();

    }
};
int main(){
    string name1= "Talha ";
    Address address2;

    Student s1(&address2, name1);
    s1.show();

return 0;
}

*/

/*Write a C++ program that implements a class hierarchy having a base class named Employee and a derived class named Adhoc_employee.
The base class has data members of Name, Id, Number of working hours and Per hour salary. The derived class implements two methods
named salary and display_info. The salary method calculates the salary of employee by multiplying “Number of working hours” by “Per hour salary”.
The display_info method displays the complete information of employee. Create an object of Adhoc_employee and display the information and salary against that instance.*/
