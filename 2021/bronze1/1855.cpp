#include <iostream>
using namespace std;

int main()
{
    int K;
    cin >> K;

    string str;
    cin >> str;

    bool flag = false;
    int row = 0;
    int col = 0;

    string password[str.length() / K][K];

    for (int i = 0; i < str.length(); i++)
    {
        password[row][col] = str[i];
        if (flag == false)
        {
            col++;
        }
        else
        {
            col--;
        }

        if (i % K == K - 1)
        {
            if (flag == false)
            {
                col--;
            }
            else
            {
                col++;
            }
            flag = !flag;
            row++;
        }
    }

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < str.length() / K; j++)
        {
            cout << password[j][i];
        }
    }
}