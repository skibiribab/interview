// Fenwick tree (binary indexed tree) — prefix sums, point updates
// When: invertible prefix/range sums, inversions; simpler than segment tree for many tasks.
// Time: O(log n) add & prefix    Space: O(n)
#include <cassert>
#include <vector>

using std::vector;

struct Fenwick {
    int n;
    vector<long long> bit;
    explicit Fenwick(int n_) : n(n_), bit(n_ + 1, 0) {}
    void add(int idx, long long delta) { // 0-based idx
        for (int i = idx + 1; i <= n; i += i & -i)
            bit[i] += delta;
    }
    long long pref(int idx) const { // sum [0..idx]
        long long s = 0;
        for (int i = idx + 1; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
    long long range_sum(int l, int r) const { return pref(r) - (l ? pref(l - 1) : 0); }
};

int main() {
    Fenwick ft(5);
    for (int i = 0; i < 5; ++i)
        ft.add(i, i + 1); // values 1..5
    assert(ft.range_sum(1, 3) == 2 + 3 + 4);
    return 0;
}
