#include <iostream>
#include <vector>

using namespace std;

int partition_Hoare(vector<int> &A, vector<int> &cnt, int low, int high)
{
    int pivot = A[low];
    int i = --low;
    int j = ++high;

    while (true)
    {
        do
        {
            ++i;
            cnt[2]++;
        } while (A[i] < pivot);

        do
        {
            --j;
            cnt[2]++;
        } while (A[j] > pivot);

        if (i < j)
        {
            swap(A[i], A[j]);
            cnt[0]++;
        }
        else
            return j;
    }
}

int partition_Lomuto(vector<int> &A, vector<int> &cnt, int low, int high)
{
    int pivot = A[low];
    int j = low;

    for (int i = low + 1; i <= high; i++)
    {
        cnt[3]++;
        if (A[i] < pivot)
        {
            ++j;
            swap(A[i], A[j]);
            cnt[1]++;
        }
    }
    int pivot_pos = j;
    swap(A[pivot_pos], A[low]);
    cnt[1]++;

    return pivot_pos;
}

void quicksort_H(vector<int> &A, vector<int> &cnt, int low, int high)
{
    if (low >= high)
        return;

    int p = partition_Hoare(A, cnt, low, high);
    quicksort_H(A, cnt, low, p);
    quicksort_H(A, cnt, ++p, high);
}

void quicksort_L(vector<int> &A, vector<int> &cnt, int low, int high)
{
    if (low >= high)
        return;

    int p = partition_Lomuto(A, cnt, low, high);
    quicksort_L(A, cnt, low, p - 1);
    quicksort_L(A, cnt, p + 1, high);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, num;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<int> H, L;
        vector<int> cnt(4);
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            H.push_back(num);
        }
        L = H;
        quicksort_H(H, cnt, 0, n - 1);
        quicksort_L(L, cnt, 0, n - 1);

        for (int k = 0; k < 4; k++)
            cout << cnt[k] << " ";
        cout << "\n";
    }
}