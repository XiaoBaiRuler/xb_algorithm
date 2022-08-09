#include "..//common//common.h"
/**
 * @brief 238. 除自身以外数组的乘积
 * https://leetcode.cn/problems/product-of-array-except-self/
 * 
 * 前缀和 + 后缀和
 * @param nums 
 * @return vector<int> 
 */
vector<int> productExceptSelf(vector<int>& nums);
int main(){
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = productExceptSelf(nums);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res;
    int temp = 1;
    for (int i : nums){
        temp *= i;
        res.push_back(temp);
    }
    int n = nums.size();
    temp = 1;
    for (int i = n - 1; i > 0; -- i){
        res[i] = res[i - 1] * temp;
        temp *= nums[i];
    }
    res[0] = temp;
    return res;
}