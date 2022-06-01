#define PATH 1
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 122. 买卖股票的最佳时机 II
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
 * 
 * 动态规划: i之前，多次买入卖出
 * 
 * 当前是持有股票的now_y
 * 1. 是之前买的股票: pre_y
 * 2. 之前没有持有，现在买的: pre_n - prices[i]
 * 当前是不持有股票的now_n
 * 1. 之前持有股票，现在卖出: pre_y + prices[i]
 * 2. 之前就没有持有股票: pre_n
 * 
 * @param prices 
 * @return int 
 */
int maxProfit(vector<int>& prices);
int main(){
    vector<vector<int>> prices = {
        {7,1,5,3,6,4},
        {1,2,3,4,5},
        {7,6,4,3,1}
    };
    int n = prices.size();
    for (int i = 0; i < n; ++ i){
        cout << maxProfit(prices[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int pre_y = -prices[0], pre_n = 0, now_y, now_n;
    for (int i = 1; i < n; ++ i){
        now_n = max(pre_n, pre_y + prices[i]);
        now_y = max(pre_y, pre_n - prices[i]);
        pre_y = now_y;
        pre_n = now_n; 
    }
    return pre_n;
}