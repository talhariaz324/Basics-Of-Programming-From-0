/*
How compiler understands it?
int a = 10;
Compiler have the value at the address. So Compiler 1st convert the variable name into address and give value.
When the address is given? 
At the execution time, address is given.
Compiler use formula for giving value.
In array:
int a[] = {1,2,3,4,5};
Now, want to change the index at 3 index
a[3] = 3;
Now compiler will do formula.
What is the formula?
Compiler knows the base address of array which is the 1st index address in memory.
So, suppose 200 is base address then:
200 + 3 * 4  = 212. where 3 is index and 4 is size of int
So the address 212 where i want to change.
General formula is:
base address + i * w where i is index and w is size of data type.


What if we start with index 1 and why c/cpp allow only index 0.
Then compiler formula will become:
base address + (i-1) * w here we make i-1 because index start with 1.
So here -1 is extra operation. which get execute for n time for accessing n values.
So it becomes slower. That's why c/cpp allow only index 0.
*/