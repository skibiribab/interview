// Manacher — longest palindromic substring / odd–even radii in linear time
// When: palindrome length/center queries on one string.
// Time: O(n)    Space: O(n)
#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using std::vector;

static int longest_palindrome_substring_length(const std::string& s) {
    std::string t = "^";
    for (char c : s) {
        t += '#';
        t += c;
    }
    t += "#$";
    int n = (int)t.size();
    vector<int> p(n);
    int c = 0, r = 0, best = 0;
    for (int i = 1; i < n - 1; ++i) {
        int mirr = 2 * c - i;
        if (i < r)
            p[i] = std::min(r - i, p[mirr]);
        while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
            ++p[i];
        if (i + p[i] > r)
            c = i, r = i + p[i];
        best = std::max(best, p[i]);
    }
    return best;
}

int main() {
    assert(longest_palindrome_substring_length("babad") == 3);
    assert(longest_palindrome_substring_length("cbbd") == 2);
    return 0;
}
