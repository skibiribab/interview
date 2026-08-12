// Heavy-light decomposition — chain decomposition for path queries on trees
// When: many path sum/max updates on a static tree (pair with segment tree).
// Time: O(n log n) typical per query with segtree    Space: O(n)
#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

struct HLD {
    vector<vector<int>> g;
    vector<int> parent, depth, heavy, head, pos;
    int cur_pos = 0;

    explicit HLD(int n) : g(n), parent(n), depth(n), heavy(n, -1), head(n), pos(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int dfs(int u, int p) {
        parent[u] = p;
        depth[u] = p == -1 ? 0 : depth[p] + 1;
        int size = 1, max_sub = 0;
        for (int v : g[u]) {
            if (v == p)
                continue;
            int sub = dfs(v, u);
            size += sub;
            if (sub > max_sub) {
                max_sub = sub;
                heavy[u] = v;
            }
        }
        return size;
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = cur_pos++;
        if (heavy[u] != -1)
            decompose(heavy[u], h);
        for (int v : g[u]) {
            if (v == parent[u] || v == heavy[u])
                continue;
            decompose(v, v);
        }
    }

    void build(int root = 0) {
        dfs(root, -1);
        decompose(root, root);
    }

    int lca(int u, int v) const {
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                std::swap(u, v);
            u = parent[head[u]];
        }
        return depth[u] < depth[v] ? u : v;
    }
};

int main() {
    HLD h(5);
    for (auto [u, v] : vector<std::pair<int, int>>{{0, 1}, {0, 2}, {1, 3}, {1, 4}}) {
        h.add_edge(u, v);
    }
    h.build(0);
    assert(h.lca(3, 4) == 1);
    assert(h.pos[0] == 0);
    assert(h.heavy[0] == 1);
    return 0;
}
