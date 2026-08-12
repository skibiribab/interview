// Segment tree — point assign, range sum (recursive)
// When: range sums with point updates; use lazy variant for range updates.
// Time: O(log n) query/update, O(n) build    Space: O(n)
#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

struct SegTree {
    int n;
    vector<long long> t;

    explicit SegTree(const vector<int>& a) : n((int)a.size()), t(4 * std::max(1, (int)a.size())) {
        if (n > 0)
            build(1, 0, n - 1, a);
    }

    void build(int v, int tl, int tr, const vector<int>& a) {
        if (tl == tr) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, a);
        build(v * 2 + 1, tm + 1, tr, a);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }

    long long sum(int v, int tl, int tr, int l, int r) const {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return sum(v * 2, tl, tm, l, std::min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r);
    }

    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr)
            t[v] = val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    long long range_sum(int l, int r) const { return n ? sum(1, 0, n - 1, l, r) : 0; }
    void set(int pos, int val) {
        if (n)
            update(1, 0, n - 1, pos, val);
    }
};

int main() {
    SegTree st({1, 2, 3, 4});
    assert(st.range_sum(1, 2) == 5);
    st.set(1, 10);
    assert(st.range_sum(0, 3) == 18);
    return 0;
}
