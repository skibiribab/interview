// 0/1 knapsack — max value with weight ≤ W (one copy per item)
// When: resource allocation, subset sum with weights, bounded DP on small W.
// Time: O(nW)    Space: O(W)
#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

static int knapsack01(int W, const vector<int>& wt, const vector<int>& val) {
    vector<int> dp(W + 1, 0);
    for (size_t i = 0; i < wt.size(); ++i)
        for (int w = W; w >= wt[i]; --w)
            dp[w] = std::max(dp[w], dp[w - wt[i]] + val[i]);
    return dp[W];
}

int main() {
    // weights 1+4+5 = 10, values 1+5+7 = 13
    assert(knapsack01(10, {1, 3, 4, 5}, {1, 4, 5, 7}) == 13);
    return 0;
}
