/*
Data types clearance:

By Default types are in code:
 integrals like 10, 15 40 etc are int
 floats like 10.3, 3.2 etc are double
Type in memory same as you mention of the identifer


int a = 13;
Above varibale type is int and the literal (constants) is also int.
double b = 90;
Above b is double but literal here is int. But in memory where the b is stored the 90 data type is double because in memory it get space according its type
int a = 10.5;
Above a is int while 10.5 is double in code. yes double.  and in memory it would be int and store 10
char b = 'A';
This will store 65 number bianry in memory and called as char because of data type and in memory it has 65 but because data type is char then we called it as char there also.
float b = 65.5; 
Above b is float but the literal is double but in memory it is float

// Processing according to data type:

char s = 65;
cout<<s; // this will give A because data type is char so it will only read 1 byte of binary of 65 and treat as charater and show A.
If want number then we do:
cout<<(int)s; // This is typecasting we are saying to treat s as int.
*/




/*
Pointers:
int a = 10;
&a // type of this is int * because we are storing address of int. read left to right as pointer to int


// How much space the pointer allocate?
ANS: Pointer space is fixed according to 32 or 64 bit system. Pointer size for 32bit system is 4Byte and for 64bit OS is 8Byte. (why? for example: you don't need 1 page for writing address of 10 marla house. You just need 1 line maybe. Same 1 line is needed for 5 marla house. So address space is fixed.
Technical Example: Look Acutally in hardware there is address register (which have the address) and  address bus (which takes the address). store the required address and address bus takes that address to RAM and do it operation etc. Now, this address bus (how much take) size is fixed in hardware. When we said our system is 32 bit then it means 4byte of pointer can address register can store and when we said 64 bit then it means our register can store 8 bytes and takes. Pointer size can never be larger than address bus.
     Counter Question/  Then why we use data type with pointer? So for derefer it.)
//Then Why should we use data type with pointers?
ANS: You can say that the data type is wall in memory. e.g;
int a = 10;
int* b = &a; now here b has the address of starting (1st) byte a. and the int tell to read/write 4 byte in memory otherwise it do not get know that how much read or write in memory.
Above b which is pointer taking 8 byte in memory.

void pointer:
A pointer which can store address of any type. But we can't derefer because it don't know how much read from memory but still it has use which we discuss it later.



int a = 1234;
&a; // type is int *
int * p (read as ---> p is pointer to int non const) = &a;
&p; // type is int ** ==> (already have int*) and 1 more have & so 1 more *

int ** q (read as ---> q is pointer to pointer to int non const) = &p;
&q; // int ***

Similarly for const;

const int b = 90;
&b; // type is const int *
const int * p (read as ---> p is pointer to int const) = &b;
&p; // type is const int ** ==> (already have int*) and 1 more have & so 1 more *

 const int ** q (read as ---> q is pointer to pointer int const) = &p;
&q; // const int ***




const int b = 100;
int* const p (read as --> p is const pointer to int non const) = &b;  
*/











/*
 int a = 10;
 const int * p = &a; // Is it feasible?
 Yes.. Because a is non-constant but when we make its pointer int to constant (not pointer const) then it means that this pointer cant change the value of a.
 But,
 int * const p = &a; // Here a p pointer is constant that we cant change it but the value its points to is not constant so we can change it.


 NOW,

 const int b =20;

 int * const p = &b; // Here is error.
 Why? Because b is constant but we are making pointer constant with the value it will access is not constant. If it allow to pass from here then:
Then below will not show any error beacuse p dont know that b is constant it just know its own data type which allow him to do run line no 94. it must check it during line no 91
 *p = 90902; // This will not be error.


int b =20;
const int * const p = &b; // Here p cant change the value of b as p data type is not allowing while b is not constant.

*/



/*
Pointer shifting in cpp:

int a = 16961; // specific number for understanding

cout<<(int)*(char*)&a;
Output: 65

If want to access 2nd byte of a
cout<<(int)*(char*)&a+1;
Output: 66



Here we are accessing 1 byte just because of char, In case of int then it will shift to 4 byte


int * p = &a; // This will show address of 4 byte
But what if we want to just read 1 byte of a?
you can use:
char * p = * (char*)&a; // 1st star is derefrence the address
cout<<p[0]<<endl; // This will show the first byte of a. *[p+0]
cout<<p[1]<<endl; // This will show the 2nd byte of a. *[p+1]
Mean here we make int into the array of characters
Output: A (if we dont derefrence then address of 1st byte of a)
Output: B







*/



/*
We can pass array by two methods:
pass by value
pass by reference

pass by value consume more time and memory.
So default method is to pass by refrence.
Now,
Pass by refrence also has its two more types
1) By pointer. (as we are reading till now)
2) By Allias (NickName)

Allias:
Allias is actually the nick name of the same variabke
which points to the address of the same variabel.
e.g;

int a = 10;
By pointer
int * p = &a;
By Allias
int & q = a;
Allias syntax is easy. Look it is saying that q is nickName of a. It dont accquire memory(it actually accquire memory and somehow working like pointer in backend but for the ease of programmers, languages say that think it is a nickName) .
q = 20;// This will change the value of a.

Allias must be initalize at the time of decleration because it is constant.

We can also make the allias of allias. 

int a = 10;
int & q = a;
int & r = q;

r = 30; // This will change the value of r and a.


so making allias of pointer

int * p = &a;

int * & q = p; // Allias of pointer (same syntax, just add the data type of pointer)

NOTE: Allias is only the replacement of const pointer. We have to use the pointers for dynamic address
*/










/*
copying elements of array from one array to another

 
int a[4] = {1,2,3,4}; // 16 bits
int b[6] = {10,20,30,40,50,60}; // 24 bits
 
memcpy(dest,src,no_of_bits);
memcpy(a,b, 16); // This will copy the elements of a into b.
If we pass 24 instead of 16 then it will cross the array "a" boundry and it is not good.

If want to transfer just 2 elements then

memcpy(a,b, 8); // This will copy the elements of b which are 10 and 20 into a by replacing 1 and 2.

*/




/*
Data Type always decides that which type of operation we can do with the any variable and specifically with pointer.
Pointer do not know which value or which type of value is going to store in it. It just play operation according to its
own data type.


Character data type have some diffrent sceniors as compare to other data type. e.g;
#include<iostream>
#include <cstring>
using namespace std;
int main(){

 char s[100] = "Pakistan";
  strcpy(s,"HE"); // strcpy is function which is used to overwrite the value of string.  So it overwrite the value of Pa with HE now.
  cout<<s[0]<<endl;


    return 0;
}



Secondly, it prints until it finds null in array of character. and one more thing is that it does not print address of particular byte using &


// But direct print like cout<<&s<<endl; print address of char array

#include<iostream>
#include <cstring>
using namespace std;
int main(){

 char s[100] = "Pakistan";
  strcpy(s,"HE"); // strcpy is function which is used to overwrite the value of string.  So it overwrite the value of Pa with HE now.
  cout<<&s[0]<<endl;  show HE and if remove index then with ampersand show address.  if add index 3 with ampersand then it will also print the whole array from index 3 to NULL. Simple "s" with ampersand show address  


    return 0;
}
*/


/*
Let's test ourselves for data type:



int a = 90;
int* p1 = &a; // &a data type is int* and so we also match the data type of identifier
// So above we matched the data type of identifer and value.
   int* const p2  = &a; // &a data type is int* and here identifier type is int* const
   Above line is valid even though type do not match. But type actually match but const is saying that i will not change the recived pointer. And recived pointer is saying that you can change me or not. its up to you. 
   const int** q = &p1; //  type of  int**  and here indentifier type is saying that non constant pointer which is good and value will be treated as constant. All good.
   const int** q = &p2; //  type of  int* const *  and here indentifier type is saying that non constant pointer which is bad here because it will change and value data type is saying i will not change.
   *q = p2; // type of int* const while identifier data type can be evaluated by just skiping 1 star in above line. so data type becomes const int*. Same problem... Value data type saying that pointer is constant and identifer saying that i will change which is not good.

  27:09
*/




/*

==> A dangling pointer is a pointer to storage that is no longer allocated. 

Dynamic memory and allias:
As you know allias behave like a constant pointer.
When you make allias of dynamic memory then it points to complete memory which is made by new keyword on heap by pointing address of starting byte.
When we deallocate it, then allias will point to garbage value but not get change. Because Allias will always points to the same memory once it allocate to it. even that memory deleted.
That's why we dont use allias with dynamic memory.

int* p = new int // new int data type is int* because new give the address of starting byte 
// making allias
int & p  = *(new int); // derefrence on right side give or return with heap memory (as discuss below) and now we can give allias to it
Now here we make allias of new int heap memory.
MAIN CONCEPT:
1) *p1= // go and write right side value at p1 address 
2) =*p1 // go and read the bytes according to data type and come back

// deAllocate memory
delete &p;
// But allias still there and having the garbage value
// So after delete, the allias become dangling, means it can cause runtime error because now p points to illegal memory. 



Let's clear one concept more,,,
#include<iostream>
using namespace std;
int main ()
 {
  int* p = new int; // make 4 byte in heap
delete p; // now memory is deleted, not variable
int* q = new int;
*p = 100; // This is allow because we delete heap memory above and again make heap memory with diffrent name.But we can use the previous name to assign value to heap because we need memory doesnt matter when initialized.
 }


=> Null pointer: Which has nullPtr and dereferncing this is called null pointer assignment error --> Runtime error just say it is null where should i go
=> Pointer in which no address of reserved memory but some non-zero value, dereferencing this type of is known as dreferncing of dangling pointer. This can cause to distrub the other some memory. -> illegal memory access --> Runtime error 
=> memory leak: You reserved some memory but this memory is not pointing by anything in your program then this memory remain reserve in memory and having some garbage value throughout the program so it is called as memory leak
*/



/*
Some more about stack and heap.


Stack is something where our variables store from higher to lower. For Example: 1st we store A and then B then it means the address of A is 104 and B is 100. Higher to Lower
But when we use array then it become reverse and store from lower to higher that's why we can use *(a+1) etc.

Heap: store data from lower to Higher.


When accessing null pointer then it will show null. But when you derefer it,,, then it may show error this error name is "null pointer assignment error"
and when you derefer dangling pointer then it may again give error but this error is big then null because dangling pointer is not reserved by you
but maybe use by other program so it is danjerous that we can read and write some confidential file which is pointed by dangling pointer.

NOTE: I am here using the word "may" which means that error can occur or not. There will be no error when we declare a pointer and derefer it but it is pointing some other value (not null mean some value coming in memory from somewhere).
Same case in the dangling pointer. suppose we delete a pointer,,, it is not reserved by our program but maybe pointing something else in computer or in our program again... and then it will not error.



Why addresses show in hexadecimal?
Address are mostly in 32 symbols in int. But they are difficult to remember. SO we show hexadecimal which is 8 symbols and easy to remember.

When we do not make array then it may be in consecutive but it is not always the behaviour because ram is for overall computer. It may give first variable at certain place
and other maybe far from it. because between space maybe fulfill by other process but this is not always the behabiur.


Data Type of Arrays and 2D Arrays:


1D array behave like a single pointer
2D array behave like a double pointer

int a[4] = {1,2,3,4};
int b[4][5]; // read as b is an array of row size 5 of type int non-const

a; // int * // read as pointer to int non-const
&a; // int (*)[4] // int and (*) this is necessary in addresses and next to it we write size of array. Actually this is adress of address because array name itself is address
// read as "pointer tof row size 4"

b; // int (*)[5] becuase b is 2D array and our 1st is showing int(*) and this is size of array[5]. read as "pointer to row size 5
&b[0][0]; // int * and we are not considering 2nd one becuase it is 0 and 0 is nothing row
b[1]; // int * // single address
&b; // again adress of adress so  int (*)[4][5];



Ok now  TEST

int a[4] = {1,2,3,4};
cout<<*(&a + 1) - a<<endl;

here  first we have to check the types of array:

x[2][3] = {1,2,3,4,5};

cout<<x<<endl; // int (*)[5]
cout<<*x<<endl; // when we use 1 derefer then it will remove 1 bracket above and become int *
cout<<**x<<endl; // when we use 2 derefer then it will remove one more bracket and become int


So now here statement is  cout<<*(&a + 1) - a <<endl; // here type &a is int (*)[4] and by adding 1 type will remain same. But here we are derefer it so its type will be int *
while type of a is remain same as int* so it will - and show answer. But if we remove the derefer then its types changes and give error.

NOTE: One more thing....

So here &a giving you whole array of 5 elements. and when we +1 it then it will add 4 bytes  * 4 bytes= 16 bytes; so now &a + 16 bytes;
suppose &a giving 100; 100 + 16 = 116;
116 - a; 
So the purpose of writing above para is here that &a + 1 do not go for 2nd index,, it will go to last index + 1 memory. because &a type is int (*)[4];

int a[4] = {1,2,3,4};
cout<<(unsigned long long int)(&a + 1) - (unsigned long long int)a<<endl; 

// here we are just type casting the coming address and into int and there types are now compatiable











*/





/*

In lecture 13 we learn about the self refrential objects who has values and pointer to next node.
So what is List?
Anything that we store is a list like array so it become array List.
Stack is also a list with some restriction
Queue is also a list with some restriction.

But mainly there are 2 types:
List is anything storing in container like array, stack etc
1) ArrayList => whatever we discussed till now is the example of arraylist even vector is also.
2) Link List => We discuss about the refrecial objects so they are also list called as linklist.

Stack, Queue and may other structure is know as LIST but with some restrictions.


In lists we can insert at any point like array in linklist and this is doen by the strct of linkList
*/