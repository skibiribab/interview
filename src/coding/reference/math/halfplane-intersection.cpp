// Half-plane intersection — intersection of half-planes → convex polygon (if bounded)
// When: linear inequalities region; dual to convex hull tricks in geometry.
// Time: O(n log n)    Space: O(n)
#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <vector>

using std::vector;

struct Pt {
    double x, y;
    Pt operator+(Pt o) const { return {x + o.x, y + o.y}; }
    Pt operator-(Pt o) const { return {x - o.x, y - o.y}; }
    Pt operator*(double k) const { return {x * k, y * k}; }
};

static double cross(Pt a, Pt b) { return a.x * b.y - a.y * b.x; }

// Half-plane = points to the LEFT of directed line A → B
struct HP {
    Pt p, v;
    double ang;
    HP() = default;
    HP(Pt a, Pt b) : p(a), v(b - a), ang(std::atan2(v.y, v.x)) {}
    bool out(Pt q) const { return cross(v, q - p) < -1e-12; }
    Pt intersect(const HP& o) const {
        Pt u = p - o.p;
        double t = cross(o.v, u) / cross(v, o.v);
        return p + v * t;
    }
};

static vector<Pt> halfplane_intersection(vector<HP> h) {
    const double BOX = 1e9;
    h.push_back(HP({-BOX, -BOX}, {BOX, -BOX}));
    h.push_back(HP({BOX, -BOX}, {BOX, BOX}));
    h.push_back(HP({BOX, BOX}, {-BOX, BOX}));
    h.push_back(HP({-BOX, BOX}, {-BOX, -BOX}));

    std::sort(h.begin(), h.end(), [](const HP& a, const HP& b) {
        if (std::fabs(a.ang - b.ang) > 1e-12)
            return a.ang < b.ang;
        return cross(a.v, b.p - a.p) < 0;
    });
    vector<HP> uniq;
    for (auto& x : h) {
        if (!uniq.empty() && std::fabs(uniq.back().ang - x.ang) < 1e-12)
            continue;
        uniq.push_back(x);
    }

    std::deque<HP> dq;
    for (auto& x : uniq) {
        while (dq.size() >= 2 && x.out(dq[dq.size() - 2].intersect(dq.back())))
            dq.pop_back();
        while (dq.size() >= 2 && x.out(dq[0].intersect(dq[1])))
            dq.pop_front();
        dq.push_back(x);
    }
    while (dq.size() >= 3 && dq.front().out(dq[dq.size() - 2].intersect(dq.back())))
        dq.pop_back();
    while (dq.size() >= 3 && dq.back().out(dq[0].intersect(dq[1])))
        dq.pop_front();

    vector<Pt> poly;
    for (size_t i = 0; i < dq.size(); ++i)
        poly.push_back(dq[i].intersect(dq[(i + 1) % dq.size()]));
    return poly;
}

int main() {
    // x≥0, y≥0, x+y≤1 → triangle
    vector<HP> h = {
        HP({0, 1}, {0, 0}), // x ≥ 0
        HP({0, 0}, {1, 0}), // y ≥ 0
        HP({1, 0}, {0, 1}), // x + y ≤ 1
    };
    auto poly = halfplane_intersection(h);
    assert(poly.size() >= 3);
    return 0;
}
