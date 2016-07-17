// using dfs
// Check whether a given directed graph with n vertices and m edges contains a cycle.
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 100;
int n, m;
vector<int> g[maxn], color(maxn);

bool dfs(int x) {
    if (color[x] == 1) return true;
    if (color[x] == 2) return false;
    color[x] = 1;
    for (int y : g[x])
        if (dfs(y))
            return true;
    color[x] = 2;
    return false;
}

int acyclic() {
    for (int i = 0; i < n; ++i)
        if (dfs(i)) return 1;
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
    }
    cout << acyclic() << endl;

    return 0;
}
