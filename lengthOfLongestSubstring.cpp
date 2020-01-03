// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <string>
#include <unordered_map>
#include <algorithm>
using std::string;
using std::unordered_map;

// https://zxi.mytechroad.com/blog/string/leetcode-3-longest-substring-without-repeating-characters/
int lengthOfLongestSubstring(string s) {
    const int n = s.length();
    unordered_map<char, int> dict;
    int start = 0;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(dict.count(s[i]) && dict[s[i]] >= start)
            start = dict[s[i]] + 1;
        ans = std::max(ans, i - start + 1);
        dict[s[i]] = i;
    }

    return ans;
}