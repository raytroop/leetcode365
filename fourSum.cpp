// https://leetcode.com/problems/4sum/

#include <vector>
#include <algorithm>
using std::vector;


// based on `threeSum`
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    const int n = nums.size();
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for(int i = 0; i <= n-4; ++i){
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        for(int j = i + 1; j <= n-3; ++j){
            if(j > i + 1 && nums[j] == nums[j-1])
                continue;

            int l = j + 1;
            int r = n - 1;
            while(l < r){
                int sum = nums[i] + nums[j] + nums[l] + nums[r];
                if(sum < target)
                    ++l;
                else if(sum > target)
                    --r;
                else{
                    ans.push_back({nums[i],  nums[j],  nums[l],  nums[r]});
                    while(l < r && nums[l+1] == nums[l])
                        ++l;
                    while(l < r && nums[r-1] == nums[r])
                        --r;
                    ++l;
                    --r;
                }
            }
        }
    }

    return ans;
}


// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-18-4sum/
// Sorting + Binary Search
#include <set>
using std::set;
vector<vector<int>> fourSum_sol(vector<int>& nums, int target){
    const int n = nums.size();
    std::sort(nums.begin(), nums.end());
    set<vector<int>> ans;

    for(int i = 0; i <= n - 4; ++i){
        for(int j = i + 1; j <= n - 3; ++j){
            for(int k = j + 1; k <= n- 2; ++k){
                int t = target - nums[i] - nums[j] - nums[k];
                if(t < nums[k])
                    break;
                if(!std::binary_search(nums.begin() + k + 1, nums.end(), t))
                    continue;
                ans.insert({nums[i], nums[j], nums[k], t});
            }
        }
    }

    return vector<vector<int>>(ans.begin(), ans.end());
}
