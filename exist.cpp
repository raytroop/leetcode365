// https://leetcode.com/problems/word-search/

#include <vector>
#include <string>
using std::string;
using std::vector;


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty())
            return false;
        rows_ = board.size();
        cols_ = board[0].size();
        vector<vector<bool>> viewed(rows_, vector<bool>(cols_, false));
        for(int i = 0; i < rows_; ++i)
            for(int j = 0; j < cols_; ++j){
                viewed[i][j] = true;
                if(exist(board, viewed, word, 0, i, j))
                    return true;
                viewed[i][j] = false;
            }

        return false;
    }
private:
    int rows_;
    int cols_;
    vector<int> dirs{0, 1, 0, -1, 0};
    bool exist(vector<vector<char>>& board, vector<vector<bool>>& viewed, string& word, int index, int r, int c){
        if(board[r][c] != word[index])
            return false;
        if(index == word.length() - 1)
            return true;

        for(int i = 0; i < 4; ++i){
            int newI = dirs[i] + r;
            int newJ = dirs[i+1] + c;
            if(newI >= rows_ || newI < 0 || newJ >= cols_ || newJ < 0 || viewed[newI][newJ])
                continue;
            viewed[newI][newJ] = true;
            if(exist(board, viewed, word, index+1, newI, newJ))
                return true;
            viewed[newI][newJ] = false;
        }

        return false;
    }
};