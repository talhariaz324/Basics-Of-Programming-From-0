/*
Binary Search is used when we have the sorted and unique array. Binary Search is used to search the element by dividing the  lower index + higher index of the array
with the 2. SO the formula is l + h / 2


This formula gives us the mid of the array. We compare our key (which is to be find) with the mid. If greater than the mid then we do the formula from right else wise we
do the formula from left.
This is how we check the array.
*/

// Code:

#include <iostream>
using namespace std;
// Static array
struct ArrayS
{
public:
    int A[10];
    int size;
    int length;
};

void Display(ArrayS arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << endl;
    }
}

int bSearch(int arr[], int key)
{
    int l = 0, h = arr.length - 1, mid;
    mid = (l + h) / 2;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
}

// Using the Recursion for binary search but it would be a tail recursive means its better to use the loop instead of it

int bSearch(int arr[], int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            return bSearch(arr, mid + 1, h, key)
        }
        else
        {
            return bSearch(arr, l, mid - 1, key)
        }
    }
}

int main()
{
    struct ArrayS arr = {{1, 2, 3}, 10, 3}; // 10 size and 3 entries (length)
    Delete(&arr, 3);
    Display(arr);
}
