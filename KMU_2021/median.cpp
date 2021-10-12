#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

int calc(priority_queue<int, vector<int>, greater<int>> &min_heap, priority_queue<int, vector<int>, less<int>> &max_heap, int num) {
    if ((max_heap.size() + min_heap.size()) % 2 == 0) {
        if (min_heap.empty())
            max_heap.push(num);
        else {
            if (min_heap.top() <= num) {
                int tmp = min_heap.top();
                min_heap.pop();
                min_heap.push(num);
                num = tmp;
            }
            max_heap.push(num);
        }

    } else {
        if (max_heap.top() > num) {
            int tmp = max_heap.top();
            max_heap.pop();
            max_heap.push(num);
            num = tmp;
        }
        min_heap.push(num);
    }

    if ((max_heap.size() + min_heap.size()) % 2 == 0)
        return (min_heap.top() + max_heap.top()) / 2;
    else
        return max_heap.top();
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        unsigned long long answer = 0;
        cin >> n;

        priority_queue<int, vector<int>, greater<int>> min_heap;
        priority_queue<int, vector<int>, less<int>> max_heap;

        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;

            answer += calc(min_heap, max_heap, num);
        }

        cout << answer % 10 << "\n";
    }
}