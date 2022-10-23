/*
Variable scoping...

There are two types of scoping:
1. Local scope
2. Global scoping


// Local Scope and Global Scope

Anything in curly braces or in function called as local scope.
This local scope can be only accessed within the curly braces in which it is declared.

Without any curly braces, it is called global scope.
Can be access from the whole program.
e.g;
    #include <iostream>
    using namespace std;

   int a =  50; // global scope

    int main () {
      int  a = 10;
      int  b = 20;
        {
            int a = 30;
            int b = 40;
            cout << a << endl; // it will access local scope and print 30
            cout << b << endl; // it will access local scope and print 40
        }

        cout << a << endl; // it will access global scope and print 10
        cout << b << endl; // it will access global scope and print 20
        // for accessing global scope, we need to use scope resolution operator ::
        cout << ::a << endl; // it will access global scope and print 50
        return 0;
    }
    OutPut:
    30
    40
    10
    20
    50





NOTE: Can't access local scope outside curly braces.
      Can't declare same var in the same scope either its local or global.

  // Another example:

   #include <iostream>
    using namespace std;

   int a =  50; // global scope

    int main () { // scope 1 start
      int  a = 10;
      int  b = 20;
        { // scope 2 start



           cout << a << endl; // it will access global scope and print 10
           cout << b << endl; // it will access global scope and print 20



        }// scope 2 end


        return 0;
    }// scope 1 end




   #include <iostream>
    using namespace std;

   int a =  50; // global scope

    int main () { // scope 1 start

        { // scope 2 start

            int a = 10;
            int b = 20;
        }// scope 2 end

     cout<< a << endl; // it will access global scope and print 50... Yes if its not find in its local scope then it go for global without resolution operator as local scope variable  is prefer on global scope variable
     cout << b << endl  // error b is not declared in this scope.
        return 0;
    }// scope 1 end


    NOTE: Local scope 2 can access the variable of local scope 1 as it is in the same scope.
          But local scope 1 can't access the variable of local scope 2 as it is in the different scope.



   Curly braces can also be of the functions and classes..  You learn classes later.



*/