#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 713. 乘积小于 K 的子数组
 * https://leetcode-cn.com/problems/subarray-product-less-than-k/
 * 
 * 双指针问题
 * 注意:
 *  1. 乘积总和是否溢出问题
 *  2. 小于或等于1的问题
 * @param nums 
 * @param k 
 * @return int 
 */
int numSubarrayProductLessThanK(vector<int>& nums, int k);
int main(){
    vector<vector<int>> nums = {
        {10,5,2,6},
        {1, 2, 3}
    };
    vector<int> k = {100, 0};
    int n = nums.size();
    for (int i = 0; i < n; ++ i){
        cout << numSubarrayProductLessThanK(nums[i], k[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k < 2){
        return 0;
    }
    long long tmp = 1;
    int l = 0, r = 0, n = nums.size(), res = 0;
    while (r < n){
        tmp *= nums[r];
        ++ r;
        while (tmp >= k){
            tmp /= nums[l];
            ++ l;
        }
        res += (r - l);
    }
    return res;
}