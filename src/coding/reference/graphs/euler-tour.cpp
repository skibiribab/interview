// Euler tour on rooted tree — flat timeline for subtree = contiguous segment
// When: subtree sum/update with Fenwick on tour order; LCA via first occurrence.
// Time: O(V) build    Space: O(V)
#include <cassert>
#include <vector>

using std::vector;

struct EulerTour {
    vector<vector<int>> g;
    vector<int> tin, tout, order;
    int timer = 0;

    explicit EulerTour(int n) : g(n), tin(n), tout(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void build(int root = 0) {
        dfs(root, -1);
    }

    void dfs(int u, int p) {
        tin[u] = timer++;
        order.push_back(u);
        for (int v : g[u]) {
            if (v == p)
                continue;
            dfs(v, u);
            order.push_back(u);
        }
        tout[u] = timer;
    }

    bool in_subtree(int node, int anc) const {
        return tin[anc] <= tin[node] && tout[node] <= tout[anc];
    }
};

int main() {
    EulerTour et(4);
    et.add_edge(0, 1);
    et.add_edge(1, 2);
    et.add_edge(1, 3);
    et.build(0);
    assert(et.in_subtree(3, 1));
    assert(!et.in_subtree(0, 3));
    assert(et.order.size() == 7);
    return 0;
}
