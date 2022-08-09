#include "..//common//common.h"
/**
 * @brief 718. 最长重复子数组
 * https://leetcode.cn/problems/maximum-length-of-repeated-subarray/
 * 
 * 注意 子数组是要求连续的
 * 
 * 双串类问题i, j:
 * 1. 当前数字相同
 * 1.1 两个数组的前一个位置 + 1
 * 2. 当前数字不同
 * 2.1 0
 * 
 * @param nums1 
 * @param nums2 
 * @return int 
 */
int findLength(vector<int>& nums1, vector<int>& nums2);
int main(){
    vector<int> nums1 = {1,0,0,0,1};
    vector<int> nums2 = {1,0,0,1,1};
    cout << findLength(nums1, nums2) << endl;
    return EXIT_SUCCESS;
}
int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int res = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            if (nums1[i - 1] == nums2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(dp[i][j], res);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return res;
}