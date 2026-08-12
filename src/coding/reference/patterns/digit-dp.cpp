// Digit DP — count numbers in [0, N] with a digit property
// When: count valid numbers with digit constraints, leading zeros, modular digit sums.
// Time: O(log N · states)    Space: O(log N · states)
#include <cassert>
#include <string>
#include <vector>

static int count_without_adjacent_equal(const std::string& n) {
    const int len = static_cast<int>(n.size());
    std::vector<int> digits(len);
    for (int i = 0; i < len; ++i) {
        digits[i] = n[i] - '0';
    }
    std::vector<std::vector<std::vector<int>>> memo(
        len, std::vector<std::vector<int>>(2, std::vector<int>(11, -1)));

    const auto dfs = [&](auto&& self, int pos, int tight, int prev) -> int {
        if (pos == len) {
            return 1;
        }
        if (memo[pos][tight][prev + 1] != -1) {
            return memo[pos][tight][prev + 1];
        }
        const int limit = tight ? digits[pos] : 9;
        int ways = 0;
        for (int d = 0; d <= limit; ++d) {
            if (prev != -1 && d == prev) {
                continue;
            }
            ways += self(self, pos + 1, tight && d == limit, d);
        }
        return memo[pos][tight][prev + 1] = ways;
    };

    return dfs(dfs, 0, 1, -1);
}

int main() {
    assert(count_without_adjacent_equal("0") == 1);
    assert(count_without_adjacent_equal("12") == 11);
    return 0;
}
