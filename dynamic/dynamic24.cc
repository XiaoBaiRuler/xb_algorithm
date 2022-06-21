#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 309. 最佳买卖股票时机含冷冻期
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 * 
 * 当前持有
 * 1. 上一次持有
 * 2. 上两次不持有，现在买入
 * 当前不持有
 * 1. 上一次不持有
 * 2. 上一次持有，现在卖出
 * 
 * @param prices 
 * @return int 
 */
int maxProfit(vector<int>& prices);
/**
 * @brief 
 * 
 * 滚动数组减少空间复杂度
 * 
 * @param prices 
 * @return int 
 */
int maxProfitChange(vector<int>& prices);
int main(){
    vector<vector<int>> prices = {
        {1,2,3,0,2},
        {1}
    };
    for (int i = 0, n = prices.size(); i < n; ++ i){
        cout << maxProfit(prices[i]) << " ";
        cout << maxProfitChange(prices[i]) << " ";
    }
    cout << endl;
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 1){
        return 0;
    }
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
    dp[1][1] = max(dp[0][1], -prices[1]);
    for (int i = 2; i < n; ++ i){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
    }
    return dp[n - 1][0];
}
int maxProfitChange(vector<int>& prices) {
    int n = prices.size();
    if (n == 1){
        return 0;
    }
    int pre0 = max(0, -prices[0] + prices[1]), pre1 = max(-prices[0], -prices[1]), prepre0 = 0;
    int now0, now1;
    for (int i = 2; i < n; ++ i){
        now0 = max(pre0, pre1 + prices[i]);
        now1 = max(pre1, prepre0 - prices[i]);
        prepre0 = pre0;
        pre0 = now0;
        pre1 = now1;
    }
    return pre0;
}