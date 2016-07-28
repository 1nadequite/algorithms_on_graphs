// Given an directed graph with positive edge weights and with n vertices and m edges as well as two
// vertices u and v, compute the weight of a shortest path between u and v (that is, the minimum total
// weight of a path from u to v).
#include <iostream>
#include <vector>
#include <set>

using namespace std;
const int maxn = 1005;
const int inf = 1000000007;
int n, m;
vector<pair<int, int>> graph[maxn];
vector<int> dist(maxn);

void short_path(int u, int v) {
  for (int i = 0; i < n; ++i) dist[i] = inf;
  set<pair<int, int>> s;
  dist[u] = 0;
  s.insert({dist[u], u});
  while (!s.empty()) {
    int x = s.begin()->second;
    int d = s.begin()->first;
    s.erase(s.begin());
    if (d > dist[x]) continue;
    for (auto p: graph[x]) {
      int y = p.first;
      int w = p.second;
      if (dist[y] > dist[x] + w) {
        dist[y] = dist[x] + w;
        s.insert({dist[y], y});
      }
    }
  }
  if (dist[v] == inf) cout << -1 << '\n'; // no path from u to v
  else cout << dist[v] << '\n';
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y, w; cin >> x >> y >> w;
    x--; y--;
    graph[x].push_back({y, w});
  }
  int u, v; cin >> u >> v; u--; v--;
  short_path(u, v);

  return 0;
}
