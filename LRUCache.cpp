// https://leetcode.com/problems/lru-cache/

#include <list>
#include <unordered_map>
#include <utility>
#include <iostream>
using std::cout;
using std::endl;

using std::list;
using std::unordered_map;
using std::pair;

// http://zxi.mytechroad.com/blog/hashtable/leetcode-146-lru-cache/
class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }

    int get(int key) {
        const auto it = m_.find(key);
        // If key does not exist
        if (it == m_.cend())
            return -1;

        // Move this key to the front of the cache
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        const auto it = m_.find(key);

        // Key already exists
        if (it != m_.cend()) {
            // Update the value
            it->second->second = value;
            // Move this entry to the front of the cache
            cache_.splice(cache_.begin(), cache_, it->second);
        } else {
            // Reached the capacity, remove the oldest entry
            if (cache_.size() == capacity_) {
                m_.erase(cache_.back().first);
                cache_.pop_back();
            }

            // Insert the entry to the front of the cache and update mapping.
            cache_.emplace_front(key, value);
            m_[key] = cache_.begin();
        }
    }

private:
    int capacity_;
    list<pair<int, int>> cache_;
    unordered_map<int, list<pair<int, int>>::iterator> m_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache cache( 2 /* capacity */ );

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // returns 1
    cache.put(3, 3);    // evicts key 2
    cout << cache.get(2) << endl;       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cout << cache.get(1) << endl;       // returns -1 (not found)
    cout << cache.get(3) << endl;       // returns 3
    cout << cache.get(4) << endl;       // returns 4

    return 0;
}