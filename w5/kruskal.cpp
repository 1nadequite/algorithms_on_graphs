// kruskal algorithm: O(|E|*log|V|)
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
const int maxn = 3005;
set<pair<int, pair<int, int>>> graph;
vector<pair<int, int>> mst;
vector<int> tree_id(maxn);
int n, m;

void kruskal(int s, int& cost) {
  for (int i = 0; i < n; ++i) tree_id[i] = i;
  for (auto& v: graph) {
    int x = v.second.first, y = v.second.second, w = v.first;
    if (tree_id[x] != tree_id[y]) { // check if not cycle
      cost += w; // mst minimum wight
      mst.push_back({x, y}); // add in minimum spanning tree
      int old_id = tree_id[x], new_id = tree_id[y];
      for (int i = 0; i < n; ++i)
        if (tree_id[i] == old_id)
          tree_id[i] = new_id;
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y, w; cin >> x >> y >> w;
    x--; y--;
    graph.insert({w, {x, y}}); // weight sort
  }
  int s; cin >> s; s--;
  int cost = 0;
  kruskal(s, cost);

  cout << cost << endl;
  for (auto& v: mst)
    cout << v.first << ' ' << v.second << endl;

  return 0;
}
