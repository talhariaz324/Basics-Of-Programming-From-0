/*
I have to calculate the marks with condition that.
If marks are greater than the 38 then round them to divisable of 5. But without addition of more than 2.
I get the number and then apply +1 and +2 and then from modulus get the value if it is 0 and 5 then proceed.
But i dont know why did not work. My logic was also complex.
*/


/*
Question was that there are 2 trees apple and orange. There is also home between both trees. 
We have to tell which fruit is falling in the home area.
We are taking s is the starting point of home and t as a endpoint.
We are taking a is the apple falling point.
We are taking b is the orange falling point.
We are taking m is the total apple fall and n is the total orange fall.
ans is counter
Solution is:
if(a+apple[apple_i]>=s && a+apple[apple_i]<=t) ans++;
 cout<<ans<<endl;
 if(b+orange[orange_i]>=s && b+orange[orange_i]<=t) ans++;
 cout<<ans<<endl;
*/



/*
We have given starting point of kangroos x1 and x2 and the number of jumps which they did v1 and v2 respectively.
They are 2 Kangroos. We have to answer YES or NO either they meet or not at the same point after jumping from their starting point.
My Logic:
if x1<x2 then v1 should be greater than v2 to reach the same point.
Similarly,
if x2<x1 then v2 should be greater than v1 to reach the same point.

If above conditions are true then i am returning YES else NO.
But I missed 2 main points:
If above conditions are true then i also have to check either x1 and x2 are equal or not. It is the case that maybe they meet or not after above conditions.
If they x1 not equal to x2 then x1 = x1 + v1 and x2 = x2 + v2 and again check x1==x2 using loop for both above conditions for v. 
Second main case i missed is that maybe v1==v2 and x1==x2 then also return YES.
*/


/*
 I have no understanding of the question of what is factor.
 Question was:
    There will be two arrays of integers. Determine all integers that satisfy the following two conditions:
       1) The elements of the first array are all factors of the integer being considered    
       2) The integer being considered is a factor of all elements of the second array    
    NOTE: The integer to be considered is auto by the hackerRank.

 1st condition is that your first array every elements should be factor of integer which was considered. 
 Formula: i%a[j]!=0 ===> i is the integer considered,,, a is the 1st array and j is loop for go through all the elements of a array.
 2nd condition is that integer being considered should be factor of all the elements of b array
 Formula: b[j]%i!=0

 Turning point: We can take factor by modulus and it should be equal to 0.
 jis k factor laina hota ha uss ko pehlay modulus operator sa and 2nd baad ma.
 1st ma i of ha to  u  ss ko pehlay
 2nd ma elements of hain to wo pehlay.
*/


/*
Problem is that we have scores corresponding to each game.
We have to find how many times score is greater than the previous greater score and how many times score is less than the previous less score.
Its simple. just loop and if conditions
if(scoreMin > scores[i]){
        min++;
        scoreMin = scores[i];
    }else if (scoreHigh < scores[i]) {
    max++;
    scoreHigh = scores[i];
*/


/*
Problem: (SubArray Division)
Two children, Lily and Ron, want to share a chocolate bar. Each of the squares has an integer on it.

Lily decides to share a contiguous segment of the bar selected such that:

The length of the segment matches Ron's birth month, and,
The sum of the integers on the squares is equal to his birth day.
Determine how many ways she can divide the chocolate.

for (int i = 0; i<n; ++i) 
    {
        int s = 0;
        for (int j = 0; j<m; ++j)
            s += squares[i+j];
        if (s==d)
            ans++;
    }

Turning point is that i was unable to justify loops conditions.
Otherwise Concept was in mind.

*/


/*
Array is given... I have to calculate the sum of each index with all next.
loops:
for(int i = 0; i<n; i++){
    for(int j = i+1; j < n; j++){
        int sum = 0;
        sum = ar[i] + ar[j];
    if(sum % k == 0){
        count++;
        
    }
    }
}
Then check each sum with divisor given that its == 0  or not. use mod.


Turning point: I was also checking the all the index sum with the current index in inner loop. But we have to check forward only from
the current index. so we change the value of the inner loop j from 1 or 0  to i+1
*/


/*
Migratory Birds:
Given an array of bird sightings where every element represents a bird type id, determine the id of the most frequently sighted type.
If more than 1 type has been spotted that maximum amount, return the smallest of their ids.

I have done with logic of returning the most repeated value in array, and also if same then their lowest.
But in 2 cases i get fail because of timeout. Logic is true but more time consuming.
We can fix it after DSA.
*/


/*
I have to tell the developer day which is on the 256th day of the year.
I have understand the problem but i did not apply all the checks after understanding. So some test cases failed.
After applying all checks, its done.

*/


/*
I have to sum array elements simply:
sum += arr[i]; // for example: [2,3,4] ==> 2 + 3 + 4  means.
*/


/*
Drawing Books problem:

p is the destination page
n is total pages.
1st page always starts from right. and every page has both sides except last page. so we apply this formula to get.

After observing we conculde that dividing by 2 gives no of pages that should turn.

p/2 gives number of pages that we have to turn to reach p from start of the book
n/2 - p/2 is the number of pages we have to turn to reach p from end of the book
*/