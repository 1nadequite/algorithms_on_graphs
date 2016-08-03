// Given n points on a plane and an integer k, compute the largest possible value of d such that the
// given points can be partitioned into k non-empty subsets in such a way that the distance between any
// two points from different subsets is at least d.
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>

using namespace std;
const int maxn = 205;
const double inf = 10000;
int n, k;
vector<pair<int, double>> graph[maxn];
vector<pair<double, double>> point(maxn);
vector<int> visited(maxn);
vector<double> dist(maxn);

double length(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void prim() {
  for (int i = 0; i < n; ++ i) {
    dist[i] = inf;
    visited[i] = false;
  }
  set<pair<double, int>> q;
  dist[0] = 0;
  q.insert({dist[0], 0});
  while (!q.empty()) {
    int x = q.begin()->second;
    double d = q.begin()->first;
    q.erase(q.begin());
    if (d > dist[x]) continue;
    visited[x] = true;
    for (auto& p: graph[x]) {
      int y = p.first;
      double w = p.second;
      if (!visited[y] && dist[y] > w) {
        q.erase({dist[y], y});
        dist[y] = w;
        q.insert({dist[y], y});
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    x--; y--;
    point[i] = {x, y};
  }
  for (int x = 0; x < n; ++ x) {
    for (int y = x + 1; y < n; ++y) {
      double w = length(point[x].first, point[x].second, point[y].first, point[y].second);
      graph[x].push_back({y, w});
      graph[y].push_back({x, w});
    }
  }
  cin >> k;
  prim();
  sort(dist.begin(), dist.end());
  reverse(dist.begin(), dist.end());
  double min_length = -1;
  for (int i = 0; i < k - 1; ++i)
    if (min_length == -1 || min_length > dist[i])
      min_length = dist[i];
  printf("%.9f\n", min_length);

  return 0;
}
