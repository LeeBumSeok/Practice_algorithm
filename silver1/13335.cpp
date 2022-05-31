#include <iostream>
#include <queue>

using namespace std;

int shortTime(int n, int w, int L, queue<int> &q) {
    queue<pair<int, int> > tmp;  // t는 다리 위에 있는 트럭들의 위치, 무게
    int time = 0;                // time은 걸린 시간
    while (!q.empty() || !tmp.empty()) {
        int weight = 0;  // weight는 현재 다리 하중

        for (int i = 0; i < tmp.size(); i++) {
            if (!tmp.empty()) {
                int ct = tmp.front().first;
                int cw = tmp.front().second;
                tmp.pop();

                weight += cw;
                tmp.push(make_pair(ct - 1, cw));
            }
        }
        if (!tmp.empty() && tmp.front().first == 0) {
            weight -= tmp.front().second;
            tmp.pop();
        }

        if (!q.empty() && weight + q.front() <= L && tmp.size() < w) {
            weight += q.front();
            tmp.push(make_pair(w, q.front()));
            q.pop();
        }

        time++;
    }

    return time;
}

int main() {
    int n, w, L,
        a;  // n은 다리를 건너는 트럭의 수, w는 다리의 길이, L은 다리의 최대하중
    queue<int> q;  // q는 트럭들의 무게
    cin >> n >> w >> L;
    for (int i = 0; i < n; i++) {
        cin >> a;
        q.push(a);
    }

    cout << shortTime(n, w, L, q) << endl;
    return 0;
}