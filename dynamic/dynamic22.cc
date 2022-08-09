#include "..//common//common.h"
/**
 * @brief 123. 买卖股票的最佳时机 III
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/submissions/
 * 
 * 限定最多两次交易
 * 1. 当第一次交易
 * 1.1 不持有: 之前不持有；之前持有但是卖出了
 * 1.2 持有: 之前持有；之前不持有但是买入
 * 2. 当第二次交易
 * 2.1 不持有: 之前不持有；之前持有但是卖出了
 * 2.2 持有: 之前持有；上一次交易完成之后(不持有) 现在买入
 * 
 * @param prices 
 * @return int 
 */
int maxProfit(vector<int>& prices);
/**
 * @brief 滚动空间，节省内存
 * 
 * @param prices 
 * @return int 
 */
int maxProfitChange(vector<int>& prices);
int main(){
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << maxProfit(prices) << " ";
    cout << maxProfitChange(prices) << " ";
    return EXIT_SUCCESS;
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2)));
    dp[0][0][0] = 0;
    dp[0][0][1] = -prices[0];
    dp[0][1][0] = 0;
    dp[0][1][1] = -prices[0];
    for (int i = 1; i < n; ++ i){
        dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][0][1] + prices[i]);
        dp[i][0][1] = max(dp[i - 1][0][1], - prices[i]);
        dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i]);
        dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][0] - prices[i]);
    }
    return max(dp[n - 1][0][0], dp[n - 1][1][0]);
}
int maxProfitChange(vector<int>& prices) {
    int n = prices.size();
    int pre0n = 0, pre0y = -prices[0];
    int pre1n = 0, pre1y = -prices[0];
    int now0n, now0y, now1n, now1y;
    for (int i = 1; i < n; ++ i){
        now0n = max(pre0n, pre0y + prices[i]);
        now0y = max(pre0y, - prices[i]);
        now1n = max(pre1n, pre1y + prices[i]);
        now1y = max(pre1y, pre0n - prices[i]);
        pre0n = now0n;
        pre0y = now0y;
        pre1n = now1n;
        pre1y = now1y;
    }
    return max(pre0n, pre1n);
}