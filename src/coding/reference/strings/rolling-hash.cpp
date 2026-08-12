// Rolling hash — substring equality via polynomial hash (single modulus)
// When: compare substrings in O(1) after prep; double-hash in contests if paranoid.
// Time: O(n) prep + O(1) per hash    Space: O(n)
#include <cassert>
#include <string>
#include <vector>

using std::vector;

struct RollingHash {
    long long base;
    long long mod;
    vector<long long> powb;
    vector<long long> pref;

    RollingHash(const std::string& s, long long b = 131, long long m = 1000000007LL)
        : base(b), mod(m), powb(s.size() + 1), pref(s.size() + 1) {
        powb[0] = 1;
        for (size_t i = 0; i < s.size(); ++i) {
            powb[i + 1] = powb[i] * base % mod;
            pref[i + 1] = (pref[i] * base + s[i]) % mod;
        }
    }

    long long substring_hash(int l, int r) const { return (pref[r + 1] - pref[l] * powb[r - l + 1] % mod + mod) % mod; }
};

static long long count_occurrences_hash(const std::string& s, const std::string& pat, long long base = 131,
                                        long long mod = 1000000007LL) {
    int n = (int)s.size(), m = (int)pat.size();
    if (m == 0 || m > n)
        return 0;
    RollingHash hs(s, base, mod);
    RollingHash hp(pat, base, mod);
    long long hpat = hp.substring_hash(0, m - 1);
    long long cnt = 0;
    for (int i = 0; i + m <= n; ++i)
        if (hs.substring_hash(i, i + m - 1) == hpat)
            cnt++;
    return cnt;
}

int main() {
    assert(count_occurrences_hash("abab", "ab") >= 2);
    RollingHash h("abcabc", 131, 1000000007LL);
    assert(h.substring_hash(0, 2) == h.substring_hash(3, 5));
    return 0;
}
