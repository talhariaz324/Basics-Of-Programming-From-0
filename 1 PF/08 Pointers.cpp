/* 

      <Pointers>
 
 

A pointer is a variable that is used to store a memory address. The reference operator is used to store the memory address of a variable and store it in a pointer.
Pointer is declared as:
DataType *var;
DataType : It is the type of variable pointed by the pointer variable
* : It indicates that the var is a pointer variable
var: It is name of the pointer variable


<Example to use pointers>

int n;
int *ptr;
cout<<“enter an integer”;
cin>>n;
ptr=&n;
cout<<“value of n:”<<n<<endl; // Give the value of n enterd by user
cout<<“address of n:”<<ptr<<endl; // Give the address of n



<Dereference operator>





Used to access the value of variable whose address is stored in
pointer.

Denoted by *

Also known as indirection operator




<Additiom and Subtraction in pointers>


 
Addition/subtraction operator on pointer is used to move the
reference forward/backward in memory

Change of memory address depends on the data type of pointer


<Pointer and arrays>

All elements of arrays are stored in consecutive memory locations.

A pointer can access all elements of array if the address of first
element is assigned to it

The name of the array represents the address of it’s first element

The address of first element can be assigned to a pointer by assigning
the name of the array to pointer

int NUM[10];

int *ptr;

Ptr=NUM;


<Example>

int marks[5];

int i, *ptr;

cout<<“enter five marks”;

for (i=0;i<5;i++)

cin>>marks[i];

ptr=marks;

cout<<“you entered”;

for (i=0;i<5;i++)

cout<<*ptr++;


<Arrays of characters>

char name[20], *ptr;

cout<<“enter your name”;

cin.get(name, 20);

ptr=name;

cout<<“name entered is”<< ptr; //why not *ptr, it will print just first char

Note: the pointer displays the values stored in each element of the array
name until it finds null character \0



// Pointer to pointer

 Storing the address of another pointer in a pointer is called pointer to pointer.
    int a=3;
    int* b;
    b = &a;


    int** c = &b; // indicate with the double staric 
    cout<<"The address of b is "<<&b<<endl; // give the address of pointer variable b
    cout<<"The address of b is "<<c<<endl; // give the address of pointer variable b
    cout<<"The value at address c is "<<*c<<endl; // give the value of pointer variable b  which is the address of a
    cout<<"The value at address value_at(value_at(c)) is "<<**c<<endl; // first give the value of pointer variable b which is the address of a then give the value of a which is 3. this all done because of double ** in cout

    return 0;

*/