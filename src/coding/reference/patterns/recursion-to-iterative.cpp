// Recursion → iteration — binary tree preorder with explicit stack
// When: avoid deep recursion limits; same order as recursive DFS.
// Time: O(n)    Space: O(h) stack
#include <cassert>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    explicit TreeNode(int v, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(v), left(l), right(r) {}
};

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

int main() {
    TreeNode c(3), b(2, &c, nullptr), a(1, &b, nullptr);
    std::vector<int> v;
    preorder_iter(&a, v);
    assert((v == std::vector<int>{1, 2, 3}));
    return 0;
}
