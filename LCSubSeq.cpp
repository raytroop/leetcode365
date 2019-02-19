//https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
/* Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4. */

#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;

int LCSubSeq(string s1, string s2){
    const int row = s1.length();
    const int col = s2.length();
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    for(int i = 1; i <= row; ++i){
        for(int j = 1; j <= col; ++j){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[row][col];
}

int main(){
    string s1("AGGTAB");
    string s2("GTAB");
    int ans = LCSubSeq(s1, s2);
    assert(ans == 4);

    return 0;
}