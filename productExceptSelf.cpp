// https://leetcode.com/problems/product-of-array-except-self/
// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-238-product-of-array-except-self/

#include <vector>
using std::vector;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty())   return {};

        const int n = nums.size();
        vector<int> left(n, 1); // left[i] = prod(nums[0] ~ nums[i - 1])
        vector<int> right(n, 1); // right[i] = prod(nums[i + 1] ~ nums[n - 1])

        for (int i = 1; i < n; ++i)
            left[i] = left[i - 1] * nums[i - 1];

        for (int i = n - 2; i >= 0; --i)
            right[i] = right[i + 1] * nums[i + 1];

        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
            ans[i] = left[i] * right[i];

        return ans;
    }
};