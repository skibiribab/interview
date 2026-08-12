// Line sweep — max overlapping intervals via sorted events
// When: meeting rooms, union length, closest pair on x-axis (1D sweep template).
// Time: O(n log n)    Space: O(n)
#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

struct Event {
    int x, delta;
    bool operator<(const Event& o) const {
        if (x != o.x)
            return x < o.x;
        return delta > o.delta; // start before end at same x
    }
};

static int max_overlapping_intervals(const vector<std::pair<int, int>>& segs) {
    vector<Event> ev;
    ev.reserve(segs.size() * 2);
    for (auto [l, r] : segs) {
        ev.push_back({l, 1});
        ev.push_back({r, -1});
    }
    std::sort(ev.begin(), ev.end());
    int cur = 0, best = 0;
    for (auto e : ev) {
        cur += e.delta;
        best = std::max(best, cur);
    }
    return best;
}

static long long union_length(const vector<std::pair<int, int>>& segs) {
    if (segs.empty())
        return 0;
    vector<std::pair<int, int>> v = segs;
    std::sort(v.begin(), v.end());
    long long len = 0;
    int cur_l = v[0].first, cur_r = v[0].second;
    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i].first <= cur_r) {
            cur_r = std::max(cur_r, v[i].second);
        } else {
            len += cur_r - cur_l;
            cur_l = v[i].first;
            cur_r = v[i].second;
        }
    }
    len += cur_r - cur_l;
    return len;
}

int main() {
    vector<std::pair<int, int>> segs = {{1, 4}, {2, 5}, {7, 9}, {8, 10}};
    assert(max_overlapping_intervals(segs) == 2);
    assert(union_length(segs) == 7); // [1,5) + [7,10)
    return 0;
}
