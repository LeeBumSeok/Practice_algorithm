#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    int tmp[n];
    int max;

    tmp[0] = a[0];
    max = a[0];

    for(int i = 1; i < n; i++) {
        tmp[i] = a[i] < tmp[i - 1] + a[i] ? tmp[i - 1] + a[i] : a[i];
        if(max < tmp[i]) max = tmp[i];
    }
    cout << max << "\n";
}