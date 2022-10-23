/*Assume you have to write a program for a cricket game. There are two teams and each team has a
 value for score and wicket. You are required to design a class Team that has relevant member
 functions for setting the score and wickets value and for getting these values too. The score and
 wicket of both the teams should be taken as an input from the user in main(). The main function
 should interact with the class Team to set and get values. */

#include <iostream>
using namespace std;

class Team
{

    int score, wicket;

public:
    void setVal(int s1, int w1)
    {

        score = s1;

        wicket = w1;
    }
    int getScore()
    {

        return score;
    }

    int getWicket()
    {

        return wicket;
    }
};

int main()
{

    int uScore1, uScore2, uWicket1, uWicket2;

    Team t1;

    Team t2;

    cout << "Enter Score of team no 1" << endl;

    cin >> uScore1;

    cout << "Enter Score of team no 2" << endl;

    cin >> uScore2;

    cout << "Enter Wicket of team no 1" << endl;

    cin >> uWicket1;

    cout << "Enter Wicket of team no 2" << endl;

    cin >> uWicket2;

    t1.setVal(uScore1, uWicket1);

    cout << "Score of Team 1 is " << t1.getScore()

         << " and Wicket of Team 1 is " << t1.getWicket()

         << endl;

    t2.setVal(uScore2, uWicket2);

    cout << "Score of Team 2 is " << t2.getScore()

         << " and Wicket of Team 2 is " << t2.getWicket()

         << endl;
}
