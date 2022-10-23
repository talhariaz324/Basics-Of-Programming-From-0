/*
Long - term scheduler ( or scheduler )
- selects processes from the job pool to
be brought into the ready queue.

  Long - term scheduler is invoked very
  infrequently ( seconds , minutes ) ( may be
  slow ).

  The long - term scheduler controls the
  degree of multiprogramming.

  More processes , smaller percentage of
  time each process is executed.




Short - term scheduler ( or CPU scheduler ) -
selects which process should be executed
next and allocates it the CPU through the
dispatcher and dispatcher do context switching process.

  Short - term scheduler is invoked very
  frequently ( milliseconds ) ( must be fast ).

  Invoked when following events occur
   => CPU slice of the current process finishes
   => Current process needs to wait for an event
   => Clock interrupt
   => 1/0 interrupt
   => System call
   => Signal



Medium Term Schedular:
Also known as swapper

Selects an in - memory process and swaps
it out to the disk temporarily

The process sending in the disk is swap out.
The process of getting back in the main memory is swap in.

Swapping decision is based on several
factors:
 1) Arrival of a higher priority process but no memory available
 2) Poor mix of jobs
 3) Memory request of a process cannot be available then move.

*/




/*
Parent process creates children processes.
which , in turn create other processes,
forming a tree of processes.

Resource sharing:
 1) Parent and children share all resource.
-2) Children share a subset of parent's resource.
 3) Parent and child share no resource.
Execution:
 => Parent and children execute concurrently.
 => Parent waits until children terminate.
 => Child wait for the parent to done. But this is not most of the time case
 and this also dont have any logic.




=> Address space
    Child duplicate of parent.
    Child has a program loaded onto it .
UNIX examples
 fork system call creates a new process
 exec system call used after a fork to replace the process ' memory image with a new executable .




Process executes the last statement and
requests the operating system to
terminate it ( exit ) .

=> Output data from child to parent ( via wait ) .
=> Process resources are deallocated by the
operating system , to be recycled later .





Parent may terminate execution of
children processes ( abort ).
Reasons of doing this:
-Child has exceeded allocated resources ( main
memory , execution time , etc. ) .
Parent needs to create another child but has
reached its maximum children limit
Task performed by the child is no longer
required .
If Parent exits:
 Operating system does not allow child to continue
 if its parent terminates .
  Cascaded termination .




When the fork system call is executed , a
new process is created which consists of a
copy of the address space of the parent .

This mechanism allows the parent process
to communicate easily with the child
process.

  SYNOPSIS
  #include < sys / types.h >
  #include < unistd.h >
  pid + fork ( void ) 




The return code for fork is zero for the
child process and the process identifier of
child is returned to the parent process .

On success , both processes continue
execution at the instruction after the fork
call .

On failure , -1 is returned to the parent
process and errno is set appropriately to
indicate the reason of failure ; no child is
created.


Based on the return value to the parent and child on success we can 
run particular piece of code for child and parent separately.
For example: child success. return value to child is 0 and process identifier
return to parent is 1234.
We can make check and run particular code.




The child process inherits the following
attributes from the parent:
Environment
Open file descriptor table
Signal handling settings
Nice value
Current working directory
Root directory
File mode creation mask ( umask )




The child process differs from the parent
process :
-Different process ID ( PID )
-Different parent process ID ( PPID )
-Child has its own copy of parent's file
 descriptors
-Etc .



The child process differs from the parent
process :
-> Maximum number of processes allowed
on the system has exceeded
-> Not enough swap space
*/