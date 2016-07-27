// Given an undirected graph with n vertices and m edges, check whether it is bipartite.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 100005;
int n, m;
vector<int> graph[maxn], color(maxn);

int inverse(int x) {
  return x == 1 ? 2 : 1;
}

bool bfs(int s) {
  queue<int> q;
  color[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int y : graph[x]) {
      if (color[y] == 0) {
        color[y] = inverse(color[x]);
        q.push(y);
      }
      else if (color[y] == color[x]) return false;
    }
  }
  return true;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y; x--; y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  if (bfs(0)) cout << 1 << endl; // if bipartite
  else cout << 0 << endl; // otherwise

  return 0;
}
