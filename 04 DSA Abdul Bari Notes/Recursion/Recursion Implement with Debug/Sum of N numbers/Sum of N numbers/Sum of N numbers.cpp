
#include <iostream>
using namespace std;
int sum(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return  sum(n - 1) + n;
    }
}



int main()
{
    int r = 0, y = 0;
    r = sum(5);
 //   y = sumLoop(5);
    cout << r << endl;
    cout << y << endl;
}