/*
Addressing in paging:

Logical address space of 16 pages of 1024 words each, mapped into a physical
memory of 32 frames.

Logical address size?
Physical address size?
Number of bits for p, f and d?


Number of bits for p: ceiling[log base 2 of 16] bits = 4 bits
Number of bits for f: ceiling[log base 2 of 32] bits = 5 bits
Number of bits for d: ceiling[log base 2 of 2048] bits = 11 bits // Assuming each word is 2 bit then 2 * 1024 = 2048


Logical address size = |p| + |d| = 4 + 11 = 15 bits
Physical address size = |f| + |d| = 5 + 11 = 16 bits
*/

/*
Assuming last example
Page Table Size

Page table size = Number of pages * Page table entry size (equal to |f| based
on our discussion so far).

Page table size = 16 * 5 bits = 16 bytes Here 5 bits approx = to 1 byte so 16 * 1
*/

/*
Paging in intel P4

-> 32 bit linear address (In p4 linear address is not logical address)
-> 4K page size
-> Maximum pages in a process address space = 2^32 / 4K
-> Number of bits for d = log base 2 of 4K = 12
-> Number of bits for p = 32 - 12 = 20
*/

/*
16-bit logical address
8K page size
Maximum pages in a process address space = 2^16 / 8K

|d| = log base 2 of 8K = 13 bits
|p| = 16 - 13 = 3 bits
|f| = ? We cannot find because we do not know the physical address space.
*/

/*
Another Hypothetical Example

Logical address = 32 bit
Process address space = 2^32 B = 4 GB
Main memory =  Ram = 512 MB
page size = 4K
Maximum pages in a process address space = 2^32 / 4K = 1M

|d| = log base 2 of 4K =  12 bits
|p| = 32 - 12 = 20 bits
No. of frames = 512 M / 4K = 128 K
|f| = ceiling [log base 2 of 128K] bits = 17 bits = 4 bytes

Physical address = 17 + 12 bits 
*/


/*
Implementation of Page Table:

In CPU registers, we can implement page table.
Ok for small process address spaces and large page sizes.
Effective memory access time (T effective) is about the same as memory
access time (T mem)
PDP-11



Implementation of page table in main memory
-> keep page table in the main memory
    -> Page table base register (PTBR)
    -> Teffective  = 2Tmem
    -> Teffective  is not acceptable because we have to access memory 
    much.
Solution:
Use a special, small, fast lookup hardware, called translation lookaside buffer (TLB).
This is actually cache which is small so we store limited entries in it. If we do not find our page init then we go in main memory and then check because other are there.
So,
Typically contain 64_1024 entires
An entry is key value pair
Parallel search for key; on a hit, value is returned. If not found in cache then it is called as miss. 

(key, value) is (p,f) for paging
For a logical address. (p,d), TLB is searched for p. If an entry with a key p
is found, we have a hit and f is used to form the physical address. Else,
page table in the main memory is searched.


The TLB is loaded with the (p,f) pair so that future references to p are
found in the TLB, resulting in improved hit ratio.

Suppose in Round Robin when process quantum ends, then the process do context
switich and new process enter. Now change the TLB with new Page table key value.
*/


/*
Performance of paging:
Teffective on a hit = Tmem + T Tlb
Teffective on a miss = 2Tmem + T Tlb
If HR is hit ratio and MR is miss ratio then
Teffective  = HR (T Tlb  + Tmem) + MR (T Tlb + 2Tmem)


Tmem = 100 nsec ,,,, T tlb = 20nsec ,,,, Hit Ratio is 80% and MR is 20%
Teffective = ?
By converting 20 percent to dividing by 100
Teffective = 0.8 (20 + 100)  + 0.2 (20 + 2*100) = 140 nsec

*/