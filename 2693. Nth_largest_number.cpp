#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for(int TestCase = 0; TestCase < T; TestCase++) {
        int A[10];
        for(int i = 0; i < 10; i++) cin >> A[i];

        sort(A, A + 10);

        cout << A[7] << "\n";
    }
}