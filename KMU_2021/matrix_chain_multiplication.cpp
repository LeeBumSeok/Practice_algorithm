#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int calc(int n, vector<int> y, vector<vector<int>> &dp) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            int k = i + j;

            if (j == k) {
                dp[j][k] = 0;
                continue;
            }
            for (int l = j; l <= k - 1; l++)
                dp[j][k] = min(dp[j][k], dp[j][l] + dp[l + 1][k] + y[j - 1] * y[l] * y[k]);
        }
    }
}

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        ++n;
        vector<int> y(n);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 0; i < n; i++) cin >> y[i];

        calc(n, y, dp);
        cout << dp[1][n - 1] << endl;
    }

    return 0;
}