// Lazy segment tree — range add and range sum
// When: range updates + aggregation (e.g. add v to [l,r], query sum on [l,r]).
// Time: O(log n) per op    Space: O(n)
#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

struct LazySegTree {
    int n;
    vector<long long> t, lazy;

    explicit LazySegTree(int n_) : n(n_), t(4 * std::max(1, n_), 0), lazy(4 * std::max(1, n_), 0) {}

    void push(int v, int tl, int tr) {
        if (!lazy[v])
            return;
        int tm = (tl + tr) / 2;
        long long add = lazy[v];
        lazy[v] = 0;
        t[v * 2] += add * (tm - tl + 1);
        t[v * 2 + 1] += add * (tr - tm);
        lazy[v * 2] += add;
        lazy[v * 2 + 1] += add;
    }

    void range_add(int v, int tl, int tr, int l, int r, long long add) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            t[v] += add * (tr - tl + 1);
            lazy[v] += add;
            return;
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        range_add(v * 2, tl, tm, l, std::min(r, tm), add);
        range_add(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, add);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }

    long long range_sum(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return range_sum(v * 2, tl, tm, l, std::min(r, tm)) + range_sum(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r);
    }

    void range_add(int l, int r, long long add) {
        if (n)
            range_add(1, 0, n - 1, l, r, add);
    }
    long long range_sum(int l, int r) { return n ? range_sum(1, 0, n - 1, l, r) : 0; }
};

int main() {
    LazySegTree st(5);
    st.range_add(1, 3, 2);
    assert(st.range_sum(0, 4) == 6);
    st.range_add(2, 2, -1);
    assert(st.range_sum(1, 3) == 5);
    return 0;
}
