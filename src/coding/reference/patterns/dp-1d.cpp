// DP 1D — house robber (max sum no two adjacent)
// When: linear constraints with “take/skip” recurrence, rolling state.
// Time: O(n)    Space: O(1) two variables
#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

static long long house_robber(const vector<int>& nums) {
    long long take = 0, skip = 0;
    for (int x : nums) {
        long long new_take = skip + x;
        long long new_skip = std::max(take, skip);
        take = new_take;
        skip = new_skip;
    }
    return std::max(take, skip);
}

int main() {
    assert(house_robber({2, 7, 9, 3, 1}) == 12);
    return 0;
}
