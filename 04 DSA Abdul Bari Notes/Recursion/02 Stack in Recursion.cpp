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
func1 stack ==> 1  
func1 stack ==> 2
main stack==> x = 3; 


Here n is 3 and activation record is 4
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
func1 stack ==> 1  // condition true but now after returning it execute its remaining statements. here is 1 and then end
func1 stack ==> 2  // condition true but now after returning it execute its remaining statements here is 2 and then end
main stack==> x = 3;  // condition true but now after returning it execute its remaining statements here is 3 and then end



Here n is 3 and activation record is 4
So formula is n+1 is the call (activation record will be made)
Degree: O(n)

*/