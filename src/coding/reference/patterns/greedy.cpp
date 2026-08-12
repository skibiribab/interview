// Greedy — maximum non-overlapping intervals (activity selection by end time)
// When: proveable exchange argument; scheduling with one resource.
// Time: O(n log n)    Space: O(1) extra after sort
#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>

using std::vector;

struct Interval {
    int lo, hi;
};

static int max_non_overlapping(vector<Interval> a) {
    std::sort(a.begin(), a.end(), [](const Interval& x, const Interval& y) { return x.hi < y.hi; });
    int cnt = 0, last_end = std::numeric_limits<int>::min();
    for (const auto& iv : a)
        if (iv.lo >= last_end) {
            ++cnt;
            last_end = iv.hi;
        }
    return cnt;
}

int main() {
    vector<Interval> v{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    assert(max_non_overlapping(v) == 3);
    return 0;
}
