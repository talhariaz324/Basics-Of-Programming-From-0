/*
What is OOP?
Before oop we used procedural programming. In which we used functions to perform certain tasks.
Sometimes in which we have to copy the same code again and again. But this issue is fix by oop.


In OOP, We use classes for certain tasks.
By using these classes we can create objects and then we can interact them.

What do you mean by objects?

Everything in the real world is an object which have attributes and behaviour and some special identity.
Something tangible.
Something that can be apprehended intellectually (Time, Date)

e.g; a car has attributes like color, model, price, etc. and behaviour like start, stop, accelerate, etc.

What is class?

Class is blueprint of objects. Mean we define the attributes and behaviour of objects in it.

Advantages of OOP:

Close to real world objects and easy to understand.

Modularity and Reusability.

Maintenance and extensibility.

*/

/*

NOTES:
    1) The class is a blueprint it will not get space in memory. But object will get space.
    2) Each object will get space for their self in memory but for only member variables not for member functions. Same Member functions in memory (which are used by 1st object) can be used by other objects.
    3) Operator overloading. We can use operators just for built in types like int, float, even for string etc..
       But for user defined data types, these operators not work. For using them for our user defined data types we use operator overloading and one more method which is called traditional method. e.g;

       ==> Traditional Approach:
       class A {
           int weight;
           public:
           A (x = 0) {
               weight  = x;
           }
           void printWeight () {
               cout<<"Weight is " << weight<<endl;
           }
           A addWeight (A w2) {
               A temp;
               temp.weight = weight + w2.weight;
               return temp;
           }
       };
       int main ()
       {
          A person1 (54);
          A person2 (45);
          A total;
          total = person1.addWeight(perosn2);
          OR:
          total = person2.addWeight(person1);
          total.printWeight();
       }

       ==> Operator Overloading

       class A {
           int weight;
           public:
           A (x = 0) {
               weight  = x;
           }
           void printWeight () {
               cout<<"Weight is " << weight<<endl;
           }
           A operator + (A w2) {
               A temp;
               temp.weight = weight + w2.weight;    OR "for pre incremnt"         A operator ++ () { ++weight }    OR "for post increment"         A operator ++ (int) {weight++}
               return temp;
           }
       };
       int main ()
       {
          A person1 (54);
          A person2 (45);
          A total;
         total = person1 + person2;
         total.printWeight();
         return 0;
       }
    4)
    => 1st case: When we make the object of derived class without params. Then it calls the base class constructor 1st and then derived class.
       2nd case: If we create derived class object with params then it will also call the defult constructor of base class 1st and then params constructor of derived class.
       In this case Derived class can't call the parameterized constructor of base class. Actually derived class has no access to params constructor of base class.
       3rd case:  If we want to call the params constructor of base class then we use member initializer.... e.g;

     2nd case example   class Base {
         public:
         Base () {
             cout<<'Default called'<<endl;
         }
         Base (int b) {
             cout<<'Params called'<<endl;
               }

         class Derived : public Base {
             public:
             Derived () {
                 cout<<'Default called dervied'<<endl;
             }
             Derived (int d) {
             cout<<'Params called derived'<<endl;
               }

         }
       };

       int main () {
           derived d; // Call default base and then default derived
           derived d1(2); // call default of base and then params of derived class and if nothing  (empty) in derived class then it will just call the base class default constructor
       }



     3rd case example   class Base {
         public:
         Base () {
             cout<<'Default called'<<endl;
         }
         Base (int b) {
             cout<<'Params called'<<endl;
               }

         class Derived : public Base {
             public:
             Derived () : Base ()   // Default is this for calling constructor but just for understanding i write this.
            {
                 cout<<'Default called dervied'<<endl;
             }
             Derived (int d) : Base (d) {   // Now the params Constructor of Base class will call as we use member initailizer.
             cout<<'Params called derived'<<endl;
               }

         }
       };

       int main () {
           derived d;  // Call default base and then default derived
           derived d(2); // Call parmas constructor of base class as i use member initializer and then call the derived params constructor
           }

    ==> Overriding:
       As you know in overriding when make the object of derived class then it call the latest override function which is absolutly in derived class
       What if we want to make object of derived class but want to access the base class function defination which is overridden in derived class with some modification
       For this simply in derived class function defination (overriden function) explictly write
       base class name :: funcation name ();
       e.g;
       class base {
public:
void myMsg () {
    cout<<"Hello world"<<endl;

}
       class derived : public base {
public:
void myMsg () {
    base :: myMsg();

}

       };

int main () {
    derived d;
    d.myMsg();
}

  ==> IS A and HAS-A Reltionship:
  We use IS A when
    1) When most of the function of base class are in derived class
    2) It expose all public members to derived class
    3) Static binding (Compile Time)
    4) Use inheritance
  We use HAS A when
    1) When few of the function of base class are in derived class
    2) It cant expose all public members to derived class only which are needed
    3) Dynamic binding (Run Time)
    4) Use Objects



==> Ways of Inheritance

public, protected, and private inheritance have the following features:

public inheritance makes public members of the base class public in the derived class, and the protected members of the base class remain protected in the derived class.
protected inheritance makes the public and protected members of the base class protected in the derived class.
private inheritance makes the public and protected members of the base class private in the derived class.
Note: private members of the base class are inaccessible to the derived class.



==> Polymorphism

  1st concept:
     base class pointer which points to object of derived class
     above condition is much compatible.
     but it does not mean that base class pointer can access the members of derived class. It can only access its own (base class) members
   2nd concept:
   Virtual function:
   we cant acess the derived class method by making pointer of base and store derived class object in it. e.g;
   class base {
       public:
      virtual void show () { // if we remove virtual it will call base method because of 1st concept but if we make it virtual (mean not visibke but have apperance) then it will not use it and go for derived class
           cout<<"Base"<<endl;

       }
   class drieved1 {
       public:
       void show () {
           cout<<"dr1"<<endl;

       }
   class drieved2 {
       public:
       void show () {
           cout<<"dr2"<<endl;

       }
   };
   int main () {
       base *ptr;
       ptr = new drieved1();
       ptr->show();
       ptr = new drieved2();
       ptr->show();
   }


   ==> Pure virtual Function

   Consult slides for it.
   When any class has pure virtual function then it will be called as abstract class and its object never be instantiate.


   ==> Conculusion


            We have one function which is overriden in derived class and at runtime its get decide which functionality is to perform
            according to the object. Now one function can performs multiple tasks then it is polymorphism.
            Polymorphism mean many forms.....
    Polymorohism are of two types:
    Compile time:
    Runtime:
--> Compile time:
                In compile time consists 1) Operator overloading 2) Function overloading
 --> Run time:
                In runtime consists 1) function overriding 2) virtual Function


    ==> Virtual destructor:

    As we seen that if create the pointer of base class and then stor the object of derived class in it.
    then it will points to base class functionality first. for fixing it we use virtual keyword

    Similarly when we delete the ptr of base class which have object of derived class it will only delete the base class.
    for deleting the whole you should write virtual with the base class destructor.

    class base {
        virtual ~base () {
            cout<<"base destructor"<<endl;
        }
    };
    class derived {
        virtual ~derived () {
            cout<<"derived destructor"<<endl;
        }
    };
    int main () {
        base *ptr = &derived();
        delete ptr;
    }


==> Friend Functions:
 A normal function which is outside the class can access only access the public members of class.
 BUT for providing high command to programmers there is a concept of friend function.
 A function which can access private , protected and public members of class.
 It can violate the classes concept but as i said it is provided for providing high command or access to programmers


 --> It acts as bridge between two classes. e.g;

#include <iostream>
using namespace std;

class Alpha
{
private:
    int a1;

public:
    Alpha(int aa1)
    {
        a1 = aa1;
    }
    friend void fun();
};
class Beta
{
private:
    int b1;

public:
    Beta(int bb1)
    {
        b1 = bb1;
    }
    friend void fun();
};

void fun()
{
   Alpha a(10);
   Beta b (10);

   int x = a.a1 + b.b1;
   cout<<x<<endl;
}
int main()
{
    fun();
}



==> Operator overloading of relational operatior...
e.g;
#include <iostream>

using namespace std;

class person {
    int weight;
    public:
    person (int w1) {
        weight = w1;
    }

    friend bool operator > (person x, person y); // we use friend here as member of class cant deal/entertain with two arguments. for fixing it we use friend
    friend bool operator < (person x, person y);
};

bool operator > (person x, person y){
    return x.weight > y.weight;
}
bool operator < (person x, person y){
    return x.weight < y.weight;
}
int main () {
    int w1, w2;
    cout<<"Enter weight of Moeez"<<endl;
    cin>>w1;
    cout<<"Enter weight of Anas"<<endl;
    cin>>w2;

    person moeez (w1);
    person anas (w2);

    if(moeez > anas) {
        cout<<"weight of moeez is greater than anas" <<endl;
    }else {
        cout<<"weight of anas is greater than moeez" <<endl;

    }

}




 ===> Friend class

 A friend class can access private and protected members of other class in which it is declared as friend.
 In inheritance we cant access the private members and constructors but in friend we can access the private members and constructors

e.g;

#include<iostream>
using namespace std;
class Alpha {
  int w;
  public:
  Alpha (int w1) {
        w = w1;
  }
  friend class Beta;
};
class Beta {
   int b;
   public:
   Beta (int b1) {
       b  = b1;
   }
   int sum () {
       Alpha a(10);
       int x = a.w + b;
       return x;
   }
};


int main () {
    Beta get(10);
    cout<<"Sum is " << get.sum();
    return 0;
}


==> Static members & static member function


Static members:
NOTE: Every object members of same class reserves its own memory.

--> But static members would be allocated memory only once.
--> That memory is shared by all objects.
--> Static data members belong a class and common to all objects.
e.g;
#include<iostream>
using namespace std;

class Alpha {
    int a,b;
    public:
    Alpha() {
        a = 5;
        b = 5;
        stat++;
    }
    static int stat;
};
int Alpha :: stat = 0;

int main () {
    Alpha a1;
    Alpha a2;

    cout<<"a1 value "<<a1.stat<<endl; // output would be same because memory is same for every object and constructor run for every object
    cout<<"a2 value "<<a2.stat<<endl;
    cout<<"class stat value "<<Alpha::stat<<endl;
}

static member function:

    ==> These static functions can only access the static members. Not others...
    ==> These static functions can be access by class name or by objects too.
e.g;
#include<iostream>
using namespace std;

class Alpha {
    int a,b;
    public:

    static int stat;
    static int getVal () {
        stat++;
        return stat;
    }
};
int Alpha :: stat = 0;

int main () {
    Alpha a1;
    Alpha a2;

    cout<<"a1 value "<<a1.getVal()<<endl; // output would be different because function get run for every object and it increase value
    cout<<"a2 value "<<a2.getVal()<<endl;
    cout<<"class stat value "<<Alpha::getVal()<<endl;
}


*/
