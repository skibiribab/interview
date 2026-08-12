// Eulerian path / circuit — Hierholzer (undirected)
// When: traverse every edge exactly once; reconstruct tour (CPH / CP-Algorithms).
// Time: O(V+E)    Space: O(V+E)
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

using std::vector;

// Returns vertex sequence of an Eulerian path (or circuit if start==end).
// Edges are undirected; graph must already admit an Eulerian path.
static vector<int> eulerian_path(int n, vector<std::pair<int, int>> edges, int start) {
    vector<vector<std::pair<int, int>>> g(n); // (to, edge_id)
    for (int i = 0; i < (int)edges.size(); ++i) {
        auto [u, v] = edges[i];
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    vector<char> used(edges.size(), 0);
    vector<int> st, path;
    st.push_back(start);
    while (!st.empty()) {
        int u = st.back();
        while (!g[u].empty() && used[g[u].back().second])
            g[u].pop_back();
        if (g[u].empty()) {
            path.push_back(u);
            st.pop_back();
        } else {
            auto [v, id] = g[u].back();
            g[u].pop_back();
            used[id] = 1;
            st.push_back(v);
        }
    }
    std::reverse(path.begin(), path.end());
    return path;
}

int main() {
    // Square circuit 0-1-2-3-0
    auto p = eulerian_path(4, {{0, 1}, {1, 2}, {2, 3}, {3, 0}}, 0);
    assert(p.size() == 5);
    assert(p.front() == 0 && p.back() == 0);
    return 0;
}
