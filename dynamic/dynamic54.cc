#include "../common/common.h"
/**
 * @brief 486. 预测赢家
 * https://leetcode.cn/problems/predict-the-winner/
 * 
 * 设(l, r, 0)为 先手在l - r范围内最大分数
 * 设(l, r, 1)为 后手在l - r范围内最大分数
 * 
 * - 每次都是从两端开始选择: 根据选两端的最大值确定
 *      - 当前选手选左端 
 *          => (l, r, 0) = (l + 1, r, 1) + [l]
 *          => (l, r, 1) = (l + 1, r, 0)
 *      - 当前选手选右端
 *          => (l, r, 0) = (l, r - 1, 1) + [r]
 *          => (l, r, 1) = (l, r - 1, 0) 
 * - 优化:
 *   当数组长度为偶数时，先手可以随意切换为后手所选的策略:(即使平手也是先手胜)
 *   那么先手必胜
 * @param nums 
 * @return true 
 * @return false 
 */
bool PredictTheWinner(vector<int>& nums);
int main(){
    vector<int> nums = {1,5,2};
    cout << PredictTheWinner(nums) << endl;
    return EXIT_SUCCESS;
}
bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    if ((n & 1) == 0){
        return true;
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2)));
    for (int i = 0; i < n; ++ i){
        dp[i][i][0] = nums[i];
        dp[i][i][1] = 0;
    }
    for (int r = 1; r < n; ++ r){
        for (int l = r - 1; l > -1; -- l){
            if (nums[l] + dp[l + 1][r][1] >= dp[l][r - 1][1] + nums[r]){
                dp[l][r][0] = nums[l] + dp[l + 1][r][1];
                dp[l][r][1] = dp[l + 1][r][0];
            }
            else{
                dp[l][r][0] = dp[l][r - 1][1] + nums[r];
                dp[l][r][1] = dp[l][r - 1][0];
            }
        }
    }
    return dp[0][n - 1][0] >= dp[0][n - 1][1];
}