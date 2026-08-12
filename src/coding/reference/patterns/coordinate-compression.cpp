// Coordinate compression — map values to ranks 0..k-1
// When: Fenwick / segtree on large or negative coordinates; offline ranks.
// Time: O(n log n)    Space: O(n)
#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

struct Compressor {
    vector<int> vals;
    void add(int x) { vals.push_back(x); }
    void build() {
        std::sort(vals.begin(), vals.end());
        vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
    }
    int get(int x) const {
        return (int)(std::lower_bound(vals.begin(), vals.end(), x) - vals.begin());
    }
    int size() const { return (int)vals.size(); }
};

int main() {
    Compressor c;
    for (int x : {100, -5, 100, 7})
        c.add(x);
    c.build();
    assert(c.size() == 3);
    assert(c.get(-5) == 0);
    assert(c.get(7) == 1);
    assert(c.get(100) == 2);
    return 0;
}
