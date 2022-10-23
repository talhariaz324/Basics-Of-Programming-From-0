// <!-- Operators: Arithmetic operators and punctuations, Precedence, Associations, Equality and
// relational operators. -->

//  <!-- Operators: -->
//             "An operator is a symbol that tells the compiler to perform specific
// mathematical or logical manipulations."


//  NOTE:  executes from right to left

// <!-- Types of operators: -->

// Arithmetic Operators
// Relational Operators
// Logical Operators
// Bitwise Operators
// Assignment Operators
// Misc Operators (others default operators of programming language)

// + Adds two operands ,A + B will give 30
// - Subtracts second operand from the first ,A - B will give -10
// * Multiplies both operands  , A * B will give 200
// / Divides numerator by de-numerator, B / A will give 2
// % Modulus Operator and remainder of after an integer division B % A will give 0

// <!-- Unary arithmetic operator : -->
// where A = 10
// ++ Increment operator, increases integer value by one , A++ will give 11
// -- Decrement operator, decreases integer value by one , A-- will give 9

// Post increment (A++) – first use A then increment
// Post decrement (A--) – first use A then decrement
// Pre increment (++A) – first   increment then use A
// Pre decrement(--A) – first decrement then use A


    int A  = 10;
    A++; // it first read the variable and then increment as its name shows its a post increment.  // 10 and then increment 11
    ++A; // first increment and then read the variable  // 11 when it read then its value be 11 not 10

// <!-- Relational operators -->
//                "Two values can be compared using relational and equality operators. For example, to know if two values are equal or if one is greater than the other."

//             The result of such an operation is either true or false (i.e., a Boolean value). 

// == Equal to   a = 10; and b  = 11;  if( a==b )  false
// != Not equal to   if(a != b) true
// < Less than  if(a < b) true
// > Greater than if(a > b) fasle
// <= Less than or equal to if(a<=b) true
// >= Greater than or equal to if(a>=b) false

//  <!-- Logical operators -->

// && Called Logical AND operator. If both the operands are non-zero, then condition becomes true.
    //  e.g; a = 1 and b = 1; then this operation gives us true
    // Otherwise a = 0 and b = 0; this operation will give us false
    // Otherwise a = 1 and b = 0; this operation will give us false
    // Otherwise a = 0 and b = 1; this operation will give us false
// || Called Logical OR Operator. If any of the two operands is non-zero, then condition becomes true.
//  e.g; a = 1 and b = 1; then this operation gives us true
    // Otherwise a = 0 and b = 0; this operation will give us false
    // Otherwise a = 1 and b = 0; this operation will give us true
    // Otherwise a = 0 and b = 1; this operation will give us true
// ! Called Logical NOT Operator. Use to reverses the logical state of its operand. If a condition is true, then Logical NOT operator will make false.

// <!-- Bit-wise operators -->

// Bitwise operator works on bits and perform bit-by-bit operation. The truth tables for &, |, and ^ are as follows −

//  p  q   p & q    p | q      p ^ q
//  0  0     0        0          0
//  0  1     0        1          1
//  1  1     1        1          0
//  1  0     0        1          1

//  & Binary AND Operator checks if exists in both operands.
// | Binary OR Operator checks if exists in either operand.
// ^ Binary XOR Operator checks if in one operand but not both.
// ~ Binary Ones Complement Operator is unary and has the effect of 'flipping' bits.
// << Binary Left Shift Operator. The left operands value is moved left by the number of bits specified by the right operand.
//    it work in 2 * n where n is number of bits e,g; a<<1 (a is howing to whom change and one shows to change 1 bit to left)
// >> Binary Right Shift Operator. The left operands value is moved right by the number of bits specified by the right operand.
//    it work in 2 power n whose answer divide by given num e.g; a>>1

// <!-- Assignment operators -->

// = Simple assignment operator, Assigns values from right side operands to left side operand. C = A + B will assign value of A + B into C
// += Add and assignment operator, It adds right operand to the left operand and assign the result to left operand. C += A is equivalent to C = C + A
// -= Subtract AND assignment operator, It subtracts right operand from the left operand and assign the result to left operand. C -= A is equivalent to C = C - A
// *= Multiply AND assignment operator, It multiplies right operand with the left operand and assign the result to left operand. C *= A is equivalent to C = C * A
// /= Divide AND assignment operator, It divides left operand with the right operand and assign the result to left operand. C /= A is equivalent to C = C / A
// %= Modulus AND assignment operator, It takes modulus using two operands and assign the result to left operand. C %= A is equivalent to C = C % A






// <!-- Expressions -->


 a = a + b;

// A combination of variables, constants and operators that represents a computation forms an expression. Expression evaluation depends on operators precedence and associativity. e.g; x = 7 + 3 * 2;

// <!-- forms -->

// Arithmetic
// Boolean (A Boolean expression is a C++ expression that returns a boolean value: 1 (true) or 0 (false))
// Relational
// Bitwise
// Constants ( only constants involved e.g. 2+2)





// <!-- Operator Precedence and Associativity -->

// Operator precedence determines which operator is performed first in an expression with more than one operators with different precedence.

// <!-- Is operator precedence same in all languages? -->

// The simplest answer is no, because different languages provide different sets of operators. For example, C++ has the :: operator, but C does not.

// For example x = 7 +3 * 2; here, x is assigned 13, not 20 because operator * has higher precedence than +, so it first gets multiplied with 3*2 and then adds into 7.

// Operators Associativity is used when two operators of same precedence appear in an expression. Associativity can be either Left to Right or Right to Left.
// For example: ‘*’ and ‘/’ have same precedence and their associativity is Left to Right, so the expression “100 / 10 * 10” is treated as “(100 / 10) * 10”.

// <!-- Table -->

// Note: operators with the highest precedence appear at the top of the table, those with the lowest appear at the bottom. Within an expression, higher precedence operators will be evaluated first.

 //  Higher precendence to lower precendece
// Operators        Precedence                     Associativity

// Brackets        () []                          Left to right
// Unary           ++ - -                         Left to right
// Multiplicative   * / %                         Left to right
// Additive         + -                           Left to right
// Equality         =, +=, -=, *=, %=, /=         Right to left
// Bitwise AND      &                             Left to right
// Bitwise XOR      ^                             Left to right
// Bitwise OR       |                             Left to right
// Logical AND      &&                            Left to right
// Logical OR       ||                            Left to right
