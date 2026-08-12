// Time vs space — same problem (two-sum) with hash vs sort + two pointers
// When: interviewer asks for O(1) extra space or immutable input tradeoffs.
// Time: O(n) hash vs O(n log n) sort+two pointers    Space: O(n) vs O(1) extra (if in-place sort ok)
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <vector>

using std::vector;

static vector<int> two_sum_hash(const vector<int>& nums, int target) {
    std::unordered_map<int, int> pos;
    for (int i = 0; i < (int)nums.size(); ++i) {
        int need = target - nums[i];
        auto it = pos.find(need);
        if (it != pos.end())
            return {it->second, i};
        pos[nums[i]] = i;
    }
    return {-1, -1};
}

static vector<int> two_sum_sort_twopointer(vector<int> nums, int target) {
    vector<std::pair<int, int>> vp;
    for (int i = 0; i < (int)nums.size(); ++i)
        vp.push_back({nums[i], i});
    std::sort(vp.begin(), vp.end());
    int lo = 0, hi = (int)vp.size() - 1;
    while (lo < hi) {
        int s = vp[lo].first + vp[hi].first;
        if (s == target)
            return {vp[lo].second, vp[hi].second};
        if (s < target)
            ++lo;
        else
            --hi;
    }
    return {-1, -1};
}

static bool same_pair(vector<int> x, vector<int> y) {
    if (x[0] > x[1])
        std::swap(x[0], x[1]);
    if (y[0] > y[1])
        std::swap(y[0], y[1]);
    return x == y;
}

int main() {
    vector<int> a{3, 1, 4, 2};
    assert(same_pair(two_sum_hash(a, 6), two_sum_sort_twopointer(a, 6)));
    return 0;
}
