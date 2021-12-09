#include <iostream>
#include <vector>
using namespace std;

vector<int> fail;
int res;

vector<int> getFail(string pattern) {
    int m = (int)pattern.size();
    int j = 0;
    vector<int> fail(m, 0);
    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) j = fail[j - 1];
        if (pattern[i] == pattern[j])
            fail[i] = ++j;
        else
            fail[i] = j;
    }
    return fail;
}

void kmp(string text, string pattern) {
    fail = getFail(pattern);
    int n = (int)text.size(), m = (int)pattern.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) j = fail[j - 1];
        if (text[i] == pattern[j]) {
            if (j == m - 1) {
                res++;
                j = fail[j];
            } else {
                j++;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        res = 0;
        string text, pattern;
        cin >> pattern >> text;

        getFail(pattern);
        kmp(text, pattern);

        for (int i = 0; i < fail.size(); i++) cout << fail[i] << " ";
        cout << endl << res << endl;
    }
}