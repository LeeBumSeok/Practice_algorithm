#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::vector<int> data = {1, 2, 3, 3, 3, 3, 5, 5, 6};
    data.erase(data.begin() + 0);

    cout << data[0] << endl;
}