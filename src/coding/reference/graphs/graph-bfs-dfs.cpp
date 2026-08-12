// Graph BFS / DFS — adjacency list, components, traversal order
// When: unweighted reachability, layers, count components, grid as graph.
// Time: O(V+E)    Space: O(V) for visited + queue/stack
#include <cassert>
#include <queue>
#include <vector>

using std::vector;

static void bfs_from(int start, const vector<vector<int>>& g, vector<bool>& vis, vector<int>& order) {
    std::queue<int> q;
    q.push(start);
    vis[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g[u])
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
    }
}

static int count_components(const vector<vector<int>>& g) {
    int n = (int)g.size();
    vector<bool> vis(n);
    int c = 0;
    for (int i = 0; i < n; ++i)
        if (!vis[i]) {
            vector<int> ord;
            bfs_from(i, g, vis, ord);
            ++c;
        }
    return c;
}

int main() {
    vector<vector<int>> g(4);
    g[0] = {1};
    g[1] = {0, 2};
    g[2] = {1};
    g[3] = {};
    assert(count_components(g) == 2);
    return 0;
}
