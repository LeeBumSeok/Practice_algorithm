#include <vector>
#include <iostream>

using namespace std;

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void max_heapify(vector<int> &a, int i)
{
    int largest;
    int l = left(i);
    int r = right(i);

    if (l <= a.size() - 1 && a[l] > a[i])
        largest = l;
    else
        largest = i;

    if (r <= a.size() - 1 && a[r] > a[largest])
        largest = r;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        max_heapify(a, largest);
    }
}

void build_max_heap(vector<int> &a)
{
    for (int i = a.size() / 2 - 1; i >= 0; i--)
        max_heapify(a, i);
}

void heap_sort(vector<int> &a, int k)
{
    build_max_heap(a);

    for (int i = a.size() - 1; i >= k; i--)
    {
        swap(a[0], a[i]);
        max_heapify(a, 0);
    }
}

vector<int> solution(vector<int> a, int k)
{
    heap_sort(a, k);
    return a;
}