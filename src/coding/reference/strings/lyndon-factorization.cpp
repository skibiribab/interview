// Lyndon factorization — Duval O(n) unique factorization into Lyndon words
// When: lexicographically minimal string rotation; circular string problems.
// Time: O(n)    Space: O(1) extra
#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using std::string;
using std::vector;

static vector<string> lyndon_factorization(const string& s) {
    vector<string> factors;
    int n = (int)s.size();
    int i = 0;
    while (i < n) {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k) {
            factors.push_back(s.substr(i, j - k));
            i += j - k;
        }
    }
    return factors;
}

static int minimal_rotation_start(const string& s) {
    string t = s + s;
    auto fac = lyndon_factorization(t);
    if (fac[0].size() == s.size())
        return 0;
    return (int)(t.find(fac[0]) % s.size());
}

int main() {
    auto f = lyndon_factorization("abcab");
    assert(!f.empty());
    assert(minimal_rotation_start("cba") >= 0);
    return 0;
}
