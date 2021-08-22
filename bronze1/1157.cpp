#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string A;

    cin >> A;

    int alpha[26];

    for (int i = 0; i < 26; i++)
    {
        alpha[i] = 0;
    }

    for (int i = 0; i < A.length(); i++)
    {
        A[i] = toupper(A[i]);
        alpha[(int)A[i] - 'A']++;
    }

    int max;
    int flag = 0;
    int index;
    max = *max_element(alpha, alpha + 26);

    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] == max)
        {
            flag++;
            index = i;
        }
    }

    if (flag == 1)
    {
        cout << (char)(index + 'A');
    }
    else
    {
        cout << "?";
    }

    return 0;
}