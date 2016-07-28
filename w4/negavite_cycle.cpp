// find negative cycles,if exist fint path (bellman-ford)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 100005;
const int inf = 1000000007;
int n, m;
vector<int> dist(maxn), parent(maxn);
struct edge {
  int a;
  int b;
  int cost;
};
vector<edge> e(maxn);

void negative_cycle(int s) {
  for (int i = 0; i < n; ++i) dist[i] = inf;
  dist[s] = 0;
  int x;
  for (int i = 0; i < n; ++i) {
    x = -1;
    for (int j = 0; j < m; ++j) {
      if (dist[e[j].a] != inf && dist[e[j].b] > dist[e[j].a] + e[j].cost) {
        dist[e[j].b] = max( -inf, dist[e[j].a] + e[j].cost );
        parent[e[j].b] = e[j].a;
        x = e[j].b;
      }
    }
  }
  if (x == -1) {
    cout << "No negative cycle from " << s << '\n';
    for (int i = 0; i < n; ++ i) {
      cout << dist[i] << ' ';
    }
    cout << '\n';
  } else {
    int y = x;
    for (int i = 0; i < n; ++i)
      y = parent[y];
    vector<int> path;
    for (int cur = y; ; cur = parent[cur]) {
      path.push_back(cur);
      if (cur == y && path.size() > 1) break;
    }
    reverse(path.begin(), path.end());
    cout << "Negative cycle: ";
    for (auto ed: path)
      cout << ed + 1 << ' ';
    cout << '\n';
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y, cost; cin >> x >> y >> cost;
    x--; y--;
    e[i] = {x, y, cost};
  }
  int s; cin >> s; s--;
  negative_cycle(s);

  return 0;
}
