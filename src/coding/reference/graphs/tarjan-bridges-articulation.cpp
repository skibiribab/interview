// Tarjan (bridges & articulation points) — one DFS with discovery/low links
// When: find cut edges / cut vertices in undirected networks.
// Time: O(V+E)    Space: O(V+E)
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using std::vector;

struct TarjanBridges {
    int n, timer = 0;
    vector<vector<std::pair<int, int>>> g;
    vector<int> disc, low;
    vector<char> vis;
    vector<char> is_bridge;
    vector<char> is_art;

    explicit TarjanBridges(int n_) : n(n_), g(n_), disc(n_, -1), low(n_), vis(n_), is_art(n_) {}

    void add_edge(int u, int v, int eid) {
        g[u].push_back({v, eid});
        g[v].push_back({u, eid});
    }

    void dfs(int v, int peid) {
        vis[v] = 1;
        disc[v] = low[v] = timer++;
        int child = 0;
        for (auto [to, eid] : g[v]) {
            if (eid == peid)
                continue;
            if (vis[to]) {
                low[v] = std::min(low[v], disc[to]);
            } else {
                ++child;
                dfs(to, eid);
                low[v] = std::min(low[v], low[to]);
                if (low[to] > disc[v])
                    is_bridge[eid] = 1;
                if (low[to] >= disc[v] && peid != -1)
                    is_art[v] = 1;
            }
        }
        if (peid == -1 && child > 1)
            is_art[v] = 1;
    }

    void run(int m) {
        is_bridge.assign(m, 0);
        for (int i = 0; i < n; ++i)
            if (!vis[i])
                dfs(i, -1);
    }
};

int main() {
    vector<std::pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}, {4, 5}, {5, 3}};
    TarjanBridges tb(6);
    for (int i = 0; i < (int)edges.size(); ++i)
        tb.add_edge(edges[i].first, edges[i].second, i);
    tb.run((int)edges.size());
    assert(tb.is_bridge[3]);
    assert(tb.is_art[1] && tb.is_art[3]);
    std::cout << "tarjan bridges ok\n";
    return 0;
}
