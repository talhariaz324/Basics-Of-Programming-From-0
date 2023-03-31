/*
Input, Output, Error Redirection:
By Default standard input, output and error is connected with the 
keyword, display and display respectively.
But what if you want to change the default files. Here come the concept
of the redirection.
*/

/*
Input redirection:
Syntax: command < input file OR command 0< input file
Detach the keyboard as input to the new input file.
Example:
$ cat < Phones
cat command take input from keyboard and output to display.
Now take input from the Phones.
*/

/*
Output redirection:
Syntax: command > input file OR command 1> output file
Detach the display screen as output to the new output file.
Example:
$ cat > Phones
CTRL + D is use to save in the unix.
Now output to the new output file which is Phones not now on the display.
*/


/*
Error Redirection:
command 2> error file
Detach the display screen as error message sending to the new file for error msg sending.

Example:
$ find ~ -name foo -print 2> errors
find search the file foo from root directory and all its sub directories for the file foo.
and send its path to display. But if now error then it send msg to errors file now.

This command can fail when search privilege is not allowed.
*/



/*
FIFO defination is discussed in previous tutorial.
It is in the disk which is use by the related or unrelated processes.

Unlike a pipe, a FIFO must be opened before using it for communication.

A write to a FIFO in case no process has opened for reading results then
it sends SIGPIPE signal.

When the last process to write to a FIFO closes it, an EOF is sent to the 
reader process.

Multiple processes can write to a FIFO ==> Atomic writes to prevent
interleaving of multiple writes.

Atomic writes means that the each process writes ti FIFO and then other
process will also write its max in FIFO. This writing size is similar to
the PIPE buff as we discuss.



Client Server FIFO:

Server has FIFO's for WAN Known FIFO which is for client to send requests to server.
Server also has the number of FIFO's according to the number of clients.
Server returns the response to each client through its FIFO.

For creating FIFO we use mknod command

Make node command in unix is used to create  special files
Special files in unix are use to represent the devices like keyboard, network connection, Mouse.
Special files can be of 2 types:
1) Block special files ==> For those who's I/O's are in form of block. like disk
2) Character special files ==> For those who's I/O's are in form of characters/bytes.

But here we are using mknod command for FIFO file creation and it is not the device file.

mknod system call

mkfifo Command

mkfifo C library call
    invokes mknod system call.
*/






/*
Command line use of FIFO:

$ mkfifo fifo1 ====> make fifo with name of fifo1
$ prog3 < fifo1 & ===> here input from fifo1 and ampersand shows this process in the background. But fifo1 is empty now so prog3 is block until the fifo1 has the content.
$ prog1 < infile | tee fifo1 | prog2 ==> take input from infile, tee writes to fifo1 and giving to prog2 using pipe.
NOW fifo1 has the content. prog3 runs, prog2 runs.



AND




$ man ls > ls.dat ===> man is command which give now manual list into the ls.dat 
$ cat < fifo1 | grep ls | wc -l & ===> reading from fifo1,,, search ls,,,,  wc is use to list the lines which containg ls because of grep and.... 
[1] Job ID,,, 21108 background process id,,,,, of above command

$ sort < ls.dat | tee fifo1 | wc -l ===> read from ls.dat and sort it. and then write to fifo1 and wc will give list of lines from all the files not only containing ls

OUTPUT:
31 ==> 2nd command
528 ==> 3rd command

$ gcc server.c -o server ==> We are using gcc terminal here to make execute of server code in sever file.
$ gcc client.c -o client ==> Same here nad in client file
$ server & // Run the server in the background for getting free the terminal to run the client command.
[1] Job id ,,, process id is 432056
$ client // Now Run Client
*/


/*
dman is the command in unix running in the background as system administrator and providing services.
*/



/*
Managing Unix/ linux Process 
| Commonly used process management commands.
ps — Display status of processes

‘top — Display CPU usage of processes by sorting them acc to their consumption

bg - Put a process in the background already running in the foreground
fg - Put a process in the foreground already running in the background
jobs - Display status of Jobs

Below are also known as the KEY-Presses
Ctrl+Z — Suspend/stop a process (suspend process do not mean terminate. it is available but not running) But not clear concept.
Ctrl+C - Send SIGINT signal to the foreground process to terminate which is default manner by kernal
kill -  Terminate a process (to send signal of any type to any process )

*/