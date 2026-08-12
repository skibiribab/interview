// Gaussian elimination — solve Ax = b over doubles (or detect singular)
// When: linear systems, matrix rank; modular variant for GF(p) contests.
// Time: O(n³)    Space: O(n²)
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>

using std::vector;

// Returns solution x, or empty if no unique solution. a is n×(n+1) augmented [A|b].
static vector<double> gauss(vector<vector<double>> a) {
    const int n = (int)a.size();
    const double EPS = 1e-9;
    for (int col = 0, row = 0; col < n && row < n; ++col) {
        int piv = row;
        for (int i = row; i < n; ++i)
            if (std::fabs(a[i][col]) > std::fabs(a[piv][col]))
                piv = i;
        if (std::fabs(a[piv][col]) < EPS)
            continue;
        std::swap(a[piv], a[row]);
        double div = a[row][col];
        for (int j = col; j <= n; ++j)
            a[row][j] /= div;
        for (int i = 0; i < n; ++i) {
            if (i == row)
                continue;
            double f = a[i][col];
            for (int j = col; j <= n; ++j)
                a[i][j] -= f * a[row][j];
        }
        ++row;
    }
    vector<double> x(n);
    for (int i = 0; i < n; ++i) {
        int piv = -1;
        for (int j = 0; j < n; ++j)
            if (std::fabs(a[i][j]) > EPS) {
                piv = j;
                break;
            }
        if (piv < 0) {
            if (std::fabs(a[i][n]) > EPS)
                return {}; // inconsistent
            continue;
        }
        x[piv] = a[i][n];
    }
    return x;
}

int main() {
    // x + y = 3, 2x + y = 4 → (1, 2)
    auto x = gauss({{1, 1, 3}, {2, 1, 4}});
    assert(x.size() == 2);
    assert(std::fabs(x[0] - 1) < 1e-6 && std::fabs(x[1] - 2) < 1e-6);
    return 0;
}
