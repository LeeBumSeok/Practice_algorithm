#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;

    string AA = to_string(A);
    string BB = to_string(B);

    reverse(AA.begin(), AA.end());
    reverse(BB.begin(), BB.end());

    A = stoi(AA);
    B = stoi(BB);

    if (A > B)
        cout << A;
    else
        cout << B;
}