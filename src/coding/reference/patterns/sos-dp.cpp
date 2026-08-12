// SOS DP — sum over subsets (superset zeta transform)
// When: count subsets with property P where mask includes submask; OR-convolution style.
// Time: O(n · 2^n)    Space: O(2^n)
#include <cassert>
#include <vector>

using std::vector;

static void sos_superset_zeta(vector<long long>& f) {
    int n = 0;
    while ((1 << n) < (int)f.size())
        n++;
    for (int b = 0; b < n; ++b) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (mask & (1 << b))
                f[mask] += f[mask ^ (1 << b)];
        }
    }
}

int main() {
    vector<long long> f = {1, 2, 3, 4};
    sos_superset_zeta(f);
    assert(f[3] == 10);
    assert(f[0] == 1);
    return 0;
}
