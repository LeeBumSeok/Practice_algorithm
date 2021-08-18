#include <iostream>

using namespace std;

int main() {
    int TestCase;
    cin >> TestCase;

    for(int test = 0; test < TestCase; test++) {
        string result;
        cin >> result;
        int tmp = 1;
        int score = 0;

        for(int i = 0; i < result.length(); i++) {
            if(result[i] == 'O') {
                score += tmp;
                tmp++;
            }
            else if(result[i] == 'X') tmp = 1;
        }

        cout << score << endl;
    }
}