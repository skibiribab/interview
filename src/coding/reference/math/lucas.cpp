// Lucas theorem — nCr(n, k) mod prime p
// When: huge n,k with small prime modulus; digit-wise binomial product.
// Time: O(p + log_p n) with factorial table mod p    Space: O(p)
#include <cassert>
#include <vector>

using std::vector;

static long long mod_pow(long long a, long long e, long long mod) {
    long long r = 1;
    for (; e; e >>= 1, a = a * a % mod)
        if (e & 1)
            r = r * a % mod;
    return r;
}

struct Lucas {
    int p;
    vector<long long> fact, ifact;
    explicit Lucas(int p_) : p(p_), fact(p_), ifact(p_) {
        fact[0] = 1;
        for (int i = 1; i < p; ++i)
            fact[i] = fact[i - 1] * i % p;
        ifact[p - 1] = mod_pow(fact[p - 1], p - 2, p);
        for (int i = p - 1; i > 0; --i)
            ifact[i - 1] = ifact[i] * i % p;
    }
    long long small(int n, int k) const {
        if (k < 0 || k > n)
            return 0;
        return fact[n] * ifact[k] % p * ifact[n - k] % p;
    }
    long long nCr(long long n, long long k) const {
        if (k < 0 || k > n)
            return 0;
        long long ans = 1;
        while (n > 0 || k > 0) {
            ans = ans * small((int)(n % p), (int)(k % p)) % p;
            n /= p;
            k /= p;
        }
        return ans;
    }
};

int main() {
    Lucas L(7);
    assert(L.nCr(10, 3) == 1); // C(10,3)=120 ≡ 1 (mod 7)
    assert(L.nCr(5, 2) == 3);
    return 0;
}
