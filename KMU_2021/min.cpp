#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, m, c;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        vector<int> coin(m);
        vector<int> dp(n + 1, INT_MAX);

        for (int j = 0; j < m; j++) cin >> coin[j];
        dp[0] = 0;

        for (int j = 0; j < m; j++) {
            for (int k = coin[j]; k <= n; k++) dp[k] = min(dp[k], dp[k - coin[j]] + 1);
        }

        cout << dp[n] << endl;
    }

    return 0;
}