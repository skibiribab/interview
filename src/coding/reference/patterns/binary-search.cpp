// Binary search — lower bound on sorted array; monotone “search on answer” template
// When: first ≥ x, rotated array pivots, minimize max / maximize min with feasible(mid).
// Time: O(log n) on array; O(log U·check) on answer    Space: O(1)
#include <cassert>
#include <vector>

using std::vector;

// First index in non-decreasing a with a[i] >= x
static int lower_bound(const vector<int>& a, int x) {
    int lo = 0, hi = (int)a.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < x)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

// Minimum k such that k * k >= target (integer sqrt ceil style)
static int min_k_square_at_least(int target) {
    int lo = 1, hi = target;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (1LL * mid * mid >= target)
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

int main() {
    vector<int> a{1, 2, 2, 4};
    assert(lower_bound(a, 2) == 1);
    assert(lower_bound(a, 3) == 3);
    assert(min_k_square_at_least(10) == 4);
    return 0;
}
