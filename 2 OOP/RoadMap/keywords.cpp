/*
Static keyword:

They are 3 types where we use static keyword:
1) static local variable
2) static member varibale // also called class  variable 
3) static member functions



1) Static Local Variable
        Which have local scope and we make them static.
        Like variable in functional scope with static keyword
        Static keyword do:
                        1) By Default initialize with 0 not with garbage value
                        2) This static variable will only be created and get into memory when program executed. And get deleted when program terminated
                        Variables which are not static. They by default initilze with some garbage value and they get created whenever the function called. And get delete when funcion done its work



2) Static Member variable
        Those variables which are in the class and we make with static keyword.
        These variable are also 0 by default.
        These variable get into memory when the class created. Only Once.
        While simple member variables are only get created when the object get created of that specific class.
        Simple variable are diffrenet for all objects while static are only once initialized when class created.
        Static Variable are declared in the class and initialzid out of the class.
        Normal member variables are also know as instance member varaible because they get into memory when object is created.
        These can be access using the objects.
        But it also exist when there is no any object then how we will access it?
        Simply Class Name and scope resoulation operator and name of that static memeber variable. But this is possible only when
        the static variable is public. But how to access when private?
        Here we can use the static member functions which allow us to only access the static member variables. 




3) Static Member Function
        Here we can use the static member functions which allow us to only access the static member variables. 
        These functions can also call with or without object
        Simply Class Name and scope resoulation operator and call static memeber function.
        Also called as class function

*/



/*

A virtual keyword in C++ is used to create a virtual function in C++. The virtual function is the parent class function which we want to 
redefine in the child class. The virtual function is declared by using the keyword virtual. When we define the virtual function the keyword 
virtual is to be proceeding in the declaration of the function. The virtual keyword tells the compiler to perform late binding or dynamic linkage
on the function.
*/