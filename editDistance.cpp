// https://leetcode.com/problems/edit-distance/

#include <vector>
#include <algorithm>
#include <string>
using std::string;
using std::vector;

// http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-72-edit-distance/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        // the first row/column is just for convenience and NOT USED
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, -1));

        return minDistance(word1, word2, dp, l1, l2);
    }
private:
    // minDistance from word1[0:l1-1] to word2[0:l2-1]
    int minDistance(string& word1, string& word2, vector<vector<int>>& dp, int l1, int l2) {
        if(l1 == 0)
            return l2;
        if(l2 == 0)
            return l1;
        if(dp[l1][l2] != -1)
            return dp[l1][l2];

        if (word1[l1 - 1] == word2[l2 - 1])
            return dp[l1][l2] = minDistance(word1, word2, dp, l1 - 1, l2 - 1);
        else
            return dp[l1][l2] = std::min(minDistance(word1, word2, dp, l1 - 1, l2),                     // delete `c` and ab -> xyz
                                         std::min(minDistance(word1, word2, dp, l1, l2 - 1),            // abc -> xy and insert `z`
                                                  minDistance(word1, word2, dp, l1 - 1, l2 - 1))) +     // ab -> xy and replace `c` with `z`
                                1;
    }
};