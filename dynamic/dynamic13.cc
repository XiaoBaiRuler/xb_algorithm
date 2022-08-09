#include "..//common//common.h"
/**
 * @brief 256. 粉刷房子
 * https://leetcode.cn/problems/paint-house/
 * 
 * 1. 当前红，那么之前就是蓝绿最小
 * 2. 当前蓝，那么之前就是红绿最小
 * 3. 当前绿，那么之前就是红蓝最小
 * 如此类推
 * @param costs 
 * @return int 
 */
int minCost(vector<vector<int>>& costs);
int main(){
    vector<vector<int>> costs = {
        {17,2,17},{16,16,5},{14,3,19}
    };
    cout << minCost(costs) << endl;
    return EXIT_SUCCESS;
}
int minCost(vector<vector<int>>& costs) {
    int n = costs.size();
    for (int j = 1; j < n; ++ j){
        costs[j][0] += min(costs[j - 1][1], costs[j - 1][2]);
        costs[j][1] += min(costs[j - 1][0], costs[j - 1][2]);
        costs[j][2] += min(costs[j - 1][0], costs[j - 1][1]);
    }
    n -= 1;
    return min(min(costs[n][0], costs[n][1]), costs[n][2]);
}