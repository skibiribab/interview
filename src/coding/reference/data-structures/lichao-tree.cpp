// Li Chao tree — dynamic segment tree of lines; min query y = mx+b on x
// When: DP optimizations, convex hull trick offline alternative on bounded x.
// Time: O(log X) insert/query    Space: O(n log X) nodes
#include <algorithm>
#include <cassert>
#include <climits>
#include <utility>
#include <vector>

using std::vector;

struct Line {
    long long m, b;
    long long eval(long long x) const { return m * x + b; }
};

struct LichaoNode {
    Line ln{0, LLONG_MAX / 4};
    LichaoNode *l = nullptr;
    LichaoNode *r = nullptr;
};

struct LichaoTree {
    long long lo, hi;
    LichaoNode* root = new LichaoNode();

    LichaoTree(long long lo_, long long hi_) : lo(lo_), hi(hi_) {}

    static void add_line(LichaoNode* node, long long l, long long r, Line nw, Line& cur) {
        long long mid = (l + r) / 2;
        bool left = nw.eval(l) < cur.eval(l);
        bool mleft = nw.eval(mid) < cur.eval(mid);
        if (left) {
            std::swap(nw, cur);
        }
        if (l == r)
            return;
        if (left != mleft) {
            if (!node->l)
                node->l = new LichaoNode();
            add_line(node->l, l, mid, nw, cur);
        } else {
            if (!node->r)
                node->r = new LichaoNode();
            add_line(node->r, mid + 1, r, nw, cur);
        }
    }

    void add(long long m, long long b) {
        add_line(root, lo, hi, {m, b}, root->ln);
    }

    long long query_rec(LichaoNode* node, long long l, long long r, long long x) const {
        if (!node)
            return LLONG_MAX / 4;
        long long ans = node->ln.eval(x);
        if (l == r)
            return ans;
        long long mid = (l + r) / 2;
        if (x <= mid)
            return std::min(ans, query_rec(node->l, l, mid, x));
        return std::min(ans, query_rec(node->r, mid + 1, r, x));
    }

    long long query(long long x) const { return query_rec(root, lo, hi, x); }
};

int main() {
    LichaoTree lct(0, 10);
    lct.add(0, 5);
    lct.add(1, 0);
    assert(lct.query(0) == 0);
    assert(lct.query(10) == 10);
    assert(lct.query(4) == 4);
    return 0;
}
