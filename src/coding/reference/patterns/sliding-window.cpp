// Sliding window — fixed- or variable-size subarray invariant
// When: max sum of k, longest substring with ≤K distinct, min window substring template.
// Time: O(n) typical (each index enters/leaves once)    Space: O(1) or O(σ) for char counts
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <vector>

using std::vector;

// Maximum sum of any contiguous subarray of length k
static long long max_sum_subarray_k(const vector<int>& nums, int k) {
    int n = (int)nums.size();
    if (n < k || k <= 0)
        return 0;
    long long win = 0;
    for (int i = 0; i < k; ++i)
        win += nums[i];
    long long best = win;
    for (int i = k; i < n; ++i) {
        win += nums[i] - nums[i - k];
        if (win > best)
            best = win;
    }
    return best;
}

// Length of longest subarray with at most max_distinct different values
static int longest_subarray_at_most_k_distinct(const vector<int>& nums, int max_distinct) {
    std::unordered_map<int, int> cnt;
    int j = 0, best = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
        ++cnt[nums[i]];
        while ((int)cnt.size() > max_distinct) {
            int c = --cnt[nums[j]];
            if (c == 0)
                cnt.erase(nums[j]);
            ++j;
        }
        best = std::max(best, i - j + 1);
    }
    return best;
}

int main() {
    assert(max_sum_subarray_k({2, 1, 5, 1, 3, 2}, 3) == 9);
    assert(longest_subarray_at_most_k_distinct({1, 2, 1, 2, 3}, 2) == 4);
    return 0;
}
