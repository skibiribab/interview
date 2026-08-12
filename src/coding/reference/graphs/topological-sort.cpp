// Topological sort — Kahn (BFS on indegree), detects cycle if incomplete
// When: course prerequisites, build order, DAG scheduling.
// Time: O(V+E)    Space: O(V)
#include <cassert>
#include <queue>
#include <vector>

using std::vector;

// Returns one topological order, or empty if cycle
static vector<int> topological_sort_kahn(int n, const vector<std::pair<int, int>>& edges) {
    vector<vector<int>> g(n);
    vector<int> indeg(n);
    for (auto [u, v] : edges) {
        g[u].push_back(v);
        indeg[v]++;
    }
    std::queue<int> q;
    for (int i = 0; i < n; ++i)
        if (indeg[i] == 0)
            q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g[u])
            if (--indeg[v] == 0)
                q.push(v);
    }
    if ((int)order.size() != n)
        return {};
    return order;
}

int main() {
    // 0 -> 1 -> 2 and 0 -> 2
    auto t = topological_sort_kahn(3, {{0, 1}, {1, 2}, {0, 2}});
    assert(t.size() == 3 && t[0] == 0);
    assert(topological_sort_kahn(2, {{0, 1}, {1, 0}}).empty());
    return 0;
}
