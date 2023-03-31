/*
Page Replacement:
When page fault occurs, It can be because of 2 reasons:
1) Page is not its address space ==> Process trap and kernel terminate process
2) Page is in address space but not in memory ==> Allocate new frame and add new page in memory
Now what if memory frames are full with pages?
Here come page replacement.
-> If no free frame is available on a page fault, replace a page in memory to
load the desired page. This page selection can be local or global. 
Local means take the victim(page to be replace) within the current process address space.
Global means can take the victim(page to be replaced) from whole memory.
-> Page-fault service routine is modified to include page replacement.
-> Service routine do check that frame's page which is to be replaced is modified or not after coming in memory.
If not modified then put new page over that page. 
But if it is modified then call it as dirty and swap out it and swap in our page.

-> use "modify(dirty) bit" to reduce overhead of page transfers -- only modified
pages are written to disk (swap out). These pages are marked with "dirty bit".
    -> this bit is set by hardware when data is written to a page
    -> Checked by OS at page replacements either dirty or not.  
*/


/*
Page replacement algorithm:
-> Want lowest page-fault rate. So we use algorithms for it.
-> Evaluate algorithm by running it on a particular string of memory references (reference string)
and computing(calculating) the number of page faults for that string.
Reference String: is the string of pages which is used by the process during its whole execution.
It is obtained by adding each page as it is used by the process. So at the end we get the reference string.
Key Point: When the process start its execution then we pre add some of its pages which it must have to use
for starting its execution. So that less page fault occurs. Means give some frames in memory before starting
the process.
Theoretically above point is below:
-> For every CPU instruction set, (just to make sure that the process (which is running 
on that particular machine) we can gurantee its execution), we need  minimum number of no frames
which we discuss in next lecture.
-> As we would increase the number of frames to one process, then it would have large memory
so it would have more pages in memory so less page fault occurs. But in VM we cant give whole memory 
to 1 process but if give then page fault would be constant. But more frames will give less page fault
*/


/*
FIFO Algorithm:
It take victim most 1st entry of page came.
Number of frame allocated  = 4;
1,2,3,4,5,3,4,1,6,7,8,7
Assume local victim target. And no frame has page in the beginning.
So, process would have page fault for page 1, then for 2, 3,4.
--> 1,2,3,4
Now process is requesting for 5 but frames are full. then as we are using
FIFO then take victim which comes first.
So here take 1 as victim and replace with 5.
---> 5,2,3,4
now 3 which is available. 4 is also available. 1 is not now available.
then now 2 is remaining first come so take it as victim.
---> 5,1,3,4
now 6
---> 5,1,6,4
now 7
---> 5,1,6,7
now 8
---> 8,1,6,7
now 7
which is already in memory.

FIFO has 1 problem which would be in next lecture.
*/


/*
Optimal Algorithm:
-> take victim the page that will not be used for the longest period of time in reference string.
This is the most optimal algorithm, no any algorithm can give like this output. Equal can give but no more.
Its optimal.
Consider same assumptions as above with same reference string but with 4,5 page now:
1,2,3,4,5,3,4,1,6,7,8,7,4,5
Page fault for each and give ---> 1,2,3,4
now 5 not available
so check victim that which is coming late among 1,2,3,4, in reference string
It finds that 2 is not available or late in the given reference string so it take victim it.
---> 1,5,3,4
now 3 and then 4 and 1 which are available.
now 6 check victim in reference string from the current position which is 1 and finds above 1,5,3,4
It finds that 4 and 5 again using but 1 and 3 are late.
So here tie.. So use FIFO.
so take 1 as victim
---> 6,5,3,4
now 7 
--> 6,5,7,4
now 8
--> 8,5,7,4
now 7 available
now 4 and 5 also available.


But this is not practical. because its completely depends on the reference string then how we would get
reference string before running the process. So we use this algorithm for checking page faults so that we can check how much optimal we are going with.
*/

/*
Now came practical concept and algorithm which can be used. It more similar to FIFO but FIFO has 1 problem
which is not present in this.
-> Take victim that hasn't been used for the longest period of time.
-> it check references string backward so its practical.

Example:
-> no of frames  = 3
-> reference string:
7,0,1,2,0,3,0,4,2,3,0
page fault for each and we get
-> 7,0,1
now 2 so check which is less so here is 7
-> 2,0,1
now 0 so same
now 3 so check that which from available use last in reference string from current position and here take victim 1
--> 2,0,3
now 0 same
now 4
--> 4,0,3
now 2
--> 4,0,2
now 3
--> 4,3,2
now 0
--> 0,3,2

So that's how it works
*/



/*
LRU implementation:
    1) Counter based implementation
    2) Stack based implementation
Counter based implementation:
    -> Every page entry has a counter; every time page is referenced through
    this entry, copy the clock into the counter. Means take counter of when used.
    -> When a page needs to be replaced, choose the one with minimum counter value.

Stack Based Implementation:
    -> Keep a stack of page numbers. Whenever a page is referenced,
    remove it from its current location and push it onto the stack.
    The LRU page is at the bottom of the stack. because reuse are bringing at the top.
    -> Doubly-linked list implementation of stack requires 6 pointers changes.
Stack graphically:
reference string: 4,7,0,7,1,0,1,2,1,2(a),7(b),1,2
So start reading reference string from a or b depend which stack you wanna make
now come back. 1st value put at top.
Take example a
so 2
and then 1
and then again 2 so it also occur before so left it bacause it already most recent use
and then 1 same above pont
and then 0 
and then 7 
and then 0 so left 
and then 7 so left
and then 4

Similarly when we track back from 7 then
7,2,1 
and then again 2 left
and then 1 again left
and then 0
so add
so again 7,0,7 so left
and then add 4

NOTE: bottom of stack is LRU page which can take as victim
stack till a:                      stack till b:
2                                     7 // as again reference so put at top
1                                     2
0                                     1
7                                     0
4                                     4                     
*/