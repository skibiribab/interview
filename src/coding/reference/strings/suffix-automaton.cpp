// Suffix automaton — all substrings in O(n) states (online construction)
// When: count distinct substrings, locate pattern, endpos-class DP on strings.
// Time: O(n) build    Space: O(n) states
#include <algorithm>
#include <cassert>
#include <map>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct SuffixAutomaton {
    struct State {
        int len, link;
        std::map<char, int> next;
        State(int l = 0, int lk = -1) : len(l), link(lk) {}
    };
    vector<State> st;
    int last = 0;

    explicit SuffixAutomaton(const string& s) {
        st.reserve(2 * s.size());
        st.emplace_back();
        for (char c : s)
            extend(c);
    }

    void extend(char c) {
        int cur = (int)st.size();
        st.emplace_back(st[last].len + 1);
        int p = last;
        while (p != -1 && !st[p].next.count(c)) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = (int)st.size();
                st.push_back(st[q]);
                st[clone].len = st[p].len + 1;
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    long long count_distinct_substrings() const {
        long long ans = 0;
        for (size_t v = 1; v < st.size(); ++v)
            ans += st[v].len - st[st[v].link].len;
        return ans;
    }
};

int main() {
    SuffixAutomaton sa("aba");
    assert(sa.count_distinct_substrings() == 5); // a,b,ab,ba,aba
    return 0;
}
