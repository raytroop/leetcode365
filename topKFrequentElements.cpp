//https://leetcode.com/problems/top-k-frequent-elements/

#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
using std::vector;
using std::priority_queue;
using std::unordered_map;
using std::pair;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    for(int x: nums)
        ++counts[x];
    // min heap
    // Using lambda to compare elements.
    auto cmp = [](pair<int, int>& element1, pair<int, int>& element2) { return element1.second > element2.second;};
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
    for(const auto& p: counts){
        heap.push(p);
        if(heap.size() > k)
            heap.pop();
    }

    vector<int> ans;
    for(int i = 0; i < k; ++i){
        ans.push_back(heap.top().first);
        heap.pop();
    }

    return ans;
}