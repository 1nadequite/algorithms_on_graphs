// Given n points on a plane, connect them with segments of minimum total length such that there is a
// path between any two points. Recall that the length of a segment with endpoints (x1, y1) and (x2, y2)
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>

using namespace std;
const int maxn = 205;
set<pair<double, pair<int, int>>> graph;
vector<pair<double, double>> point(maxn);
vector<int> tree_id(maxn);
int n;

double length(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void kruskal(double& cost) {
  for (int i = 0; i < n; ++i) tree_id[i] = i;
  for (auto& v : graph) {
    int x = v.second.first, y = v.second.second;
    double w = v.first;
    if (tree_id[x] != tree_id[y]) {
      cost += w;
      int old_id = tree_id[x], new_id = tree_id[y];
      for (int i = 0; i < n; ++i)
        if (tree_id[i] == old_id)
          tree_id[i] = new_id;
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
  for (int x = 0; x < n; ++x) {
    for (int y = x + 1; y < n; ++ y) {
      graph.insert({length(point[x].first, point[x].second, point[y].first, point[y].second), {x, y}});
    }
  }
  double cost = 0;
  kruskal(cost);
  printf("%.9f\n", cost);

  return 0;
}
