// https://leetcode.com/problems/decode-ways/

#include <string>
#include <vector>
using std::vector;
using std::string;

int numDecodings(string s) {
    if(s.empty())
        return 0;
    if(s[0] == '0')
        return 0;
    const int n = s.length();
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; ++i){
        if(s[i-1] == '0'){
            if(s[i-2] == '1' || s[i-2] == '2')
                dp[i] = dp[i-2];
            else
                return 0;
        }
        else{
            dp[i] = dp[i-1];
            if(s[i-2] != '0'){
                int twoDigt = 10 * (s[i-2] - '0') + s[i-1] - '0';
                if(twoDigt >= 1 && twoDigt <= 26)
                dp[i] += dp[i-2];
            }
        }

    }
    return dp.back();
}