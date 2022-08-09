#include "..//common//common.h"
/**
 * @brief 931. 下降路径最小和
 * https://leetcode.cn/problems/minimum-falling-path-sum/
 * 
 * 矩阵类型(i, j): 到达i, j位置的最小值 
 * 注意边界条件i = 0, j = 0, j = n - 1
 * 
 * (i, j) = (i - 1, j - 1), (i - 1, j), (i - 1, j + 1) 的最小值 + [i][j] 
 * 
 * @param matrix 
 * @return int 
 */
int minFallingPathSum(vector<vector<int>>& matrix);
int main(){
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    cout << minFallingPathSum(matrix) << endl;
    return EXIT_SUCCESS;
}
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = matrix[0][0];
    for (int j = 1; j < n; ++ j){
        dp[0][j] = matrix[0][j];
    }
    for (int i = 1, e = n - 1; i < n; ++ i){
        dp[i][0] = (1 < n ? min(dp[i - 1][0], dp[i - 1][1]) : dp[i - 1][0]) + + matrix[i][0];
        for (int j = 1; j < e; ++ j){
            dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + matrix[i][j];
        }
        dp[i][e] = min(dp[i - 1][e - 1], dp[i - 1][e]) + matrix[i][e];
    }
    int mi = dp[n - 1][0];
    for (int i = 1; i < n; ++ i){
        mi = min(dp[n - 1][i], mi); 
    }
    return mi;
}