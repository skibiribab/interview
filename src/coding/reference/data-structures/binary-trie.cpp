// Binary / XOR trie — insert numbers; max XOR with a query value
// When: max a[i]⊕x, closest XOR, offline XOR queries on prefixes.
// Time: O(B) per op (B=bit width)    Space: O(n·B)
#include <cassert>
#include <vector>

using std::vector;

struct BinaryTrie {
    static constexpr int B = 30;
    struct Node {
        int ch[2] = {-1, -1};
        int cnt = 0;
    };
    vector<Node> t{{}};

    void insert(int x) {
        int u = 0;
        ++t[u].cnt;
        for (int b = B - 1; b >= 0; --b) {
            int bit = (x >> b) & 1;
            if (t[u].ch[bit] < 0) {
                t[u].ch[bit] = (int)t.size();
                t.push_back({});
            }
            u = t[u].ch[bit];
            ++t[u].cnt;
        }
    }

    int max_xor(int x) const {
        int u = 0, ans = 0;
        for (int b = B - 1; b >= 0; --b) {
            int bit = (x >> b) & 1;
            int want = bit ^ 1;
            if (t[u].ch[want] >= 0 && t[t[u].ch[want]].cnt > 0) {
                ans |= 1 << b;
                u = t[u].ch[want];
            } else {
                u = t[u].ch[bit];
            }
        }
        return ans;
    }
};

int main() {
    BinaryTrie tr;
    tr.insert(1);
    tr.insert(5); // 101
    assert(tr.max_xor(2) == (2 ^ 5)); // prefer 5
    return 0;
}
