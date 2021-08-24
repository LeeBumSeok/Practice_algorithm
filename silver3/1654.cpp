#include <iostream>
#include <algorithm>
using namespace std;

int K, N;
int lan[10000];

bool possible(long long len)
{
    int cnt = 0;

    for (int i = 0; i < K; i++)
    {
        cnt += lan[i] / len;
    }

    if (cnt >= N)
        return true;

    return false;
}

int main()
{
    cin >> K >> N;

    for (int i = 0; i < K; i++)
        cin >> lan[i];

    long long max = *max_element(lan, lan + K);
    long long min = 1;
    long long result = 0;

    while (min <= max)
    {
        long long mid = (min + max) / 2;
        if (possible(mid))
        {
            if (result < mid)
                result = mid;
            min = mid + 1;
        }
        else
            max = mid - 1;
    }

    cout << result;

    return 0;
}