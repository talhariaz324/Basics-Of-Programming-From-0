// <!-- Data Types: Identifiers, Constants, Types of variables, Type conversion and casting, Type
// promotion rules. -->

// <!-- Identifiers -->

//  Name of variables are called identifiers. Naming convention is also vary from lang to lang.

//  <!-- Constants -->

//   Those variable which are read only. we can't change them. e.g; pi = 3.14


    // changeable
      int abbas = 10;
 
     const int pie = 3.14;  
   





// <!-- Types of variables -->

//   Types of variables are actually data types.
//   The data type specifies the size and type of information the variable
//   will store. e.g; int a = 10; this syntax can be little bit change according to language.
//   int is data type. a is variable name. 10 is value. we can't store string in int variable.





// <!-- size and function -->
// string is used for storing text. e.g; 'Hello World'

// long 8 bytes Stores whole numbers of larger size, without decimals

// int 4 bytes Stores whole numbers, without decimals

// float 4 bytes Stores fractional numbers, containing one or more decimals.
// Sufficient for storing 7 decimal digits

// double 8 bytes Stores fractional numbers, containing one or more decimals. Sufficient for storing 15 decimal digits

// boolean 1 byte Stores true or false values

// char 1 byte Stores a single character/letter/number, or ASCII values
// NOTE: 'A' gives A, and 65 gives also A. because integer in char gives ASCII

//    <!-- The size of data types is dependent on the compiler or you can say that the system architecture
//    i.e. 32 bit compiler or 64 bit compiler. The size of data type int is 2 byte in 32 bit architecture
//   or 4 bytes in 64 bit architecture. -->

//   Overflow occurs when the value assigned to any data type variable is
// more than maximum possible value.

// Underflow occurs when the value assigned to any data type variable is
// less than minimum value that could be stored.





// <!-- Type conversion or casting -->

//   Type conversion or casting is the process of converting one data type to another data type.
//   Two types of conversion are possible:
//   1. Implicit conversion (type conversion as by compiler) (automatically
//    e.g; int a = 10;
//         float b = 15.5;
//         float c =  a+b; // here compiler automatically convert int 10 to float 10.0 and then add. this is called implicit conversion.

//    e.g 2; int a = 10;
//         float b;
//         b = a; // here compiler automatically convert int 10 to float 10.0 and then assign. this is called implicit conversion.
//     No data loss

//     Conversion from lower to higher (char->short int-> int -> long int->float->double)
//   )
//   2. Explicit conversion (casting as we do this) (manually)
//    e.g; int a = 10;
//         float b = 15.5; 15.5 
//         int c = a+(int)b; // here compiler convert float b 15.5 to int 15 as we say manually and then add. this is called explicit conversion.
//    data loss.
//    conversion higher to lower (double->float->long int->int->short int->char)

// )

// <!-- Type promotion rules -->

//  Some data types like char , short int take less number of bytes than int,
// these data types are automatically promoted to int or unsigned int when an operation is performed on them.
// This is called integer promotion. For example no arithmetic calculation happens on smaller types like char, short and enum.

