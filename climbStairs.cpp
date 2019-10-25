// https://leetcode.com/problems/climbing-stairs/

#include <vector>
using std::vector;

int climbStairs(int n)
{
    if (n < 3)
        return n;

    int dp1 = 1;
    int dp2 = 2;

    for (int i = 3; i < n + 1; ++i) {
        int tmp = dp2;
        dp2 = dp1 + dp2;
        dp1 = tmp;
    }

    return dp2;
}