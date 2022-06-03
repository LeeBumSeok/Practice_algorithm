#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, a, num;
    priority_queue<int> pq;
    cin >> n;
    while (n--) {
        cin >> a;
        if (a != 0) {
            for (int i = 0; i < a; i++) {
                cin >> num;
                pq.push(num);
            }
        } else {
            if (pq.empty()) {
                cout << -1 << endl;
                continue;
            }

            cout << pq.top() << endl;
            pq.pop();
        }
    }
    return 0;
}