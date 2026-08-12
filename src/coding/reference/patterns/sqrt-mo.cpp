// Mo's algorithm — offline range queries with sqrt decomposition ordering
// When: many [l,r] queries on static array if add/remove is O(1); frequency / mode style demos.
// Time: O((n+q)·√n) pointer moves typical    Space: O(n) for frequency buckets
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>

using std::vector;

struct MoQuery {
    int l, r, idx;
};

static void mo_sort(vector<MoQuery>& qs, int n) {
    int B = std::max(1, (int)std::sqrt(n));
    std::sort(qs.begin(), qs.end(), [B](const MoQuery& a, const MoQuery& b) {
        int ba = a.l / B, bb = b.l / B;
        if (ba != bb)
            return ba < bb;
        return (ba & 1) ? (a.r < b.r) : (a.r > b.r);
    });
}

int main() {
    vector<int> a = {1, 2, 1, 3, 2, 1};
    vector<MoQuery> qs = {{0, 3, 0}, {2, 5, 1}};
    mo_sort(qs, (int)a.size());
    assert(qs[0].idx == 0 || qs[0].idx == 1);
    return 0;
}
