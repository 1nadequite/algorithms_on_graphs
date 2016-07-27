// Given an undirected graph with n vertices and m edges and two vertices u and v, compute the length
// of a shortest path between u and v (that is, the minimum number of edges in a path from u to v).
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100005;
int n, m;
vector<int> graph[maxn], dist(maxn);

void bfs(int s) {
  for (int i = 0; i < n; ++i) dist[i] = -1;
  queue<int> q;
  dist[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int y: graph[x]) {
      if (dist[y] == -1) {
        dist[y] = dist[x] + 1;
        q.push(y);
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y; x--; y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  int u, v; cin >> u >> v; u--; v--;

  bfs(u);
  cout << dist[v] << endl;

  return 0;
}
