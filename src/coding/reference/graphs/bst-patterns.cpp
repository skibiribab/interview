// BST — validate binary search tree (min/max bounds per node)
// When: “is this a BST?”, range queries on tree structure, property checks.
// Time: O(n)    Space: O(h) recursion stack
#include <cassert>
#include <optional>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    explicit TreeNode(int v, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(v), left(l), right(r) {}
};

static bool is_bst_helper(TreeNode* n, std::optional<long long> lo, std::optional<long long> hi) {
    if (!n)
        return true;
    if (lo && n->val <= *lo)
        return false;
    if (hi && n->val >= *hi)
        return false;
    return is_bst_helper(n->left, lo, n->val) && is_bst_helper(n->right, n->val, hi);
}

static bool is_bst(TreeNode* root) {
    return is_bst_helper(root, std::nullopt, std::nullopt);
}

int main() {
    TreeNode good(2, new TreeNode(1), new TreeNode(3));
    assert(is_bst(&good));
    TreeNode bad(2, new TreeNode(3), nullptr);
    assert(!is_bst(&bad));
    return 0;
}
