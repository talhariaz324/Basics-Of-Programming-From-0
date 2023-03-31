/*
Recursion: is calling the function itself.
int fun(int n){
    if(n > 0){
        fun(n - 1);
    }
    n++;
    return n;
}
int main( ){
    fun(10) *10; // First recursion done and then multiplication operation will done and move on next statements.
}
*/

/*
Syntax:

type fun (param){
    if(<base condition>){ // base condition is the condition on which recursion terminate otherwise it would infinite.
        fun(param); // itself call
    }
}
*/


/*

For Example:

void func1(int n) {
    if(n > 0){
    cout << x <<endl;
    func1(n-1);
    }
}

int main(){
    int x = 3;
    func1(x);
}
*/

/*
Tracing of recursion is done using tree.

            func1(3)
             /  \
            3   func1(2) ===> 3 > 0
                /  \
               2   func1(1) ===> 2 > 0
               /     \
               1     func1(0) ===> 1 > 0
                       no furthur call because now 0 > 0 .... false.

        After condition false function back to its parents and at the end it reach the main func1 and then main terminates because no more statements.
        
        Output: 3 2 1
*/




/*

Another Example:

void func1(int n) {
    if(n > 0){
    func1(n-1); // here little change
    cout << x <<endl;
    }
}

int main(){
    int x = 3;
    func1(x);
}
*/

/*
Tracing of recursion is done using tree.

            func1(3)
             /  \
3 > 0  func1(2)  3 
             /  \
2 > 0  func1(1)  2
            /     \
1 > 0  func1(0)   1
                       no furthur call because now 0 > 0 .... false.

        Now after false it execute its furture statements like here 1, and then similarly goes for parents.
        
        Output: 1 2 3
*/


/*
Conclusion: Recursion is done by forward and then come back.
This means recursion has 2 phases:
1) Calling (Ascending)
2) Returning (Descending)

For Example:

void func1(int n) {
    if(n > 0){
    Calling (these statements will execute before the function call)
    func1(n-1);
    Returning (these statements will execute after the function call,, because after so that's why starts from last function part)
    }
}

int main(){
    int x = 3;
    func1(x);
}


loop and recursion difference;
loop is repeat but loop is only ascending order
recursion is repeat but recursion is descending order.
*/