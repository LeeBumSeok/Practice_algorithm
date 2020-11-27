#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int diagonal, height, width;
    double c;

    cin >> diagonal >> height >> width;
    c = sqrt(pow(height, 2) + pow(width, 2));

    cout << (int) (height * diagonal / c) << " " << (int) (width * diagonal / c) << endl;
}