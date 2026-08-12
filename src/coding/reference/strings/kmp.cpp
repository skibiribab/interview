// Knuth–Morris–Pratt — prefix function and linear-time search
// When: exact single-pattern matching; avoid hash collisions.
// Time: O(n+m)    Space: O(m) for the prefix table
#include <cassert>
#include <string>
#include <vector>

using std::vector;

static vector<int> kmp_prefix(const std::string& pat) {
    int m = (int)pat.size();
    vector<int> pi(m);
    for (int i = 1; i < m; ++i) {
        int j = pi[i - 1];
        while (j > 0 && pat[i] != pat[j])
            j = pi[j - 1];
        if (pat[i] == pat[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

static int kmp_count(const std::string& pat, const std::string& text) {
    if (pat.empty())
        return 0;
    vector<int> pi = kmp_prefix(pat);
    int m = (int)pat.size(), n = (int)text.size(), ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j > 0 && text[i] != pat[j])
            j = pi[j - 1];
        if (text[i] == pat[j] && ++j == m) {
            ++ans;
            j = pi[j - 1];
        }
    }
    return ans;
}

int main() {
    assert(kmp_count("abc", "ababcababcabc") == 3);
    assert(kmp_count("abcd", "abcdabcdabcabcdabcd") == 4);
    auto pi = kmp_prefix("ababaca");
    assert(pi.back() == 1);
    return 0;
}
