// Given an directed graph with possibly negative edge weights and with n vertices and m edges, check
// whether it contains a cycle of negative weight.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1005;
const int inf = 1000000007;
int n, m;
vector<int> dist(maxn);
struct edge {
  int a;
  int b;
  int cost;
};
vector<edge> e(maxn);

void neg_weight() {
  for (int i = 0; i < n; ++i) dist[i] = inf;
  dist[0] = 0;
  int x;
  for (int i = 0; i < n; ++i) {
    x = -1;
    for (int j = 0; j < m; ++j) {
      if (dist[e[j].a] != inf && dist[e[j].b] > dist[e[j].a] + e[j].cost)
        dist[e[j].b] = max( -inf, dist[e[j].a] + e[j].cost );
        x = e[j].b;
    }
  }
  if (x == -1) cout << 0 << '\n';
  else cout << 1 << '\n';
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y, cost; cin >> x >> y >> cost;
    x--; y--;
    e[i] = {x, y, cost};
  }
  neg_weight();

  return 0;
}
