/*
3rd Dimension: int A[d1][d2][d3];
Row based (left to right):
Address(A[i1][i2][i3]) = L (base number) + [i1*d2*d3 + i2*d3 + i3] * w;
Explain:
base number + index no 1 * remaining dimensions of actual array + index no 2 * remaining dimensions  + index no 3 * remaining dimensions 

Column based (right to left):
Address(A[i1][i2][i3]) = L (base number) + [i3*d1*d2 + i2*d1 + i1] * w;
*/


/*
int A[d1][d2][d3][d4];
Row based (left to right):
Address(A[i1][i2][i3][i4]) = L (base number) + [i1*d2*d3*d4 + i2*d3*d4 + i3*d4 + i4] * w;
        FOR n?
        = L (base number) + Σ^n below is p=1 base is [ip* π^n below is q=p+1 base is dq ] * w 


Column based:
Address(A[i1][i2][i3][i4]) = L (base number) + [i4*d1*d2*d3 + i3*d1*d2 + i2*d1 + i1] * w

*/

/*
Time Complexity:
Address(A[i1][i2][i3][i4]) = L (base number) + [i1*d2*d3*d4 + i2*d3*d4 + i3*d4 + i4] * w;
        Multiplication  is:                          3           2          1


        So, 4D --> 3 + 2 + 1
            5D --> 4 + 3 + 2 + 1
            nD --> n-1 + n-2 +...+ 3 + 2 + 1  = n(n-1)/2
            So O(n^2)
But this is too much time.
How can we reduce?
We can reduce the multiplications by using Horner's Rule which is about common
1st reverse  bracket which is: i1*d2*d3*d4 + i2*d3*d4 + i3*d4 + i4
 = i4 + i3*d4 + i2*d3*d4 + i1*d2*d3*d4
 = i4 + d4* [i3 + i2*d3 + i1*d2*d3]
 = i4 + d4* [i3 + d3 * [i2 + i1*d2]]
          1           1         1 = 3
          So, 4D = 3
              5D = 4
              nD = n-1
              O(n)
So release from n^2 to n  
*/ 