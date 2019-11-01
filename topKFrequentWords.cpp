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


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counter;
        for (auto s: words)
            counter[s] += 1;

        // decltype(cmp) not work
        priority_queue<std::pair<string, int>, vector<std::pair<string, int>>,
                std::function<bool(std::pair<string, int>&, std::pair<string, int>&)>> minheap(cmp);
        for (auto& p: counter) {
            minheap.push(p);
            if (minheap.size() > k)
                minheap.pop();
        }

        vector<string> ans;
        while (!minheap.empty()) {
            ans.push_back(minheap.top().first);
            minheap.pop();
        }


        std::reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    // CAUTION `static` is important
    static bool cmp(std::pair<string, int>& s1, std::pair<string, int>& s2) {
        if (s1.second > s2.second)
            return true;
        if (s1.second == s2.second && s1.first < s2.first)
            return true;
        else
            return false;
    }
};