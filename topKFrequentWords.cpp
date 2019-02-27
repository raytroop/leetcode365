//https://leetcode.com/problems/top-k-frequent-words/

#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <queue>
using std::vector;
using std::string;
using std::pair;
using std::unordered_map;
using std::priority_queue;

vector<string> topKFrequentWords(vector<string>& words, int k){
    unordered_map<string, int> counts;
    for(string& x: words)
        ++counts[x];
    // min heap
    // Using lambda to compare elements.
    auto cmp = [](pair<string, int>& element1, pair<string, int>& element2) {
        if(element1.second == element2.second)
            return element1.first < element2.first;
        return element1.second > element2.second;};

    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> heap(cmp);
    for(const auto& p: counts){
        heap.push(p);
        if(heap.size() > k)
            heap.pop();
    }

    vector<string> ans(k);
    for(int i = k-1; i >= 0; --i){
        ans[i] = heap.top().first;
        heap.pop();
    }

    return ans;
}
