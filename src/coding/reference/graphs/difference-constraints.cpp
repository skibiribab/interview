// Difference constraints — x_j - x_i ≤ c_k via Bellman–Ford / SPFA on constraint graph
// When: schedule / inequality systems; detect negative cycle ⇒ unsatisfiable.
// Time: O(n·m)    Space: O(n+m)
#include <cassert>
#include <tuple>
#include <vector>

using std::vector;

// Constraints: x[v] - x[u] ≤ w  ⇒ edge u→v weight w
// Returns potentials x[0..n-1] with x[i]-x[0] relative, or empty if impossible.
static vector<long long> difference_constraints(int n,
                                                const vector<std::tuple<int, int, long long>>& cons) {
    vector<vector<std::pair<int, long long>>> g(n + 1);
    for (auto [u, v, w] : cons)
        g[u].push_back({v, w});
    // Super-source 0 → all, weight 0 (allow disconnected)
    for (int i = 1; i <= n; ++i)
        g[0].push_back({i, 0});

    const long long INF = 4e18;
    vector<long long> dist(n + 1, INF);
    dist[0] = 0;
    for (int it = 0; it < n; ++it) {
        bool any = false;
        for (int u = 0; u <= n; ++u)
            if (dist[u] < INF)
                for (auto [v, w] : g[u])
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        any = true;
                    }
        if (!any)
            break;
    }
    for (int u = 0; u <= n; ++u)
        if (dist[u] < INF)
            for (auto [v, w] : g[u])
                if (dist[v] > dist[u] + w)
                    return {};
    return vector<long long>(dist.begin() + 1, dist.end());
}

int main() {
    // x2-x1≤2, x1-x2≤-1 ⇒ x2-x1≤2 and x1-x2≤-1 → consistent
    auto x = difference_constraints(2, {{1, 2, 2}, {2, 1, -1}});
    assert(!x.empty());
    assert(x[1] - x[0] <= 2 && x[0] - x[1] <= -1);
    return 0;
}
