/*
We access our 2D array using A[3][4];
But how this mapping done in the linear form in memory.
There are 2 ways of mapping:
1) Row major mapping
2) Column major mapping
*/

/*
Row major mapping:
int A[3][4]; m is representing row and n is representing column
now for changing some value we use:
A[1][2] = 10;
Address(A[1][2]) = 200 + [4+2] * 2 = 212 where 200 is base address of the
array. +  move 1 row and then add 2 columns and multiply by int size (assume 2 byte)

Address(A[2][3]) = 200 + [8+3] * 2 = 222
So general:
Address(A[i][j]) = L (base address) + [i*n + j] * w where n is total columns.
So, Compiler will always use the this formula to map the 2D elements in
linear form.


In case index start from 1 then
Address(A[i][j]) = L (base address) + [(i-1)*n + (j-1)]*w 
2 more operations, so C/Cpp use index 0 and with row formula
*/


/*
Column Major Mapping:
int A[3][4]; m is representing row and n is representing column
now for changing some value we use:
A[1][2] = 10;
Address(A[1][2]) = 200 + [(2*3) + 1] * 2 = 214 where 200 is base address of the
array. +  move 2 col and then add 1 row element and multiply by int size (assume 2 byte)

Address(A[2][3]) = 200 + [(3*3) + 1] * 2 = 220
So general:
Address(A[i][j]) = L (base address) + [j*m + i] * w where m is total rows.
So, Compiler will always use the this formula to map the 2D elements in
linear form for column major mapping.
*/

// NOTE: Both have same time, you can use anyone. Just a difference is that
// Row is left to right and Column is right to left