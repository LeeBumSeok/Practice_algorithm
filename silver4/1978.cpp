#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int isPrime(int n) {
    if (n <= 1) return 0;

    if (n % 2 == 0) return n == 2 ? 1 : 0;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n, result = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n; i++)
        if (isPrime(v[i])) result++;

    cout << result << endl;

    return 0;
}