
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int e, cost;
  Edge(int a, int c) {
    e = a;
    cost = c;
  }

  bool operator<(const Edge &b) const { return cost > b.cost; }
};

int main() {
  int t, n, k, m, tmp1, tmp2;
  cin >> t;

  while (t--) {
    cin >> n;
    vector<pair<int, int>> graph[1001];

    for (int i = 1; i <= n; i++) {
      cin >> k >> m;
      for (int j = 0; j < m; j++) {
        cin >> tmp1 >> tmp2;
        graph[k].push_back(make_pair(tmp1, tmp2)); // start node, end node, cost
        graph[tmp1].push_back(make_pair(k, tmp2)); // end node, start node, cost
      }
    }

    priority_queue<Edge> pq;
    vector<int> visit(n + 1);
    int result = 0;
    pq.push(Edge(1, 0)); // start node, cost

    while (!pq.empty()) {
      Edge tmp = pq.top();
      pq.pop();
      int v = tmp.e;
      int cost = tmp.cost;

      if (!visit[v]) {
        result += cost;
        visit[v]++;

        for (int i = 0; i < graph[v].size(); i++)
          if (!visit[graph[v][i].first]) {
            pq.push(Edge(graph[v][i].first, graph[v][i].second));
          }
      }
    }

    cout << result << endl;
  }

  return 0;
}