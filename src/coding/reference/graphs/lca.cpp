// Lowest common ancestor — binary tree (two given nodes exist in tree)
// When: distance between nodes, path queries, org-chart style trees.
// Time: O(n)    Space: O(h)
#include <cassert>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    explicit TreeNode(int v, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(v), left(l), right(r) {}
};

static TreeNode* lca_bt(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q)
        return root;
    TreeNode* L = lca_bt(root->left, p, q);
    TreeNode* R = lca_bt(root->right, p, q);
    if (L && R)
        return root;
    return L ? L : R;
}

int main() {
    TreeNode p(5), q(1), l(0), r(8), root(3, &p, &q);
    p.left = &l;
    p.right = &r;
    assert(lca_bt(&root, &p, &q) == &root);
    assert(lca_bt(&root, &p, &l) == &p);
    return 0;
}
