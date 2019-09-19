// https://leetcode.com/problems/lfu-cache/submissions/

#include <set>
#include <unordered_map>
using std::set;
using std::unordered_map;

/* Solution 1: O(logc) c is the capacity */
// Author: Huahua
// Running time: 99 ms
struct CacheNode {
    int key;
    int value;
    int freq;
    long tick;

    // Defines the order, smaller one will be evicted first
    bool operator <(const CacheNode& rhs) const {
        if (freq < rhs.freq) return true;
        if (freq == rhs.freq) return tick < rhs.tick;
        return false;
    }
};
class LFUCache {
public:
    LFUCache(int capacity):capacity_(capacity), tick_(0) {}

    int get(int key) {
        auto it = m_.find(key);
        if (it == m_.cend()) return -1;
        int value = it->second.value;
        touch(it->second);
        return value;
    }

    void put(int key, int value) {
        if (capacity_ == 0) return;

        auto it = m_.find(key);

        if (it != m_.cend()) {
            // Key exists, update value and touch
            it->second.value = value;
            touch(it->second);
            return;
        }

        if (m_.size() == capacity_) {
            // Remove the first node in cache
            const CacheNode& node = *cache_.cbegin();
            m_.erase(node.key);
            cache_.erase(node);
        }

        CacheNode node{key, value, 1, ++tick_};
        m_[node.key] = node;
        cache_.insert(node);
    }
private:
    void touch(CacheNode& node) {
        cache_.erase(node);     // log(capacity)
        ++node.freq;
        node.tick = ++tick_;
        cache_.insert(node);    // log(capacity)
    }

    long tick_;
    int capacity_;
    unordered_map<int, CacheNode> m_;
    set<CacheNode> cache_;

};