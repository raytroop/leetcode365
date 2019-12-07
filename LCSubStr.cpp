//https://www.geeksforgeeks.org/longest-common-substring-dp-29/
/*Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.
Examples :

Input : X = "GeeksforGeeks", y = "GeeksQuiz"
Output : 5
The longest common substring is "Geeks" and is of
length 5.

Input : X = "abcdxyz", y = "xyzabcd"
Output : 4
The longest common substring is "abcd" and is of
length 4.

Input : X = "zxabcdezy", y = "yzabcdezx"
Output : 6
The longest common substring is "abcdez" and is ofA robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
length 6.*/

#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;

int LCSubStr(string &X, string &Y){
    const int row = X.length();
    const int col = Y.length();

    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    int result = 0;
    for(int i = 1; i <= row; ++i){
        for(int j = 1; j <= col; ++j){
            if(X[i-1] == Y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                result = std::max(result, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }

    return result;
}