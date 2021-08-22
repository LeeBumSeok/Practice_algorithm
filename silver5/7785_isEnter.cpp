#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    set<string> v;
    cin >> n;


    for(int testCase = 0; testCase < n; testCase++) {
        string name;
        string isEnter;

        cin >> name >> isEnter;

        if(isEnter == "enter") v.insert(name);
        if(isEnter == "leave") v.erase(name);
    }
    
    for(auto iter = v.rbegin(); iter != v.rend(); iter++) cout << *iter << "\n";
    return 0;
}