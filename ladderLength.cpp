//https://leetcode.com/problems/word-ladder/
#include <vector>
#include <string>
#include <set>
#include <queue>
using std::queue;
using std::string;
using std::vector;
using std::set;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    const int n = beginWord.length();
    set<string> tfsWord(wordList.begin(), wordList.end());
    if(!tfsWord.count(endWord))
        return 0;
    queue<string> q;
    q.push(beginWord);

    int ans = 1;
    while(!q.empty()){
        ++ans;
        int sz = q.size();
        while(sz--){
            string s = q.front();
            q.pop();
            for(int i = 0; i < n; ++i){
                const char c = s[i];
                for(int cc = 'a'; cc <= 'z'; ++cc){
                    if(cc == c)
                        continue;
                    s[i] = cc;
                    if(s == endWord)
                        return ans;
                    if(!tfsWord.count(s))
                        continue;
                    tfsWord.erase(s);
                    q.push(s);
                }
                s[i] = c;
            }
        }
    }
    return 0;
}