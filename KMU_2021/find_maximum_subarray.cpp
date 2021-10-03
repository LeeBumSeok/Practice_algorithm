#include <string>
#include <vector>
#include <climits>

using namespace std;

int find_max_crossing_subarray(vector<int> &param0, int low, int mid, int high)
{
    int lm;
    int rm;
    int ls = INT_MIN;
    int rs = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= low; i--)
    {
        sum += param0[i];
        if (sum > ls)
        {
            ls = sum;
            lm = i;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum = sum + param0[i];
        if (sum > rs)
        {
            rs = sum;
            rm = i;
        }
    }
    return lm, rm, ls + rs;
}

int find_maximum_subarray(vector<int> &param0, int low, int high)
{
    int ll, lh, ls, rl, rh, rs, cl, ch, cs;
    if (high == low)
    {
        return low, high, param0[low];
    }
    else
    {
        int mid = (low + high) / 2;
        ll, lh, ls = find_maximum_subarray(param0, low, mid);
        rl, rh, rs = find_maximum_subarray(param0, mid + 1, high);
        cl, ch, cs = find_max_crossing_subarray(param0, low, mid, high);
        if (ls >= rs && ls >= cs)
        {
            return ll, lh, ls;
        }
        else if (rs >= ls && rs >= cs)
        {
            return rl, rh, rs;
        }
        else
        {
            return cl, ch, cs;
        }
    }
}

int solution(vector<int> param0)
{
    int answer = 0;
    int low = 0;
    int high = 0;
    low, high, answer = find_maximum_subarray(param0, 0, param0.size() - 1);

    return answer;
}