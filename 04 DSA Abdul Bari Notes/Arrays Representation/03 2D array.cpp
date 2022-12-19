/*
2D array is actually linear in memory.  
Suppose you do A[2][2] then it means 2 rows and 2 columns. But this would be linear in memory.
There are 3 ways to declare arrays.
1) int A[2][3] = {{1,2,3}, {1,2,3}};
This would be in stack.
2) Now lets make on heap
    int *A[2]; // Pointers array on stack which would be use as row
    A[0] = new int [3]; 
    A[1] = new int [3]; 
    A[2] = new int [3]; 

3) Now make all on heap 
int **A;
A = new int *[2];
 A[0] = new int [3]; 
 A[1] = new int [3]; 
 A[2] = new int [3]; 



 For Accessing them we use nested loop

 for(int i = 0; i < 2; i++) { // row
    for(int j = 0; j < 3; j++){ // column
        cout<<A[i][j]<<endl;
    }
 }


*/