#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int L, P;
    cin >> L >> P;

    int area = L * P;
    int temp;
    queue<int> result;

    for (int i = 0; i < 5; i++)
    {
        cin >> temp;
        result.push(temp - area);
    }

    while (!result.empty())
    {
        cout << result.front() << " ";
        result.pop();
    }

    return 0;
}