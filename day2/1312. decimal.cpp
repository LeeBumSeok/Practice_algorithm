#include <iostream>

using namespace std;

int main() {
    int A, B, N, tmp, result;
    cin >> A >> B >> N;

    tmp = A % B;

    for(int i = 0; i < N; i++) {
        tmp *= 10;
        result = tmp / B;
        tmp %= B;
    }
    cout << result << endl;
}