#include "..//common//common.h"
/**
 * @brief 312. 戳气球
 * https://leetcode.cn/problems/burst-balloons/
 * 区间动态规划: 设dp[l][r]为(l + 1) - (r - 1)处需要的最大数量
 * 1. 先枚举右边界r [1, n]
 * 2. 再枚举左边界l [r - 2, -1] 由小范围 -> 大范围
 * 3. 之后枚举r - l可能出现变动的位置k [l + 1, r]
 * => dp[l][r] = dp[l][k] + nums[l] * nums[k] * nums[r] + dp[r][k]
 * 
 * @param nums 
 * @return int 
 */
int maxCoins(vector<int>& nums);
int main(){
    vector<int> nums = {3, 1, 5, 8};
    cout << maxCoins(nums) << endl;
    return EXIT_SUCCESS;
}
int maxCoins(vector<int>& nums) {
    int pre = nums[0], n = nums.size();
    nums[0] = 1;
    for (int i = 1, tmp; i < n; ++ i){
        tmp  = nums[i];
        nums[i] = pre;
        pre = tmp;
    }
    nums.push_back(pre);
    nums.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));
    for (int i = 1; i <= n; ++ i){
        dp[i][i] = nums[i - 1];
    }
    for (int r = 2; r <= n + 1; ++ r){
        for (int l = r - 2; l > -1; -- l){
            for (int k = l + 1; k < r; ++ k){
                int tmp = nums[l] * nums[k] * nums[r];
                tmp += dp[l][k] + dp[k][r];
                dp[l][r] = max(tmp, dp[l][r]);
            }
        }
    }
    return dp[0][n + 1];
}