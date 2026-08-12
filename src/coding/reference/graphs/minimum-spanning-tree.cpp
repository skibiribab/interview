// Minimum spanning tree — Kruskal (DSU) and Prim (min-heap)
// When: connect all vertices at minimum total edge cost; forest → tree check.
// Time: Kruskal O(E log E); Prim O((V+E) log V)    Space: O(V+E)
#include <algorithm>
#include <cassert>
#include <queue>
#include <tuple>
#include <vector>

using std::vector;

struct DSU {
    vector<int> p, r;
    explicit DSU(int n) : p(n), r(n, 0) {
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (r[a] < r[b])
            std::swap(a, b);
        p[b] = a;
        if (r[a] == r[b])
            r[a]++;
        return true;
    }
};

static long long kruskal_mst(int n, vector<std::tuple<int, int, int>> edges) {
    std::sort(edges.begin(), edges.end(),
              [](const auto& a, const auto& b) { return std::get<2>(a) < std::get<2>(b); });
    DSU d(n);
    long long cost = 0;
    int used = 0;
    for (auto [u, v, w] : edges) {
        if (d.unite(u, v)) {
            cost += w;
            if (++used == n - 1)
                break;
        }
    }
    return used == n - 1 ? cost : -1;
}

static long long prim_mst(int n, const vector<vector<std::pair<int, int>>>& g) {
    const long long INF = (1LL << 60);
    vector<long long> dist(n, INF);
    vector<char> used(n, 0);
    using P = std::pair<long long, int>;
    std::priority_queue<P, vector<P>, std::greater<P>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    long long cost = 0;
    int taken = 0;
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (used[u])
            continue;
        used[u] = 1;
        cost += d;
        if (++taken == n)
            break;
        for (auto [v, w] : g[u]) {
            if (!used[v] && w < dist[v]) {
                dist[v] = w;
                pq.push({w, v});
            }
        }
    }
    return taken == n ? cost : -1;
}

int main() {
    vector<std::tuple<int, int, int>> edges = {{0, 1, 1}, {1, 2, 2}, {0, 2, 4}, {2, 3, 1}};
    assert(kruskal_mst(4, edges) == 4);
    vector<vector<std::pair<int, int>>> g(4);
    for (auto [u, v, w] : edges) {
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    assert(prim_mst(4, g) == 4);
    return 0;
}
