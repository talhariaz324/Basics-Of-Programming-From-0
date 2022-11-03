/*
Let's take example:
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


Memory: has the code.
Also has stack
Also has heap.

Now discuss stack
        Stack has main and other function activation record.
func1 stack ==> 0  // condition false so end by calling its parent.
func1 stack ==> 1  // condition true but now before calling it execute its statements. here is print 1 and then call
func1 stack ==> 2  // condition true but now before calling it execute its statements. here is print 2 and then call
func1 stack ==> 3  // condition true but now before calling it execute its statements. here is print 3 and then call
main stack==> x = 3; 


NOTE: Stack activation record for each func call is created and store its n value. Before statements are the print statements. so it will print in ascending order

Here n is 3 and activation record is 4, leaving the main activation record
So formula is n+1 is the call (activation record will be made)
Degree: O(n)

*/

// Now take in return

/*
Let's take example:
void func1(int n) {
    if(n > 0){
    func1(n-1);
    cout << x <<endl;
    }
}

int main(){
    int x = 3;
    func1(x);
}


Memory: has the code.
Also has stack
Also has heap.

Now discuss stack
        Stack has main and other function activation record.
func1 stack ==> 0  // condition false so end by calling its parent.
func1 stack ==> 1  // condition true but now after returning it execute its remaining statements. here is print 1 and then end
func1 stack ==> 2  // condition true but now after returning it execute its remaining statements here is print 2 and then end
func1 stack ==> 3  // condition true but now after returning it execute its remaining statements here is print 2 and then end
main stack==> x = 3; 

NOTE: Stack activation record for each func call is created and store its n value. Remaining statements are the print statements. so it will print in descending order



Here n is 3 and activation record is 4, leaving the main activation record
So formula is n+1 is the call (activation record will be made)
Degree: O(n)

*/