// Tarjan — strongly connected components (lowlink DFS + stack)
// When: condensation graph, 2-SAT skeletons, “same cycle” grouping on directed graphs.
// Time: O(V+E)    Space: O(V)
#include <algorithm>
#include <cassert>
#include <stack>
#include <vector>

using std::vector;

struct Tarjan {
    int n, timer = 0, scc = 0;
    vector<vector<int>> g;
    vector<int> disc, low, instk;
    std::stack<int> st;
    vector<int> comp; // node -> component id

    explicit Tarjan(int n_) : n(n_), g(n_), disc(n_, -1), low(n_), instk(n_, 0), comp(n_, -1) {}

    void add_edge(int u, int v) { g[u].push_back(v); }

    void dfs(int u) {
        disc[u] = low[u] = timer++;
        st.push(u);
        instk[u] = 1;
        for (int v : g[u]) {
            if (disc[v] == -1) {
                dfs(v);
                low[u] = std::min(low[u], low[v]);
            } else if (instk[v])
                low[u] = std::min(low[u], disc[v]);
        }
        if (low[u] == disc[u]) {
            while (true) {
                int x = st.top();
                st.pop();
                instk[x] = 0;
                comp[x] = scc;
                if (x == u)
                    break;
            }
            ++scc;
        }
    }

    void run() {
        for (int i = 0; i < n; ++i)
            if (disc[i] == -1)
                dfs(i);
    }
};

int main() {
    Tarjan t(3);
    t.add_edge(0, 1);
    t.add_edge(1, 2);
    t.add_edge(2, 0);
    t.run();
    assert(t.comp[0] == t.comp[1] && t.comp[1] == t.comp[2]);
    return 0;
}
