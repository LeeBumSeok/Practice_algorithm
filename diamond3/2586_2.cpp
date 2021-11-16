#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 200000;
int P, F, pos = MAX;
pair<int, int> p[MAX];
vector<pair<int, int>> dp[MAX * 2];

int main() {
    int answer = 0;

    scanf("%d %d", &P, &F);
    for (int i = 0; i < P; i++) scanf("%d", &p[i].first), p[i].second = 0;      // 펌프
    for (int i = P; i < P + F; i++) scanf("%d", &p[i].first), p[i].second = 1;  // 소방차

    sort(p, p + P + F);  // 오름차순 정렬

    // 1차원 좌표계 표현
    // 소방차가 들어오면 현재의 위치 - 1에 넣기, 펌프가 들어오면 현재의 위치에 넣고 위치 + 1
    for (int i = 0; i < P + F; i++) p[i].second ? dp[--pos].push_back(p[i]) : dp[pos++].push_back(p[i]);

    for (int i = 0; i < MAX * 2; i++) {
        int s = 0, m;

        // 앞에서부터 펌프와 소방차 사이의 호스 길이 계산
        for (int j = 1; j < dp[i].size(); j += 2) s += dp[i][j].first - dp[i][j - 1].first;

        m = s;
        // 뒤에서부터 펌프와 소방차 사이의 호스 길이 계산
        if (dp[i].size() & 1) {
            for (int j = dp[i].size() - 1; j > 1; j -= 2) {
                // 최소 호스 길이 구하기
                m = min(m, s += dp[i][j].first - dp[i][j - 1].first * 2 + dp[i][j - 2].first);
            }
        }
        answer += m;
    }

    printf("%d", answer);
    return 0;
}