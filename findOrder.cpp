//https://leetcode.com/problems/course-schedule-ii/

#include <vector>
using std::vector;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        status_ = vector<int>(numCourses, 0);
        graph_ = vector<vector<int>>(numCourses);
        for (auto p: prerequisites)
            graph_[p[0]].push_back(p[1]);

        vector<int> ans;
        for (int i = 0; i < numCourses; ++i)
            if (dfs(i, ans)) return {};

        return ans;
    }

private:
    vector<int> status_;
    vector<vector<int>> graph_;
    // circle -> true
    bool dfs(int index, vector<int>& ans) {
        if (status_[index] == 1) return true;
        if (status_[index] == 2) return false;

        status_[index] = 1;
        for (int idx: graph_[index])
            if (dfs(idx, ans)) return true;

        status_[index] = 2;
        ans.push_back(index);

        return false;
    }
};