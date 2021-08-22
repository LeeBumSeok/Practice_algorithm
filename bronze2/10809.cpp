#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;

    for (int i = 0; i < 26; i++)
    {
        int find = str.find((char)i + 'a', 0);
        if (find == string::npos)
            cout << "-1"
                 << " ";
        else
            cout << find << " ";
    }
}