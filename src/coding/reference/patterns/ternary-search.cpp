// Ternary search — unimodal real / discrete peak finding
// When: minimize convex / maximize concave f on an interval (CPH).
// Time: O(iter · cost(f)) or O(log n) discrete    Space: O(1)
#include <cassert>
#include <cmath>

// Continuous: minimize f on [lo, hi]
template <class F>
static double ternary_min(double lo, double hi, F f, int iters = 80) {
    for (int i = 0; i < iters; ++i) {
        double m1 = lo + (hi - lo) / 3;
        double m2 = hi - (hi - lo) / 3;
        if (f(m1) < f(m2))
            hi = m2;
        else
            lo = m1;
    }
    return (lo + hi) / 2;
}

// Discrete integer domain [lo, hi], maximize f
template <class F>
static int ternary_max_int(int lo, int hi, F f) {
    while (hi - lo > 2) {
        int m1 = lo + (hi - lo) / 3;
        int m2 = hi - (hi - lo) / 3;
        if (f(m1) < f(m2))
            lo = m1;
        else
            hi = m2;
    }
    int best = lo;
    for (int x = lo; x <= hi; ++x)
        if (f(x) > f(best))
            best = x;
    return best;
}

int main() {
    auto f = [](double x) { return (x - 3) * (x - 3); };
    double x = ternary_min(-10, 10, f);
    assert(std::fabs(x - 3) < 1e-4);

    auto g = [](int x) { return -(x - 5) * (x - 5); };
    assert(ternary_max_int(0, 10, g) == 5);
    return 0;
}
