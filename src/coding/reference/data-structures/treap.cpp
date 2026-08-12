// Treap — randomized BST via split/merge by key
// When: ordered multiset with split by rank/key; implicit treap for rope-style ops.
// Time: O(log n) expected per op    Space: O(n)
#include <cassert>
#include <random>

struct Treap {
    struct Node {
        int key, pr, sz;
        Node *l, *r;
        explicit Node(int k, int p) : key(k), pr(p), sz(1), l(nullptr), r(nullptr) {}
    };
    Node* root = nullptr;
    std::mt19937 rng{std::random_device{}()};

    static int size(Node* t) { return t ? t->sz : 0; }
    static void upd(Node* t) {
        if (t)
            t->sz = 1 + size(t->l) + size(t->r);
    }

    void merge(Node*& t, Node* a, Node* b) {
        if (!a || !b)
            return void(t = a ? a : b);
        if (a->pr < b->pr)
            merge(a->r, a->r, b), t = a;
        else
            merge(b->l, a, b->l), t = b;
        upd(t);
    }

    void split(Node* t, int key, Node*& a, Node*& b) {
        if (!t)
            return void(a = b = nullptr);
        if (t->key < key)
            split(t->r, key, t->r, b), a = t;
        else
            split(t->l, key, a, t->l), b = t;
        upd(a);
        upd(b);
    }

    void insert(int key) {
        Node *l = nullptr, *r = nullptr;
        split(root, key, l, r);
        Node* m = new Node(key, (int)rng());
        merge(l, l, m);
        merge(root, l, r);
    }

    int count_less(int key) {
        Node *l = nullptr, *r = nullptr;
        split(root, key, l, r);
        int ans = size(l);
        merge(root, l, r);
        return ans;
    }
};

int main() {
    Treap t;
    t.insert(3);
    t.insert(1);
    t.insert(4);
    assert(t.count_less(3) == 1);
    assert(t.count_less(10) == 3);
    return 0;
}
