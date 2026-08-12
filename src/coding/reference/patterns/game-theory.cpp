// Game theory — Nim, mex, Sprague–Grundy, win/lose classification
// When: impartial games, who wins with optimal play, combine independent components.
// Time: O(n) Nim; O(n·G) Grundy on small heaps    Space: O(G)
#include <cassert>
#include <vector>

using std::vector;

static int mex(const vector<int>& seen) {
    int g = 0;
    while (g < (int)seen.size() && seen[g])
        g++;
    return g;
}

static int nim_xor(const vector<int>& piles) {
    int x = 0;
    for (int p : piles)
        x ^= p;
    return x;
}

static bool nim_winning(const vector<int>& piles) { return nim_xor(piles) != 0; }

static int grundy_take_k(int max_take) {
    vector<int> g(max_take + 2);
    for (int n = 0; n <= max_take; ++n) {
        vector<int> reach(max_take + 2, 0);
        for (int t = 1; t <= max_take && n - t >= 0; ++t)
            reach[g[n - t]] = 1;
        g[n] = mex(reach);
    }
    return g[max_take];
}

static bool combine_win(const vector<int>& grundies) {
    int x = 0;
    for (int g : grundies)
        x ^= g;
    return x != 0;
}

int main() {
    assert(!nim_winning({1, 2, 3}));
    assert(nim_winning({1, 2}));
    assert(grundy_take_k(3) >= 0);
    assert(combine_win({1, 2}) == nim_winning({1, 2}));
    return 0;
}
