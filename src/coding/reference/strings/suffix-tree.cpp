// Suffix tree — trie of all suffixes (explicit edges; compress at scale with SAM/SA)
// When: substring search teaching; production use suffix-automaton.cpp or suffix-array.cpp.
// Time: O(n²) build    Space: O(n²) worst case
#include <cassert>
#include <map>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct SuffixTree {
    struct Node {
        std::map<char, int> next;
        int start = 0;
        int end = 0;
    };
    string text;
    vector<Node> nodes;

    explicit SuffixTree(const string& s) : text(s), nodes(1) {
        for (int i = 0; i < (int)s.size(); ++i)
            insert_suffix(i);
    }

    void insert_suffix(int pos) {
        int u = 0;
        for (int i = pos; i < (int)text.size(); ++i) {
            char c = text[i];
            if (!nodes[u].next.count(c)) {
                int v = (int)nodes.size();
                nodes.push_back({});
                nodes[v].start = i;
                nodes[v].end = (int)text.size();
                nodes[u].next[c] = v;
            }
            u = nodes[u].next[c];
        }
    }

    bool contains(const string& pat) const {
        int u = 0;
        for (char ch : pat) {
            auto it = nodes[u].next.find(ch);
            if (it == nodes[u].next.end())
                return false;
            u = it->second;
        }
        return true;
    }
};

int main() {
    SuffixTree st("aba");
    assert(st.contains("aba"));
    assert(st.contains("ba"));
    assert(st.contains("a"));
    assert(!st.contains("bab"));
    return 0;
}
