#include <iostream>
#include <ctime>
using namespace std;

int main(void)
{
    time_t curr_time;
    struct tm *curr_tm;

    curr_time = time(NULL);
    curr_tm = localtime(&curr_time);

    cout << curr_tm->tm_year + 1900 << "-";
    if (curr_tm->tm_mon + 1 < 10)
    {
        cout << "0" << curr_tm->tm_mon + 1;
    }
    else
    {
        cout << curr_tm->tm_mon + 1;
    }
    cout << "-" << curr_tm->tm_mday << endl;
}