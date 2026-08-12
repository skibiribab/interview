// Prime test & factorization — trial division, Miller–Rabin, Pollard–Rho
// When: factor n for divisor problems, count divisors, poll on 64-bit composites.
// Time: trial O(√n); Miller–Rabin O(k log n); Pollard expected O(n^1/4)    Space: O(log n)
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <map>
#include <random>
#include <vector>

using std::vector;

static long long mul_mod(long long a, long long b, long long mod) {
    return (__int128)a * b % mod;
}

static long long mod_pow(long long a, long long e, long long mod) {
    long long r = 1;
    a %= mod;
    while (e) {
        if (e & 1)
            r = mul_mod(r, a, mod);
        a = mul_mod(a, a, mod);
        e >>= 1;
    }
    return r;
}

static bool miller_rabin(long long n) {
    if (n < 2)
        return false;
    for (long long p : {2LL, 3LL, 5LL, 7LL, 11LL, 13LL, 17LL, 19LL, 23LL, 29LL, 31LL, 37LL}) {
        if (n % p == 0)
            return n == p;
    }
    long long d = n - 1;
    int s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    auto witness = [&](long long a) {
        if (a % n == 0)
            return false;
        long long x = mod_pow(a, d, n);
        if (x == 1 || x == n - 1)
            return false;
        for (int r = 1; r < s; ++r) {
            x = mul_mod(x, x, n);
            if (x == n - 1)
                return false;
        }
        return true;
    };
    for (long long a : {2LL, 325LL, 9375LL, 28178LL, 450775LL, 9780504LL, 1795265022LL}) {
        if (witness(a))
            return false;
    }
    return true;
}

static long long pollard_rho(long long n) {
    if (n % 2 == 0)
        return 2;
    static std::mt19937_64 rng(1234567);
    while (true) {
        long long c = std::uniform_int_distribution<long long>(1, n - 1)(rng);
        long long x = std::uniform_int_distribution<long long>(0, n - 1)(rng);
        long long y = x;
        long long d = 1;
        auto f = [&](long long v) { return (mul_mod(v, v, n) + c) % n; };
        while (d == 1) {
            x = f(x);
            y = f(f(y));
            d = std::gcd(std::abs(x - y), n);
        }
        if (d != n)
            return d;
    }
}

static void factor_rec(long long n, std::map<long long, int>& out) {
    if (n == 1)
        return;
    if (miller_rabin(n)) {
        out[n]++;
        return;
    }
    long long d = pollard_rho(n);
    factor_rec(d, out);
    factor_rec(n / d, out);
}

static std::map<long long, int> factorize(long long n) {
    std::map<long long, int> f;
    for (long long p = 2; p * p <= n; ++p) {
        while (n % p == 0) {
            f[p]++;
            n /= p;
        }
    }
    if (n > 1) {
        if (miller_rabin(n))
            f[n]++;
        else
            factor_rec(n, f);
    }
    return f;
}

int main() {
    assert(miller_rabin(97));
    assert(!miller_rabin(91));
    auto f = factorize(360);
    assert(f[2] == 3 && f[3] == 2 && f[5] == 1);
    assert(miller_rabin(1000000007LL));
    return 0;
}
