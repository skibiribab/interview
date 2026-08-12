// Z-function — prefix overlap of s with every suffix s[i..]
// When: periodicity, string self-similarity, some counting on runs.
// Time: O(n)    Space: O(n)
#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using std::vector;

static vector<int> z_function(const std::string& s) {
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = std::min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    auto z = z_function("abababa");
    assert(z[1] == 0 && z[2] == 3);
    return 0;
}
