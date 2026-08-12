// DP on strings — longest common subsequence (LCS) length
// When: edit distance family, diff-like problems, subsequence matching.
// Time: O(nm)    Space: O(min(n,m)) rolling
#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using std::vector;

static int lcs(const std::string& a, const std::string& b) {
    int n = (int)a.size(), m = (int)b.size();
    vector<int> dp(m + 1);
    for (int i = 1; i <= n; ++i) {
        int prev = 0;
        for (int j = 1; j <= m; ++j) {
            int tmp = dp[j];
            if (a[i - 1] == b[j - 1])
                dp[j] = prev + 1;
            else
                dp[j] = std::max(dp[j], dp[j - 1]);
            prev = tmp;
        }
    }
    return dp[m];
}

int main() {
    assert(lcs("abcde", "ace") == 3);
    return 0;
}
