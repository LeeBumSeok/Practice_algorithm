#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int input[N];
    double result = 0.0;
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
        result += input[i];
    }

    double max = *max_element(input, input + N);

    result = (result / max * 100) / N;

    cout << fixed;
    cout.precision(8);
    cout << result;

    return 0;
}