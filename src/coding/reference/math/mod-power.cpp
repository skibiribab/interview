// Modular exponentiation — binary powering for integers (mod or 64-bit)
// When: Fermat inverse setup, repeated squaring, matrix-exponentiation building block.
// Time: O(log exp)    Space: O(1)
#include <cassert>
#include <cstdint>

static long long mod_pow(long long base, long long exp, long long mod) {
    long long res = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp >>= 1;
    }
    return res;
}

static long long mod_inv(long long a, long long mod) { return mod_pow(a, mod - 2, mod); }

static uint64_t pow_u64(uint64_t base, uint64_t exp) {
    uint64_t res = 1;
    while (exp) {
        if (exp & 1)
            res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

int main() {
    assert(mod_pow(2, 10, 1000) == 24);
    assert(mod_pow(3, 0, 7) == 1);
    assert(mod_inv(3, 11) == 4);
    assert(pow_u64(2, 10) == 1024);
    return 0;
}
