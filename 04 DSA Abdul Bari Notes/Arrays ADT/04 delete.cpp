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

    arr->A[arr->length] = x;
    arr->length++;
   
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
            arr->A[i] = arr->A[i-1];
    }
            arr->A[index] = x;
            arr->length++;
  }
}

// Still need more checks 
int Delete(ArrayS *arr, int index){
     // Now first we have to make sure that index is valid or not
    if(index < 0 || index >= arr->size){
        cout<<"Please Enter Right Index"<<endl;
    }
    if(index >= 0 || index<arr->length){
            int x = arr->A[index]; // 1
        for(int i= index;  i < arr->length-1; i++){
           arr->A[i] = arr->A[i+1]; // deleting at the end no traverse. So best case O(1) and but at start deleting would cause all traverse so n
        }
        arr->length--;  // 1
        return x;   // 1
    }

    // Best case O(3) which is O(1) and worst case O(n+3) which is O(n)

}
void Display( ArrayS arr) {
    for(int i = 0; i < arr.length; i++){
        cout<<arr.A[i]<<endl;
    }
}

int main() {
struct ArrayS arr = {{1,2,3},10, 3}; // 10 size and 3 entries (length)
Delete(&arr,3);
Display(arr);
}
