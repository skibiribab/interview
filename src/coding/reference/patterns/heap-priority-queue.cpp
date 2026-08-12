// Binary heap (priority_queue) — top-K, schedules, merge-k-way
// When: k largest/smallest, Dijkstra, “always pick best pending item”.
// Time: O(log n) push/pop; O(n) heapify    Space: O(n) for heap contents
#include <algorithm>
#include <cassert>
#include <functional>
#include <queue>
#include <vector>

using std::vector;

// k largest elements (min-heap of size k)
static vector<int> k_largest(const vector<int>& nums, int k) {
    std::priority_queue<int, vector<int>, std::greater<int>> pq; // min-heap
    for (int x : nums) {
        pq.push(x);
        if ((int)pq.size() > k)
            pq.pop();
    }
    vector<int> out;
    while (!pq.empty()) {
        out.push_back(pq.top());
        pq.pop();
    }
    std::sort(out.begin(), out.end());
    return out;
}

int main() {
    assert((k_largest({3, 2, 1, 5, 6, 4}, 2) == vector<int>{5, 6}));
    return 0;
}
