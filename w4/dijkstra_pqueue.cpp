// dijkstra with priority_queue O(n * log(m))
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn = 1000005;
const int inf = 1000000007;
int n, m;
vector<pair<int, int>> graph[maxn];
vector<int> dist(maxn);

void dijkstra(int s) {
  for (int i = 0; i < n; ++i) dist[i] = inf;
  priority_queue<pair<int, int>> q;
  dist[s] = 0;
  q.push({dist[s], s});
  while (!q.empty()) {
    int x = q.top().second;
    int d = -q.top().first;
    q.pop();
    if (d > dist[x]) continue;
    for (auto p: graph[x]) {
      int y = p.first;
      int w = p.second;
      if (dist[y] > dist[x] + w) {
        dist[y] = dist[x] + w;
        q.push({-dist[y], y});
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
