#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 1001

int DFA[MAX_SIZE][MAX_SIZE];
int patLength, txtLength, R = 3;

void constructDFA(string pattern) {
    DFA[pattern[0]][0] = 1;
    int X, j;
    for (X = 0, j = 1; j < patLength; j++) {
        for (int c = 65; c < 68; c++) DFA[c][j] = DFA[c][X];
        DFA[pattern[j]][j] = j + 1;
        X = DFA[pattern[j]][X];
    }
    for (int c = 65; c < 68; c++) DFA[c][patLength] = DFA[c][X];
}

int DFAmatching(string text) {
    int result = 0;
    int i, j;
    for (i = 0, j = 0; i < txtLength; i++) {
        j = DFA[text[i]][j];  // text[i] to be modified
        if (j == patLength) result++;
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int res = 0;

        string pattern, text;
        cin >> pattern >> text;

        patLength = pattern.length();
        txtLength = text.length();

        for (int i = 0; i < MAX_SIZE; i++) {
            for (int j = 0; j < MAX_SIZE; j++) {
                DFA[i][j] = 0;
            }
        }

        constructDFA(pattern);
        int result = DFAmatching(text);

        for (int i = 0; i < MAX_SIZE; i++) {
            for (int j = 0; j < MAX_SIZE; j++) {
                if (DFA[i][j] != 0) {
                    res++;
                }
            }
        }

        cout << res << " " << result << endl;
    }
    return 0;
}