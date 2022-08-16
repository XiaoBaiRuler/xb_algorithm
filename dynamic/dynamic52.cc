#include "../common/common.h"
/**
 * @brief 1039. 多边形三角剖分的最低得分
 * https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/
 * 
 * 区间动态规划: 设(l, r)为获得的最低分值
 * 1. 由三角形 -> 多边形 确定边数c
 *      1. l 最左点: [0, n - c)
 *      2. r 最右点: l + c
 *      3. 中间的点: [l + 1, r)
 * => (l, r) = min((l, r), (l, k) + (k + r) + l * r * k)
 * @param values 
 * @return int 
 */
int minScoreTriangulation(vector<int>& values);
int main(){
    vector<int> values = {3, 7, 4, 5};
    cout << minScoreTriangulation(values) << endl;
    return EXIT_SUCCESS;
}
int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int c = 2; c < n; ++ c){
        for (int l = 0; l < n - c; ++ l){
            int r = l + c;
            dp[l][r] = INT_MAX;
            for (int k = l + 1; k < r; ++ k){
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + values[l] * values[k] * values[r]);
            }
        }
    }
    return dp[0][n - 1];
}