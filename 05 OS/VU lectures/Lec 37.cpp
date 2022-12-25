/*
-> Virtual Memory: A technique that allows a process to execute in the
main memory space which is smaller than the process size.
-> Only a part of a process needs to be loaded in the main memory for it
to execute.
-> Sharing of address space among several processes as we earlier do sharing
-> Efficient process creation --fork() and vfork() (cloning)
-> Memory mapped files -> How access the disk files into the memory
-> Support needed for virtual memory. 


Virtual memory can be implemented via:
1) Demand Paging
2) Demand segmentation

-- Basic Structure --
Virtual memory( includes pages )-> memory map (page table which contain frame) -> Physical memory -> Secondary Storage where from files comes into memory



Demand Paging:
Bring a page into memory only when it is needed
    -> Potentially less I/O needed
    -> Potentially less memory needed
    -> Faster response
    -> Higher degree of multiprogramming
When Page is needed => a reference is made to it.
3 cases can be:
    -> invalid reference => abort it
    -> Not in memory
        => page fault (when page is not available in memory then cause page fault)
        => bring page to memory
    After bringing, maybe there is no frame available in memory then 
    you can paste over the existing frame. or swap out and then swap in new one page
    -> No free frame => swapping (out and in)


Valid invalid bit (These are not those bits which we was discussing in address space. But they are in physical memory for the frame. if invalid then cause page fault)

-> With each page table entry a valid- invalid bit is associated (1 => in memory, 0 => not in memory)
-> initially valid- invalid bit is set to 0 for all entries.
-> During address translation, if valid- invalid bit in page table entry is 0=> page fault.


Example:
logical memory has index 0 to 7. 
But its address space allows it 6 files (0 to 5) only.
Page table would be made which has 3 files and others 0 to 7 make invalid.
Physical memory has files along with frame number.
Secondary Storage would also have these 3 files opened

problems can be:
If reference come for other than 3 files which are in page table then
if reference is within 0 to 5 then reference is valid but page not available so cause page fault.
In case reference is 6 or 7 then not page fault because its not a part of address space so abort call.

Page fault:
If there is ever a reference to a page, first reference will trap to OS => page fault
OS decides:
-> invalid reference => trap to OS
    => abort process
-> Just not in memory => page fault
   => service page fault by getting file into memory

Details:
-> Allocate an empty frame
-> Locate the desired page on disk
-> Swap in the desired page into the newly allocated frame.
-> Store the frame number in the appropriate page table entry
-> Reset tables; set valid/invalid bit to 1 
-> Restart instruction


Problems with restarting instructions that cause page faults:
    -> Auto increment/ decrement location
       ++ and -- can cause so we can make copy
    -> Block move => string move means string is in memory which is src which is to shift at dest and they are in same page. If src are overlapping with dest then can't restart. 
    What is overlapping? For Example, we shift 1 src to dest and the src and dest get overlap and the 2nd src is not in memory and it would cause page fault. So when restart our src would not be same. Thats problem

    Solution: 1- copy (done can be with micro code)
              2- For every string move do copy
              2- Here we can also check at micro code level that if they are overlapping then stop.


Performance of demand paging:
-> Page fault rate 0 <= p <= 1.0
 if p = 0 no page fault 
 if p = 1 every reference is a fault.


Effective Access Time (EAT)
EAT = (1 - p) * memory access + p (page fault service time)




Page fault service:
1) Trap to OS
2) Context Switch
3) Locate the vector for the given trap
4) Check that the page reference was legal and determine the location
of the desired page on the disk
5) Locate a free frame
6) Issue a disk read into this frame


Example:
Memory access time = 100   (original)
Page fault service time = 25 millisec
T effective = (1 - p) * 100 + p (25 milli)
            = (1 - p) * 100 + p (25000000)
            = 100 + 24999900*p
If one access out of 1000 causes a page fault, effective access time is
25 microseconds (high MAT when page fault come), a slowdown by a factor of 250.


Example:
If we want less than 10 percentage degradation in effective memory access
time then we have the following inequality ==> Means If we say that max we can
bear 10 percent of MAT more because of page fault.

Using previous values:
110 > 100 + 25000000 * p
10 > 25000000 * p
p < 0.0000006 where p is page fault (which is small)

This (if we allow 10%) means we can allow only 1 page fault every  2.500,000 (2.5M) memory references.

*/