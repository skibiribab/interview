// MEX — minimum excluded non-negative integer (arrays, sets, Grundy helper)
// When: mex in game theory, counting arrays with mex k, frequency tricks.
// Time: O(n) array scan    Space: O(n)
#include <cassert>
#include <vector>

using std::vector;

static int mex_array(const vector<int>& a) {
    int n = (int)a.size();
    vector<char> seen(n + 1, 0);
    for (int x : a) {
        if (x >= 0 && x <= n)
            seen[x] = 1;
    }
    for (int i = 0;; ++i) {
        if (!seen[i])
            return i;
    }
}

static int mex_grundy(const vector<int>& reachable) {
    int m = 0;
    while (m < (int)reachable.size() && reachable[m])
        m++;
    return m;
}

static int mex_from_freq(const vector<int>& freq) {
    for (int i = 0; i < (int)freq.size(); ++i) {
        if (freq[i] == 0)
            return i;
    }
    return (int)freq.size();
}

int main() {
    assert(mex_array({1, 2, 0, 4}) == 3);
    assert(mex_array({}) == 0);
    vector<int> reach(4, 0);
    reach[0] = reach[2] = 1;
    assert(mex_grundy(reach) == 1);
    assert(mex_from_freq({2, 0, 1, 0}) == 1);
    return 0;
}
