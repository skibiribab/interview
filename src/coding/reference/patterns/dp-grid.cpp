// DP on grid — unique paths (right/down only)
// When: grid counting, obstacle variants, path existence with small state.
// Time: O(mn)    Space: O(n) one row
#include <cassert>
#include <vector>

using std::vector;

static int unique_paths(int m, int n) {
    vector<int> dp(n, 1);
    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            dp[j] += dp[j - 1];
    return dp[n - 1];
}

int main() {
    assert(unique_paths(3, 7) == 28);
    return 0;
}
