// Dinic — maximum flow (directed graph)
// When: matching reductions, vertex-disjoint paths, min-cut dual (see README).
// Time: O(E √V) typical; O(V²E) worst    Space: O(V+E)
#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

using std::vector;

struct Dinic {
    struct Edge {
        int to, rev;
        long long cap, flow;
    };
    int n, s, t;
    vector<vector<Edge>> g;
    vector<int> level, it;

    explicit Dinic(int n_) : n(n_), g(n_), level(n_), it(n_) {}

    void add_edge(int u, int v, long long cap) {
        Edge a{v, (int)g[v].size(), cap, 0};
        Edge b{u, (int)g[u].size(), 0, 0};
        g[u].push_back(a);
        g[v].push_back(b);
    }

    bool bfs() {
        fill(level.begin(), level.end(), -1);
        std::queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& e : g[v]) {
                if (e.cap > e.flow && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] >= 0;
    }

    long long dfs(int v, long long f) {
        if (v == t)
            return f;
        for (int& i = it[v]; i < (int)g[v].size(); ++i) {
            Edge& e = g[v][i];
            if (e.cap > e.flow && level[v] < level[e.to]) {
                long long ret = dfs(e.to, std::min(f, e.cap - e.flow));
                if (ret > 0) {
                    e.flow += ret;
                    g[e.to][e.rev].flow -= ret;
                    return ret;
                }
            }
        }
        return 0;
    }

    long long max_flow(int source, int sink) {
        s = source;
        t = sink;
        long long flow = 0, inf = (1LL << 62);
        while (bfs()) {
            fill(it.begin(), it.end(), 0);
            long long f;
            while ((f = dfs(s, inf)) > 0)
                flow += f;
        }
        return flow;
    }
};

int main() {
    Dinic d(4);
    d.add_edge(0, 1, 3);
    d.add_edge(0, 2, 2);
    d.add_edge(1, 2, 1);
    d.add_edge(1, 3, 1);
    d.add_edge(2, 3, 3);
    assert(d.max_flow(0, 3) == 4);
    return 0;
}
