#include "../common/common.h"
/**
 * @brief 887. 鸡蛋掉落
 * https://leetcode.cn/problems/super-egg-drop/
 * 
 * 设(i, j) i个鸡蛋测试j次最多可以测试的楼数
 * 选x楼测试 + 1
   1. 碎了，剩下(i - 1, j - 1)
   2. 没碎，剩下(i, j - 1)
 * 
 * @param k 
 * @param n 
 * @return int 
 */
int superEggDrop(int k, int n);
int main(){
    cout << superEggDrop(100, 10000) << endl;
    return EXIT_SUCCESS;
}
int superEggDrop(int k, int n) {
    // (i, j) i个鸡蛋测试j次最多可以测试的楼数
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < k; ++ i){
        for (int j = 1; j <= n; ++ j){
            // 选x楼测试 + 1
            // 1. 碎了，剩下dp[i - 1][j - 1]
            // 2. 没碎，剩下dp[i][j - 1]
            if (dp[i - 1][j - 1] > n || dp[i][j - 1] > n){
                continue;
            }
            dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] + 1;
        }
    }
    // 当用k个鸡蛋
    for (int j = 1; j <= n; ++ j){
        dp[k][j] = dp[k - 1][j - 1] + dp[k][j - 1] + 1;
        if (dp[k][j] >= n){
            return j;
        }
    }
    return n;
}