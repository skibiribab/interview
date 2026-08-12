// Trie — prefix tree (insert, search, startsWith)
// When: autocomplete, prefix counts, replace words; beats hash for shared prefixes.
// Time: O(L) per op (L = key length)    Space: O(ALPH · nodes) worst case
#include <cassert>
#include <memory>
#include <string>
#include <unordered_map>

class Trie {
    struct Node {
        std::unordered_map<char, std::unique_ptr<Node>> ch;
        bool end = false;
    };
    std::unique_ptr<Node> root = std::make_unique<Node>();

  public:
    void insert(const std::string& w) {
        Node* n = root.get();
        for (char c : w) {
            if (!n->ch.count(c))
                n->ch[c] = std::make_unique<Node>();
            n = n->ch[c].get();
        }
        n->end = true;
    }
    bool search(const std::string& w) const {
        const Node* n = root.get();
        for (char c : w) {
            auto it = n->ch.find(c);
            if (it == n->ch.end())
                return false;
            n = it->second.get();
        }
        return n->end;
    }
    bool starts_with(const std::string& pre) const {
        const Node* n = root.get();
        for (char c : pre) {
            auto it = n->ch.find(c);
            if (it == n->ch.end())
                return false;
            n = it->second.get();
        }
        return true;
    }
};

int main() {
    Trie t;
    t.insert("apple");
    assert(t.search("apple"));
    assert(!t.search("app"));
    assert(t.starts_with("app"));
    return 0;
}
