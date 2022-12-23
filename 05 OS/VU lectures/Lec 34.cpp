/*
Memory Protection in paging:
Memory Protection in paging is achieved by associating
protection bit with each page table entry.

Valid/Invalid bit... page in the process address space or not.

it is not just valid and invalid but it can also be read, write and execute.

For example: Assume logical address space is 0 to 7 so the page table 
would be 0 to 7. But suppose in the logical address space process has
only 6 pages from 0 to 5.
So while accessing it access in page table page 6 and 7 where it will find
nothing so here we add bit invalid which will not cause error.
*/

/*
Structure of the Page Table:
Hierarchical / Multilevel paging
Hashed page table
Inverted page table

We need these structures when the page table is very large because of 
large logical address space. So for handling these large page tables we
use these structures.

Multilevel paging particular use for the above reason and when also
our page is larger than the page table.
*/

/*
Multilevel paging:
Logical address = 32 bit
Page size = 4K bytes (2^12 bytes)
Page table entry = 4 bytes
Maximum pages in a process address space = 2^32 / 4K = 1M
Page table size = 4M bytes
This page cannot fit in one page => So do the paging of page table.


Page Table needed for keeping track of pages of the page table called 
the outer page table (new page table) or page directory.

No. of pages in the page table is 4M/ 4K  = 1K
Size of the outer page table is 1k * 4 bytes = 4k bytes => So outer
page will fit in one page. So stop here. This call as 2 level. It can be more levels if still page larger than the table size.

How would the addressing and address translation now done?

=> 32 bit logical address: p1 used to index the outer page table and p2
to index the inner page table (old).
|d| = log base 2 of 4K =  12 bits
|p| = 32 - 12 = 20 bits

So first 10 points to p1
So second 10 points to p2
and offset is 12.

Summary:  P1 will go in inner page table and take the frame number and 
check in the outer page table and get the frame number and append with 
d and give the physical address.



Another Example of DEC VAX computer

logical address =  32 bits
Page size = 512 bytes = 2^9 bytes
Process address space divided into 4 equal sections
As divided into 4 so 2^32 / 4 = 2^30
Pages per section = 2^30 / 2^9 = 2^21 = 2M
Size of a page table entry = 4 bytes

Bits need for page offset d = log base 2 of 512 = 9 bits
Bits to specify a section = log base 2 of 4 = 2 bits
Bits needed to index page table for a section = log base 2 of 2^21 = 21 bits
Size of a page table = 2^21 * 4 = 8MB
So larger than page size.
8MB page table is do paging into: 8Mb/ 512 = 2K pages
Size of the outer page table (2K * 4 = 8KB) so again large.
Do paging. resulting 3-level paging per section
FINAL:
section  Page number  page offset
2           21            9





MORE Examples:
64 bit Sun UltraSPARC supports 7 level paging-- too many memory references
needed for address translation. This is needed when we have very large 
logical address space. And this is the case when we have large programs.
*/

/*
Hashed Page Table:

A common approach to handle address spaces larger than 32 bits.
Usually open hashing is used
Each entry in the linked list has 3 fields: page number p, frame number f
and pointer to the next element.

More details:
Logical address (p,d)
p is hashed and give some number which is called as hash
Search this hash in the hash table.
This hash in hash table will have the pointer to linkedlist (here insted of linkedlist , only frame number can be but both approach used by the experts)
so linked list has, p,f,next 
append f with d and generate physical address.
*/


/*
Inverted Page Table:
-> One entry per real page in memory
-> Page table size is limited by the number of frames(i.e; the physical memory)
and not process address space.

Each entry in the page table contains (pid, p) where pid is process id because at sometime
more than one process can be available in physical memory.

If a page "p" for a process is loaded in frame f, its entry is stored at index
"f" in the page table. Mean f become index in page table. On the other hand f is already frame in physical memory

We effectively index the page table with frame number; hence the name
inverted page table.

Examples: 64-bit UltraSPARC and PowerPC

MORE details (Hardware Support): 
CPU -> logical address (pid, p, d) -> search pid and p -> on find get frame number which is index -> append index with d -> physical address (physical memory)
*/