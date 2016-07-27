#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs() {
    int n, m; cin >> n >> m;
    vector<int> dist(n, -1);
    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int s; cin >> s; --s;
    queue<int> q;
    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : graph[x]) {
            if (dist[y] == -1) {
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << dist[i] << ' ';
    }
}

int main() {
    bfs();

    return 0;
}
