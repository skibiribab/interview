// Hash map patterns — frequency, complement lookup, anagram keys
// When: two-sum unsorted, first unique, grouping by signature, O(1) expected lookups.
// Time: O(n) expected per scan    Space: O(n)
#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::vector;

static vector<int> two_sum_unsorted(const vector<int>& nums, int target) {
    std::unordered_map<int, int> pos; // value -> index
    for (int i = 0; i < (int)nums.size(); ++i) {
        int need = target - nums[i];
        auto it = pos.find(need);
        if (it != pos.end())
            return {it->second, i};
        pos[nums[i]] = i;
    }
    return {-1, -1};
}

// Group indices by sorted-key anagram signature
static string anagram_key(const string& s) {
    vector<int> c(26);
    for (char ch : s)
        c[ch - 'a']++;
    string key;
    for (int i = 0; i < 26; ++i)
        if (c[i])
            key += char('a' + i) + string(":") + std::to_string(c[i]) + ",";
    return key;
}

int main() {
    assert((two_sum_unsorted({3, 1, 4, 2}, 6) == vector<int>{2, 3}));
    assert(anagram_key("eat") == anagram_key("tea"));
    assert(anagram_key("eat") != anagram_key("tan"));
    return 0;
}
