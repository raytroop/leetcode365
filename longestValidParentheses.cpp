// https://leetcode.com/problems/longest-valid-parentheses/

#include <vector>
#include <string>
using std::vector;
using std::string;


//https://leetcode.com/problems/longest-valid-parentheses/solution/
//Approach 2: Using Dynamic Programming

/*
dp[i] represents the length of the longest valid substring ending at i-th index
1) if s[i] == ')' and s[i-1] == '('
    dp[i] = dp[i-2] + 2

2) if s[i] == ')' and s[i-2] == ')'
    _           _          (                    )       )
i-dp[i-1]-2  i-dp[i-1]-1  i-dp[i-1]             i-1     i

if s[i-dp[i-1]-1] == '('
    dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2]
else
    dp[i] = 0
3) if s[i] = '('
    dp[i] = 0
*/

int longestValidParentheses(string s) {
    if(s.empty())
        return 0;
    const int n = s.length();
    vector<int> dp(n, 0);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == ')' && i > 0)
            if(s[i-1] == '(')
                dp[i] = 2 + (i - 2 >= 0 ? dp[i-2] : 0);
            else
                if(i-dp[i-1] - 1 >= 0 && s[i-dp[i-1] - 1] == '(')
                    dp[i] = dp[i-1] + 2 + (i-dp[i-1]-2 >= 0 ? dp[i-dp[i-1]-2] : 0);
        ans = std::max(ans, dp[i]);
    }

    return ans;
}