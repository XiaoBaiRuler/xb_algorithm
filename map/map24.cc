#include "../common/common.h"
/**
 * @brief 130. 被围绕的区域
 * https://leetcode.cn/problems/surrounded-regions/
 * 
 * 倒过来思考
 */
vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; ++ i){
            if (board[i][0] == 'O'){
                dfs(i, 0, board);
            }
            if (board[i][m - 1] == 'O'){
                dfs(i, m - 1, board);
            }
        }
        for (int j = 0; j < m; ++ j){
            if (board[0][j] == 'O'){
                dfs(0, j, board);
            }
            if (board[n - 1][j] == 'O'){
                dfs(n - 1, j, board);
            }
        }
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                if (board[i][j] == 'Y'){
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
protected:
    void dfs(int i, int j, vector<vector<char>>& board){
        board[i][j] = 'Y';
        for (auto& d : dir){
            int x = i + d[0];
            int y = j + d[1];
            if (x < 0 || y < 0 || x >= n || y >= m || board[x][y] != 'O'){
                continue;
            }
            dfs(x, y, board);
        }
    }
private:
    int n, m;
};
int main(){
    vector<vector<char>> res = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'}};
    Solution().solve(res);
    for (auto& r : res){
        cout << r << endl;
    } 
    return EXIT_SUCCESS;
}