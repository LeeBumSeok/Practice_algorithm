#include <iostream>

using namespace std;

int main() {
    int fix, variable, each;

    cin >> fix >> variable >> each;
    
    if(variable >= each) cout << -1 << endl;
    else cout << fix / (each - variable) + 1 << endl;
}