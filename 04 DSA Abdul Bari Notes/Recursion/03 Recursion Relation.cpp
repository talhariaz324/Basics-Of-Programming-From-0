/*
=> Why 1 unit time.
When we do 1 simple process then its time taken vary from machine to machine. so for fixing it we take more general
time which is 1 unit time for each statement.
=> Simple time complexity of recursion.
            func1(3) ===> 1 unit time
             /  \
            3   func1(2) ===> 3 > 0 ===> 1 unit time
                /  \
               2   func1(1) ===> 2 > 0 ==> 1 unit time
               /     \
               1     func1(0) ===> 1 > 0 ===> 1 unit time
                       no furthur call because now 0 > 0 .... false.
                       
                  so, how much time function takes?
                  its 4 units time for the value 3.
                  Similarly, for n value it takes n +1
                  So O(n)     
                       
=> Recursion Relation time complexity

Let's take time complexity from the Recursion Relation.

void func1(int n) { // Assume function takes T(n) time
    if(n > 0){ // 1 
    cout << x <<endl; // 1
    func1(n-1); // As we assume that above function takes T(n) time then this function absolutlely takes T(n-1) as per its param
    }
}

int main(){
    int x = 3;
    func1(x);
}

Making Recursion relation.
T(n) = T(n -1) + 1 + 1
T(n) = T(n -1) + 2

T(n) = [
    1        n=0
    T(n-1)+1  n>0    // change 2 constant to 1
            ]

 We can solve it by using induction method or successive subsisitution method.
 Let's subsitute it




 T(n) = T(n -1)+1 ------ 1st equation
 ------------------------------------------------
Because,
T(n) = T(n -1)+1
T(n-1) = T(n-2)+1
-------------------------------------------------
 T(n) = T(n-2)+1+1 
 T(n) = T(n-2)+2 -------- 2nd equation
 Similarly,
 T(n) = T(n-3)+3 --------- 3rd equation

 So upto k,

 T(n) = T(n-k)+k --------- 4th equation

Assume n-k = 0 therefore, n = k

T(n) = T(n-n)+n 
T(n) = T(0)+n 
T(n) = 1+n

SO finally O(n)

Same as we get from tracing.


*/