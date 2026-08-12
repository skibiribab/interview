// Quickselect — kth smallest in average linear time (partition like quicksort)
// When: kth largest/s smallest, median, top-K without full sort (mutable array OK).
// Time: O(n) average per call; O(n²) worst    Space: O(1) extra; O(n) recursion worst-case depth without tail
// optimization
#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

// 0-based rank: returns index of element that would sit at nums[rank] if sorted
static int partition(vector<int>& nums, int lo, int hi) {
    int pivot = nums[hi];
    int i = lo;
    for (int j = lo; j < hi; ++j) {
        if (nums[j] <= pivot) {
            std::swap(nums[i], nums[j]);
            ++i;
        }
    }
    std::swap(nums[i], nums[hi]);
    return i;
}

static int quickselect(vector<int>& nums, int lo, int hi, int rank) {
    for (;;) {
        int p = partition(nums, lo, hi);
        if (p == rank)
            return nums[p];
        if (rank < p)
            hi = p - 1;
        else
            lo = p + 1;
    }
}

// k is 1-based smallest (k=1 -> minimum)
static int kth_smallest(vector<int> nums, int k) {
    assert(k >= 1 && k <= (int)nums.size());
    return quickselect(nums, 0, (int)nums.size() - 1, k - 1);
}

int main() {
    assert(kth_smallest({3, 2, 1, 5, 6, 4}, 2) == 2);
    assert(kth_smallest({1}, 1) == 1);
    assert(kth_smallest({7, 7, 7, 7}, 3) == 7);
    return 0;
}
