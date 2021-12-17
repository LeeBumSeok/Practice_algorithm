#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    stack<int> s;

    for (int i = 0; i < N; i++) {
        string input;
        int num;
        cin >> input;

        if (input == "push") {
            cin >> num;
            s.push(num);
        } else if (input == "pop") {
            if (s.empty())
                cout << -1 << endl;
            else {
                cout << s.top() << endl;
                s.pop();
            }
        } else if (input == "size")
            cout << s.size() << endl;
        else if (input == "empty") {
            if (s.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        } else if (input == "top") {
            if (s.empty())
                cout << -1 << endl;
            else
                cout << s.top() << endl;
        }
    }

    return 0;
}