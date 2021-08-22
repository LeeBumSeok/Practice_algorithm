#include <iostream>
using namespace std;

int main()
{
    int A[8];

    for (int i = 0; i < 8; i++)
    {
        cin >> A[i];
    }

    int ascending = 0;
    int descending = 0;

    for (int i = 0; i < 8; i++)
    {
        if (A[i] + 1 == A[i + 1])
        {
            ascending++;
        }
        else if (A[i] - 1 == A[i + 1])
        {
            descending++;
        }
    }

    if (ascending == 7)
        cout << "ascending";
    else if (descending == 7)
        cout << "descending";
    else
        cout << "mixed";
}