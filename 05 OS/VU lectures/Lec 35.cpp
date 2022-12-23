/*
Reentrant (read only) code pages of a process address space can be shared.

Shared code (number in the physical address space) appears in the same logical address space of all processes.

Example:
Multiple invocations(requests) of pico or gcc. (compilers)

Concluded:
Assume 2 processes p1 and p2. They have ed 1 code and ed 2 code.
ed 1 has same code in both processes then physical memory will not have 2
copies. It will only 1 in memory and the frame number of the code will be same
in both processes for ed 1.
*/


/*
Segmentation:
A memory management scheme that supports programmer's view of memory.

A segment is a logical unit such as; main program, procedure, function,
method, object, global variables, stack, symbol table.

A program is a collection of segments.

So, in program stack, global variables etc each would be treated as segment.

Segments are of different sizes. So it would be in memory at different places
so it may have holes in it which we face in MVT.


Segments Table is a table which have limit and base (where from segment start)

Logical address consists of a 2 tuple:
1) segment-number 2) offset

Segment table -- maps two-dimensional logical addresses to physical addresses.

Each segment table entry has:
base -- contains the starting physical address where the segment resides in memory.
limit -- specifies the length of the segment.


Segment-table base register (STBR) points to the segment table's location (where from segment start in memory.)
Segment-table length register (STLR) indicates number of segments used by a program
Segment number s is legal if s < STLR
else illegal and then trap.

Hardware support:
CPU ->(check s is legal or not. and check offset is within limit or not) s,d -> segment table (limit, base) -> d + base -> physical address
*/

/*
Segmentation Architecture:
Relocation:
    -> Dynamic means we can relocate the segment within the memory
    -> By segment table because it give base of that segment
Sharing
    -> Shared segments
    -> Same segment number in both processes


So, Dynamic storage Allocation (for doing compaction to avoid holes) can be done:
First fit
Best fit 
Worst fit (large space and process is small so it will left more holes)

External fragmentation
*/

/*
Protection: Bits are associated for this purpose with each entry in segment
purpose with each entry in segment table:
    -> validation bit = 0 => illegal segment
    -> Read, write, execute bits
Same as in page table when accessing segment in segment table which is not available or 
doing execution of segment which is readable.

When need?
Suppose CPU allows to read at most 16 segments to read by each process.
Then if small process come and it has only 5 segments, then remaining 11 space
is free in segment table, so when process try to access these segments which are
not part of the process so we make them invalid.
So whenever this case so due to this invalid process will generate trap and give error.
*/

/*
Example: 40 mint
*/

/*
Sharing of segment:
-> Segment at the segment level and not at the fixed-size page level
-> Sharing at the code or data level
-> in sharing, Segment table of multiple processes point to the same segment.
*/

/*
Issues with segmentation:
External Fragmentation:
Total memory space exists to satisfy a space for new allocation request for a segment, but memory space is not contiguous.

-> Reduce external fragmentation by compaction
    => Shuffle segments to place free memory together in one block
    => Compaction is possible only if relocation is dynamic, and is done
    at execution time.

Issues:
I/O problem
    Latch (catch) job in memory while it is involved in I/O
    Do I/O only into OS buffers
Very large segments => then you hve to do page program segments -- paged segmentation
*/