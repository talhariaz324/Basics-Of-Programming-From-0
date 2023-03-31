/*
Inline functions are nothing but we can make them inline using the keyword inline.
In normal function when we call the functions the compiler jumps to the def of function and then come back with results.
but it consume more time.
Solution is to use the inline keyword.
When we call the inline function then during call instead of jumping compiler copy and paste the defination of function
at the place of call. It increase efficency of code.
But compiler will only entertain the inline function when its defination is small. It should be small then it will work.
Otherwise work like a normal function
*/


/*
"The only time an inline virtual call can be inlined is when the compiler knows the "exact class" of the object which is the target of the virtual
 function call. This can happen only when the compiler has an actual object rather than a pointer or reference to an object. I.e., either with a
 local object, a global/static object, or a fully contained object inside a composite."
*/