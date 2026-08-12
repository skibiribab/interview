// Sparse table — static range minimum (RMQ) with O(1) queries
// When: array does not change; idempotent min/max/gcd over ranges.
// Time: O(n log n) build, O(1) query    Space: O(n log n)
#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

struct SparseMin {
    int n, lg;
    vector<vector<int>> st;
    explicit SparseMin(const vector<int>& a) : n((int)a.size()) {
        if (n == 0)
            return;
        lg = 1;
        while ((1 << lg) <= n)
            ++lg;
        st.assign(lg, vector<int>(n));
        st[0] = a;
        for (int k = 1; k < lg; ++k)
            for (int i = 0; i + (1 << k) <= n; ++i)
                st[k][i] = std::min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
    }
    int rmq(int l, int r) const { // inclusive
        int len = r - l + 1;
        int k = 0;
        while ((1 << (k + 1)) <= len)
            ++k;
        return std::min(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

int main() {
    SparseMin st({5, 2, 8, 1, 7});
    assert(st.rmq(0, 4) == 1);
    assert(st.rmq(1, 2) == 2);
    return 0;
}
