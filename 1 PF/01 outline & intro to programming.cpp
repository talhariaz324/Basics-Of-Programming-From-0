/*
These all about PF......

<!-- ==> Introduction to Programming: Problem solving, Introduction to programming and programs,
Types of languages, Compiler vs. Interpreter. -->

Overview of Programming: Structure of Program, indentation and coding conventions, Program
output, Syntax rules, Common errors, Language keywords.

Data Types: Identifiers, Constants, Types of variables, Type conversion and casting, Type
promotion rules.

Operators: Arithmetic operators and punctuations, Precedence, Associations, Equality and
relational operators.

Control Statements: Selection structure (if/, if/else), Multiple selection structure (switch and
break), break and continue, Loops.

Arrays: Declaring arrays; Initialization, Multidimensional arrays, Two dimensional arrays,
Example (Matrix manipulation), Assignments, and Mini Project.

Pointers

Structures

Methods/Functions: Library functions, Modular Approach, Functions, and Function definitions.
Function prototypes.




                                   <!-- Problem Solving: -->
   "We use programming to solve problems".
   For the solution, we develop a program by using the below.

    We follow the few steps to solve the problem more efficiently. These steps are also called SDLC. Software Development life cycle

    1) Define the problem ==> Clear understanding of the problem first

    2) Analysis and Design  ==> Do some analysis that how can I solve this kind of problem and then design its solution.

    3) Coding ==> Do coding after designing (In your favorite language).

    4) Testing ==> After coding, test it for any kind of errors

    5) Implementation ==> Implement solution to its place (where it is required).

    6) Maintenance ==> Do maintenance (for new features) with the passage of time.



             <!-- Introduction to programming and programs: -->
        "Writing some instructions to solve the problem (for which you are developing solution) is called programming. Your goal should be to use minimum number of lines
         and resources for your problem solution."



   For writing these programs we use IDE:

     IDE (Integrated development life cycle) is an editor use to write programs. For example;                   VS-Code, NetBeans, Eclipse, IntelliJ,

                                  <!-- Types of languages: -->
Types:

           High level language  ==> In which programmer writes program.
           Low level language  ==> Computer understands low level language also called as 0 and 1.
          NOTE:  For translating high to low level we use compiler and interpreter.

    High level language types:

          1) Procedural languages (Before OOP concept we used this type of languages but they was far from real world and had more lines of codes).

          2) Object Oriented language (Close to real world and has reusability like C++)

          3) Non Procedural languages (User only needs to tell the computer what to do not tell how to do while in above we have to tell hoe to do 
          For example; SQL (structured Query Language)).

  Low level languages types:

              1) Machine language (its also low level language in form of 0 and 1).

              2) Assembly language (For overcoming the problem of understanding 0 and 1. Assembly language uses small words for different operations
               like ADD (for addition) and SUB (for subtraction). This type of code call as mnemonics code. We convert it into 0 and 1 using assembler).

   <!-- Language translator (Compiler, interpreter, Assembler).  -->
                        Language translator : "Converts high to low level language"

               Types:

                     1) Compiler (read whole program and then give error if any).

                     2) Interpreter (read program line by line and if 3rd line has error it stops on it give error and don't execute 4th line and remaining lines).

                     3) Assembler  (Assembler converts assembly language symbols like ADD, SUB into machine code.)



                                 <!-- Compiler working -->


   Source code (our written code) --> compiler (convert to assembly language) --> Assembler (convert to machine or object code) --> Object code (machine language) --> Linker --> Executable file --> Loader



Linkers - combines object code with additional libraries (it search definition of functions because compiler just check the prototype if it doesn't find file it will give error called as linker error. For example; cout<< in cpp its defination is attached by linker during compilation process and linker also care of arranging the object in required order) and save as .exe file



Loaders - places executable file into memory when we run our executable file .exe made by linker.

When we run our program, loader loads our executable file to memory first and then show output.



                                              <!-- Compile time vs Runtime -->



   Compile time is when you are writing code.  Syntax errors are also give at compile time. like int a  = ''abc" ;// error

 Runtime means when our code has no syntax error and it can run. but we lost connection to server while running application. This error is called as runtime and also runtime errors are called as exception. Similarly, at runtime user can give wrong input which is also a part of runtime.

*/
