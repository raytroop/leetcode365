//https://leetcode.com/problems/3sum/

#include <vector>
#include <algorithm>
using std::vector;

// https://zxi.mytechroad.com/blog/two-pointers/leetcode-15-3sum/
vector<vector<int>> threeSum(vector<int>& nums) {
    const int n = nums.size();
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for(int i = 0; i <= n-3; ++i){
        if (nums[i] > 0)
            break;
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        int target = -nums[i];
        int l = i + 1;
        int r = n - 1;
        while(l < r){
            int sum = nums[l] + nums[r];
            if(sum < target)
                ++l;
            else if(sum > target)
                --r;
            else{
                ans.push_back({nums[i], nums[l], nums[r]});
                while(l < r && nums[l+1] == nums[l])
                    ++l;
                while(l < r && nums[r-1] == nums[r])
                    --r;
                ++l;
                --r;
            }
        }
    }

    return ans;
}
