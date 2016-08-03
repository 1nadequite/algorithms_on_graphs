// clustering, dfs, binary seearch
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
const int maxn = 205;
int n, k;
double g[maxn][maxn];
double x[maxn], y[maxn];
bool visited[maxn];

double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void dfs(int x, double d) {
  visited[x] = true;
  for (int y = 0; y < n; ++y)
    if (g[x][y] < d && !visited[y])
      dfs(y, d);
}

int num_comp(double d) {
  int res = 0;
  for (int i = 0; i < n; ++i)
    visited[i] = false;
  for (int x = 0; x < n; ++x) {
    if (!visited[x]) {
      ++res;
      dfs(x, d);
    }
  }
  return res;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
  }
  cin >> k;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      g[i][j] = dist(x[i], y[i], x[j], y[j]);
  double l = 0, r = 1000000000;
  for (int it = 0; it < 100; ++it) {
    double mid = (l + r) / 2.0;
    if (num_comp(mid) < k) r = mid;
    else l = mid;
  }
  printf("%.9f\n", l);

  return 0;
}

