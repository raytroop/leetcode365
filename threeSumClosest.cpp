// https://leetcode.com/problems/3sum-closest/

#include <vector>
#include <algorithm>
#include <climits>
using std::vector;

// https://zxi.mytechroad.com/blog/two-pointers/leetcode-16-3sum-closest/
int threeSumClosest(vector<int> &num, int target) {
    int n = num.size();
    int d = INT_MAX;
    int ans = target;
    sort(num.begin(), num.end());

    for (int i = 0; i < n - 2; i++) {
        int s = i + 1, t = n - 1;
        while (s < t) {
          int sum = num[i] + num[s] + num[t];
          if (sum == target)
              return target;

          int diff = std::abs(sum - target);
          if (diff < d) {
            d = diff;
            ans = sum;
          }

          if (sum > target) --t;
          else ++s;
        }
      }

      return ans;
  }