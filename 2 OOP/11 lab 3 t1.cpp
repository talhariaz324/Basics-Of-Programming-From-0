/*Develop a C++ class called PrimeNumberGenerator. An object of this class will generate successive prime
numbers on request. Think of the object as being similar to the digital tasbeeh counter. It has a reset button
which makes the counter return to 0. There is also a button to get the next prime number. On the tasbeeh,
pressing this button increments the current value of the counter. In your object, pressing this button would
generate the next prime number for display. You’ll implement the reset button as a member function
reset() and the other button as a function getNextPrime(). When an object is first created and the
getNextPrime() function is called, it will return the first prime number, i.e., 2. Upon subsequent calls to the
getNextPrime() function, the subsequent prime numbers will be returned. Define any others functions such
as constructor and attributes that you need.
According to Wikipedia: “a prime number is a natural number greater than 1, that has no
positive divisors other than 1 and itself.”*/

#include <iostream>
using namespace std;

class PrimeNumberGenerator
{
    int counter = 0;
    int menuOp;

public:
    int menu();
    void getNextPrime();
    void reset();
};

int PrimeNumberGenerator ::menu()
{
    int check = 0;

    cout << "Enter 1 If you want to reset" << endl;
    cout << "Enter 2 If you want to increment" << endl;
    if (check == 0)
    {
        cout << "Enter -1 to exit" << endl;
        cout << "Counter " << counter << endl;
    }
    check++;
    cin >> menuOp;

    return menuOp;
}

void PrimeNumberGenerator ::getNextPrime()
{
    if (counter < 1)
        counter = 1;
    for (int i = counter + 1;; i++)
    {
        bool prime = true;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
        {
            counter = i;
            break;
        }
    }
    cout << "Counter : " << counter << endl;
    // return counter;2
}
void PrimeNumberGenerator ::reset()
{
    counter = 0;
}
int main()
{
    PrimeNumberGenerator obj;
    do
    {

        int a = obj.menu();

        switch (a)
        {
        case 1:
            obj.reset();
            break;
        case 2:
            obj.getNextPrime();
            break;
        case -1:
            exit(1);
            break;

        default:
            break;
        }
    } while (1);
    return 1;
}