

/*
Few Concepts:

Job is work that needs to be done.
A task is a piece of work that needs to be done.
The process is a series of actions that is done for a particular purpose. 
Job and task define the work to be done, whereas process defines the way the work can be done or how the work should be done.


In OS:
A process refers to a program under execution. This program may be an application or system program.
Job means an application program and it is not a system program.


Zombie processes: A zombie process is a process in its terminated state. This usually happens in a program that has parent-child 
functions. After a child function has finished execution, it sends an exit status to its parent function. Until the parent function
receives and acknowledges the message, the child function remains in a “zombie” state, meaning it has executed but not exited.



NOTE: When some process in the foreground then we cant use the shell. 


*/



/*
Process Management Commands:
ps:  Display the status of all the processes OR the status of some particular process belonging to the some user OR showing the
long listing of the processes.

top: show status of all the processes after sorting that which is using more CPU.
Also give the status of the memory available and used, cache available and used, and swap (swach space) available.
How much processes are running and how much are sleep mode. 
How many are zombie processes.



Suspended processes: are those which are stop for a while.
Terminate processes: are those which are end. no more.

fg [% JOB_ID]

fg resumes the execution of a
suspended job in the foreground and
move a background job into the foreground.

If %job_id is omitted the current job
is assumed.



bg [% JOB_ID]

fg resumes the execution of a
suspended job in the background.


If %job_id is omitted the current job
is assumed.

bg runs the current or specified job in the background.


jobs command

jobs displays status of suspended and 
background processes.




Suspending a process:

Ctrl+Z send a command a STOP/SUSPEND signal to the current process.
The shell displays a message saying that the job has been suspended
and displays its prompt.

You can then manipulate the state of this job, put it in the background
with the bg command, run some other commands, and then eventually
bring the job back into the foreground with the fg command.



Ctrl+C sends the SIGNIT signal to the current process, which, by default
terminates the process.
Its actually send the signal interupt to the foreground process, kernal do the default 
behaviour of this signal which is terminate.



kill [-signal] PID sends signal number 'signal' to process with ID 'PID'
This command sends the signal which number we mention in bracket to the process which id is given. kernal do the default acc to signal.

kill 123 send the SIGTERM signal to the process with ID 123.


kill -9 send the "sure kill" signal.

kill -l displays the the signal and their numbers supported by the system .
*/




/*
Today we are going to discuss threads but before lets discuss the issues
of the processes.

The fork() system call is expensive because it will copy the same process
in memory.

IPC is required to pass the info between a parent and its child processes.


Thread:
A thread is a piece of code of the process which is executed simultaneously with the remaining process code.
It also share the code and data of the process and it also use the PPFDT and PCB of the same process.

A thread is a "light weight" process which executes within the address space of a process


A thread can be scheduled to run on a CPU as an independent unit and terminate.


Multiple threads can be run simultaneously.



Threads have their own:
Thread ID
CPU context (PC)
Thread can be at any place in process then they have their program counter
program counter: is use to execute next instruction 
Stack
Priorty
errno




Thread share

Code and data
Open files (through PPFDT)
Current working directory
User and Group IDs
Signal setups and handlers
PCB



Thread and Process similarity:
A thread can be in states similar to a process (new, ready, running, blocked, terminated)

A thread can create another thread like process.



Difference thread and process:
Multiple threads can operate within the same address space

No "Automatic" protection mechanism is in place for threads--- they
are meant to help each other. 

Like in process CPU itself take care that
each process data no go outside its address space.
But in thread data is sharing then it has less security.
But this security is up to the developer. that's why 
threads development is difficult.




Advantages:
1) Responsiveness
 => Like browser is sending request user to required server.
 => But at the same time also rendering the page or running another query of the user.
2) Resource Sharing
 => Process resource (code, data, etc),
 => OS research (PCB, PPFDT, etc)   

3) Economy
    => Less time

NOTE: Those hardwares which architectures is multi process and multithreaded,,, multiple threads run simultaneously
*/



/*
Crucks:
Process need to create another process to do some other work and stop the previous process.
Child will have own PPFDT, PCB and seperate data etc.

Thread is piece of code of process which is running simultaneously with process code and share their code and data etc.
*/