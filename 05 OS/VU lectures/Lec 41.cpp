/*
We discussed thrashing in the last lecture and now how can we prevent it.
-> To stop thrashing, the degree of multiprogramming needs to be reduced.
Means we have to enter less processes in the main memory.
-> Local (within its scope) page replacement prevents thrashing to spread among several
processes.
-> However, a thrashing process consumes more resources.
*/

/*
Locality of Reference:
Why does paging work? Paging is to get those pages into memory from logical address space
which are actually needed.
Locality of Reference model:
. The set of pages a process accesses actively, is known as its locality.
. Process migrates from one locality to another which is known as moving locality.
. Localities may overlap (means previous locality page may be in the moved locality).


Suppose locality is of 10,000 ---- then it may be the case process maybe accessing only 15 pages in this locality.
*/

/*
Working Set Model
. Working set window (delta sign)
    - A fixed number of page references, e.g; 10,000 references.
. Working set size of Process small i (WSS with small i)
    - Total number of pages referenced in the most recent delta (work set window)


Let delta = 10 references
page reference table
... 2,3,4,5,6,,7,6,5,7,8,4,2,3,2,4,3,5,4,6,,7,5,4,6,5,7,8,6,7,4,5,3,4,2,3...
          ---------------------                     -------------------
              delta no 1                                  delta no 2
So in the first WS(t1) = {5,6,8}                   WS(t2) = {6,7}
So in 10 references of delta in no 1 it access 3 pages and in second access 2 pages.

Locality maybe not in sequence like maybe L1 = 1 to 3 and 6 to 8 (so something in 1 to 3 reference (any page within) make the locality to move to 6 to 7 reference to access some page)

----
. if delta is too small, it will not encompass an entire locality
. if delta is too large, it will encompass several localities
. if delta is infinity, will encompass entire program.
So delta should be to have 1 locality


If D is the total demand of frames in the system, then D = ∑ WSS
If m is the total number of frames in the system, then D > m ==> leads to thrashing
Policy: If D > m then suspend one of the processes so that others can get their frames.


Keeping track of the working set:
- Approximation with a fixed interval timer and a reference bit.
Example:  delta = 10,000 references
. Timer interrupts every 5000 references.
. Keep in memory 2 bits for each page.
. If the delta reference some page then set its bit to 1.
. Whenever a timer interrupts, copy all reference bits and set their values to 0
. After delta reference, if one of the bits for any page either in copied references or in delta actual references = 1 => page is in the working set in previous delta reference.

But its not completely accurate. Because suppose some page refer  at start its value set to 1 and after 5,000 interrupt and generate copy with setting 0 bits. so next 5000 no reference is using it so it seems it is not in delta but it is, so just taking space so,
Improvement: Use 10 reference buts and interrupt every 1000 references.
*/ 


/*
Page Fault Frequency:
. Another method to control thrashing.
. Os keeps track of the upper and lower bounds on the page-fault rates of processes.
. If page-fault rate falls below the lower limit, the processes loses frames. If page-fault
rate goes above the upper limit, the process gains frames.
*/

/*
Other Considerations:
pre paging --> adds pages which inital need the process at start
page size selection max and min page size has their own pros and cons
    . Internal fragmentation (less fragmentation would be if min page size)
    . Page table size (page table size more with with min page size) 
        . min page size has more page fault
    . locality (also depends on page size)
    . IO overhead (if page is large and u have to get small piece of that in memory)
        . Reduced with small page size because locality improves
*/

/*
Program Structure:
if A[1024][1024]
. data store in row (linearly) in memory
. when we access it in column then it would do page fault 1024*1024 because for each column it would go for all rows.
. So we should initialize row 1st and the column. Then it access 1st row and do page fault to go in 2nd row. similar continues. so here 1024 times page fault.

So access data as it is in memory make performance better.
*/