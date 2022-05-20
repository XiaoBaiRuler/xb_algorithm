#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif

/**
 * @brief 265. 粉刷房子 II
 * https://leetcode.cn/problems/paint-house-ii/
 * 
 * 1. 当前j颜色，那么之前就是非j最小的颜色. [0, k]
 * 如此类推
 * 
 * 时间复杂度: O(nk^2)
 * 空间复杂度: O(1)
 * @param costs 
 * @return int 
 */
int minCostII(vector<vector<int>>& costs);

int main(){
    vector<vector<int>> costs = {
        {1, 5, 3},
        {2, 9, 4}
    };
    cout << minCostII(costs) << endl;
    return EXIT_SUCCESS;
}
int minCostII(vector<vector<int>>& costs) {
    int n = costs.size(), k = costs[0].size();
    for (int i = 1; i < n; ++ i){
        for (int j = 0; j < k; ++ j){
            int temp = INT_MAX;
            for (int l = 0; l < k; ++ l){
                if (l != j){
                    temp = min(temp, costs[i - 1][l]);
                }
            }
            costs[i][j] += temp;
        }
    }
    n -= 1;
    int res = INT_MAX;
    for (int t : costs[n]){
        res = min(t, res);
    }
    return res;
}