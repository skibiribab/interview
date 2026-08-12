// Persistent segment tree — point set, prefix / k-th on versioned prefixes
// When: k-th smallest on [1..r] after inserts; offline range k-th queries.
// Time: O(log V) per update/query    Space: O(n log V)
#include <cassert>
#include <vector>

using std::vector;

struct PersistentSeg {
    struct Node {
        int l = 0, r = 0, sum = 0;
    };
    vector<Node> t;
    int MAXV;

    explicit PersistentSeg(int maxv) : MAXV(maxv) {
        t.reserve(1 << 20);
        t.push_back({}); // 0 = null
    }

    int upd(int prev, int lo, int hi, int pos, int delta) {
        int cur = (int)t.size();
        t.push_back(t[prev]);
        t[cur].sum += delta;
        if (lo == hi)
            return cur;
        int mid = (lo + hi) / 2;
        if (pos <= mid)
            t[cur].l = upd(t[prev].l, lo, mid, pos, delta);
        else
            t[cur].r = upd(t[prev].r, mid + 1, hi, pos, delta);
        return cur;
    }

    int set(int prev, int pos, int delta) { return upd(prev, 1, MAXV, pos, delta); }

    // k-th (1-indexed) among values in (left_ver, right_ver] as multisets of ranks
    int kth(int left, int right, int k) const {
        int lo = 1, hi = MAXV;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int cnt = t[t[right].l].sum - t[t[left].l].sum;
            if (cnt >= k) {
                left = t[left].l;
                right = t[right].l;
                hi = mid;
            } else {
                k -= cnt;
                left = t[left].r;
                right = t[right].r;
                lo = mid + 1;
            }
        }
        return lo;
    }
};

int main() {
    // values compressed to ranks 1..3: insert 2,1,3
    PersistentSeg st(3);
    int v0 = 0;
    int v1 = st.set(v0, 2, 1);
    int v2 = st.set(v1, 1, 1);
    int v3 = st.set(v2, 3, 1);
    assert(st.kth(v0, v3, 1) == 1);
    assert(st.kth(v0, v3, 2) == 2);
    assert(st.kth(v0, v3, 3) == 3);
    return 0;
}
