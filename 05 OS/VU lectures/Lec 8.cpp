/*
Inter Process communication:
In the last lecture we learn about the cooperating processes. These processes share data in order to work. How they share info/data
between each other. This sharing is done by the IPC.
IPC also synchronize the actions of each process during communication.

We are going to discuss the message passing for communication which is IPC. But this communication can also be done with the help of 
shared variable. Like sender set the variable and the reciver read that variable. but we are discussing the message passing.
*/



/*
IPC has 2 operations:
1) Send ==> Message (Size can be fixed or variable)
2) Receive
*/


/*
If P and Q wish to communicate, they need to:
1) Establish a communication link
2) Exchange messages via send/receive


Communication link can be:
1) Physical ---> Shared Memory, Hardware bus
2) Logical ---> Logical Properties
*/


/*
Communication link Implementation Questions
How are links established?
Can a link be associated with than two processes?
How many links can there be between every pair of communicating processes?
What is the capacity of a link?
Is the size of a manage that the link can accommodate fixed or variable?
Is a link uni or bi directional? 
*/

/*
Communication between processes can be of 2 types:
1) Direct Communication ==> Sender knows the name of reciever and reciever knows the namme of sender.
2) inDirect Communication ==> Both dont know each other name. Sender put the message in the channel/mailbox and mailbox has id and reciver get messgage from mailbox.
In this indirect communication process can communicate only if they share a mailbox.
*/



/*
Direct Communication Link Properties:
Links are establish auto because sender and reciever name.
Link should be with one pair.
Each Pair exists exactly one link.
Maybe uni and bi.
*/



/*
inDirect Communication Link Properties:
Links are establish only if they share a mailbox.
Link maybe associate with many processes.
Each Pair may share several communication link.
Maybe uni and bi.



Operations:
Create a new MailBox
Send And Recieve messages through mailbox.
destroy mailbox



Problem Can be:
If p1, p2, p3 share mailBox A.
p1 sends P2 and P3 receive
Who gets the message?

Solution:
Allow a link to be associate with at most 2 processes.
Allow only one process at a time to execute a receive operation.
Allow the  system to select arbitrarily the receiver. Sender is 
notified who was the recevier.
*/



/*
In start we discuss synchronization of processes communication.
It means we stop or start process execution based on the processes.

Message passing can be either blocking or non-blocking.
Blocking is consider sync
Non-Blocking is consider async

Send and recieve can be both.


Blocking means when sender process send it wait until receive by the receiver and vice versa
NON-Blocking means when sender process send it do not wait until receive by the receiver. It continue working and vice versa for receiver
*/



/*
Buffer
Communication link can have queue for the messages.
3 ways:
1) Zero Capacity ==> Sender wait for receiver
2) Bounded Capacity ==> Sender wait if link is full (n size)
3) UnBounded Capacity ==> infinite length,,, Sender never waits.
*/




/*
IPC tools:
1) PIPE
2) Named PIPE (FIFO)
3) BSD Socket
4) TLI
5) Message queue
6) Shared Memory
*/


/*
PIPE:
Important system Calls:
1) pipe ==> Create a pipe for IPC, it returns 2 file descriptors (int). one is for sender and second is for receiver.
2) read ==> It read the data  from the PPFDT (per process for descriptive table)
3) write ==> It write the data  to the PPFDT (per process for descriptive table)
4) close ==> Destroy the pipe.

PPFDT is a table which contains the files and their data. We get file with the file descriptor which is return by the open system call.
*/

/*
An Integer returned by open system call is known as file descriptor corresponding to the opened file
Used this integer as an index in the PPDFT then we get a slot and then pointer which from we get our table of content file
Used in read, write and close calls.
Size of PPFDT is equal to the no of files that a process can open simultaneously.
*/


/*
Characteristics of a pipe in UNIX/LINUX:
Stream of bytes 
Its actually a full duplex but for reducing complexities we use as half duplex.
Bounded Buffer
Max data written is PIPE_BUF in UNIX and LINUX is 5120 and 4096 respectively.
*/



/*
There is a code for checking it. Crucks is that:
Parent => Pipe => Child
Child code:
Child read close
Child writes 
Child writes close
--------
Parent close write
Parent read what child writes
Parent use write to display which is in buffer
Parent wait but as child already close so parent continoues
cout<<"Good work child";


*/