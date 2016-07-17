// topological sort using dfs
// Compute a topological ordering of a given directed acyclic graph (DAG) with n vertices and m edges.
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 100;
int n, m;
vector<int> g[maxn], number(maxn);
bool visited[maxn];
stack<int> st;

void dfs(int x) {
    visited[x] = true;
    for (int y : g[x])
        if (!visited[y])
          dfs(y);
    st.push(x);
}

void topological_sort() {
    for (int i = 0; i < n; ++i)
      visited[i] = false;
    for (int i = 0; i < n; ++i)
      if (visited[i] == false)
        dfs(i);
    for (int i = 0; i < n; ++i) {
        number[st.top()] = i + 1;
        st.pop();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
    }
    topological_sort();
    for (int i = 0; i < n; ++i)
        cout << number[i] << ' ';
    cout << endl;
    return 0;
}
