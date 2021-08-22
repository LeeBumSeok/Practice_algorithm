#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int max = -1000000;
    int min = 1000000;
    int input;

    for (int i = 0; i < N; i++)
    {
        cin >> input;

        if (input > max)
        {
            max = input;
        }

        if (input < min)
        {
            min = input;
        }
    }

    cout << min << " " << max;
}