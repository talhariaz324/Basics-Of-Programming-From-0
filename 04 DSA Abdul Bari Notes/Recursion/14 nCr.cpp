/*
nCr = n!/n!(n-r)!
This is combination formula. Means How many
combinations can be made with the given set.
Combination should contain always different
character.
int C (int n , int r){
    int  t1, t2, t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n-r);
    return t1/(t2-t3);
}

How can we convert it into recursion?
We can use the pascal triangle for it.
7:19 Abdul Bari Recursion folder and nCr video see for pascal triangle.

This triangle shows when r==0 and n==r then 1 and else use n-1Cr-1 and n-1Cr

So, int C(int n, int r){
    if(r==0 || n==r){
        return 1;
    }
    return c(n-1,r-1)+C(n-1,r);
}

*/