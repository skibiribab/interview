// Prefix sum & difference array — O(1) range sums after O(n) build; range adds via diff
// When: static ranges, many queries; offline range updates then final values.
// Time: build O(n), range sum O(1)    Space: O(n)
#include <cassert>
#include <cstddef>
#include <vector>

using std::vector;

struct PrefixSum {
    vector<long long> p; // size n+1, p[0]=0
    explicit PrefixSum(const vector<int>& nums) : p(nums.size() + 1, 0) {
        for (size_t i = 0; i < nums.size(); ++i)
            p[i + 1] = p[i] + nums[i];
    }
    // inclusive range [l, r]
    long long range_sum(int l, int r) const { return p[r + 1] - p[l]; }
};

struct DifferenceArray {
    vector<int> diff;
    explicit DifferenceArray(int n) : diff(n + 1, 0) {}
    void range_add(int l, int r, int v) {
        diff[l] += v;
        diff[r + 1] -= v;
    }
    vector<int> recover(int n) const {
        vector<int> a(n);
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += diff[i];
            a[i] = cur;
        }
        return a;
    }
};

int main() {
    vector<int> v{1, 2, 3, 4};
    PrefixSum ps(v);
    assert(ps.range_sum(1, 2) == 5);
    DifferenceArray d(5);
    d.range_add(1, 3, 10);
    d.range_add(2, 4, 5);
    auto a = d.recover(5);
    assert(a == vector<int>({0, 10, 15, 15, 5}));
    return 0;
}
