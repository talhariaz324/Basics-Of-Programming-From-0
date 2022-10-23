/*
SomeTimes you need class in which you just want to change the dataTypes.
e.g; In matrix class, you want to do manipulation and return. This can be for int and double etc. SO we use Class Template to handle it.
e.g; Union and Intersection of Persons or anything. Logic Same but the dataType changes, So we can say or make Class Template for it.
*/


/*
In C++, Array does not know about its bounds. It can give error or may not.
*/




// We are going to make class of Array in which we will add more features which are not in default c++ array

#include <iostream>
using namespace std;
#include<cmath>

template< typename T>
class Array
{
    T *data;
    int  capacity; // size of array
    int isValidIndex( int index ) const; // function which will check the bound of the array.
public:
    Array(); // Default
    Array(int); // Parameteized Constructor
    Array ( const Array <T> & ref); // Copy Constructor
    ~Array(); // Destructor
    T & operator [] ( int i ); // index operator overloading
    const T & operator [] ( int i ) const; // with const overloading
    int getCapacity() const; // getting size of array
    void reSize ( int newCap ); // if user want to resize the array
    Array<T> & operator = ( const Array <T> & ref); // opeerator equal overloading
};

template<typename T>
void printArray(Array<T> & a)
{
    for (int i=0; i<a.getCapacity(); i++)
    {
        cout<<a[i]<<'\t';
    }
}
template<typename T>
void inputArray(Array<T> & a)
{
    for (int i=0; i<a.getCapacity(); i++)
    {
        cin>>a[i];
    }
}
int main()
{
    Array<int> a(5); // In class templates we have to explictly tell the type
    cout<<"Enter Array Element: ";
    inputArray(a);
    cout<<"Array elements are: ";
    printArray(a);

    
    
    cout<<endl;

    
    
    return 0;
}


template< typename T >
int Array<T>::isValidIndex( int index ) const
{
    return index>=0 && index<capacity; // return true else false
}
template<typename T>
Array<T>::Array()
{
    capacity=0;
    data=0;
}
template<typename T>
Array<T>::Array(int size):Array() // Delegation Constructor (if size 0 or less than 0 then delegation constructor call which make it 0)
{
    if (size<=0)  //as 0 made by delegation constructor
        return; // so return
        // else case
    capacity=size;
    data = new T[capacity];
}

template<typename T>
Array<T>::~Array()
{
    if (data) // if data mean data exists then delete  (if we dont make check then it will cause runtime error because if no data then whcih to delete on heap)
        delete [] data;
        // else 
    data=nullptr;
    capacity=0;
}
template<typename T>
T & Array<T>::operator [] ( int i )
{
    if (isValidIndex(i)) // if true index
        return data[i]; // return that index allias
        // else exit.
    exit(0);
}
template<typename T>
const T & Array<T>::operator [] ( int i ) const // same above just for const array. const object only call const function
{
    if (isValidIndex(i))
        return data[i];
    exit(0);
}
template<typename T>
int Array< T >::getCapacity() const
{
    return capacity;
}
template<typename T>
void Array<T>::reSize ( int newCap )
{
    if (newCap<=0)
    {
        this->~Array();
        return;
    }
    // else
    T * ptr = new T[newCap];
    // other if
    if (capacity>0)
    {
        int size= newCap<capacity? newCap:capacity;
        for ( int i=0; i<size; i++)
        {
            ptr[i] = data[i];
        }
    }
    // else
    this->~Array();
    capacity = newCap;
    data=ptr;
}
template<typename T>
Array<T> & Array<T>::operator = ( const Array<T> & ref)
{
    if ( this == &ref) // self assignment check so that not assign itself on heap
        return *this;
        // else
    this->~Array();
    if (ref.data == nullptr)
    {
        data = nullptr;
        capacity = 0;
        return *this;
    }
    capacity=ref.capacity;
    data = new T[capacity];
    for ( int i=0; i<capacity; i++)
    {
        data[i] = ref.data[i];
    }
    return *this;
}
template<typename T>
Array<T>::Array ( const Array <T> & ref)
{
    if (ref.data==nullptr)
    {
        data=nullptr;
        capacity=0;
        return;
    }
    capacity=ref.capacity;
    data = new T[capacity];
    for ( int i=0; i<capacity; i++)
    {
        data[i] = ref.data[i];
    }
}


