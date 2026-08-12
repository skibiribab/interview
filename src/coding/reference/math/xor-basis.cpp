// XOR / linear basis — insert & max XOR with subset linear combination
// When: maximum XOR subset, k-th XOR, independent bits over GF(2).
// Time: O(B²) insert (B=bit width); O(B) query    Space: O(B)
#include <cassert>

struct XorBasis {
    static constexpr int B = 60;
    long long b[B]{};

    bool insert(long long x) {
        for (int i = B - 1; i >= 0; --i) {
            if (!(x & (1LL << i)))
                continue;
            if (!b[i]) {
                b[i] = x;
                return true;
            }
            x ^= b[i];
        }
        return false;
    }

    long long max_xor(long long x = 0) const {
        for (int i = B - 1; i >= 0; --i)
            if ((x ^ b[i]) > x)
                x ^= b[i];
        return x;
    }
};

int main() {
    XorBasis xb;
    xb.insert(1);
    xb.insert(2);
    xb.insert(3); // linearly dependent (1^2)
    assert(xb.max_xor() == 3);
    assert(xb.max_xor(1) == 3);
    return 0;
}
