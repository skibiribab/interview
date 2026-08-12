// Shortest paths — BFS (unweighted) and Dijkstra (non-negative weights)
// When: unweighted layers or single-source cheapest route with non-negative edges.
// Time: BFS O(V+E); Dijkstra O((V+E) log V)    Space: O(V+E)
#include <algorithm>
#include <cassert>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using std::vector;

static int bfs_shortest_hops(int n, const vector<std::pair<int, int>>& und_edges, int s, int t) {
    vector<vector<int>> g(n);
    for (auto [u, v] : und_edges) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    const int INF = 1e9;
    vector<int> dist(n, INF);
    std::queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t)
            return dist[t];
        for (int v : g[u])
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
    return dist[t];
}

static int dijkstra(int n, const vector<std::tuple<int, int, int>>& directed_w, int s, int t) {
    vector<vector<std::pair<int, int>>> g(n);
    for (auto [u, v, w] : directed_w)
        g[u].push_back({v, w});
    const int INF = 1e9;
    vector<int> dist(n, INF);
    using P = std::pair<int, int>;
    std::priority_queue<P, vector<P>, std::greater<P>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u])
            continue;
        if (u == t)
            return d;
        for (auto [v, w] : g[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[t];
}

int main() {
    assert(bfs_shortest_hops(4, {{0, 1}, {1, 2}, {2, 3}}, 0, 3) == 3);
    assert(dijkstra(3, {{0, 1, 4}, {0, 2, 1}, {2, 1, 1}}, 0, 1) == 2);
    return 0;
}
