// Sqrt decomposition — block size √n for range sum and point update
// When: simpler than segtree; offline/online range queries with moderate constraints.
// Time: O(√n) update/query    Space: O(n)
#include <cassert>
#include <cmath>
#include <vector>

using std::vector;

struct SqrtDecomp {
    vector<long long> a, block;
    int n, B;

    explicit SqrtDecomp(const vector<long long>& init) : a(init), n((int)init.size()) {
        B = std::max(1, (int)std::sqrt(n));
        block.assign((n + B - 1) / B, 0);
        for (int i = 0; i < n; ++i)
            block[i / B] += a[i];
    }

    void point_add(int i, long long delta) {
        a[i] += delta;
        block[i / B] += delta;
    }

    long long range_sum(int l, int r) const {
        long long s = 0;
        while (l <= r && l % B != 0)
            s += a[l++];
        while (l + B - 1 <= r) {
            s += block[l / B];
            l += B;
        }
        while (l <= r)
            s += a[l++];
        return s;
    }
};

int main() {
    SqrtDecomp sd({1, 2, 3, 4, 5});
    assert(sd.range_sum(1, 3) == 9);
    sd.point_add(2, 10);
    assert(sd.range_sum(1, 3) == 19);
    return 0;
}
