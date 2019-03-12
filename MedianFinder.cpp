// https://leetcode.com/problems/find-median-from-data-stream/

#include <queue>
#include <vector>
#include <utility>
using std::priority_queue;
using std::vector;


// https://zxi.mytechroad.com/blog/leetcode/leetcode-295-find-median-from-data-stream/
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if(l_.empty() || num < l_.top()){
            l_.push(num);
        }
        else
            r_.push(num);

        // rebalance the tree
        // make sure len(l_) == len(r_) or len(l_) == len(r_) + 1;
        if(l_.size() < r_.size()){
            l_.push(r_.top());
            r_.pop();
        }
        else if(l_.size() == r_.size() + 2){
            r_.push(l_.top());
            l_.pop();
        }

    }

    double findMedian() {
        if(l_.size() == r_.size())
            return (static_cast<double>(l_.top()) + r_.top()) / 2;
        else
            return static_cast<double>(l_.top());
    }
private:
    priority_queue<int, vector<int>, std::less<int>> l_; // max_heap
    priority_queue<int, vector<int>, std::greater<int>> r_; // min_heap
};