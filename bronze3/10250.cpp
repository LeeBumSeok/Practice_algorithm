#include <iostream>

using namespace std;

int main() {
    int T, H, W, N, floor, num, result;

    cin >> T;

    while (T--) {
        cin >> H >> W >> N;

        if (!(N % H))
            cout << H * 100 + N / H << '\n';
        else
            cout << N % H * 100 + (N / H + 1) << endl;
    }

    return 0;
}