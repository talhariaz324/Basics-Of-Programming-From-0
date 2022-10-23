/*Implement a class RandomNumberGenerator that has number as a data member. It has two
member functions named as int GetRandom10 (); and int GetRandom30 ();. First one generates
random number between 0-10. Second one generates random number between 0-30. Main function
should call appropriate functions of class to generate 5 random numbers lying in the range (0-10)
and 5 random numbers lying in the range (0-30). This should all be done by calling the functions of
the class RandomNumberGenerator. The program should then display in main() the maximum
number out of these 10 generated random numbers.
Hint: You can store the 10 generated random numbers in an array and then find maximum value
from this array.*/

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class RandomNumberGenerator
{
    int number;

public:
    int getRandom10()
    {

        return rand() % 10;
    }
    int getRandom30()
    {

        return rand() % 30;
    }
    int getMax(int arr[8])
    {
        for (int i = 0; i < 8; i++)
        {
            if (arr[0] < arr[i])
            {
                arr[0] = arr[i];
            }
        }
        return arr[0];
    }
};

int main()
{
    int arr[8] = {};
    //  Srand (a built in function) to syncrinise with time in seconds so that it
    // genrates random number everytime
    srand(time(NULL));
    RandomNumberGenerator obj;
    for (int i = 0; i < 4; i++)
    {

        arr[i] = obj.getRandom10();
        cout << "Random numbers generated in the range (0-10): " << arr[i] << endl;
    }
    for (int i = 4; i < 8; i++)
    {

        arr[i] = obj.getRandom30();
        cout << "Random numbers generated in the range (0-30): " << arr[i] << endl;
    }
    cout << "Maximum Number is: " << obj.getMax(arr) << endl;
}
