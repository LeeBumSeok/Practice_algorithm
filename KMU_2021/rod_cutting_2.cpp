#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int calc(int start, int end, vector<int> Lk, vector<vector<int>> &dp) {
    if (dp[start][end] != INT_MAX) return dp[start][end];
    bool flag = false;
    int val = INT_MAX;

    for (int i = 0; i < Lk.size(); i++) {
        if (start < Lk[i] && Lk[i] < end) {
            flag = true;
            break;
        }
    }

    if (!flag)
        return 0;
    else {
        for (int i = 0; i < Lk.size(); i++)
            if (start < Lk[i] && Lk[i] < end)
                val = min(val, (end - start) + calc(start, Lk[i], Lk, dp) + calc(Lk[i], end, Lk, dp));

        dp[start][end] = val;
        return val;
    }
}

int main() {
    int t, k, L;

    cin >> t;

    while (t--) {
        cin >> L >> k;
        vector<int> Lk(k);
        for (int i = 0; i < k; i++) cin >> Lk[i];

        vector<vector<int>> dp(L + 1, vector<int>(L + 1, INT_MAX));

        cout << calc(0, L, Lk, dp) << endl;
    }

    return 0;
}