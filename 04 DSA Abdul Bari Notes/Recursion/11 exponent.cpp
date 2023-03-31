/*
Exponent is:
2^4 = 2 * 2 * 2 * 2
m ^ n = m * m * m * m .... *n 
so pow(m,n) =  m * m * m * (n-1) .... *n 
so pow(m,n) =  pow(m , n-1) * n 

so 1                 n==0
 pow(m , n-1) * n   n>0
*/

/*
int pow(int m, int n){
    if(n==0){
        return 1;
    }
    return pow(m, n-1) * n;
}

This will make n+1 calls and also take space of activation records n+1.
*/

/*
But is there any method by which we can reduce its number of calls for getting the same answer.
Yes.
2^4
(2^2)^2
similarly for odd
2^9
2*(2^2)^4
SO for m and n
1) (m*m)^n/2
2) m * (m*m)^n-1/2


So,
int power1(int m,int n)
{
 if(n==0)
 return 1;
 if(n%2==0)
    return power1(m*m,n/2);
 return m * power1(m*m,(n-1)/2);
}
*/