//https://leetcode.com/problems/3sum/

#include <vector>
#include <algorithm>
using std::vector;

// https://zxi.mytechroad.com/blog/two-pointers/leetcode-15-3sum/
vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    const int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n - 2; ++i) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) {
                ans.push_back({nums[i], nums[l++], nums[r--]});
                while (l < r && nums[l] == nums[l - 1]) l++;
                while (l < r && nums[r] == nums[r + 1]) r--;
            } else if (sum > 0)
                r--;
            else
                l++;
        }
    }

    return ans;
}
