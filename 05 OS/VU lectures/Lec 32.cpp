/*
MVT stands for Multiprogramming with variable tasks.

Both the number and size of partitions change with time.

A process still resides in one region but can be of any
size up to the size of the user space and can change with time.

Jobs can move from one partition to another

Dynamic address binding

No internal fragmentation (Space in the partition which is not allocated and can't be given to other process)

Introduces the external fragmentation.
*/

/*
What is the external fragmentation?
Suppose A process come.
B process come.
C process come.
D process come.

Suppose C process complete and left. Now the C space is not allocated. and now the space is not contiguous.
So this is the external fragmentation.
To fix it, we do memory compact.
A process
B process
D process
and now the contiguous space is available.
Now, we can add process.
*/

/*
Paging:
Divide physical memory into fixed-sized blocks, called frames.
Divide logical memory into blocks of the same size, called pages.
Size of a page is a power of 2.
Typical page sizes: 1K - 16K.

Keep track of all free frames.
To run a program of size n pages, find n free frames and load program pages
into these frames.

Keep track of a program's pages in the main memory by using the page table.

Process addresses space             Page Table                 Physical Address Space

Now in the process address space   In which we have pages      frame numbers and the
we have pages with numbers         numbers along with each     process.
                                   page we have frame numbers

So,,,

Logical address space of a process can be noncontiguous; a process page
is allocated a frame whenever the latter is available.

Set up a page table to translate logical addresses to physical addresses.

Internal Fragmentation (For example, process is 10k and 1 byte pages, this 1 byte take complete page and frame )
So remaining space in the frame is unallocated. So internal fragmentation.
*/

/*
Addressing in paging
-> Logical address: (p,d)
where p is page number and d is offset(actual jagaa in page) within the page.

-> p is used to index the process page table; page table entry contains
the frame number f, where page p is loaded.

-> Physical Address of thr location referenced by (p,d) is computed
by appending d at the end of f.

So, CPU make (p,d) p get the frame, and then append d with frame f. so this is 
would be in binary. so this make the physical address.

you can see example at 46.
*/

/*
Logical address   page(p) frame(f)        Frame member
page 0                 0........1         0...... null  
page 1                 1........4         1........ page 0  
page 2                 2........8         2............
page 3                 3........7         3.......... page 2
*/                                       //4 ......... page1
                                        // 5
                                        // 6
                                        // 7 ......... page3


/*Detail Example is at 23:05 in lec 33. 
How many bits required to address some number?
ceiling[log base 2 and the number] for which you want to check the how many bits

See Example now.
*/


/*NOTE: Page table are handle in hardware. If we do in software then it will get slow.*/