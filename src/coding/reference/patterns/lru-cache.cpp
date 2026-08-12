// LRU cache — least-recently-used eviction with O(1) get and put
// When: capacity-bounded key-value store (design interview / OS-style caches).
// Time: O(1) average get/put    Space: O(capacity)
#include <cassert>
#include <list>
#include <unordered_map>
#include <utility>

class LRUCache {
    int cap;
    std::list<std::pair<int, int>> order; // front = MRU
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> pos;

  public:
    explicit LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = pos.find(key);
        if (it == pos.end())
            return -1;
        order.splice(order.begin(), order, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        if (auto it = pos.find(key); it != pos.end()) {
            it->second->second = value;
            order.splice(order.begin(), order, it->second);
            return;
        }
        if ((int)order.size() == cap) {
            int evict = order.back().first;
            pos.erase(evict);
            order.pop_back();
        }
        order.push_front({key, value});
        pos[key] = order.begin();
    }
};

int main() {
    LRUCache c(2);
    c.put(1, 1);
    c.put(2, 2);
    assert(c.get(1) == 1);
    c.put(3, 3);
    assert(c.get(2) == -1);
    c.put(4, 4);
    assert(c.get(1) == -1);
    assert(c.get(3) == 3);
    assert(c.get(4) == 4);
    return 0;
}
