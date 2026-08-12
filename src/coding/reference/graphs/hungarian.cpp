// Hungarian algorithm — minimum-cost assignment (n workers → n jobs)
// When: bipartite perfect matching with costs; assignment / scheduling.
// Time: O(n³)    Space: O(n²)
#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>

using std::vector;

static const int INF = 1e9;

// cost[i][j] = cost to assign row i to column j; returns min total cost.
static int hungarian(vector<vector<int>> cost) {
    int n = (int)cost.size();
    vector<int> u(n + 1), v(n + 1), p(n + 1), way(n + 1);
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv(n + 1, INF);
        vector<char> used(n + 1, 0);
        do {
            used[j0] = 1;
            int i0 = p[j0], delta = INF, j1 = 0;
            for (int j = 1; j <= n; ++j) {
                if (used[j])
                    continue;
                int cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                if (cur < minv[j]) {
                    minv[j] = cur;
                    way[j] = j0;
                }
                if (minv[j] < delta) {
                    delta = minv[j];
                    j1 = j;
                }
            }
            for (int j = 0; j <= n; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    return -v[0];
}

int main() {
    vector<vector<int>> cost = {{4, 1, 3}, {2, 0, 5}, {3, 2, 2}};
    assert(hungarian(cost) == 5); // 1+0+2
    return 0;
}
