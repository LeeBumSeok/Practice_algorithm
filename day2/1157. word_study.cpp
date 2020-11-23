#include <iostream>

using namespace std;

int main() {
    string word;
    int alphabet[26];
    int big = 0;
    int cnt;

    cin >> word;
    
    for(int i = 0; i < 26; i++) alphabet[i] = 0;

    for(int i = 0; i < word.length(); i++) {
        word[i] = toupper(word[i]);
        alphabet[(int)(word[i] - 65)]++;
    }

    for(int i = 0; i < 26; i++) {
        if(alphabet[i] > big) {
            big = alphabet[i];
            cnt = i;
        }
    }

    for(int i = 0; i < 26; i++) {
        if(i != cnt) {
            if(alphabet[i] == big) {
                cout << "?" << endl;
                return 0;
            }
        }
    }

    char result = cnt + 65;
    cout << result << endl;
    return 0;
}