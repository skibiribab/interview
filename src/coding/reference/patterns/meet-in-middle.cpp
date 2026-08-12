// Meet-in-the-middle — split set, enumerate halves, combine. O(2^(n/2)).
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <vector>

static int64_t subset_sum_closest(const std::vector<int>& values, int64_t target) {
    const int n = static_cast<int>(values.size());
    const int half = n / 2;
    std::vector<int64_t> left_sums{0}, right_sums{0};
    for (int mask = 1; mask < (1 << half); ++mask) {
        int64_t sum = 0;
        for (int i = 0; i < half; ++i) {
            if (mask & (1 << i)) {
                sum += values[i];
            }
        }
        left_sums.push_back(sum);
    }
    for (int mask = 1; mask < (1 << (n - half)); ++mask) {
        int64_t sum = 0;
        for (int i = 0; i < n - half; ++i) {
            if (mask & (1 << i)) {
                sum += values[half + i];
            }
        }
        right_sums.push_back(sum);
    }
    std::sort(left_sums.begin(), left_sums.end());
    int64_t best = left_sums.front();
    int64_t best_diff = std::llabs(best - target);
    for (int64_t r : right_sums) {
        const int64_t need = target - r;
        auto it = std::lower_bound(left_sums.begin(), left_sums.end(), need);
        if (it != left_sums.end()) {
            const int64_t diff = std::llabs(*it + r - target);
            if (diff < best_diff) {
                best_diff = diff;
                best = *it + r;
            }
        }
        if (it != left_sums.begin()) {
            const int64_t diff = std::llabs(*(it - 1) + r - target);
            if (diff < best_diff) {
                best_diff = diff;
                best = *(it - 1) + r;
            }
        }
    }
    return best;
}

int main() {
    assert(subset_sum_closest({1, 2, 3, 4}, 5) == 5);
    assert(subset_sum_closest({10, 20, 30}, 35) == 30);
    return 0;
}
