#include <iostream>
#include <string>
using namespace std;

int main()
{
    int A;
    cin >> A;

    string B;
    cin >> B;
    int result = 0;
    for (int i = 0; i < A; i++)
        result += B[i] - 48;

    cout << result;
    return 0;
}