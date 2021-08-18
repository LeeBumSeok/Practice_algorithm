#include <iostream>
#include <string>

using namespace std;

int main() {
    string X;

    cin >> X;
    int temp = 0;
    int conversion = 1;

    if(X.length() == 1) {
        cout << conversion - 1 << endl;
        if(stoi(X) % 3 == 0) cout << "YES" << endl;
        else cout << "NO" <<endl;  
        return 0;
    }

    do {
        temp = 0;
        for(int i = 0; i < X.size(); i++) temp += X[i] - '0';
        if(temp >= 10) conversion++;
        X = to_string(temp);
    } while(temp >= 10);

    cout << conversion << endl;
    if(temp % 3 == 0) cout << "YES" << endl;
    else cout << "NO" <<endl;
    
    return 0;
}