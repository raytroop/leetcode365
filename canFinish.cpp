// https://leetcode.com/problems/course-schedule/

// http://zxi.mytechroad.com/blog/graph/leetcode-207-course-schedule/
#include <vector>
#include <utility>
using std::vector;
using std::pair;

// Topological Sort
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // states: 0 = unkonwn, 1 == visiting, 2 = visited
        vector<int> states(numCourses, 0);

        vector<vector<int>> graph(numCourses);
        for(const auto& p: prerequisites)
            graph[p.first].push_back(p.second);

        for(int i = 0; i < numCourses; ++i)
            if(dfs(i, states, graph))
                return false;

        return true;
    }
private:
    // if circule, return true
    bool dfs(int idx, vector<int>& states, vector<vector<int>>& graph){
        if(states[idx] == 1)
            return true;
        if(states[idx] == 2)
            return false;

        states[idx] = 1;
        for(const int t : graph[idx])
            if(dfs(t, states, graph))
                return true;
        states[idx] = 2;

        return false;
    }
};