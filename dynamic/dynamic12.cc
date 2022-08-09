#include "..//common//common.h"
/**
 * @brief 813. 最大平均值和的分组
 * https://leetcode.cn/problems/largest-sum-of-averages/
 * 
 * => 一个数组最多能分k个子列的数组，且分多少个，怎样分可以获得最大的平均值和
 * => 当分 1 个 数组时， 最大和为所有值的平均值
 * => 当分 2 个 数组时，就会多一个变量位置，在哪里分割好那?
 * 
 * => 那么可以假设在i位置前的数组，分配p个数组，可以获得的最大的平均值和为dp[i][p], 而其中p[1, k], i[p - 1, n - 1]
 * => 而在在i之前分配j个数组，那么在何地分配第一个数组呢，接着分配呢? 
 * => 不妨，将j[i, 1]作为分配位置。 
 * => dp[i][p] = max(dp[j - 1][p - 1](j - 1之前分配p - 1个数组获得的最大值) + avg(nums[j]...nums[i]) (j .... i之间的平均值), dp[i][p])
 * @param nums 
 * @param k 
 * @return public 
 */
double largestSumOfAverages(vector<int>& nums, int k);
int main(){
    vector<vector<int>> nums = {
        {9,1,2,3,9},
        {1,2,3,4,5,6,7}
    };
    vector<int> k = {3, 4};
    int n = nums.size();
    for (int i = 0; i < n; ++ i){
        cout << largestSumOfAverages(nums[i], k[i]) << " ";
    }
    cout << endl;
    return 0;
}
double largestSumOfAverages(vector<int>& nums, int k) {
    int n = nums.size();
    vector<double> presum(1, 0.0);
    // 前序和，前面多一个减少不必要的端点判断
    for (int i = 0; i < n; ++ i){
        presum.push_back(nums[i] + presum[i]);
    }
    vector<vector<double>> dp(n, vector<double>(k + 1, 0.0));
    // 考虑分一个数组的
    for (int i = 0; i < n; ++i) {
        dp[i][1] = presum[i + 1] / (i + 1);
    }
    // 考虑分[2, k]个数组的
    for (int p = 2; p <= k; ++ p) {
        // i 可能[p - 1, n - 1]，必须要够多少个才能构成多少个数组
        for (int i = p - 1; i < n; ++ i) {
            // j 可能在[i, 1]
            for (int j = i; j >= 1; -- j) {
                // i之前构成p个数组的最大值 = j - 1之前p-1个数组的最大值 + [j, i]之间的平均值(由于i - j可能重合)
                dp[i][p] = max(dp[i][p], dp[j - 1][p - 1] + (presum[i + 1] - presum[j]) / (i - j + 1));
            }
        }
    }
    // 最后一个就是结果
    return dp[n - 1][k];
}