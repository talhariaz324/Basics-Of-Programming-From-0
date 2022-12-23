/*
1- Write formula of 2D array address where index starts from 1.
int A[m][n];
Addrs(intA[i][j]) = L + (i-1) * n + j-1;

2- int x[2][2] = {{1,2},{3,4}};
index are: 0, 1
 x+1 = ?
*(x+1) = ?
*(x+1) + 1 = ?
x+1 = address of row no 2 (index 1) base
*(x+1) = address of row no 2 (index 1) base same
*(x+1) + 1 = address of row no 2 + col no 2 (index 1) = 4 value address

For accessing value using airthmetic pointer we use double pointers
*(*(x+1) + 1) = gives 4

3- For multiplying A * B matirices which approach efficient:
Row major
col major

Answer: Both equal because both have same number of operations in their formula.


4- 3D array  find data type X[?][?][?]
find data type and l, m, n
where
int size = 2 bytes
float size = 4 bytes

t0 = i*1024
t1 = j*32
t2 = k*4
t3 = t0 + t1
t4 = t2+ t3
t5 X[t4]


Formula: L (base number) + [i*m*n + j*n + k] * w;
L + i*m*n*w + j*n*w + k*w
So if we see t2 then w = 4
if t1 then j * 32 where j*n*w so 32 is n*w = 32
n = 32/w(4) = 8
n=8

so for m
i*m*n*w = i*1024 as given
so m*n*w = 1024
 m = 1024/32(n*w) = 32
 m=32
 for l we cant find.
 because its not in formula but if options are given
 then only 1 would be remaining then it must be l

*/