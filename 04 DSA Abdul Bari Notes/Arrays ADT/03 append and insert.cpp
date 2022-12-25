#include <iostream>
using namespace std;
// Static array 
struct ArrayS {
    public:
 int A[10];
 int size;
 int length;

};

void Append( ArrayS *arr, int x){ // Here referencing with * and passing with &. Because we have to change in array

    arr->A[arr->length] = x;   // Time complexity is 1
    arr->length++; // 1
   // SO total would be 2 so 2n^0 and O(n^0) = O(1) constant
}
// Some checks are still missing but go with abdul bari sb
void insert(ArrayS *arr, int index, int x){
    // Now first we have to make sure that index is valid or not
    if(index < 0 || index >= arr->size){
        cout<<"Please Enter Right Index"<<endl;
    }
    // Do traversing so that we can put our x at require index 
  if(index >= 0 || index<arr->length){
        for(int i=arr->length; i > index; i-- ){
            arr->A[i] = arr->A[i-1]; // 0 or n
    }
            arr->A[index] = x;  //  1
            arr->length++;      // 1
  }

  // Time complexity of insert is vary acc to index so that we can traverse.
  // If the index is last to insert then no work so O(1) 
  // But when index is 0 then it need to traverse all elements which would be O(n)

  // So, min O(1) best case and max O(n+2) -> O(n) worst case
}
void Display( ArrayS arr) {
    for(int i = 0; i < arr.length; i++){
        cout<<arr.A[i]<<endl; //max O(n) because it depends on number of elements and min O(1) when no element 
    }
}

int main() {
struct ArrayS arr = {{1,2,3},10, 3}; // 10 size and 3 entries (length)
insert(&arr,4,5);
Display(arr);
}
