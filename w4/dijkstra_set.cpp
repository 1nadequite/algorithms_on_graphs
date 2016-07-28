// dijkstra with set O(n * log(m))
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
const int maxn = 1000005;
const int inf = 1000000007;
int n, m;
vector<pair<int, int>> graph[maxn];
vector<int> dist(maxn);

void dijkstra(int s) {
  for (int i = 0; i < n; ++i) dist[i] = inf;
  set<pair<int, int>> q;
  dist[s] = 0;
  q.insert({dist[s], s});
  while (!q.empty()) {
    int x = q.begin()->second;
    int d = q.begin()->first;
    q.erase(q.begin());
    if (d > dist[x]) continue;
    for (auto p: graph[x]) {
      int y = p.first;
      int w = p.second;
      if (dist[y] > dist[x] + w) {
        dist[y] = dist[x] + w;
        q.insert({dist[y], y});
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << dist[i] << ' ';
  }
  cout << '\n';
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
  dijkstra(s);

  return 0;
}
