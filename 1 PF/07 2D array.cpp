/*

<Two-dimensional or 2D array>

In C++ two Dimensional array is an array that consists of more than
one rows and more than one column. In 2-D array each element is
refer by two indexes. Elements stored in these Arrays in the form of
matrices. The first index shows a row of the matrix and the second
index shows the column of the matrix.

A two-dimensional array is, in essence, a list of one-dimensional
arrays.

Declared as

type arrayName [ R ][ C ];



     <As general>

Arr[0][0]=10; // 10 stored in first column of first row

Arr[0][1]=20; // 20 stored in second column of first row

Arr[0][2]=30; // 30 stored in third column of first row

Arr[1][0]=40; // 40 stored in first column of second row

Arr[1][1]=50; // 50 stored in second column of second row

Arr[1][2]=60; // 60 stored in third column of second row


               < Initializing 2D Array>

The process of assigning values during declaration is called initialization.
These arrays can be initialized by putting the curly braces around each row
separating by a comma also each element of a matrix should be separated
by a comma.

int mat [3][3]= {

{ 3,6,8 },

{ 5,4,7 },

{ 2,4,7 }

};

OR:

int mat[3][3]={3, 6, 8, 5, 4, 7, 2, 4, 7};



         < Initializing using loop>


  Nested loop is used to enter data in 2-D arrays. Generally, the outer
loop acts as the number of rows of a matrix and the inner loop acts as
the number of columns of a matrix.

Random 

int arr[2][4];

for( int i =0; i <2;i++)

for(int j=0;j<4;j++)

cin>>arr[i][j];



<Proper Example>

int matrix [2][3];
//Taking integer inputs in a matrix 

for (int i=0 ; i<2 ; i++)
{
    for (int j=0 ; j<3 ; j++)
    {
     cout<<"Enter Integer :";
     cin>>matrix [i][j];
     }
}
cout<<endl;

//Displaying elements of a matrix 

for (int i=0 ; i<2 ; i++)
{
    for (int j=0 ; j<3 ; j++)
    {
     cout<<"Your Entered Integer are :";
     cout<<matrix [i][j];
     cout<<endl;
    }
}



*/