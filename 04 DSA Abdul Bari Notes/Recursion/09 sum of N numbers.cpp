/*
Recursion is very simple from the mathematical point of view. Let's take example of the sum of N (naturals) numbers
For Example:
we have numbers:  sum(n) = 1, 2, 3, .... + n
so we can write in this way:  sum(n) = 1, 2, 3, .... (n - 1) + n
AND  sum(n) = 1, 2, 3, .... (n - 1) can be write sum(n -1)
so in simple way can be write as sum(n) =  sum(n - 1) + n
SO
sum (n) = sum(n -1) + n
The above formula is for the large number of naturals but while making this mathematical we should consider both large case and small case as well.
Here large case is upto n which formula is at line no 9
Here small case is number 0 so it is not in natural number so no formula, we can give it fix answer. here is answer is 0
NOTE: small case most of the time has the fix answer
We can concise mathematically:
sum(n) =
{
 0                          n===0
 sum(n -1) + n              n > 0                      
}
*/

/*   
int sum(int n){
    if(n == 0){
        return 0;   
    }else {
        return  sum(n -1) + n;
    }
}

Tracing:
                            While returning
sum(5) ==> sum(4) + 5 -----> 10 + 5 = 15
sum(4) ==> sum(3) + 4 ----> 6 + 4 = 10
sum(3) ==> sum(2) + 3 -----> 3 + 3 = 6
sum(2) ==> sum(1) + 2 -----> 1 + 2 = 3
sum(1) ==> sum(0) + 1  ---> 0 + 1 = 1
sum(0) ==> return 0

*/


/*
Using for loop solving sum of n numbers:
In loops we have to devise the logic and then implement it but in recursion its easy,
int sum(int n){
int sum;
for(int i = 0; i < n; i++){
    sum = sum  + i;
}
return sum;
}

*/


/*
We can also may have direct function which can calculate the sum of natural numbers,
Like for the sum of N numbers: n(n + 1)/ 2
int sum(n){
    return n * (n + 1) /2;
}
*/ 


/*
Let's discuss the time and space complexity:
FOR RECURSION:
It will make n+1 calls for the function. SO O(n)
It will make n+1 activation records and so O(n)
SO its easy but space complexity more.

FOR LOOP:
It will enter loop n + 1 and execute formula n times so 2n + 1 . SO O(n)
It will make space for n,i, sum so, less than recursion


FOR DIRECT:
Just operations so we can say O(1).
because fix operation is to be done.
Space for only n variable.

*/
