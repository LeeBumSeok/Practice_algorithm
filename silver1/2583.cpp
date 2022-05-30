#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int area[101][101];

int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};

int bfs(int a, int b, int M, int N) {
    deque<pair<int, int>> dq;
    dq.push_back({a, b});
    area[a][b] = 1;
    int count = 1;

    while (!dq.empty()) {
        pair<int, int> xy = dq.front();
        dq.pop_front();
        for (int i = 0; i < 4; i++) {
            int tempX = xy.first + moveX[i];
            int tempY = xy.second + moveY[i];

            if (tempX < 0 || tempX >= M || tempY < 0 || tempY >= N) {
                continue;
            }
            if (area[tempX][tempY] == 0) {
                area[tempX][tempY] = 1;
                dq.push_back({tempX, tempY});
                count++;
            }
        }
    }

    return count;
}

int main() {
    int M, N, K, lx, ly, rx, ry;
    cin >> M >> N >> K;

    vector<int> result;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            area[i][j] = 0;
        }
    }

    for (int i = 0; i < K; i++) {
        cin >> lx >> ly >> rx >> ry;
        for (int j = ly; j < ry; j++) {
            for (int k = lx; k < rx; k++) {
                area[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (area[i][j] == 0) {
                result.push_back(bfs(i, j, M, N));
            }
        }
    }

    cout << result.size() << endl;
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}