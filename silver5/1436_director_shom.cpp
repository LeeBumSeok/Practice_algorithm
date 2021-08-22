#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int cnt = 0;
    string tmp;
    for (int i = 666; i; i++)
    {
        tmp = to_string(i);

        if (tmp.find("666") != string::npos)
            cnt++;

        if (cnt == N)
        {
            cout << i << endl;
            break;
        }
    }
}