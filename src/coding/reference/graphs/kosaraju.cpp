// Kosaraju — strongly connected components
// When: list all SCCs; two-pass DFS on G and G^T.
// Time: O(V+E)    Space: O(V+E)
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

using std::vector;

struct Kosaraju {
    int n;
    vector<vector<int>> g, gt;
    vector<int> comp;

    explicit Kosaraju(int n_) : n(n_), g(n_), gt(n_), comp(n_, -1) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        gt[v].push_back(u);
    }

    void dfs1(int v, vector<char>& vis, std::stack<int>& order) {
        vis[v] = 1;
        for (int u : g[v])
            if (!vis[u])
                dfs1(u, vis, order);
        order.push(v);
    }

    void dfs2(int v, int cid, vector<char>& vis) {
        vis[v] = 1;
        comp[v] = cid;
        for (int u : gt[v])
            if (!vis[u])
                dfs2(u, cid, vis);
    }

    int build() {
        vector<char> vis(n);
        std::stack<int> order;
        for (int i = 0; i < n; ++i)
            if (!vis[i])
                dfs1(i, vis, order);
        fill(vis.begin(), vis.end(), 0);
        int cid = 0;
        while (!order.empty()) {
            int v = order.top();
            order.pop();
            if (!vis[v])
                dfs2(v, cid++, vis);
        }
        return cid;
    }
};

int main() {
    Kosaraju k(6);
    k.add_edge(0, 1);
    k.add_edge(1, 2);
    k.add_edge(2, 0);
    k.add_edge(3, 4);
    k.add_edge(4, 5);
    k.add_edge(5, 3);
    k.add_edge(1, 3);
    int c = k.build();
    assert(c == 2);
    std::cout << "kosaraju ok\n";
    return 0;
}
