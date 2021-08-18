#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long divide(int n, int d) {
    int value = 0;

    for(long long i = d; i <= n; i *= d) value += (n / i);

    return value;
}

int main() {
    unsigned long long n, m, result;
    cin >> n >> m;

    int two, five;
    two = 0, five = 0;

    two += divide(n, 2);
    two -= divide(m, 2);
    two -= divide(n - m, 2);

    five += divide(n, 5);
    five -= divide(m, 5);
    five -= divide(n - m, 5);

    cout << min(two, five) << "\n";
    
}