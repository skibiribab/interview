// Hopcroft–Karp — maximum bipartite matching (faster than Kuhn)
// When: large bipartite matching; |E|√|V| expected.
// Time: O(E √V)    Space: O(V+E)
#include <cassert>
#include <queue>
#include <vector>

using std::vector;

struct HopcroftKarp {
    int n_left, n_right;
    vector<vector<int>> g; // left → right
    vector<int> pairu, pairv, dist;

    HopcroftKarp(int L, int R) : n_left(L), n_right(R), g(L + 1), pairu(L + 1), pairv(R + 1), dist(L + 1) {}

    void add_edge(int u, int v) { g[u].push_back(v); } // 1-based

    bool bfs() {
        std::queue<int> q;
        for (int u = 1; u <= n_left; ++u) {
            if (!pairu[u]) {
                dist[u] = 0;
                q.push(u);
            } else
                dist[u] = -1;
        }
        bool found = false;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                int u2 = pairv[v];
                if (!u2)
                    found = true;
                else if (dist[u2] < 0) {
                    dist[u2] = dist[u] + 1;
                    q.push(u2);
                }
            }
        }
        return found;
    }

    bool dfs(int u) {
        for (int v : g[u]) {
            int u2 = pairv[v];
            if (!u2 || (dist[u2] == dist[u] + 1 && dfs(u2))) {
                pairu[u] = v;
                pairv[v] = u;
                return true;
            }
        }
        dist[u] = -1;
        return false;
    }

    int max_matching() {
        int match = 0;
        while (bfs())
            for (int u = 1; u <= n_left; ++u)
                if (!pairu[u] && dfs(u))
                    ++match;
        return match;
    }
};

int main() {
    HopcroftKarp hk(3, 3);
    hk.add_edge(1, 1);
    hk.add_edge(1, 2);
    hk.add_edge(2, 2);
    hk.add_edge(3, 3);
    assert(hk.max_matching() == 3);
    return 0;
}
