#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int row = 1; row <= N; row++)
    {
        for (int i = 0; i < N - row; i++)
            cout << ' ';

        for (int i = 0; i < row; i++)
            cout << '*';

        cout << endl;
    }
    return 0;
}