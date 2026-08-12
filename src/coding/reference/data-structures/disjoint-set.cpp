// Disjoint set (union–find) with path compression and union by rank
// When: dynamic connectivity, Kruskal, offline “are u,v connected?”
// Time: O(α(n)) amortized find/unite    Space: O(n)
#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

struct DSU {
    vector<int> p, r;
    explicit DSU(int n) : p(n), r(n, 0) {
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (r[a] < r[b])
            std::swap(a, b);
        p[b] = a;
        if (r[a] == r[b])
            r[a]++;
        return true;
    }
    bool same(int a, int b) { return find(a) == find(b); }
};

int main() {
    DSU d(5);
    d.unite(0, 1);
    d.unite(2, 3);
    assert(d.same(0, 1));
    assert(!d.same(0, 4));
    return 0;
}
