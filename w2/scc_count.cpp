// SCC - strongly connected components
// using, graph, reverse graph, dfs
// Compute the number of strongly connected components of a given directed graph with n vertices and
// m edges.
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 100;
int n, m;
vector<int> g[maxn], gr[maxn], order;
bool visited[maxn];

void dfs_g(int x) {
    visited[x] = true;
    for (auto y : g[x])
        if (!visited[y])
            dfs_g(y);
    order.push_back(x);
}

void dfs_gr(int x) {
    visited[x] = true;
    for (auto y : gr[x])
        if (!visited[y])
            dfs_gr(y);
}

int number_of_strongly_connected_components() {
  int result = 0;
  for (int i = 0; i < n; ++i) visited[i] = false;
  for (int i = 0; i < n; ++i)
      if (!visited[i])
          dfs_g(i);
  for (int i = 0; i < n; ++i) visited[i] = false;
  for (int i = 0; i < n; ++i) {
      int x = order[n - 1 - i];
      if (!visited[x]) {
          dfs_gr(x);
          result++;
      }
  }
  return result;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
      int x, y; cin >> x >> y;
      --x, --y;
      g[x].push_back(y);
      gr[y].push_back(x);
  }
  cout << number_of_strongly_connected_components() << endl; // print number of strongly connected components

  return 0;
}
