// Number Theoretic Transform — convolution mod 998244353 (primitive root 3)
// When: multiply polynomials / subset convolution at scale; CP counting problems.
// Time: O(n log n)    Space: O(n)
#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

static const int MOD = 998244353;
static const int G = 3;

static int mod_pow(int a, long long e) {
    long long r = 1, b = a;
    while (e) {
        if (e & 1)
            r = r * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return (int)r;
}

static void ntt(vector<int>& a, bool invert) {
    int n = (int)a.size();
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            std::swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        int wlen = mod_pow(G, (MOD - 1) / len);
        if (invert)
            wlen = mod_pow(wlen, MOD - 2);
        for (int i = 0; i < n; i += len) {
            long long w = 1;
            for (int j = 0; j < len / 2; ++j) {
                int u = a[i + j];
                int v = (int)(a[i + j + len / 2] * w % MOD);
                a[i + j] = u + v < MOD ? u + v : u + v - MOD;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + MOD;
                w = w * wlen % MOD;
            }
        }
    }
    if (invert) {
        int inv_n = mod_pow(n, MOD - 2);
        for (int& x : a)
            x = (int)((long long)x * inv_n % MOD);
    }
}

static vector<int> convolution(vector<int> a, vector<int> b) {
    int need = 1;
    while (need < (int)a.size() + (int)b.size() - 1)
        need <<= 1;
    a.resize(need);
    b.resize(need);
    ntt(a, false);
    ntt(b, false);
    for (int i = 0; i < need; ++i)
        a[i] = (int)((long long)a[i] * b[i] % MOD);
    ntt(a, true);
    a.resize(need);
    return a;
}

int main() {
    auto c = convolution({1, 2, 3}, {4, 5});
    assert(c[0] == 4);
    assert(c[1] == 13);
    assert(c[2] == 22);
    assert(c[3] == 15);
    return 0;
}
