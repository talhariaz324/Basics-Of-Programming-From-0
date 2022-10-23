/*
OS Components:
Process Management
Main Memory management
Secondary Storage Management
I/O system management
File management
Protection Management
Networking
Command Line Interpreter (shells)
*/


/*
Services for User and user of programs:
Program execution
I / O Operations
File System Manipulation
Communications between
processes / users
Error detection and handling


Services for efficient system
operation :
Resource management
Accounting
Protection
*/


/*
OS Kernel:
STRUCTURE:
Users
Applications
Operating System API , AUI
Operating System Kernel
Computer Hardware
Real work is done in the kernel
Actually Everything done in kernel.



Entry Points into Kernel
System Call
Interrupt
Signal
Trap
*/


/*
User processes must not be given open access to the kernel code
=> The system call interface layer
contains entry point in the kernel
code
=> Any user or application request
that involves access to any system
resource must be handled by the
kernel code




Types Of System Calls:

Process Control
File Management
Device Management
Information maintenance
Communications


System Call Execution
=>The user program makes a call to a library function .
=>Library routine puts appropriate parameters at a well - known place ( registers , stack , or a table in memory ) .
=>The trap instruction is executed to change mode from user to kernel .
=>Control goes to operating system .
=>Operating system determines which
system call is to be carried out by indexing in the dispatch table.

Dispatch Table: contains pointers of particular code of system call.



Kernel indexes the dispatch table , which contains pointers to service routines for system calls .
Service routine is executed and return parameter or error code placed at wellknown places ( usually a CPU register ) .
Control given back to user program .
Library function executes the instruction following trap .
*/


/*
Operating System Structure:
■ Simple Structure
■ Layered Approach
■ Microkernel
■ Virtual Machines


Simple Structure are those which dont have any structure just for efficiency. E.G; DOS,,, it has no structure, it simply has essentials 
for OS in simple order.
e.g; DOS and UNIX
UNIX as such dont have any structure but just for clarity this is simple structure we have:

User   User makes a request
----- 
libraries  User request may go for libraries (compiler or interpreter)  OR may go for system call if request is not of compiler or interpreter.
------
System Call        Depend on request either compiler or system call
------ 
Kernal      All the components of OS are handle by the kernal
------
Kernal to Hardware    Kernal connect to hardware by using hardware drivers.



Layer architecture:

The OS is broken up into a number of
layers
Bottom layer is hardware and the
topmost layer ( layer N ) is the user
interface

Upper layer serve by the below layer. For example M-1 and top of it is M and then top of it is M+1.
M will be serve by the M-1 and M+1 by the M.
layers are connected by the service points.

Advantage:  is that modularity and we can manage each layer
Disadvantage: Difficult to build

MicroKernal:

Structures the operating system by
removing all non - essential components
from the kernel and implementing as
system and user level programs

Smaller kernel

Main function is to provide a
communication facility between client
programs and the various services that
are also running in the user space.

NOTE: Essential includes => Kernal have inter-process-communication and the message passing. All Other processes are on the
user assistant processes.

Working: Whenever the user make a request e.g; File Server... His req using the client process which use message passing in kernal and
give to request Server and server process req and give result.
NOTE: File sever here running as user process Because here user request is not in kernal but in user assistant processes and here his req is file server


ADVANTAGE:
Easier to extend the OS - new services
are added to user space and consequently
do not require modification of the kernel
and / or its recompilation
Easier to maintain operating system code
( enhancement , debugging , etc. )
OS is easier to port from one hardware
to another
More security and reliability


We can also run application by adding their server to the microKernal OS. e.g; Win32 app on the win32 server while winNT is running.




Virtual Machine:

By using CPU scheduling and virtual memory we emulate the actual/underlying hardware we produce a virtual machine on top of the actual/underlying hardware. User can install 
another OS on that VM and use it. Even we can make more than 1 VM and allow user to make their work.

BUT memory of VM is not larger than normal system. Like if system have 512 Mb then we can say left 96MB and use other. 

Difficult to implement
But allow to do work on different OS without having disturbing normal system operations/ actual system. 

NOTE: Concept of VM is also use by languages like JAVA.
Working: Java code to byte code. byte code loads to VM using java Vm and then verify and then interprets by the Java interpreter.
We do interpret Java code independent of Normal MAchine as long as we have java vm.

*/