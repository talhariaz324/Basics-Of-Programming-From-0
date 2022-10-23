/*
Create a class called Date that includes three pieces of information as data members—a month (type
int), a day (type int) and a year (type int). Your class should have a constructor with three
parameters that uses the parameters to initialize the three data members. For the purpose of this
exercise, assume that the values provided for the year and day are correct, but ensure that the
month value is in the range 1–12; if it isn’t, set the month to 1. Provide a set and a get function for
each data member. Provide a member function displayDate that displays the month, day and year
separated by forward slashes (/). Write a test program that demonstrates class Date’s capabilities
*/
#include <iostream>
using namespace std;

class Date
{
    int month, day, year;

public:
    Date()
    {
    }
    Date(int mo, int dy, int yr)
    {
        month = mo;
        day = dy;
        year = yr;
    }
    int setMonth()
    {
        int mo1;
        cout << "Enter the month" << endl;
        cin >> mo1;
        if (mo1 <= 12)
        {

            return mo1;
        }
        else
        {
            return 1;
        }
    }
    int setDay()
    {
        int dy1;
        cout << "Enter the day" << endl;
        cin >> dy1;
        return dy1;
    }
    int setYear()
    {
        int yr1;
        cout << "Enter the year" << endl;
        cin >> yr1;
        return yr1;
    }
    int getMonth()
    {
        return month;
    }
    int getDay()
    {
        return day;
    }
    int getYear()
    {
        return year;
    }
    void displayDate()
    {
        cout << "Date is: " << getMonth() << "/" << getDay() << "/" << getYear() << endl;
    }
};
int main()
{
    Date obj;
    Date obj1(obj.setMonth(), obj.setDay(), obj.setYear());

    obj1.displayDate();
}