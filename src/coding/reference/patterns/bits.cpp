// Bit tricks — XOR single-number, popcount, subset enumeration by mask
// When: parity, set bits, small-n bitmask DP, powerset over n ≤ 20.
// Time: O(n) XOR scan; O(1) popcount; O(2^n·n) naive subset work    Space: O(1)
#include <cassert>
#include <vector>

using std::vector;

static int single_number_xor(const vector<int>& nums) {
    int x = 0;
    for (int v : nums)
        x ^= v;
    return x;
}

static int popcount_loop(int x) {
    int c = 0;
    for (; x; x &= x - 1)
        ++c;
    return c;
}

int main() {
    assert(single_number_xor({4, 1, 2, 1, 2}) == 4);
    assert(popcount_loop(7) == 3);
    return 0;
}
