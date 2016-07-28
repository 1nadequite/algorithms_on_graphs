// bellman-ford algorithm O(n*m)
// no negative weight cycles in graph!!!
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 1000005;
const int inf = 1000000007;
int n, m;
vector<int> dist(maxn);

struct edge {
  int a;
  int b;
  int cost;
};
vector<edge> e(maxn);

void bellman_ford(int s) {
  for (int i = 0; i < n; ++i) dist[i] = inf;
  dist[s] = 0;
  for (;;) {
    bool any_change = false;
    for (int i = 0; i < m; ++i) {
      if (dist[e[i].a] != inf && dist[e[i].b] > dist[e[i].a] + e[i].cost) {
        dist[e[i].b] = dist[e[i].a] + e[i].cost;
        any_change = true;
      }
    }
    if (!any_change) break;
  }
  for (int i = 0; i < n; ++i) {
    cout << dist[i] << ' ';
  }
  cout << '\n';
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y, cost; cin >> x >> y >> cost;
    x--; y--;
    e[i] = {x, y, cost};
  }
  int s; cin >> s; --s;
  bellman_ford(s);

  return 0;
}
