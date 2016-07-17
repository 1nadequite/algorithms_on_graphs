// using dfs
// Check whether a given directed graph with n vertices and m edges contains a cycle.
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 100;
int n, m, cycle_start, cycle_end;
vector<int> g[maxn], color(maxn), parent(maxn), cycle;

bool dfs(int x) {
    color[x] = 1;
    for (int y : g[x]) {
        if (color[y] == 0) {
            parent[y] = x;
            if (dfs(y)) return true;
        } else if (color[y] == 1) {
            cycle_start = y;
            cycle_end = x;
            return true;
        }
    }
    color[x] = 2;
    return false;
}

bool acyclic() {
    cycle_start = -1;
    for (int i = 0; i < n; ++i)
        if (dfs(i)) break; // graph with cycle
    if (cycle_start == -1)
        return false; // graph without cycle
    else {
        cycle.push_back(cycle_start + 1); // constr cycle path
        for (int x = cycle_end; x != cycle_start; x = parent[x])
            cycle.push_back(x + 1);
        cycle.push_back(cycle_start + 1);
        reverse(cycle.begin(), cycle.end());
        return true;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
    }
    parent.assign(n, -1);
    color.assign(n, 0);
    bool ccl = acyclic();
    cout << ccl << endl;
    if (ccl) {
      cout << "Cycle: ";
      for (int i = 0; i < cycle.size(); ++i) {
          if (i != 0) cout << " -> ";
          cout << cycle[i];
      }
      cout << endl;
    }

    return 0;
}
