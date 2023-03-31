#include<iostream>
using namespace std;

template<typename T>
class Stack
{
T * data;
int capacity;
int top;
void reSize(int);
public:
Stack();
Stack(const Stack<T> &);
Stack & operator = (const Stack<T> & );
~Stack();
void push(T);
T pop();
T stackTop();
bool isFull();
bool isEmpty();
int getCapacity();
int getNumberOfElements();
};

int main()
{
Stack<int> s;
for (int i=1; i<=12; i++)
{
s.push(i);
}
while(!(s.isEmpty()))
{
cout<<endl<<s.pop();
}
return 0;
}

template<typename T>
Stack<T>::Stack(){
    data = nullptr;
    capacity = 0;
    top = 0;
}

template<typename T>
void Stack<T>::push(T val){
    if(isFull()) // assuming it
    {
        reSize(capacity=0?1 : capacity*2);
    }
    data[top++] = val;
}
template<typename T>
T Stack<T>::pop(){
    if(isEmpty()) // assuming it
    {
        exit(0);
    }
    else{
        T val = data[--top];
        if(top ==0 && top == capacity/4){
            reSize(capacity/2);
        }
            return val;
    }
    
}


template<typename T>
void Stack<T>::reSize(int newSize){
    T * temp = new T[newSize];
    for(int i =0; i<top; i++){
        temp[i] = data[i];
    }
    this->~Stack();
    data = temp;
    capacity = newSize;
}

template<typename T>
T Stack<T>::stackTop(){
    if(isEmpty()) {
        exit(0);
    }
    else {
        return data[top-1];
    }
}


template<typename T>
 Stack<T>::~Stack(){
    if(!data){
        return;
    }
    else{
        capacity = 0;
data = nullptr;
top = 0;
    }
}




