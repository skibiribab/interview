// Fenwick tree 2D — rectangle sum, point updates
// When: 2D prefix queries on a grid; offline compressed coordinates.
// Time: O(log² n)    Space: O(n²) dense (use map/dynamic for sparse)
#include <cassert>
#include <vector>

using std::vector;

struct Fenwick2D {
    int n, m;
    vector<vector<long long>> bit;
    Fenwick2D(int n_, int m_) : n(n_), m(m_), bit(n_ + 1, vector<long long>(m_ + 1)) {}

    void add(int x, int y, long long d) { // 0-based
        for (int i = x + 1; i <= n; i += i & -i)
            for (int j = y + 1; j <= m; j += j & -j)
                bit[i][j] += d;
    }

    long long pref(int x, int y) const { // sum [0..x]×[0..y]
        long long s = 0;
        for (int i = x + 1; i > 0; i -= i & -i)
            for (int j = y + 1; j > 0; j -= j & -j)
                s += bit[i][j];
        return s;
    }

    long long rect(int x1, int y1, int x2, int y2) const {
        return pref(x2, y2) - (x1 ? pref(x1 - 1, y2) : 0) - (y1 ? pref(x2, y1 - 1) : 0) +
               (x1 && y1 ? pref(x1 - 1, y1 - 1) : 0);
    }
};

int main() {
    Fenwick2D ft(3, 3);
    ft.add(1, 1, 5);
    ft.add(2, 2, 3);
    assert(ft.rect(1, 1, 2, 2) == 8);
    return 0;
}
