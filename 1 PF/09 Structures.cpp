/*

<Structures>

NOTE: The only difference between a structure and a class is that a structure is public by default whereas a class is private by default. 
We can use struct for small amount of data like just variables and class for large amount of data mean for functionality.

This struct in cpp because it was in C lang and for the compatibility with C we use struct in C++.

Suppose, you want to store information about a person: his/her
name, citizenship number, and salary. You can create different
variables name, citNo and salary to store this information.

What if you need to store information of more than one person?
Now, you need to create different variables for each information per
person: name1, citNo1, salary1, name2, citNo2, salary2, etc.

A better approach would be to have a collection of all related
information under a single name Person structure and use it for every
person.

Methods can also be written in structure.


struct employee
{
   
    int eId; 
    char favChar; 
    float salary; 
};

int main() {
     struct employee harry;
     struct employee Anas;
     harry.eId = 1;
     harry.favChar = 'c';
     harry.salary = 120000000;
     cout<<"The value is "<<harry.eId<<endl; 
     cout<<"The value is "<<harry.favChar<<endl; 
     cout<<"The value is "<<harry.salary<<endl; 
     return 0;
}



 <Pointer and Structure>

#include<iostream>

using namespace std;

struct person

{

int age;

float weight;

};

int main()

{

person *personPtr, person1;

personPtr = &person1;

cout<<"Enter age: "<<endl;

cin>>personPtr->age;

cout<<"Enter weight: "<<endl;

cin>>personPtr->weight;

cout<<"Displaying:\n";

cout<<personPtr->age;

cout<<personPtr->weight;

return 0;

}


*/