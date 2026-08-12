// Aho–Corasick — multi-pattern automaton, one scan over text
// When: many keywords, streaming text (censoring, virus scan toy, DNA k-mers).
// Time: O(|text| + matches + σ·nodes)    Space: O(σ·nodes)
#include <cassert>
#include <queue>
#include <string>
#include <vector>

using std::vector;

struct AhoCorasick {
    static const int SIG = 26;
    struct Node {
        int next[SIG];
        int link;
        int out;
        Node() : link(0), out(0) {
            for (int i = 0; i < SIG; ++i)
                next[i] = 0;
        }
    };
    vector<Node> t;

    AhoCorasick() { t.emplace_back(); }

    void insert(const std::string& s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (!t[v].next[c]) {
                t[v].next[c] = (int)t.size();
                t.emplace_back();
            }
            v = t[v].next[c];
        }
        t[v].out++;
    }

    void build() {
        std::queue<int> q;
        for (int c = 0; c < SIG; ++c) {
            int u = t[0].next[c];
            if (u) {
                t[u].link = 0;
                q.push(u);
            }
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int c = 0; c < SIG; ++c) {
                int u = t[v].next[c];
                if (u) {
                    t[u].link = t[t[v].link].next[c];
                    t[u].out += t[t[u].link].out;
                    q.push(u);
                } else
                    t[v].next[c] = t[t[v].link].next[c];
            }
        }
    }

    int count_hits(const std::string& s) {
        build();
        int v = 0, ans = 0;
        for (char ch : s) {
            v = t[v].next[ch - 'a'];
            ans += t[v].out;
        }
        return ans;
    }
};

int main() {
    AhoCorasick ac;
    ac.insert("a");
    ac.insert("ab");
    ac.insert("bab");
    ac.insert("bc");
    ac.insert("bca");
    ac.insert("c");
    ac.insert("ca");
    ac.insert("caa");
    assert(ac.count_hits("abccab") >= 1);
    return 0;
}
