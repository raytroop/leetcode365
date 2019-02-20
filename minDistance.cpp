// https://leetcode.com/problems/edit-distance/
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, -1));

        return minDistance(word1, word2, l1, l2, dp);
    }
private:
    // word1[0, 1, 2, ..., l1-1] => word2[0, 1, 2, ..., l2-1]
    int minDistance(string& word1, string& word2, int l1, int l2, vector<vector<int>>& dp){
        if(l1 == 0)
            return l2;
        if(l2 == 0)
            return l1;
        if(dp[l1][l2] >= 0)
            return dp[l1][l2];

        if(word1[l1-1] == word2[l2-1])
            dp[l1][l2] = minDistance(word1, word2, l1-1, l2-1, dp);
        else
            dp[l1][l2] = std::min(minDistance(word1, word2, l1 - 1, l2 - 1, dp), // replace with
                              std::min(minDistance(word1, word2, l1 - 1, l2, dp),   // delete
                                       minDistance(word1, word2, l1, l2 - 1, dp))) // insert
                                       + 1;

        return dp[l1][l2];
    }
};