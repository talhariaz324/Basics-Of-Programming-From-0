/*
Search in array are of 2 types:
1) Linear Search
2) Binary Search
Linear Search is to search for element by traversing each element in array.
If found then return index else return -1.
The element which is to be search is known as key.
If find then known as successful else unsuccessful.
*/

/*
Can we improve the linear search?
Ok.. suppose if you want to search something then at first time it would take
more time. But if you again search for the same thing then you know where it is and find it in less time
than the previous time.
Same case here. If we search for some element. Then if we search for the same element the it should take less time
as compared to before.
For this we use 2 techniques:
1) Transposition ==> If the key found then swap it with i-1 means previous one. and if again search then again do this. That's how for each search and onFinding we are improving time. 
2) Move to Front/Head  ===> If the key found then swap it with index 0. Simple. On the next search it would find in constant time.
*/

#include <iostream>
using namespace std;
// Static array 
struct ArrayS {
    public:
 int A[10];
 int size;
 int length;

};



int LinearSearch( ArrayS arr, int key) { // Here not passing with reference because here we are not goona make changes
    for(int i = 0; i < arr.length; i++){
        if(key == arr.A[i]){
            return i;
        }
    }
    return -1;
    /*
    Time complexity is: Best O(1) // finds at first index
                        Worst O(n) // have to traverse n elements if element is at the end or not find
                        Average: is difficult to get because it take more analysis than the worst case. 
                        But its formula is add each case and divide by the total number of cases.
                        Here is, 1+2+3...n/n (1-> search at once, 2-> for second index and so on to n)
                                 n(n+1)/2/n (1+2+3...n === n(n+1)/2)
                                 = n+1/2 (as n cut the above n)
                                 = O(n)
                        As it sometimes difficult to do analysis for each case for average we mostly do worst case because most of time
                        average case is equal to worst case.
    */
}


// Improved Linear Search
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearchModifications( ArrayS *arr, int key) {  // Here as we have to do swap in array (changing)
    for(int i = 0; i < arr->length; i++){
        if(key == arr->A[i]){
            swap(&arr->A[i], &arr->A[i-1]); // For move to front just change i-1 to 0
            // swap(&arr->A[i], &arr->A[0]); // For move to front just change i-1 to 0
            return i; 
        }
    }
    return -1;
}



void Display( ArrayS arr) {
    for(int i = 0; i < arr.length; i++){
        cout<<arr.A[i]<<endl;
    }
}

int main() {
struct ArrayS arr = {{1,2,3},10, 3}; // 10 size and 3 entries (length)
// cout<<"Index is "<<LinearSearch(&arr,2)<<endl;
cout<<"Index is "<<LinearSearchModifications(&arr,2)<<endl;
Display(arr);
}
