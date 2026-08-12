// Google Code Jam / Meta Hacker Cup — multiple cases with "Case #k:" prefix
// When: batch judging expects labeled output per case; put logic in solve().
// Time: O(total input)    Space: O(1) besides stream buffer
#include <iostream>

static void fast_io() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

static void solve(int case_id) {
    (void)case_id;
    // TODO: read case input, print answer (no trailing newline here)
}

int main() {
    fast_io();
    int T = 0;
    if (!(std::cin >> T)) {
        return 0;
    }
    for (int t = 1; t <= T; ++t) {
        std::cout << "Case #" << t << ": ";
        solve(t);
        std::cout << '\n';
    }
    return 0;
}
