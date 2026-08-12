// ICPC / Codeforces / CodeChef — multiple test cases, logic in solve_case
// When: batch judging with T on first line; keep I/O in main, pure logic in solve_case.
// Time: O(total input)    Space: O(1) besides stream buffer
#include <iostream>

using int64 = long long;

[[maybe_unused]] static constexpr int64 k_mod = 1'000'000'007;

[[maybe_unused]] static int64 mod_add(int64 a, int64 b) {
    int64 s = a + b;
    if (s >= k_mod) {
        s -= k_mod;
    }
    return s;
}

static void fast_io() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// Reads one test case from cin and prints the answer line (no trailing spaces).
static void solve_case() {
    int n = 0;
    if (!(std::cin >> n)) {
        return;
    }
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        long long x = 0;
        std::cin >> x;
        sum += x;
    }
    std::cout << sum << '\n';
}

int main() {
    fast_io();
    int T = 0;
    if (!(std::cin >> T)) {
        return 0;
    }
    for (int t = 0; t < T; ++t) {
        (void)t;
        solve_case();
    }
    return 0;
}
