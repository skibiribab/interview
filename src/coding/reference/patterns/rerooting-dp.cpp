// Rerooting DP — compute f(root) for every choice of root in O(n)
// When: for-each-root answers on trees (sum distances, max path from root, …).
// Time: O(n)    Space: O(n)
#include <cassert>
#include <functional>
#include <vector>

using std::vector;

// Example: for each root, sum of distances to all nodes.
static vector<long long> sum_distances_all_roots(int n, const vector<vector<int>>& g) {
    vector<int> sub(n, 1);
    vector<long long> down(n, 0), ans(n, 0);

    std::function<void(int, int)> dfs1 = [&](int u, int p) {
        for (int v : g[u]) {
            if (v == p)
                continue;
            dfs1(v, u);
            sub[u] += sub[v];
            down[u] += down[v] + sub[v];
        }
    };
    dfs1(0, -1);
    ans[0] = down[0];

    std::function<void(int, int)> dfs2 = [&](int u, int p) {
        for (int v : g[u]) {
            if (v == p)
                continue;
            ans[v] = ans[u] - sub[v] + (n - sub[v]);
            dfs2(v, u);
        }
    };
    dfs2(0, -1);
    return ans;
}

int main() {
    // Path 0-1-2
    vector<vector<int>> g(3);
    g[0] = {1};
    g[1] = {0, 2};
    g[2] = {1};
    auto a = sum_distances_all_roots(3, g);
    assert(a[0] == 3 && a[1] == 2 && a[2] == 3);
    return 0;
}
