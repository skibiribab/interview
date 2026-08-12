// Implicit treap — array as BST by size; split/merge for insert/erase/reverse
// When: dynamic arrays, range reverse/add with lazy; sequence as tree.
// Time: O(log n) expected    Space: O(n)
#include <cassert>
#include <cstdlib>
#include <utility>

struct ImplicitTreap {
    struct Node {
        int prio, sz, val;
        bool rev = false;
        Node *l = nullptr, *r = nullptr;
        explicit Node(int v) : prio(std::rand()), sz(1), val(v) {}
    };
    using P = Node*;

    static int size(P t) { return t ? t->sz : 0; }
    static void pull(P t) {
        if (t)
            t->sz = 1 + size(t->l) + size(t->r);
    }
    static void push(P t) {
        if (!t || !t->rev)
            return;
        std::swap(t->l, t->r);
        if (t->l)
            t->l->rev ^= 1;
        if (t->r)
            t->r->rev ^= 1;
        t->rev = false;
    }

    static void split(P t, int k, P& a, P& b) { // a: first k nodes
        if (!t) {
            a = b = nullptr;
            return;
        }
        push(t);
        if (size(t->l) >= k) {
            split(t->l, k, a, t->l);
            b = t;
        } else {
            split(t->r, k - size(t->l) - 1, t->r, b);
            a = t;
        }
        pull(t);
    }

    static P merge(P a, P b) {
        if (!a || !b)
            return a ? a : b;
        push(a);
        push(b);
        if (a->prio < b->prio) {
            a->r = merge(a->r, b);
            pull(a);
            return a;
        }
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }

    P root = nullptr;

    void insert(int pos, int val) { // 0-based
        P a, b;
        split(root, pos, a, b);
        root = merge(merge(a, new Node(val)), b);
    }

    void reverse(int l, int r) { // inclusive
        P a, b, c;
        split(root, l, a, b);
        split(b, r - l + 1, b, c);
        if (b)
            b->rev ^= 1;
        root = merge(merge(a, b), c);
    }

    int get(int pos) {
        P a, b, c;
        split(root, pos, a, b);
        split(b, 1, b, c);
        int v = b->val;
        root = merge(merge(a, b), c);
        return v;
    }
};

int main() {
    ImplicitTreap t;
    t.insert(0, 1);
    t.insert(1, 2);
    t.insert(2, 3);
    t.reverse(0, 2);
    assert(t.get(0) == 3 && t.get(1) == 2 && t.get(2) == 1);
    return 0;
}
