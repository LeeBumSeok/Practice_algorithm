#include <cmath>
#include <iostream>

using namespace std;

unsigned long long int k;

void hanoi_tower(int n, int a, int b, int c) {
    unsigned long long int tmp = pow(2, n - 1);
    if (n > 0) {
        if (k > tmp) {
            k -= tmp;
            hanoi_tower(n - 1, b, a, c);
        } else if (k < tmp)
            hanoi_tower(n - 1, a, c, b);
        else
            cout << a << " " << c << "\n";
    }
}

int main() {
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        hanoi_tower(n, 1, 2, 3);
    }
}