// LCA on general tree — binary lifting (O(log n) query)
// When: k-th ancestor, distance on tree, jump queries after O(n log n) prep.
// Time: build O(n log n); query O(log n)    Space: O(n log n)
#include <cassert>
#include <vector>

using std::vector;

struct TreeLCA {
    int n, LOG;
    vector<vector<int>> up;
    vector<int> depth;

    TreeLCA(int n_, const vector<vector<int>>& g, int root = 0) : n(n_), depth(n, 0) {
        LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;
        up.assign(LOG, vector<int>(n, -1));
        dfs(root, -1, g);
        for (int k = 1; k < LOG; ++k) {
            for (int v = 0; v < n; ++v) {
                int mid = up[k - 1][v];
                up[k][v] = mid == -1 ? -1 : up[k - 1][mid];
            }
        }
    }

    void dfs(int u, int p, const vector<vector<int>>& g) {
        up[0][u] = p;
        for (int v : g[u]) {
            if (v == p)
                continue;
            depth[v] = depth[u] + 1;
            dfs(v, u, g);
        }
    }

    int lift(int u, int k) const {
        for (int i = 0; k && u != -1; ++i, k >>= 1) {
            if (k & 1)
                u = up[i][u];
        }
        return u;
    }

    int lca(int u, int v) const {
        if (depth[u] < depth[v])
            std::swap(u, v);
        u = lift(u, depth[u] - depth[v]);
        if (u == v)
            return u;
        for (int k = LOG - 1; k >= 0; --k) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }
        return up[0][u];
    }

    int dist(int u, int v) const { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }
};

int main() {
    vector<vector<int>> g(5);
    for (auto [u, v] : vector<std::pair<int, int>>{{0, 1}, {0, 2}, {1, 3}, {1, 4}}) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    TreeLCA lca(5, g, 0);
    assert(lca.lca(3, 4) == 1);
    assert(lca.dist(3, 2) == 3);
    assert(lca.lift(3, 1) == 1);
    return 0;
}
