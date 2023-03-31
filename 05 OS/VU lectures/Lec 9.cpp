/*
IPC Tools are going to discuss:
Related Process means those who have some relation like parent process
and child process. 
Pipe: For communication between related processes on a system.
Parent make a pipe and child with fork system call. As you know fork make
the same as parent so child also know it has the pipe.



Named Pipe(FIFO): For communication between related or unrelated processes on a system. 
They have file FIFO on disk and use for communication.

Most Useable
Socket: For communication between related or unrelated processes on a same system or different systems.
Each process make its own socket and internally, Kernal on both systems make sure communication using some 
network software. 
*/



/*
Important System Calls for all IPC which we discuss above
open ==> Open return file descriptor corresponding to the opened file. We pass this file descriptor to the kernal along with some other parameters to perform some action on file. If the open command do not find file then it will create it.
read ==> Read the file/ pipe.
write ==> Write the file/ pipe.
close ==> For close/destroy the file or FIFO (No need to close the pipe)
pipe ==> is used to create pipe communication channel b/w related processes.
*/


/*
open system call syntax or parameters we pass:
1st parameter: path where is file
2nd parameter: oflag ==> Purpose of opening file like reading/ writing or both or something else.
3rd parameter: mode ==> If file do not exist then open file will create file. For setting permissions to that file we use mode. If file already exists then it already have permissions.

open system call get fails if signal come.
Returns -1 on failure.
Open System Call can fail for below reasons:
    Non-existent file
    Operation specified is not allowed due to file permissions.
    Search not allowed on a pathname
    User disk quota on the file system has been exhausted/full.
*/



/*
Read system call parameters:
file descriptor of the file to read.
pointer to buffer,,, area in process where the read data store
number of bytes that max can be read.
This system call can return int which is bytes that are readed.
3rd parameter and return value may not equal because you allow max 120 bytes and read data bytes are 100 bytes.



When we done with the read using loop then at the end it returns 0 which means all reading is done.

Can Fail:
invalid file descriptor, buffer, number of bytes.
Signal caught.
*/


/*
Write System Call Parameters:
file descriptor of the file to write.
pointer to buffer,,, area in process where the data for write data store
number of bytes that max can be write.


Call Fails:
Invaild Argument 
File size limit for process or system would exceed.
Disk is full
*/


/*
Kernal maintain a table for each process called PPFDT.
When we want to read/ write... kernal use the file
descriptor to index the slot in the PPFDT. It gives pointer
which go in the file table. It also return pointer and go in the Inode table.
Inode table has the inode for each file uniquely. this inode has all the
attributes and the path to the file at the disk.
*/


/*
Standard Files are those which are automatically opened for every process for
the process to read its input from and send its output and error messages to.
Standard Input ==> By Default process read data
Standard OutPut ==> By Default process write/output data
Standard Error ==> By default process error messages are sent to
are created for each process. PPFDT has first 3 slots already fill with these.
when new file created then it will be at 4 slot.

Standard files also have the file descriptor called standard file descriptor.
Standard files are attached to the terminal on which a process runs.
Standard Input 0 Keyboard
Standard OutPut 1 Display Screen
Standard Error  2 Display Screen
*/



/*
Pipe() call:

int pipe(int pipedes[2]);
Call Fails:
At least 2 slots not empty in the PPFDT because pipe return 2 file desctriptors for read and write--- too many files or pipe open
in the process.

Buffer space not available in the kernel.
File table is full.



Characteristics of Pipe call:
As discuss in previous lec




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


/*

Command line use of pipe.

Connect standard output of a connect to standard input of another
Use pipe operator |
cmd 1 | cmd 2 | ...| cmdN


Example:
cat /etc/passwd | grep zaheer

cat is used to display content of passwd file content
But with pipe we connect it with grep
grep is use to get only those lines with characters of zaheer.
*/