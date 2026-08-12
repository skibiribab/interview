// Suffix array (+ LCP via Kasai) — suffix ordering with prefix-doubling build
// When: substring order / repeated substring class problems; upgrade to SA-IS for huge n if needed.
// Time: O(n log² n) build here; LCP O(n)    Space: O(n)
#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using std::vector;

struct SuffixArray {
    int n;
    vector<int> sa;
    vector<int> rank;
    vector<int> lcp;

    explicit SuffixArray(const std::string& s) : n((int)s.size()) {
        sa.resize(n);
        rank.resize(n);
        vector<int> tmp(n);
        for (int i = 0; i < n; ++i) {
            sa[i] = i;
            rank[i] = i < n ? (unsigned char)s[i] : 0;
        }
        for (int k = 1; k < n; k *= 2) {
            auto cmp = [&](int i, int j) {
                if (rank[i] != rank[j])
                    return rank[i] < rank[j];
                int ri = i + k < n ? rank[i + k] : -1;
                int rj = j + k < n ? rank[j + k] : -1;
                return ri < rj;
            };
            std::sort(sa.begin(), sa.end(), cmp);
            tmp[sa[0]] = 0;
            for (int i = 1; i < n; ++i)
                tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
            rank = tmp;
            if (rank[sa[n - 1]] == n - 1)
                break;
        }
        kasai_lcp(s);
    }

    void kasai_lcp(const std::string& s) {
        lcp.assign(n ? n - 1 : 0, 0);
        if (n <= 1)
            return;
        vector<int> inv(n);
        for (int i = 0; i < n; ++i)
            inv[sa[i]] = i;
        int h = 0;
        for (int i = 0; i < n; ++i) {
            int r = inv[i];
            if (r == 0)
                continue;
            int j = sa[r - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h])
                ++h;
            lcp[r - 1] = h;
            if (h)
                --h;
        }
    }
};

int main() {
    SuffixArray sa("abab");
    assert((int)sa.sa.size() == 4);
    return 0;
}
