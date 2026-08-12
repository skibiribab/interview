// Tree diameter — two BFS/DFS passes on unweighted tree
// When: longest shortest path in a tree; center/radius problems.
// Time: O(V+E)    Space: O(V)
#include <cassert>
#include <queue>
#include <utility>
#include <vector>

using std::vector;

static std::pair<int, int> bfs_farthest(int n, int start, const vector<vector<int>>& g) {
    vector<int> dist(n, -1);
    std::queue<int> q;
    dist[start] = 0;
    q.push(start);
    int far = start;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        far = u;
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return {far, dist[far]};
}

static int tree_diameter(int n, const vector<std::pair<int, int>>& edges) {
    vector<vector<int>> g(n);
    for (auto [u, v] : edges) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int a = bfs_farthest(n, 0, g).first;
    return bfs_farthest(n, a, g).second;
}

int main() {
    // path 0—1—2—3 has diameter 3
    assert(tree_diameter(4, {{0, 1}, {1, 2}, {2, 3}}) == 3);
    return 0;
}
