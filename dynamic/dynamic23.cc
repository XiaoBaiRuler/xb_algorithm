#include "..//common//common.h"
/**
 * @brief 188. 买卖股票的最佳时机 IV
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/
 * 
 * III的 两次交易 -> 扩展到k 次交易
 * @param k 
 * @param prices 
 * @return int 
 */
int maxProfit(int k, vector<int>& prices);
int main(){
    vector<int> prices = {3,2,6,5,0,3};
    cout << maxProfit(2, prices) << endl;
    return EXIT_SUCCESS;
}
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (n == 0 || k == 0){
        return 0;
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k, vector<int>(2)));
    dp[0][0][0] = 0;
    dp[0][0][1] = - prices[0];
    for (int i = 1; i < n; ++ i){
        dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][0][1] + prices[i]);
        dp[i][0][1] = max(dp[i - 1][0][1], - prices[i]);
    }
    for (int j = 1; j < k; ++ j){
        dp[0][j][0] = 0;
        dp[0][j][1] = - prices[0];
        for (int i = 1; i < n; ++ i){
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
        }
    }
    return dp[n - 1][k - 1][0];
}