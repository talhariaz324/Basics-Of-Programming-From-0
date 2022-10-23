/*
Destructors are use to release the resources which was taken by the object of class.
*/

/*
Private Destructor:
When you do not want users to access the destructor, i.e., you want the object to only be destroyed through other means.
private destructor cannot directly delete from the heap so we need to use friend class for deleting it.

// CPP program to illustrate
// Private Destructor
#include <iostream>
  
// A class with private destructor
class Test {
private:
    ~Test() {}
  
public:
    friend void destructTest(Test*);
};
  
// Only this function can destruct objects of Test
void destructTest(Test* ptr) { delete ptr; }
  
int main()
{
    // create an object
    Test* ptr = new Test;
  
    // destruct the object
    destructTest(ptr);
  
    return 0;
}
*/



/*
Pure Virtual Destructors in C++
NOTE: Before learning it, you should must know about the pure virtual function.

Pure Virtual Destructors are legal in C++. Also, pure virtual Destructors must be defined, which is against the pure virtual behaviour.
The only difference between Virtual and Pure Virtual Destructor is, that pure virtual destructor will make its Base class Abstract, hence you cannot create object of that class.
There is no requirement of implementing pure virtual destructors in the derived classes.


class Base
{
    public:
    virtual ~Base() = 0;     // Pure Virtual Destructor
};

// Definition of Pure Virtual Destructor
Base::~Base() 
{ 
    cout << "Base Destructor\n"; 
} 

class Derived:public Base
{
    public:
    ~Derived() 
    { 
        cout<< "Derived Destructor"; 
    }
}; 



Can a destructor be pure virtual in C++? 
Yes, it is possible to have a pure virtual destructor. Pure virtual destructors are legal in standard C++ and one of the most important things to remember is that if a class contains a pure virtual destructor, it must provide a function body for the pure virtual destructor. 

Why a pure virtual function requires a function body?

The reason is that destructors (unlike other functions) are not actually ‘overridden’, rather they are always called in the reverse order of the class derivation. This means that a derived class destructor will be invoked first, then the base class destructor will be called. If the definition of the pure virtual destructor is not provided, then what function body will be called during object destruction? Therefore the compiler and linker enforce the existence of a function body for pure virtual destructors. 
 

*/


/*

when do we need to write a user-defined destructor

If you do not define a destructor, the compiler will provide a default one; for many classes this is sufficient. You only need to define a custom destructor when the class stores handles to system resources that need to be released, or pointers that own the memory they point to.
*/


/*
Can a destructor be virtual? when to use it.

Yes, can be... Virtual destructors are useful when you might potentially delete an instance of a derived class through a pointer to base class:
*/