// https://leetcode.com/problems/01-matrix/

/* Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right. */

#include <vector>
#include <algorithm>
#include <climits>
using std::vector;

// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-542-01-matrix/
// DP
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix){
    if(matrix.empty())
        return {};
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<vector<int>> ans(m, vector<int>(n, INT_MAX - m * n)); // `INT_MAX - m*n` avoid overflow
    // down, right
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            if(matrix[i][j]){
                if(i > 0)
                    ans[i][j] = ans[i-1][j] + 1;
                if(j > 0)
                    ans[i][j] = std::min(ans[i][j], ans[i][j-1] + 1);
            }
            else
                ans[i][j] = 0;

    // up, left
    for(int i = m - 1; i >= 0; --i)
        for(int j = n - 1; j >= 0; --j)
            if(matrix[i][j]){
                if(i < m - 1)
                    ans[i][j] = std::min(ans[i+1][j] + 1, ans[i][j]);
                if(j < n - 1)
                    ans[i][j] = std::min(ans[i][j+1] + 1, ans[i][j]);
            }

    return ans;
}

// BFS Start from all 0 cells and find shortest paths to rest of the cells.
#include <queue>
#include <utility>
using std::pair;
using std:: queue;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return {};
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<vector<int>> seen(m, vector<int>(n, 0));
        vector<vector<int>> ans(m, vector<int>(n));
        queue<pair<int, int>> q;
        // collect all 0 cells
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(matrix[i][j] == 0){
                    seen[i][j] = 1;
                    q.push({i, j});
                }

        // find shortest paths to rest cells from seen cells
        int steps = 0;
        vector<int> dirs{0, -1, 0, 1, 0};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                ans[i][j] = steps;
                for(int k = 0; k < 4; ++k){
                    int ik = i + dirs[k];
                    int jk = j + dirs[k+1];
                    if(ik < 0 || ik >= m || jk < 0 || jk >= n || seen[ik][jk])
                        continue;
                    seen[ik][jk] = 1;
                    q.push({ik, jk});
                }
            }
            ++steps;
        }
    return ans;
    }
};