// https://leetcode.com/problems/largest-rectangle-in-histogram/
/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/

#include <cassert>
#include <stack>
#include <vector>
#include <algorithm>
using std::vector;
using std::stack;

// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        const int n = heights.size();
        int ans = 0;
        int i = 0;
        while(i < n){
            if(s.empty() || heights[s.top()] <= heights[i])
                s.push(i++);
            else{
                int idx = s.top();
                s.pop();
                int width = s.empty() ? i : i - s.top() -1;
                ans = std::max(ans, width * heights[idx]);
            }
        }

        while(!s.empty()){
            int idx = s.top();
            s.pop();
            int width = s.empty() ? n : n - s.top() - 1;
            ans = std::max(ans, width * heights[idx]);
        }

        return ans;
}


int main(){
    vector<int> heights{2,1,5,6,2,3};
    int ans = largestRectangleArea(heights);

    assert(ans == 10);

    return 0;
}