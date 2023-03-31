/*
Sync Hardware:

Normally, access to a memory location excludes other accesses to that
same location. Means one process can access a memory location ,,, other processes can't at that time.

Extension: Designer have proposed machine instructions that perform 2 operations
atomically (indivisibly) on the same memory location.
For Example: Read and write.

Note: Atomically means that one process doing both things. by using true and false,

The execution if such an instruction is also mutually exclusive (even on microprocessor)

They can be used to provide mutual exclusion but other mechanisms are needed to satisfy the other 2 requirements of a good 
solution to the CS problem.
*/ 



/*
TSL instruction (test and set)

boolean TestAndSet (boolean &target){
    boolean rv = target;
    target = true;
    return rv;
}

-> Lock is set to false and its a global variable and access by the other processes as well.
do{
    while(TestAndSet(lock)){ // Only go inside when lock is false. if some process is in cs then it make the lock to true so the while condition will remain true 
        CS
        lock  = true;
    }
    lock = false;
        Remainder Section
}


Solution good? NO
Mutual Exclusion: Satisfied
Progress: Satisfed
Bounds-waiting: Not satisfying
because after process complete it CS it may go  entry section and then again enter CS.
*/

// Using Swap
/*
void swap (boolean &a, boolean &b){
    boolean temp = a;
    a = b;
    b = temp;
}
key is local and set to false.
do{
    key = true; // 1st process come and its key true
    while(key == true ){ // if key is true
        swap(lock, key); // make swap,,, now swap make the lock true and the other processes not allowed to enter CS
        CS
    }
    lock = false;
        Remainder section
}


Solution good? NO 
Mutual Exclusion: Satisfied
Progress: Satisfed
Bounds-waiting: Not satisfying
because after process complete it CS it may go  entry section and then again enter CS.

*/