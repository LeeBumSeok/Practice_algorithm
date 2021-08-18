#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    unsigned int N;
    cin >> N;
    int divisor[N];

    for(int i = 0; i < N; i++) cin >> divisor[i];
    sort(divisor, divisor + N);
    cout << divisor[0] * divisor[N - 1] << endl;

    return 0;
}