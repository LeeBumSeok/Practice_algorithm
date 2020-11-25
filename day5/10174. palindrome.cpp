#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for(int testCase = 0; testCase < n; testCase++) {
        string str;
        getline(cin, str);
        string result = "Yes";
        for(int i = 0; i < str.length(); i++) str[i] = toupper(str[i]);
        char tmp[str.length() / 2];

        for(int j = 0; j < str.length() / 2; j++) tmp[j] = str[str.length() - j - 1];

        for(int k = 0; k < str.length() / 2; k++) if(tmp[k] != str[k]) result = "No";

        cout << result << endl;
    }
    return 0;
}