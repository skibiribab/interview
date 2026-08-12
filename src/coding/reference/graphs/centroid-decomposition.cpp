// Centroid decomposition — divide tree for path queries (dist sums, etc.)
// When: many queries about paths or distances on a tree; O(n log n) total typical.
// Time: O(n log n) build    Space: O(n)
#include <cassert>
#include <vector>

using std::vector;

struct CentroidDecomp {
    vector<vector<int>> g;
    vector<int> dead, sub;
    vector<int> centroids;

    explicit CentroidDecomp(int n) : g(n), dead(n, 0), sub(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int calc_sub(int u, int p) {
        sub[u] = 1;
        for (int v : g[u]) {
            if (v == p || dead[v])
                continue;
            sub[u] += calc_sub(v, u);
        }
        return sub[u];
    }

    int find_centroid(int u, int p, int total) {
        for (int v : g[u]) {
            if (v == p || dead[v])
                continue;
            if (sub[v] > total / 2)
                return find_centroid(v, u, total);
        }
        return u;
    }

    void decompose(int entry, int p = -1) {
        int total = calc_sub(entry, -1);
        int c = find_centroid(entry, -1, total);
        dead[c] = 1;
        centroids.push_back(c);
        for (int v : g[c]) {
            if (!dead[v])
                decompose(v, c);
        }
    }
};

int main() {
    CentroidDecomp cd(5);
    for (auto [u, v] : vector<std::pair<int, int>>{{0, 1}, {0, 2}, {1, 3}, {1, 4}}) {
        cd.add_edge(u, v);
    }
    cd.decompose(0);
    assert(cd.centroids.size() == 5);
    assert(cd.centroids[0] == 1 || cd.centroids[0] == 0);
    return 0;
}
