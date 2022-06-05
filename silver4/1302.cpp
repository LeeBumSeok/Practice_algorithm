#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> bookList;
    string title;
    for (int i = 0; i < N; i++) {
        cin >> title;
        bookList[title] += 1;
    }

    int count = 0;
    map<string, int>::iterator iter;
    for (iter = bookList.begin(); iter != bookList.end(); iter++) {
        if (count < iter->second) {
            title = iter->first;
            count = iter->second;
        }
    }
    cout << title << endl;
    return 0;
}