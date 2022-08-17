#include "../common/common.h"
/**
 * @brief 1000. 合并石头的最低成本
 * https://leetcode.cn/problems/minimum-cost-to-merge-stones/
 * 
 * 区间动态规划: (l, r, k) 为l 到 r范围内分成k堆所需的最低成本
 * 
 * 范围大小由c 2 - n
 * 堆数大小由t 2 - k
 * rr [l, r)
 * => (l, r, t) = min((l, r, t), (l, rr, 1) + (rr + 1, r, t - 1))
 * 
 * @param stones 
 * @param k 
 * @return int 
 */
int mergeStones(vector<int>& stones, int k);
int main(){
    vector<int> stones = {3,2,4,1};
    cout << mergeStones(stones, 2) << endl;
    return EXIT_SUCCESS;
}
int mergeStones(vector<int>& stones, int k) {
    int n = stones.size();
    if ((n - 1) % (k - 1) != 0){
        return -1;
    }
    vector<int> pre(n + 1);
    pre[0] = 0;
    for (int i = 1; i <= n; ++ i){
        pre[i] = stones[i - 1] + pre[i - 1];
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX / 2)));
    // 本身为一堆所需的成本为0
    for (int i = 0; i < n; ++ i){
        dp[i][i][1] = 0;
    }
    for (int c = 2; c <= n; ++ c){
        for (int l = 0, e = n - c; l <= e; ++ l){
            int r = l + c - 1;
            // 堆数 [2, k]
            for (int t = 2; t <= k; ++ t){
                // rr [l, r)
                for (int rr = l; rr < r; rr += k - 1){
                    dp[l][r][t] = min(dp[l][r][t], dp[l][rr][1] + dp[rr + 1][r][t - 1]);
                }
            }
            dp[l][r][1] = dp[l][r][k] + pre[r + 1] - pre[l];
        }
    }    
    return dp[0][n - 1][1];
}