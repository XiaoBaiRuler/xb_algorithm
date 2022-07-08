#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 221. 最大正方形
 * https://leetcode.cn/problems/maximal-square/
 * 
 * 矩阵类型(i, j): 设以(i, j)为右下角可以构造的正方形的最大边长
 * 那么当前的最大边长，取决于当前是不是为'1'
 * 1. ='0' => 0
 * 2. ='1' => 取决于(i, j - 1)(i - 1, j)(i - 1, j - 1)的最小值
 * 
 * => 所有的值的最大值就是最大正方形的边长
 * @param matrix 
 * @return int 
 */
int maximalSquare(vector<vector<char>>& matrix);
int main(){
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };
    cout << maximalSquare(matrix) << endl;
    return EXIT_SUCCESS;
}
int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int res = 0;
    for (int i = 0; i < n; ++ i){
        if (matrix[i][0] == '1'){
            dp[i][0] = 1;
            res = 1;
        }
    }
    for (int j = 1; j < m; ++ j){
        if (matrix[0][j] == '1'){
            dp[0][j] = 1;
            res = 1;
        }
    }
    for (int i = 1; i < n; ++ i){
        for (int j = 1; j < m; ++ j){
            if (matrix[i][j] == '1'){
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                res = max(dp[i][j], res);
            }
        }
    }
    return res * res;
}