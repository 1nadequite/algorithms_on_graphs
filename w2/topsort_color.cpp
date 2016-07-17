// topological sort using dfs(color)
// Compute a topological ordering of a given directed acyclic graph (DAG) with n vertices and m edges.
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 100;
int n, m;
vector<int> g[maxn], number(maxn), color(maxn);
stack<int> st;

bool dfs(int x) {
    if (color[x] == 1) return true;
    if (color[x] == 2) return false;
    color[x] = 1;
    for (int y : g[x])
        if (dfs(y)) return true;
    st.push(x);
    color[x] = 2;
    return false;
}

bool topological_sort() {
    for (int i = 0; i < n; ++i)
        if (dfs(i)) return false;
    for (int i = 0; i < n; ++i) {
        number[st.top()] = i + 1;
        st.pop();
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
    }
    if (topological_sort())
        for (int i = 0; i < n; ++i)
            cout << number[i] << ' ';
    else cout << "Graph with cycle.";
    cout << endl;

    return 0;
}
