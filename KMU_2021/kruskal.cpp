#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int s, e, cost;
  Edge(int a, int b, int c) {
    s = a;
    e = b;
    cost = c;
  }
  bool operator<(const Edge &b) const { return cost < b.cost; }
};

int find_set(int v, vector<int> &parent) {
  if (v == parent[v])
    return v;
  else
    return parent[v] = find_set(parent[v], parent);
}

void union_set(int u, int v, vector<int> &parent) {
  u = find_set(u, parent);
  v = find_set(v, parent);
  if (u != v)
    parent[u] = v;
}

int main() {
  int t, n, k, m, tmp1, tmp2;
  cin >> t;

  while (t--) {
    cin >> n;

    vector<int> parent(n + 1);

    int result = 0;
    for (int i = 1; i <= n; i++)
      parent[i] = i;

    vector<pair<int, int>> graph[n + 1];

    for (int i = 1; i <= n; i++) {
      cin >> k >> m;

      for (int j = 0; j < m; j++) {
        cin >> tmp1 >> tmp2;
        graph[k].push_back(make_pair(tmp1, tmp2));
      }
    }

    vector<Edge> E;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < graph[i].size(); j++)
        E.push_back(Edge(i, graph[i][j].first, graph[i][j].second));

    sort(E.begin(), E.end());

    for (int i = 0; i < E.size(); i++) {
      if (find_set(E[i].s, parent) != find_set(E[i].e, parent)) {
        result += E[i].cost;
        union_set(E[i].s, E[i].e, parent);
      }
    }

    cout << result << endl;
  }

  return 0;
}