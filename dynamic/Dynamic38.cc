#include "..//common//common.h"
/**
 * @brief 174. 地下城游戏
 * https://leetcode.cn/problems/dungeon-game/submissions/
 * 
 * 1. 从(0, 0) -> (n - 1, m - 1), 但是终点的状态会影响前面的路径
 * 
 * 2. 从(n - 1, m - 1) -> (0, 0), 起始最低血量为1, 那么(i, j)的状态就是勇者从该位置开始所需的最低血量:
 * 那么(i, j) = max(1, min((i - 1)(j), (i, j - 1)) - [i, j])
 * @param dungeon 
 * @return int 
 */
int calculateMinimumHP(vector<vector<int>>& dungeon);
int main(){
    vector<vector<int>> dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    cout << calculateMinimumHP(dungeon) << endl;
    return EXIT_SUCCESS;
}
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int n = dungeon.size(), m = dungeon[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; ++ i){
        dp[i][m] = INT_MAX;
    }
    for (int j = 0; j <= m; ++ j){
        dp[n][j] = INT_MAX;
    }
    dp[n - 1][m] = 1;
    dp[n][m - 1] = 1;
    for (int i = n - 1; i > -1; -- i){
        for (int j = m - 1; j > -1; -- j){
            dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
        }
    }
    return dp[0][0];
}