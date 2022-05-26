
#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 410. 分割数组的最大值
 * https://leetcode.cn/problems/split-array-largest-sum/
 * 
 * eg: [7, 2, 5, 10, 8] 
 *     [7, 9, 14, 24, 32]
 * 当m = 1时，result = 32
 * 当m = 2时，
 *  => 先当它只有两个元素[7, 2], 那么值为7, 2的最小值，
 *  => 再当它只有三个元素[7, 2, 5], 那么值就是，max(7, 2 + 5), max(7 + 2, 5) 中的最小值.
 *  => 再当它只有四个元素[7, 2, 5, 10], 那么值为, max(7, 2 + 5 + 10), max(7 + 2， 5 + 10), max(7 + 2 + 5, 10)
 *  ...
 *  => 以此类推，不妨设i为前多少个元素[1, n], j为分多少个组[1, min(i, m)], k为前面i - 1分组个分组的边界[0, i)，
 *  => dp[i][j]为i个元素分j组中最大值和的最小值
 *  => 那么值为dp[i][j] = min(max(dp[k][j - 1], (k到i之间的和)), dp[i][j])
 *  
 *  到最后dp[n][m]为结果
 * @param nums 
 * @param m 
 * @return int 
 */
int splitArray(vector<int>& nums, int m);
int main(){
    vector<vector<int>> nums = {
        {7,2,5,10,8},
        {1,2,3,4,5},
        {1, 4, 4}
    };
    vector<int> m = {
        2, 2, 3
    };
    int n = nums.size();
    for (int i = 0; i < n; ++ i){
        cout << splitArray(nums[i], m[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
int splitArray(vector<int>& nums, int m) {
    int n = nums.size();
    for (int i = 1; i < n; ++ i){
        nums[i] += nums[i - 1];
    }
    vector<vector<long>> dp(n + 1, vector<long>(m + 1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1, end = min(i, m); j <= end; ++ j){
            dp[i][j] = min(dp[i][j], max(dp[0][j - 1], static_cast<long>(nums[i - 1])));
            for (int k = 1; k < i; ++ k){
                dp[i][j] = min(dp[i][j], max(dp[k][j - 1], static_cast<long>(nums[i - 1] - nums[k - 1])));
            }
        }
    }
    return (int)dp[n][m];
}