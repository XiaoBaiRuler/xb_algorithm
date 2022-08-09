#include "..//common//common.h"
/**
 * @brief 64. 最小路径和
 * https://leetcode.cn/problems/minimum-path-sum/
 * 
 * 注意边界条件:
 * 当前的位置，只与上面和左面一个位置有关   
 * @param grid 
 * @return int 
 */
int minPathSum(vector<vector<int>>& grid);
int main(){
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << minPathSum(grid) << endl;
    return EXIT_SUCCESS;
}
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; ++ i){
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < m; ++ j){
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (int i = 1; i < n; ++ i){
        for (int j = 1; j < m; ++ j){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[n - 1][m - 1];
}