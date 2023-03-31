/*
Array size cannot be increase.
Because array is contiguous. When we initialize array with size 5 then it is given contiguous location in memory.
When we want to resize it, then it is not sure that next location is free or not in memory. It can be but not sure.
SO we use this technique.

int *p,*q;
int p = new int[5];
Want to increase to 10.
int q = new int[10];
for(int i=0; i<5; i++){
    q[i] = p[i];
}
delete[] p;
p = q;
q = null;


So this technique is use for array resizing.
*/

