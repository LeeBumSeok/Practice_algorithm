#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string findPassword(const string L) {
    stack<char> s, tmp;
    for (int i = 0; i < L.size(); i++) {
        if (L[i] == '<') {
            if (s.empty())
                continue;
            else {
                tmp.push(s.top());
                s.pop();
            }
        } else if (L[i] == '>') {
            if (tmp.empty())
                continue;
            else {
                s.push(tmp.top());
                tmp.pop();
            }
        } else if (L[i] == '-') {
            if (s.empty())
                continue;
            else
                s.pop();
        } else
            s.push(L[i]);
    }
    while (!tmp.empty()) {
        s.push(tmp.top());
        tmp.pop();
    }

    string password;
    while (!s.empty()) {
        password += s.top();
        s.pop();
    }
    return password;
}

int main() {
    int t;
    string L;
    cin >> t;
    while (t--) {
        cin >> L;
        string password = findPassword(L);
        reverse(password.begin(), password.end());
        cout << password << endl;
    }
    return 0;
}