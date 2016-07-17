// Given an undirected graph and two distinct vertices u and v, check if there is a path between u and v.
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

int reachability(int x, int y) {
  dfs(x);
  if (visited[y]) return 1;
  else return 0;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y;
    x--; y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  int x, y; cin >> x >> y; x--; y--;
  cout << reachability(x, y) << endl;
}
