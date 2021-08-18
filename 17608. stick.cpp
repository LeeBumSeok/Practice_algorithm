#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    int h[N];
    vector<int> v;
    
    int result = 1;

    for(int i = 0; i < N; i++) cin >> h[i];

    int high = h[N - 1];

    for(int i = N - 2; i >= 0; i--) {
        if(h[i] > high) {
            result++;
            high = h[i];
        }
    }

    cout << result << endl;
}