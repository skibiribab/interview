// Linked list — reverse (iterative), cycle detection (Floyd tortoise–hare)
// When: in-place reorder, detect loops, find middle (variant).
// Time: O(n)    Space: O(1)
#include <cassert>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int v = 0, ListNode* n = nullptr) : val(v), next(n) {}
};

static ListNode* reverse_list(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (cur) {
        ListNode* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

static bool has_cycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main() {
    ListNode x(1), y(2), z(3);
    x.next = &y;
    y.next = &z;
    ListNode* r = reverse_list(&x);
    assert(r == &z && r->val == 3 && r->next->val == 2);

    ListNode n1(1), n2(2);
    n1.next = &n2;
    n2.next = &n2; // self-loop
    assert(has_cycle(&n1));
    return 0;
}
