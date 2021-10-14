#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int CUT_ROD(int p[], int n) {
    if (n <= 0) {
        return 0;
    }
    int q = INT_MIN;
    for (int i = 0; i < n; i++) {
        q = max(q, p[i] + CUT_ROD(p, n - i - 1));
    }
    return q;
}

int MEMOIZED_CUT_ROD_AUX(int p[], int n, int r[]) {
    if (r[n] >= 0) {
        return r[n];
    }
    int q;
    if (n == 0) {
        q = 0;
    } else {
        q = INT_MIN;
        for (int i = 0; i < n; i++) {
            q = max(q, p[i] + MEMOIZED_CUT_ROD_AUX(p, n - i - 1, r));
        }
    }
    r[n] = q;
    return q;
}

int MEMOIZED_CUT_ROD(int p[], int n) {
    int r[n + 1];
    for (int i = 0; i < n + 1; i++) {
        r[i] = INT_MIN;
    }
    return MEMOIZED_CUT_ROD_AUX(p, n, r);
}

int BOTTOM_UP_CUT_ROD(int p[], int n) {
    int r[n + 1];
    int q;
    r[0] = 0;
    for (int j = 1; j <= n; j++) {
        q = INT_MIN;
        for (int i = 0; i < j; i++) {
            q = max(q, p[i] + r[j - i - 1]);
        }
        r[j] = q;
    }
    return r[n];
}

int Extended_Bottom_Up_Cut_Rod(int p[], int n, int r[], int s[]) {
    int q;
    r[0] = 0;
    s[0] = 0;
    for (int j = 1; j < n + 1; j++) {
        q = INT_MIN;
        for (int i = 0; i < j; i++) {
            if (q < (p[i] + r[j - i - 1])) {
                q = p[i] + r[j - i - 1];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    return q;
}

int main() {
    int p[] = {2, 7, 10, 14, 19, 22, 23, 26, 28, 29};
    int n = 10;

    cout << BOTTOM_UP_CUT_ROD(p, n) << endl;
}