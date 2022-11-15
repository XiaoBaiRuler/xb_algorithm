#include "../common/common.h"
/**
 * @brief 37. 解数独
 * https://leetcode.cn/problems/sudoku-solver/
 * 
 * dfs
 */
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // 行
        row = vector<vector<bool>>(9, vector<bool>(10, false));
        // 列
        col = vector<vector<bool>>(9, vector<bool>(10, false));
        // 块
        block = vector<vector<bool>>(9, vector<bool>(10, false));

        for (int i = 0; i < 9; ++ i){
            for (int j = 0; j < 9; ++ j){
                if (board[i][j] != '.'){
                    int tmp = board[i][j] - '0';
                    row[i][tmp] = true;
                    col[j][tmp] = true;
                    block[i / 3 * 3 + j / 3][tmp] = true;
                }
            }
        }
        dfs(board, 0, 0);
    }
protected:
    bool dfs(vector<vector<char>>& board, int i, int j){
        for (; i < 9; ++ i){
            for (; j < 9; ++ j){
                if (board[i][j] == '.'){
                    break;
                }
            }
            if (j != 9){
                break;
            }
            j = 0;
        }
        if (i == 9){
            return true;
        }
        for (int c = 1; c < 10; ++ c){
            int in = i / 3 * 3 + j / 3;
            if (row[i][c] || col[j][c] || block[in][c]){
                continue;
            }
            board[i][j] = static_cast<char>(c + '0');
            row[i][c] = true;
            col[j][c] = true;
            block[in][c] = true;
            if (dfs(board, i, j)){
                return true;
            }
            else{
                board[i][j] = '.';
                row[i][c] = false;
                col[j][c] = false;
                block[in][c] = false;
            }
        }
        return false;
    }
private:
    vector<vector<bool>> row, col, block;
};
int main(){
    vector<vector<char>> nums = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution().solveSudoku(nums);
    for (auto& n : nums){
        cout << n << endl;
    }
    return EXIT_SUCCESS;
}