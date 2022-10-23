#include <iostream>
using namespace std;

class ScheduleJob
{
    int jobId1, jobId2, jobId3, deadLine1, deadLine2, deadLine3;

public:
    void setVal(int id1, int id2, int id3, int dL1, int dL2, int dL3)
    {
        jobId1 = id1;
        jobId2 = id2;
        jobId3 = id3;
        deadLine1 = dL1;
        deadLine2 = dL2;
        deadLine3 = dL3;
    }

    int scheduledJob1()
    {
        if (deadLine1 < deadLine2 && deadLine1 < deadLine3)
        {
            return jobId1;
        }
        else if (deadLine2 < deadLine1 && deadLine2 < deadLine3)
        {
            return jobId2;
        }
        else
        {
            return jobId3;
        }
    }
    int scheduledJob2()
    {
        if (scheduledJob1() == jobId1)
        {
            if (deadLine2 < deadLine3)
            {
                return jobId2;
            }
            else
            {
                return jobId3;
            }
        }
        if (scheduledJob1() == jobId2)
        {
            if (deadLine1 < deadLine3)
            {
                return jobId1;
            }
            else
            {
                return jobId3;
            }
        }
        if (scheduledJob1() == jobId3)
        {
            if (deadLine1 < deadLine2)
            {
                return jobId1;
            }
            else
            {
                return jobId2;
            }
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    int jobId1, jobId2, jobId3, deadLine1, deadLine2, deadLine3;
    cout << "Enter job 1 id" << endl;
    cin >> jobId1;
    cout << "Enter job 2 id" << endl;
    cin >> jobId2;
    cout << "Enter job 3 id" << endl;
    cin >> jobId3;
    cout << "Enter deadline of job 1 " << endl;
    cin >> deadLine1;
    cout << "Enter deadline of job 2 " << endl;
    cin >> deadLine2;
    cout << "Enter deadline of job 3 " << endl;
    cin >> deadLine3;
    ScheduleJob obj1;
    obj1.setVal(jobId1, jobId2, jobId3, deadLine1, deadLine2, deadLine3);
    cout << "Earliest deadline of job is " << obj1.scheduledJob1() << endl;
    cout << "2nd Earliest deadline of job is " << obj1.scheduledJob2() << endl;
}