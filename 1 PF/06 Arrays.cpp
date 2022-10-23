/* Arrays: Declaring arrays; Initialization, Multidimensional arrays, Two dimensional arrays,
 Example (Matrix manipulation), Assignments, and Mini Project.

    <Array>



  Arrays are used to store multiple values in a single variable, instead of
declaring separate variables for each value.




 

  <Declaring arrays>




   
   dataType arrayName[arraySize];
 
  <Example>
   
    float mark[5];

string cars[4];

string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};

<To create an array of three integers, you could write:>

int myNum[3] = {10, 20, 30};





<Access Elements of array>





You access an array element by referring to the index number.

This statement accesses the value of the first element in cars:

string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
cout << cars[3];


//  Accessing from loop


string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
for(int i = 0; i <4; i++) {
cout << cars[i] << "\n";
}





NOTES:

 1) You don't have to specify the size of the array. It will be as big as the
elements that are inserted into it:

string cars[] = {"Volvo", "BMW", "Ford"};



   2) int testArray[10];

 If you try to access array elements outside of its bound, let's
 say testArray[14], the compiler may not show any error. However,
 this may cause unexpected output (undefined behavior).

 <Charater Arrays>

 Two ways of declaration and initialization:

char name[]="khan ali"; // space inculdes in array size
 cout<<name; // it will print khan ali because it is a character array and at the end it will find null character ('\0') and it will stop printing.
char name2[]={'a','b','c'}; 
cout<<name; // it will print abc because it is a character array and at the end it will find null character ('\0') and it will stop printing.
Note: In character arrays, by default, at the end of array size has null char ('\0') and it will stop printing.

 
 

*/
