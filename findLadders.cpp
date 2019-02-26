//https://leetcode.com/problems/word-ladder-ii/

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using std::queue;
using std::vector;
using std::string;
using std::unordered_set;
using std::unordered_map;

//http://zxi.mytechroad.com/blog/searching/leetcode-126-word-ladder-ii/
class Solution {
public:
    // BFS
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        beginWord_ = beginWord;
        endWord_ = endWord;

        unordered_set<string> tfmsWords(wordList.begin(), wordList.end());
        if(!tfmsWords.count(endWord))
            return {};
        const int l = beginWord.length();

        tfmsWords.erase(beginWord);
        unordered_map<string, vector<string>> parents;
        queue<string> q; q.push(beginWord);
        bool found = false;

        while(!q.empty() && !found){
            unordered_set<string> viewed;
            for(int sz = q.size(); sz > 0; --sz){
                const string s = q.front(); q.pop();
                string ss = s;
                for(int i = 0; i < l; ++i){
                    const char c = s[i];
                    for(char cc = 'a'; cc <= 'z'; ++cc){
                        if(cc == c)
                            continue;
                        ss[i] = cc;
                        if(ss == endWord)
                            found = true;
                        if(!tfmsWords.count(ss))
                            continue;

                        parents[ss].push_back(s);
                        viewed.insert(ss);
                    }
                    ss[i] = c;
                }
            }
            for(const auto& x: viewed){
                tfmsWords.erase(x);
                q.push(x);
            }
        }

        vector<vector<string>> ans;
        if(found){
            vector<string> curr{endWord};
            getPaths(endWord, curr, parents, ans);
        }

        return ans;
    }
private:
    //  DFS
    string beginWord_;
    string endWord_;
    void getPaths(const string& word, vector<string>& curr, const unordered_map<string, vector<string>>& parents, vector<vector<string>>& ans){
        if(word == beginWord_){
            ans.push_back(vector<string>(curr.rbegin(), curr.rend()));
            return;
        }

        for(const auto& w: parents.at(word)){
            curr.push_back(w);
            getPaths(w, curr, parents, ans);
            curr.pop_back();
        }
    }
};