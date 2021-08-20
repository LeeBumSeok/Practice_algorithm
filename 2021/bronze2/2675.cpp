#include <iostream>
using namespace std;

int main()
{
    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int j;
        cin >> j;
        string str;
        cin >> str;

        for (int k = 0; k < str.length(); k++)
        {
            for (int m = 0; m < j; m++)
            {
                cout << str[k];
            }
        }
        cout << endl;
    }
    return 0;
}