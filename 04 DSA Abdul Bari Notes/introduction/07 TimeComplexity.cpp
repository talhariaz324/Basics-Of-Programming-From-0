// Checking the time complexity of the program through the code.

/*
NOTE:  We assume 1 unit time for each operation/statement.
1 unit time ==>  time k 1 unit.
void swap(x, y)
{
    int  t;  // we mostly do not consider declare 
    t = x; ===> 1 unit time
    x = y; ===> 1 unit time
    y = t; ===> 1 unit time
}

TOTAL: 1 + 1 + 1 = 3 unit time
constant has n with degree is 0.
polynomial with degree 0 is 1
So 3n0 is 1
Order O(1); // Constant
*/




/*
int sum(int A[], int n)
{
    int s,i;
    s = 0; ==> 1
    for (i = 0; i < n; i++){ ==> 1 + n+1 + n =2(n+1) But most author say you just have to take condition time which is n+1 (+1 of false) here. 
        s = s + A[i]; ===> n (loop for n times run)
    }
    return s; ==> 1
}

Total: 1 + n+1 + n  + 1 (2n+3) 
Order O(n) 
*/


/*
void Add(int n) {
    int i, j;
    for (i = 0; i < n; i++){ // n + 1
        for (j = 0; j < n; j++){  // n(n+1)
            c[i][j] = A[i][j] + B[i][j]; // n*n
            }
    }
}

Total: n + 1 + n(n+1) + n
      n + 1 + n2 + n + n2
      2n2 + 2n + 1

      Order O(n2)
*/ 



/*
func1(){
    func2(); // n
}
Total O(n)

func2(){
    for(int i = 0; i < n; i++){
        
        }
}

TOTAL: O(n)
*/



/*
#include<iostream>
using namespace std;
int main ()
{

    int arr[10], n, i, sum = 0, pro = 1; // 1 + 1
    cout << "Enter the size of the array : "; // 1
    cin >> n; // 1
    cout << "\nEnter the elements of the array : "; // 1
    for (i = 0; i < n; i++) //n + 1
    cin >> arr[i]; // n
    for (i = 0; i < n; i++) // n + 1
    {
        sum += arr[i];  // n
        pro *= arr[i]; // n
    }
    cout << "\nSum of array elements : " << sum; // 1
    cout << "\nProduct of array elements : " << pro; // 1
    return 0;

    }

    Total: n + 1 + n + n +1 + n + n + 2 + 4 = 5n + 8
    O(n)
*/