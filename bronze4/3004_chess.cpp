#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    cout << ((N - N / 2) + 1)  * ((N / 2) + 1) << endl;
}