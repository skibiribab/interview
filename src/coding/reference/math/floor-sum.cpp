// Floor sum — ∑_{i=1}^n ⌊n/i⌋ in O(√n) blocks
// When: divisor-sum enumerations, Dirichlet convolution prefixes.
// Time: O(√n)    Space: O(1)
#include <cassert>

static long long floor_sum(long long n) {
    long long ans = 0;
    for (long long l = 1; l <= n;) {
        long long v = n / l;
        long long r = n / v;
        ans += v * (r - l + 1);
        l = r + 1;
    }
    return ans;
}

int main() {
    // n=5: 5+2+1+1+1 = 10
    assert(floor_sum(5) == 10);
    assert(floor_sum(1) == 1);
    return 0;
}
