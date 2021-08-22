#include <iostream>
using namespace std;

int main()
{
    int A;
    int result = 1;

    for (int i = 0; i < 3; i++)
    {
        cin >> A;
        result *= A;
    }

    string string_A;
    string_A = to_string(result);
    int num_count[10];

    for (int i = 0; i < 10; i++)
    {
        num_count[i] = 0;
    }

    for (int i = 0; i < string_A.length(); i++)
    {
        num_count[(int)string_A[i] - '0']++;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << num_count[i] << endl;
    }

    return 0;
}