// Given an directed graph with possibly negative edge weights and with n vertices and m edges as well
// as its vertex s, compute the length of shortest paths from s to all other vertices of the graph.
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
const int maxn = 1005;
const int maxm = 10005;
const int inf = 1000000007;
int n, m;
vector<int> dist(maxn), visited(maxn);
struct edge {
  int a;
  int b;
  int cost;
};
vector<edge> e(maxm);

void exch_money(int s) {
  for (int i = 0; i < n; ++i) {
    dist[i] = inf;
    visited[i] = false;
  }
  dist[s] = 0;
  //set<int> ss;
  for (int i = 0; i < n - 1; ++i) {
    //ss.clear();
    for (int j = 0; j < m; ++j) {
      if (dist[e[j].a] != inf && dist[e[j].b] > dist[e[j].a] + e[j].cost) {
        dist[e[j].b] = max( -inf, dist[e[j].a] + e[j].cost );
        //ss.insert(e[j].a);
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    if (dist[e[i].b] > dist[e[i].a] + e[i].cost)
      cout << e[i].b << ' ' << e[i].a << endl;
  }
  /*queue<int> q;
  for (auto x: ss) q.push(x);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    visited[x] = true;
    for (int i = 0; i < m; ++i) {
      if (e[i].a == x && !visited[x]) {
        q.push(e[i].b);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (dist[i] == inf) cout << '*' << endl;
    else {
      if (visited[i] == true) cout << '-' << endl;
      else cout << dist[i] << endl;
    }
  }*/
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y, cost; cin >> x >> y >> cost;
    x--; y--;
    e[i] = {x, y, cost};
  }
  int s; cin >> s; s--;
  exch_money(s);

  return 0;
}
