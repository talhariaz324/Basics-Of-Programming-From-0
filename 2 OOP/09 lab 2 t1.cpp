#include <iostream>
using namespace std;

class TollBooth
{
    unsigned int totalCars; // unsigned for zero to positive value while signed consitis negitive and postive
    double totalMoney;

public:
    TollBooth()
    {
        totalCars = 0;
        totalMoney = 0;
    }
    void payingCar()
    {
        cout << "ADDED" << endl
             << endl;
        totalCars++;
        totalMoney = totalMoney + 0.50;
    }
    void noPayCar()
    {
        cout << "ADDED" << endl
             << endl;

        totalCars++;
    }
    void display()
    {
        cout << "Total of car is " << totalCars << endl
             << endl;
        cout << "Total of money is " << totalMoney << endl
             << endl;
    }
    int showMenu()
    {
        int selectedNum;
        cout << "Select from the menu" << endl;
        cout << "1 for Paying Car" << endl;
        cout << "2 for No Paying Car" << endl;
        cout << "3 for Display the Total" << endl;
        cout << "4 to Exit" << endl;
        cin >> selectedNum;
        return selectedNum;
    }
};
int main()
{
    TollBooth obj;

    do
    {
        int get = obj.showMenu();
        switch (get)
        {
        case 1:
            obj.payingCar();
            break;
        case 2:
            obj.noPayCar();
            break;
        case 3:
            obj.display();
            break;
        case 4:
            exit(1);
            break;

        default:
            break;
        }
    } while (1);
    return 1;
}