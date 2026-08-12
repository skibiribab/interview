// Block-cut tree — biconnected components + articulation points condensation
// When: queries on bridges/arts; path uniqueness through cut vertices.
// Time: O(V+E)    Space: O(V+E)
#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

struct BlockCut {
    int n, timer = 0, bcc_cnt = 0;
    vector<vector<int>> g, tree;
    vector<int> tin, low, art;
    vector<std::pair<int, int>> st;
    vector<vector<int>> comps; // edge-biconnected components as vertex lists

    explicit BlockCut(int n_) : n(n_), g(n_), tin(n_, -1), low(n_), art(n_, 0) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void dfs(int u, int p) {
        tin[u] = low[u] = timer++;
        int children = 0;
        for (int v : g[u]) {
            if (v == p)
                continue;
            if (tin[v] != -1) {
                low[u] = std::min(low[u], tin[v]);
                if (tin[v] < tin[u])
                    st.push_back({u, v});
            } else {
                st.push_back({u, v});
                dfs(v, u);
                low[u] = std::min(low[u], low[v]);
                if (low[v] >= tin[u]) {
                    if (p != -1)
                        art[u] = 1;
                    vector<int> comp;
                    while (true) {
                        auto e = st.back();
                        st.pop_back();
                        comp.push_back(e.first);
                        comp.push_back(e.second);
                        if (e.first == u && e.second == v)
                            break;
                    }
                    std::sort(comp.begin(), comp.end());
                    comp.erase(std::unique(comp.begin(), comp.end()), comp.end());
                    comps.push_back(comp);
                    ++bcc_cnt;
                }
                ++children;
            }
        }
        if (p == -1 && children > 1)
            art[u] = 1;
    }

    void build() {
        for (int i = 0; i < n; ++i)
            if (tin[i] < 0)
                dfs(i, -1);
    }
};

int main() {
    BlockCut bc(4);
    bc.add_edge(0, 1);
    bc.add_edge(1, 2);
    bc.add_edge(1, 3);
    bc.build();
    assert(bc.art[1] == 1);
    assert(bc.bcc_cnt >= 1);
    return 0;
}
