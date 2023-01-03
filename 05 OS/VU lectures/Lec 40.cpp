/*
Belady's Anomaly:
For some page replacement algorithms, the page fault rate may increase as the
number of allocated frames increases.

As we discussed earlier that when memory increases then page fault rate get low.
But Some algos make it false by increasing the page fault with memory. This anomaly
is known Belady's Anomaly.
FIFO algorithm is one of them that cause this things
*/

/*
Solution:
Stack Replacement Algorithnms:
A class of page replacement algorithms with the following property:
    Set of pages in the main memory with n frames is a subset(part)
    of the set of pages(all other pages required for particular process) that would be in memory with n+1 frames.

Do not suffer from Belady's Anomaly.
Example: LRU
*/

/*
LRU Approximation Algorithm:  (Its a method to implement the LRU. Actually approximation of LRU).
-> Use of reference bit
    With each page associate a bit, initially = 0
    Whenever page is referenced bit set to 1.
    Whenever we have to choose victim then we choose whose bit is 0 as tell below.
    Replace the one which is 0 (if one exists). We do not know the order, however.
    What if more than 1 pages exists with 0. Then we go with FIFO.
     
*/


/*
Depending on the frequency of pages use, we choose victim such algos are frequency based:

Least Frequently Used Algo:
- LFU
- We have reference count bit with each page in page table. Whenever page is referenced we increase bit.
- Replace the page with the smallest reference count.  
Before learning How works, we have to learn about locality of reference.
For Example: We have process with 10,000 memory references. Then process refer for some page within memory references. 
So to whom process refer is known as locality of references. So, That process refering page in memory references is locality of references.
This locality moves. Mean when executed 1 page then next so moving.
So, with moving the process refer to page get different because locality moving.
2 types of locality:
1) Spatial Locality --> nearby instructions to recently executed instruction are likely to be executed soon..
2) Temporal Locality --> a recently executed instruction is likely to be executed again very soon.

 Based on locality of reference concept, we say least frequently used page is
 not in the current locality. So choose it as victim.
NOTE: if not in current locality then we do not use it as victim because then we need it.







Most Frequently Used:
In this algorithm replaces the page which is most frequently used.
It is in locality so choose as victim.
*/


/*
Page Buffering Algorithm:
Os may keep a pool of free frames:
    -> A process in need can be given a frame quickly
    -> Victims are selected and free frames are added to the pool in the background
    by the OS. SO OS handles in the background by keeping eye on the pages of processes and select victims.

Os may keep a list of modified pages:
    In the background, the modified (dirty) pages are written to disk.
    Then small number of dirty pages in the system (because OS already send dirty pages after modified to disk) at the time of page replacement
    Then at victim selection, we have more pages which are not dirty so which is main purpose of algorithm.

*/


/*
Local VS Global Replacement:
If Process P generates a page fault
    Select for replacement one of its frames (Local) less page fault so fair  but use more resources.
    Select for replacement a frame from a process with lower priority number (Global) page fault service time less but More page fault .
*/

/*
Allocation of frames:
Each process needs min number of frames so that its execution must be guaranteed on a given machine.
Example: MOV X,Y 
where X is destination and Y is source.
2 bytes for MOV
2 bytes for X
2 bytes for Y 
So total 6 bytes and 16 bits.

Now question is that. In worst case X 1 bit is in the last of some page. and 2nd bit is at start of some page
Same goes for Y. Then How many frames should u need for its execution?

Solution: We need 2 frames to store instruction itself in memory in worst case because 5 are in one page and remaining one is another page.
X also needs 2 frames
Y also needs 2 frames
So we need min 6 frames for successfully execution without any page fault. If less that 6 then cause page fault and get into loop in worst case. Because to whom we choose victim? If itself take then next time it would not be available.


3 Major Allocation schemes:
1) Fixed Allocation
    Free Frames are equally divided among processes and if some left then send to OS which use for the process when some process need it.
2) Proportional Allocation:
Number of frames allocated to a process is proportional to its size. More size more frames.
3) Priority Allocation:
Priority based proportional allocation.
*/


/*
Thrashing:
If a process does not have  "enough" pages, the page-fault rate is very high.
This leads to:
- Low CPU utilization and more Disk Usage
- Operating system thinks that it needs to increase the degree of multiprogramming because CPU is free.
- And OS adds  more processes which cause more  page fault and again OS think and continoues.
- Serious Problem


A process is thrashing ig it is spending more time paging (swap in and out) then executing

Thrashing results in severe performance problems:
Low CPU utilization
High disk utilization
Low utilization of other I/O devices


To stop thrashing, the degree if multiprogramming needs to be reduced.
Local page replacement prevents thrashing to spread among several processes.
However, a thrashing process consumes more resources.
*/