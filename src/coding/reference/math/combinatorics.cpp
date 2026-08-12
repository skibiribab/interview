// Combinatorics — nCr, factorial mod, modular inverse. Common in counting problems.
#include <cassert>
#include <cstdint>
#include <vector>

static const int MOD = 1'000'000'007;

static int64_t mod_pow(int64_t base, int64_t exp) {
    int64_t out = 1;
    while (exp > 0) {
        if (exp & 1) {
            out = out * base % MOD;
        }
        base = base * base % MOD;
        exp >>= 1;
    }
    return out;
}

static int64_t mod_inv(int64_t x) { return mod_pow(x, MOD - 2); }

static std::vector<int64_t> factorial_table(int n) {
    std::vector<int64_t> fact(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    return fact;
}

static int64_t nCr(int n, int r, const std::vector<int64_t>& fact) {
    if (r < 0 || r > n) {
        return 0;
    }
    return fact[n] * mod_inv(fact[r] * fact[n - r] % MOD) % MOD;
}

int main() {
    auto fact = factorial_table(10);
    assert((nCr(5, 2, fact) == 10));
    assert((nCr(10, 3, fact) == 120));
    return 0;
}
