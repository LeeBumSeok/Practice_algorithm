#include <iostream>

using namespace std;

int main()
{
    string str;
    int n;
    cin >> str >> n;
    string dic[n];

    for (int i = 0; i < n; i++)
    {
        cin >> dic[i];
    }

    int len = str.length();

    for (int i = 0; i < 26; i++)
    {
        string temp = "";
        for (int j = 0; j < len; j++)
        {
            temp += (str[j] - 'a' + i) % 26 + 'a';
        }

        for (int k = 0; k < n; k++)
        {
            if (temp.find(dic[k]) != string::npos)
            {
                cout << temp;
                break;
            }
        }
    }

    return 0;
}