#include <vector>
using std::vector;

// https://stackoverflow.com/a/25883550/8037585
class Solution {
public:
    vector<int> merge_sort(vector<int> nums) {
        if (nums.size() > 1) {
            std::vector<int> nums1(nums.begin(), nums.begin() + nums.size() / 2);
            vector<int> left = merge_sort(vector<int>(nums.begin(), nums.begin() + nums.size() / 2));
            vector<int> right = merge_sort(vector<int>(nums.begin() + nums.size() / 2, nums.end()));
            return merge(left, right);
        }
        else
            return nums;
    }
private:
    vector<int> merge(vector<int> left, vector<int> right){
        int i = 0;
        int j = 0;
        vector<int> ans;
        while(i < left.size() && j < right.size()){
            if(left[i] < right[j]){
                ans.push_back(left[i]);
                ++i;
            }
            else{
                ans.push_back(right[j]);
                ++j;
            }
        }

        while(i < left.size()){
            ans.push_back(left[i]);
            ++i;
        }

        while(j < right.size()){
            ans.push_back(right[j]);
            ++j;
        }

        return ans;
    }
};