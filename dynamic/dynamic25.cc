#include "..//common//common.h"
/**
 * @brief 714. 买卖股票的最佳时机含手续费
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 * 
 * 在卖出时，收手续费
 * @param prices 
 * @param fee 
 * @return int 
 */
int maxProfit(vector<int>& prices, int fee);
int main(){
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    cout << maxProfit(prices, 2) << endl;
    return EXIT_SUCCESS;
}
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size(), pre1 = - prices[0], pre0 = 0, now0, now1;
    for (int i = 1; i < n; ++ i){
        now0 = max(pre0, pre1 + prices[i] - fee);
        now1 = max(pre1, now0 - prices[i]);
        pre0 = now0;
        pre1 = now1;
    }
    return pre0;
}