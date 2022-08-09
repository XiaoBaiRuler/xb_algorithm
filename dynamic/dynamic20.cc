#include "..//common//common.h"
/**
 * @brief 121. 买卖股票的最佳时机
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
 * 
 * 天数 交易次数1 持有状态
 * 动态规划的方法:
 * 1. 持有: 前天就持有或者今天再买入
 * 2. 不持有: 前天也没持有或者今天持有再卖出
 * 
 * @param prices 
 * @return int 
 */
int maxProfit(vector<int>& prices);
/**
 * @brief 
 * 滚动代替数组，空间减少为O(1)
 * 
 * @param prices 
 * @return int 
 */
int maxProfitChange(vector<int>& prices);
int main(){
    vector<vector<int>> prices = {
        {7,1,5,3,6,4},
        {7,6,4,3,1}
    };
    int n = prices.size();
    for (int i = 0; i < n; ++ i){
        cout << maxProfit(prices[i]) << " ";
        cout << maxProfitChange(prices[i]) << " ";
    }
    return EXIT_SUCCESS;
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][1] = -prices[0];
    dp[0][0] = 0;
    for (int i = 1; i < n; ++ i){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], - prices[i]);
    }
    return dp[n - 1][0];
}
int maxProfitChange(vector<int>& prices) {
    int n = prices.size();
    int prey = -prices[0], pren = 0, nowy, nown; 
    for (int i = 1; i < n; ++ i){
        nown = max(pren, prey + prices[i]);
        nowy = max(prey, - prices[i]);
        prey = nowy;
        pren = nown;
    }
    return pren;
}