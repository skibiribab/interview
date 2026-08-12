// Bitmask DP — traveling salesman (Held–Karp) on n ≤ 20
// When: visit all nodes once, minimize cost; Hamiltonian path/cycle on small n.
// Time: O(n² · 2^n)    Space: O(n · 2^n)
#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

static const int INF = 1e9;

static int tsp_held_karp(const vector<vector<int>>& dist) {
    int n = (int)dist.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));
    dp[1][0] = 0;
    for (int mask = 1; mask < (1 << n); mask += 2) {
        for (int u = 0; u < n; ++u) {
            if (!(mask & (1 << u)) || dp[mask][u] == INF)
                continue;
            for (int v = 0; v < n; ++v) {
                if (mask & (1 << v))
                    continue;
                int nmask = mask | (1 << v);
                dp[nmask][v] = std::min(dp[nmask][v], dp[mask][u] + dist[u][v]);
            }
        }
    }
    int full = (1 << n) - 1;
    int ans = INF;
    for (int u = 1; u < n; ++u) {
        if (dp[full][u] != INF)
            ans = std::min(ans, dp[full][u] + dist[u][0]);
    }
    return ans;
}

int main() {
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0},
    };
    assert(tsp_held_karp(dist) == 80);
    return 0;
}
