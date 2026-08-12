// Discrete log — baby-step giant-step: solve a^x ≡ b (mod m), gcd(a,m)=1
// When: find exponent in multiplicative group; crypto / number-theory contests.
// Time: O(√m)    Space: O(√m)
#include <cassert>
#include <cmath>
#include <unordered_map>

static long long mod_pow(long long a, long long e, long long m) {
    long long r = 1 % m;
    for (a %= m; e > 0; e >>= 1, a = a * a % m)
        if (e & 1)
            r = r * a % m;
    return r;
}

static long long egcd(long long a, long long b, long long& x, long long& y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    long long g = egcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

// Returns minimal x≥0, or -1 if none
static long long discrete_log(long long a, long long b, long long m) {
    a %= m;
    b %= m;
    if (b == 1 % m)
        return 0;
    long long n = (long long)std::sqrt(m) + 1;
    std::unordered_map<long long, long long> baby;
    long long cur = 1;
    for (long long j = 0; j < n; ++j) {
        baby.emplace(cur, j);
        cur = cur * a % m;
    }
    long long an = mod_pow(a, n, m), inv_x, inv_y;
    if (egcd(an, m, inv_x, inv_y) != 1)
        return -1;
    long long inv_an = (inv_x % m + m) % m;

    cur = b;
    for (long long i = 0; i <= n; ++i) {
        auto it = baby.find(cur);
        if (it != baby.end())
            return i * n + it->second;
        cur = cur * inv_an % m;
    }
    return -1;
}

int main() {
    assert(discrete_log(2, 8, 1000000007) == 3);
    return 0;
}
