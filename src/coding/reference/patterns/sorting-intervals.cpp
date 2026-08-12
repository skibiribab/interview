// Intervals — merge overlapping after sort by start
// When: calendar blocking, meeting rooms base, skyline-style prep.
// Time: O(n log n) + O(n)    Space: O(n) output
#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

struct Interval {
    int lo, hi;
};

static vector<Interval> merge_intervals(vector<Interval> a) {
    if (a.empty())
        return {};
    std::sort(a.begin(), a.end(), [](const Interval& x, const Interval& y) { return x.lo < y.lo; });
    vector<Interval> out;
    out.push_back(a[0]);
    for (size_t i = 1; i < a.size(); ++i) {
        if (a[i].lo <= out.back().hi)
            out.back().hi = std::max(out.back().hi, a[i].hi);
        else
            out.push_back(a[i]);
    }
    return out;
}

int main() {
    auto m = merge_intervals({{1, 3}, {2, 6}, {8, 10}, {15, 18}});
    assert(m.size() == 3 && m[0].lo == 1 && m[0].hi == 6);
    return 0;
}
