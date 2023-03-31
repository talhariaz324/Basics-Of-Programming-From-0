/*
User Threads:

Thread Management done by user level threads libraries
Kernel not aware of threads
CPU not interrupted during thread switching
A system call by a thread blocks the whole process
Fair scheduling: P1 has one thread and P2 has 100 threads.
Then CPU will give the fair time to the process P1 and P2 because CPU
only knows the process not threads of P2 so it will stop the process
execution until the thread complete its work.

Examples:
1) POSIX Pthreads
2) Mach C-threads
3) Solaris 2 threads
*/



/*
Kernel Threads:

Thread Management done by kernel
Kernel aware of threads
CPU switched during context switching 
A system call does not block the whole process
Fair scheduling: P1 has one thread and P2 has 100 threads.
Not fair scheduling between P1 and  P2. Because P2 has threads it runs 
the process code and thread simultaneously so it get more CPU time
then the P1 so it is not fair scheduling.

Examples:
Windows NT/2000
Solaris 2
Linux
*/


/*
Multithreading Models to implement user level threads and to attach with the kernel level thread:

Support for both user and kernel threads.
1) Many to One: Many user threads per kernel thread; process blocks when
a thread makes a system call.

Solaris Green threads
Pthreads

2) One to One:  One user thread per kernel thread; process does not
block when a thread makes a system call.
Overhead for creating a kernel thread per user thread
True concurrency achieved
Windows NT/2000, OS/2

3) Many to Many: Multiple user threads multiplexed over a smaller or equal
number of kernel threads ==> Not concurrency because maybe user level thread are 10 but in kernel thread maybe only 1 or maybe more which is supporting the user-level thread.
True concurrency not achieved because kernel can only schedule one
thread at a time
 Kernel can schedule another thread when a user thread makes blocking
system call
Solaris 2, HR UX
*/



/*
Solaris 2 Threads Model:

=> Solaris 2: Threads, Light Weight processes and processes

    At least one LWP per process to allow a user thread to talk to a
    kernel thread.
    User level threads switched and scheduled among LWP's without
    kernel's knowledge.
    One kernel thread per LWP; some kernel threads have no LWP 
    e.g; threads for clock interrupt handler and scheduling.
*/


/*
Pthreads:
A POSIX (Portable operating system interface) standard (IEEE 1003.1c) API
for thread creation, termination, and synchronization.

API specifies the behavior of the thread library, implementation is up tp
developers of the library.
Common in UNIX operating systems.


Creating a Thread:
int pthread_create (pthread_t *threadp, const pthread_attr_t *attr, void (*routine)(void *), arg *arg);
1st parameter: ID of the thread
2nd parameter: attributes which you want to give the thread other than the default attributes. LIKE Stack size, stack address. detached, joinable, priority etc.
Detach mean other thread cannot make join (wait for it to done and then start its execution) call on it
Joinable is that it allow other thread to join
3rd parameter: function which you want to make thread.
4th parameter: arguments which you want to give to the function.


Error Handling:
pthread_create() fails and returns the corresponding value if any of the
following conditions  is detected:

 EAGAIN: The system-imposed limit on the total number of threads in a process
 the total number of threads in a process has been exceeded or some system resource has 
 been exceeded (for example, too many LWP were created).

 ENOMEM: Not enough memory was available to create the new thread.



 Joining a thread:
 Waiting for a thread
 int pthread_join(pthread_t aThread, void **statusp);

number of thread to which thread you want to join
 statusp get return value of pthread exit (thread which ends).

Cannot join with a detached thread
Can only join with thread's in the same process address space
Multiple threads can join with one thread but only one returns successfully,
others return with an error that no thread could be found with the given TID.


Terminating a thread:

Main thread terminates

Thread returns

void pthread_exit(void *valuep)

Returns value pointed to by ‘valuep’ to
a joining thread,if provided the exiting
thread is not detached


Example:
C program

NOtE: Typically functions are the threads that we make.
you make main func
in main you make thread "a"  function
and then call a  function
Now main thread and a function thread are running.
First the function thread complete and then remaining main thread complete because we make thread using the pthread library which is for the user level thread. 


Another example for it is that we can loop the makeing of thread and make the 5 threads using pthread library.

first complete the 1st thread and its output show.
second complete the 2nd thread and its output show.
third complete the 3rd thread and its output show.
fourth complete the 4th thread and its output show.
five complete the 5th thread and its output show.

and then main and then exit. If we use the exit system call for terminating the thread then process is terminated instead of thread
because kernel do not know about threads because they are user level (pthread).
If you want to use the exit system call then use it with pthread.exit(). then it terminates the thread.

*/