// ModInt — modular arithmetic wrapper for prime MOD
// When: clean + - * / pow on contest modular fields.
// Time: O(1) ops; O(log MOD) inv/pow    Space: O(1)
#include <cassert>

template <int MOD>
struct Mint {
    int v;
    Mint(long long x = 0) : v(int((x % MOD + MOD) % MOD)) {}
    Mint& operator+=(const Mint& o) {
        v += o.v;
        if (v >= MOD)
            v -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint& o) {
        v -= o.v;
        if (v < 0)
            v += MOD;
        return *this;
    }
    Mint& operator*=(const Mint& o) {
        v = int(1LL * v * o.v % MOD);
        return *this;
    }
    Mint operator+(Mint o) const { return o += *this; }
    Mint operator-(Mint o) const {
        Mint t = *this;
        return t -= o;
    }
    Mint operator*(Mint o) const { return o *= *this; }
    Mint pow(long long e) const {
        Mint a = *this, r(1);
        for (; e > 0; e >>= 1, a *= a)
            if (e & 1)
                r *= a;
        return r;
    }
    Mint inv() const { return pow(MOD - 2); }
    Mint& operator/=(const Mint& o) { return *this *= o.inv(); }
    Mint operator/(Mint o) const { return Mint(*this) /= o; }
    bool operator==(const Mint& o) const { return v == o.v; }
};

using mint = Mint<1000000007>;

int main() {
    mint a = 3, b = 5;
    assert((a * b).v == 15);
    assert((a / a).v == 1);
    assert(a.pow(3).v == 27);
    return 0;
}
