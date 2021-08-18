#include <iostream>
#include <cmath>

using namespace std;

int main() {
    unsigned long long n, result;
    cin >> n;
    result = sqrt(n);

    if(result != n) result++;
    
    cout << result << endl;
}