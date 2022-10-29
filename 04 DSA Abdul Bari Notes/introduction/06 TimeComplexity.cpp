/*
What is Time Complexity?
In real life, when we do some work then we need some time to do that work.
Now we are taking our work from the machine.
Machine will also take the time.
Now what time?
This calculation is called as the time complexity.
*/


// Taking different scenarios for the time complexity.

/*
01:
We have array: [0,1,2,3,4,5,6,7,8,9]
Now we have to search 7. Then program will go through all the elements until it finds the 7. So the worst case can be it never find 7.
So in worst case, it will run n times. where n is the number of elements. it can be infinite.
So the time complexity in worst case is: n
But in time complexity we write it as: O(n)
O is known as order OR degree 
so O(n) is read as degree of n.
There are some also terms which we use to show time complexity which are:
BigO, Omega and theta. But we discuss them in the last of this course.

Also we can check with the help of code:
for(int i = 0; i < n; i++){
    
}

One loop so we can say its time complexity will be O(n). But its not always true we must have to check the condition of loop etc.



Space Complexity:
The space which the program is taking in the memory during its execution.
here we are not concern with how many bytes but we have to check how many n will be in memory, If n increases then space increase if n decreases then space decrease.

In this case space Complexity is n because problem size is n
O(n)


*/


// NOTE: Before continue want to mention that we can get the time complexity by analysis of the procedure/ logic we are opting. We can also get it by code.



/*
02:
We have array: [0,1,2,3,4,5,6,7,8,9]
Now we take each element of the array and then compare it with all the elements in the array.
Now, getting each element of the array is: n
Comparing with all the elements in the array is: n
So, n * n = N^2
Code:
for(int i = 0; i < n; i++){ // n
    for(int j = 0; j < n; j++){ // n
       Code
    }
}

Two loops so we can say its time complexity will be O(n^2). But its not always true we must have to check the condition of loop etc.


*/


/*
03:
We have array: [0,1,2,3,4,5,6,7,8,9]
We have to take each element of the array and compare them with remaining elements in the array.
For example: I take 1 then compare with rest of elements. if i take 2 then compare with rest of next elements not before elements.
So we are seeing that formula will be:
                                            n-1,+ n-2,+ n-3,+...+ 4+3+2+1 ====> Means value starts from n-1 and continuously skipping elements so at the end have 1.
                                            This formula: n(n-1)/2 ==> n^2-n/2 ===> In this polynomial is n^2 so:
                                O(n^2)
Code:
for(int i = 0; i < n; i++){ 
    for(int j = i+1; j < n; j++){ 
       Code
    }
}

Two loops so we can say its time complexity will be O(n^2). But its not always true we must have to check the condition of loop etc.
*/



/*
04:
We have array: [0,1,2,3,4,5,6,7,8,9]
This time, we want the middle of the array and then its middle and then again its middle until we reach 1.
Here is for example: 4
its half: 2
its half: 1
Now reach 1 so stop.

In this case when we successively dividing by 2 then its time complexity measure in log.
Here log2n where 2 is the base. n is the total size. 2 also shows we are dividing by 2.
So time complexity will be: O(log n) we skip base while writing log in O.

Code:
for(int i = n; i > 1; i=i/2){ 
  Code
}

Here we have the 1 loop but here time complexity is not O(n) because loop inside condition make it different so that's why we do analyze thoroughly the code.
Time complexity: O(log n)
*/

// NOTE:  Here we see the 4 cases, Analyze the time complexity by process/work/logic is better.


/*
Till now we discuss the structure of array.
Lets have a look on the other structures.

LinkedList: is also a list like array. But its in heap. Which does not matter here. So remain same as array.



Space complexity of linked list with the n data as array.
here size is n.
But we need pointers for each element also.
So, 2 * n
Degree will remain: O(n)  because we consider polynomial not constant and base etc.
*/


/*
Matrix:

1 2 6 3
2 3 2 2
3 4 2 1
4 5 2 6


Here we have the structure of matrix. 
Matrix is 4*4 
It can be n so, n * n
Degree is: O(n^2)

But what if want to just read row then: O(n)
But what if want to just read column then also: O(n)


Code:
for(int i = 0; i < n; i++){ // n
    for(int j = 0; j < n; j++){ // n
       Code
    }
}

In case we call some function inside the inner loop. That function also have loop then its time complexity will be O(n^3) but if function have 1 or 2 statements only
then it will remain: O(n^2)




Space Complexity:
O(n^2)

*/


/*
Next structure is Array of LinkedList.
Means array has the head pointer to the linkedLists.
Array you can say m
LinkedList you can say n
Then their time complexity will be O(m+n) in case you consider array and linked lists both
If you dont want to consider array and go for linked list only then O(n)

What do you mean by considering ?
It means you are using code but dont want to add in time complexity.
So this is considering or not.





Space Complexity:
O(m+n)
*/


/*
Next structure is tree:
In tree structure we have:
                              A
                            /  \ 
                           B    C
                          / \  / \
                         D   E F  G

    In this tree, if we analyze from bottom then its getting divide by 2.
    Its time complexity is: log2n 
    Its degree is: O(log n)

    But if want to read all the elements of the tree then its degree is: O(n)






Space Complexity:
O(n) // Because total elements in memory will be n

*/


