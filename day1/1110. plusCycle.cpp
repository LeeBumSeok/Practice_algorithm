#include <iostream>

using namespace std;

int main() {
    int input, before, after, tmp, cycle = 0;
    cin >> input;

    tmp = input;

    while(true) {
        before = tmp / 10;
        after = tmp % 10;
        tmp = after * 10 + (before + after) % 10;
        cycle++;

        if(input == tmp) break;
    }

    cout << cycle << endl;
}