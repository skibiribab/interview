// Extended CRT — merge x ≡ a (mod m), x ≡ b (mod n) for non-coprime moduli
// When: systems of congruences; fails iff a≢b (mod gcd(m,n)).
// Time: O(log) per merge    Space: O(1)
#include <cassert>
#include <optional>
#include <utility>

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

// Returns {x0, lcm} with x ≡ x0 (mod lcm), or nullopt if impossible
static std::optional<std::pair<long long, long long>> crt_merge(long long a, long long m, long long b,
                                                                 long long n) {
    long long x, y;
    long long g = egcd(m, n, x, y);
    if ((a - b) % g != 0)
        return std::nullopt;
    long long lcm = m / g * n;
    long long t = ((b - a) / g % (n / g) + (n / g)) % (n / g);
    long long x0 = (a + m * ((x % (n / g) + (n / g)) % (n / g) * t % (n / g))) % lcm;
    if (x0 < 0)
        x0 += lcm;
    return std::pair{x0, lcm};
}

int main() {
    auto r = crt_merge(2, 4, 4, 6); // x≡2 mod 4, x≡4 mod 6 → x≡10 mod 12
    assert(r && r->first == 10 && r->second == 12);
    assert(!crt_merge(1, 4, 2, 6));
    return 0;
}
