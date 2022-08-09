#include "..//common//common.h"
/**
 * @brief 85. 最大矩形
 * https://leetcode.cn/problems/maximal-rectangle/
 * 
 * 1. 可以利用最大正方形来决定最大矩形的最小边k: 那么一条边长的长度可能为[1, k]
 * 2. 可以利用从左往右的最大前序或从上往下的最大前序和来决定另外一条边的长度
 * 3. 分别枚举两条边(获取最大矩形) 注意要剪枝
 * 
 * 
 * @param matrix 
 * @return int 
 */
int maximalRectangle(vector<vector<char>>& matrix);
int main(){
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };
    cout << maximalRectangle(matrix) << endl;
    return EXIT_SUCCESS;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3)));
    dp[0][0][0] = matrix[0][0] == '1' ? 1 : 0;
    dp[0][0][1] = dp[0][0][0];
    dp[0][0][2] = dp[0][0][0];
    int res = dp[0][0][0];
    for (int i = 1; i < n; ++ i){
        if (matrix[i][0] == '1'){
            dp[i][0][0] = 1;
            dp[i][0][1] = dp[i - 1][0][1] + 1;
            dp[i][0][2] = 1;
        }
        else{
            dp[i][0][0] = 0;
            dp[i][0][1] = 0;
            dp[i][0][2] = 0;
        }
        res = max(dp[i][0][1], res); 
    }
    for (int j = 1; j < m; ++ j){
        if (matrix[0][j] == '1'){
            dp[0][j][0] = 1;
            dp[0][j][1] = 1;
            dp[0][j][2] = dp[0][j - 1][2] + 1;
        }
        else{
            dp[0][j][0] = 0;
            dp[0][j][1] = 0;
            dp[0][j][2] = 0; 
        }
        res = max(dp[0][j][2], res); 
    }
    for (int i = 1; i < n; ++ i){
        for (int j = 1; j < m; ++ j){
            if (matrix[i][j] == '1'){
                dp[i][j][0] = min(min(dp[i - 1][j][0], dp[i - 1][j - 1][0]), dp[i][j - 1][0]) + 1;
                dp[i][j][1] = dp[i - 1][j][1] + 1;
                dp[i][j][2] = dp[i][j - 1][2] + 1;
                for (int k = dp[i][j][0]; k > 0; -- k){
                    int w = dp[i][j][2];
                    for (int l = i - 1, e = i - k; l > e; -- l){
                        w = min(w, dp[l][j][2]);
                    }
                    res = max(w * k, res);
                    int h = dp[i][j][1];
                    for (int l = j - 1, e = j - k; l > e; -- l){
                        h = min(h, dp[i][l][1]);
                    }
                    res = max(h * k, res);
                    // 剪枝条
                    if (res >= (i + 1) * (j + 1)){
                        break;
                    }
                }
            }
            else{
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
                dp[i][j][2] = 0;
            }
        }
    }
    return res;
}