//https://leetcode.com/problems/word-ladder/
#include <vector>
#include <string>
#include <set>
#include <queue>
using std::queue;
using std::string;
using std::vector;
using std::set;

// https://zxi.mytechroad.com/blog/searching/127-word-ladder/
// BFS with queue
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
                    // skip the same word
                    if(cc == c)
                        continue;
                    s[i] = cc;
                    // Found the solution
                    if(s == endWord)
                        return ans;
                    // Not in dict, skip it
                    if(!tfsWord.count(s))
                        continue;
                    // Add new word into queue
                    q.push(s);
                    // Remove new word from dict
                    tfsWord.erase(s);
                }
                s[i] = c;
            }
        }
    }
    return 0;
}
