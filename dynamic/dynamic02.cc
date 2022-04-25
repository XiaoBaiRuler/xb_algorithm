#include "E:\GitStore\xb_algorithm\common\common.h"
/**
 * @brief 1027. 最长等差数列
 * https://leetcode-cn.com/problems/longest-arithmetic-subsequence/
 * 
 * 固定可能数列的最后一个值为i [0, n)
 * => 第二个值j可能为j [0, i)
 * => dp[i][tmp] = dp[j][tmp] + 1;
 * 另外，由于数列可能重复 => dp[i][tmp] = max(dp[j][tmp] + 1, dp[i][tmp])
 * @param nums 
 * @return int 
 */
int longestArithSeqLength(vector<int>& nums);
int main(){
    vector<vector<int>> nums = {
        {3,6,9,12},
        {9,4,7,2,10},
        {20,1,15,3,10,5,8},
        {44,46,22,68,45,66,43,9,37,30,50,67,32,47,44,11,15,4,11,6,20,64,54,54,61,63,23,43,3,12,51,61,16,57,14,12,55,17,18,25,19,28,45,56,29,39,52,8,1,21,17,21,23,70,51,61,21,52,25,28},
    };
    int n = nums.size();
    for (int i = 0; i < n; ++ i){
        cout << longestArithSeqLength(nums[i]) << endl;
    }
    return EXIT_SUCCESS;
}
int longestArithSeqLength(vector<int>& nums){
        int n = nums.size(), res = 0;
        vector<vector<int>> pre(n, vector<int>(1001));
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < i; ++ j){
                int tmp = nums[i] - nums[j] + 500;
                pre[i][tmp] = max(pre[j][tmp] + 1, pre[i][tmp]);
                res = max(res, pre[i][tmp]);
            }
        }
        return res + 1;
}