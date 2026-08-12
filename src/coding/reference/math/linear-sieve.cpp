// Linear sieve — primes, spf, Euler totient φ(n) in O(n)
// When: multiplicative functions, count coprime pairs, Mobius prep.
// Time: O(n)    Space: O(n)
#include <cassert>
#include <vector>

using std::vector;

struct LinearSieve {
    vector<int> primes, spf, phi;

    explicit LinearSieve(int n) : spf(n + 1), phi(n + 1) {
        phi[0] = 0;
        phi[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (spf[i] == 0) {
                spf[i] = i;
                primes.push_back(i);
                phi[i] = i - 1;
            }
            for (int p : primes) {
                long long v = 1LL * i * p;
                if (v > n)
                    break;
                spf[(int)v] = p;
                if (i % p == 0) {
                    phi[(int)v] = phi[i] * p;
                    break;
                }
                phi[(int)v] = phi[i] * (p - 1);
            }
        }
    }
};

int main() {
    LinearSieve ls(10);
    assert(ls.phi[6] == 2);
    assert(ls.phi[9] == 6);
    assert(ls.spf[10] == 2);
    return 0;
}
