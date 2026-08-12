// Möbius function μ — linear sieve + inclusion for gcd convolution / counting
// When: inversion over divisors, coprime counting, ∑ f(gcd) tricks.
// Time: O(n) build    Space: O(n)
#include <cassert>
#include <vector>

using std::vector;

struct Mobius {
    vector<int> mu, primes;
    vector<char> vis;
    explicit Mobius(int n) : mu(n + 1), vis(n + 1, 0) {
        mu[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (!vis[i]) {
                primes.push_back(i);
                mu[i] = -1;
            }
            for (int p : primes) {
                if (1LL * i * p > n)
                    break;
                vis[i * p] = 1;
                if (i % p == 0) {
                    mu[i * p] = 0;
                    break;
                }
                mu[i * p] = -mu[i];
            }
        }
    }
};

// Count pairs 1≤i,j≤n with gcd(i,j)=1 via ∑ μ(d)·⌊n/d⌋²
static long long count_coprime_pairs(int n, const Mobius& m) {
    long long ans = 0;
    for (int d = 1; d <= n; ++d)
        ans += 1LL * m.mu[d] * (n / d) * (n / d);
    return ans;
}

int main() {
    Mobius m(20);
    assert(m.mu[1] == 1);
    assert(m.mu[2] == -1);
    assert(m.mu[4] == 0);
    assert(m.mu[6] == 1);
    assert(count_coprime_pairs(1, m) == 1);
    return 0;
}
