/*
Primitive Data Types: 
A primitive data type is pre-defined by the programming language. The size and type of variable values are specified, and it has no additional methods.
Non-Primitive Data Types:
These data types are not actually defined by the programming language but are created by the programmer.
*/


/*
ADT (Abstract Data Type): 
Before learning the Abstract Data Type, we learn about the data type.
Data Type:
 Data Type consists:
    1) Representation of Data ==>  example: if data is int.  then it takes 4 bytes in memory. 1st bit is sign bit which shows positive or negative. and remaining is data in bits.
    2) Operation of Data ==> Add, subtraction, multiplication, and division and modulus.

    so this is data type which have representation in memory and also has operations.


So abstract data type means on which you are performing operation but it is hidden from you that how it works.
Class in oop is example of ADT. If we make list in the class then it will become the ADT data type also as it is non primitive data type defined by user.  
*/


/*
List Representation:
1- Space for storing elements
2- Capacity (total space)
3- Size (occupied space)

Operations:
add(x);
remove();
search(key);


We see that list has representation and operation so it is data type and we make it in class then it is ADT.

Now we can represent it with the help of array or linked-lists.
*/


/*
Operations that we can make in class of List:
add(element) / append (element)
add(index, element) / insert (index, element)
remove(index)
set(index, element) / replace (index, element)
get(index)
search(key) / contains (key)
sort(index)
*/