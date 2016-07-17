// connected components
// Given an undirected graph with n vertices and m edges, compute the number of connected components
// in it.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn = 20005;
int n, m;
vector<int> graph[maxn];
bool visited[maxn];

void dfs(int x) {
  visited[x] = true;
  for (auto& y : graph[x])
    if (!visited[y])
      dfs(y);
}

int number_of_components() {
  int res = 0;
  for (int i = 0; i < n; ++i) visited[i] = false;
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(i);
      res++;
    }
  }
  return res;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y;
    x--; y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  cout << number_of_components() << endl;
}
