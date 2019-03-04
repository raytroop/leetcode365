//https://leetcode.com/problems/search-a-2d-matrix/


#include <vector>
using std::vector;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.empty())
        return false;

    const int m = matrix.size();
    const int n = matrix[0].size();
    int i = 0;
    int j = n - 1;
    while(i < m && j >= 0){
        int curr = matrix[i][j];
        if(curr == target)
            return true;
        else if(curr < target)
            ++i;
        else
            --j;
    }

    return false;
}
