// Two pointers — opposite ends on sorted array (or partition-style scans)
// When: sorted two-sum, water container style, partitioning with two indices.
// Time: O(n)    Space: O(1)
#include <cassert>
#include <vector>

using std::vector;

// Returns {i, j} 1-based if nums[i-1] + nums[j-1] == target, else {-1,-1}
static vector<int> two_sum_sorted(const vector<int>& nums, int target) {
    int lo = 0, hi = (int)nums.size() - 1;
    while (lo < hi) {
        int s = nums[lo] + nums[hi];
        if (s == target)
            return {lo + 1, hi + 1};
        if (s < target)
            ++lo;
        else
            --hi;
    }
    return {-1, -1};
}

int main() {
    vector<int> a{1, 2, 3, 4, 5};
    assert((two_sum_sorted(a, 9) == vector<int>{4, 5}));
    assert((two_sum_sorted(a, 99) == vector<int>{-1, -1}));
    return 0;
}
