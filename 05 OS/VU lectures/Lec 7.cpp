/*
Wait System Call:
=> Parent process make a child with fork and then parent process call the wait system call and then parent process in the wait state until the child terminates. Parent Process knows about child termination because child will return process identifier to parent
=> If the child process terminates before the parent process go in the wait state then parent will no go in the wait state.
=> If the call is successful , the process ID of the terminating child is returned.
=> If the parent process get terminates before the child then to who the child will return the value?
=> These type of processes known as zombie process. Because now the process remain in the memory.
=> But for fixing it, this type of processes given to init process which is 1st process of user and this terminates the child process then.
=> Thus the children still have a parent to collect their status and execution statistics.
*/


/*
exec System Call:
=> Typically the exec system call is used after a fork system call by one of the two processes to replace the process ' memory space with a new executable program.
=> The new process image is constructed from an ordinary , executable file.
=> There can be no return from a successful exec because the calling process image is overlaid by the new process image.
We are discussing the excelp command like there are other exec commands as well.
if ( execlp ( "/bin/ls " , " Is " ,NULL ) < 0 ) // execlp read its argument. It knows 1st is address of executable and 2nd is name for that particular process and it do not know that how many argument it take so it stop when it finds null pointer and here is 3rd argument.

*/



/*
Cooperating Processes:
=> Independent process cannot affect or be affected by the execution of another process.
=> Cooperating process can affect or be affected by the execution of another process. Because they are sharing something.

Advantages of process cooperation
■  Information sharing
■  Computation speed - up because CPU handle small processes simultaneously. 
■  Modularity Divide big process into small
■ Convenience  

*/


/*
Buffer:
The main memory has an area called buffer that is used to store or hold the data temporarily that is being
transmitted either between two devices or between a device or an application. Buffering is an act of storing data temporarily
in the buffer.

Producer Consumer Problem OR Bounded Buffer Problem:
Buffer can be unbounded and bounded.
Suppose you have array in the bounded buffer. Consumer takes value from the buffer and set its variable to point to next which is to
be consume and Producer variable points to the index where is to be produce and after that points to next index.
Suppose Producer is faster than Consumer then buffer may get full and Where it have to point for next.
Similarly, Consumer can be faster and buffer may get empty and then to whom the consumer variable point?


Solution is that assume 10 size buffer. In variable for producers and out variable for consumer.
We have to utilize the 9 space in buffer and left the last one. Reason we code its solution like that. Otherwise condition of consumer and producer will get same.
If in and out are equal then empty buffer and consumer should wait/do nothing.
If in+1 == out then buffer is full and producer should wait/ do nothing.
*/