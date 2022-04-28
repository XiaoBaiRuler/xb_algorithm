#include "E:\GitStore\xb_algorithm\common\common.h"
/**
 * @brief 368. 最大整除子集
 * 
 * https://leetcode-cn.com/problems/largest-divisible-subset/
 * 
 * 排序 + 动态规划
 * if (dp[i] % dp[j]) == 0
 * dp[i] = max(dp[i], dp[j] + 1);
 * 
 * 求列表 从最大值，倒减，每次次最大值，都在上一次的下面
 * 
 * 
 * @param nums 
 * @return vector<int> 
 */
vector<int> largestDivisibleSubset(vector<int>& nums);
int main(){

    vector<vector<int>> nums = {
        {1, 2, 4, 8},
        {1, 2, 3}
    };
    int n = nums.size();
    for (int i = 0;  i < n; ++ i){
        auto it = largestDivisibleSubset(nums[i]);
        for (int i : it){
            cout << i << " ";
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}
vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> dp(n, 1);
    int ma = 0, m; 
    for (int i = 1; i < n; ++ i){
        for (int j = 0; j < i; ++ j){
            if (nums[i] % nums[j] == 0){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (dp[i] > ma){
            ma = dp[i];
            m = nums[i];
        }
    }
    vector<int> res;
    if (n == 1){
        res.push_back(nums[0]);
        return res;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (dp[i] == ma && m % nums[i] == 0) {
            res.push_back(nums[i]);
            m = nums[i];
            ma --;
        }
    }
    return res;
}