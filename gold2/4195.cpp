#include <iostream>
#include <map>

using namespace std;

struct Union {
    map<string, string> parent;
    map<string, int> friendList;

    string find(string u);
    void union_find(string u, string v);
};

string Union::find(string u) {
    if (u == parent[u]) return u;
    return find(parent[u]);
}

void Union::union_find(string u, string v) {
    u = find(u);
    v = find(v);

    if (u == v) return;
    if (friendList[u] < friendList[v]) swap(u, v);

    parent[v] = u;
    friendList[u] += friendList[v];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t, F;
    string u, v;
    cin >> t;

    while (t--) {
        cin >> F;
        Union un;
        for (int i = 0; i < F; i++) {
            cin >> u >> v;

            if (un.parent.count(u) == 0) {
                un.parent.insert(make_pair(u, u));
                un.friendList.insert(make_pair(u, 1));
            }
            if (un.parent.count(v) == 0) {
                un.parent.insert(make_pair(v, v));
                un.friendList.insert(make_pair(v, 1));
            }

            un.union_find(u, v);
            cout << un.friendList[un.find(u)] << "\n";
        }
    }
    return 0;
}