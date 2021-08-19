#include <iostream>

using namespace std;

int main()
{
    int a;
    int second = 0;
    int minute = 0;

    for (int i = 0; i < 4; i++)
    {
        cin >> a;
        second += a;
    }

    while (second > 59)
    {
        second -= 60;
        minute++;
    }

    cout << minute << endl
         << second;
}