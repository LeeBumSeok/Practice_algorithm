#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int result = 0;
    while (x > 0)
    {
        result += month[x - 1];
        x--;
    }

    result += y;

    if (result % 7 == 1)
        cout << "MON"
             << "\n";
    else if (result % 7 == 2)
        cout << "TUE"
             << "\n";
    else if (result % 7 == 3)
        cout << "WED"
             << "\n";
    else if (result % 7 == 4)
        cout << "THU"
             << "\n";
    else if (result % 7 == 5)
        cout << "FRI"
             << "\n";
    else if (result % 7 == 6)
        cout << "SAT"
             << "\n";
    else if (result % 7 == 0)
        cout << "SUN"
             << "\n";

    return 0;
}