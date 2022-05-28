#include <iostream>
#include <vector>

using namespace std;

struct Union {
    vector<int> parent, rank;

    Union(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u);
    bool union_find(int u, int v);
};

int Union::find(int u) {
    if (u == parent[u]) return u;
    return find(parent[u]);
}

bool Union::union_find(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return true;
    if (rank[u] > rank[v]) swap(u, v);

    parent[u] = v;
    if (rank[u] == rank[v]) ++rank[v];
    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, u, v;
    cin >> n >> m;

    Union un(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        if (un.union_find(u, v)) {
            if (i == 0)
                cout << 0 << "\n";
            else
                cout << i + 1 << "\n";

            return 0;
        }
    }
    cout << 0 << "\n";
    return 0;
}