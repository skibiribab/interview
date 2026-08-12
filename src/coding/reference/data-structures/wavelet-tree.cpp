// Wavelet tree — k-th smallest in subarray (static values)
// When: order statistics on values within [l,r]; moderate alphabet / compressed range.
// Time: O(log σ) per query (σ = value range); build O(n log σ)    Space: O(n log σ)
#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

struct WaveletTree {
    int lo, hi;
    WaveletTree* l = nullptr;
    WaveletTree* r = nullptr;
    vector<int> b;

    WaveletTree(vector<int>::iterator from, vector<int>::iterator to, int x, int y) : lo(x), hi(y) {
        if (from >= to || lo == hi)
            return;
        int mid = (lo + hi) / 2;
        auto left = [&](int v) { return v <= mid; };
        b.reserve((int)(to - from) + 1);
        b.push_back(0);
        for (auto it = from; it != to; ++it)
            b.push_back(b.back() + left(*it));
        auto pivot = std::stable_partition(from, to, left);
        l = new WaveletTree(from, pivot, lo, mid);
        r = new WaveletTree(pivot, to, mid + 1, hi);
    }

    int kth(int lt, int rt, int k) const {
        if (lt > rt)
            return 0;
        if (lo == hi)
            return lo;
        int inLeft = b[rt + 1] - b[lt];
        if (k <= inLeft)
            return l ? l->kth(b[lt], b[rt + 1] - 1, k) : 0;
        return r ? r->kth(lt - b[lt], rt - b[rt + 1], k - inLeft) : 0;
    }
};

int main() {
    vector<int> a = {1, 4, 2, 8, 5, 7};
    int mn = *std::min_element(a.begin(), a.end());
    int mx = *std::max_element(a.begin(), a.end());
    WaveletTree wt(a.begin(), a.end(), mn, mx);
    assert(wt.kth(0, 5, 3) == 4);
    return 0;
}
