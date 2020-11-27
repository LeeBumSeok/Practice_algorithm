#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    int temp;

    int result[N + M];

    for(int i = 0; i < N + M; i++) cin >> result[i];
    sort(result, result + N + M);

    for(int i = 0; i < N + M; i++) cout << result[i] << " ";

    cout << "\n";
    return 0;
}