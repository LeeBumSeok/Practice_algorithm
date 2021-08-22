#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> num;
    int a;

    for (int i = 0; i < 10; i++)
    {
        cin >> a;
        num.insert(a % 42);
    }

    cout << num.size();
}