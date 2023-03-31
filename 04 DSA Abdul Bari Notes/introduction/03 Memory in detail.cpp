/*
Memory: has the small blocks. Each block has 1 byte size.
Every byte has address. 
In large memoris like 8 GB etc, memory is divided into segments.
Each segment size is 64KB.  
In this course we are going to take 1 segment as memory OR memory as a size 64 KB.
*/


/*
How Program Use the memory?
Memory has 3 parts:
1) Code ==> After loading, program machine code is place in the code section of memory. It actually has the main function.
2) Stack ===>  The variables in the program and in the function is place inside the stack. 
The size of memory which is taken by the variable is decided at the compile time. So this is called as static memory allocation because its size is decided at compile time.
Every function has part in stack where its variables will store. So this part for each function is known as activation record OR Stack Frame.
For Example:
func2(){
int c;
}
func1(){
	int b;
	func2();
}
int main(){
 int a;
 func1();
}
How Memory is used by this program:
Code Section: This will have the main() function machine code, func1 function machine code, func2 machine code.
Stack: Stack also has parts for each function.
main function stack frame in stack has  "a" variable.
func1 function stack frame in stack has "b" variable.
func2 function stack frame in stack has "c" variable. Topmost in stack (current)

NOTE: topmost part in stack will be the current function is running.
The sizes of variable is decided by the compiler, so it is static. 
These variables also will be dealloacted by the compiler.
First removes the topmost like func2 part, func1 part and then main stack frame respectively.

3) Heap ==> Heap term is used for the organized which shows tower shape as well as for unorganized also shows tower shape.
But in program we are using Heap memory as unorganized data. 
Orgainzed data is used by the stack in memory.
Heap should also use as a resourse. Means when use it then also have to relaase/deallocate it.
Heap cannot be directly accessable by the program. We have to use pointer.
And pointer points to the address of the heap.
After using it, delete it. Otherwise memory leak
make pointer null. Otherwise dangling pointer,

int main(){

int* p;
 p = new int[5];
 delete p;
 p = NULL;

}
 */