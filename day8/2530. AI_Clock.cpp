#include <iostream>

using namespace std;

int main() {
    int hour, minute, second, cook_clock;
    cin >> hour >> minute >> second >> cook_clock;

    second += cook_clock;
    minute += second / 60;
    second %= 60;
    hour += minute / 60;
    minute %= 60;
    hour %= 24;

    cout << hour << " " << minute << " " << second << endl;

    return 0;
}