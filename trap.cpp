// https://leetcode.com/problems/trapping-rain-water/
#include <vector>
#include <algorithm>
using std::vector;

int trap(vector<int>& height) {
    const int n = height.size();
    if(n < 3)
        return 0;

    vector<int> leftHgt(n, 0);
    vector<int> rightHgt(n, 0);
    int ans = 0;

    leftHgt[0] = height[0];
    for(int i = 1; i < n - 1; ++i)
        leftHgt[i] = std::max(height[i], leftHgt[i-1]);

    rightHgt[n-1] = height[n-1];
    for(int i = n - 2; i > 0; --i)
        rightHgt[i] = std::max(height[i], rightHgt[i+1]);

    for(int i = 1; i < n -1; ++i)
        ans += std::min(leftHgt[i], rightHgt[i]) - height[i];

    return ans;
}