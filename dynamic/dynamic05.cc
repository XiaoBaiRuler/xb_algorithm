#include "..//common//common.h"
/**
 * @brief 413. 等差数列划分
 * 
 * https://leetcode-cn.com/problems/arithmetic-slices/
 * 求3个以上的等差数列子数组个数。子数组:数组中的一个连续序列。
 * 
 * 求连续字数数组最长的个数n，那么可以构成的总数为1 + ... n - 1;
 * 
 * @param nums 
 * @return int 
 */
int numberOfArithmeticSlices(vector<int>& nums);
int main(){
    vector<vector<int>> nums = {
        {1, 2, 3, 4},
        {1}
    };
    int n = nums.size();
    for (int i = 0; i < n; ++ i){
        cout << numberOfArithmeticSlices(nums[i]) << " ";
    }
    return EXIT_SUCCESS;
}
int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    if (n < 3){
        return 0;
    }
    int res = 0, tmp = nums[0] - nums[1], now = 0;
    for (int i = 2; i < n; ++ i){
        if (tmp == (nums[i - 1] - nums[i])){
            ++ now;
        }
        else{
            tmp = nums[i - 1] - nums[i];
            now = 0;
        }
        res += now;
    }
    return res;
}