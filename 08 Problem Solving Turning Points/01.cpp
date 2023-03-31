// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;


// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
//     long long a[5];
//     long long sum = 0;
//     for(int i = 0; i < 5; i++){
//         cin >> a[i];
//         sum += a[i];
//     }
    
//     sort(a, a+5);
//     cout << sum - a[4] << " " << sum - a[0] << endl;
//     return 0;
// }


/*Problem is that i have to check positive and negative and zero numbers in the array. THen divide the total positive numbers
with the size of array. same for remaining. But turning point was that i have to show decimal numbers after point till 6

For Example: 0.333333


After my logic,,, Just apply the typecasting into float. Float shows 7 digits including point before value. so we get 6 numbers
after point.
*/


/*
If we put 6 then output should be this. left side space acc to given val. and then increment of # with filling space.
      #
     ##
    ###
   ####
  #####
 ######


We need to loops. 1 is for all 6 times. Second is adding space and adding # in each space.
Execute 2nd loop as it is condition as for outer as we need to iterate similar times for space and #.
Logic is that in inner loop has check that which calculates how many left and which add.


for(int i=0; i<n; i++)      
    {
        for(int j=0; j<n; j++)
        {
            if(j<n-i-1) // check 6-0-1 = 5
                cout << " ";
            else
                cout << "#";
        }
        cout << std::endl;
    }

*/





/*
Absolute difference of the diagnols of square matrix.
Read input from STDIN. Print output to STDOUT in n
int a[n][n]
for(i=0;i<n;i++)
        d1+=a[i][i];
for(i=n-1,j=0;i>=0&&;j<ni--,j++)
            d2+=a[j][i];
       cout<<abs(d1-d2);
*/




/*
I have to calculate the given array min sum and max sum.
I just go and write plenty of code. Instead the solution is just use sort function for header file.
Get Total sum of all array elements.
Smallest value will be the total sum - last value of sorted array
Max value will be the total sum - first value of sorted array.


e.g;
[2,4,1]
[1,2,4]
1+2+4 = 7

7-4 = 3
7-1 = 6
*/



/*
Tallest candle will blow off first. Tell how much candles will blow off. 
Solution
Candles array is given and in which i have to get maximum and count it how many times it occur in array and then return that concurrance.
I use sort and then get last index val which is absolutely large after sorting, but this is fail in some test cases
So,
solution was that simply get max by using func and then use the counter.
*/



/*
convert the 12 hour format to 24 hour format,
Turning point is that AM and PM ma sirf hours e change hogay
aur iss k lia check laga lia agr temp ma A ha then go with this otherwise add +!2
and what is temp.
We are ending our char array on index 2 by adding /0 null. 
Using temp after hour for colon  mint array for colon, sec for Am and PM. 
This temp helps us to AM or PM.
*/