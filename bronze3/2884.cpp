#include <iostream>
using namespace std;

int main()
{
    int H, M;
    cin >> H >> M;

    if (M >= 45)
    {
        M -= 45;
    }
    else
    {
        M = 60 - 45 + M;

        if (H == 0)
            H = 23;
        else
            H--;
    }

    cout << H << " " << M;
}