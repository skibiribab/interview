// Min-cost max-flow — successive shortest augmenting paths (integer costs)
// When: assign flows with linear cost; small/medium graphs (SPFA sensitive to worst case).
// Time: O(flow · VE) worst case per augmentation style    Space: O(V+E)
#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

using std::vector;

struct MinCostMaxFlow {
    struct Edge {
        int to, rev;
        int cap, flow;
        int cost;
    };
    int n, s, t;
    vector<vector<Edge>> g;
    vector<int> dist, pe, pv;
    vector<char> inq;

    explicit MinCostMaxFlow(int n_) : n(n_), g(n_), dist(n_), pe(n_), pv(n_), inq(n_) {}

    void add_edge(int u, int v, int cap, int cost) {
        Edge a{v, (int)g[v].size(), cap, 0, cost};
        Edge b{u, (int)g[u].size(), 0, 0, -cost};
        g[u].push_back(a);
        g[v].push_back(b);
    }

    bool spfa() {
        const int INF = 1e9;
        fill(dist.begin(), dist.end(), INF);
        fill(inq.begin(), inq.end(), 0);
        std::queue<int> q;
        dist[s] = 0;
        q.push(s);
        inq[s] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            inq[v] = 0;
            for (int i = 0; i < (int)g[v].size(); ++i) {
                Edge& e = g[v][i];
                if (e.cap > e.flow && dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    pe[e.to] = i;
                    pv[e.to] = v;
                    if (!inq[e.to]) {
                        inq[e.to] = 1;
                        q.push(e.to);
                    }
                }
            }
        }
        return dist[t] < INF;
    }

    std::pair<int, long long> run(int source, int sink) {
        s = source;
        t = sink;
        int flow = 0;
        long long cost = 0;
        while (spfa()) {
            int add = 1e9;
            for (int v = t; v != s; v = pv[v]) {
                Edge& e = g[pv[v]][pe[v]];
                add = std::min(add, e.cap - e.flow);
            }
            for (int v = t; v != s; v = pv[v]) {
                Edge& e = g[pv[v]][pe[v]];
                e.flow += add;
                g[e.to][e.rev].flow -= add;
            }
            flow += add;
            cost += 1LL * add * dist[t];
        }
        return {flow, cost};
    }
};

int main() {
    MinCostMaxFlow m(4);
    m.add_edge(0, 1, 2, 1);
    m.add_edge(0, 2, 1, 2);
    m.add_edge(1, 3, 2, 0);
    m.add_edge(2, 3, 1, 0);
    auto [f, c] = m.run(0, 3);
    assert(f == 2);
    assert(c == 2);
    return 0;
}
