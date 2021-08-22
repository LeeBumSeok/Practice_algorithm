#include <iostream>

using namespace std;

int d(int n) {
    return n + (n / 1000) + (n % 1000) / 100 + (n % 100) / 10 + (n % 10);
}

int main() {
    bool selfNum[10000];
    int num;
    for(int i = 0; i < 10000; i++) selfNum[i] = false;

    for(int i = 1; i < 10000; i++) {
        num = i;
        while(num < 10000) {
            num = d(num);
            if(num <= 10000) selfNum[num - 1] = true;
        }
    }

    for(int i = 0; i < 10000; i++) if(!selfNum[i]) cout << i + 1 << endl;
    
    return 0;
}