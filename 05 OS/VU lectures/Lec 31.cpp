/*
Overlays:

-> Contiguos in memory
Overlays give the concept of virtual memory.
-> Allow a process to be larger than the amount of 
memory allocated to it.
-> Keep in memory only those instructions and data that are
needed at any given time.
-> Keeping only few instructions in memory at a time is concept of virtual memory.

-> Allow a process to be larger than the amount of memory allocated to it.

-> Keep in memory only those instructions and data that are needed at any given time.

-> When other instructions are needed, they are loaded into the space occupied
previously by instructions and/or data that are no longer needed.

-> Implemented by user
-> Programming design of overlay structure is complex and not possible
in all cases.
*/

/*
Overlay Example:
Assume:
2-pass compiler/assembler
What is meaning of 1 pass and 2 pass compiler.
The compiler which check the code syntax  and make code only once is 1 pass.
The compiler which check the code syntax two times and make code  is 2 pass.
Working of compiler:
Check syntax and make file
Then from file make the code for execution.

So, Assume 2-pass compiler

Available main memory: 150k
Code size: 200k
Pass 1 ..... 70k --> Syntax check
Pass 2 ..... 80k --> Make code
Common Routine ... 30k
Symbol table ... 20k

Common Routine and symbol table are must be in memory but pass 1 and pass2
would be one at a time in memory. and now we can
work within 150k. So this is concept of overlay.




*/


/*
Swapping:
Swap out and swap in (or roll out and roll in)
Major part of swap time is transfer time; the total transfer is
directly proportional to the amount of memory swapped.

Large context switching time.

Cost of swapping:
Process size = 1MB
Transfer rate = 5MB/sec
Swap out time = 1/5 sec
            =200 ms
Average latency = 8ms
Net swap out time = 208ms
Swap out + swap in = 416ms


Issues with swapping:
Quantum for RR scheduler // Use 10 and 90 rule that quantum should be 10 percent of the CPU brust so, here total swap time is 416ms, so quantum should be 4ms
Pending I/O for swapped out process
-> Means 1 process request for the I/O but it is swapped out even its request is
still not fulfill. So the high priority process come into its space. So,
I/O request code then go for the new process. Which is wrong.
User space used for I/O
solutions:
So, We can fix it by 2 ways:
1) Never swap out the process which requests the I/O
2) Don't do I/O directly to the address space of the process. But instead, I/O with the kernel buffer and then kernel buffer sends to the process and vice versa when I/O leave the process.

*/

/*
Contiguous Allocation:
Main memory divided into:
Kernel space ==> For kernel
 user space ==> For user processes

=> A process is placed in a single contiguous area in memory.
=> Base (re-location) and limit registers are used to point to the smallest
memory address of a process and its size respectively.

Cpu => logical address => if <limit register then => add relocation register and get physical address
If not <limit register then trap; addressing error.
Limit register is the size of process.
*/


/*
MFT:
-> Multiprogramming with fixed tasks (MFT)
-> Memory is divided into several fixed-size partitions.
-> Each partition may contain exactly one process/task.
-> Boundaries for partitions are set at bott time and are not movable.
        -> An input queue per partition
        -> One input queue for all partitions
-> The degree of multiprogramming is bound by the number of partitions.
Large partitions in number then more processes can have.


Example of input queue per partition:

input queue   partition       size
 Me, Me ===> Partition 4 ==> 100k size partition
 Me, Me, Me ===> Partition 3 ==> 300k size partition
    null    ===> Partition 2 ==> 200k size partition
    Me    ===> Partition 1 ==> 150k size partition
                OS

-> Potential for wasted memory space. an empty partition but no 
process in the associated queue.
-> Load time address binding means when swap out the process at runtime.
Then again swap in then the process must go in the same partition so we
have to use load address binding in which compiler do not know the location
to put on but generate re-locate code and fulfill the request at the same place.


MFT with single input queue:
Single queue for all partitions
    Search the queue for a process when a partition becomes empty
    First fit, best fit, worst fit space allocation algorithm use for 
    entering the process in which partition.


    Input queue => Partition 1
                    Partition 2
                    Partition 3
                    OS

MFT issues:
Internal fragmentation  => wasted space inside a fixed-size memory region
No sharing between processes.
Load time address binding with multiple input queues
*/