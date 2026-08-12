// 2D matrix — rotate 90° clockwise in-place (square n×n)
// When: image/matrix rotation, layer-wise traversal patterns on grids.
// Time: O(n²)    Space: O(1)
#include <cassert>
#include <vector>

using std::vector;

static void rotate_90_cw(vector<vector<int>>& m) {
    int n = (int)m.size();
    for (int layer = 0; layer < n / 2; ++layer) {
        int first = layer, last = n - 1 - layer;
        for (int i = first; i < last; ++i) {
            int offset = i - first;
            int top = m[first][i];
            m[first][i] = m[last - offset][first];
            m[last - offset][first] = m[last][last - offset];
            m[last][last - offset] = m[i][last];
            m[i][last] = top;
        }
    }
}

int main() {
    vector<vector<int>> m{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate_90_cw(m);
    vector<vector<int>> want{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
    assert(m == want);
    return 0;
}
