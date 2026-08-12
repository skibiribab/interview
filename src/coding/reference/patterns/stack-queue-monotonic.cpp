// Monotonic stack / deque — next greater, sliding window max, histogram tricks
// When: “next element satisfying …”, window min/max in O(n), largest rectangle in histogram.
// Time: O(n) for linear scans with stack/deque    Space: O(n) stack depth
#include <cassert>
#include <deque>
#include <stack>
#include <vector>

using std::vector;

// For each i, index of next element to the right that is > nums[i], or -1
static vector<int> next_greater_index(const vector<int>& nums) {
    int n = (int)nums.size();
    vector<int> ans(n, -1);
    std::stack<int> st; // indices, increasing values nums[st.top()]
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

// Max of each window of size k
static vector<int> sliding_window_max(const vector<int>& nums, int k) {
    std::deque<int> dq; // indices, values decreasing
    vector<int> out;
    for (int i = 0; i < (int)nums.size(); ++i) {
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            out.push_back(nums[dq.front()]);
    }
    return out;
}

int main() {
    assert((next_greater_index({2, 1, 2, 4, 3}) == vector<int>{3, 2, 3, -1, -1}));
    assert((sliding_window_max({1, 3, -1, -3, 5, 3, 6, 7}, 3) == vector<int>({3, 3, 5, 5, 6, 7})));
    return 0;
}
