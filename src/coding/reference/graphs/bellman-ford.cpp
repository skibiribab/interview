// Bellman–Ford — single-source shortest paths with negative edges
// When: negative weights allowed; detect negative cycles reachable from source.
// Time: O(VE)    Space: O(V)
#include <cassert>
#include <tuple>
#include <vector>

using std::vector;

static const long long INF = (1LL << 60);

// Returns {dist, has_negative_cycle}.
static std::pair<vector<long long>, bool> bellman_ford(int n, int s,
                                                       const vector<std::tuple<int, int, int>>& edges) {
    vector<long long> dist(n, INF);
    dist[s] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INF && dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }
    bool neg = false;
    for (auto [u, v, w] : edges) {
        if (dist[u] != INF && dist[v] > dist[u] + w) {
            neg = true;
            break;
        }
    }
    return {dist, neg};
}

int main() {
    vector<std::tuple<int, int, int>> edges = {{0, 1, 1}, {1, 2, -2}, {0, 2, 4}};
    auto [dist, neg] = bellman_ford(3, 0, edges);
    assert(!neg);
    assert(dist[2] == -1);
    vector<std::tuple<int, int, int>> cycle = {{0, 1, -1}, {1, 0, -1}};
    auto [d2, neg2] = bellman_ford(2, 0, cycle);
    assert(neg2);
    return 0;
}
