/*
Paged Segmentation:
We do paging of segments.
Divide every segment in a process into fixed size pages.
Need for a page table per segment
CPU's memory management unit must support both segmentation and paging.

Why need?
With increase of logical address space, segments increase so we face more
external segmentation. For fixing external segmentation we do paging of
segmentation.

Logical address is still <s,d> with s used to index the segment table.
Each segment table entry consist of the tuple:
1) segment length
2) page table base 
The logical address is legal if d < segment-length

-> Segment offset d is partitioned into two parts:
p and d', where p is used to index the page table associated with
segment s and d' is used as offset within a page

p indexes the page table to retrieve frame f and physical address  is 
get by appending: (f,d').


Hardware support:
logical address (s,d) => d valid or not => then d divides into p and d' => p sends into s segment table and get frame number f => append f and d' = physical address 
*/

/*
Example:
-> Ge 345 processor
-> Logical address = 34 bits
-> Page size = 1 KB
s is 18 bits and d is 16 bits
Find;
Size of p and d', largest segment size, and max, number of segments per process?

Solution:
K is 1024 where needed
Largest segment = 2^d = 2^15 bytes -->15 or 16 check calculator
Maximum number of pages per segment = 2^16 / 1K = 64 
|p| = log base 2 of 64 bits = 6 bits
|d'| = log base 2 of 1 K = 10 bits
Maximum number of segments per process = 2^s =218

Consider a process with its segment 15 having 5096 bytes.
The process generates a logical address (15, 3921)
Is it legal address? => 15 segment is within or equal s legal and d is 3921 < 5096 so legal
How many pages does the segment have? => |5096/1| = 5 (0 to 4)
What page does the logical address refer to?  3921 / 1K(1024) and quotient  = 4 (page number is 3)
what are the value of d' and the physical address if page number 3 (i.e. the fourth page) is in frame 12?

d' = 3921 - 3*1K = 849
Physical address = 12 *1L + 849
 = 13137

*/



/*
Intel 80386 Example:
IBM OS/2, Microsoft Windows, and Linux
Paged segmentation with 2 level paging
Logical address = 48 bits
16-bit selector and 32 bit offset
Page size = 4KB
4-byte page table entry 
32 entry TLB, covering 32*4K (128 KB) memory ... SO TLB reach(How much TLB can reach in memory) is 128 KB

 offset includes:
 16 bit first are selector, 32 bits are offset
 First 16 bit contains 3 parts:
 s (Segment)         g(1 bit global or local segment)      p(2 bit privilege)


2 cases for intel

1) Real Mode:
 20- bit physical address is obtained by shifting left the selector value 
 by four bits and adding to it the 16 bit effective address

2) Protected Mode:
  2^48 bytes -> virtual address space
  2^32 bytes -> linear address space (Actually this is segment space and it tell the linear address which is here 32 which tell offset would be 32 bits)
  Max segment size = 4GB because 2^32
  Max segments per process  = 16K because as above we discuss 16 bit selector in which 13 bit is s and 1 bit is local global so total 14 and 2^14 = 16 K
  Six CPU registers allow access to six segments at a time.

Selector is used to index a segment descriptor table to obtain an 8 byte
segment descriptor entry. Which gives base address and offset are added
to get a 32 bit linear address, which is partitioned into p1, p2 and d
for supporting 2 level paging.

CPU support: 
logical address -> selector get into descriptor table and give base address -> append with offset -> gives p1(directory), p2(page), offset so whole is linear address -> p1(directory) use to index into inner table(page directory) -> which leads to page table and give frame number -> append frame number and offset of linear address = physical address
*/