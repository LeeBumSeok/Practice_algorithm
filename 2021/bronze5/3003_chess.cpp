#include <iostream>
using namespace std;

int main()
{
    int piece[6] = {1, 1, 2, 2, 2, 8};
    int input[6];
    int result[6];

    for (int i = 0; i < 6; i++)
    {
        cin >> input[i];
        result[i] = piece[i] - input[i];
    }

    for (int j = 0; j < 6; j++)
    {
        cout << result[j] << " ";
    }

    return 0;
}