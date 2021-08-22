#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int A[9];

    for (int i = 0; i < 9; i++)
    {
        cin >> A[i];
    }

    int max;
    max = *max_element(A, A + 9);

    cout << max << endl;

    for (int i = 0; i < 9; i++)
    {
        if (A[i] == max)
        {
            cout << i + 1;
            break;
        }
    }
    return 0;
}