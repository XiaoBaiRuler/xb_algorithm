#include "../common/common.h"
/**
 * @brief 529. 扫雷游戏
 * https://leetcode.cn/problems/minesweeper/
 */
vector<vector<int>> dir = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        n = board.size();
        m = board[0].size();
        int i = click[0];
        int j = click[1];
        // 1. 刚好点到雷M
        if (board[i][j] == 'M'){
            board[i][j] = 'X';
            return board;
        }
        number = vector<vector<int>>(n, vector<int>(m, 0));
        // 2. 刚好点到未知空白E
        if (board[i][j] == 'E'){
            getNumber(board);
            if (number[i][j] != 0){
                board[i][j] = static_cast<int>(number[i][j] + '0');
            }
            else{
                board[i][j] = 'B';
                dfs(i, j, board);
            }
            return board;
        }
        return board;
    }
protected:
    void getNumber(vector<vector<char>>& board){
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                if (board[i][j] == 'M'){
                    for (auto& d : dir){
                        int x = d[0] + i;
                        int y = d[1] + j;
                        if (x < 0 || y < 0 || x >= n || y >= m){
                            continue;
                        }
                        number[x][y] += 1; 
                    }     
                }
            }
        }
    }
    void dfs(int i, int j, vector<vector<char>>& board){
        int ans = 0;
        for (auto& d : dir){
            int x = i + d[0];
            int y = j + d[1];
            if (x < 0 || y < 0 || x >= n || y >= m){
                continue;
            }
            if (board[x][y] == 'E'){
                if (number[x][y] != 0){
                    board[x][y] = static_cast<int>(number[x][y] + '0');
                }
                else{
                    board[x][y] = 'B';
                    dfs(x, y, board);
                }
            }
        }
    }
private:
    int n, m;
    vector<vector<int>> number;
};
int main(){
    vector<vector<char>> board = {
        {'E','E','E','E','E'},{'E','E','M','E','E'},{'E','E','E','E','E'},{'E','E','E','E','E'}
    };
    vector<int> click = {3, 0};
    Solution().updateBoard(board, click);
    for (auto& b : board){
        cout << b << endl;
    }
    return EXIT_SUCCESS;
}