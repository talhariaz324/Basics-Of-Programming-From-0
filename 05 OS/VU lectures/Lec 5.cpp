/*


In this lecture, he is telling about some commands in UNIX/LINUX for getting
more doing in the folder structure.
Some also commands for compile the program in the UNIX/LINUX.


But main topic is Process:


Process - a program in execution ;  
process execution must progress in
sequential fashion .
A process consists of :
Code ( text ) section ==> It has code which is to be executed.
Data section ==> Global variables or strings etc.
Stack ==> This has functions which are getting call. Local variables and return value.
Heap ==> It has the dynamic allocation and deallocation at runtime.
Environment ==> When we pass parameters in the terminal. Environment handles these parameters.
CPU state ( program counter , etc. ) ==> Process has different states. CPU state tells which instruction is to be execute next. 
Process control - block ( PCB ) ==> Every process is attached with the PCB which is data structure which is maintained by the kernel



Processes can be :
   I / O - bound process - spends more time
   doing I / O than computations , many
   short CPU bursts .

   CPU - bound process - spends more time
   doing computations ; few very long CPU
   bursts .
         
*/



/*

Process States:
1) New
2) Ready
3) Running/ Execute
4) Waiting
5) Terminate 




Process information and attributes:
■ Process state ==> Can be any state.
■ Program counter ==> A program counter is a register in a computer processor that contains the address (location) of the instruction being executed at the current time.
■ CPU registers ==> CPU has registers 
■ CPU scheduling information 
■ Memory - management information
■ Accounting information
■ I/O status information
■ Per process file table
■ Process ID ( PID ) ==> Process has some specific ID>
■ Parent PID , etc. ==> Process has the parent process. and its ID.

NOTE: These all information is stored in PCB which is above discussed.



PCB Structure

pointer 
process state
process number
process counter
registers
memory limits
list of open files

*/



/*
Process switches from one to another.
Example: Let p0 and p1 are processes
If p0 is running then p1 is waiting state.
if p1 is running then p0 is waiting state.
How it is to going to select which process is to be execute.

CPU schedular selects which process is to select next.
CPU schedular tells the dispatcher and dispatcher calls the process which is called
as context switching.
Context Switching:
It save the current process context in its PCB and then execute the process requested
by the schedular by getting its state from its PCB.
==> Context: is the register or other values of the process which is to be save in memory.
==> Time for context switching is overhead. No do any useful work while switching.
In computers, overhead refers to the processing time required by system software, which includes the operating system and any utility that supports application programs.
*/


/*
Corresponding to the states, system maintain the queues:
■ Job queue - set of all processes in the
 system .
■ Ready queue - set of all processes
 residing in main memory , ready and
 waiting to execute .
■ Device queues - set of processes
 waiting for I / O devices .

■ Process migration between the various
 queues
*/


/*
Schedulars:
Three types of Schedulars:
1) Long term ==> The process from job pool to main memory
Job Pool is the space in the disk where the process which is requested by
the user wait to be in,, in the main memory.

2) Short term ==> The process from main memory/ready queue to CPU/
3) Medium term ==> Take the process from the main memory/ready queue or I/O queue to the Disk temporily is done by the medium schedular.
This process is known as swapping and medium term schedualar is also known as swappwer.
The space where on the this process will go on the disk is known as swap-disk

*/