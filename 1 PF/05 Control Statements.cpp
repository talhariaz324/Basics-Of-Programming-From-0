
/*<!-- Control Statements:
1) Sequential: default mode (linear sequence of statements.)....
2) Selection: used for decisions, branching -- choosing between 2 or more alternative paths.(if/, if/else, switch) ...
3) Repetition: used for looping, i.e. repeating a piece of code multiple times in a row. (loops => while, do/while, for)
    Also we will discuss break and continue concept. -->

<!-- if statement -->

"if keyword is used to execute a statement or block"
if (condition) // true
{
statement; // if true then this statement will get execute.
}
// always go below part

<!-- if else statement -->

if (condition)
<!-- We can also use condition with compound statements like a > b && a < c (similarly we can also use || )  -->
{
statement;
}
else
{
statement;
}

<!--  if else if -->

if (condition)
{
statement;
}
else if (condition)
{
statement;
}
else
{
statement;
}



<!--  nested if -->

if(condition) // 1
    if(condition) { //2 
        statement
    }
<!-- else of 2nd if -->
    else {  // 2

    }
<!-- else of 1st if -->
else // 1
{}

<!--  switch statement -->

The switch statement executes one or more of a series of cases, based on the value of a controlling expression.
Syntax:
switch ( expression )
statement

The Switch statement is typically a compound statement, within which are one or more case statements executed if the
control expression matches the case.

<!-- The syntax for a case label and expression follows: -->

case constant-expression :
statement

The constant expression must have an integral type
No two case labels can specify the same value
There is no limit on the number of case labels in a switch statement
Only one statement in the compound statement can have the following label
default:

<!-- When the switch statement is executed, the following sequence takes place: -->
The switch control expression is evaluated (and integral promotions applied) and compared with the constant expressions
in the case labels.
If the control expression's value matches a case label, control transfers to the statement following that label. If a
break statement is encountered, the switch statement terminates; otherwise, execution continues into the following case
or default statements until a break statement or the end of the switch statement is encountered
If the control expression's value does not match any case label, and there is a default label, control is transferred to
the statement following that label. If a break statement does not end the default statement, and a case label follows,
that case statement is executed.
If the control expression's value does not match any case label and there is no default label, execution of the switch
statement terminates.

<!-- complete syntax -->
switch(expression) {
case constant-expression :
statement(s);
break;
case constant-expression :
statement(s);
break;
default :
statement(s);
}


<!-- program -->
int day =8;
switch (day) {
case 1:
cout << "Monday" ; break;
case 2:
cout << "Tuesday" ; break;
case 3:
cout << "Wednesday" ; break;
case 4: 
cout << "Thursday" ; break; 
case 5: 
cout << "Friday" ; break; 
case 6: 
cout << "Saturday" ; break;
case 7: 
cout<< "Sunday" ; break;
default: cout<<“inappropriate value”; }






 <!-- Loops -->

    <!-- Repetition -->

    <!-- loop -->
    block of statements
    A loop consists of two parts, a body of a loop and a control statement. The control statement is a combination of
    some conditions (boolean expression) that direct the body of the loop to execute until the specified condition
    becomes false.
    <!-- Tyoes of loops -->
    While loop
    do while loop
    for loop
    <!-- while loop -->
    while (condition) {
    statements;
    }

    If a condition is true then and only then the body of a loop is executed. After the body of a loop is executed then
    control again goes back at the beginning, and the condition is checked if it is true, the same process is executed
    until the condition becomes false. Once the condition becomes false, the control goes out of the loop.
    e.g;
    int num =0;
    while (num<=10)
     { 
         cout<<num;
          num++; 
          } 
     
     
     <!-- do while loop -->

        do
        {
        Statements
        } while (expression);

        A do-while loop is similar to the while loop except that the condition (boolean expression) is always executed
        after the body of a loop. It is also called an exit-controlled loop.
        The body is executed if and only if the condition is true. In some cases, we have to execute a body of the loop
        at least once even if the condition is false.
        e.g;

        int num =1;

        do {
        cout<<2*num;
         num++;
         } while (num<=10); 
         
         
         
         <!-- for loop -->

            for (initial value; condition; increment or decrement statement)
            { statements; }

            The initial value of the for loop is performed only once.
            The condition is a Boolean expression that tests and compares the counter to a fixed value after each
            iteration, stopping the for loop when false is returned.
            The increment/decrement increases (or decreases) the counter by a set value.

            e.g;



            1) int number;
            for(number=1;number<=10;number++)
             cout<<number; 


            We can skip the initial value expression, condition and/or
                increment by adding a semicolon.


         2) int i=0; 
         int max=10; 
         for (; i < max; i++)
          cout<<i;
         
         
         
         
         
          <!-- Nested loops-->

                loops can also be nested where there is an outer loop and an inner loop.
                For each iteration of the outer loop, the inner loop repeats its entire cycle

                e.g;
                int main()
                {
                int table = 2;
                int max = 5;
                // outer loop
                for (int i = 1; i <= table; i++)
                    {
                         for (int j=0; j <=max; j++)
                    // inner loop
               
        { 
            cout<< i*j; 
        }
         cout<<“\n”;
                    }

<!-- break statement -->
                    You cannot use a break anywhere but inside a loop or a switch statement. break in switch use to stop
                    the
                    execution
                    of the switch statement. whereas break terminates the loop and causes execution to resume after the
                    current loop.

                    The break statement is used in the switch statement. It is also useful for immediately stopping a loop.
                    int main() 
                    { 
                    int num = 5;
                    while (num > 0) 
                    { 
                    if (num == 3) 
                    break;  // exit the loop permanent 
                    cout<<num; 
                    num--; 
                    }
                    }






 <!-- continue statement -->
                    You cannot use a continue anywhere but inside a loop and its effect is to directly jump to the next
                    loop
                    iteration,
                    When you want to skip to particular iteration but remain in the loop, you should use the continue statement.
int main() 
{ 
int nb = 7; 
while (nb > 0) 
{
     nb--; 
if (nb == 5) 
continue; 
cout<<nb;
}
}

Selection of a loop is always a tough task for a programmer, to select a loop do the following steps:
Analyze the problem and check whether it requires a pre-test or a post-test loop.
If pre-test is required, use a while or for a loop.
If post-test is required, use a do-while loop.
For and while loop is entry-controlled loops.
Do-while is an exit-controlled loop.


                    */



        //            #include<iostream>
        //            using namespace std;

        //          int main()
        //         {
        //         int table = 2;
        //         int max = 5;
        //         // outer loop
        //         for (int i = 1; i <= table; i++)
        //             {
        //                  for (int j=0; j <=max; j++)
        //             // inner loop
        //             {
                            
        //             }
               
        // { 
        //     cout<< i*j; 
        // }
        //  cout<<“\n”;
        //             }
         
        //   cout<<"remianing"<<endl;
     
        //             return 0; 
        //            }


                   