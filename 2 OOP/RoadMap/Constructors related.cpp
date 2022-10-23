/*
Shallow copy and deep copy

Whenever we do copy the already created constructor to the new constructor of same class then compiler call its copy constructor and
do shallow copy.
Whenever we define our own copy constructor is called as deep copy. Because in which we handle pointer also.
For Example:
In simple class, we can go with shallow copy.
But the class which has the pointer which is pointing to the variable which is outside the class. In that case shallow copy, copies
the pointer and when we delete one object other pointer also get deleted and when we change value of pointer variable of one object
is also cause to change the value in other object,


For Overcoming this, we are here and we are doing deep copy. Deep copy is to define our own copy constructor and in which handle the
pointer of new object and which is pointing to same value of copied object pointer but with diffrent address.
*/



/*
Copy Constructor and Assignment Operator.

Copy Constructor is used to initialize the object during its declration with already created one.
Assignment Operator is used to initalize the object after declartion of object or or overwirting the exosting value of object with already
created one.
Assignemmnt and copy constructor are by defualt by the langyage.
*/

/*
Dangling pointer is a pointer pointing to a memory location that has been freed (or deleted).
Memory leak: Pointer get delete which was pointing to the address of variable which is in heap (dynamic). So dynamic variable has no name
and we also can't use it, but they still in memory. So causing memory leak.
*/



/*

Virtual Constructor:

The virtual mechanism works only when we have a base class pointer to a derived class object. e.g; Base *p = Dervied();

In C++, the constructor cannot be virtual, because when a constructor of a class is executed there is no virtual table in the memory, means no virtual pointer defined yet. So, the constructor should always be non-virtual.


Virtual Destrucor: When we are creating heap object of dervied class with the help of pointer of base class then compiler will do early binding.
Suppose Dervied class have pointers which are  pointing to some address. So we have to call the destructor of derived class first to delete the
pointers variables to avoid the memory leak.
But as early binding, it will call the destructor of base class (because pointer type is of base) first and dervied class destructor does not matter for it.
For fixing it, we simply add virtual keyword behind the base class destuctor which will tell the compiler, i am late binder, then compiler
go to the dervied class destructor and then destruct it and then go to base class.


NOTE: Writing virtual for base class is for inherited for all derived class.

*/



