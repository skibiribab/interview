// Bipartite matching — augmenting paths (Kuhn DFS), nL × nR bipartite graph
// When: assign workers to tasks, maximum matching on small/medium sparse graphs.
// Time: O(VE) worst    Space: O(V+E)
#include <cassert>
#include <vector>

using std::vector;

struct BipartiteMatch {
    int nL, nR;
    vector<vector<int>> g; // left u -> list of right nodes
    vector<int> matchR, vis;
    int token = 1;

    BipartiteMatch(int nl, int nr) : nL(nl), nR(nr), g(nl), matchR(nr, -1), vis(nr, 0) {}

    void add_edge(int u_left, int v_right) { g[u_left].push_back(v_right); }

    bool dfs(int u) {
        for (int v : g[u]) {
            if (vis[v] == token)
                continue;
            vis[v] = token;
            if (matchR[v] == -1 || dfs(matchR[v])) {
                matchR[v] = u;
                return true;
            }
        }
        return false;
    }

    int max_matching() {
        int cnt = 0;
        for (int u = 0; u < nL; ++u) {
            ++token;
            if (dfs(u))
                ++cnt;
        }
        return cnt;
    }
};

int main() {
    BipartiteMatch m(2, 2);
    m.add_edge(0, 0);
    m.add_edge(0, 1);
    m.add_edge(1, 1);
    assert(m.max_matching() == 2);
    return 0;
}
