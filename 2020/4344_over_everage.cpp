#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int C, N;

    cin >> C;

    for(int testcase = 0; testcase < C; testcase++) {
        cin >> N;
        int score[N];
        int everage = 0;
        int result = 0;
        for(int i = 0; i < N; i++) {
            cin >> score[i];
            everage += score[i];
        }

        everage /= N;

        for(int i = 0; i < N; i++) {
            if(score[i] > everage) result++;
        }

        printf("%.3f%%\n", (double) result / (double) N * 100);
    }   
    return 0;
}