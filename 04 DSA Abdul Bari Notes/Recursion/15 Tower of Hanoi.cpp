/*
Tower of Hanoi is the problem in which we have 3 towers.
A B and C.
A has 3 disks in order from small disk to large disk from upper to bottom.
Now, We have to move the each disk from A to C tower. But with 2 conditions.
1) At one time shift 1 disk
2) Smaller size disk should be upper to the larger size disk. Mean small , its large and then its large from up to bottom.
*/

/*
Solution:
A tower is source, B is using, C is destination.
Break the problem.
=> Consider 1 disk
So,
Move Disk from A to C (Simple)

=> Consider 2 disk
1- TOH(1,A,C,B) // Call func in which 1st argue show no of disk. 2nd argue show source. 3rd using, and 4th show destination
2- Move disk from A to C
3- TOH(1,B,A,C)

=> Consider 3 disks
1- TOH(2,A,C,B)
2- Move disk from A to C
3- TOH(2,B,A,C)
NOTE: These 2 disks are moving one by one by using above method of shifting.


General:
1- TOH(n-1,A,C,B);
2- Move disk from A to C
3- TOH(n-1,B,A,C);
*/


/*
void TOH(int n, int A, int B, int C){
    if(n>0){
        TOH(n-1,A,C,B);
        cout<<"From %d to %d"<<A<<C;
        TOH(n-1,B,A,C)
    }
}

Time O(2^n)
*/