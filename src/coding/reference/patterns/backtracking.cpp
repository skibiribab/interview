// Backtracking — subsets (include / exclude each element)
// When: enumerate combinations, powerset, prune-heavy search trees.
// Time: O(2^n·n) if copying each subset    Space: O(n) recursion depth
#include <cassert>
#include <vector>

using std::vector;

static void subsets_helper(const vector<int>& nums, int i, vector<int>& cur, vector<vector<int>>& out) {
    if (i == (int)nums.size()) {
        out.push_back(cur);
        return;
    }
    cur.push_back(nums[i]);
    subsets_helper(nums, i + 1, cur, out);
    cur.pop_back();
    subsets_helper(nums, i + 1, cur, out);
}

static vector<vector<int>> subsets(const vector<int>& nums) {
    vector<vector<int>> out;
    vector<int> cur;
    subsets_helper(nums, 0, cur, out);
    return out;
}

int main() {
    auto s = subsets({1, 2});
    assert(s.size() == 4);
    return 0;
}
