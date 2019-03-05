// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<vector<char>> d(10);
        d[2] = {'a','b','c'};
        d[3] = {'d','e','f'};
        d[4] = {'g','h','i'};
        d[5] = {'j','k','l'};
        d[6] = {'m','n','o'};
        d[7] = {'p','q','r','s'};
        d[8] = {'t','u','v'};
        d[9] = {'w','x','y','z'};
        string curr;
        vector<string> ans;
        dfs(digits, d, 0, curr, ans);
        return ans;
    }
private:
    void dfs(string& digits, vector<vector<char>>& d, int index, string& curr, vector<string>& ans){
        if(index == digits.size()){
            ans.push_back(curr);
            return;
        }

        for(char c: d[digits[index] - '0']){
            curr.push_back(c);
            dfs(digits, d, index + 1, curr, ans);
            curr.pop_back();
        }
    }
};