// Longest Increasing Subsequence — patience sorting (length) + reconstruction
// When: LIS length / one optimal sequence; also via Fenwick on compressed ranks.
// Time: O(n log n)    Space: O(n)
#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

static int lis_length(const vector<int>& a) {
    vector<int> tails; // tails[k] = smallest tail of LIS length k+1
    for (int x : a) {
        auto it = std::lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end())
            tails.push_back(x);
        else
            *it = x;
    }
    return (int)tails.size();
}

static vector<int> lis_sequence(const vector<int>& a) {
    const int n = (int)a.size();
    vector<int> tails, tail_idx, prev(n, -1);
    for (int i = 0; i < n; ++i) {
        auto it = std::lower_bound(tails.begin(), tails.end(), a[i]);
        int k = (int)(it - tails.begin());
        if (it == tails.end()) {
            tails.push_back(a[i]);
            tail_idx.push_back(i);
        } else {
            *it = a[i];
            tail_idx[k] = i;
        }
        if (k > 0)
            prev[i] = tail_idx[k - 1];
    }
    vector<int> seq;
    for (int i = tail_idx.back(); i >= 0; i = prev[i])
        seq.push_back(a[i]);
    std::reverse(seq.begin(), seq.end());
    return seq;
}

int main() {
    vector<int> a = {1, 3, 2, 4, 3, 5};
    assert(lis_length(a) == 4);
    auto s = lis_sequence(a);
    assert((int)s.size() == 4);
    for (int i = 1; i < (int)s.size(); ++i)
        assert(s[i - 1] < s[i]);
    return 0;
}
