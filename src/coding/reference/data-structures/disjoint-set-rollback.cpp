// DSU with rollback — union by size/rank without path compression
// When: offline Mo on trees, divide-and-conquer on timeline, temporary unions.
// Time: O(log n) find/unite; O(1) rollback    Space: O(n + ops)
#include <cassert>
#include <utility>
#include <vector>

using std::vector;

struct DSURollback {
    vector<int> p, sz;
    vector<std::pair<int, int>> hist; // (node, old_parent_or_-size)

    explicit DSURollback(int n) : p(n), sz(n, 1) {
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }

    int find(int x) const { return p[x] == x ? x : find(p[x]); }

    int snapshot() const { return (int)hist.size(); }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (sz[a] < sz[b])
            std::swap(a, b);
        hist.push_back({b, p[b]});
        hist.push_back({a, -sz[a]});
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }

    void rollback(int snap) {
        while ((int)hist.size() > snap) {
            auto [x, y] = hist.back();
            hist.pop_back();
            if (y < 0)
                sz[x] = -y;
            else
                p[x] = y;
        }
    }

    bool same(int a, int b) const { return find(a) == find(b); }
};

int main() {
    DSURollback d(4);
    int s = d.snapshot();
    d.unite(0, 1);
    d.unite(2, 3);
    assert(d.same(0, 1));
    d.rollback(s);
    assert(!d.same(0, 1));
    return 0;
}
