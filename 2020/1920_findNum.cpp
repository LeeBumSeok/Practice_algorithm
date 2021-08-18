#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    set<int> A;
    int N, M, temp;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        A.insert(temp);
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> temp;
        if(A.find(temp) == A.end()) cout << 0 << "\n";
        else cout << 1 << "\n";
    }

    return 0;
}