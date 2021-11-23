#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int P, F;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    int answer = 0, num;

    cin >> P >> F;
    for (int i = 0; i < P; i++) cin >> num, pq.push(make_pair(num, 0));
    for (int i = 0; i < F; i++) cin >> num, pq.push(make_pair(num, 1));

    int pos = P + F;
    vector<pair<int, int>> dp[(P + F) * 2];

    while (!pq.empty()) {
        if (pq.top().second) {
            dp[--pos].push_back(pq.top());
            // cout << pos << endl;
        }

        else {
            dp[pos++].push_back(pq.top());
            // cout << pos << endl;
        }

        // cout << pos << endl;
        pq.pop();
    }

    for (int i = 0; i < (P + F) * 2; i++) {
        int s = 0, m;
        if (dp[i].size() % 2) {
            cout << dp[i].size() << endl;
            for (int j = 0; j < dp[i].size(); j++) cout << dp[i][j].first << endl;
        }

        for (int j = 1; j < dp[i].size(); j += 2) s += dp[i][j].first - dp[i][j - 1].first;
        m = s;
        if (dp[i].size() % 2) {
            for (int j = dp[i].size() - 1; j > 1; j -= 2) {
                m = min(m, s += dp[i][j].first - dp[i][j - 1].first * 2 + dp[i][j - 2].first);
            }
        }
        answer += m;
    }

    cout << answer;
    return 0;
}
