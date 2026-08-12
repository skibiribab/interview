// Tonelli–Shanks — modular square root x² ≡ a (mod p), p odd prime
// When: extract sqrt in prime field; cipolla alternative for some p.
// Time: O(log² p) typical    Space: O(1)
#include <cassert>

static long long mod_pow(long long a, long long e, long long mod) {
    long long r = 1 % mod;
    for (a %= mod; e; e >>= 1, a = a * a % mod)
        if (e & 1)
            r = r * a % mod;
    return r;
}

// Returns x in [0,p) with x²≡n, or -1 if none. p odd prime.
static long long tonelli_shanks(long long n, long long p) {
    n %= p;
    if (n == 0)
        return 0;
    if (p == 2)
        return n;
    if (mod_pow(n, (p - 1) / 2, p) != 1)
        return -1;
    if (p % 4 == 3)
        return mod_pow(n, (p + 1) / 4, p);

    long long q = p - 1, s = 0;
    while (q % 2 == 0) {
        q /= 2;
        ++s;
    }
    long long z = 2;
    while (mod_pow(z, (p - 1) / 2, p) != p - 1)
        ++z;
    long long m = s, c = mod_pow(z, q, p), r = mod_pow(n, (q + 1) / 2, p), t = mod_pow(n, q, p);
    while (t != 1) {
        long long i = 1, t2 = t * t % p;
        while (t2 != 1) {
            t2 = t2 * t2 % p;
            ++i;
        }
        long long b = mod_pow(c, 1LL << (m - i - 1), p);
        r = r * b % p;
        c = b * b % p;
        t = t * c % p;
        m = i;
    }
    return r;
}

int main() {
    long long x = tonelli_shanks(2, 7); // 3²=9≡2
    assert(x == 3 || x == 4);
    assert(x * x % 7 == 2);
    assert(tonelli_shanks(3, 7) == -1);
    return 0;
}
