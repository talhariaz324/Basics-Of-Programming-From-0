/*
Normal memory allocation (Compile time) is a technique for allocating memory on the stack.
Dynamic memory allocation is a technique for allocating memory on the heap.
Slides too.
In the programs seen in previous chapters, all memory needs were determined before program execution by defining the variables needed.
 But there may be cases where the memory needs of a program can only be determined during runtime. For example, when the memory needed
 depends on user input. On these cases, programs need to dynamically allocate memory, for which the C++ language integrates the operators
new and delete.
Dynamic memory is allocated using operator new. new is followed by a data type specifier and, if a sequence of more than one element is required, the number of these within brackets []. It returns a pointer to the beginning of the new block of memory allocated. Its syntax is:

pointer = new type
pointer = new type [number_of_elements]

The first expression is used to allocate memory to contain one single element of type type. The second one is used to allocate a block (an array) of elements of type type, where number_of_elements is an integer value representing the amount of these. For example:

1
2
int * foo;
foo = new int [5];


In this case, the system dynamically allocates space for five elements of type int and returns a pointer to the first element of the sequence, which is assigned to foo (a pointer). Therefore, foo now points to a valid block of memory with space for five elements of type int.



Here, foo is a pointer, and thus, the first element pointed to by foo can be accessed either with the expression foo[0] or the expression *foo (both are equivalent). The second element can be accessed either with foo[1] or *(foo+1), and so on...

There is a substantial difference between declaring a normal array and allocating dynamic memory for a block of memory using new. The most important difference is that the size of a regular array needs to be a constant expression, and thus its size has to be determined at the moment of designing the program, before it is run, whereas the dynamic memory allocation performed by new allows to assign memory during runtime using any variable value as size.

The dynamic memory requested by our program is allocated by the system from the memory heap. However, computer memory is a limited resource, and it can be exhausted. Therefore, there are no guarantees that all requests to allocate memory using operator new are going to be granted by the system.




We can  store the user taken value in pointer like cin<<*n
We can also pass the pointer to array like arr[*n]
*/