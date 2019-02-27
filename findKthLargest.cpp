// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, std::greater<int>> minHeap;
    for(int x: nums){
        minHeap.push(x);
        if(minHeap.size() > k)
            minHeap.pop();
    }

    return minHeap.top();
}