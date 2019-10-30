// https://leetcode.com/problems/word-break/

// http://zxi.mytechroad.com/blog/leetcode/leetcode-139-word-break/

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using std::string;
using std::vector;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        mem_.clear();
        dict_.clear();
        dict_.insert(wordDict.begin(), wordDict.end());

        return wordBreak(s);
    }

private:
    bool wordBreak(string& s) {
        if (dict_.count(s)) return true;
        if (mem_.count(s)) return mem_[s];

        for (int i = 1; i < s.size(); ++i) {
            string left = s.substr(0, i);
            string right = s.substr(i);

            if (wordBreak(left) && (mem_[right] || dict_.count(right)))
                return mem_[s] = true;
        }

        return mem_[s] = false;
    }
private:
    std::unordered_map<string, bool> mem_;
    std::unordered_set<string> dict_;
};