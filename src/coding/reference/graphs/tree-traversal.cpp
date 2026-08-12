// Binary tree traversals — preorder (recursive + iterative stack sketch)
// When: serialization, expression trees, DFS order on trees before graph variants.
// Time: O(n)    Space: O(h) stack; O(n) worst skewed tree
#include <algorithm>
#include <cassert>
#include <functional>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    explicit TreeNode(int v, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(v), left(l), right(r) {}
};

static void preorder_rec(TreeNode* n, std::vector<int>& out) {
    if (!n)
        return;
    out.push_back(n->val);
    preorder_rec(n->left, out);
    preorder_rec(n->right, out);
}

static void preorder_iter(TreeNode* root, std::vector<int>& out) {
    if (!root)
        return;
    std::stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* n = st.top();
        st.pop();
        out.push_back(n->val);
        if (n->right)
            st.push(n->right);
        if (n->left)
            st.push(n->left);
    }
}

static int height(TreeNode* n) {
    if (!n)
        return -1;
    return 1 + std::max(height(n->left), height(n->right));
}

int main() {
    TreeNode c(3), d(4), b(2, &c, &d), a(1, &b, nullptr);
    std::vector<int> r1, r2;
    preorder_rec(&a, r1);
    preorder_iter(&a, r2);
    assert(r1 == r2);
    assert(height(&a) == 2);
    return 0;
}
