// https://leetcode.com/problems/n-queens/

#include <vector>
#include <string>
using std::string;
using std::vector;

// one row by one row
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        n_ = n;
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solveNQUtil(board, 0, ans);

        return ans;
    }
private:
    int n_;
    bool isSafe(vector<string>& board, int row, int col){
        // check column
        for(int i = row - 1; i >= 0; --i)
            if(board[i][col] == 'Q')
                return false;

        // check upper right
        for(int i = row - 1, j = col + 1; i >= 0 && j < n_; --i, ++j)
            if(board[i][j] == 'Q')
                return false;

        // check upper left
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if(board[i][j] == 'Q')
                return false;

        return true;
    }

    void solveNQUtil(vector<string>& board, int row, vector<vector<string>>& ans){
        // base case: If all queens are placed
        // then return
        if(row == board.size()){
            ans.push_back(board);
            return;
        }

        // Consider this row and try placing
        // this queen in every column one by one
        for(int j = 0; j < board.size(); ++j)
            if(isSafe(board, row, j)){
                // Place this queen in board[row][j]
                board[row][j] = 'Q';
                // recur to place rest of the queens
                solveNQUtil(board, row+1, ans);
                board[row][j] = '.';
            }

    }
};