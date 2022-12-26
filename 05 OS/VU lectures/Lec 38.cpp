/*
Page Fault and No free Frame:
-> Page Replacement => Get page into frame, if frame not available then 
place new page over the existing page if existing page is in the same condition
as we got it from disk. If existing page changed after getting into memory then
we swap out it and swap in our new page.
    -> Replacement algorithm (minimize number of page faults)
    -> Performance with replacement 
    -> Victim selection
        -> Local vs global
*/

/*
Another Example:
Effective memory access is 100 ns
page fault overhead is 100 microseconds = 10^5 ns
Page swap time is 10 milliseconds = 10^7 ns
50% of the time the page to be replaced is dirty (means replacing the victim would take 50% time)
Restart (for update page table) overhead is 20 microseconds = 2 * 10^4 ns

Effective access time = 100 * (1 - p) + (10^5 + 2 * 10^4 + 0.5*10^7 + 0.5 * 2*10^7) * p
             Calculated EAT would be if we put values:
                    = 100 * (1-p) + 15,120,000 * p
*/


/*
What is a good page fault rate?
For the previous example suppose p is 1%, then EAT is
= 100 * (1-p) + 15,120,000 * p
EAT = 151299 ns
===> a slowdown of 151299/100 = 1513 ns
So get slow with 1% p is 1513


For the luxury of virtual memory to cost only 20% overhead (includes page faults etc), we need:
120 > 100 * (1-p)  + 15,120,000 * p
120 > 100 - 100p + 15,120,000 p
p < 0.00000132
===> Less than one page fault for every 755995 memory accesses.

So p (page fault) should be small as possible.
*/

/*
Process Creation:
-> fork()
    -> Exact copy of parent;s memory image
    -> Copying parent's pages (address space)
-> Child may call exec() immediately ==> copying parent's address space 
is not needed because child would have its own memory image. Then why we do fork? so making efficient we use 2 techniques
1) Copy on write:
2) vfork()
*/


/*
copy on write:
-> Child share's parent's address space and pages which may get change are
marked "copy on write".
-> When a process tries to modify a page (which marked as copy on write), it copied and inserted in the page table
for the process
-> Used in windows 2000, solaris 2 and linux 
*/

/*
vfork() ==> We use when child have to immediately call the exec and have its own memory image. In this case we dont need copy. so we solve it with vfork()
-> parent is suspended (not terminate) and child uses parent's address space
-> Pages altered (change) by the child process are visible to parent
-> Intended to be used when child process calls exec() immediately after its creation
*/

/*
Linux Implementation:
-> Shared pages are marked readonly after fork()
-> If either process tries to modify shared page, a page fault occurs and the page is copied for modify.
-> The other process (who later faults on write on this copied one) discovers it is the only owner;
so no copying takes place. 
*/

/*
Memory Mapped Files:
-> Earlier we use system calls to read, write the file from the disk but it was slow because of mechnical.
So,
-> Memory-mapped file I/O allows file I/O to be treated as routine memory access by
mapping a disk block to a page in memory. (Means we take file and mapped its blocks in pages in memory).
This mapping is in the process address space which want to access that file. And mapping maybe in page table

-> A file is initially read using demand paging from the disk and mapped into pages in memory and mapping of blocks and pages took in process address space.
-> A page-sized portion of the file is read from the file system into physical page. (as tell above from disk to memory)
-> Subsequent reads/writes from/to the file are treated as ordinary memory accesses as we access variables etc.


-> Simplifies file access by treating file I/O throgh memory rather than read and write system calls.
-> Also allows several processes to map the same file, allowing the pages in memory to be shared.
-> Some OS only provide memory-mapping a system call (mmap()). Others treat all file
I/O as memory-mapped files.


Details:
Process A process        Memory              Process B
1, 2, 3                1, 2, 3              1, 2, 3

So 1,2,3 are blocks in memory (with frames)
Process A and B are mapped with these blocks.
If process A want to access block 3 then it would check its page table
and get the frame number for block 3 and get into it.


Difference in Normal File I/O and File I/O with mmap()
Normal File I/O:
fildes = open(...) // give descriptor
lseek(...) // some operation
read(fildes, buf, len) // store the files data into buf and then we can use it.

File I/O with mmap():
fildes = open(...) // give descriptor
address = mmap((caddr_t)0, len, (PROT_READ | PROT_WRITE), MAP_PRIVATE, fildes, offset); 
so mmap some parameters and it auto map the file from disk to memory.
Its working is it would map the file blocks into virtual memory in frames of calling process.
and then map blocks and pages into the address space of process and set the page table so that whenever process want to access block of its address space, it can go with frame number in its page table.

We would use this address variable for accessing the file from main memory.
*/


/*
Memory Mapped Files in Solaris 2:
It uses both memory mapped techniques:
-> If file is opened as memory mapped (mmap uses); it maps the file to the address space of the process.
If not mmap then store in kernal buffers and give data on read and write.
-> If the file is opened non memory mapped, solaris 2 opens it as a memory mapped file, mapping it to kernel address space.
*/