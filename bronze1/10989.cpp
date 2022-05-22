#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    cin >> N;
    vector<int> numList(10001);

    for (int i = 0; i < N; i++) {
        cin >> num;
        numList[num]++;
    }

    for (int i = 1; i <= 10000; i++)
        for (int j = 0; j < numList[i]; j++) cout << i << "\n";

    return 0;
}