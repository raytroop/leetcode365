//https://leetcode.com/problems/longest-palindromic-substring/
#include <vector>
#include <string>
using std::vector;
using std::string;

string longestPalindrome(string s)
{
    const int sz = s.length();
    vector<vector<bool>> dp(sz, vector<bool>(sz, false));
    int start = 0;
    int maxlen = 1;
    for (int i = 0; i < sz; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (i - j < 2)
                dp[i][j] = (s[i] == s[j]);
            else
                dp[i][j] = dp[i - 1][j + 1] && (s[i] == s[j]);

            if (dp[i][j] && (i - j + 1 > maxlen))
            {
                start = j;
                maxlen = i - j + 1;
            }
        }
    }

    return s.substr(start, maxlen);
}