// Convex hull trick — maintain lines for min query x·m+b (increasing slopes)
// When: DP transition dp[i]=min_j dp[j]+cost(j,i) with linear cost in j.
// Time: O(n) amortized insert/query with monotone slopes    Space: O(n)
#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>

using std::vector;

struct Line {
    long long m, b;
    long long eval(long long x) const { return m * x + b; }
};

struct ConvexHullTrick {
    vector<Line> hull;
    size_t ptr = 0;

    bool bad(const Line& l1, const Line& l2, const Line& l3) const {
        // Intersection(l1,l2) >= intersection(l2,l3) for min query with increasing m.
        return (l2.b - l1.b) * (l2.m - l3.m) >= (l2.b - l3.b) * (l2.m - l1.m);
    }

    void add(long long m, long long b) {
        Line ln{m, b};
        while (hull.size() >= 2 && bad(hull[hull.size() - 2], hull.back(), ln))
            hull.pop_back();
        hull.push_back(ln);
        if (ptr > hull.size() - 1)
            ptr = hull.size() - 1;
    }

    long long query(long long x) {
        while (ptr + 1 < hull.size() && hull[ptr + 1].eval(x) <= hull[ptr].eval(x))
            ptr++;
        return hull[ptr].eval(x);
    }
};

int main() {
    ConvexHullTrick cht;
    cht.add(1, 5);
    cht.add(2, 0);
    assert(cht.query(4) == 8);
    assert(cht.query(1) == 2);
    return 0;
}
