#include <iostream>
using namespace std;

int main()
{
    string A;
    getline(cin, A);

    int result = 1;
    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == ' ')
        {
            result++;
        }
    }

    if (A[0] == ' ')
        result--;
    if (A[A.length() - 1] == ' ')
        result--;

    cout << result;

    return 0;
}