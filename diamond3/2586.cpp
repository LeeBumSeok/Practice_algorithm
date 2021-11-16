#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int p, f, answer = 0;
    cin >> p >> f;

    vector<int> pump(p);
    vector<int> firetruck(f);

    for (int i = 0; i < p; i++) cin >> pump[i];
    for (int i = 0; i < f; i++) cin >> firetruck[i];

    int idx = p - 1;

    for (int i = 0; i < f; i++) {
        int s = lower_bound(pump.begin(), pump.end(), firetruck[i]) - pump.begin();
        if (s > 0 && s < p) {
            if (abs(pump[s] - firetruck[i]) < abs(pump[s - 1] - firetruck[i])) {
                answer += pump[s] - firetruck[i];
                pump.erase(pump.begin() + s);
                p--;
            } else {
                answer += abs(pump[s - 1] - firetruck[i]);
                pump.erase(pump.begin() + s - 1);
                p--;
            }
        } else if (s == 0) {
            answer += abs(pump[s] - firetruck[i]);
            pump.erase(pump.begin() + s);
            p--;
        } else if (s >= p) {
            answer += abs(firetruck[i] - pump[p - 1]);
            pump.erase(pump.begin() + p - 1);
            p--;
        }
    }

    cout << answer << endl;

    return 0;
}