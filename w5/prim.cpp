#include <iostream>
#include <vector>
#include <set>

using namespace std;
const int maxn = 3005;
const int inf = 1000000007;
vector<pair<int, int>> graph[maxn], mst;
vector<int> dist(maxn), visited(maxn), parent(maxn);
int n, m;

void prim(int s) {
  for (int i = 0; i < n; ++i) {
    dist[i] = inf;
    visited[i] = false;
    parent[i] = -1;
  }
  set<pair<int, int>> q;
  dist[s] = 0;
  q.insert({dist[s], s});
  while(!q.empty()) {
    // take edge from this vertex with min weight
    int x = q.begin()->second;
    int d = q.begin()->first;
    q.erase(q.begin());
    if (d > dist[x]) continue;
    if (dist[x] == inf) {
      cout << "No MST" << endl;
      return;
    }
    visited[x] = true;
    if (parent[x] != -1)
      mst.push_back({x + 1, parent[x] + 1});
    for (auto& p: graph[x]) {
      int y = p.first;
      int w = p.second;
      if (!visited[y] && dist[y] > w) {
        q.erase({dist[y], y});
        dist[y] = w;
        parent[y] = x;
        q.insert({dist[y], y});
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y, w; cin >> x >> y >> w;
    x--; y--;
    graph[x].push_back({y, w});
    graph[y].push_back({x, w});
  }
  int s; cin >> s; s--;
  prim(s);
  int cost = 0;
  for (int i = 0; i < n; ++i)
    cost += dist[i];
  cout << cost << endl;
  for (auto& v: mst)
    cout << v.first << ' ' << v.second << endl;

  return 0;
}
