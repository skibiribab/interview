// Tree DP — maximum independent set on a tree (take / skip per node)
// When: select nodes with no adjacent pair; classic rooted tree DP template.
// Time: O(n)    Space: O(n)
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

using std::vector;

static std::pair<long long, long long> tree_mis_dfs(int u, int p, const vector<vector<int>>& g,
                                                    const vector<int>& w) {
    long long take = w[u];
    long long skip = 0;
    for (int v : g[u]) {
        if (v == p)
            continue;
        auto [t, s] = tree_mis_dfs(v, u, g, w);
        take += s;
        skip += std::max(t, s);
    }
    return {take, skip};
}

static long long max_independent_set(int n, const vector<vector<int>>& g, const vector<int>& w) {
    return tree_mis_dfs(0, -1, g, w).second;
}

int main() {
    vector<vector<int>> g(4);
    g[0] = {1, 2};
    g[1] = {0, 3};
    g[2] = {0};
    g[3] = {1};
    vector<int> w = {5, 1, 4, 3};
    assert(max_independent_set(4, g, w) == 12); // 5+4+3
    return 0;
}
