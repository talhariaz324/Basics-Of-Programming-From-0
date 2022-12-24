#include <iostream>
using namespace std;
// Static array 
// struct ArrayS {
//  int A[10];
//  int size;
//  int length;

// };
// void Display(struct ArrayS arr) {
//     for(int i = 0; i < arr.length; i++){
//         cout<<arr.A[i]<<endl;
//     }
// }

// int main() {
// struct ArrayS arr = {{1,2,3},10, 3}; // 10 size and 3 entries (length)
// Display(arr);
// }



// Dynamic Array

struct ArrayD {
 int *A;
 int size;
 int length;

};
void Display(struct ArrayD arr) {
    for(int i = 0; i < arr.length; i++){
        cout<<arr.A[i]<<endl;
    }
}

int main() {

struct ArrayD arr; 
cout<<"Enter size of an array: "<<endl;
cin>>arr.size;
arr.A = new int[arr.size];
arr.length = 0;
int n;
cout<<"How many elements"<<endl;
cin>>n;
for(int i=0; i<n; i++) {
    cin>>arr.A[i];
    arr.length = n;
}

Display(arr);
}