#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 120. 三角形最小路径和
 * https://leetcode.cn/problems/triangle/
 * 
 * 当前的选择只以前面当前位置和上一个位置有关
 * 
 * @param triangle 
 * @return int 
 */
int minimumTotal(vector<vector<int>>& triangle);
int main(){
    vector<vector<int>> triangle = {
        {2},{3, 4},{5, 6, 7},{4, 1, 8, 3}
    };
    cout << minimumTotal(triangle) << endl;
    return EXIT_SUCCESS;
}
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++ i){
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        for (int j = 1; j < i; ++ j){
            dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        } 
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }
    int mi = INT_MAX;
    for (int i : dp[n - 1]){
        mi = min(i, mi);
    }
    return mi;
}