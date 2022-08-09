#include "..//common//common.h"
/**
 * @brief 剑指 Offer II 091. 粉刷房子
 * https://leetcode.cn/problems/JEj789/
 * 
 * 1. 当前选红
 * - 之前就是绿蓝中最小的
 * 2. 当前选蓝
 * - 之前就是红绿中最小的
 * 3. 当前选绿
 * - 之前就是红蓝中最小的
 * @param costs 
 * @return int 
 */
int minCost(vector<vector<int>>& costs);
int main(){
    vector<vector<int>> costs = {
        {17,2,17},
        {16,16,5},
        {14,3,19}
    };
    cout << minCost(costs) << endl;
    return EXIT_SUCCESS;
}
int minCost(vector<vector<int>>& costs) {
    int n = costs.size();
    for (int i = 1; i < n; ++ i){
        costs[i][0] = min(costs[i - 1][1], costs[i - 1][2]) + costs[i][0];
        costs[i][1] = min(costs[i - 1][0], costs[i - 1][2]) + costs[i][1]; 
        costs[i][2] = min(costs[i - 1][0], costs[i - 1][1]) + costs[i][2]; 
    }
    return min(min(costs[n - 1][0], costs[n - 1][1]), costs[n - 1][2]);
}