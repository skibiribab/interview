// Chinese Remainder Theorem — merge congruences x ≡ a_i (mod m_i), pairwise coprime mods
// When: reconstruct integer from modular residues; Garner / CRT merge.
// Time: O(k log M)    Space: O(k)
#include <cassert>
#include <cstddef>
#include <tuple>
#include <vector>

using std::vector;

static long long ext_gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

static long long crt_coprime(const vector<long long>& rem, const vector<long long>& mod) {
    long long x = 0, prod = 1;
    for (size_t i = 0; i < rem.size(); ++i) {
        long long a, b;
        ext_gcd(prod, mod[i], a, b);
        long long t = (rem[i] - x) % mod[i];
        if (t < 0)
            t += mod[i];
        t = (t * (a % mod[i] + mod[i])) % mod[i];
        x += t * prod;
        prod *= mod[i];
    }
    return (x % prod + prod) % prod;
}

int main() {
    assert(crt_coprime({2, 3, 1}, {3, 4, 5}) == 11);
    return 0;
}
