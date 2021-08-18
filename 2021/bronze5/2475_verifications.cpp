#include <iostream>

using namespace std;

int main()
{
    int a;

    int result = 0;

    for (int i = 0; i < 5; i++)
    {
        cin >> a;
        result += (a * a);
    }

    cout << result % 10;
}