// https://leetcode.com/problems/container-with-most-water/

// https://leetcode.com/problems/container-with-most-water/solution/

#include <vector>
#include <algorithm>
using std::vector;

int maxArea(vector<int>& height) {
    int l = 0;
    int r = height.size() - 1;
    int ans = -1;
    while (l < r) {
        int area = (r - l) * std::min(height[l], height[r]);
        ans = std::max(ans, area);
        if (height[l] < height[r])
            l++;
        else
            r--;
    }

    return ans;
}