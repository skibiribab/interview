// 0-1 BFS — shortest path on unweighted graph with 0/1 edge weights. O(V + E).
#include <cassert>
#include <deque>
#include <utility>
#include <vector>

static int zero_one_bfs(const std::vector<std::vector<std::pair<int, int>>>& adj, int start,
                        int goal) {
    const int n = static_cast<int>(adj.size());
    const int INF = 1'000'000'000;
    std::vector<int> dist(n, INF);
    std::deque<int> dq;
    dist[start] = 0;
    dq.push_back(start);
    while (!dq.empty()) {
        const int u = dq.front();
        dq.pop_front();
        for (const auto [v, w] : adj[u]) {
            const int nd = dist[u] + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                if (w == 0) {
                    dq.push_front(v);
                } else {
                    dq.push_back(v);
                }
            }
        }
    }
    return dist[goal];
}

int main() {
    std::vector<std::vector<std::pair<int, int>>> adj(4);
    adj[0].push_back({1, 0});
    adj[0].push_back({2, 1});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 0});
    assert(zero_one_bfs(adj, 0, 3) == 1);
    return 0;
}
