// Closest pair of points — divide and conquer
// When: minimum Euclidean distance among n points (CP-Algorithms geometry).
// Time: O(n log n)    Space: O(n)
#include <algorithm>
#include <cassert>
#include <cmath>
#include <limits>
#include <vector>

using std::vector;

struct Pt {
    double x, y;
};

static double dist2(const Pt& a, const Pt& b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

static double strip_closest(vector<Pt>& strip, double best) {
    std::sort(strip.begin(), strip.end(), [](const Pt& a, const Pt& b) { return a.y < b.y; });
    for (size_t i = 0; i < strip.size(); ++i)
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) < best;
             ++j)
            best = std::min(best, dist2(strip[i], strip[j]));
    return best;
}

static double solve(vector<Pt>& px) {
    const int n = (int)px.size();
    if (n <= 3) {
        double best = std::numeric_limits<double>::infinity();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                best = std::min(best, dist2(px[i], px[j]));
        std::sort(px.begin(), px.end(), [](const Pt& a, const Pt& b) { return a.y < b.y; });
        return best;
    }
    int mid = n / 2;
    double midx = px[mid].x;
    vector<Pt> L(px.begin(), px.begin() + mid), R(px.begin() + mid, px.end());
    double d = std::min(solve(L), solve(R));
    vector<Pt> strip;
    for (auto& p : px)
        if ((p.x - midx) * (p.x - midx) < d)
            strip.push_back(p);
    return strip_closest(strip, d);
}

static double closest_pair(vector<Pt> pts) {
    std::sort(pts.begin(), pts.end(), [](const Pt& a, const Pt& b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    return std::sqrt(solve(pts));
}

int main() {
    vector<Pt> pts = {{0, 0}, {1, 1}, {2, 2}, {0, 1}};
    double d = closest_pair(pts);
    assert(std::fabs(d - 1.0) < 1e-6);
    return 0;
}
