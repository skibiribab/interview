// 2-SAT — implication graph + Tarjan SCC; assign true/false or report unsat
// When: (a ∨ b) clauses, scheduling with pairs of choices, grid parity constraints.
// Time: O(V+E)    Space: O(V+E)
#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

struct TwoSat {
    int n;
    vector<vector<int>> g;
    vector<int> comp, order, used;
    vector<char> val;

    explicit TwoSat(int vars) : n(vars), g(2 * vars), comp(2 * vars), used(2 * vars), val(2 * vars) {}

    // literal: variable v, neg=false means x_v; neg=true means ¬x_v
    static int lit(int v, bool neg) { return 2 * v + (neg ? 0 : 1); }

    void either(int a, bool na, int b, bool nb) {
        int la = lit(a, na);
        int lb = lit(b, nb);
        g[lit(a, !na)].push_back(lb);
        g[lit(b, !nb)].push_back(la);
    }

    void unit(int a, bool na) { either(a, na, a, na); }

    void dfs1(int v) {
        used[v] = 1;
        for (int u : g[v])
            if (!used[u])
                dfs1(u);
        order.push_back(v);
    }

    void dfs2(int v, int c, const vector<vector<int>>& gr) {
        comp[v] = c;
        for (int u : gr[v])
            if (comp[u] == -1)
                dfs2(u, c, gr);
    }

    bool solve() {
        for (int i = 0; i < 2 * n; ++i)
            if (!used[i])
                dfs1(i);
        vector<vector<int>> gr(2 * n);
        for (int u = 0; u < 2 * n; ++u)
            for (int v : g[u])
                gr[v].push_back(u);
        std::fill(comp.begin(), comp.end(), -1);
        int j = 0;
        for (int i = 2 * n - 1; i >= 0; --i) {
            int v = order[i];
            if (comp[v] == -1)
                dfs2(v, j++, gr);
        }
        for (int i = 0; i < n; ++i) {
            if (comp[2 * i] == comp[2 * i + 1])
                return false;
            val[i] = comp[2 * i] < comp[2 * i + 1];
        }
        return true;
    }
};

int main() {
    TwoSat ts(2);
    ts.either(0, false, 1, false); // x0 ∨ x1
    ts.either(0, true, 1, true);   // ¬x0 ∨ ¬x1
    assert(ts.solve());
    assert(ts.val[0] != ts.val[1]);

    TwoSat bad(1);
    bad.unit(0, false); // x0
    bad.unit(0, true);  // ¬x0
    assert(!bad.solve());
    return 0;
}
