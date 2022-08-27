#include "../common/common.h"
/**
 * @brief 1478. 安排邮筒
 * https://leetcode.cn/problems/allocate-mailboxes/
 * 
 * 设{l, r}为l - r 共用1个邮箱时的距离和
 * - 邮箱两点的最短距离就是两点之间的线段
 * 
 * 设(i, j)前j个房子使用i个邮箱的最短距离
 * 最后一个邮箱的放置位置可以为t [1 j]
 * (i, j) = min((i, j), (i - 1, t - 1) + {t, j})
 * 
 * @param houses 
 * @param k 
 * @return int 
 */
int minDistance(vector<int>& houses, int k);
int main(){
    vector<int> houses = {5,18,25,27,28,13,9,12,22};
    cout << minDistance(houses, 7) << endl;
    return EXIT_SUCCESS;
}
int minDistance(vector<int>& houses, int k) {
    int n = houses.size();
    if (n == k){
        return 0;
    }
    sort(houses.begin(), houses.end());
    // l - r 共用1个邮箱时的距离和
    vector<vector<int>> pre(n, vector<int>(n));
    for (int l = 0; l < n; ++ l){
        pre[l][l] = 0; 
        for (int r = l + 1; r < n; ++ r){
            int ll = l, rr = r;
            while (ll <= rr){
                pre[l][r] += houses[rr] - houses[ll];
                -- rr;
                ++ ll; 
            } 
        }
    }
    // 前j个房子使用i个邮箱的最短距离
    vector<vector<int>> dp(k, vector<int>(n));
    for (int j = 0; j < n; ++ j){
        dp[0][j] = pre[0][j];
    }
    for (int i = 1; i < k; ++ i){
        dp[i][0] = 0;
        for (int j = 1; j < n; ++ j){
            dp[i][j] = pre[0][j];
            for (int t = 1; t <= j; ++ t){
                dp[i][j] = min(dp[i][j], dp[i - 1][t - 1] + pre[t][j]);
            }
        }
    }
    return dp[k - 1][n - 1];
}